#include <Servo.h>

/*
Robot has five states
State 1: Break Over, waiting for phone next to user (Alarm sounding)
State 2: Running Away, robot moves 15 feet from user and maintains that distance for 25 minutes (webcam and IR sensors in use)
State 3: Near Collision, robot turns to avoid object in the way
State 4: Return Phone, approach user and wait until phone is no longer sensed
State 5: Break time, 5 minute timer next to user
*/
int machineState = 1;

// Three IR sensors to gather information. Mini is inside the box and left and right are for object collision
// Variables are for the pins being accessed
int sensorMini = A0; 
int sensorLeft = 
int sensorRight = 

// Readings from each of the IR sensors, initialized to zero
int irReadingMini = 0;
int irReadingLeft = 0;
int irReadingRight = 0;

// Motors for moving
Servo leftMotor;
Servo rightMotor;

void setup() {
  Serial.begin(9600); // start serial monitor (top right magnifying glass icon)
  pinMode(sensorMini, INPUT); // initialize IR sensor Mini
  pinMode(sensorLeft, INPUT); // initialize IR sensor Left
  pinMode(sensorRight, INPUT); // initialize IR sensor Right
  leftMotor.attach(10); // Attaches left motor to correct pin
  rightMotor.attach(11); // Attaches right motor to correct pin
}

Serial.print("State: ");
Serial.println(state);   //show current state
}  

/*
void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  turretServo.attach(8);
  Serial.begin(9600);
}
*/



void loop() {

  if (machineState == 1) {
    if(phoneSensed()){machineState = 2;}
    else{
      //MAKE CODE FOR SOUNDING ALARM
      delay(500);
    }
  }
  
  else if(machineState == 2){
    if(irReading < 220){
      machineState = 1;
      for(int i = 0; i < 8; i){
        irReading = analogRead(A0);
        turretCommand=turretCommand+commandStep*5*sweepDirection;
        if(turretCommand <= 0){sweepDirection=1;}
        if(turretCommand >= 2000){sweepDirection=-1;}
        turretServo.writeMicroseconds(turretCommand);
        if(irReading >= 220){machineState = 0; break;}
        if(turretCommand <= 1080 && turretCommand >= 1000){i++;}
        Serial.print(turretCommand);Serial.print(" ");Serial.println(irReading);
        delay(30);
      }
      
        }
  }
  if(machineState == 1){
  turretCommand=turretCommand+commandStep*sweepDirection;
  if(turretCommand<=0){sweepDirection=1;}
  if(turretCommand>=2000){sweepDirection=-1;}
  turretServo.writeMicroseconds(turretCommand);
  } else if(machineState == 0){
      tone(6,500);
      delay(500);
      noTone(6);
      delay(500);
  }
    irReading=analogRead(A0);
    Serial.print(turretCommand);Serial.print(" ");Serial.println(irReading);



    delay(30);
    digitalWrite(7,LOW);

}

bool phoneSensed() {
  irReadingMini = analogRead(sensorMini); // read analog value from IR sensor
  if(irReadingMini < 100){
    return true;
  } else {
    return false;
  }
