#include "BluetoothSerial.h"

#define FSR_0 12
#define FSR_1 14
#define FSR_2 
#define FSR_3 
#define FSR_4
BluetoothSerial SerialBT;
int numFinger = 2;
int touch[2];


void setup() {
  // put your setup code here, to run once:
  SerialBT.begin("esp32r");
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  touch[0] = analogRead(FSR_0);
  touch[1] = analogRead(FSR_1);

  for (int i = 0; i < numFinger; i++){
    if (touch[i] >= 10){
      SerialBT.print(touch[i]); SerialBT.print(" "); SerialBT.print("1"); SerialBT.print(" ");
    }
    else{
      SerialBT.print("0"); SerialBT.print(" "); SerialBT.print("0"); SerialBT.print(" "); 
    }
  }
  SerialBT.println(" ");

  delay(10);
}
