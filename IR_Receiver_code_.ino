#include <IRremote.hpp>  // For IRremote 4.x and newer

const int IR_RECEIVE_PIN = 2;

const int ledPins[] = {3, 4, 5, 6};
const uint32_t irCodes[] = {
  0xFFA25D, // Button 1
  0xFF629D, // Button 2
  0xFFE21D, // Button 3
  0xFF22DD  // Button 4
};

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t receivedCode = IrReceiver.decodedIRData.command;
    Serial.print("Received Code: ");
    Serial.println(receivedCode, HEX);

    // Match received code with known codes
    for (int i = 0; i < 4; i++) {
      if (receivedCode == (irCodes[i] & 0xFF)) { // Compare only 8-bit command value
        digitalWrite(ledPins[i], !digitalRead(ledPins[i])); // Toggle LED
        break;
      }
    }

    IrReceiver.resume(); // Ready to receive next
  }
}
