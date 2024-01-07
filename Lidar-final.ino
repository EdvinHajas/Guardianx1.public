#include <Servo.h> 
#include <SharpIR.h>

#define ir A0
#define model 20150
SharpIR SharpIR(ir, model);

Servo myservo;	
int pos = 0;
int start = 0;

void setup() 
{
  Serial.begin(9600);
	myservo.attach(10); 
  myservo.write(start);
}

void loop() 
{
	for(pos = 0; pos <= 180; pos += 1) 
	{
    int dis=SharpIR.distance();
    if (dis > 110) {
    Serial.print("Mean distance: ");  
    Serial.print("110");
    Serial.println(" cm");
    }
    if (dis < 110) {
    Serial.print("Mean distance: ");  
    Serial.print(dis);  
    Serial.println(" cm");
    }
    Serial.write(pos);
    Serial.println(pos);
		myservo.write(pos);
		delay(20);
	}
	for(pos = 180; pos>=0; pos-=1)
	{
    int dis=SharpIR.distance();
    if (dis > 110) {
    Serial.print("Mean distance: ");  
    Serial.print("110+");
    Serial.println(" cm");
    }
    if (dis < 110) {
    Serial.print("Mean distance: ");  
    Serial.print(dis);  
    Serial.println(" cm");
    }
    Serial.write(pos);
    Serial.println(pos);
		myservo.write(pos);
		delay(20);
	}
}
