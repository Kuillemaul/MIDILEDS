void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  brightness = map(velocity, 1 , 127 , 0 , 255);
  switch (pitch) {
    case 36: //bass
      padHit = 5;
      padName = "BASS";  //Pad name will be used with LCD screen integratrion.
      fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(bassColor);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 38: //SNARE
    case 40: //SNARE RIM
    case 37: //SNARE X-stick
      padHit = 4;
      padName = "SNARE";
      colorpos = snareColor;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(snareColor);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 48: //TOM 1 HEAD
    case 50: //TOM 1 RIM
      padHit = 1;
      padName = "TOM 1";
      colorpos = tom1Color;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(tom1Color);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 45: //TOM 2 HEAD
    case 47: //TOM 2 RIM
      padHit = 2;
      padName = "TOM 2";
      colorpos = tom2Color;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(tom2Color);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 43: //TOM 3 HEAD
    case 58: //TOM 3 RIM
      padHit = 3;
      padName = "TOM 3";
      colorpos = tom3Color;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(tom3Color);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 46: //HH OPEN BOW
    case 26: //HH OPEN EDGE
    case 42: //HH CLOSED BOW
    case 22: //HH CLOSED EDGE
    case 44: //HH PEDAL
      padHit = 6;
      padName = "HI HAT";
      colorpos = hihatColor;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(hihatColor);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 49: // CRASH 1 BOW
    case 55: // CRASH 1 EDGE
      padHit = 7;
      padName = "CRASH";
      colorpos = crashColor;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(crashColor);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;
    case 51: //RIDE BOW
    case 59: //RIDE EDGE
      padHit = 8;
      padName = "RIDE";
      colorpos = crashColor;
      Serial1.println("PAD HIT");
      Serial1.println(padName);
      fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
      Serial1.println("Filling LEDS");
      Serial1.print("COLOR  :");
      Serial1.println(rideColor);
      Serial1.print("brightness :");
      Serial.println(brightness);
      break;

  }

}
