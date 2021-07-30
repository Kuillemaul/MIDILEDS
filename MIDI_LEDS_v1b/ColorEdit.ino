void colorEdit() {
 
  //redraw = true;
  currentStateCLK1 = digitalRead(up);

  if (currentStateCLK1 != lastStateCLK1  && currentStateCLK1 == 1) {
    if (digitalRead(down) != currentStateCLK1) {
      color -= 2;
      currentDir1 = "Up";
    } else {
      // Encoder is rotating CW so increment
      color += 2;
      currentDir1 = "Down";
    }
    Serial1.println("<Color Change: >");
    Serial1.println(currentDir1);
    Serial1.println("< | Value: >");
    Serial1.println(color);
    redraw = true;
  }
  lastStateCLK1 = currentStateCLK1;

  if (redraw) {
    //clearLCD();
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_courB14);
      u8g.drawFrame(0, 0, 128, 64);
      u8g.drawFrame(36, 33, 63, 31);
      //int w = u8g.getStrWidth(padName);
      //u8g.setPrintPos((SCREEN_WIDTH - w / 2), 14);
      u8g.print(padName);
      //u8g.drawStr( 37, 14, "SNARE"); //STRING TEST
      u8g.drawStr( 37, 28, "COLOR");
      u8g.setFont(u8g_font_courB24);
      u8g.setPrintPos(38, 58);
      u8g.print (color);
      //sprintf (buf, "%d", brightness);
    }
    while ( u8g.nextPage() );
    //clearLCD();
    // rebuild the picture after some delay
    delay(50);
    redraw = false;
  }


  //Serial2.println("why not here");
  // COLOR ENCODER BUTTON TO SAVE SETTING
  int btnState1 = digitalRead(save);
  if (btnState1 == LOW) {
    if (millis() - lastButtonPress1 > 50) {
      //Serial2.println("SAVE SETTING");
      //saveSetting();
      delay(100);
      setEdit = 3;
      redraw = true;
      if (redraw) {
        clearLCD();
        u8g.firstPage();
        do {
          u8g.setFont(u8g_font_courB14);
          u8g.drawFrame(0, 0, 128, 64);
          //u8g.drawFrame(36, 33, 63, 31);
          u8g.setPrintPos(37, 14);
          u8g.print(padName);
          //u8g.drawStr( 37, 14, "SNARE"); //STRING TEST
          u8g.drawStr( 37, 28, "COLOR");
          u8g.setFont(u8g_font_courB24);
          u8g.drawStr( 20, 58, "SAVED");
        }
        while ( u8g.nextPage() );
        //clearLCD();
        // rebuild the picture after some delay
        delay(50);
        redraw = true;
        delay(500);
        clearLCD();
      }

    }
    lastButtonPress1 = millis();
  }


  switch (padHit) {
    case 1:
      bassLed();
      bassColor = color;
      break;
    case 2:
      snareLed();
      snareColor = color;
      break;
//    case 3:
//      tomaLed();
//      tomaColor = color;
//      break;
//    case 4:
//      tombLed();
//      tombColor = color;
//      break;
//    case 5:
//      tomcLed();
//      tomcColor = color;
//      break;
//    case 6:
//      hiHatLed();
//      hiHatColor = color;
//      break;
//    case 7:
//      crashLed();
//      crashColor = color;
//      break;
//    case 8:
//      rideLed();
//      rideColor = color;
//      break;
  }

}
