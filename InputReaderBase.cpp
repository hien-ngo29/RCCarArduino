#include "InputReaderBase.h"

void RCCar::InputReaderBase::process() {
  if (bluetoothModule->available()) {
    receivedDATA = bluetoothModule->read();
  }
}

bool RCCar::InputReaderBase::isRightPressed() {
  return receivedDATA == 'C';
}

bool RCCar::InputReaderBase::isLeftPressed() {
  return receivedDATA == 'S';
}

bool RCCar::InputReaderBase::isForwardPressed() {
  return receivedDATA == 'F';
}

bool RCCar::InputReaderBase::isBackwardPressed() {
  return receivedDATA == 'B';
}

bool RCCar::InputReaderBase::isIncreaseSpeedPressed() {
  return receivedDATA == 'T';
}

bool RCCar::InputReaderBase::isDecreaseSpeedPressed() {
  return receivedDATA == 'X';
}