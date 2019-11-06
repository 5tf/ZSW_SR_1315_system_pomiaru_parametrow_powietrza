//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHT11_PIN 2
DHT dht;
unsigned long time;
LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //lcd.setCursor(3,0);
  //lcd.print("56");
  lcd.setCursor(6,0);
  lcd.print("% ");
  lcd.setCursor(6,1);
  lcd.print("*C");
}


void loop()
{
  //czas od włączenia programu
  time = millis();
  int timeS = time/1000;
  lcd.setCursor(0,0);
  lcd.print(timeS);
  
  //Odczyt wilgotnosci
  int wilgotnosc = dht.getHumidity();
  lcd.setCursor(4,0);
  lcd.print(wilgotnosc);
  Serial.println(wilgotnosc);
 
  //Odczyt temperatury
  int temperatura = dht.getTemperature();
  lcd.setCursor(4,1);
  lcd.print(temperatura);
  Serial.println(temperatura);
 
  delay(1000);
}
