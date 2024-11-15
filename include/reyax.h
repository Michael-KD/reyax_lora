#ifndef REYAX_H
#define REYAX_H

#include <Arduino.h>

class Reyax {
public:
    Reyax(HardwareSerial& serial, int rstPin);
    void begin();
    bool sendATCommand(String command);
    String readResponse();
  private:
    HardwareSerial& serial;
    int rstPin;
};