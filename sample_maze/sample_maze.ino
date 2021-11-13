#define blueLED 2
#define redLED 21
#define Lswitch 14
#define trigPin 11
#define echoPin 12

// —————————————————————————  Motor Pins
int motorLeft[] = {16, 17, 10};
int motorRight[] = {8, 7, 9};

// —————————————————————————  Ultrasonic Variables
float duration;
int distance;
unsigned long prevTime = 0;
bool forward = true;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(Lswitch, INPUT);
  
  // Setup motors
  int i;
  for(i = 0; i < 3; i++){
    pinMode(motorLeft[i], OUTPUT);
    pinMode(motorRight[i], OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  distance = runUltraSonicSensor();
  if(digitalRead(Lswitch) == LOW && distance > 5 && counter < 2){
    driveForward(200); 
  }
  else if(distance <5 && counter == 0){
     turnRight();
     counter++; 
  }
  else if(distance <5 && counter == 1){
    turnLeft();
    counter++; // add 1 to our counter variable so that counter = 2
  }
  else if(counter >= 2){
    driveForward(0);
  }

  */
  
}

// ------------------------------ Camper drive functions

void driveForward(int power){
  driveLeftMotorForward(power);
  driveRightMotorForward(power);
}

void driveBackward(int power){
  driveLeftMotorBackward(power);
  driveRightMotorBackward(power);
}

void turnRight(){
  driveLeftMotorForward(150);
  driveRightMotorForward(0);
  delay(750);
}

void turnLeft(){
  driveRightMotorForward(150);
  driveLeftMotorForward(0);
  delay(750);
}

// ------------------------------ Pre-made drive functions
void driveLeftMotorForward(int power){
  analogWrite(motorLeft[2], power);
  digitalWrite(motorLeft[0], LOW);
  digitalWrite(motorLeft[1], HIGH);
}

void driveRightMotorForward(int power){
  analogWrite(motorRight[2], power);
  digitalWrite(motorRight[0], LOW);
  digitalWrite(motorRight[1], HIGH);
}

void driveLeftMotorBackward(int power){
  analogWrite(motorLeft[2], power);
  digitalWrite(motorLeft[0], HIGH);
  digitalWrite(motorLeft[1], LOW);
}

void driveRightMotorBackward(int power){
  analogWrite(motorRight[2], power);
  digitalWrite(motorRight[0], HIGH);
  digitalWrite(motorRight[1], LOW); 
}

int runUltraSonicSensor(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * .034 / 2;
  //Serial.println(distance);

  if(millis() - prevTime >= 1000){
    forward = !forward;
    prevTime = millis();
  }
  if(forward){
    driveForward(150);
  }else{
    driveBackward(150);
  }

  return distance;
}
