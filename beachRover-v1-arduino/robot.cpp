#include<Arduino.h>
#include "robot.h"
#include "pitches.h"

boolean on = true;

void indicate_led(LED light, boolean on) {
  if (on) {
    digitalWrite(light, HIGH);
  } else {
    digitalWrite(light, LOW);
  }
}



void flash_leds(){
  indicate_led(YELLOW_LED, true);
  indicate_led(GREEN_LED, false);
  delay(500);
  indicate_led(YELLOW_LED, false);
  indicate_led(GREEN_LED, true);
  delay(500);
  indicate_led(YELLOW_LED, false);
  indicate_led(GREEN_LED, false);
}

void test_leds() {
 for(int i=0;i<2;i++){
  flash_leds(); 
 }
}


//Mario main theme melody
int mario[] = {
  NOTE_C7,NOTE_E7, NOTE_G7
};

//Mario main them tempo
int mario_tempo[] = {
  9,9,9
};

void buzz(int targetPin, long frequency, long length) {
  //  analogWrite(GREEN_LED, 255);
  long delayValue = 1000000 / frequency / 2;

  long numCycles = frequency * length / 1000;

  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  //  analogWrite(GREEN_LED, 0);

}

void sing(int song[],int song_length, int* tempo) {
  
  for (int thisNote = 0; thisNote < song_length; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    buzz(BUZZER, song[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    buzz(BUZZER, 0, noteDuration);
  }
}


void run_diagnostics() {
  pinMode(BUZZER, OUTPUT);//buzzer
  sing(mario,sizeof(mario)/sizeof(mario[0]), mario_tempo);
  test_leds();
}
