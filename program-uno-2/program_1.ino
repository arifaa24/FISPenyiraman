// program relay
#define intervalRelay 1000 // 1000ms
unsigned long lastDelayRelay = 0;
void relayState(byte pinOut, uint8_t state) {
  if((unsigned long) (millis() - lastDelayRelay) >= intervalRelay) {
    lastDelayRelay = millis();
    digitalWrite(pinOut, state);
  }
}

// program pengukuran level air
bool program1(void) {
  // jalankan fungsi sensor ultrasonic
  sensorUltrasonic();
  
  // tampilkan hasil di serial monitor
  Serial.println(F("Level Air = "));
  Serial.print(levelair);
  Serial.println(F(" cm"));

  if (levelair >= 12) {
    // digitalWrite(relay1Pin, HIGH);
    relayState(relay1Pin, HIGH);
    Serial.println(F("Relay 1 Mati"));
    return true;
  }
  else {
    // digitalWrite(relay1Pin, LOW);
    relayState(relay1Pin, LOW);
    Serial.println(F("Relay 1 Hidup"));
    return false;
  }
}
