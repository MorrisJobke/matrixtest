#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

#define PIN 4

#define TYPE NEOPIXEL // seems to be the same as WS2812B + RGB
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
#define NUMMATRIX (MATRIX_WIDTH*MATRIX_HEIGHT)


// This could also be defined as matrix->color(255,0,0) but those defines
// are meant to work for adafruit_gfx backends that are lacking color()
#define LED_BLACK    0

#define LED_RED           (uint32)matrix->Color(0, 255, 0)


CRGB matrixleds[NUMMATRIX];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(
  matrixleds, MATRIX_WIDTH, MATRIX_HEIGHT, 1, 1,
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG );

const uint16_t colors[] = {
  matrix->Color(128, 128, 128),
  matrix->Color(255, 0, 0),
  matrix->Color(0, 255, 0),
  matrix->Color(0, 0, 255),
  matrix->Color(0, 0, 0)
};

void setup() {
  FastLED.addLeds<TYPE,PIN>(matrixleds, NUMMATRIX).setCorrection(TypicalLEDStrip);
  matrix->begin();
  matrix->setBrightness(40); // with 80 the colors flip
  matrix->setTextWrap(false);
  matrix->setTextColor(colors[0]);
  Serial.begin(9600);
}

int x = 0;
int direction = -1;
int pass = 0;
bool show_diagonals_not_text = true;

void loop() {
  matrix->fillScreen(0);

  
  matrix->setTextColor(colors[0]);
  matrix->setCursor(x + 10, 0);
  matrix->print(F("Antje"));

  x += direction;
  if (x < -8) {
    direction = 1;
  }
  if (x > -1) {
    direction = -1;
  }

  matrix->drawPixel(0, 2, colors[0]);
  matrix->drawPixel(0, 3, colors[0]);
  matrix->drawPixel(1, 1, colors[0]);
  matrix->drawPixel(1, 4, colors[0]);
  matrix->drawPixel(2, 0, colors[0]);
  matrix->drawPixel(2, 5, colors[0]);
  matrix->drawPixel(3, 0, colors[0]);
  matrix->drawPixel(3, 6, colors[0]);
  matrix->drawPixel(4, 1, colors[0]);
  matrix->drawPixel(4, 7, colors[0]);
  matrix->drawPixel(5, 0, colors[0]);
  matrix->drawPixel(5, 6, colors[0]);
  matrix->drawPixel(6, 0, colors[0]);
  matrix->drawPixel(6, 5, colors[0]);
  matrix->drawPixel(7, 1, colors[0]);
  matrix->drawPixel(7, 4, colors[0]);
  matrix->drawPixel(8, 2, colors[0]);
  matrix->drawPixel(8, 3, colors[0]);

  matrix->drawPixel(1, 2, colors[1]);
  matrix->drawPixel(1, 3, colors[1]);
  matrix->drawPixel(2, 1, colors[1]);
  matrix->drawPixel(2, 2, colors[1]);
  matrix->drawPixel(2, 3, colors[1]);
  matrix->drawPixel(2, 4, colors[1]);
  matrix->drawPixel(3, 1, colors[1]);
  matrix->drawPixel(3, 2, colors[1]);
  matrix->drawPixel(3, 3, colors[1]);
  matrix->drawPixel(3, 4, colors[1]);
  matrix->drawPixel(3, 5, colors[1]);
  matrix->drawPixel(4, 2, colors[1]);
  matrix->drawPixel(4, 3, colors[1]);
  matrix->drawPixel(4, 4, colors[1]);
  matrix->drawPixel(4, 5, colors[1]);
  matrix->drawPixel(4, 6, colors[1]);
  matrix->drawPixel(5, 1, colors[1]);
  matrix->drawPixel(5, 2, colors[1]);
  matrix->drawPixel(5, 3, colors[1]);
  matrix->drawPixel(5, 4, colors[1]);
  matrix->drawPixel(5, 5, colors[1]);
  matrix->drawPixel(6, 1, colors[1]);
  matrix->drawPixel(6, 2, colors[1]);
  matrix->drawPixel(6, 3, colors[1]);
  matrix->drawPixel(6, 4, colors[1]);
  matrix->drawPixel(7, 2, colors[1]);
  matrix->drawPixel(7, 3, colors[1]);

  // paint it black
  matrix->drawPixel(1, 0, colors[4]);
  matrix->drawPixel(1, 5, colors[4]);
  matrix->drawPixel(1, 6, colors[4]);
  matrix->drawPixel(1, 7, colors[4]);
  matrix->drawPixel(2, 6, colors[4]);
  matrix->drawPixel(2, 7, colors[4]);
  matrix->drawPixel(3, 7, colors[4]);
  matrix->drawPixel(4, 0, colors[4]);
  matrix->drawPixel(5, 7, colors[4]);
  matrix->drawPixel(6, 6, colors[4]);
  matrix->drawPixel(6, 7, colors[4]);
  matrix->drawPixel(7, 0, colors[4]);
  matrix->drawPixel(7, 5, colors[4]);
  matrix->drawPixel(7, 6, colors[4]);
  matrix->drawPixel(7, 7, colors[4]);
  matrix->drawPixel(8, 0, colors[4]);
  matrix->drawPixel(8, 1, colors[4]);
  matrix->drawPixel(8, 4, colors[4]);
  matrix->drawPixel(8, 5, colors[4]);
  matrix->drawPixel(8, 6, colors[4]);
  matrix->drawPixel(8, 7, colors[4]);
  matrix->drawPixel(9, 0, colors[4]);
  matrix->drawPixel(9, 1, colors[4]);
  matrix->drawPixel(9, 2, colors[4]);
  matrix->drawPixel(9, 3, colors[4]);
  matrix->drawPixel(9, 4, colors[4]);
  matrix->drawPixel(9, 5, colors[4]);
  matrix->drawPixel(9, 6, colors[4]);
  matrix->drawPixel(9, 7, colors[4]);

  matrix->show();
  delay(250);
}
