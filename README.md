A small program for a RC Car project of my school tech club.

## Building your own RC Car for this code
This project uses Arduino UNO.

We decided to use [Dabble](https://play.google.com/store/apps/details?id=io.dabbleapp) (Available on both Android and iOS) to control the car movement. Install, select **Gamepad** and connect your bluetooth module, that's it.

Car struture:
- A servo (_MG996R_ or likewise is recommended), setting up in a way that the car can turn when the servo is rotated (you might need to modify [CarCore.h](./CarCore.h) and [CarLimitData.h](./CarLimitData.h) to match your set up).
- A motor (we're using DC Servo GA25-370, i'm not sure if my code accepts any kind of other motors) to make the car move.
- An HM-05 or HC-10 UART bluetooth module for input reading.

Decide how car look, my code just care about these 3 parts.
> Visit [Pins.h](./Pins.h) for references about pins and modify if you need.
