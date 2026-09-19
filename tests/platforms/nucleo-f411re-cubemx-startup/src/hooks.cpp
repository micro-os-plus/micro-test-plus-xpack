/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/startup.h"
#include "micro-os-plus/nucleo-f411re-cubemx-startup/led-green.h"

// ----------------------------------------------------------------------------

// The onboard green LED, used to signal general board activity. The
// CubeMX-generated `main()` (renamed
// `micro_os_plus_startup_initialise_hardware_hook()`) already brings up
// the clocks and configures the LD2 pin, so there is no
// `initialise_hardware_early_hook` here.
platform::nucleo_f411re_cubemx_startup::led_green activity_led;

// ----------------------------------------------------------------------------

// Called from micro_os_plus_startup_run_main(), after the static
// initialisers have run (post_init_array, not initialise_hardware, so
// that activity_led is touched only after its own static initialiser
// has executed).
// Requires MICRO_OS_PLUS_STARTUP_POST_INIT_ARRAY_ENABLED (startup-defines.h).
int
micro_os_plus_startup_post_init_array_hook (void)
{
  activity_led.power_up ();
  activity_led.turn_on ();

  return 0;
}

// Called from micro_os_plus_startup_exit() right before the
// application session terminates (semihosting exit or hardware reset).
// Requires MICRO_OS_PLUS_STARTUP_FINALISE_HARDWARE_ENABLED
// (startup-defines.h).
void
micro_os_plus_startup_finalise_hardware_hook (void)
{
  activity_led.turn_off ();
  activity_led.power_down ();
}

// ----------------------------------------------------------------------------
