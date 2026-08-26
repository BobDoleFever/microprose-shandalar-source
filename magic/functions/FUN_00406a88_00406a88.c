/*
 * Decompiled function: FUN_00406a88
 * Entry Point: 00406a88
 * Size: 121 bytes
 */
#include "magic.h"


void FUN_00406a88(char *str_1,int arg2)

{
  int iVar1;
  size_t sVar2;
  
  while( true ) {
    iVar1 = FUN_0040c465(str_1);
    if (iVar1 <= arg2) break;
    sVar2 = strlen(str_1);
    if (str_1[sVar2 - 3] != ' ') {
      sVar2 = strlen(str_1);
      str_1[sVar2 - 2] = '.';
    }
    sVar2 = strlen(str_1);
    str_1[sVar2 - 1] = '\0';
  }
  return;
}


