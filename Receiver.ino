#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define jel1 
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

void setup() {
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MAX);
}

void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
    radio.read(&data, sizeof(Data_Package));
    Serial.println(data.xval1);
    Serial.println(data.yval1);
    Serial.println(data.xval2);
    Serial.println(data.yval2);
    Serial.println(data.ButtonState1);
    Serial.println(data.ButtonState2);
    Serial.println(data.ButtonState3);
    Serial.println(data.ButtonState4);
    Serial.println(data.ButtonState5);

    }
    delay(5);
    radio.stopListening();
    radio.write(&adat, sizeof(Adat_Csomag));

  
  }
}