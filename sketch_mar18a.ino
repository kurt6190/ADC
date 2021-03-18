
double T, Temp;
double To = 301.15;  // 273.15 + 28 (room temperature) 室溫換成絕對溫度
double lnR;
int16_t R; 
int16_t ADCvalue;// Thermistor resistence
int16_t R0 = 8000;  // calibrated by reading R at room temperature (=28 degree Celsius )
int16_t B  = 3950;
int16_t Pullup = 9930; // 10K ohm
// R / (Pullup + R)   = adc / 4096id 

void setup() {
  Serial.begin(115200);
}
  // put your setup code here, to run once:
void Thermistor(int16_t ADCvalue)
{
 // put your main code here, to run repeatedly:
R = (Pullup*ADCvalue) / (4096-ADCvalue);
// B = (log(R) -log(R0)) / (1/T -1/To) 
T = 1/(1/To+(log(R)-log(R0))/B);
Temp = T -273.15;
ADCvalue= analogRead(A3);
//("ADC:%4d, R=%d, Temp.=%f\n", ADCvalue, R, Temp);
}

void loop()
{
 R = (Pullup * ADCvalue) / (4096 -ADCvalue);
// B = (log(R) -log(R0)) / (1/T -1/To) 
T = 1 / (1/To + (log(R)-log(R0)) / B );
Temp = T -273.15;
ADCvalue= analogRead(A3);
Serial.print("ADC:");
Serial.println(ADCvalue);

//printf("ADC:%4d, R=%d, Temp.=%f\n", ADCvalue, R, Temp);
}
