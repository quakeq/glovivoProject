int flexAmp[5]; //array stores each finger's value
const int numFing = 5; //easy to change number of fingers

void setup() {
  //Average set serial to 9600
  Serial.begin(9600);
}

void loop() {
  //For loop inputs the value of the flex sensors to flexAmp
  for (j = 0; j < numFing; j++){
    flexAmp[j] = analogRead();
  }
  //Writes out the flexAmp amount
  for (i = 0; i < numFing; i++){
    if (flexAmp[i] >= 5){
      Serial.println("Finger" + i + ":" + flexAmp[i]);
    }
    else {
      //If small bend, then it doesn't trigger a bang, meaning finger's sound doesn't play
      Serial.println("Finger" + i + ":" + "OFF"); 
    }
  }
  delay(100); //small delay
}