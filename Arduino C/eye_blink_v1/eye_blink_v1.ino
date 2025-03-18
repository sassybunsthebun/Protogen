#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

int matrix1 = 2;
int matrix2 = 3;

///EYE ANIMATION FRAMES///

static const uint8_t PROGMEM eye_open_v1_left[] = {
  0b00001111,
  0b00111111,
  0b01111111,
  0b01111111,
  0b01111111,
  0b01111111,
  0b00111111,
  0b00011111
};

static const uint8_t PROGMEM eye_open_v1_right[] = {
  0b10000000,
  0b11000000,
  0b11100000,
  0b11110000,
  0b11111111,
  0b11111110,
  0b11111000,
  0b11000000
};

const uint8_t PROGMEM eye_closed_v1_left[] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01100000,
  0b01111111,
  0b00111111,
  0b00011111
};

const uint8_t PROGMEM eye_closed_v1_right[] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00011111,
  0b11111110,
  0b11111000,
  0b11000000
};

///INITIALIZE MULTIPLEXER///

void setMultiplexerOutput(uint8_t bus){
  Wire.beginTransmission(0x71); //multiplexer address. has to be different from the individual matrixes
  Wire.write(1 << bus);
  Wire.endTransmission();
  Serial.println(bus);
}

///CHECK IF THE MATRIXES INITIALIZE PROPERLY///

void setup() {
  Serial.begin(9600); 
  setMultiplexerOutput(matrix1); 
  if (!matrix.begin(0x70)) {
    Serial.println("There was an issue starting the LED matrix number 2");
  } 

  setMultiplexerOutput(matrix2); 
  if (!matrix.begin(0x70)) {
    Serial.println("There was an issue starting the LED matrix number 6");
  } 
}
///MAIN ANIMATION LOOP///

void loop() {

  setMultiplexerOutput(matrix1);
  matrix.setRotation(3);
  matrix.setBrightness(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, eye_open_v1_left, 8, 8, LED_ON);
  matrix.writeDisplay();

  setMultiplexerOutput(matrix2);
  matrix.setRotation(3);
  matrix.setBrightness(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, eye_open_v1_right, 8, 8, LED_ON);
  matrix.writeDisplay();

  delay(1000);

  setMultiplexerOutput(matrix1);
  matrix.setRotation(3);
  matrix.setBrightness(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, eye_closed_v1_left, 8, 8, LED_ON);
  matrix.writeDisplay();

  setMultiplexerOutput(matrix2);
  matrix.setRotation(3);
  matrix.setBrightness(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, eye_closed_v1_right, 8, 8, LED_ON);
  matrix.writeDisplay();

  delay(1000);
}