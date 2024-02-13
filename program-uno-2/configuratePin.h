// file definisi pin input dan output module
// referensi kalo engga tau type data uint
// https://www.badprog.com/c-type-what-are-uint8-t-uint16-t-uint32-t-and-uint64-t

#ifndef configuratePin_h
#define configuratePin_h

#include <DHT.h>
#include <GravityTDS.h>

// DHT Sensor
#define DHTPIN        13
#define DHTTYPE       DHT22
float h, t; // variabel untuk menyimpan data sensor DHT
// deklarasi objek dht sensor
DHT dht(DHTPIN, DHTTYPE);

// TDS Sensor Pin
#define TDSSensorPin  A1
uint16_t maximumRange = 200;        // kebutuhan akan maksimal range
uint16_t minimumRange = 0;          // kebutuhan akan minimal range
float temperature = 25.0, tdsValue = 0.0;
// deklarasi objek TDS Sensor
GravityTDS gravityTds;

// Sensor Ultrasonic HC-SR04 PIN
#define echoPin       12
#define trigPin       11
long duration, distance, levelair;  // waktu untuk kalkulasi jarak

// relay module pinout
// reference default : HIGH = 0x1; LOW = 0x0
#define relay1Pin     4
#define relay2Pin     3
//#define MATI          0x1
//#define HIDUP         0x0

// configurate pinout Motor
// Motor A (Pompa nutrisi)
const uint8_t enA = 10; // Pin PWM untuk mengatur kecepatan motor A
const uint8_t in1 = 9;
const uint8_t in2 = 8;
// Motor B (Pompa Penyiraman)
const uint8_t enB = 5; // Pin PWM untuk mengatur kecepatan motor B
const uint8_t in3 = 6;
const uint8_t in4 = 7;

#endif
