#include <Arduino.h>
#include <FastLED.h>
#include <RotaryEncoder.h>
#include <MIDI.h>  // Add Midi Library
#include "SparkFun_Qwiic_Twist_Arduino_Library.h"

// LED STRIP PIN FOR EACH MIDI DRUM
#define TOM1PIN 2
#define TOM2PIN 3
#define TOM3PIN 4
#define SNAREPIN 5
#define BASSPIN 6
#define HIHATPIN 7
#define CRASHPIN 8
#define RIDEPIN 9

//CONTROLLER NUMBERS

#define TOM1LEDS 0
#define TOM2LEDS 1
#define TOM3LEDS 2
#define SNARELEDS 3
#define BASSLEDS 4
#define HIHATLEDS 5
#define CRASHLEDS 6
#define RIDELEDS 7

//NUMBER OF LEDS PER MIDI DRUM

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

// PATTERN SPECIFIC SETTINGS
#define FRAMES_PER_SECOND  120
#define SPARKING 190
#define COOLING  55

//--------------------DEFAULTS AND VARIABLES

byte mode = 0; 
volatile byte padHit = 0;

String padName = "none";

//Drum Defaults


// PAD BRIGHTNESS

byte tom1Brightness = 255; 
byte tom2Brightness = 255;
byte tom3Brightness = 255;
byte snareBrightness = 255;
byte bassBrightness = 255;
byte hihatBrightness = 255;
byte crashBrightness = 255;
byte rideBrightness = 255; 

// MIN BRIGHTNESS

minBrightness = 0;

// FADE SPEED

byte tom1Fade = 1; 
byte tom2Fade = 1;
byte tom3Fade = 1;
byte snareFade = 1;
byte bassFade = 1;
byte hihatFade = 1;
byte crashFade = 1;
byte rideFade = 1;  

// COLOR

byte tom1Color = 45; 
byte tom2Color = 160;
byte tom3Color = 95;
byte snareColor = 0;
byte bassColor = 210;
byte hihatColor = 45;
byte crashColor = 160;
byte rideColor = 95;

// CREATE STRIP ARRAYS
CRGB hihatstrip[HIHATLEDS];
CRGB crashstrip[CRASHLEDS];
CRGB ridestrip[RIDELEDS];
CRGB tom1strip[TOM1LEDS];
CRGB tom2strip[TOM1LEDS];
CRGB tom3strip[TOM1LEDS];
CRGB snarestrip[SNARELEDS];
CRGB bassstrip[BASSLEDS];
CRGB leds[NUM_LEDS];
CLEDController *controllers[NUM_STRIPS];

TWIST twist

void setup() {

  Serial.begin (115200);  // SERIAL DEBUG

  delay(2000); // PROTECTION DELAY
  Serial.println("Hello World");                     // TEST PRINT I AM ALIVE
  if (twist.begin() == false)
  {
    Serial.println("Twist does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }

  int currentVersion = twist.getVersion();

  if (currentVersion < 0x0201) //v1.2 in two byte form
  {
    Serial.print("The current firmware version is: ");
    Serial.print(currentVersion & 0xFF);
    Serial.print(".");
    Serial.println(currentVersion >> 8);

    Serial.println("This feature is not supported. Please consider upgrading the firmware on your Qwiic Twist. Freezing.");
    while (1); //Freeze
  }

  // CREATE LED STRIPS
// TESTING NEW CODE FOUND IN https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples I will also change the order and see if that chnages the outcome. 
FastLED.addLeds<WS2812B, HIHATPIN, GRB>(hihatstrip, HIHATLEDS);
FastLED.addLeds<WS2812B, CRASHPIN, GRB>(crashstrip, CRASHLEDS);
FastLED.addLeds<WS2812B, RIDEPIN, GRB>(ridestrip, RIDELEDS);
FastLED.addLeds<WS2812B, TOM1PIN, GRB>(tom1strip, TOM1LEDS);
FastLED.addLeds<WS2812B, TOM2PIN, GRB>(tom2strip, TOM2LEDS);
FastLED.addLeds<WS2812B, TOM3PIN, GRB>(tom3strip, TOM3LEDS);
FastLED.addLeds<WS2812B, SNAREPIN, GRB>(snarestrip, SNARELEDS);
FastLED.addLeds<WS2812B, BASSPIN, GRB>(bassstrip, BASSLEDS);


  // TEST LED STRIPS

  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, hihatBrightness));
  FastLED[0].showLeds(125);
  delay(1000);
  fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, crashBrightness));
  delay(1000);
  FastLED[1].showLeds(125);
  fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, rideBrightness));
  FastLED[2].showLeds(125);
  delay(1000);
  fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, tom1Brightness));
  delay(1000);
  FastLED[3].showLeds(125);
  fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, tom2Brightness));
  FastLED[4].showLeds(125);
  delay(1000);
  fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, tom3Brightness));
  FastLED[5].showLeds(125);
  delay(1000);
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, snareBrightness));
  delay(1000);
  FastLED[6].showLeds(125);
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, bassBrightness));
  FastLED[7].showLeds(125);
  delay(1000);

  for (int i = 0; i < NUM_STRIPS; i++) {
    FastLED[i].showLeds(0);  //Should turn the leds off?
  }  

usbMIDI.setHandleNoteOn(MyHandleNoteOn);
  
}
// PATTERNS SETUP

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm, };
uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
//bool gReverseDirection = false; // FIRE ANIMATION

void loop() {

  usbMIDI.read(); // Continuously check if Midi data has been received.
if(twist.isClicked()) setMode ++;

  // CHECK IF AN EDIT MODE IS ENABLED

  if (setMode == 1) {
    editMode();
  }
  if (setEdit == 1 ) {
    colorEdit ();
  }
  if (setEdit == 3 ) {
    fade();
  }
  //if (setMode == 4 ) { // FUTURE DEVELOPMENT
  //  setMinBrightness();
  //}
  if (setMode == 2) {
    patterns();
  }
  }
  /* THIS FADES THE LED STRIP */
 EVERY_N_MILLISECONDS (5) {
    if ((hihatBrightness) > (minBrightness)) {
      hihatBrightness-(hihatFade);
      FastLED[0].showLeds(hihatBrightness);
    }
    if ((snareBrightness) > (minBrightness)) {
      snareBrightness-(snareFade);
      FastLED[1].showLeds(snareBrightness);
    }
    if (bassBrightness > minBrightness) {
      bassBrightness-(bassFade);
      FastLED[2].showLeds(bassBrightness);
    }
}
