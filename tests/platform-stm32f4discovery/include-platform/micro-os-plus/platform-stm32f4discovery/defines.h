/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2020 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#ifndef MICRO_OS_PLUS_PLATFORM_STM32F4DISCOVERY_DEFINES_H_
#define MICRO_OS_PLUS_PLATFORM_STM32F4DISCOVERY_DEFINES_H_

// ----------------------------------------------------------------------------

// ----- LED definitions ------------------------------------------------------

// On the STM32F4-Discovery board, the coloured LEDs are
// connected to PD12-PD15, active high.

#define LED_GREEN_PORT_NUMBER (3)
#define LED_GREEN_PIN_NUMBER (12)

#define LED_ORANGE_PORT_NUMBER (3)
#define LED_ORANGE_PIN_NUMBER (13)

#define LED_RED_PORT_NUMBER (3)
#define LED_RED_PIN_NUMBER (14)

#define LED_BLUE_PORT_NUMBER (3)
#define LED_BLUE_PIN_NUMBER (15)

// ----------------------------------------------------------------------------

#endif /* MICRO_OS_PLUS_PLATFORM_STM32F4DISCOVERY_DEFINES_H_ */

// ----------------------------------------------------------------------------
