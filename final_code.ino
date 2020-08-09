#include<LiquidCrystal.h>
LiquidCrystal disp(12,11,5,4,3,2);
int alchol=A3;
int buz=13;
int value=900;


void setup() 
{
  disp.begin(16,2);
  pinMode(alchol,INPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  disp.clear();
  disp.setCursor(0,0);
  disp.print("Project!");
  int sensorvalue=analogRead(alchol);
  disp.setCursor(0,1);
  if(sensorvalue>value)
  {
    disp.print("ALchol Detected");
    tone(buz,45,100);
  }
  else
  {
    disp.print("Not Detected");
    noTone(buz);
  }
  delay(80);
}
