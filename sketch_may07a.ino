// Подключаем стандартную библиотеку LiquidCrystal
#include <LiquidCrystal.h>
unsigned int StartTime=0,SetTime=0;
int den=170;
// Инициализируем объект-экран, передаём использованные 
// для подключения контакты на Arduino в порядке:
// RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
 
void setup() 
{
    // устанавливаем размер (количество столбцов и строк) экрана
pinMode(0, INPUT);
    lcd.begin(16, 2);delay(17);
    // печатаем первую строку
  

}
 
void loop() 
{
  int startDist=analogRead(A0);
  int diff;
  
  while(diff<den){
    diff=abs(analogRead(A0)-startDist);
    lcd.setCursor(0, 1);lcd.print(diff);
    lcd.setCursor(0, 0);lcd.print("Timer stable");
    lcd.setCursor(12, 1);lcd.print(analogRead(A0));
    delay(1);
    }
  StartTime=millis();
  lcd.setCursor(0, 0);
  lcd.print("start          ");
  
 while(millis()-StartTime<2000){lcd.setCursor(8, 0);
  lcd.print(millis()-StartTime);}
 diff=abs(analogRead(A0)-startDist);
  while(diff<den)
   {diff=abs(analogRead(A0)-startDist);delay(1);
    lcd.setCursor(8, 0);
    lcd.print(millis()-StartTime);
    }
  SetTime=millis()-StartTime;
  lcd.setCursor(0, 0);
  lcd.print("Finish            ");
  lcd.setCursor(0, 1);
  lcd.print("Time");
  lcd.setCursor(5, 1);
  lcd.print(SetTime);
  delay(1999);
  while(digitalRead(0)==1){}
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  lcd.setCursor(0, 0);
  lcd.print("                ");
  
}
