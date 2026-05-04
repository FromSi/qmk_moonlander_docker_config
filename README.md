# Moonlander QMK keymap

This setup uses `zsa/qmk_firmware` on the [`firmware25`](https://github.com/zsa/qmk_firmware/tree/firmware25) branch. The default firmware target is `zsa/moonlander/reva`.

## Flash

Put the Moonlander into bootloader/reset mode before running the command below. On the keyboard this is the mode used for flashing/programming firmware.

```bash
sudo make flash
```

This is the main command. The first run clones ZSA QMK firmware into `./qmk_firmware`, copies this keymap there, builds the firmware, and flashes the keyboard. Next runs reuse the existing `./qmk_firmware` directory, so they only refresh the keymap files, build, and flash again.

If the keyboard flashes successfully but does not boot, try the other Moonlander revision:

```bash
sudo make flash KEYBOARD_REV=reva
```

## Clean

```bash
sudo make clean
```

This removes the local `./qmk_firmware` clone. The next `sudo make flash` will clone it again.

## Help

```bash
make help
```
