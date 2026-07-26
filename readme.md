# Keyboard keymaps

QMK keymaps for two keyboards:

- Planck Rev 6 Drop: `planck/rev6_drop`
- Cipulot EC60X-SE in an HHKB Pro 3: `cipulot/ec_60x`

The repository is a [QMK external userspace](https://docs.qmk.fm/newbs_external_userspace). Each keyboard has an independent `main` keymap.

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

The EC60X-SE keymap includes VIA support. The map in `keymap.c` is the default restored after an EEPROM reset; changes made in VIA are stored on the keyboard and do not modify this repository.
