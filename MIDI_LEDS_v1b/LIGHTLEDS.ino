
// MyHandleNoteOn/Off are the functions that will be called by the Midi Library
// when a MIDI Note message is received.
// It will be passed bytes for Channel, Pitch, and Value
// If it is, it lights up the corresponding LED

void bassLed (){
  fill_solid(bassLeds, BASS_LEDS, CHSV(bassColor, 255, brightness)); // TEST SNARE LED STRIP
  FastLED.show();

}

void snareLed (){
fill_solid(snareLeds, SNARE_LEDS, CHSV(bassColor, 255, brightness)); // TEST SNARE LED STRIP
  FastLED.show();

  }

  
//void bassLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[bass[i]].setHSV(bassColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void snareLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[snare[i]].setHSV(snareColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void tomaLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[toma[i]].setHSV(tomaColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void tombLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[tomb[i]].setHSV(tombColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void tomcLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[tomc[i]].setHSV(tomcColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void hiHatLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[hihat[i]].setHSV(hiHatColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void crashLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[crash[i]].setHSV(crashColor, 255, brightness);
//  }
//  FastLED.show();
//}
//void rideLed () {
//  for (int i = 0; i < 5; i++)
//  {
//    leds[ride[i]].setHSV(rideColor, 255, brightness);
//  }
//  FastLED.show();
//}
