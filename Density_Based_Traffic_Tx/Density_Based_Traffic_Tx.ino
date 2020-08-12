#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
 
// tx/rx configuration
const int txSpeed = 2000;
const int rxPin = 5;
const int txPin = 6;
const int pttPin = 7;
int i=0;
 
RH_ASK driver(txSpeed, rxPin, txPin, pttPin);
 
void setup()
{
 if(!driver.init())
 {
  Serial.println("rf driver init failed");
 }
 pinMode(LED_BUILTIN,OUTPUT);
 pinMode(12,INPUT);
}
 
void loop()
{
 const char *msg = "AMB";
 if(digitalRead(12))
 {
  while(digitalRead(12));
  for(i=0;i<100;i++)
  {
   digitalWrite(LED_BUILTIN, HIGH);
   delay(50);
   digitalWrite(LED_BUILTIN, LOW);
   delay(50);
   driver.send((uint8_t *)msg, strlen(msg));
   driver.waitPacketSent();
   delay(200);
  } 
 } 
}
