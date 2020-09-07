/*
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin 11
        Echo: Echo (OUTPUT) - Pin 11
        GND: GND
 */
long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);
}
 
void loop()
{
 
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delayMicroseconds(5);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
	
  // Read the signal from the sensor:
  pinMode(11, INPUT);
  duration = pulseIn(11, HIGH);
  Serial.println(duration);
  // convert the time into a distance
  
  inches = (duration/2) / 74; 
  //A dustbin has variable sizes but the sensor doesnt care as
  // as long as it doenst cross 132 inches or say 11 ft
  // Because we need to see only how much of it is filled we
  // only require the height of garbage in it.
  // The model outputs a green light when it can be easily filled
  // more, a yellow light when its reaching its brim and a red light
  // with buzer beeping to show its filled up and needs clearance.
  
  if(inches <2){			
    analogWrite(A0,1024);
    analogWrite(A1,0);
    analogWrite(A2,0);
  }
  else if(inches >6){		
   analogWrite(A2,1024);
    analogWrite(A0,0);
    analogWrite(A1,0);
  }
  else if(inches>=2 && inches<=6)
  {
	analogWrite(A1,1024);
    analogWrite(A0,0);
    analogWrite(A2,0);
  }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();
  
  delay(250);
}
