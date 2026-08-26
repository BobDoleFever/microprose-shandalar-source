/*
 * Decompiled function: _strlen
 * Entry Point: 00405540
 * Size: 123 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *str_1)

{
  uint32_t uval_1;
  uint32_t *u_ptr_2;
  uint32_t *u_ptr_3;
  
  u_ptr_2 = (uint32_t *)str_1;
  do {
    if (((uint32_t)u_ptr_2 & 3) == 0) goto LAB_00405560;
    uval_1 = *u_ptr_2;
    u_ptr_2 = (uint32_t *)((int)u_ptr_2 + 1);
  } while ((char)uval_1 != '\0');
LAB_00405593:
  return (size_t)((int)u_ptr_2 + (-1 - (int)str_1));
LAB_00405560:
  do {
    do {
      u_ptr_3 = u_ptr_2;
      u_ptr_2 = u_ptr_3 + 1;
    } while (((*u_ptr_3 ^ 0xffffffff ^ *u_ptr_3 + 0x7efefeff) & 0x81010100) == 0);
    uval_1 = *u_ptr_3;
    if ((char)uval_1 == '\0') {
      return (int)u_ptr_3 - (int)str_1;
    }
    if ((char)(uval_1 >> 8) == '\0') {
      return (size_t)((int)u_ptr_3 + (1 - (int)str_1));
    }
    if ((uval_1 & 0xff0000) == 0) {
      return (size_t)((int)u_ptr_3 + (2 - (int)str_1));
    }
  } while ((uval_1 & 0xff000000) != 0);
  goto LAB_00405593;
}


