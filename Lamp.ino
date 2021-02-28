/*-------------------------------------------
Author : Anuj Mahendra Mutha
Website : https://www.anujmutha.com 
LinkedIn : https://www.linkedin.com/in/anujmutha/
Github : https://github.com/AnujMutha
Instagram : https://www.instagram.com/anuj.mutha/
Facebook : https://www.facebook.com/anuj.mutha.31  
Twitter : https://twitter.com/anuj_mutha
--------------------------------------------*/
#include <FastLED.h>
#define NUM_LEDS 5
#define DATA_PIN 3
int touchCount = 1;

CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.clear();
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.setBrightness(255);
}

void loop() 
{
  Serial.print(digitalRead(7));
  if(digitalRead(7) == HIGH || digitalRead(7) == 1)
  {
    touchCount += 1;
    switch(touchCount)
    {        
      case 1:
        initLEDS(255, 147, 41);
        break;
      case 2:
        initLEDS(255, 197, 143);
        break;
      case 3:
        initLEDS(255, 214, 170);
        break;
      case 4:
        initLEDS(255, 241, 224);
        break;
      case 5:
        initLEDS(255, 255, 255);
        break;
      case 6:
        initLEDS(201, 226, 255);
        break;
      case 7:
        initLEDS(74, 167, 245);
        break;
      case 8:
        initLEDS(255,0,0);
        break;
      case 9:
        initLEDS(0,255,0);
        break;
      case 10:
        initLEDS(0,0,255);
        break; 
    }
    if(touchCount == 11)
    {
      touchCount = 0;
    }
  }
  delay(750);
}


void initLEDS(int r,int g,int b)
{
  int i = 0;
  while(i<=NUM_LEDS)
  {
    leds[i].setRGB(r,g,b);
    i++;
  }
  FastLED.show();
}
