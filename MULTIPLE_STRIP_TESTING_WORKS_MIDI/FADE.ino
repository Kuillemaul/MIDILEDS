void fade() {

  encoder.tick();

  // get the current physical position and calc the logical position
  int newPos = encoder.getPosition() * SPEEDROTARYSTEPS;

  if (newPos < speedmin) {
    encoder.setPosition(speedmin / SPEEDROTARYSTEPS);
    newPos = speedmin;

  } else if (newPos > speedmax) {
    encoder.setPosition(speedmax / SPEEDROTARYSTEPS);
    newPos = speedmax;
  } // if

  if (lastPos != newPos) {
    //Serial.print(newPos);
    //Serial.println();
    lastPos = newPos;
    fadeSpeed = newPos;
  } // if
  //  unsigned long currentTime = millis();
  //  if (currentTime - previousTime >=  setspeed) {
  //    /* Event code */
  //    fadeToBlackBy(tom1strip, TOM1LEDS, 1);
  //    fadeToBlackBy(tom2strip, TOM2LEDS, 1);
  //    fadeToBlackBy(tom3strip, TOM3LEDS, 1);
  //    fadeToBlackBy(snarestrip, SNARELEDS, 1);
  //    fadeToBlackBy(bassstrip, BASSLEDS, 1);
  //    fadeToBlackBy(hihatstrip, HIHATLEDS, 1);
  //    fadeToBlackBy(crashstrip, CRASHLEDS, 1);
  //    fadeToBlackBy(ridestrip, RIDELEDS, 1);
  //for (int i = 0; i < NUM_STRIPS; i++) {
  //    FastLED[i].showLeds();  //Show Leds fading?

  EVERY_N_MILLISECONDS_I( fadeTimerObj, FADE_SPEED ) {
    fadeTimerObj.setPeriod( fadeSpeed);
    fadeToBlackBy(tom1strip, TOM1LEDS, 1);
    fadeToBlackBy(tom2strip, TOM2LEDS, 1);
    fadeToBlackBy(tom3strip, TOM3LEDS, 1);
    fadeToBlackBy(snarestrip, SNARELEDS, 1);
    fadeToBlackBy(bassstrip, BASSLEDS, 1);
    fadeToBlackBy(hihatstrip, HIHATLEDS, 1);
    fadeToBlackBy(crashstrip, CRASHLEDS, 1);
    fadeToBlackBy(ridestrip, RIDELEDS, 1);
    FastLED.show();
  }



  //previousTime = currentTime;

  EVERY_N_MILLISECONDS( 2000 ) {
    switch (padHit) {
      case 1:
        fadeSpeed = newPos;
        fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
        FastLED[TOM1LEDS_F].showLeds(255);
        break;
      case 2:
        fadeSpeed = newPos;
        fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
        FastLED[TOM2LEDS_F].showLeds(255);
        break;
      case 3:
        fadeSpeed = newPos;
        fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
        FastLED[TOM3LEDS_F].showLeds(255);
        break;
      case 4:
        fadeSpeed = newPos;
        fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
        FastLED[SNARELEDS_F].showLeds(255); 
        break;
      case 5:
        fadeSpeed = newPos;
        fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
        FastLED[BASSLEDS_F].showLeds(255); 
        break;
      case 6:
        fadeSpeed = newPos;
        fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
        FastLED[HIHATLEDS_F].showLeds(255); 
        break;
      case 7:
        fadeSpeed = newPos;
        fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
        FastLED[CRASHLEDS_F].showLeds(255); 
        break;
      case 8:
        fadeSpeed = newPos;
        fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
        FastLED[RIDELEDS_F].showLeds(255); 
        break;
    }
    // FastLED.show();
  }
}

