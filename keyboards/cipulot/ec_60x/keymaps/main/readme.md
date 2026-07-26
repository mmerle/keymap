# Cipulot EC60X-SE HHKB

Stock-style HHKB layout for the EC60X-SE PCB in an HHKB Pro 3. The keymap uses `LAYOUT_all` because the EC60X supports several physical layouts; unused matrix positions are disabled with `KC_NO`.

## Fn layer

The Fn layer follows the conventional HHKB arrangement for function keys, navigation, media and keypad controls. Additional controls are:

- Fn+Esc: enter the bootloader.
- Fn+Z: toggle RGB lighting.
- Fn+X: select the next RGB mode.
- Fn+C/Fn+V: decrease/increase RGB brightness.

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
