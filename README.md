# ESP32-C3 Lab

Hands-on embedded development experiments using ESP32-C3 SuperMini, Arduino, and PlatformIO.

## Labs

| # | Experiment | Topics |
|---|---|---|
| 001 | [Voltage Divider & ADC](docs/labs/001-voltage-divider.md) | GPIO0, voltage divider, ADC measurements |
| 002 | [Capacitor & ADC Stability](docs/labs/002-capacitor-adc-stability.md) | RC filtering, ADC noise, statistics, hardware debugging |

## Hardware

- ESP32-C3 SuperMini
- Breadboard and basic electronic components
- Multimeter

## Development

- VS Code + PlatformIO
- Arduino framework

## Running a lab

Each lab has its own source directory under `src/` and a matching PlatformIO environment:

| Environment | Source |
|---|---|
| `lab001` | [Voltage Divider & ADC](src/lab001-voltage-divider/main.cpp) |
| `lab002` | [Capacitor & ADC Stability](src/lab002-adc-stability/main.cpp) |

Select the lab under **PlatformIO → Project Tasks**, or use the terminal:

```sh
pio run -e lab002
pio run -e lab002 -t upload
pio device monitor -e lab002
```

Replace `lab002` with the desired environment. The default environment is `lab002`.

Stop the serial monitor before uploading. When switching labs, regenerate the compilation database for clangd:

```sh
pio run -e lab002 -t compiledb
```

Restart clangd if needed. The existing toolchain configuration is machine-specific.

For each new lab, create a source directory containing its own `main.cpp`, add an environment with a matching `build_src_filter`, and update the lab index. Keep completed lab sources intact.
