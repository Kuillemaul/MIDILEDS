void padchange (){


static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
    
if (padHit < 8) 
     padHit ++; 
    else
     padHit = 0;
    //Serial.println("Pad Edit ");
    //Serial.println(padHit);
    //redraw = true;
    delay(20);
    //clearLCD();
       //padHit = 0;
     switch (padHit) {
      case 1:
      padName = "TOM1";
      tom1led ();
      break;
      case 2:
      padName = "TOM2";
      tom2led ();
      break;
      case 3:
      padName = "TOM3";
      tom3led ();
      break;
      case 4:
      padName = "SNARE";
      snareled ();
      break;
      case 5:
      padName = "BASS";
      bassled ();
      break;
      case 6:
      padName = "HIHAT";
      hihatled ();
      break;
      case 7:
      padName = "CRASH";
      crashled ();
      break;
      case 8:
      padName = "RIDE";
      rideled ();
      break;
      
       
  }
  last_interrupt_time = interrupt_time;
}
}
