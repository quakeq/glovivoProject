int flexAmp[10];
bool fingerOn[10] = false; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 10; i++){
    if (flexAmp[i] >= 10){
      fingerOn[i] = true;
    }
    if (flexAmp[i] < 10){
      fingerOn[i] = false;
    }
  }
  Flex. 
  Serial.write()
}
