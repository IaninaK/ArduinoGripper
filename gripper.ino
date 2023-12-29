#include <Servo.h>


int sensorPin = A0; // pin for potentiometer
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;
int ledPin = 13; // pin 4 LED
int sensorValue = 0; // value from sensor
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

int deg0 = 0;
int deg1 = 0;
int deg2 = 0;
int deg3 = 0;
int recordButton = 6;

Servo base;
Servo shoulder;
Servo arm;
Servo gripper;

int baseM[] = {}; //base movement
int shoulderM[] = {}; //shoulder movement
int armM[] = {}; //arm movement
int gripperM[] = {}; //gripper movement

void setup() {
  //declare the recordButton
  pinMode(recordButton, INPUT_PULLUP);
  
  base.attach(2);  //base
  shoulder.attach(3); //shoulder
  arm.attach(4); // arm
  gripper.attach(5); // gripper
}

void loop() {
  // read the value from sensor
  sensorValue0 = analogRead(sensorPin);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  
  deg0 = map(sensorValue0, 0, 1023, 0, 180);
  deg1 = map(sensorValue1, 0, 1023, 0, 180);
  deg2 = map(sensorValue2, 0, 1023, 0, 180);
  deg3 = map(sensorValue3, 0, 1023, 0, 180);    
                                                                                                                                               
  base.write(deg0);
  shoulder.write(deg1);
  arm.write(deg2);
  gripper.write(deg3); //pin 2
  
}
