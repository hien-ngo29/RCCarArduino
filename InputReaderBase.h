#include "InputReader.h"
#pragma once

namespace RCCar {
  class InputReaderBase : InputReader {
  public:
    void process() override;

    bool isRightPressed() override;
    bool isLeftPressed() override;
    bool isForwardPressed() override;
    bool isBackwardPressed() override;
    
    bool isIncreaseSpeedPressed() override;
    bool isDecreaseSpeedPressed() override;
  };
}