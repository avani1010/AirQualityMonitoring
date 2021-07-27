
#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
int sensorValue;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() 
{
  lcd.begin(16,2);
  Serial.begin(9600);           //  sets the serial port to 9600
}
void loop()
{
  sensorValue=analogRead(0);    //  read analog input pin 0


Serial.print("AIRQ=");
Serial.print(sensorValue,DEC);   // prints the value read
Serial.println("PPM");
lcd.setCursor(0,0);
lcd.print("NMIT AIRQ=");
lcd.print(sensorValue,DEC);
lcd.print("PPM");
lcd.println("          ");
lcd.print("  ");
lcd.setCursor(0,1);
if(sensorValue<250)
{
  lcd.print("Indoor");
}
else if(sensorValue>=250 and sensorValue<350)
{
  lcd.print("Fresh Air");
}
else if(sensorValue>=350 and sensorValue<1000)
{
  lcd.print("Normal Air");
}
else if(sensorValue>=1000 and sensorValue<=2000)
{
  lcd.print("Poor Air");
}
else
  lcd.print("Toxic Air");



delay(500);                       //  wait 500ms for next reading

}
