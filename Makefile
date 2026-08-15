.DEFAULT_GOAL := help

QMK ?= qmk
DFU_UTIL ?= dfu-util

HHKB_VIA_DEFINITION := $(CURDIR)/via/ec_60x-2026-07-23.json
HHKB_FIRMWARE := $(CURDIR)/cipulot_ec_60x_main.bin
HHKB_SECTOR_0 := $(CURDIR)/cipulot_ec_60x_main_sector_0.bin
HHKB_SECTOR_2_ONWARD := $(CURDIR)/cipulot_ec_60x_main_sector_2_onward.bin

.PHONY: help setup all planck hhkb flash-planck flash-hhkb via-hhkb

help:
	@printf '%s\n' \
		'Usage:' \
		'  make setup          Configure this repository as QMK userspace' \
		'  make all            Build all configured keyboards' \
		'  make planck         Build the Planck keymap' \
		'  make hhkb           Build the EC60X-SE keymap' \
		'  make flash-planck   Build and flash the Planck' \
		'  make flash-hhkb     Build and flash the EC60X-SE' \
		'  make via-hhkb       Reveal the compatible EC60X-SE VIA definition'

setup:
	$(QMK) config user.overlay_dir="$(CURDIR)"

all:
	$(QMK) userspace-compile

planck:
	$(QMK) compile -kb planck/rev6_drop -km main

hhkb:
	$(QMK) compile -kb cipulot/ec_60x -km main

flash-planck:
	$(QMK) flash -kb planck/rev6_drop -km main

flash-hhkb: hhkb
	dd if="$(HHKB_FIRMWARE)" of="$(HHKB_SECTOR_0)" bs=16384 count=1
	dd if="$(HHKB_FIRMWARE)" of="$(HHKB_SECTOR_2_ONWARD)" bs=32768 skip=1
	$(DFU_UTIL) -a 0 -d 0483:df11 -s 0x08000000 -D "$(HHKB_SECTOR_0)"
	$(DFU_UTIL) -a 0 -d 0483:df11 -s 0x08008000:leave -D "$(HHKB_SECTOR_2_ONWARD)"

via-hhkb:
	open -R "$(HHKB_VIA_DEFINITION)"
