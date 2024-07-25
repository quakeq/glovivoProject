int flexAmp[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  for (j = 0; j < 5; j++){
    flexAmp[j] = analogRead();
  }
  for (i = 0; i < 10; i++){
    if (flexAmp[i] >= 10){
      Serial.write("Finger" + i +":" + flexAmp[i]);
    }
    else {
      continue;
    }
  }
  delay(100);
}