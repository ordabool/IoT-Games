/*
  Project 2

  Manipulates LEDs on switch press.
*/

const int SWITCH = 2;
const int GREEN_LED = 3;
const int RED_LED_1 = 4;
const int RED_LED_2 = 5;
const int CYCLE_TIME = 150;
bool steadyLight;
bool isLight1Active = false;
bool isLight2Active = false;

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
    delay(250);
  }
  
  if (steadyLight) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED_1, LOW);
    digitalWrite(RED_LED_2, LOW);
    isLight1Active = false;
    isLight2Active = false;
  } else {
    digitalWrite(GREEN_LED, LOW);
    if (!isLight1Active) {
      digitalWrite(RED_LED_1, HIGH);
      digitalWrite(RED_LED_2, LOW);
      isLight1Active = true;
      isLight2Active = false;
    } else {
      digitalWrite(RED_LED_1, LOW);
      digitalWrite(RED_LED_2, HIGH);
      isLight1Active = false;
      isLight2Active = false;
    }
    delay(CYCLE_TIME);
  }
}
