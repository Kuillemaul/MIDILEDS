#include <FastLED.h>
#include <RotaryEncoder.h>
#include <MIDI.h>  // Add Midi Library

// LED STRIP PIN FOR EACH MIDI DRUM
#define TOM1PIN 31
#define TOM2PIN 33
#define TOM3PIN 35
#define SNAREPIN 37
#define BASSPIN 39
#define HIHATPIN 41
#define CRASHPIN 43
#define RIDEPIN 45

//DEBUG AND TESTING
#define ledPin 7 //DEBUG LED PIN
#define button1Pin 5       //PAD CHANGE IN PLACE OF MIDI HIT
#define modeButton 2       //CHANGE MODE Center Encoder Button
//NUMBER OF LEDS PER MIDI DRUM

#define TOM1LEDS 0
#define TOM2LEDS 1
#define TOM3LEDS 2
#define SNARELEDS 3
#define BASSLEDS 4
#define HIHATLEDS 5
#define CRASHLEDS 6
#define RIDELEDS 7


#define TOM1LEDS 34
#define TOM2LEDS 34
#define TOM3LEDS 34
#define SNARELEDS 54
#define BASSLEDS 67
#define HIHATLEDS 30
#define CRASHLEDS 37
#define RIDELEDS 37
#define NUM_LEDS TOM1LEDS+TOM2LEDS+TOM3LEDS+SNARELEDS+BASSLEDS+HIHATLEDS+CRASHLEDS+RIDELEDS // TOTAL LEDS
#define NUM_STRIPS  8  // TOTAL STRIPS

// Encoder Settings
#define PIN_IN1 4 //UP PIN
#define PIN_IN2 3 //DOWN PIN

#define COLORROTARYSTEPS 3
#define SPEEDROTARYSTEPS 1
#define colormin 0 // COLOR SETTINGS
#define colormax 255

#define speedmin 0 // SPEED SETTING
#define speedmax 200

// PATTERN SPECIFIC SETTINGS
#define FRAMES_PER_SECOND  120
#define SPARKING 190
#define COOLING  55

//DEFAULTS AND VARIABLES

MIDI_CREATE_DEFAULT_INSTANCE();

volatile byte mode = 0; //INTERUPT FOR MODE SETTING ENCODER BUTTON
volatile byte padHit = 0;

String padName = "none";
unsigned long previousTime = 0;
unsigned long startMillis = millis();

//Drum Defaults

byte brightness = 100;

byte setspeed = 1;   // FADE SPEED

byte tom1Color = 45; // COLOR
byte tom2Color = 160;
byte tom3Color = 95;
byte snareColor = 0;
byte bassColor = 210;
byte hihatColor = 45;
byte crashColor = 160;
byte rideColor = 95;

//ENCODER
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);
int lastPos = -1;
byte colorpos = 0;

// CREATE STRIP ARRAYS
CRGB tom1strip[TOM1LEDS];
CRGB tom2strip[TOM1LEDS];
CRGB tom3strip[TOM1LEDS];
CRGB snarestrip[SNARELEDS];
CRGB bassstrip[BASSLEDS];
CRGB hihatstrip[HIHATLEDS];
CRGB crashstrip[CRASHLEDS];
CRGB ridestrip[RIDELEDS];
CRGB leds[NUM_LEDS];
CLEDController *controllers[NUM_STRIPS];



void setup() {

  //Serial.begin (115200);  // SERIAL DEBUG
  pinMode (ledPin, OUTPUT);
  pinMode (button1Pin, INPUT);
  delay(2000); // PROTECTION DELAY
  //Serial.println("Hello World");                     // TEST PRINT I AM ALIVE

  // CREATE LED STRIPS

//  controllers[0] = &FastLED.addLeds<WS2812, TOM1PIN, GRB>(tom1strip, TOM1LEDS);
//  controllers[1] = &FastLED.addLeds<WS2812, TOM2PIN, GRB>(tom2strip, TOM2LEDS);
//  controllers[2] = &FastLED.addLeds<WS2812, TOM3PIN, GRB>(tom3strip, TOM3LEDS);
//  controllers[3] = &FastLED.addLeds<WS2812, SNAREPIN, GRB>(snarestrip, SNARELEDS);
//  controllers[4] = &FastLED.addLeds<WS2812, BASSPIN, GRB>(bassstrip, BASSLEDS);
//  controllers[5] = &FastLED.addLeds<WS2812, HIHATPIN, GRB>(hihatstrip, HIHATLEDS);
//  controllers[6] = &FastLED.addLeds<WS2812, CRASHPIN, GRB>(crashstrip, CRASHLEDS);
//  controllers[7] = &FastLED.addLeds<WS2812, RIDEPIN, GRB>(ridestrip, RIDELEDS);
//
//  leds[0] = &tom1strip[0];
//  leds[1] = &tom2strip[0];
//  leds[2] = &tom3strip[0];
//  leds[3] = &snarestrip[0];
//  leds[4] = &bassstrip[0];
//  leds[5] = &hihatstrip[0];
//  leds[6] = &crashstrip[0];
//  leds[7] = &ridestrip[0];

// TESTING NEW CODE FOUND IN https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples I will also change the order and see if that chnages the outcome. 
FastLED.addLeds<WS2812B, HIHATPIN, GRB>(hihatstrip, HIHATLEDS);
FastLED.addLeds<WS2812B, CRASHPIN, GRB>(crashstrip, CRASHLEDS);
FastLED.addLeds<WS2812B, RIDEPIN, GRB>(ridestrip, RIDELEDS);
FastLED.addLeds<WS2812B, TOM1PIN, GRB>(tom1strip, TOM1LEDS);
FastLED.addLeds<WS2812B, TOM2PIN, GRB>(tom2strip, TOM2LEDS);
FastLED.addLeds<WS2812B, TOM3PIN, GRB>(tom3strip, TOM3LEDS);
FastLED.addLeds<WS2812B, SNAREPIN, GRB>(snarestrip, SNARELEDS);
FastLED.addLeds<WS2812B, BASSPIN, GRB>(bassstrip, BASSLEDS);


  attachInterrupt(digitalPinToInterrupt(modeButton), modechange, CHANGE); // Mode Change Interrupt
  attachInterrupt(digitalPinToInterrupt(button1Pin), padchange, CHANGE); // Mode Change Interrupt
  //pinMode(save, INPUT_PULLUP); //Pinmode for Encoder

  // TEST LED STRIPS

  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
  FastLED[0].showLeds(125);
  delay(1000);
  fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
  delay(1000);
  FastLED[1].showLeds(125);
  fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
  FastLED[2].showLeds(125);
  delay(1000);
  fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
  delay(1000);
  FastLED[3].showLeds(125);
  fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
  FastLED[4].showLeds(125);
  delay(1000);
  fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
  FastLED[5].showLeds(125);
  delay(1000);
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
  delay(1000);
  FastLED[6].showLeds(125);
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
  FastLED[7].showLeds(125);
  delay(1000);

  for (int i = 0; i < NUM_STRIPS; i++) {
    FastLED[i].showLeds(0);  //Should turn the leds off?
  }  

//  fill_solid(tom1strip, TOM1LEDS, CHSV(0, 0, 0));
//  fill_solid(tom2strip, TOM2LEDS, CHSV(0, 0, 0));
//  fill_solid(tom3strip, TOM3LEDS, CHSV(0, 0, 0));
//  fill_solid(snarestrip, SNARELEDS, CHSV(0, 0, 0));
//  fill_solid(bassstrip, BASSLEDS, CHSV(0, 0, 0));
//  fill_solid(hihatstrip, HIHATLEDS, CHSV(0, 0, 0));
//  fill_solid(crashstrip, CRASHLEDS, CHSV(0, 0, 0));
//  fill_solid(ridestrip, RIDELEDS, CHSV(0, 0, 0));
//
//  controllers[0]->showLeds();
//  controllers[1]->showLeds();
//  controllers[2]->showLeds();
//  controllers[3]->showLeds();
//  controllers[4]->showLeds();
//  controllers[5]->showLeds();
//  controllers[6]->showLeds();
//  controllers[7]->showLeds();

  delay(2000);

  startMillis = millis();

  MIDI.setHandleNoteOn(MyHandleNoteOn); // Calls when not is on
  MIDI.begin(10); // Initialize the Midi Library on channel 10  
  MIDI. turnThruOff();

}
// PATTERNS SETUP

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm, };
uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
//bool gReverseDirection = false; // FIRE ANIMATION

void loop() {

  MIDI.read(); // Continuously check if Midi data has been received.

  // CHECK IF AN EDIT MODE IS ENABLED

  if (mode > 0) {
    switch(mode) {
      case 1: 
        patterns();
        break;
      case 2: 
        coloredit();
        break;
      case 3: 
        fade();
        break;
      default:
        break;
    }
  }
  /* THIS FADES THE LED STRIP */
  unsigned long currentTime = millis();
  if (currentTime - previousTime >=  setspeed) {
    /* Event code */
    fadeToBlackBy(tom1strip, TOM1LEDS, 1);
    fadeToBlackBy(tom2strip, TOM2LEDS, 1);
    fadeToBlackBy(tom3strip, TOM3LEDS, 1);
    fadeToBlackBy(snarestrip, SNARELEDS, 1);
    fadeToBlackBy(bassstrip, BASSLEDS, 1);
    fadeToBlackBy(hihatstrip, HIHATLEDS, 1);
    fadeToBlackBy(crashstrip, CRASHLEDS, 1);
    fadeToBlackBy(ridestrip, RIDELEDS, 1);

  
  for (int i = 0; i < NUM_STRIPS; i++) {
    FastLED[i].showLeds();  //Show Leds fading?
  } 
  } 
//  for (int i = 0; i < NUM_STRIPS; i++) {
//    controllers[i]->showLeds();
//  }  
}
