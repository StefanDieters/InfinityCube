//https://colorpicker.me/#f5e6fb

#include "FastLED.h"
#define NumPixels 120
#define DataPin 2
 
CRGB leds[NumPixels];
CHSV kleur = CHSV(135, 255, 255);

int strip[6][20];

void setup()
{
 Serial.begin(9600);
 FastLED.addLeds<WS2812, DataPin, BGR>(leds, NumPixels);
 fill_solid(leds, NumPixels, CRGB(0,0,0));
 //FastLED.setBrightness(10);
 FastLED.show();
 delay(1000);
}

void loop() 
{
 for(int i = 0; i < 5; i++){
  leds[i+70] = CHSV(135, 255, 100-((100/5)*i));
  FastLED.show();
  delay(50);
 }
 delay(1000);
 fill_solid(leds, NumPixels, CRGB(0,0,0));
 FastLED.show();
 delay(250);
}
