---
name: led
description: 'Create or update a board LED driver under tests/platforms/<board>, built on direct register access to the chip''s GPIO peripheral. Use when the user asks to add, wire up, or fix an LED (or "blinky") driver for a specific board/platform in this repository.'
argument-hint: 'Board platform name (e.g. raspberry-pi-pico, nucleo-f411re) and, if known, the LED pin/port'
---

# LED Driver — µTest++ Test Platforms

## When to Use

- The user asks to add an LED driver (on/off/toggle, blink pattern) for one
  of the boards under `tests/platforms/<board>/`.
- The user asks to fix, extend, or port an existing LED driver to another
  board.

## Scope and Split

LED wiring (which pin, which port, active-high or active-low) is
**board-specific**; the GPIO peripheral it is wired to is **chip-specific**.
Split the driver accordingly, following the precedent set by
`tests/platforms/raspberry-pi-pico/device/rp2040/{include,src}/clock.*`:

- **Chip-level GPIO driver** — `tests/platforms/<board>/device/<chip>/`
  - `include/micro-os-plus/<chip>/gpio.h`
  - `src/gpio.c`
  - Provides generic, pin-parametrised operations only (configure a pin as
    output, set/clear/toggle it, read it back). No knowledge of *which* pin
    is an LED.
  - If a GPIO driver already exists for the chip, reuse and, if needed,
    extend it; do not duplicate register access in the board-level driver.
- **Board-level LED driver** — `tests/platforms/<board>/`
  - `include/micro-os-plus/<board>/led.h`
  - `src/led.c`
  - Defines the board's LED pin/port/polarity constants and thin semantic
    wrappers (`_initialise`, `_on`, `_off`, `_toggle`) 
    over the chip-level GPIO driver.
  - This is new territory for most boards: as of this writing, boards under
    `tests/platforms/` have no top-level `src/` folder (their README's
    "Source files" section says "None."). Adding `led.c` means creating
    `src/`, registering it, and updating that README section (see
    "Registration" below).

Do not introduce a vendor HAL/BSP dependency (STM32Cube HAL, pico-sdk
runtime) for the driver logic itself, matching the raw-register approach
already used by `clock.c`. Vendor-generated files already checked into the
board (CubeMX `.ioc`/BSP headers under `device/*/stm32cubemx/`, or the
pico-sdk register headers under `hardware/regs/`) are still the right
*reference* for pin numbers, ports, and bit-field names — read them to get
the mapping right, but write directly to the peripheral registers rather
than calling into HAL/BSP functions. For example, the STM32H5xx Nucleo BSP
header defines the onboard LED as `LED2_PIN` = `GPIO_PIN_0` on `GPIOF`; use
that fact, not `BSP_LED_On()`.

## Naming Conventions

Match `clock.h`/`clock.c` exactly:

- C, not C++ (`extern "C"` guard in the header for C++ callers).
- Header guard: `MICRO_OS_PLUS_<CHIP-OR-BOARD>_<NAME>_H_`.
- C function names: `micro_os_plus_<chip>_gpio_<verb>` (chip level) and
  `micro_os_plus_<board>_led_<verb>` (board level), all `snake_case`,
  with verbs as `_power_up`, `_turn_on`, `_turn_off`, `_toggle`, `_power_down`
- C++ class name: platform::<board>::led_<colour>, with methods as above verbs.
- File names: lower-case, dash-separated where multi-word (the existing
  precedent uses single words — `gpio.h`, `led.h` — keep it that way unless
  a board needs to disambiguate more than one LED, e.g. `led-user.h`).
- Comments are plain C `//`/`/* */` prose, not Doxygen — the test-platform
  device layer does not use Doxygen (unlike the library's own
  `include/`/`src/`, see the top-level Copilot instructions). Explain *why*
  (register sequencing, busy-wait conditions, datasheet section) rather
  than restating the code.
- MIT licence header block identical to the one in `clock.c`/`clock.h`,
  with a plausible copyright year range (check `git log` for the file's
  first year if it already exists).

## Register-Level Access Rules

- Access peripherals through the CMSIS-style register structs already
  pulled in via `micro-os-plus/device.h` (e.g. `GPIOx->MODER`, `SIO->GPIO_OUT`),
  the same way `clock.c` uses `CLOCKS->...`, `XOSC->...`, `PLL_SYS->...`.
- Read-modify-write bit fields using the vendor's `_BITS`/`_LSB`/`_MASK`
  macros (or the CMSIS bit-field names for STM32) rather than magic
  numbers.
- Any busy-wait loop (e.g. waiting for a GPIO/clock-enable bit to take
  effect) gets an explanatory comment inside the empty loop body, exactly
  as `clock.c` does for the XOSC/PLL lock waits.
- Enable the peripheral's clock/reset gate before touching its registers,
  if the chip requires it (e.g. STM32 `RCC` GPIO clock enable, matching
  `LEDx_GPIO_CLK_ENABLE()` in the CubeMX BSP reference — implemented as a
  direct `RCC->...` write, not the HAL macro).
- Keep polarity explicit: if the LED is active-low, `_on()` clears the pin
  and `_off()` sets it; say so in a comment next to the pin/port constants,
  do not bury it in the verb names.

## Registration

For a new or changed chip-level GPIO driver:

- Add `gpio.c` to `target_sources()` in
  `tests/platforms/<board>/device/<chip>/CMakeLists.txt` (see how `clock.c`
  is registered there).

For a new board-level LED driver:

- Create `tests/platforms/<board>/src/` if it does not exist.
- Add `target_sources (micro-os-plus-platform-interface INTERFACE "src/led.c")`
  to `tests/platforms/<board>/CMakeLists.txt`.
- Update the corresponding `meson.build` for the platform with the same
  source addition.
- Update the board's `README.md` "Source files" section (currently
  "None.") to list `led.c`.

## Testing

- Prefer a QEMU-runnable board when adding a brand-new LED driver so the
  change can be exercised in CI (e.g. `qemu-cortex-m0`/`qemu-cortex-m7f`
  boards can toggle a GPIO even though there is nothing to visually see;
  assert the register state instead). If the target board is
  hardware-only (e.g. `raspberry-pi-pico`, `nucleo-*`), state plainly that
  the change is unverified beyond building, since it cannot be run in this
  environment.
- Build the specific platform action, not just the default system-compiler
  test: `xpm run test-<platform>-gcc -C tests` (see `tests/package.json`
  for the exact generated action name for the board).
- If a sample program is used to exercise the LED (e.g. under
  `tests/sources/`), confirm it builds and, where runnable under QEMU,
  passes.

## Checklist Before Reporting Done

- Chip/board split respected; no board-specific pin knowledge inside the
  chip-level GPIO driver.
- Naming, header guards, licence header, and comment style match
  `clock.h`/`clock.c`.
- No `#ifdef`/`#ifndef` outside header guards; every `#endif` repeats its
  `#if defined(...)` expression in a trailing comment.
- Line length below 80 characters.
- Polarity and pin/port mapping verified against the board's schematic or
  vendor BSP/CubeMX reference, not guessed.
- CMake **and** meson source lists updated; README "Source files" section
  updated if it changed from "None.".
- Relevant `xpm run test-<platform>-*` action run and reported (or its
  absence from this environment stated explicitly).
