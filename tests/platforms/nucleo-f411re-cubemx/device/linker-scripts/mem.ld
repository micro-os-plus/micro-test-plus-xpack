/* 
 * DO NOT EDIT! Automatically generated from template file:
 * build-helper/templates/common/_micro-os-plus/tests/platforms/nucleo-f411re-cubemx/device/linker-scripts/mem-liquid.ld
 *
 * The STM32F411xe memory map.
 * The memory sections are defined in the `startup` package.
 */
MEMORY
{
  RAM (xrw): ORIGIN = 0x20000000, LENGTH = 128K /* 0x20020000 */
  FLASH (rx): ORIGIN = 0x08000000, LENGTH = 512K /* 0x08080000 */
}
