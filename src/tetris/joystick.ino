/* This function reads from the joystick pins and return
 * some actions such as move right/left, restart and rotate
 * Author: Shu Xu
 * Last edited: Dec 16th, 2022
 */
int joystick_track(int VRx, int VRy, int SW){
  // control delaytime
  unsigned long control_time = 200;
  
  // Joystick readings
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(buttonPin);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  // Serial.println(SW_state);
  
  // moving/rotate
  if (mapY > 500 && (millis() - last_control > control_time)){  // rotate
    last_control = millis();
    return 1;
  } else if (mapY < -500 && (millis() - last_control > control_time)){ // move down
    last_control = millis();
    return 2;
  } else if (mapX > 500 && (millis() - last_control > control_time)){ // move right
    last_control = millis();
    return 3;
  } else if (mapX < -500 && (millis() - last_control > control_time)){ // move left
    last_control = millis();
    return 4;
  } else if (SW_state && (millis() - last_control > control_time)){ // restart
    last_control = millis();
    return 0;
  }
  // no action
  return 5;
}
