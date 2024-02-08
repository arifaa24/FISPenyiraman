// program pengukuran level air
bool program1(void) {
  // jalankan fungsi sensor ultrasonic
  sensorUltrasonic();
  
  // tampilkan hasil di serial monitor
  Serial.println(F("Level Air = "));
  Serial.print(levelair);
  Serial.println(F(" cm"));

  if (levelair > 12) {
    digitalWrite(relay1Pin, MATI);
    Serial.println(F("Relay 1 Mati"));
    return true;
  }
  else {
    digitalWrite(relay1Pin, HIDUP);
    Serial.println(F("Relay 1 Hidup"));
    return false;
  }
}