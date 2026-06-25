#include <ESP32Servo.h>

Servo myservo;  

const int servoPin = 18; 

void setup() {

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  

  myservo.setPeriodHertz(50); 

  myservo.attach(servoPin, 500, 2400); 
}

void loop() {

  for (int pos = 0; pos <= 180; pos += 20) {
    myservo.write(pos);
    delay(5);
  }
  

  for (int pos = 180; pos >= 0; pos -= 20) {
    myservo.write(pos);
    delay(5);
  }
}