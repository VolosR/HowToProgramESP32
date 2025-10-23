#include <Arduino_GFX_Library.h>

#define LCD_ROTATION 1
#define LCD_H_RES 240
#define LCD_V_RES 320
#define LCD_BL 1


Arduino_DataBus *bus = new Arduino_ESP32SPI(42 /* DC */, 45 /* CS */,39 /* SCK */, 38 /* MOSI */, 40 /* MISO */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, -1 /* RST */, LCD_ROTATION /*rotation*/, true /* IPS */,LCD_H_RES /*width*/, LCD_V_RES /*height*/);

void setup() {
  Serial.begin(115200);

  gfx->begin();
  gfx->setRotation(0);
  gfx->displayOn();

  gfx->fillScreen(BLACK);
  gfx->setTextSize(2);
  gfx->setCursor(50,50);
  gfx->setTextColor(GREEN);
  gfx->print("Helllo World");
  

  analogWrite(LCD_BL,150); //0-255

}

void loop() {
  // put your main code here, to run repeatedly:

}
