#define LASER_PIN 7
#define SENSOR_PIN A0 // LDR connected to analog pin
#define BUZZER_PIN 9
#define LED_PIN 13
#define THRESHOLD 600 // Adjust based on ambient light

void setup() {
    pinMode(LASER_PIN, OUTPUT); // Laser module
    pinMode(BUZZER_PIN, OUTPUT); // Buzzer
    pinMode(LED_PIN, OUTPUT); // LED
    digitalWrite(LASER_PIN, HIGH); // Turn on laser
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN);
    Serial.println(sensorValue); // Debugging
    
    if (sensorValue < THRESHOLD) { // Laser beam interrupted
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Intruder detected!");
    } else {
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_PIN, LOW);
    }
    delay(100);
}
