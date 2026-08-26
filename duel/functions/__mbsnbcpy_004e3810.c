/*
 * Decompiled function: __mbsnbcpy
 * Entry Point: 004e3810
 * Size: 277 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __mbsnbcpy
   
   Library: Visual Studio 1998 Debug */

uchar * __cdecl __mbsnbcpy(uchar *str_1,uchar *str_2,size_t arg_3)

{
  size_t sVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar uVar4;
  uchar *puVar5;
  
  puVar5 = str_1;
  puVar3 = str_1;
  if (DAT_0050a304 == 0) {
    puVar5 = (uchar *)_strncpy((char *)str_1,(char *)str_2,arg_3);
  }
  else {
    do {
      while( true ) {
        str_1 = puVar3;
        if (arg_3 == 0) goto LAB_004e38f7;
        sVar1 = arg_3 - 1;
        if (((&DAT_0050a201)[*str_2] & 4) == 0) break;
        *str_1 = *str_2;
        puVar2 = str_1 + 1;
        if (sVar1 == 0) {
          *str_1 = '\0';
          str_1 = puVar2;
          arg_3 = sVar1;
          goto LAB_004e38f7;
        }
        arg_3 = arg_3 - 2;
        *puVar2 = str_2[1];
        str_2 = str_2 + 2;
        puVar3 = str_1 + 2;
        if (*puVar2 == '\0') {
          *str_1 = '\0';
          str_1 = str_1 + 2;
          goto LAB_004e38f7;
        }
      }
      puVar3 = str_1 + 1;
      *str_1 = *str_2;
      str_2 = str_2 + 1;
      uVar4 = *str_1;
      str_1 = puVar3;
      arg_3 = sVar1;
    } while (uVar4 != '\0');
LAB_004e38f7:
    while (arg_3 != 0) {
      *str_1 = '\0';
      str_1 = str_1 + 1;
      arg_3 = arg_3 - 1;
    }
  }
  return puVar5;
}


