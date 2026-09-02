#include <IRremote.hpp>

const int buttonPins[] = {2, 3, 4, 5};
const uint8_t irCommands[] = {
  0xA2, // Button 1
  0x62, // Button 2
  0xE2, // Button 3
  0x22  // Button 4
};

void setup() {
  Serial.begin(9600);
  IrSender.begin(9); // IR LED on pin 9
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      IrSender.sendNEC(0x00FF, irCommands[i], 0); // Address, Command, Repeat
      Serial.print("Sent: ");
      Serial.println(irCommands[i], HEX);
      delay(300);
    }
  }
}
