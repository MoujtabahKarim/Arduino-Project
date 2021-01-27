
int trigPin = 9;
int echoPin = 10;
int LBack = 4;
int RBack = 7;
int LMotor = 5;
int RMotor = 6;
int pot2 = A1;
int pot1 = A0;

  


//INITIAL SPEED
int lSpeed = 200; 
int rSpeed = 200 ;

char Direction[] = {'N', 'E', 'S', 'W'};


//Current Ticks
int XTicks ; 
int YTicks ;

int currentDirection = 1;

char facing = Direction[currentDirection];

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LBack, OUTPUT);
  pinMode(LBack, OUTPUT);
  pinMode(RMotor, OUTPUT);
  pinMode(LMotor, OUTPUT);
  Serial.begin(9600); 
}

void loop() {   // the loop function runs over and over again forever
//direction = getDirection(direction);   
float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);
  
/*
 float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);

  analogWrite(LMotor, lSpeed);
   analogWrite(RMotor, rSpeed);
   analogWrite(LBack, 0);
   analogWrite(RBack, 0);

   
*/

 followBlackLine(); 
 
Serial.print("L: ");
Serial.println(LSensor);
Serial.print("R: ");
Serial.println(RSensor) ; 


}

boolean OnWhite(int value) {
if(value < 150) {
    return true ; 
  }
  else return false ; 
}

void followBlackLine() {
  float LSensor = analogRead(pot1);
  float RSensor = analogRead(pot2);

  analogWrite(LMotor, lSpeed);
   analogWrite(RMotor, rSpeed);
   analogWrite(LBack, 0);
   analogWrite(RBack, 0);
   
  //goForwards(); 
   if(LSensor < 150 && RSensor > 150) {
    rSpeed = 0 ; 
    lSpeed = lSpeed + 50 ; 
  }
  else if(RSensor < 150 && LSensor > 150) {
    lSpeed = 0;
    rSpeed = rSpeed + 50 ; 
     
  }
    else {
      if(RSensor < 150 && LSensor < 150) {
          lSpeed = 100 ; 
        rSpeed = 100 ;
      }
      if(RSensor > 150 && LSensor > 150) {
        turnLeft(255); 
      }
     
    }
  

  
}

/*char getDirection(char currentDirection){
  char newDirection ; 

  if(x == 'E') {
    newDirection = currentDirection ; 
  }
  
  return newPosition ;
}
*/
int getDistance() {
  long duration, distance;
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

  return distance; 
}

void goForwards(int speed) {
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, 0);
   analogWrite(RBack, 0);
}

void stopMoving() {
  digitalWrite(RBack, LOW);
  digitalWrite(RMotor, LOW);
  digitalWrite(LBack, LOW);
  digitalWrite(LMotor, LOW);
}

void goBackwards(int speed) {
  analogWrite(LMotor, 0);
  analogWrite(RMotor, 0);
  analogWrite(LBack, speed);
  analogWrite(RBack, speed);
}

void turnRight(int speed, int time) {
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   digitalWrite(LBack, LOW);
   analogWrite(RBack, speed);
   delay(time); 
   digitalWrite(LMotor, LOW);
   digitalWrite(RMotor, LOW);
   digitalWrite(RBack, LOW);
}

boolean itsNotWokringLOL {
  if(LSensor < 150 && RSensor > 150)
}

void turnLeft(int speed, boolean itsNotWokringLOL) {

if(itsNotWorkingLOL) {
  lSpeed = 0 ;
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, speed);
   digitalWrite(RBack, LOW);
   delay(30);
   digitalWrite(RMotor, LOW);
   digitalWrite(LMotor, LOW);
   digitalWrite(LBack, LOW);

} 
 
 /*
   analogWrite(RMotor, speed);
   analogWrite(LBack, speed);
   digitalWrite(RBack, LOW);
   delay(30);
   digitalWrite(RMotor, LOW);
   digitalWrite(LMotor, LOW);
   digitalWrite(LBack, LOW);
*/



 /* 
   analogWrite(LMotor, speed);
   analogWrite(RMotor, speed);
   analogWrite(LBack, speed);
   digitalWrite(RBack, LOW);
   delay(30);
   digitalWrite(RMotor, LOW);
   digitalWrite(LMotor, LOW);
   digitalWrite(LBack, LOW);
   */
  
}






