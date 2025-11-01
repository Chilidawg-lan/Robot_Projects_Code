#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo pulse range (tune if needed for your model)
#define SERVOMIN  150  // 0 degrees
#define SERVOMAX  600  // 180 degrees

// Convert angle (0-180) to pulse length
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

// === CONFIGURE HERE ===
// Change this to test a different servo channel
//0-pinky 
//1- middle and ring and Pointer
//2- Middle and Ring
//4- Thumb
//5 forarm turn
int testChannel = 5; // 0, 1, 2, 4, or 5

void setup() {
  Serial.begin(9600);
  Serial.println("PCA9685 Servo Isolated Test");

  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz for standard servos
  delay(10);

  // Set all servos to neutral/rest first
  int channels[] = {0, 1, 2, 4, 5};
  for (int i = 0; i < 5; i++) {
    pwm.setPWM(channels[i], 0, angleToPulse(90));
  }
  delay(1000);
}

void loop() {
  // Sweep the test servo from 0° → 180° → 0°
  for (int pos = 0; pos <= 180; pos += 5) {
    pwm.setPWM(testChannel, 0, angleToPulse(pos));
    delay(40);
  }

  for (int pos = 180; pos >= 0; pos -= 5) {
    pwm.setPWM(testChannel, 0, angleToPulse(pos));
    delay(40);
  }

  // Return test servo to rest/neutral
  pwm.setPWM(testChannel, 0, angleToPulse(90));
  delay(1000); // Pause before repeating
}
