#include <LiquidCrystal.h>
#define trigPin 10
#define echoPin 13

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    lcd.print("Out of range");
    delay(500);
  }
  else {
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
