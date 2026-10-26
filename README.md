# IRIV 883M Firmware

Firmware downloads for the **Wilcoxon 883M gateway** on the **Cytron IRIV IO Controller (RP2350 + W5500)**.

## Download

Prepared firmware: **4.10.0-beta.3**. [Release and downloads](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/tag/v4.10.0-beta.3).

| File | Use |
| --- | --- |
| [IRIV-883M-beta3.uf2](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/IRIV-883M-beta3.uf2) | USB bootloader installation |
| [IRIV-883M-beta3.bin](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/IRIV-883M-beta3.bin) | Manual upload through the gateway firmware upload control |
| [SHA256SUMS-beta3.txt](https://github.com/dineshpalsingh1989/IRIV-883M-Firmware/releases/download/v4.10.0-beta.3/SHA256SUMS-beta3.txt) | SHA-256 checksums |

## Installation

1. Download the file for your installation method and verify its SHA-256 checksum against the supplied checksum file.
2. Back up important gateway settings and review the board's documented wiring and bootloader procedure.
3. For USB installation, enter the board's USB bootloader mode and copy the `.uf2` file to its bootloader volume. For an existing compatible gateway, use its manual firmware upload control with the `.bin` file.
4. Keep power connected during installation. Reconnect to the gateway and check its firmware version and settings.

This firmware is for the 883M IRIV gateway. Use the correct firmware for your board and sensor.

## Beta status

Hardware validation is pending. The watchdog is disabled in this beta, so a hang may require a manual reset or power cycle. Use plain MQTT on a trusted network or through a local broker; MQTT over TLS is not supported for bench use in the current IRIV project guidance.

These are existing prepared beta.3 binaries verified against their supplied checksums, not a fresh build. Compilation and simulated browser tests do not establish hardware behavior. Boot, I/O, sensor communication, networking, settings persistence and update recovery still require hardware verification.

## Source project

[Wilcoxon 883M gateway source](https://github.com/dineshpalsingh1989/Wilcoxon-883M_RTU-to-TCP-and-MQTT). This repository distributes firmware through GitHub Releases.
