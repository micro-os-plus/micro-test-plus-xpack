
#include "micro-os-plus/device.h"
#include "micro-os-plus/startup.h"

extern "C" void
runtime_init (void)
{
  // // Global interrupts are masked by the boot ROM; unmask them here,
  // // before running main(), by clearing PRIMASK.
  // __enable_irq ();

  micro_os_plus_startup_run_main ();
}