// buat variable lastTime untuk menyimpan nilai akhir millis
unsigned long lastTimeSensorTDS = 0, lastTimeSensorDHT = 0;
// buat batas interval/delay millis (untuk sensor TDS 1000ms dan DHT 3000ms)
const uint16_t intervalTDS = 1000, intervalDHT = 5000;

// program ultrasonic
void sensorUltrasonic() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // perhitungan untuk dijadikan jarak
  distance = duration / 58.2;
  levelair = 20 - distance;
}

// sensor TDS
void sensorTDS() {
  unsigned long currentTime = millis();
  if((unsigned long) (currentTime - lastTimeSensorTDS) >= intervalTDS) {
    // temperature = readTemperature(); // add your temperature sensor and read it
    gravityTds.setTemperature(temperature);
    gravityTds.update(); // sample and calculate
    tdsValue = gravityTds.getTdsValue();
    lastTimeSensorTDS = currentTime; // masukan nilai lastTime millis
  }
}

// sensor DHT22
void sensorDHT() {
  unsigned long currentTime = millis();
  if((unsigned long) (currentTime - lastTimeSensorDHT) >= intervalDHT) {
    lastTimeSensorDHT = currentTime;
    h = dht.readHumidity();
    t = dht.readTemperature();
    if(isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      h = 0.0; t = 0.0;
      return;
    }
  }
  
}