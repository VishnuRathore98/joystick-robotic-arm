#include <Servo.h>

// Shoulder servo motor pin
#define shoulder_pin 3
// Arm servo motor pin
#define arm_pin 5
// Wrist servo motor pin
#define wrist_pin 7
// Claw servo motor pin
#define claw_pin 9

Servo shoulder_motor;
Servo arm_motor;
Servo wrist_motor;
Servo claw_motor;

// For left right base shoulder motor
#define joy1X_shoulder_pin A0
// For up down arm motor
#define joy1Y_arm_pin A1
// For left right wrist motor
#define joy2X_wrist_pin A2
// For claw open and close motor
#define joy2Y_claw_pin A3

void setup(){
  Serial.begin(9600);
  shoulder_motor.attach(shoulder_pin);
  arm_motor.attach(arm_pin);
  wrist_motor.attach(wrist_pin);
  claw_motor.attach(claw_pin);
}

void loop(){
  int val1X_shoulder = analogRead(joy1X_shoulder_pin);
  int val1Y_arm = analogRead(joy1Y_arm_pin);
  int val2X_wrist = analogRead(joy2X_wrist_pin);
  int val2Y_claw = analogRead(joy2Y_claw_pin);
  // delay(100);

  val1X_shoulder=map(val1X_shoulder, 0, 1024, 0, 180);
  val1Y_arm=map(val1Y_arm, 0, 1024, 0, 180);
   
  val2X_wrist=map(val2X_wrist, 0, 1024, 0, 180);
  val2Y_claw=map(val2Y_claw, 0, 1024, 0, 180);

//  Serial.print("X: ");
//  Serial.println(val1X_shoulder);
  shoulder_motor.write(val1X_shoulder);

//  Serial.print("Y: ");
//  Serial.println(val1Y_arm);
  arm_motor.write(val1Y_arm);

//  Serial.print("X: ");
//  Serial.println();
  wrist_motor.write(val2X_wrist);

//  Serial.print("Y: ");
//  Serial.println();
  claw_motor.write(val2Y_claw);
}
