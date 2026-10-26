# IRIV 883M Firmware

**Wilcoxon 883M vibration sensor gateway for the Cytron IRIV IO Controller.**

Read sensor data over Modbus RTU and make it available through Ethernet, Modbus TCP, MQTT and a browser dashboard.

[Download main release](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/latest) | [Report a problem](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/issues) | [Source project](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT)

![Simplified Cytron IRIV IO Controller front panel and gateway connections](docs/images/iriv-io-controller.svg)

*Controller illustration, not a photograph or a wiring substitute. Check your unit's terminal labels and the board and sensor manuals before connecting equipment.*

## What the gateway provides

| Feature | Purpose |
| --- | --- |
| Modbus RTU | Read the Wilcoxon 883M over RS485 |
| Modbus TCP | Expose cached sensor readings to network clients |
| MQTT | Publish sensor information to a broker |
| Browser dashboard | View sensor status, vibration metrics and trends |
| Capture controls | Start and inspect sensor captures |
| Device settings | Configure network, sensor and integration settings |
| Manual firmware upload | Install a compatible BIN image through the gateway |

## Dashboard preview

![Gateway dashboard with simulated readings](docs/images/dashboard-demo.png)

*Shared gateway dashboard rendered by the ESP32 hardware-free demo with simulated readings. This illustrates the interface; it is not a screenshot from the IRIV controller and does not establish hardware validation.*

## Download the firmware

This repository distributes the **main firmware release** for the **Cytron IRIV IO Controller (RP2350 + W5500)** and **Wilcoxon 883M** sensor.

| Download | When to use it |
| --- | --- |
| [IRIV-883M-beta3.uf2](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/IRIV-883M-beta3.uf2) | Install through the board's USB bootloader |
| [IRIV-883M-beta3.bin](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/IRIV-883M-beta3.bin) | Upload through an existing compatible gateway |
| [SHA256SUMS-beta3.txt](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/SHA256SUMS-beta3.txt) | Verify downloaded firmware files |

The release is designated as the main release. The unchanged binaries, filenames and release tag retain the internal build identifier `4.10.0-beta.3`.

## Before installation

- Confirm the controller and sensor match this firmware. ILA210 and ESP32 boards require their own images.
- Back up important gateway settings.
- Use the board's documented power supply, USB connection and bootloader procedure.
- Review the [883M wiring guide](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT/blob/main/docs/wiring.md) and the bundled sensor manual in the source project.

## Install using USB

1. Download the UF2 image and checksum file above.
2. Verify the downloaded file's SHA-256 checksum.
3. Follow the Cytron board documentation to enter USB bootloader mode.
4. Copy the `.uf2` image to the board's bootloader volume and keep power connected during installation.
5. Allow the controller to restart, then reconnect to the gateway and check its firmware version and settings.

## Update an existing gateway

1. Download the BIN image and verify its checksum.
2. Open the existing compatible gateway in your browser.
3. Open its Device Diagnostics firmware upload control and select the `.bin` file.
4. Wait for installation and restart to finish while keeping power connected.
5. Reopen the gateway and check the firmware version, sensor status and saved settings.

## Verify a download on Windows

From PowerShell in the download folder:

```powershell
Get-FileHash .\IRIV-883M-beta3.uf2 -Algorithm SHA256
Get-FileHash .\IRIV-883M-beta3.bin -Algorithm SHA256
```

Compare each hash with the matching filename in `SHA256SUMS-beta3.txt`.

## First connection

Connect Ethernet to a network with DHCP and open the controller's assigned address in a browser. Without DHCP, the project's documented fallback address is `192.168.4.1`; use a compatible local network configuration to reach it.

Configure the sensor connection and your Modbus TCP or MQTT integration in the gateway settings. Use plain MQTT on a trusted network or through a local broker: MQTT over TLS is not supported for bench use in the current IRIV project guidance.

## Build and validation status

The supplied files are existing prepared binaries, verified against their SHA-256 checksums. They were not rebuilt for this repository publication.

Hardware validation remains pending. The watchdog is disabled in this build, so a hang may require a manual reset or power cycle. Compilation and simulated browser tests do not establish real controller behavior. Boot, I/O, sensor communication, networking, settings persistence and update recovery still require hardware verification.

## Help and source code

For an issue, include the controller model, firmware version shown by the device, installation method, symptoms and relevant diagnostics. Remove credentials and other private information before sharing logs.

- [Open an issue](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/issues)
- [Gateway source repository](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT)
- [IRIV project guide](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT/tree/main/IRIV%20IOC)
