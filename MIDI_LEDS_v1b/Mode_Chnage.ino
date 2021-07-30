void modechange() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
    if (setMode < 2) 
      setMode ++; 
    else
      setMode = 0;
    Serial1.println("Mode Counter is");
    Serial1.println(setMode);
    redraw = true;
    delay(20);
    clearLCD();
       padHit = 0;
  }
  last_interrupt_time = interrupt_time;
}
