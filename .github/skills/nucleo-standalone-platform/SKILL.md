---
name: nucleo-standalone-platform
description: 'Create a new tests/platforms/nucleo-<board> platform that drives its clock and onboard LED directly on CMSIS registers, derived from an existing tests/platforms/nucleo-<board>-cubemx platform that uses the STM32Cube HAL (and, on some boards, a Nucleo BSP layer). Use when the user asks to add a "standalone" variant of a Nucleo board that currently only has a *-cubemx platform, following the nucleo-f411re/nucleo-f767zi/nucleo-h533re precedent.'
argument-hint: 'Source *-cubemx platform name (e.g. nucleo-h533re-cubemx) and the target standalone platform name (e.g. nucleo-h533re)'
---

# Standalone Nucleo Platform From a CubeMX Platform — µTest++ Test Platforms

## When to Use

- The user asks to add a "standalone" `tests/platforms/nucleo-<board>` platform
  derived from an existing `tests/platforms/nucleo-<board>-cubemx` one — a
  platform that keeps only the CMSIS register headers from the original
  STM32CubeMX project and drives the clock/LED directly on the peripheral
  registers, with no STM32Cube HAL and no Nucleo BSP.
- The user asks to port this pattern to a new STM32 family the repo hasn't
  seen yet (F4, F7 and H5 are already covered by nucleo-f411re, nucleo-f767zi
  and nucleo-h533re respectively; the pitfalls section below calls out where
  those three already disagree with each other).

Three worked examples already exist in this repo and are the primary
reference for every step below: `nucleo-f411re` (from `nucleo-f411re-cubemx`,
STM32F411, Cortex-M4), `nucleo-f767zi` (from `nucleo-f767zi-cubemx`,
STM32F767, Cortex-M7) and `nucleo-h533re` (from `nucleo-h533re-cubemx`,
STM32H533, Cortex-M33). When in doubt, diff the `*-cubemx` and standalone
pair closest to the target family rather than guessing.

## Scope

This is a whole-platform port, not just an LED driver — see the separate
`led` skill for the driver-writing conventions it shares. This skill covers
the full set of files that change: `device/CMakeLists.txt`, `device.h`, a
new chip-level `system-clock.h`/`.cpp`, a new `system-<chip>.cpp` replacing
the CubeMX-generated `system_stm32<fam>xx.c`, the board-level LED header/
source, `platform.h`, `startup-defines.h`, both `cmake/*.cmake` files that
still reference the removed CubeMX objects library, and both `README.md`s.

## Procedure

1. **Check `tests/package.json` first.** The build configuration for the
   target platform name may already be pre-wired (this was true for both
   `nucleo-f767zi` and `nucleo-h533re` — someone had already added
   `buildConfigurations["<board>-cmake-gcc-debug/release"]`, the
   `clear/install/link-dependencies/build/test/clean-<board>-cmake-gcc`
   actions block, and the `convert-startup-to-vectors.mjs` script line,
   before the platform folder existed). Confirm with:
   ```sh
   python3 -c "import json; bc=json.load(open('tests/package.json'))['xpack']['buildConfigurations']; \
     print([k for k in bc if '<board>' in k])"
   grep -n '"nucleo-<board>' tests/package.json
   ```
   If it is genuinely missing, add it by copying the shape of an existing
   `<board>`/`<board>-cubemx` pair (e.g. `nucleo-f411re`/
   `nucleo-f411re-cubemx`'s entries) — same `inherits`, same
   `devDependencies`, `properties.platformName` set to the new board name,
   same `link-dependencies` action — plus the matching `configs-*` actions
   block and, if a `vectors-*.c` file needs regenerating later, the
   `convert-startup-to-vectors.mjs` line under `scripts`.

2. **Copy and prune the source tree.**
   ```sh
   rsync -a --exclude='.DS_Store' tests/platforms/<board>-cubemx/ tests/platforms/<board>/
   find tests/platforms/<board> -name '.DS_Store' -delete
   cd tests/platforms/<board>/device/stm32cubemx
   rm -rf .mxproject cmake CMakeLists.txt CMakePresets.json Core \
          Drivers/<FAMILY>_HAL_Driver Drivers/BSP \
          startup_*.s *_FLASH.ld *_RAM.ld
   ```
   Keep **only** `Drivers/CMSIS/**` and the `.ioc` file under
   `stm32cubemx/`. `device/<CHIP>.svd` and `device/linker-scripts/mem.ld`
   are not CubeMX-generated (or are pre-extracted from the removed linker
   scripts) — diff them against the `*-cubemx` originals to confirm they
   are byte-identical, then leave them untouched.

3. **Rename the board's LED include folder** from
   `include/micro-os-plus/<board>-cubemx/` to
   `include/micro-os-plus/<board>/`, and create
   `device/include/micro-os-plus/<chip>/` for the new clock driver header
   (`<chip>` is the family/part lower-cased, e.g. `stm32f411re`,
   `stm32f767zi`, `stm32h533re` — match the existing headers' naming,
   not the CMSIS device macro spelling).

4. **`cmake/artefacts.cmake`**: delete the
   `prepend_compile_common_private_options
   (stm32cubemx-drivers-objects-library)` line (the static-library one
   above it stays).

5. **`cmake/dependencies-libraries.cmake`**: replace
   `micro-os-plus::stm32cubemx-drivers-objects-library` with an empty
   `set (xpack_dependencies_libraries)` plus a comment explaining why.

6. **`device/CMakeLists.txt`**: replace the whole
   `stm32cubemx-interface`/`stm32cubemx-drivers-objects-library` machinery
   (the block that calls `add_subdirectory ("stm32cubemx/cmake/stm32cubemx")`
   and extracts `MX_*` directory properties) with a direct
   `micro-os-plus-device-interface` that:
   - `target_include_directories`s the two CMSIS folders kept in step 2
     (`stm32cubemx/Drivers/CMSIS/Device/ST/<FAMILY>/Include` and
     `stm32cubemx/Drivers/CMSIS/Include`), plus `include`.
   - `target_compile_definitions`s the bare device macro (`STM32F411xE`,
     `STM32F767xx`, `STM32H533xx`, …) — grep the vendored
     `stm32<fam>xx.h` aggregator header for the `#elif defined(...)` chain
     to get the exact spelling.
   - `target_sources`s `src/vectors-<chip>.c` (unchanged, reused verbatim
     — it only depends on `micro-os-plus/architecture*.h`, never the HAL),
     the new `src/system-<chip>.cpp`, and the new `src/system-clock.cpp`.
   - Drops `micro-os-plus::stm32cubemx` from `target_link_libraries`,
     keeping only `micro-os-plus::architecture`.
   - Keeps the `target_link_options`/linker-script block and the
     `micro-os-plus::device` alias unchanged.

7. **`device/include/micro-os-plus/device.h`**: drop the
   `stm32<fam>xx_hal.h` include (keep `stm32<fam>xx.h`), add
   `#include "micro-os-plus/<chip>/system-clock.h"`, and add
   `extern device::system_clock system_clock;` after the include guard's
   opening `#define`. The vendored aggregator header itself guards the HAL
   include behind `USE_HAL_DRIVER` (confirm this with a quick grep the
   first time you touch a new family) — since the build never defines that
   macro, nothing else needs to change to keep the HAL out.

8. **Write the chip-level clock driver**
   (`device/include/micro-os-plus/<chip>/system-clock.h` +
   `device/src/system-clock.cpp`), a `device::system_clock` class with
   `initialise()` (returns the resulting HCLK in Hz) and
   `clock_get_frequency_hz()` (reads the live registers back). Read
   **the literal `SystemClock_Config()`** in
   `<board>-cubemx/device/stm32cubemx/Core/Src/main.c` and reproduce
   *exactly* that oscillator/PLL/divider/voltage-scale/flash-latency
   choice on bare registers — do not assume CubeMX picked the device's
   maximum frequency. F767ZI and H533RE both turned out to be plain,
   undivided HSI with no PLL at all, despite being on capable-of-much-more
   chips — the only way to know is to read the generated `main.c`, not to
   guess from the part number's ceiling. Also do not assume an existing
   standalone driver still matches its sibling `*-cubemx` project's
   *current* `.ioc`/`main.c`: `nucleo-f411re`'s driver brings up HSE, in
   bypass mode, into the PLL for 100 MHz, but `nucleo-f411re-cubemx`'s
   checked-in `main.c` currently configures the PLL from **HSI**, not
   HSE, for 96 MHz — the two have drifted apart since the driver was
   written (the `.ioc` was presumably re-saved from CubeMX at some point
   after). If you are asked to update or re-verify an existing standalone
   driver, diff it against the sibling `*-cubemx` project's *current*
   `main.c`, don't trust that the driver still reflects it.

9. **Write `device/src/system-<chip>.cpp`**, replacing the
   CubeMX-generated `system_stm32<fam>xx.c`. It is essentially
   family-agnostic boilerplate — copy `nucleo-f767zi`'s
   `system-stm32f767xx.cpp` and rename the file/comments: declare
   `SystemCoreClock` **without an initialiser** (so it lands in `.bss`,
   not `.data` — a `.data` global would get overwritten by the `.data`
   copy that runs between the two startup hooks, clobbering whatever the
   early hook wrote), instantiate a private `device::system_clock
   system_clock;`, and implement `SystemInit()`/`SystemCoreClockUpdate()`
   by calling `system_clock.clock_get_frequency_hz()`.

10. **Write the board-level LED driver**
    (`include/micro-os-plus/<board>/led-green.h` + `src/led-green.cpp`)
    following the `led` skill's conventions, but note this repo's Nucleo
    boards use **C++ classes** (`platform::led_green`), not the C
    function-prefix convention that skill's own header describes for the
    `raspberry-pi-pico` precedent — match the sibling Nucleo boards
    (`nucleo-f411re`/`nucleo-f767zi`/`nucleo-h533re`), not the pico one.
    Trace the actual pin from the CubeMX project, not from the LED's
    on-silkscreen name:
    - Nucleo-64 boards: `Core/Inc/main.h` usually defines `LDx_Pin`/
      `LDx_GPIO_Port` directly.
    - Nucleo-144 boards: same, but check `Core/Src/gpio.c`'s
      `HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, ...)` call to
      confirm which of the three LEDs CubeMX generated `main()` actually
      lights.
    - Boards with a Nucleo BSP layer (H5 and newer families) do **not**
      define `LDx_Pin` at all — `main()` calls
      `BSP_LED_Init(LED_GREEN)`/`BSP_LED_On(LED_GREEN)` instead. Trace
      `LED_GREEN` through
      `Drivers/BSP/STM32<Hn>xx_Nucleo/stm32<hn>xx_nucleo.h`'s
      `Led_TypeDef` enum (it aliases `LED_GREEN` to `LED1` or `LED2`
      depending on an `#if defined (USE_NUCLEO_144)` branch) and then
      through the `LED_PORT[]`/`LED_PIN[]` arrays in the matching `.c`
      file, which themselves branch again on the board-specific
      `USE_NUCLEO_<PART>` macro (confirm which one is actually defined in
      `Core/Inc/stm32<hn>xx_nucleo_conf.h`) to the real `LEDn_GPIO_PORT`/
      `LEDn_PIN` macros.

11. **`include/micro-os-plus/platform.h`**: drop the CubeMX-generated
    `main.h` include and the old `<board>-cubemx/led-green.h` include;
    add `#include "micro-os-plus/<board>/led-green.h"`.

12. **`include/micro-os-plus/startup-defines.h`**: uncomment
    `#define MICRO_OS_PLUS_STARTUP_INITIALISE_HARDWARE_EARLY_ENABLED` (the
    standalone platform needs the early hook to bring the clock up before
    `.bss` init; the `*-cubemx` platform doesn't, because its renamed
    `main()` — `micro_os_plus_startup_initialise_hardware_hook()` — runs
    late enough that it never needed one).

13. **`src/hooks.cpp`**: add
    `micro_os_plus_startup_initialise_hardware_early_hook()` (instantiates
    nothing new — just calls `SystemCoreClock = system_clock.initialise
    ();` using the `extern device::system_clock system_clock;` from
    `device.h`) and `micro_os_plus_startup_initialise_hardware_hook()`
    (just calls `SystemInit ();`). Leave the existing
    `post_init_array_hook`/`finalise_hardware_hook` LED on/off pair as is.

14. **Update both `README.md`s** (top-level and `device/`) to describe the
    new bring-up path and explicitly list, in `device/README.md`, exactly
    which CubeMX-generated pieces were dropped and why (`Core/`, the
    family's `*_HAL_Driver/`, `Drivers/BSP/` if present, the generated
    CMake, `.mxproject`, `startup_*.s`) — this is the file a future reader
    checks to understand why the `stm32cubemx/` folder looks half-empty.

## Naming Conventions

- Header guards: `MICRO_OS_PLUS_<CHIP-OR-BOARD>_<NAME>_H_`, matching the
  renamed folder, not the old `*-cubemx`-suffixed one.
- `device::system_clock` and `platform::led_green` (not
  `platform::<board>::led_green` — the namespace is fixed, the board
  identity lives in the file path only).
- File/folder names lower-case, matching the existing three platforms
  exactly (`system-clock.h`/`.cpp`, `system-<chip>.cpp`,
  `led-green.h`/`.cpp`).
- Comments explain *why* (register sequencing, which CubeMX-generated call
  a given write replaces, busy-wait conditions), not *what* — see any of
  the three existing `system-clock.cpp` files for the expected density.

## Register-Level Access Rules

- **Never assume a bit-field's position, mask, or macro name carries over
  from another STM32 family — grep the vendored `stm32<fam>xx.h` for the
  literal `_Pos`/`_Msk`/`_0`/`_1` defines every time**, even for
  conceptually identical fields. Concrete traps already hit while writing
  these three platforms:
  - **Voltage-scale encoding is not consistent across families.** F7's
    `PWR_REGULATOR_VOLTAGE_SCALE3` really is `PWR_CR1_VOS_0`. H5's
    `PWR_REGULATOR_VOLTAGE_SCALE3` is `(0U)` — no bits set — and
    `PWR_VOSCR_VOS_0` is actually **scale 2**. Writing `VOS_0` and
    labelling it "scale 3" by analogy with the F7 driver produced a real,
    if harmless (over-provisioned, not under-provisioned), bug in the
    first `nucleo-h533re` clock driver — caught only by disassembling
    `initialise()` and checking the immediate against the header's actual
    `_Pos`/`_Msk`. Always cross-check the HAL header's own
    `#define PWR_REGULATOR_VOLTAGE_SCALEn ...` line, not another family's
    driver, and always spot-check the max-HCLK-per-scale numbers in the
    HAL header's doc comments before picking a scale for a frequency that
    wasn't already used by the CubeMX config you're mirroring.
  - GPIO clock-enable lives on a different AHB bus register per family:
    `RCC_AHB1ENR_GPIOxEN` on F4/F7, `RCC_AHB2ENR_GPIOxEN` on H5.
  - GPIO bit-field macro spelling is inconsistent even where the field is
    identical: F4 uses `GPIO_OSPEEDR_OSPEED5`/`GPIO_PUPDR_PUPD5`; F7 uses
    `GPIO_OSPEEDR_OSPEEDR0`/`GPIO_PUPDR_PUPDR0` (extra `R`); H5 uses
    `GPIO_MODER_MODE5` (no extra `R` in `MODE`, unlike F4/F7's
    `MODER5`)/`GPIO_OSPEEDR_OSPEED5`/`GPIO_PUPDR_PUPD5`. There is no
    reliable pattern — grep the actual header.
  - The clock-control register layout itself differs: F4/F7 have one
    `RCC->CFGR` for `SW`/`SWS`/`HPRE`/`PPRE1`/`PPRE2`; H5 splits it into
    `RCC->CFGR1` (`SW`/`SWS`) and `RCC->CFGR2`
    (`HPRE`/`PPRE1`/`PPRE2`/`PPRE3` — note the extra APB3 bus). Don't
    port a single-`CFGR` read/write pattern to H5 without checking.
- Read-modify-write every field through its `_Msk` (clear) then `_Pos`/
  named `_n` value (set); never hand-roll a shifted literal.
- Every busy-wait loop (`HSIRDY`, `HSERDY`, `VOSRDY`, `SWS` settling) gets
  an explanatory comment in the empty body; if the wait can plausibly hang
  forever on hardware that doesn't actually route the expected signal
  (see "Upgrading a Modest Clock to a More Accurate One" below), say so
  in the comment, not just in the PR description.
- **Disassemble `system_clock::initialise()` after writing it**
  (`arm-none-eabi-objdump -d <exe>.elf`) and check every immediate
  against the header's `_Pos`/`_Msk` by hand. This is cheap (a few
  minutes) and is the only technique that actually caught the
  voltage-scale bug above — a clean `-Werror` build proves nothing
  about register-field correctness.

## Upgrading a Modest Clock to a More Accurate One (Optional, Hardware-Gated)

CubeMX frequently leaves a project on internal HSI even when the board's
onboard ST-LINK feeds a more accurate external clock into the target's
`OSC_IN` pin (visible in the `.ioc` as
`PH0-OSC_IN(PH0).Mode=HSE-External-Clock-Source` plus an `RCC.HSE_VALUE=`
entry, even when the *active* `SystemClock_Config()` never turns HSE on).
If asked to switch a driver built per this skill from HSI to that HSE
signal:

- Treat a `GPIO_Label` on the `.ioc`'s `PH0-OSC_IN` entry that names the
  actual source chip/pin (e.g. `MCO [STM32F103CBT6_PA8]` — the ST-LINK/
  V2-1's own MCU) as materially stronger evidence than a bare `Mode=
  HSE-External-Clock-Source` with no label. `nucleo-f767zi`'s `.ioc` has
  the label and the HSE-bypass switch works on real hardware;
  `nucleo-h533re`'s `.ioc` doesn't have it, and the equivalent switch
  hangs on `HSERDY` on real hardware (the ST-LINK clock never reaches
  the pin on that board/revision).
  - HSE-bypass mode requires an `HSEEXT` bit choice on H5-family parts
    (digital vs analog bypass) that F4/F7 don't have at all — check the
    HAL's `RCC_HSE_BYPASS` vs `RCC_HSE_BYPASS_DIGITAL` macros before
    picking one for a new H5-family board.
- If the new HSE frequency differs from the frequency the HSI-based
  config used, **recheck voltage scale and flash latency independently**
  — do not assume the old config's choices still cover the new
  frequency (this is where the H533RE voltage-scale bug above actually
  mattered: 25 MHz exceeds VOS3's documented 24 MHz ceiling, so the
  switch to HSE also required moving to VOS2).
- State plainly, in both the driver header comment and whichever
  `README.md`/hooks comment describes the early hook, that the change is
  unverified until a human confirms it on real hardware, and what the
  failure symptom looks like (`initialise()` never returns — the
  `HSERDY` busy-wait spins forever) — so a future reader who hits that
  hang immediately recognises it as this exact failure mode rather than
  debugging a hard fault. Once confirmed working, update those comments
  to say so instead of leaving stale "unverified" language behind (see
  `nucleo-f767zi`'s history for both states).

## Testing

- `xpm install --config <board>-cmake-gcc-debug`, then
  `xpm run link-dependencies --config <board>-cmake-gcc-debug`, then
  `xpm run setup --config <board>-cmake-gcc-debug`, then
  `xpm run build --config <board>-cmake-gcc-debug` — per this project's
  standing guidance, do **not** rely on the `-C tests` composite actions
  or on `xpm run test -C tests` alone; they only exercise the
  system-compiler config, not a specific board. Repeat for
  `-cmake-gcc-release`.
- A clean build must show zero `-Werror` diagnostics for all five test
  executables (`empty`, `minimal`, `suite`, `sample`, `unit`).
- `arm-none-eabi-nm` the resulting `.elf` and confirm `SystemCoreClock`,
  the private `system_clock` instance, and `activity_led` are in `.bss`
  (address in the `20000...` RAM range, symbol type `B`), not `.data`.
- This platform cannot run in QEMU; do not claim it was "tested" beyond
  building and the register-level disassembly check above. Hardware
  verification is the user's to do — ask them to report back rather than
  assuming success.
- Delete the verification build folders under `tests/build/` afterwards
  (`rm -rf tests/build/<board>-cmake-gcc-{debug,release}`) — they are
  gitignored but there is no reason to leave them lying around.

## Checklist Before Reporting Done

- `tests/package.json` build configuration confirmed present (or added).
- `stm32cubemx/` folder contains only `Drivers/CMSIS/**` and the `.ioc`;
  no lingering `Core/`, HAL driver, BSP, generated CMake, `.mxproject`, or
  `startup_*.s`.
- `device.h` no longer includes the family's `_hal.h`; `USE_HAL_DRIVER`
  confirmed never defined.
- `system_clock::initialise()` reproduces the literal
  `SystemClock_Config()` from the `*-cubemx` project's `main.c` — not a
  guessed "maximum performance" configuration — unless intentionally
  upgraded per the HSE section above, in which case that section's extra
  checks were done.
- Every register field written was verified against that family's
  `stm32<fam>xx.h` `_Pos`/`_Msk` defines directly, not carried over from
  a different family's driver by analogy.
- `system_clock::initialise()` disassembled and every immediate checked
  by hand against those same `_Pos`/`_Msk` defines.
- LED pin/port traced through the actual CubeMX project (`main.h` or the
  Nucleo BSP's `Led_TypeDef`/`LED_PORT[]`/`LED_PIN[]` chain), not assumed
  from the LED's silkscreen colour or another board's pin.
- Both `README.md`s updated, including an explicit list of what was
  dropped from `stm32cubemx/` and why.
- `-cmake-gcc-debug` and `-cmake-gcc-release` both built clean under
  `-Werror`; `.bss` placement of `SystemCoreClock`/`system_clock`/
  `activity_led` confirmed via `nm`; verification build folders removed.
- Hardware behaviour stated as unverified (or, if the user has since
  confirmed it, comments/README updated to say so instead of leaving
  stale "unverified" language).
