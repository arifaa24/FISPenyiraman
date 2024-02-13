// program pengukuran level air

unsigned long lastDelayRelay = 0;

bool program1(void) {
  // jalankan fungsi sensor ultrasonic
  sensorUltrasonic();
  
  // tampilkan hasil di serial monitor
  Serial.println(F("Level Air = "));
  Serial.print(levelair);
  Serial.println(F(" cm"));

  if((unsigned long) (millis() - lastDelayRelay) >= 1000) {
    lastDelayRelay = millis();
    if (levelair >= 12) {
      digitalWrite(relay1Pin, HIGH);
      Serial.println(F("Relay 1 Mati"));
      return true;
    }
    else {
      digitalWrite(relay1Pin, LOW);
      Serial.println(F("Relay 1 Hidup"));
      return false;
    }
  }
}
