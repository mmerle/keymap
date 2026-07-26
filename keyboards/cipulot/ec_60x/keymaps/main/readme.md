# Cipulot EC60X-SE HHKB

HHKB layout for the EC60X-SE PCB in an HHKB Pro 3. The keymap uses `LAYOUT_all` because the EC60X supports several physical layouts; unused matrix positions are disabled with `KC_NO`.

The Control position sends Escape when tapped and Right Control when held.

## Fn layer

The Fn layer provides function keys and navigation controls:

- Fn+grave (the top-left key): enter the bootloader.
- Fn+H/J/K/L: left/down/up/right.
- Fn+N/M/comma/period: Home/Page Down/Page Up/End.

## VIA

VIA support is compiled into this keymap. Changes made in VIA are stored in EEPROM. Resetting EEPROM restores the layout defined in `keymap.c`.

Select the HHKB bottom-row option in VIA so its layout view matches the physical keyboard.

## Build

```sh
make hhkb
```

## Flash

```sh
make flash-hhkb
```
