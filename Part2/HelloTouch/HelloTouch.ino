#include <Arduino_GFX_Library.h>
#include <bb_captouch.h>

#define LCD_ROTATION 1
#define LCD_H_RES 240
#define LCD_V_RES 320
#define LCD_BL 1

Arduino_DataBus *bus = new Arduino_ESP32SPI(42 /* DC */, 45 /* CS */,39 /* SCK */, 38 /* MOSI */, 40 /* MISO */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, -1 /* RST */, LCD_ROTATION /*rotation*/, true /* IPS */,LCD_H_RES /*width*/, LCD_V_RES /*height*/);

static BBCapTouch touch;

int boxSize=80;
int xcor=80;
int ycor1=20;
int ycor2=120;
int ycor3=220;


void setup() {
  Serial.begin(115200);

  gfx->begin();
  gfx->setRotation(0);
  gfx->displayOn();

  touch.init(48, 47, -1, -1, 400000); 
  touch.setOrientation(0, LCD_H_RES, LCD_V_RES);

  gfx->fillScreen(BLACK);
  gfx->setTextSize(2);

  gfx->fillRect(xcor,ycor1,boxSize,boxSize,RED);
  gfx->fillRect(xcor,ycor2,boxSize,boxSize,GREEN);
  gfx->fillRect(xcor,ycor3,boxSize,boxSize,BLUE);

  
  analogWrite(LCD_BL,150); //0-255 brightness
}

void loop() {
  TOUCHINFO ti;

    if (touch.getSamples(&ti) && ti.count > 0) {
    Serial.println(ti.x[0]);

   // IF RED IS TOUCHED
    if(ti.x[0]>xcor && ti.x[0]<xcor+boxSize &&  ti.y[0]>ycor1 && ti.y[0]<ycor1+boxSize)
    {
         gfx->fillRect(0,0,70,30,BLACK);
         gfx->setCursor(10,10);
         gfx->print("RED");
    }

    // IF GREEN IS TOUCHED
      if(ti.x[0]>xcor && ti.x[0]<xcor+boxSize && ti.y[0]>ycor2 && ti.y[0]<ycor2+boxSize)
    {
         gfx->fillRect(0,0,70,30,BLACK);
         gfx->setCursor(10,10);
         gfx->print("GREEN");
    }

    // IF BLUE IS TOUCHED
      if(ti.x[0]>xcor && ti.x[0]<xcor+boxSize && ti.y[0]>ycor3 && ti.y[0]<ycor3+boxSize)
    {
         gfx->fillRect(0,0,70,30,BLACK);
         gfx->setCursor(10,10);
         gfx->print("BLUE");
    }

 
    }

}