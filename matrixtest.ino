#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

#define PIN 4

#define TYPE NEOPIXEL // seems to be the same as WS2812B + RGB
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
#define NUMMATRIX (MATRIX_WIDTH*MATRIX_HEIGHT)

CRGB matrixleds[NUMMATRIX];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(
  matrixleds, MATRIX_WIDTH, MATRIX_HEIGHT, 1, 1,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG );

const uint16_t colors[] = {
  matrix->Color(255, 0, 0),
  matrix->Color(0, 255, 0),
  matrix->Color(0, 0, 255)
};

void setup() {
  FastLED.addLeds<TYPE,PIN>(matrixleds, NUMMATRIX);
  matrix->begin();
  matrix->setBrightness(40); // with 80 the colors flip
  Serial.begin(9600);
}

int x = MATRIX_WIDTH;
int pass = 0;
bool show_diagonals_not_text = true;

void loop() {
  matrix->fillScreen(0);

  if (show_diagonals_not_text) {

    matrix->drawLine(0, 0, 8, 8, colors[0]);
    matrix->drawLine(8, 0, 16, 8, colors[1]);
    matrix->drawLine(16, 0, 24, 8, colors[2]);

  } else {

    matrix->setCursor(x, 0);
    matrix->print(F("Howdy"));
    if(--x < -36) {
      x = matrix->width();
      if(++pass >= 3) pass = 0;
      matrix->setTextColor(colors[pass]);
    }
    // line that shows that there is something off
    matrix->drawLine(0, 0, 8, 8, colors[pass]);

  }

  matrix->show();
  delay(100);
}
