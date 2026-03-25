#pragma once
#include "CarLimitData.h"

namespace RCCar {
  class CarCore {
  private:
    CarData carDefaultData;
    int currentSpeed = 0;
    int currentWheelAngle = 90;

  public:
    RCCar();
    void ReturnToIdleState();
    void SetWheelAngleDefault();

    void MoveForward();
    void TurnRight();
    void TurnLeft();
    void MoveBackward();

    void IncreaseSpeed(int interval = 2);
    void DecreaseSpeed(int interval = 2);

    bool isInStopState();

    int GetCurrentSpeed();
    int GetCurrentWheelAngle();
    
  };
}