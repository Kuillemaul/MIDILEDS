void fade() {
  //redraw = true;
  currentStateCLK1 = digitalRead(up);

  if (currentStateCLK1 != lastStateCLK1  && currentStateCLK1 == 1) {
    if (digitalRead(down) != currentStateCLK1) {
      speedSet -= 1;
      if (speedSet < 1) {
        speedSet = 1;
      }
      currentDir1 = "Up";
    } else {
      // Encoder is rotating CW so increment
      speedSet += 1;
      if (speedSet > 200) {
        speedSet = 200;
      }
      currentDir1 = "Down";
    }
    Serial1.println("Speed Change");
    Serial1.println(currentDir1);
    Serial1.println("< | Value: >");
    Serial1.println(speedSet);
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
      u8g.setPrintPos(37, 14);
      u8g.print(padName);
      u8g.drawStr( 10, 28, "FADE SPEED");
      u8g.setFont(u8g_font_courB24);
      u8g.setPrintPos(38, 58);
      u8g.print(speedSet);
    }
    while ( u8g.nextPage() );
    //clearLCD();
    // rebuild the picture after some delay
    delay(20);
  }
  redraw = false;

  int btnState1 = digitalRead(save);
  if (btnState1 == LOW) {
    if (millis() - lastButtonPress1 > 50) {
      //Serial1.println("SAVE SETTING");

      delay(100);
      setMode = 1;
      setEdit = 0;
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
          u8g.drawStr( 37, 28, "FADE");
          u8g.setFont(u8g_font_courB24);
          u8g.drawStr( 22, 58, "SAVED");
        } while ( u8g.nextPage() );

      }
      redraw = true;
      saveSetting();
      delay (500);

      clearLCD();
    }

    lastButtonPress1 = millis();
    //saveSetting();
  }


  EVERY_N_MILLIS(2000) {
    switch (padHit) {
      case 1:
        bassLed();
        break;
      case 2:
        snareLed();
        break;
//      case 3:
//        tomaLed();
//        break;
//      case 4:
//        tombLed();
//        break;
//      case 5:
//        tomcLed();
//        break;
//      case 6:
//        hiHatLed();
//        break;
//      case 7:
//        crashLed();
//        break;
//      case 8:
//        rideLed();
//        break;
    }
  }
    unsigned long currentTime = millis();
  if (currentTime - previousTime >= snareSpeed) {
    /* Event code */
    fadeToBlackBy( snareLeds, SNARE_LEDS, 1);
    FastLED.show();    
  }

  if (currentTime - previousTime >= bassSpeed) {
    /* Event code */
    fadeToBlackBy( bassLeds, BASS_LEDS, 1);
    FastLED.show();

    previousTime = currentTime;
  }
}
