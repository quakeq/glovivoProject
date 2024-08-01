#include "BluetoothSerial.h"

#define FSR_0 36
#define FSR_1 39
#define FSR_2 34

#define FLEX_0 32
#define FLEX_1 33

BluetoothSerial SerialBT;

int numFinger = 3;
int numFlex = 2;
int touch[3];
int flex[2];

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  touch[0] = analogRead(FSR_0);
  touch[1] = analogRead(FSR_1);
  touch[2] = analogRead(FSR_2);
  for (int i = 0; i < numFinger; i++){
    if (touch[i] >= 10){
      Serial.print(touch[i]); Serial.print(" "); Serial.print("1"); Serial.print(" ");
    }
    else{
      Serial.print("0"); Serial.print(" "); Serial.print("0"); Serial.print(" "); 
    }
  }
  flex[0] = analogRead(FLEX_0);
  flex[1] = analogRead(FLEX_1);
  for (int i = 0; i < numFlex; i++){
    if (flex[i] != 0){
      Serial.print(flex[i]); Serial.print(" "); Serial.print("1"); Serial.print(" ");
    }
    else{
      Serial.print("0"); Serial.print(" "); Serial.print("0"); Serial.print(" "); 
    }
  }
  Serial.println(" ");

  delay(10);
}
