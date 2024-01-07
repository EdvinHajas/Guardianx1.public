#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};

struct Adat_Csomag{
  String a = "Akadály Ballra!";
  String b = "Akadály Elöttem!";
  String c = "Akadály Jobbra!";
};
Adat_Csomag adat;

struct Data_Package {
  int xval1 = 514;
  int yval1 = 514;
  int xval2 = 514;
  int yval2 = 514;
  boolean ButtonState1 = 0;
  boolean ButtonState2 = 0;
  boolean ButtonState3 = 0;
  boolean ButtonState4 = 0;
  boolean ButtonState5 = 0;
};
Data_Package data; 

LiquidCrystal_I2C lcd(0x27,  16, 2);
void setup() {
  pinMode(12, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MAX);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Hi I'm a Robot");
}

void loop() {
  delay(5);

  radio.stopListening();
  int xval1 = analogRead(A0);
  int yval1 = analogRead(A1);
  int xval2 = analogRead(A2);
  int yval2 = analogRead(A3);
  boolean ButtonState1 = digitalRead(2);
  boolean ButtonState2 = digitalRead(3);
  boolean ButtonState3 = digitalRead(4);
  boolean ButtonState4 = digitalRead(5);
  boolean ButtonState5 = digitalRead(6);

  radio.write(&data, sizeof(Data_Package));


  delay(5);
  radio.startListening();
  while (!radio.available());{
    radio.read(&adat, sizeof(Adat_Csomag));
    Serial.println(adat.a);
    Serial.println(adat.b);
    Serial.println(adat.c);

  }
}
