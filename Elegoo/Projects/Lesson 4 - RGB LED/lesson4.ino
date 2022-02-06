#define RED 3
#define GREEN 5
#define BLUE 6
#define delayTime 10

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void loop() {
    cycleColors(RED, GREEN);
    cycleColors(GREEN, BLUE);
    cycleColors(BLUE, RED);
}

void cycleColors(int decreseColor, int increaseColor) {
    int currenColorValue = 255;
    int nextColorValue = 0;
    for(int i = 0; i < 255; i += 1) {
        currenColorValue -= 1;
        nextColorValue += 1;
        analogWrite(decreseColor, currenColorValue);
        analogWrite(increaseColor, nextColorValue);
        delay(delayTime);
    }
}