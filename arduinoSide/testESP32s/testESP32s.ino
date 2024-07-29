#define FSR_0 12
#define FSR_1 14

int numFinger = 2;
int touch[2];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  touch[0] = analogRead(FSR_0);
  touch[1] = analogRead(FSR_1);

  for (int i = 0; i < numFinger; i++){
    if (touch[i] >= 10){
      Serial.print(touch[i]); Serial.print(" "); Serial.print("1"); Serial.print(" ");
    }
    else{
      Serial.print("0"); Serial.print(" "); Serial.print("0"); Serial.print(" "); 
    }
  }
  Serial.println(" ");

  delay(10);
}
