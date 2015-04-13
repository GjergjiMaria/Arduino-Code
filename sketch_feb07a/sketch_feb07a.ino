int steeringPower = 12;
int steeringBreak = 9;
int steeringAnalog = 3;

int goPin = 13;
int goBreakPin = 8;
int goAnalog = 11;

int theSpeed = 100;
int incomingByte =0;

void runRC(int input){
  switch(input){
    case 1:
      goForward();
      break;
    case 2:   
      goBackward();
      break;
    case 3: 
      goBreak();
      break;
    case 4:
      goStraight();
      break;
    case 5:
     goRight();
     break;
    case 6:
     goLeft();
     break;
    case 7:
     theSpeed = 125;
     break;
    case 8:
     theSpeed = 65;
     break;
    case 9:
     theSpeed = 255;
     break;
    case 0:
     theSpeed = 200;
     break;
  }

} 

void goForward(){
  //Motor A forward @ theSpeed
  Serial.println("Going Forward");
  digitalWrite(goPin, LOW); //Establishes forward direction of Channel A
  digitalWrite(goBreakPin, LOW);   //Disengage the Brake for Channel A
  analogWrite(goAnalog, theSpeed);   //Spins the motor on Channel A at full speed
}
void goBackward(){
  //Motor A forward @ theSpeed
  Serial.println("Going Backward");
  digitalWrite(goPin, HIGH); //Establishes forward direction of Channel A
  digitalWrite(goBreakPin, LOW);   //Disengage the Brake for Channel A
  analogWrite(goAnalog, theSpeed);   //Spins the motor on Channel A at full speed  
}
void goBreak(){
  // Breaking
  Serial.println("Going To Break");
  digitalWrite(goPin, LOW); //Establishes forward direction of Channel A
  digitalWrite(goBreakPin, HIGH);   //Disengage the Brake for Channel A
  analogWrite(goAnalog, 0);   //Spins the motor on Channel A at full speed
}
void goStraight(){
  Serial.println("Going Straight");
  digitalWrite(steeringPower, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(steeringBreak, HIGH);   //Disengage the Brake for Channel B
  analogWrite(steeringPower, 0);    //Spins the motor on Channel B at half speed
}

void goLeft(){
  // Left Turn
  Serial.println("Going Left");
  digitalWrite(steeringPower, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(steeringBreak, LOW);   //Disengage the Brake for Channel B
  analogWrite(steeringAnalog, theSpeed);    //Spins the motor on Channel B at half speed
  
}
void goRight(){
  // Left Right
  Serial.println("Going Right");
  digitalWrite(steeringPower, LOW);  //Establishes backward direction of Channel B
  digitalWrite(steeringBreak, LOW);   //Disengage the Brake for Channel B
  analogWrite(steeringAnalog, theSpeed);    //Spins the motor on Channel B at half speed  
  
}

void setup() {
  
  Serial.begin(9600);
  Serial.println("Connected");
  //Setup Channel A
  
  pinMode(goPin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(goBreakPin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(steeringBreak, OUTPUT); //Initiates Motor Channel A pin
  pinMode(steeringPower, OUTPUT); //Initiates Motor Channel A pin
  pinMode(4, OUTPUT);
  /*
  pinMode(steeringAnalog, OUTPUT);
  pinMode(goAnalog, OUTPUT);
  */
  
}

void loop() {

        // send data only when you receive data:
        digitalWrite(4,LOW);
        if (Serial.available() > 0) {
                // read the incoming byte:
                digitalWrite(4,HIGH);
                delay(1000);
                incomingByte = Serial.read();
                // say what you got:
                Serial.print("I received a ");
                Serial.print(incomingByte-48);
                Serial.print(" So I am ");
                runRC(incomingByte-48);
        }
}


