/* This function takes in a color select charg and return the 16 bits color code for pixel colr
 * color select string: 
 * r for red,
 * g for grenn,
 * b for blue,
 * w for white
 * e for erase
 * y for yellow
 * p for pink
 * o for orange
 * c for cyan
 * Author: Shu Xu
 * Last edited: Dec 16th, 2022
 */

uint16_t color(char select) {
  uint16_t color_select;
  if (select == 'r'){
    color_select = matrix.Color333(7, 0, 0);
  } else if (select == 'g'){
    color_select = matrix.Color333(0, 7, 0);
  } else if (select == 'b'){
    color_select = matrix.Color333(0, 0, 7);
  } else if (select == 'w'){
    color_select = matrix.Color333(7, 7, 7);
  } else if (select == 'e'){
    color_select = matrix.Color333(0, 0, 0);
  } else if (select == 'y'){
    color_select = matrix.Color333(7, 7, 0);
  } else if (select == 'p'){
    color_select = matrix.Color333(7, 0, 7);
  } else if (select == 'o'){
    color_select = matrix.Color333(7, 3, 0);
  } else if (select == 'c'){
    color_select = matrix.Color333(0, 7, 7);
  }
  return color_select;
}
