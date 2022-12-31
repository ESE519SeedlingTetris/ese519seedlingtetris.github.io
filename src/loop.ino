// loop function

void loop() {
 
  
  if (new_block == 1){ // new block drop
    create_block();
    new_block = 0;
  } else if (new_block == 2){ // new block can't move down; gameover
    gameover();
  }

  //Serial.println(moving_map[21][11]);
  action = joystick_track(VRx, VRy, SW);
  
  // drop time checker
  if(millis() - last_drop > droptime){
     last_drop = millis();
     //move down
     drop = true;
  }
  
  if (action == 0){ // restart
    gamestart();
  } else if (action == 1) {  // rotate
    rotate();
  } else if (action == 2) { //move down
    drop = true;
  } else if (action == 3) { // move right
    move_right();
  } else if (action == 4) { // move left
    move_left();
  }

  if (drop){
    new_block = move_down();  // move down if it is ok to drop
    //Serial.println(new_block);
    drop = false;
  }

   /*Test --------------------
  buzzer.loop(); // MUST call the buzzer.loop() function in loop()
  // int length = sizeof(noteDurations) / sizeof(int);
  // buzzer.playMelody(melody, noteDurations, length); // playing

  if (buzzer.getState() == BUZZER_IDLE) {
    int length = sizeof(noteDurations) / sizeof(int);
    buzzer.playMelody(melody, noteDurations, length); // playing
  }


  //-----------------------Test */
}
