'''
    LED.py

    This example is a basic introduction the the RPi.GPIO library.
    Here we are blinking an LED on pin number 18.
'''

import RPi.GPIO as GPIO
import time

# PIN Mapping
LED_PIN = 18

# Setups
GPIO.setmode(GPIO.BCM) # referring to the pins by the "Broadcom SOC channel" number
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.output(LED_PIN, GPIO.LOW)

# Main Loop
turn_on = True
                                                                                                                                                              
try:
    while True:
        print("turning-on" if turn_on else "turning-off")
        GPIO.output(LED_PIN, GPIO.HIGH if turn_on else GPIO.LOW)
        time.sleep(0.5)
        turn_on = not turn_on

except KeyboardInterrupt:
    GPIO.output(LED_PIN, GPIO.LOW)
    GPIO.cleanup()