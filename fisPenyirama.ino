//***********************************************************************
// Matlab .fis to arduino C converter v2.0.1.25122016                   
// - Karthik Nadig, USA                                                  
// Please report bugs to:                                                
// https://github.com/karthiknadig/ArduinoFIS/issues                     
// If you don't have a GitHub account mail to karthiknadig@gmail.com     
//***********************************************************************

#include "fis_header.h"
#include "DHT.h"
#include <EEPROM.h>
#include "GravityTDS.h"
#define DHTPIN 13     // Sensor DHT22 PIN
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define TdsSensorPin A1 // Sensor TDS PIN
// Sensor Ultrasonic HC-SR04 PIN
#define echoPin 12 //Echo Pin
#define trigPin 11 //Trigger Pin 
//#define LEDPin 13
DHT dht(DHTPIN, DHTTYPE);
GravityTDS gravityTds;
int relay1Pin = 4;
int relay2Pin = 3;
// Motor A (pompa nutrisi)
int enA = 10;  // Pin PWM untuk mengatur kecepatan motor A
int in1 = 9;
int in2 = 8;
// Motor B (pompa penyiraman)
int enB = 5;  // Pin PWM untuk mengatur kecepatan motor B
int in3 = 6;
int in4 = 7;
float h,t;

int maximumRange = 200; //kebutuhan akan maksimal range
int minimumRange = 00; //kebutuhan akan minimal range
long duration, distance, levelair;//waktu untuk kalkulasi jarak
float temperature = 25,tdsValue = 0;

// Number of inputs to the fuzzy inference system
const int fis_gcI = 3;
// Number of outputs to the fuzzy inference system
const int fis_gcO = 2;
// Number of rules to the fuzzy inference system
const int fis_gcR = 24;

FIS_TYPE g_fisInput[fis_gcI];
FIS_TYPE g_fisOutput[fis_gcO];

// Setup routine runs once when you press reset:
void setup()
{

    Serial.begin (9600); //inisialiasasi komunikasi serial
    //deklarasi pin
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(LEDPin, OUTPUT);

    dht.begin();
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
    // initialize the Analog pins for input.
  
    // Pin mode for Output: oPenyiraman
    pinMode(enA , OUTPUT);
    // Pin mode for Output: oNutrisi
    pinMode(enB , OUTPUT);
    // pin mode for output motor DC (Mixer)
    pinMode(relay1Pin, OUTPUT);
    pinMode(relay2Pin, OUTPUT);
    // Matikan semua relay saat awal
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(relay2Pin, HIGH);

}

// Loop routine runs over and over again forever:
void loop()
{
 program1();
 if(program1() == true) {
 program2();
 } else {
 digitalWrite(relay2Pin, HIGH);    
 }
 delay(50);
}
