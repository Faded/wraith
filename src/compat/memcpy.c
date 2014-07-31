/*
 * memcpy.c -- provides memcpy() if necessary.
 *
 */


#include "memcpy.h"

#ifndef HAVE_MEMCPY
void *memcpy(void *dest, const void *src, size_t n)
{
  while (n--)
    *((char *) dest)++ = *((char *) src)++;
  return dest;
}
#endif /* !HAVE_MEMCPY */
/* vim: set sts=2 sw=2 ts=8 et: */
