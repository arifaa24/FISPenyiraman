bool program1(){

  sensorUltra();
  
  Serial.print("Level Air =");
  Serial.print(levelair);
  Serial.println("cm");
  digitalWrite(LEDPin, LOW);
  
  if (distance >= maximumRange || distance <= minimumRange){
    Serial.println("-1");digitalWrite(LEDPin, HIGH);
  } else {
    if (levelair > 12) {
      digitalWrite(relay1Pin, HIGH);
      Serial.println("Relay mati");
      return true;
    } else {
      digitalWrite(relay1Pin, LOW);
      Serial.println("Relay hidup");
      return false;
      }

  }
}
