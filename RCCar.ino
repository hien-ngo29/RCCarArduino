#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <Arduino.h>
#include <Servo.h>
#include "CarCore.h"
#include "Pins.h"
#include <Dabble.h>

using namespace RCCar;

// InputReader inputReader;
CarCore carCore;

Servo wheelServo;
SoftwareSerial bluetooth(bluetoothPin1, bluetoothPin2);

unsigned long lastPacket = 0;

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
  if (GamePad.isUpPressed())
    carCore.MoveForward();
  else if (GamePad.isDownPressed())
    carCore.MoveBackward();
  else
    carCore.ReturnToIdleState();

  if (GamePad.isCirclePressed())
    carCore.TurnRight();
  else if (GamePad.isSquarePressed())
    carCore.TurnLeft();
  else
    carCore.SetWheelAngleDefault();
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
