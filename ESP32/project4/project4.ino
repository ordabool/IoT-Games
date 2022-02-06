#define RED 25
#define GREEN 33
#define BLUE 32
#define RED_PWM_CHANNEL 0
#define GREEN_PWM_CHANNEL 1
#define BLUE_PWM_CHANNEL 2
#define RESOLUTION 8
#define FREQUENCY 5000
#define DELAY_TIME 10

void setup() {
    ledcSetup(RED_PWM_CHANNEL, FREQUENCY, RESOLUTION);
    ledcSetup(GREEN_PWM_CHANNEL, FREQUENCY, RESOLUTION);
    ledcSetup(BLUE_PWM_CHANNEL, FREQUENCY, RESOLUTION);
    ledcAttachPin(RED, RED_PWM_CHANNEL);
    ledcAttachPin(GREEN, GREEN_PWM_CHANNEL);
    ledcAttachPin(BLUE, BLUE_PWM_CHANNEL);
}

void loop() {
    cycleColors(RED_PWM_CHANNEL, GREEN_PWM_CHANNEL);
    cycleColors(GREEN_PWM_CHANNEL, BLUE_PWM_CHANNEL);
    cycleColors(BLUE_PWM_CHANNEL, RED_PWM_CHANNEL);
}

void cycleColors(int decreseColor, int increaseColor) {
    int currenColorValue = 255;
    int nextColorValue = 0;
    for(int i = 0; i < 255; i += 1) {
        currenColorValue -= 1;
        nextColorValue += 1;
        ledcWrite(decreseColor, currenColorValue);
        ledcWrite(increaseColor, nextColorValue);
        delay(DELAY_TIME);
    }
}

// More info @ https://randomnerdtutorials.com/esp32-pwm-arduino-ide/