#include <Dabble.h>
#include "InputReader.h"

bool RCCar::InputReader::isForwardPressed() {
  return GamePad.isUpPressed();
}

bool RCCar::InputReader::isBackwardPressed() {
  return GamePad.isDownPressed();
}

bool RCCar::InputReader::isRightPressed() {
  return GamePad.isCirclePressed();
}

bool RCCar::InputReader::isLeftPressed() {
  return GamePad.isSquarePressed();
}

bool RCCar::InputReader::isIncreaseSpeedPressed() {
  return GamePad.isTrianglePressed();
}

bool RCCar::InputReader::isDecreaseSpeedPressed() {
  return GamePad.isCrossPressed();
}