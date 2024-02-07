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
//***********************************************************************
// Support functions for Fuzzy Inference System                          
//***********************************************************************
// Trapezoidal Member Function
FIS_TYPE fis_trapmf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE a = p[0], b = p[1], c = p[2], d = p[3];
    FIS_TYPE t1 = ((x <= c) ? 1 : ((d < x) ? 0 : ((c != d) ? ((d - x) / (d - c)) : 0)));
    FIS_TYPE t2 = ((b <= x) ? 1 : ((x < a) ? 0 : ((a != b) ? ((x - a) / (b - a)) : 0)));
    return (FIS_TYPE) min(t1, t2);
}

// Triangular Member Function
FIS_TYPE fis_trimf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE a = p[0], b = p[1], c = p[2];
    FIS_TYPE t1 = (x - a) / (b - a);
    FIS_TYPE t2 = (c - x) / (c - b);
    if ((a == b) && (b == c)) return (FIS_TYPE) (x == a);
    if (a == b) return (FIS_TYPE) (t2*(b <= x)*(x <= c));
    if (b == c) return (FIS_TYPE) (t1*(a <= x)*(x <= b));
    t1 = min(t1, t2);
    return (FIS_TYPE) max(t1, 0);
}

FIS_TYPE fis_min(FIS_TYPE a, FIS_TYPE b)
{
    return min(a, b);
}

FIS_TYPE fis_max(FIS_TYPE a, FIS_TYPE b)
{
    return max(a, b);
}

FIS_TYPE fis_array_operation(FIS_TYPE *array, int size, _FIS_ARR_OP pfnOp)
{
    int i;
    FIS_TYPE ret = 0;

    if (size == 0) return ret;
    if (size == 1) return array[0];

    ret = array[0];
    for (i = 1; i < size; i++)
    {
        ret = (*pfnOp)(ret, array[i]);
    }

    return ret;
}
