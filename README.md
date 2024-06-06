# cleaning_robot
Components and Pin Assignments

**Ultrasonic Sensor:**

trigPin (Pin 2): Trigger pin to send the ultrasonic pulse.

echoPin (Pin 3): Echo pin to receive the reflected pulse.

**Motors:**

Pins 4, 5, 6, 7: Control the direction of the motors.

Pin 8: Controls a sprayer.

**LED or Indicator:**

Pin 14: LED that lights up when an obstacle is detected within 30 cm.

**Software Serial Communication:**

mySerial: Uses pins 10 and 11 for serial communication with another device, such as a remote control or a computer.

Setup Function

Initializes the pin modes for the ultrasonic sensor, motors, sprayer, and LED.
Starts the hardware and software serial communication at 9600 baud rate.
Sends a welcome message over the software serial interface.

****Loop Function**

**Obstacle Detection:****

Sends a pulse from the trigPin.
Measures the duration of the echo pulse received by the echoPin.
Calculates the distance to an obstacle.
Prints the distance to the serial monitor.

**Obstacle Handling:**

If an obstacle is detected within 30 cm, it sends an alert message over the software serial interface, blinks the LED, and stops all motors.
Remote Control Commands:

Checks if there's any incoming data from the software serial interface.
Depending on the received character, it performs actions like:

'C': Turns the sprayer ON.

'D': Turns the sprayer OFF.

'F': Moves the robot forward.

'B': Moves the robot backward.

'L': Turns the robot left.

'R': Turns the robot right.

'S': Stops the robot.

Detailed Functionality

**Ultrasonic Sensor Logic:**

Sends a HIGH pulse for 10 microseconds to the trigPin.
Measures the duration of the HIGH pulse on the echoPin, which corresponds to the time taken for the pulse to travel to the obstacle and back.

**Distance calculation: **
diatance =(duration/2 )/29.1 

converts the time into a distance in cm.

**Motor Control:**

The state of pins 4, 5, 6, and 7 determines the movement direction of the robot:

Forward: Pin 7 and Pin 5 HIGH, Pin 6 and Pin 4 LOW.

Backward: Pin 7 and Pin 5 LOW, Pin 6 and Pin 4 HIGH.

Left: Pin 6 and Pin 5 HIGH, Pin 7 and Pin 4 LOW.

Right: Pin 7 and Pin 4 HIGH, Pin 6 and Pin 5 LOW.

Stop: All motor pins LOW.


**Sprayer Control:**

The state of pin 8 controls the sprayer:

HIGH: Sprayer OFF.

LOW: Sprayer ON.
