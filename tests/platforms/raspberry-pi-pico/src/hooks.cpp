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

#include "micro-os-plus/device.h"
#include "micro-os-plus/startup.h"
#include "micro-os-plus/rp2040/clock.h"
#include "micro-os-plus/raspberry-pi-pico/led-green.h"

// ----------------------------------------------------------------------------

// The onboard green LED, used to signal general board activity.
platform::pico::led_green activityLed;

// ----------------------------------------------------------------------------

// Called before the data & bss sections are initialised, typically used to
// set up the system clock (so that the initialisations are faster) and
// possibly to enable external RAM.
// If any driver leaves values in RAM, they will be cleared and lost, so
// those drivers should reinitialise their RAM contents in the next hook.
int
micro_os_plus_startup_initialise_hardware_early_hook (void)
{
  SystemCoreClock = micro_os_plus_rp2040_clock_init ();
  return 0;
}

// Called after the data & bss sections are initialised, typically used to
// finalise the hardware setup.
int
micro_os_plus_startup_initialise_hardware_hook (void)
{
  SystemInit ();

  activityLed.power_up ();
  activityLed.turn_on ();

  return 0;
}

void
micro_os_plus_startup_finalise_hardware_hook (void)
{
  activityLed.turn_off ();
  activityLed.power_down ();
}

// ----------------------------------------------------------------------------
