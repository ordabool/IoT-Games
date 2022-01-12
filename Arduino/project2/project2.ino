/*
  Project 2

  Manipulates LEDs on switch press.
*/

const int SWITCH = 2;
const int GREEN_LED = 3;
const int RED_LED_1 = 4;
const int RED_LED_2 = 5;
const int CYCLE_TIME = 250;
bool steadyLight;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);
  pinMode(SWITCH, INPUT);
  steadyLight = true;
  Serial.begin(9600);
}

void loop() {
  Serial.print("Steady Lights: ");
  Serial.println(steadyLight);
  int switchState = digitalRead(SWITCH);
  if (switchState == HIGH) {
    Serial.println("Pressed!");
    steadyLight = !steadyLight;
    delay(500);
  }
  
  if (steadyLight) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED_1, LOW);
    digitalWrite(RED_LED_2, LOW);
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED_1, LOW);
    digitalWrite(RED_LED_2, HIGH);
    delay(CYCLE_TIME);
    digitalWrite(RED_LED_1, HIGH);
    digitalWrite(RED_LED_2, LOW);
    delay(CYCLE_TIME);
  }
}
