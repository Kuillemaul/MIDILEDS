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
    setspeed = newPos;
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

  EVERY_N_MILLISECONDS( setspeed ) {
    fadeToBlackBy(tom1strip, TOM1LEDS, 1);
    fadeToBlackBy(tom2strip, TOM2LEDS, 1);
    fadeToBlackBy(tom3strip, TOM3LEDS, 1);
    fadeToBlackBy(snarestrip, SNARELEDS, 1);
    fadeToBlackBy(bassstrip, BASSLEDS, 1);
    fadeToBlackBy(hihatstrip, HIHATLEDS, 1);
    fadeToBlackBy(crashstrip, CRASHLEDS, 1);
    fadeToBlackBy(ridestrip, RIDELEDS, 1);

<<<<<<< Updated upstream
=======

    //  for (int i = 0; i < NUM_STRIPS; i++) {
    //    FastLED[i].showLeds();  //Show Leds fading?
    //  }
    FastLED.show();
>>>>>>> Stashed changes
  }



  //previousTime = currentTime;

  EVERY_N_MILLISECONDS( 2000 ) {
    switch (padHit) {
      case 1:
        setspeed = newPos;
<<<<<<< Updated upstream
        tom1led ();
        break;
      case 2:
        setspeed = newPos;
        tom2led ();
        break;
      case 3:
        setspeed = newPos;
        tom3led ();
        break;
      case 4:
        setspeed = newPos;
        snareled ();
        break;
      case 5:
        setspeed = newPos;
        bassled ();
        break;
      case 6:
        setspeed = newPos;
        hihatled ();
        break;
      case 7:
        setspeed = newPos;
        crashled ();
        break;
      case 8:
        setspeed = newPos;
        rideled ();
=======
        fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
        break;
      case 2:
        setspeed = newPos;
        fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
        break;
      case 3:
        setspeed = newPos;
        fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
        break;
      case 4:
        setspeed = newPos;
        fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
        break;
      case 5:
        setspeed = newPos;
        fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
        break;
      case 6:
        setspeed = newPos;
        fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
        break;
      case 7:
        setspeed = newPos;
        fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
        break;
      case 8:
        setspeed = newPos;
        fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
>>>>>>> Stashed changes
        break;
        FastLED.show();
    }
  }
}
