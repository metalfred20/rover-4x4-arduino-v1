#include <AFMotor.h>

char command; //char from BT
int vel;//velocidad

//pin motors
AF_DCMotor MDD(1);
AF_DCMotor MDI(2);
AF_DCMotor MTD(3);
AF_DCMotor MTI(4);


void setup()
{
  Serial1.begin(38400); //BT connected to serial 1
  const int buzzer = 15; //pin for buzzer
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop(){
  if(Serial1.available >()0){
    command = Serial1.read();
    Stop();//start with motors stopped
    switch(command){
      case 'F': //F,B,L,R. Directionals,
      forward();
      break;
      case 'B':
      back();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
      case '1':
      vel=25; //velocity for the motors
      break;
      case '2':
      vel=50;
      break;
      case '3':
      vel=75;
      break;
      case '4':
      vel=100;
      case '5':
      vel=128;
      break;
      case '6':
      vel=140;
      break;
      case '7':
      vel=190;
      break;
      case '8':
      vel=230;
      break;
      case '9':
      vel=250;
      break;
      case 'q':
      vel=255;
      break;
      case 'V'://Horn
      digitalWrite(15, HIGH);
      break;
      case 'v':
      digitalWrite(15, LOW);
      break; 
    }
  }
}
void forward()
{
  MDD.setSpeed(vel);
  MDD.run(FORWARD);
  MDI.setSpeed(vel);
  MDI.run(FORWARD);
  MTD.setSpeed(vel);
  MTD.run(FORWARD);
  MTI.setSpeed(vel);
  MTI.run(FORWARD);
}
void back()
{
  MDD.setSpeed(vel);
  MDD.run(BACKWARD);
  MDI.setSpeed(vel);
  MDI.run(BACKWARD);
  MTD.setSpeed(vel);
  MTD.run(BACKWARD);
  MTI.setSpeed(vel);
  MTI.run(BACKWARD);
}
void left()
{
  MDD.setSpeed(vel);
  MDD.run(FORWARD);
  MDI.setSpeed(vel);
  MDI.run(BACKWARD);
  MTD.setSpeed(vel);
  MTD.run(FORWARD);
  MTI.setSpeed(vel);
  MTI.run(BACKWARD);

}

void right()
{
  MDD.setSpeed(vel);
  MDD.run(BACKWARD);
  MDI.setSpeed(vel);
  MDI.run(FORWARD);
  MTD.setSpeed(vel);
  MTD.run(BACKWARD);
  MTI.setSpeed(vel);
  MTI.run(FORWARD);

}

void Stop()
{
  MDD.setSpeed(0);
  MDD.run(RELEASE);
  MDI.setSpeed(0);
  MDI.run(RELEASE);
  MTD.setSpeed(0);
  MTD.run(RELEASE);
  MTI.setSpeed(0);
  MTI.run(RELEASE);
}



