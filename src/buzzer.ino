// play losing sound effect
void losing_sound(){
  if (lose == 0){
    tone(buzzer_PIN, 2000, 300);
    delay(300);
    tone(buzzer_PIN, 1500, 300);
    delay(300);
    tone(buzzer_PIN, 1000, 300);
    lose = 1;
  }
}

// play cant move right/left sound effect
void cant_move(){
  tone(buzzer_PIN, 800, 100);
}

// play rotate sound effect
void rotate_sound(){
  tone(buzzer_PIN, 300, 100);
  delay(100);
  tone(buzzer_PIN, 800, 100);
}

// play scoreing sound, depending on the number of lines earased
void score_sound(int line_count){
  tone(buzzer_PIN, 1500 * line_count, 200);
  delay(200);
  tone(buzzer_PIN, 500, 200);
}

// play when the score hits seven
void seven_noise(){
  tone(buzzer_PIN, 2000, 300); 
  delay(500);
  tone(buzzer_PIN, 2000, 300);
  delay(500);
  tone(buzzer_PIN, 2000, 300);
}

// Test -----------------
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


#define REST 0

int melody[] = {
  
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
  NOTE_C5,   NOTE_A4,  NOTE_A4, REST, 
  
  NOTE_E5,  NOTE_C5,
  NOTE_D5,   NOTE_B4,
  NOTE_C5,   NOTE_A4,
  NOTE_GS4,  NOTE_B4,  REST, 
  NOTE_E5,   NOTE_C5,
  NOTE_D5,   NOTE_B4,
  NOTE_C5,   NOTE_E5,  NOTE_A5,
  NOTE_GS5

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
  4, 4, 4, 4,
  2, 2,
  2, 2,
  2, 2,
  2, 4, 8,
  2, 2,
  2, 2,
  4, 4, 2,
  2
};
*/

// ----------------Test
