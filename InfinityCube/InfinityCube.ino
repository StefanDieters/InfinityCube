//https://colorpicker.me/#f5e6fb

#include "FastLED.h"
#define NumPixels 120
#define DataPin 2
 
CRGB leds[NumPixels];
CHSV kleur = CHSV(135, 255, 255);

int corners[8][6] = {
    {70, -69, 55, -54, -14, 15}
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
    fromCorner(0, 100);
    delay(1000);
    fill_solid(leds, NumPixels, CRGB(0,0,0));
    FastLED.show();
    delay(250);
}

void fromCorner(int corner, int wait){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
        int multiplier = abs(corners[corner][j]) / corners[corner][j];
        Serial.println(abs(corners[corner][j]) + (i * multiplier));
        leds[abs(corners[corner][j]) + (i * multiplier)] = CHSV(135, 255, 100 - ((100/5) * i));
      }
      FastLED.show();
      delay(wait);
    }
  }
void toCorner(int corner, int wait){
  for(int i = 4; i > 0; i--){
    for(int j = 0; j < 6; j++){
        int multiplier = abs(corners[corner][j]) / corners[corner][j];
        Serial.println(abs(corners[corner][j]) + (i * multiplier));
        leds[abs(corners[corner][j]) + (i * multiplier)] = CHSV(135, 255, 100 - ((100/5) * i));
      }
      FastLED.show();
      delay(wait);
    }
  }
