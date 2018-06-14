#include <BoltIoT-Arduino-Helper.h>
# define left_motor1    6
# define left_motor2    7
# define right_motor1   8
# define right_motor2   9
# define sensor         3
String command = "";
int delay_time = 250;

String check() {
  int sensor_value = digitalRead(sensor);
  Serial.println(sensor_value);
  Serial.println(command);
  if ((sensor_value == 0) && (command == "FORWARD")) {
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  command = "";
  }
  return "STOP";
}

String forward(String *data) {
  command = "FORWARD";
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  return "Success:Forward";
}

String backward(String *data) {
  command = "BACKWARD";
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  return "Success:Backward";
}

String right(String *data) {
  command = "RIGHT";
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Left";
}

String left(String *data) {
  command = "LEFT";
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
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
