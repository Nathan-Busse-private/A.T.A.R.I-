#include <LiquidCrystal_I2C.h>
//#include <wire.h>
//I2C addess 0x27

//int period = 1000;
//unsigned long time_now = 1000;


LiquidCrystal_I2C lcd(0x27,16,2); //16x2 display
void setup()
{
  lcd.init();// initialize the lcd 
  lcd.backlight();// Backlight ON
  lcd.setCursor(1,0);// 2nd column,1st row
  lcd.print("Powering On!");
  lcd.setCursor(1,2);// 1st column,3nd row
  lcd.print("Ready");
  
  //delay(0);
}

void loop()
{
  lcd.init();// initialize the lcd 
  lcd.backlight();// Backlight ON
  lcd.setCursor(1,0);// 2nd column,1st row
  lcd.print("Powering On!");
 
  lcd.clear();
  
  lcd.setCursor(5,19);
  lcd.println("A.T.A.R.I");
  lcd.setCursor(19,12);   //Move cursor to character 2 on line 1
  lcd.print(" Made by Nathan Busse");
delay(15000);

        
        lcd.noBacklight();

        delay(43200000);
  
        
}  

  
