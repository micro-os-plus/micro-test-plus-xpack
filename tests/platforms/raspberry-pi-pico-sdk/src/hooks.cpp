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
#include "micro-os-plus/raspberry-pi-pico-sdk/led-green.h"

// ----------------------------------------------------------------------------

// The onboard green LED, used to signal general board activity. Unlike
// the raspberry-pi-pico platform, the Pico SDK's own
// pico_crt0/pico_runtime_init already bring up the clocks (see
// __wrap_main() in wraps.c), so there is no
// initialise_hardware_early_hook here.
platform::raspberry_pi_pico_sdk::led_green activity_led;

// ----------------------------------------------------------------------------

// Called after the static initialisers have run (post_init_array, not
// initialise_hardware, so that activity_led is touched only after its
// own static initialiser has executed).
int
micro_os_plus_startup_post_init_array_hook (void)
{
  activity_led.power_up ();
  activity_led.turn_on ();

  return 0;
}

void
micro_os_plus_startup_finalise_hardware_hook (void)
{
  activity_led.turn_off ();
  activity_led.power_down ();
}

// ----------------------------------------------------------------------------
