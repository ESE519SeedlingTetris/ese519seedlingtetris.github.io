// This function displays a score above the tetris
// gaming area
void score(int pt){
  // lv 1 to 6 depending on current points
  if (point >= 20){
    lv = 2;
    droptime = initial_droptime * 0.9;
    if (point >= 40){
      lv = 3;
      droptime = initial_droptime * 0.9 * 0.9;
      if (point >= 100){
        lv = 4;
        droptime = initial_droptime * 0.9 * 0.9* 0.9;
        if (point >= 200){
          lv = 5;
          droptime = initial_droptime * 0.9 * 0.9 * 0.9 * 0.9;
          if (point >= 400){
            lv = 6;
            droptime = initial_droptime * 0.9 * 0.9 * 0.9 * 0.9 * 0.9;
          }
        }         
      }  
    }
  } else {
    droptime = initial_droptime;
  }
  
  int hundreds, tens, ones;
  // extract digits
  ones = pt % 10;
  if ((ones == 7) || (point % 7 == 0 && point != 0)){
    // when hit seven on ones digit or hit the mutiples of seven
    // play seven noise, and droptime is temporarily decreased by 30%
    touch_seven = true;
    seven_block_coming = true;
    /*
    seven_noise();
    seven_block(5, 20, true);
    */
    droptime = droptime * 0.7;
  }
  display_num(ones, 1);
  pt = pt / 10;
  tens = pt % 10;
  display_num(tens, 2);
  pt = pt / 10;
  hundreds = pt % 10; 
  display_num(hundreds, 3);

  touch_seven = false;
  
}

void display_num(int number, int digit){
  // the color of this display
  char color_select;
  color_select = 'y';
  
  if (touch_seven){
    color_select = 'b';
  }

  // score block left lowest pixel
  int x, y;
  x = 22;
  switch(digit){
    case 1:
      y = 11;
      break;
    case 2:
      y = 6;
      break;
    case 3:
      y = 1;
      break;
  }
  matrix.fillRect(x, y, 5, 3, color('e'));
  // draw numbers 0 - 9
  switch(number){
    case 0:
      matrix.drawRect(x, y, 5, 3, color(color_select));
      break;

    case 1:
      matrix.drawLine(x, y+1, x+4, y+1, color(color_select));
      break;

    case 2:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawLine(x+1, y+1, x+1, y+2, color('e'));
      matrix.drawLine(x+3, y, x+3, y+1, color('e'));
      break;

    case 3:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawLine(x+1, y, x+1, y+1, color('e'));
      matrix.drawLine(x+3, y, x+3, y+1, color('e'));
      break;

    case 4:
      matrix.drawLine(x+2, y, x+4, y, color(color_select));
      matrix.drawLine(x, y+2, x+4, y+2, color(color_select));
      matrix.drawPixel(x+2, y+1, color(color_select));
      break;

    case 5:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawLine(x+1, y, x+1, y+1, color('e'));
      matrix.drawLine(x+3, y+1, x+3, y+2, color('e'));
      break;

    case 6:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawLine(x+3, y+1, x+3, y+2, color('e'));
      matrix.drawPixel(x+1, y+1, color('e'));
      break;

    case 7:
      matrix.drawLine(x+4, y, x+4, y+2, color(color_select));
      matrix.drawLine(x, y+2, x+3, y+2, color(color_select));
      break;

    case 8:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawPixel(x+1, y+1, color('e'));
      matrix.drawPixel(x+3, y+1, color('e'));
      break;

    case 9:
      matrix.fillRect(x, y, 5, 3, color(color_select));
      matrix.drawLine(x+1, y, x+1, y+1, color('e'));
      matrix.drawPixel(x+3, y+1, color('e'));
      break;
  }
}

// This function calculates the power of an integer
int powint(int base, int power)
{
  if (power==0) {
    return(1);
  } else {
    return(powint(base,power-1)*base);
  }
}
