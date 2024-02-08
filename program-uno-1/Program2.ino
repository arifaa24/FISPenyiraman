void program2(){
  //Sensor DHT22
  sensorDHT();
  
//Sensor TDS
//temperature = readTemperature();  //add your temperature sensor and read it
//gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
//gravityTds.update();  //sample and calculate
//tdsValue = gravityTds.getTdsValue();  // then get the value

if (sensorTDS() > 800) {
  digitalWrite(relay2Pin, HIGH);
  Serial.println("Relay mati");
 } else {
  digitalWrite(relay2Pin, LOW);
  Serial.println("Relay hidup");
 }

// Read Input: iSuhu
g_fisInput[0] = t;
// Read Input: iKelembapan
g_fisInput[1] = h;
// Read Input: iNutrisi
g_fisInput[2] = tdsValue;   

g_fisOutput[0] = 0;
g_fisOutput[1] = 0;

fis_evaluate();

// Set output vlaue: oPenyiraman
digitalWrite(enB, g_fisOutput[0]);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
// Set output vlaue: oNutrisi
digitalWrite(enA, g_fisOutput[1]);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

Serial.print("Suhu = ");
Serial.print(t);
Serial.println("*C");
Serial.print("Kelembapan = ");
Serial.print(h);
Serial.println("%");
Serial.print("Kadar Nutrisi = ");
Serial.print(tdsValue);
Serial.println("TDS");
Serial.print("Motor pompa penyiraman = ");
Serial.print(g_fisOutput[0]);
Serial.println("PWM");
Serial.print("Motor pompa Nutrisi = ");
Serial.print(g_fisOutput[1]);
Serial.println("PWM"); 
}