# Keyboard keymaps

QMK keymaps for two keyboards:

- Planck Rev 6 Drop: `planck/rev6_drop`
- Cipulot EC60X-SE in an HHKB Pro 3: `cipulot/ec_60x`

The repository is a [QMK external userspace](https://docs.qmk.fm/newbs_external_userspace). Each keyboard has an independent `main` keymap compiled into QMK firmware.

## Setup

Install and configure a current QMK checkout, then register this repository as the userspace overlay:

```sh
make setup
```

## Build

```sh
make          # List commands
make all      # Build both keyboards
make planck   # Build only the Planck
make hhkb     # Build only the EC60X-SE
```

## Flash

```sh
make flash-planck
make flash-hhkb
```

The EC60X-SE keymap includes VIA support for calibration and EC settings. Entering the bootloader with the keymap's `QK_BOOT` key invalidates only VIA's dynamic map; after flashing, VIA reloads the compiled `keymap.c` and the configured physical layout.

Use `make flash-hhkb`, not a direct `qmk flash` command. The target flashes STM32 sector 0 and sectors 2 onward separately, leaving the sector 1 wear-leveling EEPROM untouched. This preserves EC calibration and RGB settings.

## VIA

The current live EC60X definition queries board-variant value `245`, which upstream QMK does not implement. In VIA, enable the Design tab and load `via/ec_60x-2026-07-23.json` before authorizing the keyboard. `make via-hhkb` reveals the file in Finder.

The previous manufacturer firmware remains in `bins/ec_60x_60x_se_via.bin` as a recovery asset.
