//Right motor
int enRb = 2;
int rbForward = 3;
int rbReverse = 4;
int rfForward = 5;
int rfReverse = 6;
int enRf = 7;

//Left motor

int enLb = 8;
int lbForward = 9;
int lbReverse = 10;

int lfForward = 11;
int lfReverse = 12;
int enLf = 13;

int regularSpeed = 255;
int turnSpeed = 125;
int reverseSpeed = 150;

//ldr
int ldr = A7;
int ldrVal = 0;

//LED
int ledPin1 = 16;

int state = 0;
char command;
int ledPin = 14;
int del = 5000;
int delayTurn = 500;

//PIR
int pirPin = A8;

//buzzer
int buzzerPin =15;
int freq=3000;
int duration=5000;

void setup()
{
  Serial.begin(9600);

  pinMode( rbForward, OUTPUT);
  pinMode( rbReverse, OUTPUT);
  pinMode( rfForward, OUTPUT);
  pinMode( rfReverse, OUTPUT);
  pinMode(lbForward, OUTPUT);
  pinMode(lbReverse, OUTPUT);
  pinMode(lfForward, OUTPUT);
  pinMode(lfReverse, OUTPUT);

  pinMode(pirPin, INPUT);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
}

void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        reverse();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stopp();
        break;
    }

  }
  getPirValue();
  getLightIntensity();

}

void setRegularSpeed()
{
  analogWrite(enLb, regularSpeed);
  analogWrite(enRb, regularSpeed);
  analogWrite(enLf, regularSpeed);
  analogWrite(enRf, regularSpeed);
}
void setTurnSpeed()
{
  analogWrite(enLb, turnSpeed);
  analogWrite(enRb, turnSpeed);
  analogWrite(enLf, turnSpeed);
  analogWrite(enRf, turnSpeed);
}
void setReverseSpeed()
{
  analogWrite(enLb, reverseSpeed);
  analogWrite(enRb, reverseSpeed);
  analogWrite(enLf, reverseSpeed);
  analogWrite(enRf, reverseSpeed);
}

void forward()
{
  setRegularSpeed();

  digitalWrite(lbForward, HIGH);
  digitalWrite(rbForward, HIGH);
  digitalWrite(lfForward, HIGH);
  digitalWrite(rfForward, HIGH);

  digitalWrite(lbReverse, LOW);
  digitalWrite(rbReverse, LOW);
  digitalWrite(lfReverse, LOW);
  digitalWrite(rfReverse, LOW);
}

void reverse()
{
  setReverseSpeed();

  digitalWrite(lbReverse, HIGH);
  digitalWrite(rbReverse, HIGH);
  digitalWrite(lfReverse, HIGH);
  digitalWrite(rfReverse, HIGH);

  digitalWrite(lbForward, LOW);
  digitalWrite(rbForward, LOW);
  digitalWrite(lfForward, LOW);
  digitalWrite(rfForward, LOW);
}

void stopp()
{
  setRegularSpeed();

  digitalWrite(lfReverse, LOW);
  digitalWrite(rfReverse, LOW);
  digitalWrite(lbReverse, LOW);
  digitalWrite(rbReverse, LOW);

  digitalWrite(lfForward, LOW);
  digitalWrite(rfForward, LOW);
  digitalWrite(lbForward, LOW);
  digitalWrite(rbForward, LOW);
}

void right()
{
  setTurnSpeed();

  digitalWrite(lbForward, HIGH);
  digitalWrite(rbForward, HIGH);
  digitalWrite(lfForward, HIGH);
  digitalWrite(rfForward, LOW);

  digitalWrite(lbReverse, LOW);
  digitalWrite(rbReverse, LOW);
  digitalWrite(lfReverse, LOW);
  digitalWrite(rfReverse, LOW);
}

void left()
{
  setTurnSpeed();

  digitalWrite(lbForward, HIGH);
  digitalWrite(rbForward, HIGH);
  digitalWrite(lfForward, LOW);
  digitalWrite(rfForward, HIGH);

  digitalWrite(lbReverse, LOW);
  digitalWrite(rbReverse, LOW);
  digitalWrite(lfReverse, LOW);
  digitalWrite(rfReverse, LOW);
}

void getPirValue()
{
  int value = analogRead(pirPin);

  if (value > 400) 
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin,freq,duration);
    Serial.println(value);
  }else{
    Serial.println(value);
    digitalWrite(ledPin, LOW);
  }

}
void getLightIntensity()
{
  ldrVal = analogRead(ldr);
  Serial.println("Intensity of the LDR is =");
  Serial.println(ldrVal);
  if(ldrVal<150){
    digitalWrite(ledPin1, HIGH);
  }
  else{
    digitalWrite(ledPin1, LOW);
  }
}
