.DEFAULT_GOAL := help

QMK ?= qmk

.PHONY: help setup all planck hhkb flash-planck flash-hhkb

help:
	@printf '%s\n' \
		'Usage:' \
		'  make setup          Configure this repository as QMK userspace' \
		'  make all            Build all configured keyboards' \
		'  make planck         Build the Planck keymap' \
		'  make hhkb           Build the EC60X-SE keymap' \
		'  make flash-planck   Build and flash the Planck' \
		'  make flash-hhkb     Build and flash the EC60X-SE'

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

flash-hhkb:
	$(QMK) flash -kb cipulot/ec_60x -km main
