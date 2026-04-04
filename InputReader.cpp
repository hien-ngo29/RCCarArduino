#include "InputReader.h"

RCCar::InputReader::InputReader() : bluetoothModule(nullptr) {
  
}

RCCar::InputReader::InputReader(SoftwareSerial &bluetooth) {
  SetBluetoothModule(bluetooth);
}

void RCCar::InputReader::SetBluetoothModule(SoftwareSerial &bluetooth) {
  bluetoothModule = &bluetooth;
}

void RCCar::InputReader::init() {}
void RCCar::InputReader::process() {}
bool RCCar::InputReader::isForwardPressed() {}
bool RCCar::InputReader::isBackwardPressed() {}
bool RCCar::InputReader::isRightPressed() {}
bool RCCar::InputReader::isLeftPressed() {}
bool RCCar::InputReader::isIncreaseSpeedPressed() {}
bool RCCar::InputReader::isDecreaseSpeedPressed() {}