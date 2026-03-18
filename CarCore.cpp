#include "Arduino.h"
#include "CarCore.h"

RCCar::CarCore::RCCar() {
  
}

void RCCar::CarCore::ReturnToIdleState() {
  currentSpeed = 0;
}

void RCCar::CarCore::SetWheelAngleDefault() {
  currentWheelAngle = 90;
}

void RCCar::CarCore::MoveForward() {
  // switch (carCore) {
  //   case CarMode::MANUAL:
  //     MoveForwardManualMode();
  //     break;
  //   case CarMode::AUTO:
  //     MoveForwardAutoMode();
  //     break;
  // }
  currentSpeed = carLimitData.maxSpeed;
}

void RCCar::CarCore::TurnLeft() {
  currentWheelAngle = 90 - carLimitData.maxTurnAngle;
}

void RCCar::CarCore::TurnRight() {
  currentWheelAngle = 90 + carLimitData.maxTurnAngle;
}

void RCCar::CarCore::MoveBackward() {
  currentSpeed = -carLimitData.maxSpeed / 3;
}

void RCCar::CarCore::MoveForwardAutoMode() {
  IncreaseSpeed();
  MoveForwardManualMode();
}

void RCCar::CarCore::MoveForwardManualMode() {
  currentSpeed = carLimitData.maxSpeed;
}

void RCCar::CarCore::IncreaseSpeed(int interval = 2) {
  carLimitData.maxSpeed += interval;
  carLimitData.maxSpeed = constrain(interval, 1, 255);
}

bool RCCar::CarCore::isInStopState() {
  return currentSpeed == 0;
}

int RCCar::CarCore::GetCurrentSpeed() {
  return currentSpeed;
}

int RCCar::CarCore::GetCurrentWheelAngle() {
  return currentWheelAngle;
}