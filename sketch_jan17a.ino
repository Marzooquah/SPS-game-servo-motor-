#include <Servo.h>

// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN_1 = 2;  // the Arduino's input pin that connects to the sensor's SIGNAL pin
const int SENSOR_PIN_2 = 3;  // the Arduino's input pin that connects to the sensor's SIGNAL pin
const int SENSOR_PIN_3 = 4;  // the Arduino's input pin that connects to the sensor's SIGNAL pin

const int SERVO_1 = 5;
const int SERVO_2 = 6;
const int SERVO_3 = 7;

const int LED_RED = 8;
const int LED_GREEN = 9;

Servo servoOne;
Servo servoTwo;
Servo servoThree;

// Variables will change:
int lastState1 = LOW;  // the previous state from the input pin
int lastState2 = LOW;  // the previous state from the input pin
int lastState3 = LOW;  // the previous state from the input pin

int currentState1;  // the current reading from the input pin
int currentState2;  // the current reading from the input pin
int currentState3;  // the current reading from the input pin

bool butt_free = true;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN_1, INPUT);
  pinMode(SENSOR_PIN_2, INPUT);
  pinMode(SENSOR_PIN_3, INPUT);

  servoOne.attach(SERVO_1);
  servoTwo.attach(SERVO_2);
  servoThree.attach(SERVO_3);

  servoOne.write(180);
  delay(300);
  servoOne.write(0);

  delay(300);
  servoTwo.write(180);
  delay(300);
  servoTwo.write(0);

  delay(300);
  servoThree.write(180);
  delay(300);
  servoThree.write(0);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
}

void loop() {
  // read the state of the the input pin:
  currentState1 = digitalRead(SENSOR_PIN_1);
  currentState2 = digitalRead(SENSOR_PIN_2);
  currentState3 = digitalRead(SENSOR_PIN_3);

  if (lastState1 == HIGH && currentState1 == LOW && butt_free) {
    servoRun(servoOne);
  }

  if (lastState2 == HIGH && currentState2 == LOW && butt_free) {
    servoRun(servoTwo);
  }

  if (lastState3 == HIGH && currentState3 == LOW && butt_free) {
    servoRun(servoThree);
  }

  // save the the last state
  lastState1 = currentState1;
  lastState2 = currentState2;
  lastState3 = currentState3;
}

void servoRun(Servo &servo) {
  Serial.println("Busy");
  // Green LED ON, Red LED OFF
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, HIGH);

  butt_free = false;
  servo.write(130);
  delay(1000);
  servo.write(60);
  delay(300);
  servo.write(40);
  delay(300);
  servo.write(20);
  delay(300);
  servo.write(0);
  butt_free = true;
  Serial.println("Free");

  // Green LED ON, Red LED OFF
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
}
