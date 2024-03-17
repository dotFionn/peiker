#include <Joystick.h>

Joystick_ Joystick;

const int firstButtonId = 14;
const int buttonsCount = 3;

void setup() {
  // Initialize Button Pins
  for (int i; i < buttonsCount; i++) {
    pinMode(firstButtonId + i, INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the buttons
int lastButtonState[buttonsCount] = {};

void loop() {
  // Read pin values
  for (int i = 0; i < buttonsCount; i++)
  {
    int currentButtonState = !digitalRead(firstButtonId + i);
    if (currentButtonState != lastButtonState[i])
    {
      Joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  }

  delay(10);
}
