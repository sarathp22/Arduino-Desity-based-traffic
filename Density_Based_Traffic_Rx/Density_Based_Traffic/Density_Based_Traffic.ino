#include<RH_ASK.h>
#include<SPI.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(34,35,36,37,38,39);
//Led Red orange green order
const int txSpeed = 2000;
const int rxPin = 5;
const int txPin = 6;
const int pttPin = 7;
int x=0,i=0,j=0,k=0;

RH_ASK driver(txSpeed, rxPin, txPin, pttPin);

void way1()
{
 int t1=10;
 lcd.setCursor(0,0);
 lcd.write("WAY 1 : GO");
 digitalWrite(22,0);
 digitalWrite(23,0);
 digitalWrite(24,1);
 digitalWrite(25,1);
 digitalWrite(28,1);
 digitalWrite(31,1);
 if(digitalRead(13)==0)
 {
  t1=15; 
 }
 for(i=t1;i>=2;i--)
 {
  lcd.setCursor(0,1);
  lcd.print(i);
  Serial.println(i); 
  delay(1000);
  if(i==10)
  {
      lcd.clear();
  }
  lcd.setCursor(0,0);
  lcd.write("WAY 1 : GO"); 
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("WAY 1 : STOP");
 digitalWrite(22,0);
 digitalWrite(23,1);
 digitalWrite(24,0);
 delay(2000);
 digitalWrite(22,1);
 digitalWrite(23,0);
 digitalWrite(24,0);
 lcd.clear();
}

void way2()
{
 int t2=10;
 lcd.setCursor(0,0);
 lcd.write("WAY 2 : GO");
 digitalWrite(25,0);
 digitalWrite(26,0);
 digitalWrite(27,1);
 if(digitalRead(12)==0)
 {
  t2=15;
 }
 for(i=t2;i>=2;i--)
 {
  lcd.setCursor(0,1);
  lcd.print(i); 
  delay(1000);
  if(i==10)
  {
   lcd.clear();
   lcd.write("WAY 2 : GO");
  }
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("WAY 2 : STOP");
 digitalWrite(25,0);
 digitalWrite(26,1);
 digitalWrite(27,0);
 delay(2000);
 digitalWrite(25,1);
 digitalWrite(26,0);
 digitalWrite(27,0);
 lcd.clear();
}

void way3()
{
 int t3=10;
 lcd.setCursor(0,0);
 lcd.write("WAY 3 : GO");
 digitalWrite(28,0);
 digitalWrite(29,0);
 digitalWrite(30,1);
 if(digitalRead(11)==0)
 {
  t3=15;
 }
 for(i=t3;i>=2;i--)
 {
  lcd.setCursor(0,1);
  lcd.print(i); 
  delay(1000);
  if(i==10)
  {
   lcd.clear();
   lcd.write("WAY 3 : GO");
  }
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("WAY 3 : STOP");
 digitalWrite(28,0);
 digitalWrite(29,1);
 digitalWrite(30,0);
 delay(2000);
 digitalWrite(28,1);
 digitalWrite(29,0);
 digitalWrite(30,0);
 lcd.clear();
}

void way4()
{
 int t4=10;
 lcd.setCursor(0,0);
 lcd.write("WAY 4 : GO");
 digitalWrite(31,0);
 digitalWrite(32,0);
 digitalWrite(33,1);
 if(digitalRead(10)==0)
 {
  t4=15;
 }
 for(i=t4;i>=2;i--)
 {
  lcd.setCursor(0,1);
  lcd.print(i); 
  delay(1000);
  if(i==10)
  {
   lcd.clear();
   lcd.write("WAY 4 : GO");
  }
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("WAY 4 : STOP");
 digitalWrite(31,0);
 digitalWrite(32,1);
 digitalWrite(33,0);
 delay(2000);
 digitalWrite(31,1);
 digitalWrite(32,0);
 digitalWrite(33,0);
 lcd.clear();
}

void emer()
{
 int em=20;
 lcd.setCursor(0,0);
 lcd.write("WAY 1 EMERGENCY");
 digitalWrite(22,0);
 digitalWrite(23,0);
 digitalWrite(24,1);
 for(i=em;i>=2;i--)
 {
  lcd.setCursor(0,1);
  lcd.print(i); 
  delay(1000);
  if(i==10)
  {
   lcd.clear();
   lcd.write("WAY 1 EMERGENCY");
  }
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write("WAY 1 : STOP");
 digitalWrite(22,0);
 digitalWrite(23,1);
 digitalWrite(24,0);
 delay(2000);
 digitalWrite(22,1);
 digitalWrite(23,0);
 digitalWrite(24,0);
 lcd.clear();
}

void setup()
{
 lcd.begin(16,2);
 Serial.begin(9600);//Debugging only
 pinMode(13,INPUT);//IR1
 pinMode(12,INPUT);//IR2
 pinMode(11,INPUT);//IR3
 pinMode(10,INPUT);//IR4
 pinMode(22,OUTPUT);//RT1
 pinMode(23,OUTPUT);//YT1
 pinMode(24,OUTPUT);//GT1
 pinMode(25,OUTPUT);//RT2
 pinMode(26,OUTPUT);//YT2
 pinMode(27,OUTPUT);//GT2
 pinMode(28,OUTPUT);//RT3
 pinMode(29,OUTPUT);//YT3
 pinMode(30,OUTPUT);//GT3
 pinMode(31,OUTPUT);//RT4
 pinMode(32,OUTPUT);//YT4
 pinMode(33,OUTPUT);//GT4
 if(!driver.init())
 {
  Serial.println("init failed");
 }
}

void loop()
{
  if(k==0)
  {
  for(j=0;j<5;j++)
 {
  digitalWrite(23,1);
 digitalWrite(26,1);
 digitalWrite(29,1);
 digitalWrite(32,1);
 delay(250);
 digitalWrite(23,0);
 digitalWrite(26,0);
 digitalWrite(29,0);
 digitalWrite(32,0);
  delay(250);
 }
 k=1;
  }

 uint8_t buf[RH_ASK_MAX_MESSAGE_LEN] = {0};
 uint8_t buflen = sizeof(buf);
 if(driver.recv(buf, &buflen)) // if message received, save it
 {
  x=1;
  
  Serial.println((char*)buf); // print received message
 }
 if(x==1)
 {
  emer();
  x=0;
 }
 way1();
 if(driver.recv(buf, &buflen)) // if message received, save it
 {
  x=1;
  Serial.println((char*)buf); // print received message
 }
 if(x==1)
 {
  emer();
  x=0;
 }
 way2();
 if(driver.recv(buf, &buflen)) // if message received, save it
 {
  x=1;
  Serial.println((char*)buf); // print received message
 }
 if(x==1)
 {
  emer();
  x=0;
 }
 way3();
 if(driver.recv(buf, &buflen)) // if message received, save it
 {
  x=1;
  Serial.println((char*)buf); // print received message
 }
 if(x==1)
 {
  emer();
  x=0;
 }
 way4();
}
