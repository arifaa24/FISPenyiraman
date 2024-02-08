void program2(void) {
  // jalankan fungsi program sensor DHT 22
  sensorDHT();

  // jalankan fungsi program sensor tds
  sensorTDS();
  if(tdsValue > 800) {
    digitalWrite(relay2Pin, MATI);
    Serial.println(F("Relay 2 Mati"));
  } else {
    digitalWrite(relay2Pin, HIDUP);
    Serial.println(F("Relay 2 Hidup"));
  }
  
  // masukan nilai kelembapan dan suhu
  // Read Input : iSuhu
  g_fisInput[0] = t;
  // Read Input : iKelembapan
  g_fisInput[1] = h;
  // Read Input : iNutrisi
  g_fisInput[2] = tdsValue;

  g_fisOutput[0] = 0;
  g_fisOutput[1] = 0;

  // jalankan kalkulasi fuzzy
  fis_evaluate();

  // set output value : oPenyiraman
  digitalWrite(enB, g_fisOutput[0]);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // set output value : oNutrisi
  digitalWrite(enA, g_fisOutput[1]);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // tampilkan data di serial monitor
  // Suhu
  Serial.print(F("Suhu = "));
  Serial.print(t);
  Serial.println("*C");
  // Kelembapan
  Serial.print(F("Kelembapan = "));
  Serial.print(h);
  Serial.println(F("%"));
  // Kadar Nutrisi
  Serial.print(F("Kadar Nutrisi = "));
  Serial.print(tdsValue);
  Serial.println(F("ppm"));
  // Hasil PWM Motor Pompa Penyiraman
  Serial.print(F("Motor Pompa penyiraman = "));
  Serial.print(g_fisOutput[0]);
  Serial.println(F("PWM"));
  // Hasil PWM Motor Pompa Nutrisi
  Serial.print(F("Motor Pompa Nutrisi = "));
  Serial.print(g_fisOutput[1]);
  Serial.println(F("PWM"));
}