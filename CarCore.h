#pragma once
#include "CarLimitData.h"

namespace RCCar {
  enum class CarMode {
    AUTO, // Car has acceleration till max speed on move foward event pressed
    MANUAL // Car speed is configured through events
  };

  class CarCore {
  private:
    CarLimitData carLimitData;
    int currentSpeed = 0;
    int currentWheelAngle = 90;

    CarMode carMode;

  public:
    RCCar();
    void ReturnToIdleState();
    void SetWheelAngleDefault();

    void MoveForward();
    void TurnRight();
    void TurnLeft();
    void MoveBackward();

    void MoveForwardAutoMode();
    void MoveForwardManualMode();

    void IncreaseSpeed(int interval = 2);

    bool isInStopState();

    int GetCurrentSpeed();
    int GetCurrentWheelAngle();
    
  };
}