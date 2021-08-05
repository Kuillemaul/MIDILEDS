#include <SoftwareSerial.h>
#include <MIDI.h>
#include <FastLED.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define hihatPin 3
#define bassPin 4
#define snarePin 5
#define resetPin 6

#define HIHATLEDS 30
#define SNARELEDS 54
#define BASSLEDS 67

#define NUM_STRIPS  3
CLEDController *controllers[NUM_STRIPS];

byte brightness = 100;

byte bassHit = 0;
byte snareHit = 0;
byte tom1Hit = 0;
byte tom2Hit = 0;
byte tom3Hit = 0;
byte hihatHit = 0;
byte crashHit = 0;
byte rideHit = 0;

byte snareColor = 0;
byte bassColor = 210;
byte hihatColor = 45;

byte snareBrightnes = 100;
byte bassBrightnes = 100;
byte hihatBrightnes = 100;

int buttonRead;

SoftwareSerial mySerial(10, 11); // RX, TX

CRGB hihatstrip[HIHATLEDS];
CRGB snarestrip[SNARELEDS];
CRGB bassstrip[BASSLEDS];

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(57600);
  mySerial.println("I am ALIVE and ready to send MIDI Stuff");
  pinMode(resetPin, INPUT);

  FastLED.addLeds<WS2812B, hihatPin, GRB>(hihatstrip, HIHATLEDS);
  FastLED.addLeds<WS2812B, snarePin, GRB>(snarestrip, SNARELEDS);
  FastLED.addLeds<WS2812B, bassPin, GRB>(bassstrip, BASSLEDS);

  mySerial.println(" Testing Strips :::::: They should flash 3 times. ");
  delay(500);

  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, hihatBrightnes));
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, snareBrightnes));
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, bassBrightnes));
  FastLED.show();
  mySerial.println(" FLASH 1");
  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);

  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, hihatBrightnes));
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, snareBrightnes));
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, bassBrightnes));
  FastLED.show();
  mySerial.println(" FLASH 2");
  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);

  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, hihatBrightnes));
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, snareBrightnes));
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, bassBrightnes));
  mySerial.println(" FLASH 3");
  FastLED.show();
  delay(500);
  FastLED.clear();
  FastLED.show();

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.begin(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  MIDI.read();
  buttonRead = digitalRead(resetPin);
  if (buttonRead == HIGH) {
    mySerial.println("===============================================");
    mySerial.println("         RESET BUTTON HAS BEEN PRESSED         ");
    mySerial.println(" THE FOLLOWING MIDI SIGNALS HAVE BEEN RECIEVED ");
    mySerial.println("===============================================");
    mySerial.println();
    delay(500);
    mySerial.println("===============================================");
    mySerial.print("BASS DRUM : ");
    mySerial.print(bassHit);
    mySerial.println("  TIMES  ");
    mySerial.println("===============================================");
    delay(500);
    mySerial.println("===============================================");
    mySerial.print("SNARE DRUM : ");
    mySerial.print(snareHit);
    mySerial.println("  TIMES  ");
    mySerial.println("===============================================");
    delay(500);
    mySerial.println("===============================================");
    mySerial.print("HIHAT  : ");
    mySerial.print(hihatHit);
    mySerial.println("  TIMES  ");
    mySerial.println("===============================================");
    delay(200);
    bassHit = 0;
    snareHit = 0;
    tom1Hit = 0;
    tom2Hit = 0;
    tom3Hit = 0;
    hihatHit = 0;
    crashHit = 0;
    rideHit = 0;
    mySerial.println("===============================================");
    mySerial.println("         ALL HITS HAVE BEEN RESET              ");
    mySerial.println("              HOW DID WE GO?                   ");
    mySerial.println("===============================================");
  }
//  EVERY_N_MILLISECONDS(10) {
//
//    fadeToBlackBy(snarestrip, SNARELEDS, 1);
//    fadeToBlackBy(bassstrip, BASSLEDS, 1);
//    fadeToBlackBy(hihatstrip, HIHATLEDS, 1);
//
//    FastLED.show();
//  }
  EVERY_N_MILLISECONDS (10) {
    if (hihatBrightnes > 0) {
      hihatBrightnes--;
     FastLED[0].showLeds(hihatBrightnes);
    }
    if (snareBrightnes > 0) {
      snareBrightnes--;
     FastLED[1].showLeds(snareBrightnes);
    }
    if (bassBrightnes > 0) {
      bassBrightnes--;
     FastLED[2].showLeds(bassBrightnes);
    }
  }
}
