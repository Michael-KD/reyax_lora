#include <Arduino.h>
#include "reyax.h"

#define RST_PIN 2

Reyax reyax(Serial1, RST_PIN);

void setup() {
  while (!Serial) {
    ;
  }
  
  Serial.begin(115200); // Serial monitor
  reyax.begin();

  // Send initialization commands to Reyax 998
  reyax.sendATCommand("AT+MODE=0");  
  reyax.sendATCommand("AT+ADDRESS=1");
}

void loop() {
  if (Serial1.available()) {
    String response = reyax.readResponse();
    Serial.println("Received: " + response);
  }

  // Example command to send data
  reyax.sendATCommand("AT+SEND=2,5,HELLO");
  delay(2000);
}