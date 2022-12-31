// ------------------------------------------- set-up function -------------------------------------------
void setup() {
  matrix.begin();
  gamestart();
  
  // no drops at the beginning
  drop = false;
  // Serial.begin(115200);
  last_drop = millis();
  last_control = millis();

  // test ----------------------
  // Serial.begin(9600);
  // ------------------------test
}
