# IRIV Arduino Libraries

Four original Arduino/PlatformIO libraries maintained by dineshpalsingh1989. Each library keeps its own MIT license and version. This repository contains library source, examples and tests. Third-party dependencies are installed separately; gateway firmware and generated binaries are excluded.

| Library | Version | Purpose |
| --- | --- | --- |
| [IRIVIOCHardware](libraries/IRIVIOCHardware/README.md) | 0.1.0-alpha.1 | Configurable Arduino-Pico W5500 Ethernet and bounded LittleFS settings |
| [W5500SecureMqtt](libraries/W5500SecureMqtt/README.md) | 0.1.0-alpha.3 | MQTT over Arduino-Pico lwIP Ethernet with certificate validation |
| [WilcoxonMqtt](libraries/WilcoxonMqtt/README.md) | 0.1.0-alpha.1 | Small MQTT 3.1.1 client for plain or TLS Arduino connections; replaces PubSubClient |
| [Wilcoxon883MRTU](libraries/Wilcoxon883MRTU/README.md) | 0.1.0-beta.4 | Wilcoxon 883M Modbus RTU client and optional Modbus TCP register server |

All four are experimental. Hardware, real sensor, PLC and broker validation remain pending. The Wilcoxon examples target ESP32; the source also includes RP2350 support used by the parent gateway, whose standalone examples need separate validation. See each library's limitations before use.

## Install

For PlatformIO, copy the required directory from `libraries/` into your project's `lib/` directory. For Arduino IDE, copy it into your sketchbook's `libraries/` directory. Copy individual library folders, rather than this entire repository as one library.

- IRIVIOCHardware requires Arduino-Pico and ArduinoJson 6.
- W5500SecureMqtt requires Arduino-Pico's W5500lwIP/BearSSL support and WilcoxonMqtt.
- WilcoxonMqtt has no dependencies beyond the Arduino `Client` interface. Its IRIV example also requires IRIVIOCHardware and ArduinoJson 6.
- Wilcoxon883MRTU has no third-party Modbus dependency. Its supplied examples target the ESP32 Arduino core.

Third-party cores and packages retain their own licenses. Do not copy dependency caches into this repository. Configure Wi-Fi, MQTT credentials and trust anchors locally; the secure MQTT example ships with an empty CA placeholder and will not connect until configured.

## Checks

Run these commands from this repository's root with the required tools installed:

```sh
python libraries/Wilcoxon883MRTU/tests/run_native.py
python libraries/WilcoxonMqtt/tests/run_native.py
pio run -d libraries/Wilcoxon883MRTU/tests/esp32_compile
pio run -d libraries/Wilcoxon883MRTU/tests/esp32_discovery
pio run -d libraries/Wilcoxon883MRTU/tests/esp32_tcp
pio run -d libraries/W5500SecureMqtt/tests/iriv_compile
```

Native tests need a C++11 compiler. Compile checks need PlatformIO and downloaded board packages. Simulated tests and successful compilation do not establish hardware validation. [The existing MQTT validation record](libraries/W5500SecureMqtt/VALIDATION.md) records checks from the parent workspace.

Obtain the Wilcoxon 883M manual separately before connecting or configuring a sensor; it is not bundled here. Source provenance: [Wilcoxon gateway project](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT), `IRIV IOC/lib/`.
