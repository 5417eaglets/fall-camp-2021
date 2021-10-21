#define Lswitch 14
#define trigPin 12
#define echoPin 11

// —————————————————————————  Motors
int motorLeft[] = {16, 17, 10};
int motorRight[] = {8, 7, 9};

float duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  pinMode(Lswitch, INPUT);

  pinMode(codePin, INPUT);
  
  // Setup motors
  int i;
  for(i = 0; i < 3; i++){
    pinMode(motorLeft[i], OUTPUT);
    pinMode(motorRight[i], OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(codePin));
  /*digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * .034 / 2;

  Serial.println(distance);*/
  
  driveForward(150);
  delay(1000);
  driveBackward(150);
  delay(1000);
  

}

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

void driveBackward(int power){
  driveRightMotorBackward(power);
  driveLeftMotorBackward(power);
}

void driveForward(int power){
  driveRightMotorForward(power);
  driveLeftMotorForward(power);
}
