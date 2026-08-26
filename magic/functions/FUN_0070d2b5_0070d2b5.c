/*
 * Decompiled function: FUN_0070d2b5
 * Entry Point: 0070d2b5
 * Size: 75 bytes
 */
#include "magic.h"


void FUN_0070d2b5(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  iVar3 = 0;
  iVar2 = 0x800;
  do {
    *(undefined2 *)((int)&DAT_00532860 + iVar3) = 0xffff;
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  cVar1 = '\0';
  iVar3 = 0;
  iVar2 = 0x100;
  do {
    (&DAT_00532862)[iVar3] = cVar1;
    cVar1 = cVar1 + '\x01';
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


