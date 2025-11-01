const int leftRV = 6; 
const int leftFW = 5; 
const int rightRV = 3; 
const int rightFW = 4; 
const int enableLeftMotor = 9; 
const int enableRightMotor = 10;

const int PWMA = 3;
const int AI1 = 4;
const int AI2 = 5;
const int buttonPin = 6;




bool motorOn = false; // Start with motor OFF

void setup() {
  Serial.begin(9600);

  // Motor control pins


  pinMode(leftRV, OUTPUT);
  pinMode(leftFW, OUTPUT);
  pinMode(rightRV, OUTPUT);
  pinMode(rightFW, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(enableRightMotor, OUTPUT);


  // Button with internal pull-up (connects to GND when pressed)
  pinMode(buttonPin, INPUT_PULLUP);

  // Start with motor OFF
  Stop();
  Serial.println("System Ready. Press button to toggle motor.");
}


void loop() {
  // Read button (LOW when pressed, HIGH when not pressed)
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Simple debounce delay
    if (digitalRead(buttonPin) == LOW) { // Confirm button is still pressed
      motorOn = !motorOn; // Toggle state

      if (motorOn) {

//Type here


        Serial.println("Motor ON");
      } else {
        stopMotor();
        Serial.println("Motor OFF");
      }

      // Wait for button release to avoid rapid toggling
      while (digitalRead(buttonPin) == LOW) {
        delay(10);
      }
    }
  }
  void Fw(unsigned long ) {
  analogWrite(enableLeftMotor, 96);
  analogWrite(enableRightMotor,90); //78
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, HIGH);
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, HIGH);
  delay(1000); 
}

void SFw(unsigned long ){
    analogWrite(enableLeftMotor, 96);
  analogWrite(enableRightMotor,90); //78
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, HIGH);
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, HIGH);
  delay(500); 
}

void L(unsigned long ) {
  analogWrite(enableLeftMotor, 95);
  analogWrite(enableRightMotor, 95); 
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, LOW); 
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, HIGH); 
  delay(800); 
}
void SL(unsigned long ) {
    analogWrite(enableLeftMotor, 100);
  analogWrite(enableRightMotor, 100); 
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, LOW); 
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, HIGH); 
  delay(100); 
}

void R(unsigned long ) {
  analogWrite(enableLeftMotor, 95;// 84.1
  analogWrite(enableRightMotor, 95); //63
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, HIGH); 
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, LOW); 
  delay(700); 
}
void SR(unsigned long) {
   analogWrite(enableLeftMotor, 100);// 84.1
  analogWrite(enableRightMotor, 100); //63
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, HIGH); 
  digitalWrite(rightRV, LOW);
  digitalWrite(rightFW, LOW); 
  delay(100); 
}


void Stop() {
  analogWrite(enableLeftMotor, 0);
  analogWrite(enableRightMotor, 0); 
  digitalWrite(leftRV, LOW); 
  digitalWrite(leftFW, LOW); 
  digitalWrite(rightRV, LOW); 
  digitalWrite(rightFW, LOW); 
}
void U(unsigned long ) {
  analogWrite(enableLeftMotor, 60);
  analogWrite(enableRightMotor, 60);
  digitalWrite(leftRV, LOW);
  digitalWrite(leftFW, HIGH);
  digitalWrite(rightRV, HIGH);
  digitalWrite(rightFW, LOW); 
  delay(1520);
}

}
