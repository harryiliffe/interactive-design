#include <Wire.h>
#include <FastLED.h>
#define ttp229 (0xAF>>1)
#define NUM_BUTTONS 5

#define NUM_LEDS 10
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

uint16_t data_out=0;
uint16_t data1,data2;

bool buttonState[NUM_BUTTONS];
bool buttonSent[NUM_BUTTONS];

//int aboutFab[8] = [2,3,4,5,6,7,8,9];
//int laserIntro[4] = [0,1,4,5];
//int laserMachine[5] = [0,1,2,3,4];
//int PrinterIntro[5] = [0,1,9,7,6];
//int PrinterMachine[6] = [0,1,9,8,7,6];

int ledRef[5][10] = {
  {0,0,1,1,1,1,1,1,1,1},
  {1,1,0,1,1,1,0,0,0,0},
  {1,1,1,1,1,0,0,0,0,0},
  {1,1,0,0,0,0,1,1,0,1},
  {1,1,0,0,0,0,1,1,1,1},
};

int ledMain[5] = {1,3,5,8,6};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); 
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  
  FastLED.setBrightness(50);
}




void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(ttp229,2,true);
  while(Wire.available())
  {
    data1=Wire.read();
    data2=Wire.read();
    data_out=(data1<<8)|data2;
    for(int i=0;i<NUM_BUTTONS;i++){
      buttonState[i] = bitRead(data_out, i);
      Serial.print(buttonState[i]);
    }
    Serial.println();
  }
  for(int i=0; i<NUM_BUTTONS;i++){
     if(buttonState[i]==1){
        for(int l=0;l<NUM_LEDS;l++){
          
          if(ledRef[i][l] == 1){
            leds[l] = CRGB::White;
          } else {
            leds[l] = CRGB::Black;
          }
        }
        leds[ledMain[i]] = CRGB::Purple;
     }
  }
  FastLED.show();
}

