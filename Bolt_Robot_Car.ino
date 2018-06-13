#include <BoltIoT-Arduino-Helper.h>
# define left_motor1    6
# define left_motor2    7
# define right_motor1   8
# define right_motor2   9
# define sensor         3

String check() {
  int sensor_value = digitalRead(sensor);
  Serial.println(sensor_value);
  if (sensor_value == 0) {
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  }
  return "STOP";
}

String forward(String *data) {
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  check();
  return "Success:Forward";
}

String backward(String *data) {
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  return "Success:Backward";
}

String right(String *data) {
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  return "Success:Left";
}

String left(String *data) {
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  return "Success:Right";
}

String stopcar(String *data) {
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Stop";
}

void setup() {
  // put your setup code here, to run once:
  pinMode(left_motor1,OUTPUT);
  pinMode(left_motor2,OUTPUT);
  pinMode(right_motor1,OUTPUT);
  pinMode(right_motor2,OUTPUT);
  pinMode(sensor,INPUT);
  boltiot.begin(Serial);
  Serial.begin(9600);
  boltiot.setCommandString("FORWARD",forward);
  boltiot.setCommandString("BACKWARD",backward);
  boltiot.setCommandString("LEFT",left);
  boltiot.setCommandString("RIGHT",right);
  boltiot.setCommandString("STOP",stopcar);
}

void loop() {
  // put your main code here, to run repeatedly:
  boltiot.handleCommand();
  check();
}
