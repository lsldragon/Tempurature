#include <UTFT.h>
#include<OneWire.h>
#include<DallasTemperature.h>

#define ONE_WIRE_BUS 2
extern uint8_t hallfetica_normal[];

UTFT LCD(15,A2,A1,A5,A4,A3);

int positive = 10;
int negtive = 11;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(){

  LCD.InitLCD(PORTRAIT);
  LCD.setFont(hallfetica_normal);
  
  Serial.begin(9600);
  sensors.begin();

  pinMode(positive,OUTPUT);
  digitalWrite(positive,HIGH);

  pinMode(negtive,OUTPUT);
  digitalWrite(negtive,LOW);
  LCD.clrScr();
  LCD.setColor(255,0,0);
}

void loop(){
  
  sensors.requestTemperatures(); 
  Serial.print("Temperature for the device 1 (index 0) is: ");
  float temp = sensors.getTempCByIndex(0);
  Serial.println(temp); 
  delay(10); 
  
 char c[20];
 dtostrf(temp,3,2,c);
 LCD.print("Temp..",20,20);
 LCD.print(c,20,40);
 LCD.print("By LSL",20,80);
}

