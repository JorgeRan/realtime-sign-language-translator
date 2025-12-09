#include <LiquidCrystal_I2C.h>
#include <Wire.h>

String incoming = "";
unsigned long lastScroll = 0;
unsigned long lastGestureTime = 0;
int scrollIndex = 0;

#define SDA 13
#define SCL 14

LiquidCrystal_I2C lcd(0x27, 16, 2);

String error = "No Gesture Detected";
bool gestureActive = false;

void setup() {
  Wire.begin(SDA, SCL);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Detected Gestures:");
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      incoming.trim();

      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(incoming);

      lastGestureTime = millis();  
      gestureActive = true;        
      incoming = "";
      scrollIndex = 0;
      return;
    } else {
      incoming += c;
    }
  }

  
  if (gestureActive) {
    if (millis() - lastGestureTime >= 2000) { 
      gestureActive = false;  
    } else {
      return; 
    }
  }

  if (millis() - lastScroll >= 300) {
    lastScroll = millis();

    if (scrollIndex > error.length() - 16)
      scrollIndex = 0;

    lcd.setCursor(0, 1);
    lcd.print(error.substring(scrollIndex, scrollIndex + 16));
    scrollIndex++;
  }
}
