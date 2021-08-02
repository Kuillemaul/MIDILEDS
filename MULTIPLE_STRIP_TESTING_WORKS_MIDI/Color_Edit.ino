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
      fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
      FastLED[TOM1LEDS_F].showLeds(255);   
      break;
    case 2:
      tom2Color = newcolorPos;
      fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
      FastLED[TOM2LEDS_F].showLeds(255); 
      
      break;
    case 3:
      tom3Color = newcolorPos;
      fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
     FastLED[TOM3LEDS_F].showLeds(255); 
      
      break;
    case 4:
      snareColor = newcolorPos;
      fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
      FastLED[SNARELEDS_F].showLeds(255); 
      break;
    case 5:
      bassColor = newcolorPos;
      fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
     FastLED[BASSLEDS_F].showLeds(255); 
      break;
    case 6:
      hihatColor = newcolorPos;
      fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
      FastLED[HIHATLEDS_F].showLeds(255); 
      break;
    case 7:
      crashColor = newcolorPos;
      fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
      FastLED[CRASHLEDS_F].showLeds(255); 
      break;
    case 8:
      rideColor = newcolorPos;
      fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
      FastLED[RIDELEDS_F].showLeds(255); 
      break;
  }
  FastLED.show();
}
