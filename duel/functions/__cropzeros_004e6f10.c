/*
 * Decompiled function: __cropzeros
 * Entry Point: 004e6f10
 * Size: 223 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cropzeros
   
   Library: Visual Studio 1998 Debug */

void __cdecl __cropzeros(char *str_1)

{
  char *pcVar1;
  char *local_8;
  
  for (; (*str_1 != '\0' && (DAT_005096b0 != *str_1)); str_1 = str_1 + 1) {
  }
  if (*str_1 != '\0') {
    do {
      pcVar1 = str_1;
      str_1 = pcVar1 + 1;
      if ((*str_1 == '\0') || (*str_1 == 'e')) break;
    } while (*str_1 != 'E');
    local_8 = str_1;
    for (str_1 = pcVar1; *str_1 == '0'; str_1 = str_1 + -1) {
    }
    if (DAT_005096b0 == *str_1) {
      str_1 = str_1 + -1;
    }
    do {
      str_1 = str_1 + 1;
      *str_1 = *local_8;
      local_8 = local_8 + 1;
    } while (*str_1 != '\0');
  }
  return;
}


