// Solar Tracker using Arduino - by saikumar2510
#include <Servo.h>

#define LDR1 A0
#define LDR2 A1
#define ERROR 10
#define SERVO_PIN 11
#define DELAY 80

Servo tracker;
int Spoint = 90;

void setup() {
  tracker.attach(SERVO_PIN);
  tracker.write(90);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);
  
  int diff = ldr1 - ldr2;
  
  if (abs(diff) <= ERROR) {
    // Do nothing - light is balanced
  } 
  else if (ldr1 > ldr2) {
    Spoint--;
    if (Spoint < 0) Spoint = 0;
  } 
  else {
    Spoint++;
    if (Spoint > 180) Spoint = 180;
  }
  
  tracker.write(Spoint);
  
  Serial.print("LDR1: ");
  Serial.print(ldr1);
  Serial.print(" | LDR2: ");
  Serial.println(ldr2);
  
  delay(DELAY);
}
