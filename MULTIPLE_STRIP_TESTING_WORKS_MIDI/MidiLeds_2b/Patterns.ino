void patterns() {

  static int pos = 0;
  encoder.tick();
  RotaryEncoder::Direction dir = encoder.getDirection();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    if (dir == RotaryEncoder::Direction::CLOCKWISE) {
      //Serial.println("NEXT PATTERN");
      nextPattern();
      //Serial.print("pos:");
      //Serial.print(newPos);
      //Serial.print(" dir:");
      //Serial.println((int)(encoder.getDirection()));
      pos = newPos;
    }
    if (dir == RotaryEncoder::Direction::COUNTERCLOCKWISE) {
      //Serial.println("PREV PATTERN");
      prevPattern();
      //Serial.print("pos:");
      //Serial.print(newPos);
      //Serial.print(" dir:");
      //Serial.println((int)(encoder.getDirection()));
      pos = newPos;
    }
  }


  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  //FastLED.show();
  //  controllers[0]->showLeds(125);
  //  controllers[1]->showLeds(125);
  //  controllers[2]->showLeds(125);
  //  controllers[3]->showLeds(125);
  //  controllers[4]->showLeds(125);
  //  controllers[5]->showLeds(125);
  //  controllers[6]->showLeds(125);
  //  controllers[7]->showLeds(125);

  for (int i = 0; i < NUM_STRIPS; i++) {
    FastLED[i].showLeds(100);  //Show Leds
  }

  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }
  EVERY_N_SECONDS(30) {

    //Serial.print("A:");
    //Serial.print(gCurrentPatternNumber);
    // Serial.println(".");

    FastLED.setBrightness(brightness);
  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}
void prevPattern()
{


  gCurrentPatternNumber = (gCurrentPatternNumber - 1);
  if (gCurrentPatternNumber > ARRAY_SIZE(gPatterns)) {
    gCurrentPatternNumber = ARRAY_SIZE(gPatterns) - 1;
  }
}



void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow(tom1strip, TOM1LEDS, gHue, 7);
  fill_rainbow(tom2strip, TOM2LEDS, gHue, 7);
  fill_rainbow(tom3strip, TOM3LEDS, gHue, 7);
  fill_rainbow(snarestrip, SNARELEDS, gHue, 7);
  fill_rainbow(bassstrip, BASSLEDS, gHue, 7);
  fill_rainbow(hihatstrip, HIHATLEDS, gHue, 7);
  fill_rainbow(crashstrip, CRASHLEDS, gHue, 7);
  fill_rainbow(ridestrip, RIDELEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    tom1strip[ random16(TOM1LEDS) ] += CRGB::White;
    tom2strip[ random16(TOM2LEDS) ] += CRGB::White;
    tom3strip[ random16(TOM3LEDS) ] += CRGB::White;
    snarestrip[ random16(SNARELEDS) ] += CRGB::White;
    bassstrip[ random16(BASSLEDS) ] += CRGB::White;
    hihatstrip[ random16(HIHATLEDS) ] += CRGB::White;
    crashstrip[ random16(CRASHLEDS) ] += CRGB::White;
    ridestrip[ random16(RIDELEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy(tom1strip, TOM1LEDS, 10);
  fadeToBlackBy(tom2strip, TOM2LEDS, 10);
  fadeToBlackBy(tom3strip, TOM3LEDS, 10);
  fadeToBlackBy(snarestrip, SNARELEDS, 10);
  fadeToBlackBy(bassstrip, BASSLEDS, 10);
  fadeToBlackBy(hihatstrip, HIHATLEDS, 10);
  fadeToBlackBy(crashstrip, CRASHLEDS, 10);
  fadeToBlackBy(ridestrip, RIDELEDS, 10);

  int pos1 = random16(TOM1LEDS);
  int pos2 = random16(TOM2LEDS);
  int pos3 = random16(TOM3LEDS);
  int pos4 = random16(SNARELEDS);
  int pos5 = random16(BASSLEDS);
  int pos6 = random16(HIHATLEDS);
  int pos7 = random16(CRASHLEDS);
  int pos8 = random16(RIDELEDS);

  tom1strip[pos1] += CHSV( gHue + random8(64), 200, 255);
  tom2strip[pos2] += CHSV( gHue + random8(64), 200, 255);
  tom3strip[pos3] += CHSV( gHue + random8(64), 200, 255);
  snarestrip[pos4] += CHSV( gHue + random8(64), 200, 255);
  bassstrip[pos5] += CHSV( gHue + random8(64), 200, 255);
  hihatstrip[pos6] += CHSV( gHue + random8(64), 200, 255);
  crashstrip[pos7] += CHSV( gHue + random8(64), 200, 255);
  ridestrip[pos8] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy(tom1strip, TOM1LEDS, 20);
  fadeToBlackBy(tom2strip, TOM2LEDS, 20);
  fadeToBlackBy(tom3strip, TOM3LEDS, 20);
  fadeToBlackBy(snarestrip, SNARELEDS, 20);
  fadeToBlackBy(bassstrip, BASSLEDS, 20);
  fadeToBlackBy(hihatstrip, HIHATLEDS, 20);
  fadeToBlackBy(crashstrip, CRASHLEDS, 20);
  fadeToBlackBy(ridestrip, RIDELEDS, 20);
  int pos1 = beatsin16( 13, 0, TOM1LEDS - 1 );
  int pos2 = beatsin16( 13, 0, TOM2LEDS - 1 );
  int pos3 = beatsin16( 13, 0, TOM3LEDS - 1 );
  int pos4 = beatsin16( 13, 0, SNARELEDS - 1 );
  int pos5 = beatsin16( 13, 0, BASSLEDS - 1 );
  int pos6 = beatsin16( 13, 0, HIHATLEDS - 1 );
  int pos7 = beatsin16( 13, 0, CRASHLEDS - 1 );
  int pos8 = beatsin16( 13, 0, RIDELEDS - 1 );
  tom1strip[pos1] += CHSV( gHue, 255, 192);
  tom2strip[pos2] += CHSV( gHue, 255, 192);
  tom3strip[pos3] += CHSV( gHue, 255, 192);
  snarestrip[pos4] += CHSV( gHue, 255, 192);
  bassstrip[pos5] += CHSV( gHue, 255, 192);
  hihatstrip[pos6] += CHSV( gHue, 255, 192);
  crashstrip[pos7] += CHSV( gHue, 255, 192);
  ridestrip[pos8] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < TOM1LEDS; i++) { //9948
    tom1strip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    tom2strip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    tom3strip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
  for ( int i = 0; i < SNARELEDS; i++) { //9948
    snarestrip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
  for ( int i = 0; i < BASSLEDS; i++) { //9948
    bassstrip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
  for ( int i = 0; i < HIHATLEDS; i++) { //9948
    hihatstrip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
  for ( int i = 0; i < CRASHLEDS; i++) { //9948
    crashstrip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
  for ( int i = 0; i < RIDELEDS; i++) { //9948
    ridestrip[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}
void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy(tom1strip, TOM1LEDS, 20);
  fadeToBlackBy(tom2strip, TOM2LEDS, 20);
  fadeToBlackBy(tom3strip, TOM3LEDS, 20);
  fadeToBlackBy(snarestrip, SNARELEDS, 20);
  fadeToBlackBy(bassstrip, BASSLEDS, 20);
  fadeToBlackBy(hihatstrip, HIHATLEDS, 20);
  fadeToBlackBy(crashstrip, CRASHLEDS, 20);
  fadeToBlackBy(ridestrip, RIDELEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    tom1strip[beatsin16( i + 7, 0, TOM1LEDS - 1 )] |= CHSV(dothue, 200, 255);
    tom2strip[beatsin16( i + 7, 0, TOM2LEDS - 1 )] |= CHSV(dothue, 200, 255);
    tom3strip[beatsin16( i + 7, 0, TOM3LEDS - 1 )] |= CHSV(dothue, 200, 255);
    snarestrip[beatsin16( i + 7, 0, SNARELEDS - 1 )] |= CHSV(dothue, 200, 255);
    bassstrip[beatsin16( i + 7, 0, BASSLEDS - 1 )] |= CHSV(dothue, 200, 255);
    hihatstrip[beatsin16( i + 7, 0, HIHATLEDS - 1 )] |= CHSV(dothue, 200, 255);
    crashstrip[beatsin16( i + 7, 0, CRASHLEDS - 1 )] |= CHSV(dothue, 200, 255);
    ridestrip[beatsin16( i + 7, 0, RIDELEDS - 1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
// Fire2012 by Mark Kriegsman, July 2012
// as part of "Five Elements" shown here: http://youtu.be/knWiGsmgycY
////
// This basic one-dimensional 'fire' simulation works roughly as follows:
// There's a underlying array of 'heat' cells, that model the temperature
// at each point along the line.  Every cycle through the simulation,
// four steps are performed:
//  1) All cells cool down a little bit, losing heat to the air
//  2) The heat from each cell drifts 'up' and diffuses a little
//  3) Sometimes randomly new 'sparks' of heat are added at the bottom
//  4) The heat from each cell is rendered as a color into the leds array
//     The heat-to-color mapping uses a black-body radiation approximation.
//
// Temperature is in arbitrary units from 0 (cold black) to 255 (white hot).
//
// This simulation scales it self a bit depending on NUM_LEDS; it should look
// "OK" on anywhere from 20 to 100 LEDs without too much tweaking.
//
// I recommend running this simulation at anywhere from 30-100 frames per second,
// meaning an interframe delay of about 10-35 milliseconds.
//
// Looks best on a high-density LED setup (60+ pixels/meter).
//
//
// There are two main parameters you can play with to control the look and
// feel of your fire: COOLING (used in step 1 above), and SPARKING (used
// in step 3 above).
//
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 50, suggested range 20-100


// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.



//void rocketengines() {
//  fadeToBlackBy(tom1strip, TOM1LEDS, 20);
//  fadeToBlackBy(tom2strip, TOM2LEDS, 20);
//  fadeToBlackBy(tom3strip, TOM3LEDS, 20);
//  fadeToBlackBy(snarestrip, SNARELEDS, 20);
//  fadeToBlackBy(bassstrip, BASSLEDS, 20);
//  fadeToBlackBy(hihatstrip, HIHATLEDS, 20);
//  fadeToBlackBy(crashstrip, CRASHLEDS, 20);
//  fadeToBlackBy(ridestrip, RIDELEDS, 20);
//// Array of temperature readings at each simulation cell
//  static byte heat[NUM_LEDS1];
//
//  // Step 1.  Cool down every cell a little
//    for( int i = 0; i < NUM_LEDS1; i++) {
//      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS1) + 2));
//    }
//
//    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
//    for( int k= NUM_LEDS1 - 1; k >= 2; k--) {
//      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
//    }
//
//    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
//    if( random8() < SPARKING ) {
//      int y = random8(7);
//      heat[y] = qadd8( heat[y], random8(160,255) );
//    }
//
//    // Step 4.  Map from heat cells to LED colors
//    for( int j = 0; j < NUM_LEDS1; j++) {
//      CRGB color = HeatColor( heat[j]);
//      int pixelnumber;
//      if( gReverseDirection ) {
//        pixelnumber = (NUM_LEDS1-1) - j;
//      } else {
//        pixelnumber = j;
//      }
//      strip1[pixelnumber] = color;
//      strip2[pixelnumber] = color;
//      strip3[pixelnumber] = color;
//    }
//}
