#define ONBOARD_LED  2

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ONBOARD_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ONBOARD_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                        // wait for a second
  digitalWrite(ONBOARD_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                        // wait for a second
}
