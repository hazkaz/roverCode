#include "robot.h"

boolean on = true;

void indicate_led(LED light, boolean on) {
  if (on) {
    digitalWrite(light, HIGH);
  } else {
    digitalWrite(light, LOW);
  }
}

void test_leds() {
  indicate_led(YELLOW_LED, true);
  indicate_led(GREEN_LED, false);
  delay(500);
  indicate_led(YELLOW_LED, false);
  indicate_led(GREEN_LED, true);
  delay(500);
}
