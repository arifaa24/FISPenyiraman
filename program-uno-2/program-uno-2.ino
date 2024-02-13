#include <EEPROM.h>
#include "configuratePin.h"
#include "fis_header.h"

void setup() {
  // put your setup code here, to run once:
  // inisialisasi komunikasi serial
  Serial.begin(9600); // set baudrate ke 9600 bps (bit per seconds)
  
  // inisialisasi pin input dan output
  // Sensor Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // DHT Sensor
  dht.begin();
  
  // TDS Sensor
  gravityTds.setPin(TDSSensorPin);
  gravityTds.setAref(5.0);        // reference volt on ADC, default 5.0V on UNO
  gravityTds.setAdcRange(1024);   // 1024 for 10bit ADC; 4096 for 12bit ADC

  // inisialisasi pin Output
  // pin mode for output 1 : oPenyiraman
  pinMode(enA, OUTPUT);
  // pin mode for output 2 : oNutrisi
  pinMode(enB, OUTPUT);
  // pin mode for output motor DC (Mixer)
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  // Matikan semua relay saat dinyalakan MCU Arduino
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(program1() == true) {
    program2();
  }
  else {
    // digitalWrite(relay2Pin, HIGH);
    relayState(relay2Pin, HIGH);
  }
  delay(50);
}
