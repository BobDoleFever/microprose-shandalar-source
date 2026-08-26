/*
 * Decompiled function: __printMemBlockData
 * Entry Point: 004dc480
 * Size: 252 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __printMemBlockData
   
   Library: Visual Studio 1998 Debug */

void __printMemBlockData(int arg_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  uint local_58;
  int local_50;
  byte local_4c [20];
  char local_38 [52];
  
  local_50 = 0;
  while( true ) {
    iVar3 = *(int *)(arg_1 + 0x10);
    if (0xf < iVar3) {
      iVar3 = 0x10;
    }
    if (iVar3 <= local_50) break;
    bVar1 = *(byte *)(arg_1 + 0x20 + local_50);
    if (DAT_005096ac < 2) {
      local_58 = *(ushort *)(PTR_DAT_005094a0 + (uint)bVar1 * 2) & 0x157;
    }
    else {
      local_58 = __isctype((uint)bVar1,0x157);
    }
    if (local_58 == 0) {
      local_4c[local_50] = 0x20;
    }
    else {
      local_4c[local_50] = bVar1;
    }
    _sprintf(local_38 + local_50 * 3,"%.2X ",(uint)bVar1);
    local_50 = local_50 + 1;
  }
  local_4c[local_50] = 0;
  iVar3 = __CrtDbgReport(0,0,0,0," Data: <%s> %s\n");
  if (iVar3 == 1) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  return;
}


