int ledPin = 13;
int interruptPin = 2;
int state = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() { digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}