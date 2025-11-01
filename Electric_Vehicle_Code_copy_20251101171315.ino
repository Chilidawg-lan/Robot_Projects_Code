const int PWMA = 3;
const int AI1 = 4;
const int AI2 = 5;
const int buttonPin = 6;

bool motorOn = false; // Start with motor OFF

void setup() {
  Serial.begin(9600);
  
  // Motor control pins
  pinMode(PWMA, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  
  // Button with internal pull-up (connects to GND when pressed)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Start with motor OFF
  stopMotor();
  Serial.println("System Ready. Press button to toggle motor.");
}

void loop() {
  // Read button (LOW when pressed, HIGH when not pressed)
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Simple debounce delay
    if (digitalRead(buttonPin) == LOW) { // Confirm button is still pressed
      motorOn = !motorOn; // Toggle state
      
      if (motorOn) {
        startMotor();
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
}

void startMotor() {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  analogWrite(PWMA, 250);
  delay(4000);
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  analogWrite(PWMA, 0);
}

void stopMotor() {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  analogWrite(PWMA, 0);
}