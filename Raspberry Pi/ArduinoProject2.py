'''
    Arduino Project 2

    This project will try to recreate the 2nd project in the Arduino Starter Kit,
    but this time on the Raspberry Pi.
    For this we will need 3 OUTPUT pins for the LEDs, and one INPUT for the switch.
'''

import RPi.GPIO as GPIO
import time

# Pin declarations
SWITCH = 23
GREEN_LED = 14
RED_LED_1 = 15
RED_LED_2 = 18

# Some variables for the script
CYCLE_TIME = 0.15
steadyLight = True
isLight1Active = False
isLight2Active = False

# Setups
GPIO.setmode(GPIO.BCM) # referring to the pins by the "Broadcom SOC channel" number
GPIO.setup(GREEN_LED, GPIO.OUT)
GPIO.setup(RED_LED_1, GPIO.OUT)
GPIO.setup(RED_LED_2, GPIO.OUT)
GPIO.setup(SWITCH, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.output(GREEN_LED, GPIO.LOW)
GPIO.output(RED_LED_1, GPIO.LOW)
GPIO.output(RED_LED_2, GPIO.LOW)

# Run Loop
try:
    while True:
        print(f'Steady Lights: {steadyLight}');
        if GPIO.input(SWITCH) == GPIO.HIGH:
            print('Pressed!');
            steadyLight = not steadyLight
            time.sleep(0.25)

        if steadyLight:
            GPIO.output(GREEN_LED, GPIO.HIGH)
            GPIO.output(RED_LED_1, GPIO.LOW)
            GPIO.output(RED_LED_2, GPIO.LOW)
            isLight1Active = False
            isLight2Active = False
        else:
            GPIO.output(GREEN_LED, GPIO.LOW)
            GPIO.output(RED_LED_1, GPIO.HIGH if not isLight2Active else GPIO.LOW)
            isLight1Active = not isLight1Active
            GPIO.output(RED_LED_2, GPIO.HIGH if not isLight1Active else GPIO.LOW)
            isLight2Active = not isLight2Active
        time.sleep(CYCLE_TIME)

except KeyboardInterrupt:
    GPIO.output(GREEN_LED, GPIO.LOW)
    GPIO.output(RED_LED_1, GPIO.LOW)
    GPIO.output(RED_LED_2, GPIO.LOW)
    GPIO.cleanup()