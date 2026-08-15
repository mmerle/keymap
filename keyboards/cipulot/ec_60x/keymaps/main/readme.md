# Cipulot EC60X-SE HHKB

EC60X-SE PCB in an HHKB Pro 3.

## VIA

VIA is compiled into the QMK firmware for calibration and EC settings. Enter the bootloader with the keymap's `QK_BOOT` key before flashing so VIA reloads the newly compiled map.

## Build

```sh
make hhkb
```

## Flash

```sh
make flash-hhkb
```

This target flashes STM32 sector 0 and sectors 2 onward separately, leaving the sector 1 EEPROM untouched. This preserves EC calibration and RGB settings. Do not substitute a direct `qmk flash` command.

Load `via/ec_60x-2026-07-23.json` in VIA because the current live definition expects a board-variant command that upstream QMK does not implement.
