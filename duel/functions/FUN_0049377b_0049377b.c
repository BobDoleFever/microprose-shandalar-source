/*
 * Decompiled function: FUN_0049377b
 * Entry Point: 0049377b
 * Size: 144 bytes
 */
#include "duel.h"


char * FUN_0049377b(char *str_1)

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


