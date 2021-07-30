void coloredit () {

  static byte pos = 0;
  encoder.tick();
  RotaryEncoder::Direction dir = encoder.getDirection();

  byte newPos = encoder.getPosition();
  if (pos != newPos) {
    //Serial.print("pos:");
    //Serial.print(newPos);
    //Serial.print(" dir:");
    //Serial.println((int)(encoder.getDirection()));
    pos = newPos;
    //delay (20);
  }
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


  switch (padHit) {
    case 1:
      tom1Color = newPos;
      tom1led ();
     
      break;
    case 2:
      tom2Color = newPos;
      tom2led ();
      
      break;
    case 3:
      tom3Color = newPos;
      tom3led ();
      
      break;
    case 4:
      snareColor = newPos;
      snareled ();
      
      break;
    case 5:
      bassColor = newPos;
      bassled ();
     
      break;
    case 6:
      hihatColor = newPos;
      hihatled ();
      
      break;
    case 7:
      crashColor = newPos;
      crashled ();
      
      break;
    case 8:
      rideColor = newPos;
      rideled ();
     
      break;
  }
}
