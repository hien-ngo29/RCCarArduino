#include <SoftwareSerial.h>
#pragma once

namespace RCCar {
  class InputReader {
  protected:
    SoftwareSerial *bluetoothModule;
    char receivedDATA;
  public:
    InputReader();
    InputReader(SoftwareSerial &bluetooth);

    void SetBluetoothModule(SoftwareSerial &bluetooth);
    
    virtual void init();
    virtual void process(); // To be run on loop

    virtual bool isRightPressed();
    virtual bool isLeftPressed();
    virtual bool isForwardPressed();
    virtual bool isBackwardPressed();
    
    virtual bool isIncreaseSpeedPressed();
    virtual bool isDecreaseSpeedPressed();
  };
}