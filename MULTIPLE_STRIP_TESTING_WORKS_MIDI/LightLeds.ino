
void tom1led () {
  fill_solid(tom1strip, TOM1LEDS, CHSV(tom1Color, 255, brightness));
  //controllers[0]->showLeds(brightness);
}

void tom2led () {
  fill_solid(tom2strip, TOM2LEDS, CHSV(tom2Color, 255, brightness));
  //controllers[1]->showLeds(brightness);
}

void tom3led () {
  fill_solid(tom3strip, TOM3LEDS, CHSV(tom3Color, 255, brightness));
 // controllers[2]->showLeds(brightness);
}
void snareled () {
  fill_solid(snarestrip, SNARELEDS, CHSV(snareColor, 255, brightness));
  //controllers[3]->showLeds(brightness);
}

void bassled () {
  fill_solid(bassstrip, BASSLEDS, CHSV(bassColor, 255, brightness));
  //controllers[4]->showLeds(brightness);
}

void hihatled () {
  fill_solid(hihatstrip, HIHATLEDS, CHSV(hihatColor, 255, brightness));
  //controllers[5]->showLeds(brightness);
}

void crashled () {
  fill_solid(crashstrip, CRASHLEDS, CHSV(crashColor, 255, brightness));
  //controllers[6]->showLeds(brightness);
}

void rideled () {
  fill_solid(ridestrip, RIDELEDS, CHSV(rideColor, 255, brightness));
  //controllers[7]->showLeds(brightness);
}
