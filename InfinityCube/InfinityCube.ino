//https://colorpicker.me/#f5e6fb

#include "FastLED.h"
#define NumPixels 120
#define DataPin 2
 
CRGB leds[NumPixels];
CHSV kleur = CHSV(135, 255, 255);

int corners[8][6][2] = {
    {70, -69, 55, -54, -14, 15},
    {-24, 25, 80, -99, -114, 115}
  };

void setup()
{
 Serial.begin(9600);
 FastLED.addLeds<WS2812, DataPin, BGR>(leds, NumPixels);
 fill_solid(leds, NumPixels, CRGB(0,0,0));
 FastLED.show();
 delay(1000);
}

void loop() 
{
    fromCorner(0, 100, false);
    delay(0);
    //fill_solid(leds, NumPixels, CRGB(0,0,0));
    //FastLED.show();
    delay(0);
    toCorner(1, 100, true);
    delay(0);
    fill_solid(leds, NumPixels, CRGB(0,0,0));
    //FastLED.show();
    delay(0);
    fromCorner(1, 100, false);
    delay(0);
    //fill_solid(leds, NumPixels, CRGB(0,0,0));
    //FastLED.show();
    delay(0);
    toCorner(0, 100, true);
    delay(0);
    fill_solid(leds, NumPixels, CRGB(0,0,0));
    //FastLED.show();
    delay(0);
}

void fromCorner(int corner, int wait, bool invert){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
        int multiplier = abs(corners[corner][j]) / corners[corner][j];
        int value;
        if(invert){
            value = (i + 1) * 20;
          } else {
              value = 100 - ((i - 1) * 20);
            }
        leds[abs(corners[corner][j]) + (i * multiplier)] = CHSV(135, 255, value);
      }
      FastLED.show();
      delay(wait);
    }
  }
void toCorner(int corner, int wait, bool invert){
  for(int i = 4; i >= 0; i--){
    for(int j = 0; j < 6; j++){
        int multiplier = abs(corners[corner][j]) / corners[corner][j];
        int value;
        if(invert){
            value = (i + 1) * 20;
          } else {
              value = 100 - ((i - 1) * 20);
            }
        leds[abs(corners[corner][j]) + (i * multiplier)] = CHSV(135, 255, value);
      }
      FastLED.show();
      delay(wait);
    }
  }
