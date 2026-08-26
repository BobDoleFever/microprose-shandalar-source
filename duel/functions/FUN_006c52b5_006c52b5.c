/*
 * Decompiled function: FUN_006c52b5
 * Entry Point: 006c52b5
 * Size: 75 bytes
 */
#include "duel.h"


void FUN_006c52b5(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  DAT_004ff16a = 9;
  DAT_004ff16c = 0x1ff;
  DAT_004ff170 = 0x100;
  iVar3 = 0;
  iVar2 = 0x800;
  do {
    *(undefined2 *)((int)&DAT_004fb154 + iVar3) = 0xffff;
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  cVar1 = '\0';
  iVar3 = 0;
  iVar2 = 0x100;
  do {
    (&DAT_004fb156)[iVar3] = cVar1;
    cVar1 = cVar1 + '\x01';
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


