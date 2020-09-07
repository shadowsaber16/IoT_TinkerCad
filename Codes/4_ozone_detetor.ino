#include <LiquidCrystal.h>
int LED = A1;
int LED1 = A2;
int Buz = A5;
const int gas = 0;
int MQ2pin = A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  
}
//Minimum cutoff for safe ozone level is 220 Dobson Units
//Minimum ozone levels observed were about 110 Dobson Units
// Maximum ozone levels observed ere about 350 Dobson units
// Scaling the output of the Gas sensor i.e between 85 -355 
// We get 110 + (sensoroutput-85)*240/270
// source for data -
// https://ozonewatch.gsfc.nasa.gov/facts/hole_SH.html
void loop() {
  float sensorValue;
  float actualValue;
sensorValue = analogRead(MQ2pin); 
actualValue = 110 + (sensorValue-85)*240/270;
lcd.setCursor(0, 1);
  if(actualValue < 220){
    analogWrite(LED1,0);
    analogWrite(LED,1024);
    analogWrite(Buz,1024);
    //Serial.println("Sensor Value: ");
    //Serial.print(sensorValue);
    lcd.print("HAZARD");
  }
  else{
  	analogWrite(LED1,1024);
    analogWrite(LED,0);
    analogWrite(Buz,0);
    //Serial.println("Sensor Value: ");
    //Serial.println(sensorValue);
    lcd.print("SAFE  ");
  } 
  delay(1000);
}
