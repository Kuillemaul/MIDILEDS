void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  brightness = map(velocity, 1 , 127 , 0 , 255);
  switch (pitch) {
    case 36: //bass
      padHit = 5;
<<<<<<< Updated upstream
      padName = "BASS";
      bassled();
=======
      //padName = "BASS";  //Pad name will be used with LCD screen integratrion. 
      fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 38: //SNARE
    case 40: //SNARE RIM
    case 37: //SNARE X-stick
      padHit = 4;
<<<<<<< Updated upstream
      padName = "SNARE";
      snareled();
=======
      //padName = "SNARE";
      colorpos = snareColor;
      fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 48: //TOM 1 HEAD
    case 50: //TOM 1 RIM
      padHit = 1;
<<<<<<< Updated upstream
      padName = "TOM 1";
      tom1led();
=======
      //padName = "TOM 1";
      colorpos = tom1Color;
      fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));    
>>>>>>> Stashed changes
      break;
    case 45: //TOM 2 HEAD
    case 47: //TOM 2 RIM
      padHit = 2;
<<<<<<< Updated upstream
      padName = "TOM 2";
      tom2led();
=======
     //padName = "TOM 2";
     colorpos = tom2Color;
      fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 43: //TOM 3 HEAD
    case 58: //TOM 3 RIM
      padHit = 3;
<<<<<<< Updated upstream
      padName = "TOM 3";
      tom3led();
=======
     // padName = "TOM 3";
     colorpos = tom3Color;
      fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 46: //HH OPEN BOW
    case 26: //HH OPEN EDGE
    case 42: //HH CLOSED BOW
    case 22: //HH CLOSED EDGE
    case 44: // HH PEDAL
      padName = "HI HAT";
      padHit = 6;
<<<<<<< Updated upstream
      hihatled();
=======
      colorpos = hihatColor;
      fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 49: // CRASH 1 BOW
    case 55: // CRASH 1 EDGE
      padHit = 7;
<<<<<<< Updated upstream
      padName = "CRASH";
      crashled();
=======
      //padName = "CRASH";
      colorpos = crashColor;
      fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
>>>>>>> Stashed changes
      break;
    case 51: //RIDE BOW
    case 59: //RIDE EDGE
      padHit = 8;
<<<<<<< Updated upstream
      padName = "RIDE";
      rideled();
=======
      colorpos = crashColor;
      //padName = "RIDE";
      fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
>>>>>>> Stashed changes
      break;

  }
}
