#include <Arduino.h>

constexpr int ADC_PIN = 0;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
}

void loop() {
  int voltage = analogReadMilliVolts(ADC_PIN);

  Serial.println(voltage);

  delay(10);
}
