int touched[5]; //bool array checks if each sensor is activated
const int numFing = 5; //easy to change number of fingers

void setup() {
  //Average set serial to 9600
  Serial.begin(9600);
}

void loop() {
  //For loop checks if fingers are activated
  for (j = 0; j < numFing; j++){
    touched[j] = analogRead(j);
  }
  //Writes out the flexAmp amount
  for (i = 0; i < numFing; i++){
    if (touched[i] >= 10){
      Serial.println("Finger" + i + ":" + touched[i]);
    }
    else {
      //If small bend, then it doesn't trigger a bang, meaning finger's sound doesn't play
      Serial.println("Finger" + i + ":" + "OFF"); 
    }
  }
  delay(100); //small delay
}