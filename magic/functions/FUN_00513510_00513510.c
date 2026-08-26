/*
 * Decompiled function: FUN_00513510
 * Entry Point: 00513510
 * Size: 204 bytes
 */
#include "magic.h"


uint FUN_00513510(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_006261d8;
  uVar2 = 0;
  (&g_OverworldWorldState)[DAT_006261d8] = 0;
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      uVar2 = uVar2 + (int)*(short *)(&g_OverworldWorldState + iVar1);
      iVar1 = iVar1 + 2;
    } while (iVar1 < DAT_006261d8);
  }
  uVar2 = uVar2 & 0x7fff;
  if (uVar2 == 0) {
    uVar2 = DAT_006261d8 * 0x25 & 0x7fff;
  }
  uVar3 = uVar2 % 0xffb;
  iVar1 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uVar3 * 0xc);
    if (*DAT_00702924 == -1) {
      return 0xffffffff;
    }
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == DAT_006261dc)) break;
    if (iVar1 == -1) {
      iVar1 = 0xff9 - uVar2 % 0xff9;
    }
    if (iVar1 == 0) {
      iVar1 = DAT_006261d8 * 0x89;
    }
    uVar3 = (int)(iVar1 + uVar3) % 0xffb;
  }
  return uVar3;
}


