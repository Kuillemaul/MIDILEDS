// What to do when midi note is received.

void handleNoteOn(byte channel, byte pitch, byte velocity) {
brightness = map(velocity, 1 , 127 , 0 , 255);
  switch (pitch) {
    case 36: //bass
      bassHit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, bassBrightnes));
   FastLED[0].showLeds();
      break;
    case 38: //SNARE
    case 40: //SNARE RIM
    case 37: //SNARE X-stick
      snareHit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      snareBrightnes = brightness;   
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, snareBrightnes));
   FastLED[1].showLeds();
      break;
    case 48: //TOM 1 HEAD
    case 50: //TOM 1 RIM
      tom1Hit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      break;
    case 45: //TOM 2 HEAD
    case 47: //TOM 2 RIM
      tom2Hit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      break;
    case 43: //TOM 3 HEAD
    case 58: //TOM 3 RIM
      tom2Hit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      break;
    case 46: //HH OPEN BOW
    case 26: //HH OPEN EDGE
    case 42: //HH CLOSED BOW
    case 22: //HH CLOSED EDGE
    case 44: // HH PEDAL
      hihatHit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      brightness = hihatBrightnes;
      fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, hihatBrightnes));
      FastLED[2].showLeds();
      break;
    case 49: // CRASH 1 BOW
    case 55: // CRASH 1 EDGE
      crashHit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      break;
    case 51: //RIDE BOW
    case 59: //RIDE EDGE
      rideHit++;
      mySerial.println("=======================");
      mySerial.println("NOTE RECEIVED");
      mySerial.print("CHANNEL");
      mySerial.println(channel);
      mySerial.print("PITCH");
      mySerial.println(pitch);
      mySerial.print("VELOCITY");
      mySerial.println(velocity);
      mySerial.println("=======================");
      break;
  }
  //FastLED.show();
}
