// the sensor communicates using SPI, so include the library:
#include <SPI.h>

void setup() {
 
  pinMode(10,OUTPUT);//slave select channel select chip select
  pinMode(11,OUTPUT);//slave select channel select chip select
  digitalWrite(10,1);
  Serial.begin(9600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
 
}

void loop()
{
  
 int num=48;// 0 ASCCI
 delay(100);
 digitalWrite(10,0); // SLAVE SELECTION
 for(int i=0;i<10;i++)
 {
  SPI.transfer(num++);
  delay(100);
 }
   digitalWrite(10,1); // SLAVE RELEASE
   
 }