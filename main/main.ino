#include <Servo.h>

#define pinA 2
#define pinB 4
#define pinP 13

int value = 0;

int value_A;
int value_B;

int pressed = 0;
char flag;
Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing system");
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinP, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), logRotation,FALLING);
  servo.attach(9);
}

void loop() {
    if (flag != 0) {
      if (flag == 1){
        if (value != 180){
          value = value + 10;
          servo.write(value);
        }
        Serial.println(value);
        
      } else {
        if (value != 0){
          value = value - 10;
          servo.write(value);
        }
        Serial.println(value);
      }
      flag = 0;
    }
    pressed = digitalRead(pinP);
    if (pressed != 0) {
      if (value != 0) {
        servo.write(0);
      } else {
        servo.write(180);
      }
    }
}

void logRotation(){
    value_A = digitalRead(pinA);
    value_B = digitalRead(pinB);

    if (value_A == value_B) {
      flag = 1;
    } else {
      flag = 2;
    }
}
