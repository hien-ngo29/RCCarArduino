#pragma once

namespace RCCar {
  class InputReader {
  public:
    virtual bool isRightPressed();
    virtual bool isLeftPressed();
    virtual bool isForwardPressed();
    virtual bool isBackwardPressed();
    
    virtual bool isIncreaseSpeedPressed();
    virtual bool isDecreaseSpeedPressed();
  };
}