#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "table.h"
#include "eye.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

int matrixes[7] = {1, 2, 3, 4, 5, 6, 7}; //the multiplexer output port numbers

/**
 * @brief   Initialize multiplexer and set the multiplexer output
 *
 * @param   uint8_t bus
 */
void setMultiplexerOutput(uint8_t bus){
  Wire.beginTransmission(0x71); //multiplexer address. has to be different from the individual matrixes
  Wire.write(1 << bus);
  Wire.endTransmission();
}

/**
 * @brief   Check if the matrixes initialize properly
 *
 * @param   int matrixNumber
 */
void initializeMatrix(int matrixNumber) {
  setMultiplexerOutput(matrix1);
  if (!matrix.begin(0x70)) {
    Serial.print("There was an issue starting the LED matrix number");
    Serial.println(matrixNumber);
  } 
  else {
    Serial.print(matrixNumber);
    Serial.println("Initialized!");
  }
}

/**
 * @brief   Configure the matrix rotation and brightness
 *
 * @param   int matrixNumber
 * @param   int rotation
 * @param   int brightness
 */
void setMatrixConfiguration(int matrixNumber, int rotation, int brightness){
  setMultiplexerOutput(matrixNumber);
  matrix.setRotation(rotation);
  matrix.setBrightness(brightness);
}

/**
 * @brief   Set the matrix animation frame
 *
 * @param   int matrixNumber
 * @param   uint8_t animationframe[]
 */
void setMatrixOutput(int matrixNumber, uint8_t animationFrame[]){
  setMultiplexerOutput(matrixNumber);
  matrix.clear();
  matrix.drawBitmap(0, 0, animationFrame, 8, 8, LED_ON);
  matrix.writeDisplay();
}

void setup() {
  Serial.begin(9600); 
  for (int i = 0; i <= 7; i++){
    initializeMatrix(matrixes[i]);
    Serial.print("Matrix");
    Serial.print(i);
    Serial.print("initialized!");
  }
  //mirror matrix
  for (int i = 0; i < 8; i++){
    eye_left[i] = table[eye_right[i]];
  }

  for (int i = 0; i <= 7; i++){
    setMatrixConfiguration(matrixes[i], 3, 1);
  }
}
///MAIN ANIMATION LOOP///

void loop() {

  for (int i = 0; i <= 7; i++){
    setMatrixOutput(matrixes[i], eye_left);
  }

  delay(500);

    for (int i = 0; i <= 7; i++){
    setMatrixOutput(matrixes[i], eye_right);
  }

  delay(500);
}