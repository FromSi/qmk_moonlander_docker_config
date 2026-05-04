QMK_REPO := git@github.com:zsa/qmk_firmware.git
QMK_BRANCH := firmware25
QMK_DIR := qmk_firmware
KEYBOARD_REV ?= reva
KEYBOARD := zsa/moonlander/$(KEYBOARD_REV)
KEYMAP_KEYBOARD := zsa/moonlander
KEYMAP := qmk_moonlander_docker_config
KEYMAP_DIR := $(QMK_DIR)/keyboards/$(KEYMAP_KEYBOARD)/keymaps/$(KEYMAP)
LEGACY_KEYMAP_DIR := $(QMK_DIR)/keyboards/moonlander/keymaps/$(KEYMAP)
KEYMAP_FILES := config.h i18n.h keymap.c keymap.json rules.mk

.PHONY: setup-qmk
setup-qmk: ## clone QMK firmware when needed
	@if [ ! -d "$(QMK_DIR)/.git" ]; then \
		git clone --depth 1 --recurse-submodules --branch "$(QMK_BRANCH)" "$(QMK_REPO)" "$(QMK_DIR)"; \
	else \
		echo "Using existing $(QMK_DIR)"; \
	fi

.PHONY: sync
sync: setup-qmk ## copy this keymap into the QMK firmware tree
	@rm -rf "$(KEYMAP_DIR)"
	@rm -rf "$(LEGACY_KEYMAP_DIR)"
	@mkdir -p "$(KEYMAP_DIR)"
	@cp $(KEYMAP_FILES) "$(KEYMAP_DIR)/"

.PHONY: build
build: sync ## build the keyboard firmware
	cd "$(QMK_DIR)" && util/docker_build.sh $(KEYBOARD):$(KEYMAP)

.PHONY: flash
flash: sync ## build and flash the keyboard firmware
	cd "$(QMK_DIR)" && util/docker_build.sh $(KEYBOARD):$(KEYMAP):flash

.PHONY: clean
clean: ## remove cloned QMK firmware and local keymap build files
	rm -rf "$(QMK_DIR)"

.PHONY: help
help: ## show available make targets with short descriptions
	@cat $(MAKEFILE_LIST) | grep -e "^[a-zA-Z_\-]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
