// include keyboard module
#include <Keyboard.h>

void setup() {
// setup pins and start keyboard communication
  pinMode(9, INPUT_PULLUP);
  Keyboard.begin();
}

// set variable to false
bool lastState = false;

void loop() {
// read pin 9
  int isConnected = digitalRead(9);

// check last state and if it's unpressed
  if (lastState != isConnected && lastState == 0) {

// press esc, delay for 50ms, and release
      Keyboard.press(KEY_ESC);
      delay(50);
      Keyboard.releaseAll();
  }

// set last state to current state for next loop
  lastState = isConnected;
  delay(50);
}