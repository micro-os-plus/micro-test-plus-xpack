#include <stddef.h>

int __attribute__ ((weak))
_getentropy (__attribute__ ((unused)) void* buffer,
             __attribute__ ((unused)) size_t length)
{
  // note we don't hook this up as it isn't clear if/where it is used, and we don't particularly
  // want to pull in pico_rand. the user can supply their own strong implementation if they need it!
  return -1;
}
