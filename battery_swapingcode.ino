//https://www.instructables.com/Voltage-Measurement-Using-Arduino/#:~:text=With%20a%20slight%20modification%20in,R1%20%2B%20R2)%2FR2)%3B
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define b1p A0
#define b2p A1
#define rly A5
int b1v = 0;
int b2v = 0;
float b1volt;
float b2volt;
float R1 = 47000.0;
float R2 = 33000.0;
void setup()
{
  pinMode(b1p, INPUT);
  pinMode(b2p, INPUT);
  pinMode(rly, OUTPUT);
  digitalWrite(rly, LOW);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AUTO LOW BATTERY");
  lcd.setCursor(0, 1);
  lcd.print(" SWAPING SYSTEM ");
  delay(2000);
}
void loop()
{
  b1v = analogRead(A0);
  b2v = analogRead(A1);
  b1volt = b1v * (5.0 / 1024) * ((R1 + R2) / R2);
  b2volt = b2v * (5.0 / 1024) * ((R1 + R2) / R2);
  b1volt = b1volt + 1;
  b2volt = b2volt + 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("B1 ");
  lcd.print(b1volt);
  lcd.print(" B2 ");
  lcd.print(b2volt);
  if (b1volt < 8 and b2volt>8 or b1volt<8 and b2volt<8) {
    digitalWrite(rly, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" BAT 1 CHARGING ");
  }
  if (b2volt < 8 and b1volt>8) {
    digitalWrite(rly, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(" BAT 2 CHARGING ");
  }
  if(b1volt>8 and b2volt>8){
    digitalWrite(rly, LOW);
  }

  delay(100);
} 

