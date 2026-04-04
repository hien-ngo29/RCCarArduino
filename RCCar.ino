#include <Arduino.h>
#include <Servo.h>
#include "CarCore.h"
#include "Pins.h"
#include "InputReaderBase.h"

using namespace RCCar;

InputReader carInputReader;
CarCore carCore;

Servo wheelServo;
SoftwareSerial bluetooth(bluetoothPinTX, bluetoothPinRX);

InputReaderBase inputReaderBase;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(engineForwardPin, OUTPUT);
  pinMode(engineBackwardPin, OUTPUT);

  wheelServo.attach(turnPin);

  carCore.ReturnToIdleState();
  carCore.SetWheelAngleDefault();
}

void loop() {
  inputReaderBase.process();

  carCore.ReturnToIdleState();
  carCore.SetWheelAngleDefault();
    
  checkControl();
  runFromCarData();
}

void checkControl() {
  checkStraightControl();
  checkWheelRotationControl();
  checkSpeedControl();
}

void checkStraightControl()
{
  if (inputReaderBase.isForwardPressed())
    carCore.MoveForward();
  else if (inputReaderBase.isBackwardPressed())
    carCore.MoveBackward();
  else
    carCore.ReturnToIdleState();
}

void checkWheelRotationControl()
{
  if (inputReaderBase.isRightPressed())
    carCore.TurnRight();
  else if (inputReaderBase.isLeftPressed())
    carCore.TurnLeft();
  else
    carCore.SetWheelAngleDefault();
}

void checkSpeedControl()
{
  if (inputReaderBase.isIncreaseSpeedPressed())
    carCore.IncreaseSpeed();
  else if (inputReaderBase.isDecreaseSpeedPressed())
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
