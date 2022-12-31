/* This function starts/restarts the game
 *  Author: Shu Xu
 * Last edited: Dec 16th, 2022
 */

void gamestart(){
  new_block = 1;
  // draw tetris gaming area
  // drawRect(x, y, x_length, y_length, color)
  matrix.drawRect(0, 2, 22, 12, color('r'));

  // clear game area
  matrix.fillRect(1 ,3 ,20, 10, color('e'));
  
  // Point
  // P
  // drawLine(start x, start y, end x, end y, color)
  matrix.drawLine(28, 4, 31, 4, color('w'));
  matrix.drawLine(29, 6, 31, 6, color('w'));
  matrix.drawPixel(31, 5, color('w'));
  matrix.drawPixel(29, 5, color('w'));
  // T
  matrix.drawLine(28, 9, 30, 9, color('w'));
  matrix.drawLine(31, 8, 31, 10, color('w'));
  // point in seven segment form display
  point = 0;
  score(point);

  // back to lv 1
  lv = 1;
  // initialize drop time
  droptime = initial_droptime;
  


  // clear game map and moving map
  for(int i = 1; i < 21; i++){
    for(int j = 1; j < 11; j++){
      moving_map[i][j] = false;
      game_map[i][j] = false;
    }
  }
}

// game over function that displays sad face in different colors
void gameover(){
  // clear game area
  matrix.fillRect(1 ,3 ,20, 10, color('e'));
  
  // all colors from red to cyan
  char all_color[] = {"rgbwyopc"};
  char face_color;
  
  face_color = all_color[random(0,7)];
  matrix.drawLine(13, 4, 16, 4, color(face_color));
  matrix.drawLine(13, 11, 16, 11, color(face_color));
  matrix.drawLine(18, 6, 18, 9, color(face_color));
  matrix.drawLine(11, 6, 11, 9, color(face_color));
  matrix.drawLine(12, 5, 14, 7, color(face_color));
  matrix.drawLine(12, 10, 14, 8, color(face_color));
  matrix.drawLine(17, 5, 16, 6, color(face_color));
  matrix.drawLine(16, 9, 17, 10, color(face_color));
}
