int analogPin = 1;
int touch[2];  //bool array checks if each sensor is activated
const int numFing = 2; //easy to change number of fingers


#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

#define CAP1188_RESET  9

#define CAP1188_CS  10

#define CAP1188_MOSI  11
#define CAP1188_MISO  12
#define CAP1188_CLK  13
#define FORCE_SENSOR_PIN0 36
#define FORCE_SENSOR_PIN1 39

Adafruit_CAP1188 cap = Adafruit_CAP1188();

void setup () {
  Serial.begin(9600);
  Serial.println("CAP1188 test!");

  if (!cap.begin()) {
    Serial.println("CAP1188 not found");
    while (1);
  }
  Serial.println("CAP1188 found!");
}

void loop() {
  touch[0] = analogRead(FORCE_SENSOR_PIN0);
  touch[1] = analogRead(FORCE_SENSOR_PIN1);
  
  //Writes out the flexAmp amount
  for (int i = 0; i < numFing; i++){
    if (touch[i] >= 10){
      Serial.print(touch[i]); Serial.print(" "); Serial.print("1"); Serial.print(" ");
    }
    else{
      Serial.print("0"); Serial.print(" "); Serial.print("0"); Serial.print(" "); 
    }
  }
  Serial.println(" "); // print the raw analog reading

  uint8_t touched = cap.touched();

  if (touched == 0) {
    return;
  }
  
  for (uint8_t i=0; i<8; i++) {
    if (touched & (1 << i)) {
      Serial.print("C "); Serial.print(i+1); Serial.print("\t");
    }
  }
  Serial.println();
  delay(50);
}
