#include <Wire.h>
#include <FastLED.h>
#include "objects.h"
#include "capsensor.h"



#define NUM_BUTTONS 5
#define NUM_LEDS 10
#define DATA_PIN 6
CRGB leds[NUM_LEDS];



bool buttonState[NUM_BUTTONS];

Button buttons[4] = {   Button( 0, "About Fab", NULL, 1),
                        Button( 1, "Digital Design", 0, 2),
                        Button( 2, "Illustrator", 1, 3),
                        Button( 3, "Vinyl Cutter", 2, NULL)
                     };


int ledRef[5][10] = {
  {3, 3, 1, 1, 1, 1, 1, 1, 1, 1}, //aboutfab
  {2, 2, 2, 3, 1, 1, 0, 0, 0, 0}, //laserintro
  {2, 2, 2, 2, 2, 3, 0, 0, 0, 0}, //lasermachine
  {2, 2, 0, 0, 0, 0, 1, 1, 3, 2}, //printerintro
  {2, 2, 0, 0, 0, 0, 3, 2, 2, 2}, //printermachine
};



int ledMain[5] = {1, 3, 5, 8, 6};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);

  FastLED.setBrightness(50);

  for (int i = 0; i < NUM_BUTTONS; i++) {

  }
}




void loop() {
  // put your main code here, to run repeatedly:
  readWire(NUM_BUTTONS, buttonState);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (buttonState[i] == 1) {
      for (int l = 0; l < NUM_LEDS; l++) {

        if (ledRef[i][l] == 1) { //after
          leds[l] = CRGB::Red;
        } else if (ledRef[i][l] == 2) { //before
          leds[l] = CRGB::Green;
        } else if (ledRef[i][l] == 3) { //on
          leds[l] = CRGB::Orange;
        } else { //off
          leds[l] = CRGB::Black;
        }
      }
      //        leds[ledMain[i]] = CRGB::Green;
    }
  }
  FastLED.show();
}



