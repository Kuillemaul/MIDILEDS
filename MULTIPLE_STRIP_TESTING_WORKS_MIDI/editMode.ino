void () {
  if (padHit == 0) {
    Serial.println("======== EDIT MODE ENABLED ========");
    Serial.println("======== HIT PAD TO SELECT ========");
  }
  if (padHit != 0) {
    Serial.print("======== ");
    Serial.print(padName);
    Serial.println("======== ");
    Serial.println("========      SELECTED     ========");
  }
  setMode = 0
  setEdit = 1
  
}
