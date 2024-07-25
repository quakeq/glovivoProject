int touched[2]; //bool array checks if each sensor is activated
const int numFing = 2; //easy to change number of fingers

void setup() {
  //Average set serial to 9600
  Serial.begin(9600);
}

void loop() {
  //For loop checks if fingers are activated
  for (int j = 0; j < numFing; j++){
    touched[j] = analogRead(j);
  }
  //Writes out the flexAmp amount
  for (int i = 0; i < numFing; i++){
    if (touched[i] >= 10){
      Serial.print(touched[i]); Serial.print(i); 
    }
    else{
      Serial.print("0"); Serial.print(i);
    }
  }
    Serial.println(" ");
  
  delay(10); //small delay
}