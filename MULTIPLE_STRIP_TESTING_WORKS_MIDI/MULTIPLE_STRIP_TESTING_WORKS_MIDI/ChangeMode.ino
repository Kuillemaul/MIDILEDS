void modechange() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
    if (mode < 3) 
      mode ++; 
    else
      mode = 0;
    //Serial.println("Mode Counter is");
    //Serial.println(mode);
    //redraw = true;
    delay(20);
    //clearLCD();
       //padHit = 0;
  }
  last_interrupt_time = interrupt_time;
  if (mode == 2) {
    fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness)); // Added to see what mode i was in. 
    FastLED[6].showLeds(125);
    delay(500);
    FastLED[6].showLeds(0);
    delay(500);
    fill_solid(snarestrip, SNARELEDS, CHSV(tom1Color, 255, brightness));
    FastLED[6].showLeds(125);
    delay(500);
    FastLED[6].showLeds(0);
    delay(500);
    fill_solid(snarestrip, SNARELEDS, CHSV(tom2Color, 255, brightness));
    FastLED[6].showLeds(125);
    delay(500);
    FastLED[6].showLeds(0);
  }
}
