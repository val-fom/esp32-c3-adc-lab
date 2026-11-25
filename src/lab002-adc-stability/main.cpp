#include <Arduino.h>

constexpr int ADC_PIN = 0;
constexpr int SAMPLE_COUNT = 100;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
}

void loop() {
  int sum = 0;
  double sumSquares = 0;
  int minVoltage;
  int maxVoltage;

  for (int i = 0; i < SAMPLE_COUNT; i++) {
    int voltage = analogReadMilliVolts(ADC_PIN);

    if (i == 0) {
      minVoltage = voltage;
      maxVoltage = voltage;
    } else {
      if (voltage < minVoltage)
        minVoltage = voltage;
      if (voltage > maxVoltage)
        maxVoltage = voltage;
    }

    sum += voltage;
    sumSquares += static_cast<double>(voltage) * voltage;
  }

  int p2p = maxVoltage - minVoltage;

  double average = sum / static_cast<double>(SAMPLE_COUNT);
  double variance = sumSquares / SAMPLE_COUNT - average * average;
  double stddev = sqrt(max(0.0, variance));

  Serial.printf("MIN: %d | MAX: %d | AVG: %.2f | P2P: %d | VAR: %.2f | STD: %.2f mV\n", minVoltage,
                maxVoltage, average, p2p, variance, stddev);

  delay(1000);
}
