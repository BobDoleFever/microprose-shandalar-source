/*
 * Decompiled function: FUN_004077ae
 * Entry Point: 004077ae
 * Size: 144 bytes
 */
#include "magic.h"


char * FUN_004077ae(char *str_1)

{
  for (; ((*str_1 != '\0' && (*str_1 == ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  for (; ((*str_1 != '\0' && (*str_1 != ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  if (*str_1 == '\0') {
    str_1 = (char *)0x0;
  }
  return str_1;
}


