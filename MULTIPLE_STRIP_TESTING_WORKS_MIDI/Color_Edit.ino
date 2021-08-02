void coloredit () {

  //static byte pos = 0;
  encoder.tick();
  RotaryEncoder::Direction dir = encoder.getDirection();

  byte newcolorPos = encoder.getPosition();
  if (colorpos != newcolorPos) {
    //Serial.print("pos:");
    //Serial.print(newPos);
    //Serial.print(" dir:");
    //Serial.println((int)(encoder.getDirection()));
    colorpos = newcolorPos;
    //delay (20);
  }
  switch (padHit) {
    case 1:
      tom1Color = newcolorPos;
      tom1led ();
      FastLED[3].showLeds(255);   
      break;
    case 2:
      tom2Color = newcolorPos;
      tom2led ();
      FastLED[4].showLeds(255); 
      
      break;
    case 3:
      tom3Color = newcolorPos;
      tom3led ();
     FastLED[5].showLeds(255); 
      
      break;
    case 4:
      snareColor = newcolorPos;
      snareled ();
      FastLED[6].showLeds(255); 
      break;
    case 5:
      bassColor = newcolorPos;
      bassled ();
     FastLED[7].showLeds(255); 
      break;
    case 6:
      hihatColor = newcolorPos;
      hihatled ();
      FastLED[1].showLeds(255); 
      break;
    case 7:
      crashColor = newcolorPos;
      crashled ();
      FastLED[2].showLeds(255); 
      break;
    case 8:
      rideColor = newcolorPos;
      rideled ();
     FastLED[3].showLeds(255); 
      break;
  }
      fill_solid(tom1strip, TOM1LEDS, CHSV(0, 0, 0));  //Not sure if this will work but will see. 
      fill_solid(tom2strip, TOM2LEDS, CHSV(0, 0, 0));
      fill_solid(tom3strip, TOM3LEDS, CHSV(0, 0, 0));
      fill_solid(snarestrip, SNARELEDS, CHSV(0, 0, 0));
      fill_solid(bassstrip, BASSLEDS, CHSV(0, 0, 0));
      fill_solid(hihatstrip, HIHATLEDS, CHSV(0, 0, 0));
      fill_solid(crashstrip, CRASHLEDS, CHSV(0, 0, 0));
      fill_solid(ridestrip, RIDELEDS, CHSV(0, 0, 0));
      
      for (int i = 0; i < NUM_STRIPS; i++) {
    FastLED[i].showLeds();  //Show Leds fading?
  }  
//      controllers[0]->showLeds();
//      controllers[1]->showLeds();
//      controllers[2]->showLeds();
//      controllers[3]->showLeds();
//      controllers[4]->showLeds();
//      controllers[5]->showLeds();
//      controllers[6]->showLeds();
//      controllers[7]->showLeds();


  
}
