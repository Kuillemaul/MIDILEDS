void modechange() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
    if (mode < 3) 
      mode ++; 
    else
      mode = 0;
    Serial1.println("Mode Counter is");
    Serial1.println(mode);
    //redraw = true;
    //delay(20);
    //clearLCD();
       //padHit = 0;
  }
  last_interrupt_time = interrupt_time;
}
