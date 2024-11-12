#include "BetterButton.h"

int button1Pin = 33;
int button2Pin = 34;
int button3Pin = 32;

BetterButton button1(button1Pin, 60);
BetterButton button2(button2Pin, 62);
BetterButton button3(button3Pin, 64);

void setup() {
  Serial.begin(9600);
  
  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);
  button3.pressHandler(onPress);
  button3.releaseHandler(onRelease);
}

void loop() {
  button1.process();
  button2.process();
  button3.process();
}

void onPress(int val) {
  Serial.print(val);
  usbMIDI.sendNoteOn(val, 127, 1);
  Serial.println(" on");
}

void onRelease(int val) {
  Serial.print(val);
  usbMIDI.sendNoteOff(val, 0, 1);
  Serial.println(" off");
}
