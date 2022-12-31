// This function moves down a block if ok to do so
int move_down(){
  int check_ok;
  // if it is ok to move down
  check_ok = check(0);
  // Serial.println(game_map[1][5]);
  // move down
  if(check_ok == 1){
    lose = 0;
    sel_block(block, type, x, y, false);
    y = y-1;
    sel_block(block, type, x, y, true);
    return 0;
  } else if (y == 20){ // can't move down & the block touches the celling
    losing_sound();
    return 2;
  } else { // can't move down, update game_map, clear moving map, check line
    for(int i = 1; i < 21; i++){
      for(int j = 1; j < 11; j++){
        if (moving_map[i][j]) {
          game_map[i][j] = moving_map[i][j];
          moving_map[i][j] = false; 
        } 
      }
    }
    check_line();
    // check if any line is fullfilled
    return 1;
  }
}

// This function moves the block to the left
void move_left(){
  int check_ok;
  // if it is ok to move down
  check_ok = check(1);

  if(check_ok == 1){
    sel_block(block, type, x, y, false);
    x = x-1;
    sel_block(block, type, x, y, true);
  } else {
    cant_move();
  }
}

// This function moves the block to the left
void move_right(){
  int check_ok;
  // if it is ok to move down
  check_ok = check(2);

  if(check_ok == 1){
    sel_block(block, type, x, y, false);
    x = x+1;
    sel_block(block, type, x, y, true);
  } else {
    cant_move();
  }
}

// This function rotates the block clockwise
void rotate(){
  int check_ok;
  // if it is ok to move down
  check_ok = check(3);

  if(check_ok != 0){
    rotate_sound();
    sel_block(block, type, x, y, false);
    type_next(check_ok);
  }
}

// check if the movement is ok
int check(int dir){
  // rotate type flag
  int flag;
  
  switch(dir){
    // move down checker
    case 0:
      for(int i = 1; i < 21; i++){
        for(int j = 1; j < 11; j++){
          if (moving_map[i][j]) { // moving block detected
            if (game_map[i-1][j] || i == 1){ // see if the position under this pixel is empty
              return 0;
            }
          }  
        }
      }
      flag = 1;
      break;

    // move left checker
    case 1:
      for(int i = 1; i < 21; i++){
        for(int j = 1; j < 11; j++){
          if (moving_map[i][j]) { // moving block detected
            if (game_map[i][j-1] || j == 1){ // see if the pixel on the left is empty
              return 0;
            }
          }  
        }
      }
      flag = 1;
      break;  

    // move right checker
    case 2:
      for(int i = 1; i < 21; i++){
        for(int j = 1; j < 11; j++){
          if (moving_map[i][j]) { // moving block detected
            if (game_map[i][j+1] || j == 10){ // see if the pixel on the right is empty
              return 0;
            }
          }  
        }
      }
      flag = 1;
      break;
  
    // clockwise rotate checker
    case 3:
      flag = 1;
      switch(block){
        // I block
        case 0:
          switch(type){
            case 0:
              for (int i = 1; i < 4 ; i++){
                if((game_map[y-i][x+1])){
                  return 0;
                } else if (y < 4){
                  if(game_map[y+4-i][x+1]){
                    return 0;
                  }
                  return 2;
                }
              }
              break;

            case 1:
              for (int i = -1; i < 3 ; i++){
                if(game_map[y][x+i]){
                  return 0;
                } else if (x > 8) {
                  if (game_map[y][x-4+i]){
                    return 0;
                  }
                  flag = 2;
                } else if (x < 2){
                  if (game_map[y][x+3]){
                    return 0;
                  }
                  flag = 3;
                }
              }
              break;
          }
          break;

        // J block
        case 1:
          switch(type){
            case 0:
              if (game_map[y][x-1] || game_map[y-1][x-1] || game_map[y-1][x+1]){
                return 0;
              } else if (x == 10){
                if (game_map[y][x-2] || game_map[y-1][x-2]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 1:
              if (game_map[y][x+1] || game_map[y-2][x]){
                return 0;
              } else if (y < 3){
                if (game_map[y+1][x] || game_map[y+1][x+1]){
                  return 0;
                }
                flag = 2;
              }
              break;
              
            case 2:
              if (game_map[y][x+2] || game_map[y-1][x+2]){
                return 0;
              } else if (x > 8){
                if (game_map[y][x-1] || game_map[y-1][x+1]){
                  return 0;
                }
                flag = 2;
              }
              
              break;

            case 3:
              if (game_map[y-2][x] || game_map[y-1][x+1] || game_map[y-2][x+1]){
                return 0;
              } else if (y < 3){
                if (game_map[y-1][x] || game_map[y+1][x+1]) {
                  return 0;
                }
                flag = 2;
              }
              break;
          }
          break;

        // L block
        case 2:
          switch(type){
            case 0:
              if (game_map[y][x-1] || game_map[y-1][x-1] || game_map[y][x+1]){
                return 0;
              } else if (x == 1){
                if (game_map[y][x+2]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 1:
              if (game_map[y-1][x+2] || game_map[y-2][x+2]){
                return 0;
              } else if (y < 3){
                if (game_map[y+1][x+1] || game_map[y+1][x+2]){
                  return 0;
                }
                flag = 2;
              }
              break;
              
            case 2:
              if (game_map[y-1][x] || game_map[y-1][x-1]){
                return 0;
              } else if (x == 1){
                if (game_map[y][x+2] || game_map[y-1][x+2]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 3:
              if (game_map[y][x-1] || game_map[y-2][x-1] || game_map[y-2][x]){
                return 0;
              } else if (y < 3){
                if (game_map[y+1][x-1]) {
                  return 0;
                }
                flag = 2;
              }
              break;
          }
          break;

        // O block
        case 3:
          return 0;
          break;

        // S block
        case 4:
          switch(type){
            case 0:
              if (game_map[y-1][x+1] || game_map[y-2][x+1]){
                return 0;
              } else if (y < 3) {
                if (game_map[y+1][x]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 1:
              if (game_map[y][x+1] || game_map[y-1][x-1]){
                return 0;
              } else if (x == 1) {
                if (game_map[y][x+2]){
                  return 0;
                }
                flag = 2;
              }
              break;
          }
          break;

        // Z block
        case 5:
          switch(type){
            case 0:
              if (game_map[y-1][x] || game_map[y-2][x]){
                return 0;
              } else if (y < 3) {
                if (game_map[y+1][x+1]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 1:
              if (game_map[y][x-1] || game_map[y-1][x+1]){
                return 0;
              } else if (x == 10) {
                if (game_map[y][x-2]){
                  return 0;
                }
                flag = 2;
              }
              break;
          }
          break;

        // T block
        case 6:
          switch(type){
            case 0:
              if (game_map[y][x-1] || game_map[y-2][x-1]){
                return 0;
              } else if (y < 3) {
                if (game_map[y+1][x-1]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 1:
              if (game_map[y][x+1] || game_map[y][x+2]){
                return 0;
              } else if (x > 8) {
                if (game_map[y][x-1]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 2:
              if (game_map[y-1][x] || game_map[y-2][x+1]){
                return 0;
              } else if (y < 3) {
                if (game_map[y+1][x+1]){
                  return 0;
                }
                flag = 2;
              }
              break;

            case 3:
              if (game_map[y-1][x+1]){
                return 0;
              } else if (x == 10) {
                if (game_map[y][x-1] || game_map[y-1][x-2]){
                  return 0;
                }
                flag = 2;
              }
              break;
          }
          break;
      }
  }
  return flag;
}

// This function switch types and reset the starting pixel of the moving block if needed
void type_next(int check_ok){
  switch(block){
    // I block
    case 0:
      switch(type){
        // horizontal to vertical
        case 0:
          if (check_ok == 2){
            y = 4;
          }
          x = x + 1;
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        // vertical to horizontal
        case 1:
          if (check_ok == 2){
            x = 7;
          } else if (check_ok == 3){
            x = 1;
          } else{
            x = x - 1;
          }
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break;
    // J block  
    case 1:
      switch(type){
        case 0:
          if (check_ok == 2){
            x = 8;
          } else{
            x = x - 1;
          }
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        case 1:
          if (check_ok == 2){
            y = 3;
          }
          type = 2;
          sel_block(block, type, x, y, true);
          break;
        case 2:
          if (check_ok == 2){
            x = x - 1;
          }
          type = 3;
          sel_block(block, type, x, y, true);
          break;
        case 3:
          if (check_ok == 2){
            y = y + 1;
          }
          x = x + 1;
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break; 
    // L block
    case 2:
      switch(type){
        case 0:
          if (check_ok == 2){
            // x = x
          } else {
            x = x - 1;
          }
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        case 1:
          if (check_ok == 2){
            y = y + 1;  
          }
          x = x + 1;
          type = 2;
          sel_block(block, type, x, y, true);
          break;
        case 2:
          if (check_ok == 2){
            x = x + 1;
          }
          x = x + 1;
          type = 3;
          sel_block(block, type, x, y, true);
          break;
        case 3:
          if (check_ok == 2){
            y = y + 1;
          }
          x = x - 1;
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break; 
    // O block
    case 3:
      sel_block(block, type, x, y, true);
      break;
    // S block
    case 4:
      switch(type){
        case 0:
          if (check_ok == 2){
            y = y + 1;
          }
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        case 1:
          if (check_ok == 2){
            x = x + 1;
          }
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break; 
    // Z block
    case 5:
      switch(type){
        case 0:
          if (check_ok == 2){
            y = y + 1;
          }
          x = x + 1;
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        case 1:
          if (check_ok == 2){
            x = x - 1;
          }
          x = x - 1;
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break; 
    // T block
    case 6:
      switch(type){
        case 0:
          if (check_ok == 2){
            y = y + 1;
          }
          x = x - 1;
          type = 1;
          sel_block(block, type, x, y, true);
          break;
        case 1:
          if (check_ok == 2){
            x = x - 1;
          }
          type = 2;
          sel_block(block, type, x, y, true);
          break;
        case 2:
          if (check_ok == 2){
            y = y + 1;
          }
          x = x + 1;
          type = 3;
          sel_block(block, type, x, y, true);
          break;
        case 3:
          if (check_ok == 2){
            x = x - 1;
          }
          type = 0;
          sel_block(block, type, x, y, true);
          break;
      }
      break; 
  }
}

// this function checks if a line is full. If full, earse the line and add points
void check_line(){
  int line_count = 0;
  for(int i = 1; i < 21; i++){
    int j = 1;
    while(game_map[i][j]){
      j++;
      if (j > 10){
        // Serial.println(j);
        line_count++;
        line_erase(i);
         i = i - 1;
      }
    }
  }

  /* line erased | add pts  | lv
   *    1             1        1
   *    2             2        1
   *    3             4        1
   *    4             8        1
   */
  if (line_count != 0){
    point = point + (powint(2, line_count - 1) * lv);
    score_sound(line_count);
    // update score
    score(point);
  } 
}

void line_erase(int line){
  // all colors from red to cyan
  char all_color[] = {"gbwyopc"};
  // select a random color
  char new_color;
  
  for (int i = line; i < 20 ; i++){
    for (int j = 1; j < 11; j++){
      if (game_map[i+1][j]){ // pixel above is occupied
        new_color = all_color[random(0,6)];
      } else {  // empty pixel above
        new_color = 'e';
      }
      updatePixel(j, i, new_color);
    }
  }
  // clear the top line
  matrix.drawLine(20 ,3 ,20, 12, color('e'));
}

// This function translate the gaming zone coordinate to the whole matrix coordinate
// And update game map
void updatePixel(int x_live, int y_live, char color_select){
  // update moving map
  if(color_select == 'e'){
    game_map[y_live][x_live] = false; 
  } else{
    game_map[y_live][x_live] = true;
  }
  
  // relocate x and y value to fit in 32*16 matrix
  int temp;
  temp = x_live;
  x_live = y_live;
  y_live = temp + 2;
  
  matrix.drawPixel(x_live, y_live, color(color_select));
}
