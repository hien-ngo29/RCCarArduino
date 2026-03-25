#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <Arduino.h>
#include <Dabble.h>
#include <Servo.h>
#include "CarCore.h"
#include "Pins.h"
#include "InputReader.h"

using namespace RCCar;

InputReader carInputReader;
CarCore carCore;

Servo wheelServo;
SoftwareSerial bluetooth(bluetoothPinTX, bluetoothPinRX);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Dabble.begin(bluetooth);

  pinMode(engineForwardPin, OUTPUT);
  pinMode(engineBackwardPin, OUTPUT);

  wheelServo.attach(turnPin);

  carCore.ReturnToIdleState();
  carCore.SetWheelAngleDefault();
}

void loop() {
  Dabble.processInput();

  if (Dabble.isAppConnected())  
    checkControl();
  else {
    carCore.ReturnToIdleState();
    carCore.SetWheelAngleDefault();
  }
    
  runFromCarData();
}

void checkControl() {
  checkStraightControl();
  checkWheelRotationControl();
  checkSpeedControl();
}

void checkStraightControl()
{
  if (carInputReader.isForwardPressed())
    carCore.MoveForward();
  else if (carInputReader.isBackwardPressed())
    carCore.MoveBackward();
  else
    carCore.ReturnToIdleState();
}

void checkWheelRotationControl()
{
  if (carInputReader.isRightPressed())
    carCore.TurnRight();
  else if (carInputReader.isLeftPressed())
    carCore.TurnLeft();
  else
    carCore.SetWheelAngleDefault();
}

void checkSpeedControl()
{
  if (carInputReader.isIncreaseSpeedPressed())
    carCore.IncreaseSpeed();
  else if (carInputReader.isDecreaseSpeedPressed())
    carCore.DecreaseSpeed();
}

void runFromCarData() {
  if (carCore.GetCurrentSpeed() < 0) {
    analogWrite(engineForwardPin, 0);
    analogWrite(engineBackwardPin, abs(carCore.GetCurrentSpeed()));
  }

  else if (carCore.GetCurrentSpeed() > 0) {
    analogWrite(engineBackwardPin, 0);
    analogWrite(engineForwardPin, carCore.GetCurrentSpeed());
  }

  else {
    analogWrite(engineForwardPin, 0);
    analogWrite(engineBackwardPin, 0);
  }

  wheelServo.write(carCore.GetCurrentWheelAngle());
}
