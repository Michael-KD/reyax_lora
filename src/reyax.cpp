#include "reyax.h"

Reyax::Reyax(HardwareSerial& serial, int rstPin) : serial(serial), rstPin(rstPin) {}

void Reyax::begin() {
    serial.begin(115200);
    pinMode(rstPin, OUTPUT);
    digitalWrite(rstPin, HIGH);
    reset();
}

bool Reyax::sendATCommand(String command) {
    serial.println(command);
    delay(100);
    String response = readResponse();
    Serial.println("Sent: " + command);
    Serial.println("Received: " + response);
    return response.startsWith("+OK");
}

String Reyax::readResponse() {
    String response = "";
    while (serial.available()) {
        response += char(serial.read());
    }
    return response;
}

void Reyax::reset() {
    digitalWrite(rstPin, LOW);
    delay(100);
    digitalWrite(rstPin, HIGH);
    delay(100);
    Serial.println("Reset complete");
}