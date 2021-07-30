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
#define TOM1LEDS 34
#define TOM2LEDS 34
#define TOM3LEDS 34
#define SNARELEDS 54
#define BASSLEDS 67
#define HIHATLEDS 30
#define CRASHLEDS 37
#define RIDELEDS 37
#define NUM_LEDS 327  // TOTAL LEDS
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

byte brightness = 125;

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

  controllers[0] = &FastLED.addLeds<WS2811, TOM1PIN, GRB>(tom1strip, TOM1LEDS);
  controllers[1] = &FastLED.addLeds<WS2811, TOM2PIN, GRB>(tom2strip, TOM2LEDS);
  controllers[2] = &FastLED.addLeds<WS2811, TOM3PIN, GRB>(tom3strip, TOM3LEDS);
  controllers[3] = &FastLED.addLeds<WS2811, SNAREPIN, GRB>(snarestrip, SNARELEDS);
  controllers[4] = &FastLED.addLeds<WS2811, BASSPIN, GRB>(bassstrip, BASSLEDS);
  controllers[5] = &FastLED.addLeds<WS2811, HIHATPIN, GRB>(hihatstrip, HIHATLEDS);
  controllers[6] = &FastLED.addLeds<WS2811, CRASHPIN, GRB>(crashstrip, CRASHLEDS);
  controllers[7] = &FastLED.addLeds<WS2811, RIDEPIN, GRB>(ridestrip, RIDELEDS);

  attachInterrupt(digitalPinToInterrupt(modeButton), modechange, CHANGE); // Mode Change Interrupt
  attachInterrupt(digitalPinToInterrupt(button1Pin), padchange, CHANGE); // Mode Change Interrupt
  //pinMode(save, INPUT_PULLUP); //Pinmode for Encoder

  // TEST LED STRIPS

  fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
  delay(1000);
  controllers[0]->showLeds(125);
  fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
  controllers[1]->showLeds(125);
  delay(1000);
  fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
  controllers[2]->showLeds(125);
  delay(1000);
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
  delay(1000);
  controllers[3]->showLeds(125);
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
  controllers[4]->showLeds(125);
  delay(1000);
  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
  controllers[5]->showLeds(125);
  delay(1000);
  fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
  delay(1000);
  controllers[6]->showLeds(125);
  fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
  controllers[7]->showLeds(125);
  delay(1000);

  fill_solid(tom1strip, TOM1LEDS, CHSV(0, 0, 0));
  fill_solid(tom2strip, TOM2LEDS, CHSV(0, 0, 0));
  fill_solid(tom3strip, TOM3LEDS, CHSV(0, 0, 0));
  fill_solid(snarestrip, SNARELEDS, CHSV(0, 0, 0));
  fill_solid(bassstrip, BASSLEDS, CHSV(0, 0, 0));
  fill_solid(hihatstrip, HIHATLEDS, CHSV(0, 0, 0));
  fill_solid(crashstrip, CRASHLEDS, CHSV(0, 0, 0));
  fill_solid(ridestrip, RIDELEDS, CHSV(0, 0, 0));

  controllers[0]->showLeds();
  controllers[1]->showLeds();
  controllers[2]->showLeds();
  controllers[3]->showLeds();
  controllers[4]->showLeds();
  controllers[5]->showLeds();
  controllers[6]->showLeds();
  controllers[7]->showLeds();

  delay(2000);

  startMillis = millis();

  MIDI.setHandleNoteOn(MyHandleNoteOn); // Calls when not is on
  MIDI.begin(10); // Initialize the Midi Library on channel 10

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

  if (mode == 1) {
    patterns();
  }

  if (mode == 2) {
    coloredit();
  }
  if (mode == 3) {
    fade();
  }
  if (mode == 0) {


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

    controllers[0]->showLeds();
    controllers[1]->showLeds();
    controllers[2]->showLeds();
    controllers[3]->showLeds();
    controllers[4]->showLeds();
    controllers[5]->showLeds();
    controllers[6]->showLeds();
    controllers[7]->showLeds();
  }


 
  
}
