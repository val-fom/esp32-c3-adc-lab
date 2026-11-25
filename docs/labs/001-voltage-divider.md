# Lab 001 — Voltage Divider & ADC

**Date:** 2026-11-24  
**Hardware:** ESP32-C3 SuperMini, breadboard, multimeter  
**Setup:** 3.3V → 10kΩ → GPIO0 → ID resistor → GND

![Breadboard setup](../images/lab-001-breadboard.jpg)

| Pull-up | ID resistor | Expected | Measured (ADC) | Raw ADC |
|---|---|---:|---:|---:|
| 10kΩ | 1kΩ | 300 mV | ~300–306 mV | ~408 |
| 10kΩ | 2.2kΩ | 595 mV | ~590–615 mV | ~810 |
| 10kΩ | Disconnected | 3.3 V | Saturated (2915 mV reported) | 4095 |
| Disconnected | 1kΩ | 0 V | ~0–4 mV | ~0–5 |
| Disconnected | Disconnected | Undefined (floating) | Unstable | 0–4095 |

## Findings

- Voltage divider calculations match real measurements.
- Pull-up holds GPIO0 HIGH when the ID resistor is disconnected.
- Without pull-up, a connected ID resistor pulls GPIO0 LOW; without either resistor, GPIO0 floats and readings become unpredictable.
- ADC readings fluctuate slightly; `analogRead()` and `analogReadMilliVolts()` perform separate measurements.
- USB CDC logging works through PlatformIO Serial Monitor.

## Next

**Lab 002:** Add a 100 nF capacitor between GPIO0 and GND. Compare ADC stability before and after.
