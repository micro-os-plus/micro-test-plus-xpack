/* 
 * DO NOT EDIT! Automatically generated from template file:
 * build-helper/templates/common/_micro-os-plus/tests/platforms/nucleo-f767zi/device/linker-scripts/mem-liquid.ld
 *
 * The STM32F767xx memory map.
 * The memory sections are defined in the `startup` package.
 */
MEMORY
{
  RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 512K
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 2048K
}
