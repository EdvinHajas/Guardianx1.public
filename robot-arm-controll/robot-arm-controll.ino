#include <TimerOne.h>

int yval;
int xval;
int time = 1;
void setup() {
  Serial.begin(9600);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(7 ,OUTPUT);
  pinMode(9, OUTPUT);
  //TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz

  //TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz

  //TCCR0B = TCCR0B & B11111000 | B00000011; // for PWM frequency of 976.56 Hz (The DEFAULT)

  TCCR0B = TCCR0B & B11111000 | B00000100; // for PWM frequency of 244.14 Hz

  //TCCR0B = TCCR0B & B11111000 | B00000101; // for PWM frequency of 61.04 
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);


}

void loop() {
  int yval = analogRead(A7);
  int xval = analogRead(A6);
  Serial.print("Y tengely:");
  Serial.println(yval);
  Serial.print("x tengely:");
  Serial.println(xval);

  if(xval<400){
    digitalWrite(7, LOW); //Dir
    analogWrite(6, 70); //Step
  }
  if(xval>600){
    digitalWrite(7, HIGH); //Dir
    analogWrite(6, 70); //Step
  }
  if(xval == 518){
    digitalWrite(7, LOW);
    analogWrite(6, 0);
  }

  if(yval<400){
    digitalWrite(9, HIGH); //Dir
    analogWrite(5, 70); //Step

  }
  if(yval>600){
    digitalWrite(9, LOW); //Dir
    analogWrite(5, 70); //Step
  }
  if(yval == 514){
    digitalWrite(9, LOW);
    analogWrite(5, 0);
  }








    
  




}
