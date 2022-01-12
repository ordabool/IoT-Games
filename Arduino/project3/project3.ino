/*
  Project 3

  Analog input with Temperature Sensor, Serial Monitor.

  Pins:
  A0 - Temperature Sensor
  2 - Red LED
  3 - Red LED
  4 - Red LED
*/

const int sensorPin = A0;
const float baselineTemp = 20.0; // Temps in celsius - will be used as threshold

void setup() {
    Serial.begin(9600); // Open a serial port

    // Set LED pins as output through a loop, and turn them off
    for (int i = 2; i < 5; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}

void loop() {
    int sensorValue = analogRead(sensorPin);
    Serial.print("Sensor value: ");
    Serial.print(sensorValue);

    // Convert the ADC (Analog Digital Converter) reading to voltage
    // Analog range - 0-1023
    // Voltage range - 0-5
    float voltage = (sensorValue/1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);

    float temperature = (voltage - 0.5) * 100; // We can get this from the Datasheet
    Serial.print(", Degrees C: ");
    Serial.println(temperature);

    if (temperature < baselineTemp) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if (temperature >= baselineTemp+6) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }

    delay(1); // Put a small delay to avoid garbage data from the sensor trying to read too fast
}