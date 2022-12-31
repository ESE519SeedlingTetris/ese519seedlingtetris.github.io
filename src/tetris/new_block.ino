/* Create a new block
 *  Author: Shu Xu
 * Last edited: Dec 16th, 2022
 */
void create_block(){
  // select block type
  block = random(0, 7);

  // select the special giant seven block
  if (seven_block_coming){
    block = 7;
    seven_block_coming = false;
  }

  // starting position of new block
  x = 5;
  y = 20;
  
  switch(block) {
    case 0:
      type = random(0,2);     
      switch(type){
        case 0:
          x = 4;
          break;
        case 1:
          break;
      }
      break;
  
    case 1:
      type = random(0,4);
      switch(type){
        case 0:
          x = 6;
          break;
        case 1:
        case 2:
        case 3:
          break;
      }
      break;
  
    case 2:
      type = random(0,4);
      switch(type){
        case 0:
        case 1:
        case 2:
          break;
        case 3:
          x = 6;
          break;
      }
      break;
  
    case 3:
      type = 0;
      break;
  
    case 4:
      type = random(0,2);
      break;
  
    case 5:
      type = random(0,2);
      switch(type){
        case 0:
          break;
        case 1:
          x = 6;
          break;
      }
      break;
  
    case 6:
      type = random(0,4);
      switch(type){
        case 0:
        case 1:
        case 2:
          break;
        case 3:
          x = 6;
          break;
      }
      break;

    case 7:
      break;
  }
  sel_block(block, type, x, y, true);
}
