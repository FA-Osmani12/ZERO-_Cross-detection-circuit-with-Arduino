volatile bool zeroCrossDetected = false;
volatile int zeroCrossCount = 0;

void setup() {
  pinMode(13, OUTPUT);                // Onboard LED
  pinMode(2, INPUT_PULLUP);          // Zero cross input
  attachInterrupt(digitalPinToInterrupt(2), zeroCrossISR, FALLING);
  
  Serial.begin(9600);                 // Start Serial Monitor
}

void loop() {
  if (zeroCrossDetected) {
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);

    Serial.print("Zero Cross Count: ");
    Serial.println(zeroCrossCount);

    zeroCrossDetected = false;
  }
}

void zeroCrossISR() {
  zeroCrossDetected = true;
  zeroCrossCount++;
}
