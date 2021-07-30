void editMode() {

  if (padHit == 0) {
    //editPage();
    redraw = true;
    if (redraw) {
      u8g.firstPage();
      do {
        u8g.setFont(u8g_font_courB14);
        u8g.drawFrame(0, 0, 128, 64);
        u8g.drawStr( 14, 19, "EDIT MODE");
        u8g.drawStr( 25, 38, "HIT PAD");
        u8g.drawStr( 14, 57, "TO SELECT");
      }
      while ( u8g.nextPage() );
      delay(50);
    }
    redraw = false;
  }
  if (padHit != 0) {
    redraw = true;
    if (redraw) {
      u8g.firstPage();
      do {
        u8g.setFont(u8g_font_courB14);
        u8g.drawFrame(0, 0, 128, 64);
        u8g.setPrintPos(4, 28);
        u8g.print(padName);
        u8g.drawStr( 4, 56 , "SELECTED");
      }
      while ( u8g.nextPage() );
      //clearLCD();
      // rebuild the picture after some delay
      delay(50);
    }
    redraw = true;

    delay(1000);
    setMode = 0;
    setEdit = 2;
  }
      switch (padHit) {
      case 1:
        color = bassColor;
        speedSet = bassSpeed;
        break;
      case 2:
        speedSet = snareSpeed;
        color = snareColor;
        break;
      case 3:
        speedSet = tomaSpeed;
        color = tomaColor;
        break;
      case 4:
        speedSet = tombSpeed;
        color = tombColor;
        break;
      case 5:
        speedSet = tomcSpeed;
        color = tomcColor;
        break;
      case 6:
        speedSet = hiHatSpeed;
        color = hiHatColor;
        break;
      case 7:
        speedSet = crashSpeed;
        color = crashColor;
        break;
      case 8:
        speedSet = rideSpeed;
        color = rideColor;
        break;
    }
}


void saveSetting() {
  switch (padHit) {
    case 1:
      bassColor = color;
      bassSpeed = speedSet;
      padHit = 0;
    case 2:
      snareColor = color;
      snareSpeed = speedSet;
      padHit = 0;
    case 3:
      tomaColor = color;
      tomaSpeed = speedSet;
      padHit = 0;
    case 4:
      tombColor = color;
      tombSpeed = speedSet;
      padHit = 0;
    case 5:
      tomcColor = color;
      tomcSpeed = speedSet;
      padHit = 0;
    case 6:
      hiHatColor = color;
      hiHatSpeed = speedSet;
      padHit = 0;
    case 7:
      crashColor = color;
      crashSpeed = speedSet;
      padHit = 0;
    case 8:
      rideColor = color;
      rideSpeed = speedSet;
      padHit = 0;
  }
}
