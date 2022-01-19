#define pinA 3
#define pinB 4

int value;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing system");

  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}