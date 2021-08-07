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
  } // if
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

  }


  //previousTime = currentTime;

  EVERY_N_MILLISECONDS( 2000 ) {
    switch (padHit) {
      case 1:
        setspeed = newPos;
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
        break;

    }
  }
}
