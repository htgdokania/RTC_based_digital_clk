#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
RTC_DS1307 RTC;
void setup () {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
    DateTime now = RTC.now();
                           
  display.setTextSize(2);                            
  display.setTextColor(WHITE,BLACK);
  display.setCursor(20,4);                           
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.print(':');
  display.print(now.second(), DEC);
  
  display.setTextSize(1);                            
  display.setTextColor(WHITE,BLACK);
  display.setCursor(35,22);
  display.print(now.year(), DEC);
  display.print('/');
  display.print(now.month(), DEC);
  display.print('/');
  display.print(now.day(), DEC);
  display.display();
  display.clearDisplay();
 
}
