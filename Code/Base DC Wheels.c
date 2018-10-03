
int forward = 0;
const int speed = 255;
unsigned long motorStartMillis;
unsigned long motorRunMillis = 180000;
const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 9;    // H-bridge enable pin
// nikhil chut
void setup() {
    Serial.begin(9600);
    pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    analogWrite(enablePin, speed);
}

void loop() {
  int i = 1;
  if (i == 1){
    motorStartMillis = millis();
    i = 2;
  }
  if (forward == 0){
    if (millis() - motorStartMillis <= motorRunMillis) {
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
      forward = 0;
    }else{
      digitalWrite(enablePin,LOW);
      forward = 1
      delay(3000);
      motorStartMillis = millis();
    }
  }else if(forward == 1){
    analogWrite(enablePin, speed);
    if (millis() - motorStartMillis <= motorRunMillis) {
      digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge high
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge low
      forward = 1;
    }else{
      digitalWrite(enablePin,LOW);
      forward = 2;
    }
  }
}
