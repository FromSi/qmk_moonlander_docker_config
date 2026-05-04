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

## Modes

### MOD_MAIN

Main English layer with letters, basic punctuation, navigation, and shortcuts to the other modes.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    X      Y      P      ---    !   │   │ ?      F      G      C      R      L      ---  │
│ Tab    A      O      E      U      I      -   │   │ '      D      H      T      N      S      ---  │
│ Space  ---    Q      J      K      ---        │   │        B      M      W      V      Z      ---  │
│ ,      Mouse  Game   Work   Sym               │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ Lang   Move   Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_RU

Russian layer with the same utility keys and mode switches, while the letter area sends Russian characters.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    Й      Ц      У      Е      Ф      !   │   │ ?      Щ      Г      Т      Н      З      Ъ    │
│ Tab    К      М      В      А      П      -   │   │ "      Р      О      Л      Д      Ж      Э    │
│ Space  Я      Ч      С      И      Ы          │   │        Ш      Ь      Б      Ю      Х      Ё    │
│ ,      Mouse  Game   Work   Sym               │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ Lang   Move   Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_WORKSPACE

Workspace layer for fast workspace and window-group switching through Ctrl/Gui combinations.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    C-q    C-w    C-e    C-r    ---    !   │   │ ?      G-7    G-8    G-9    ---    ---    ---  │
│ Tab    C-a    C-s    C-d    C-f    ---    -   │   │ '      G-4    G-5    G-6    ---    ---    ---  │
│ Space  C-z    C-x    C-c    C-v    C-/        │   │        G-1    G-2    G-3    G-0    ---    ---  │
│ ,      Mouse  Game   Main   Sym               │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ A-Gui  ---    Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_WINDOW

Window-management layer for moving windows, changing focus, and running Gui/Alt command variants.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    ---    ---    ---    ---    !   │   │ ?      ---    A-G-H  A-G-J  A-G-K  A-G-L  ---  │
│ Tab    G-g    G-s    G-f    G-d    ---    -   │   │ '      ---    G-h    G-j    G-k    G-l    ---  │
│ Space  ---    ---    ---    ---    ---        │   │        ---    AGSH   AGSJ   AGSK   AGSL   ---  │
│ ,      Mouse  Game   Work   Sym               │   │               Num    Main   Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ ---    ---    Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_SYMBOL

Symbol layer with brackets, operators, and macros for compound symbols.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ~      `      %      @      ---    !   │   │ ?      ---    [      ]      ->     =>     ---  │
│ Tab    =      |      &      $      +      -   │   │ '      ---    (      )      <      >      ---  │
│ Space  ^      #      *      \      /          │   │        ---    {      }      <=     >=     ---  │
│ ,      Mouse  Game   Work   Main              │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ ---    ---    Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_NUMBER

Number layer with function keys on the left, digits on the right, and utility navigation at the bottom.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    F12    F11    F10    F9     !   │   │ ?      7      8      9      ---    ---    ---  │
│ Tab    ---    F8     F7     F6     F5     -   │   │ '      4      5      6      ---    ---    ---  │
│ Space  ---    F4     F3     F2     F1         │   │        1      2      3      0      ---    ---  │
│ ,      Mouse  Game   Work   Sym               │   │               Main   Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ ---    ---    Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_MUSIC

Minimal music and RGB layer: most keys are disabled, with only the needed toggles active.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ---    ---    ---    ---    ---    ---    --- │   │ ---    ---    ---    ---    ---    ---    ---  │
│ ---    ---    ---    ---    ---    ---    --- │   │ ---    ---    ---    ---    ---    ---    ---  │
│ ---    ---    ---    ---    ---    ---    --- │   │ ---    ---    ---    ---    ---    ---    ---  │
│ ---    ---    ---    ---    ---    ---        │   │        ---    ---    ---    ---    ---    ---  │
│ ---    ---    ---    ---    ---               │   │               ---    ---    ---    ---    ---  │
│                                         MuTg  │   │ MuNext                                         │
│                           LedTg  RGBMod RGBTg │   │ Main   ---    ---                              │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_MOVE

Movement layer with arrows, Home/End/Page keys, and a Vim-like H/J/K/L block.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    ---    ---    ---    ---    !   │   │ ?      ---    Home   PgDn   PgUp   End    ---  │
│ Tab    ---    ---    ---    ---    ---    -   │   │ '      ---    Left   Down   Up     Right  ---  │
│ Space  ---    ---    ---    ---    ---        │   │        ---    H      J      K      L      ---  │
│ ,      Mouse  Game   Work   Sym               │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ ---    Main   Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_CONFIG

Configuration layer for bootloader access, RGB brightness, system power, volume, and media controls.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    ---    ---    ---    ---    !   │   │ ?      Boot   RGB+   RGB-   ---    ---    ---  │
│ Tab    ---    ---    ---    ---    ---    -   │   │ '      Power  Vol+   Vol-   Mute   ---    ---  │
│ Space  ---    ---    ---    ---    ---        │   │        ---    Next   Play   Stop   Prev   ---  │
│ ,      Mouse  Game   Work   Sym               │   │               Num    Win    Music  Main   .    │
│                                         Ctrl  │   │ Alt                                            │
│                           Shift  Bspc   Enter │   │ ---    ---    Space                            │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_MOUSE

Mouse layer for cursor movement, wheel scrolling, and mouse buttons.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    C-z    ---    ;      (      C-c    C-v │   │ Left   Right  )      :      ---    PrScr  Pass │
│ GUI    ---    ---    ---    ---    ---    !   │   │ ?      ---    ---    ---    ---    ---    ---  │
│ Tab    ---    ---    ---    ---    ---    -   │   │ '      ---    MsL    MsD    MsU    MsR    ---  │
│ Space  ---    ---    ---    ---    ---        │   │        ---    WhL    WhD    WhU    WhR    ---  │
│ ,      Main   Game   Work   Sym               │   │               Num    Win    Music  Config .    │
│                                         Ctrl  │   │ Btn4                                           │
│                           Shift  Bspc   Enter │   │ Btn3   Btn1   Btn2                             │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```

### MOD_GAME

Gaming layer with a classic WASD block, number row, and dedicated modifiers.

```text
┌───────────────────────────────────────────────┐   ┌────────────────────────────────────────────────┐
│ ESC    1      2      3      4      5      6   │   │ 7      8      9      0      -      =      ESC  │
│ ---    Q      W      E      R      T      --- │   │ ---    Y      U      I      Up     P      ---  │
│ Tab    A      S      D      F      G      Alt │   │ RAlt   H      J      Left   Down   Right  ---  │
│ Shift  Z      X      C      V      B          │   │        N      M      ,      .      /      RSft │
│ Ctrl   Mouse  Main   Work   Sym               │   │               Num    Win    Music  Config RCtl │
│                                         GUI   │   │ ---                                            │
│                           Space  Bspc   Enter │   │ L      ---    ---                              │
└───────────────────────────────────────────────┘   └────────────────────────────────────────────────┘
```
