#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); 
}
float temp;
int tempPin = A3;
int ledPins[] = {A4,A5,A1,A0};

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  temp = analogRead(tempPin);
  temp = ((temp-20) * 165/338) -40 ;
  Serial.print(temp);
  Serial.print("\n");
  if(temp < 22)
  { 
    analogWrite(ledPins[2],1024);
  	analogWrite(ledPins[3],0);
    analogWrite(ledPins[1],0);
    analogWrite(ledPins[0],0);
    lcd.print("Too Cold:");
  }
  else if(temp>=22 && temp<32)
  { 
    analogWrite(ledPins[3],1024);
    analogWrite(ledPins[1],0);
    analogWrite(ledPins[0],0);
    analogWrite(ledPins[2],0);
    lcd.print("Ideal Temp:");
  }
  else if(temp>=32 && temp<38)
  { analogWrite(ledPins[1],1024);
    analogWrite(ledPins[0],0);
    analogWrite(ledPins[2],0);
    analogWrite(ledPins[3],0);
   lcd.print("Moderately High:");
  }
  else if(temp>=38)
  {
 	analogWrite(ledPins[0],1024);
    analogWrite(ledPins[3],0);
    analogWrite(ledPins[1],0);
    analogWrite(ledPins[2],0);
    lcd.print("Too High:");
  }
  lcd.setCursor(0, 1);
  lcd.print(temp);
  delay(1000);
}