/* ESE 5190 final project: Tetris
 * Team Seedlings
 * This function builds a tetris game with Arduino UNO board and adafruit 16*32 matrix
 * panel, controled by joystick.
 * 
 * This file inclueds all global variables.
 * Author: Shu Xu
 * Last edited: Dec 16th, 2022
 */

#include <RGBmatrixPanel.h>

#define CLK  8 // clk
#define OE   9 // output enable
#define LAT 10 // latch, noted as STB on some 16*32 matrix
#define A   A0 // A to C as row select
#define B   A1
#define C   A2

/*  joystick configures
 *  X to A3, Y to A4, SW to pin12
 */
int VRx = A3;
int VRy = A4;
int SW = 12;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// Buzzer set up
// #define 

// push button set up
#define buttonPin 12

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// new block come in flag
int new_block;

// block & type
int block, type;

// block action flag
int action;

// drop timer
unsigned long last_drop;

// control timer
unsigned long last_control;

// inital drop period
const unsigned long initial_droptime = 800;
// actual drop period, depending on game points earned
unsigned long droptime;

// drop flag: drop when equals 1
bool drop;

// score of this player
int point;
// points mutiplier depending on current game speed
int lv;

// moving block position
bool moving_map[21][11];

// pixel occupied matrix, used to store the pixel thats been occupied
boolean game_map[21][11];

// moving block position
int x;
int y;

// buzzer pin
const int buzzer_PIN = 11;
// --------test
//#include <ezBuzzer.h> // ezBuzzer library

//ezBuzzer buzzer (buzzer_PIN); // create ezBuzzer object that attach to a pin;


/* notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};
*/

/*
#define REST 0
int melody[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
  NOTE_E5,   NOTE_B4,  NOTE_C5,  NOTE_D5,  NOTE_C5,  NOTE_B4,
  NOTE_A4,   NOTE_A4,  NOTE_C5,  NOTE_E5,  NOTE_D5,  NOTE_C5,
  NOTE_B4,   NOTE_C5,  NOTE_D5,  NOTE_E5,
  NOTE_C5,   NOTE_A4,  NOTE_A4,  NOTE_A4,  NOTE_B4,  NOTE_C5,

  NOTE_D5,   NOTE_F5,  NOTE_A5,  NOTE_G5,  NOTE_F5,
  NOTE_E5,   NOTE_C5,  NOTE_E5,  NOTE_D5,  NOTE_C5,
  NOTE_B4,   NOTE_B4,  NOTE_C5,  NOTE_D5,  NOTE_E5,
  NOTE_C5,   NOTE_A4,  NOTE_A4, REST, 

  NOTE_E5,   NOTE_B4,  NOTE_C5,  NOTE_D5,  NOTE_C5,  NOTE_B4,
  NOTE_A4,   NOTE_A4,  NOTE_C5,  NOTE_E5,  NOTE_D5,  NOTE_C5,
  NOTE_B4,   NOTE_C5,  NOTE_D5,  NOTE_E5,
  NOTE_C5,   NOTE_A4,  NOTE_A4,  NOTE_A4,  NOTE_B4,  NOTE_C5,

  NOTE_D5,   NOTE_F5,  NOTE_A5,  NOTE_G5,  NOTE_F5,
  NOTE_E5,   NOTE_C5,  NOTE_E5,  NOTE_D5,  NOTE_C5,
  NOTE_B4,   NOTE_B4,  NOTE_C5,  NOTE_D5,  NOTE_E5,
  NOTE_C5,   NOTE_A4,  NOTE_A4, REST

};

int noteDurations[] = {
  4, 8, 8, 4, 8, 8,
  4, 8, 8, 4, 8, 8,
  4, 8, 4, 4,
  4, 4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  4, 8, 8, 4, 8, 8,
  4, 8, 8, 4, 8, 8,
  4, 8, 4, 4,
  4, 4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 8, 4, 4,
  4, 4, 4, 4
};
*/

//int noteDurations[];
//int melody[];
  
// test ------------

// losing-sound flag
int lose = 0;

// Special rule: Don't touch seven!
// the flag used to alter the score display
bool touch_seven = false;
// the flag used to change the type for the next block
bool seven_block_coming = false;
