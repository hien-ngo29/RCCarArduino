#include "Arduino.h"
#include "CarCore.h"

RCCar::CarCore::RCCar() {
  
}

void RCCar::CarCore::ReturnToIdleState() {
  currentSpeed = 0;
}

void RCCar::CarCore::SetWheelAngleDefault() {
  currentWheelAngle = carDefaultData.idleTurnAngle;
}

void RCCar::CarCore::MoveForward() {
  currentSpeed = carDefaultData.maxSpeed;
}

void RCCar::CarCore::TurnLeft() {
  currentWheelAngle = carDefaultData.idleTurnAngle - carDefaultData.maxTurnAngle;
}

void RCCar::CarCore::TurnRight() {
  currentWheelAngle = carDefaultData.idleTurnAngle + carDefaultData.maxTurnAngle;
}

void RCCar::CarCore::MoveBackward() {
  currentSpeed = -carDefaultData.maxSpeed;
}

void RCCar::CarCore::IncreaseSpeed(int interval = 2) {
  carDefaultData.maxSpeed += interval;
  carDefaultData.maxSpeed = constrain(interval, 1, 255);
}

void RCCar::CarCore::DecreaseSpeed(int interval = 2) {
  IncreaseSpeed(-interval);
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