void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  brightness = map(velocity, 1 , 127 , 0 , 255);
  switch (pitch) {
    case 36: //bass
      padHit = 5;
      //padName = "BASS";  //Pad name will be used with LCD screen integratrion. 
      bassled();
      break;
    case 38: //SNARE
    case 40: //SNARE RIM
    case 37: //SNARE X-stick
      padHit = 4;
      //padName = "SNARE";
      colorpos = snareColor;
      snareled();
      break;
    case 48: //TOM 1 HEAD
    case 50: //TOM 1 RIM
      padHit = 1;
      //padName = "TOM 1";
      colorpos = tom1Color;
      tom1led();
      break;
    case 45: //TOM 2 HEAD
    case 47: //TOM 2 RIM
      padHit = 2;
     //padName = "TOM 2";
     colorpos = tom2Color;
      tom2led();
      break;
    case 43: //TOM 3 HEAD
    case 58: //TOM 3 RIM
      padHit = 3;
     // padName = "TOM 3";
     colorpos = tom3Color;
      tom3led();
      break;
    case 46: //HH OPEN BOW
    case 26: //HH OPEN EDGE
    case 42: //HH CLOSED BOW
    case 22: //HH CLOSED EDGE
    case 44: //HH PEDAL
     // padName = "HI HAT";
      padHit = 6;
      colorpos = hihatColor;
      hihatled();
      break;
    case 49: // CRASH 1 BOW
    case 55: // CRASH 1 EDGE
      padHit = 7;
      //padName = "CRASH";
      colorpos = crashColor;
      crashled();
      break;
    case 51: //RIDE BOW
    case 59: //RIDE EDGE
      padHit = 8;
      colorpos = crashColor;
      //padName = "RIDE";
      rideled();
      break;

  }
}
