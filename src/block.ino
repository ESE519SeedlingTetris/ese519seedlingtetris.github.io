  // ------------------------------------------- block function -------------------------------------------
/* block:
 *  0 -- I
 *  1 -- J
 *  2 -- L
 *  3 -- O
 *  4 -- S
 *  5 -- Z
 *  6 -- T
*/

/*  This function draw or erase a block as needed
 *   block: 0 to 6 to select block type
 *  type: 0 to 1 or 0 to 3 to select forward of the block
 *  x,y : leading pixel position (usually the highest / left most pixel
 *  write: 0 as clear, 1 as write
 */


void sel_block(int block, int type, int x, int y, boolean write){
  
  switch(block){
    case 0:
      I_block(type, x, y, write);
      break;

    case 1:
      J_block(type, x, y, write);
      break;

    case 2:
      L_block(type, x, y, write);
      break;

    case 3:
      O_block(x, y, write);
      break;

    case 4:
      S_block(type, x, y, write);
      break;

    case 5:
      Z_block(type, x, y, write);
      break;
      
    case 6:
      T_block(type, x, y, write);
      break;

    case 7:
      seven_block(x, y, write);
      break;
  }
}

// This is the special giant seven block which can't rotate
void seven_block(int x, int y, boolean write){
  // select color as blue if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'b';
  }

  drawPixel(x, y, color_select);
  drawPixel(x+1, y, color_select);
  drawPixel(x+2, y, color_select);
  drawPixel(x+2, y-1, color_select);
  drawPixel(x+2, y-2, color_select);
  drawPixel(x+2, y-3, color_select);
  drawPixel(x+2, y-4, color_select);
}

/* I block: two cases 
 *  case 0 - horizontal
 *  case 1 - vertical 
 *  x, y represents the starting point of block 
 *  write represents write/erase action
 */
void I_block(int type, int x, int y, boolean write){
  
  // select color as green if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'g';
  }
  
  
  
  switch(type){
    
    // horizontal I block
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+2, y, color_select);
      drawPixel(x+3, y, color_select);
      break;
    // vertical I block
    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x, y-3, color_select);
      break;
  } 
}

/* J block: four cases 
 *  case 0 - vertical left
 *  case 1 - horizontal up
 *  case 2 - vertical right
 *  case 3 - horizontal down
 *  write represents write/erase action
 */
void J_block(int type, int x, int y, boolean write){
  
  // select color as blue if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'b';
  }
  
  switch(type){
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x-1, y-2, color_select);
      break;

    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x+1, y-1, color_select);
      drawPixel(x+2, y-1, color_select);
      break;

    case 2:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x+1, y, color_select);
      break;

    case 3:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+2, y, color_select);
      drawPixel(x+2, y-1, color_select);
      break;
    
  }
}

/* L block: four cases 
 *  case 0 - vertical right
 *  case 1 - horizontal down
 *  case 2 - vertical left
 *  case 3 - horizontal up
 *  write represents write/erase action
 */
void L_block(int type, int x, int y, boolean write){
  
  // select color as white if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'w';
  }
  
  switch(type){
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x+1, y-2, color_select);
      break;

    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+2, y, color_select);
      break;

    case 2:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+1, y-1, color_select);
      drawPixel(x+1, y-2, color_select);
      break;

    case 3:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x-1, y-1, color_select);
      drawPixel(x-2, y-1, color_select);
      break;
  }
}

// O block
// write represents write/erase action
void O_block(int x, int y, boolean write){
  
  // select color as yellow if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'y';
  }
  
  drawPixel(x, y, color_select);
  drawPixel(x+1, y, color_select);
  drawPixel(x, y-1, color_select);
  drawPixel(x+1, y-1, color_select);
}

/* S block: two cases 
 *  case 0 - horizontal
 *  case 1 - vertical
 *  write represents write/erase action
 */
void S_block(int type, int x, int y, boolean write){
  
  // select color as pink if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'p';
  }
  
  switch(type){
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x-1, y-1, color_select);
      break;

    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x+1, y-1, color_select);
      drawPixel(x+1, y-2, color_select);
      break;
  }
}

/* Z block: two cases 
 *  case 0 - horizontal
 *  case 1 - vertical
 *  write represents write/erase action
 */
void Z_block(int type, int x, int y, boolean write){
  
  // select color as orange if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'o';
  }
  
  switch(type){
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+1, y-1, color_select);
      drawPixel(x+2, y-1, color_select);
      break;

    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x-1, y-1, color_select);
      drawPixel(x-1, y-2, color_select);
      break;
  }
}

/* T block: four cases 
 *  case 0 - up
 *  case 1 - right
 *  case 2 - dpwn
 *  case 3 - left
 *  write represents write/erase action
 */
void T_block(int type, int x, int y, boolean write){
  
  // select color as cyan if not erased
  char color_select;
  if (!write){
    color_select = 'e';
  } else {
    color_select = 'c';
  }
  
  switch(type){
    case 0:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x-1, y-1, color_select);
      drawPixel(x+1, y-1, color_select);
      break;

    case 1:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x+1, y-1, color_select);
      break;

    case 2:
      drawPixel(x, y, color_select);
      drawPixel(x+1, y, color_select);
      drawPixel(x+2, y, color_select);
      drawPixel(x+1, y-1, color_select);
      break;

    case 3:
      drawPixel(x, y, color_select);
      drawPixel(x, y-1, color_select);
      drawPixel(x, y-2, color_select);
      drawPixel(x-1, y-1, color_select);
      break;
  }
}

// This function translate the gaming zone coordinate to the whole matrix coordinate
// And update moving block map
void drawPixel(int x_live, int y_live, char color_select){
  // update moving map
  if(color_select == 'e'){
    moving_map[y_live][x_live] = false; 
  } else{
    moving_map[y_live][x_live] = true;
  }
  
  // relocate x and y value to fit in 32*16 matrix
  int temp;
  temp = x_live;
  x_live = y_live;
  y_live = temp + 2;
  
  matrix.drawPixel(x_live, y_live, color(color_select));
}
