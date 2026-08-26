/*
 * Decompiled function: FUN_00492b17
 * Entry Point: 00492b17
 * Size: 121 bytes
 */
#include "duel.h"


void FUN_00492b17(char *str_1,int arg2)

{
  int iVar1;
  size_t sVar2;
  
  while( true ) {
    iVar1 = Mem_AllocOrFree_0049f5c6(str_1);
    if (iVar1 <= arg2) break;
    sVar2 = _strlen(str_1);
    if (str_1[sVar2 - 3] != ' ') {
      sVar2 = _strlen(str_1);
      str_1[sVar2 - 2] = '.';
    }
    sVar2 = _strlen(str_1);
    str_1[sVar2 - 1] = '\0';
  }
  return;
}


