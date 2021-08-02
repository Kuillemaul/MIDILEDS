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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
      tom1Color = newPos;
=======
      tom1Color = newcolorPos;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
     
=======
      tom1Color = newcolorPos;
      fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, 255));
=======
     FastLED[3].showLeds(255); 
>>>>>>> Stashed changes
      break;
    case 2:
      tom2Color = newcolorPos;
      fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, 255));
      break;
    case 3:
      tom3Color = newcolorPos;
      fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, 255));
      break;
    case 4:
      snareColor = newcolorPos;
      fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, 255));
      break;
    case 5:
      bassColor = newcolorPos;
      fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, 255));
      break;
    case 6:
      hihatColor = newcolorPos;
      fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, 255));
      break;
    case 7:
      crashColor = newcolorPos;
      fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, 255));
      break;
    case 8:
      rideColor = newcolorPos;
      fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, 255));
>>>>>>> Stashed changes
      break;
      FastLED.show();
  }
<<<<<<< Updated upstream
<<<<<<< Updated upstream
}
=======
  fill_solid(tom1strip, TOM1LEDS, CHSV(0, 0, 0));  //Not sure if this will work but will see.
  fill_solid(tom2strip, TOM2LEDS, CHSV(0, 0, 0));
  fill_solid(tom3strip, TOM3LEDS, CHSV(0, 0, 0));
  fill_solid(snarestrip, SNARELEDS, CHSV(0, 0, 0));
  fill_solid(bassstrip, BASSLEDS, CHSV(0, 0, 0));
  fill_solid(hihatstrip, HIHATLEDS, CHSV(0, 0, 0));
  fill_solid(crashstrip, CRASHLEDS, CHSV(0, 0, 0));
  fill_solid(ridestrip, RIDELEDS, CHSV(0, 0, 0));

  FastLED.show();
=======
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


  
>>>>>>> Stashed changes
}
//      controllers[0]->showLeds();
//      controllers[1]->showLeds();
//      controllers[2]->showLeds();
//      controllers[3]->showLeds();
//      controllers[4]->showLeds();
//      controllers[5]->showLeds();
//      controllers[6]->showLeds();
//      controllers[7]->showLeds();
>>>>>>> Stashed changes
