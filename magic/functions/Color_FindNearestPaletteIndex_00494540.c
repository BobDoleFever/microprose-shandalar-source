/*
 * Decompiled function: Color_FindNearestPaletteIndex
 * Entry Point: 00494540
 * Size: 324 bytes
 */
#include "magic.h"


uint Color_FindNearestPaletteIndex(uint arg_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int local_18;
  uint local_14;
  
  Color_QuantizeRGBToPalette(arg_1,(uint *)&DAT_0054af08);
  pbVar4 = &DAT_0054af08;
  piVar3 = DAT_0054aefc;
  while( true ) {
    piVar1 = (int *)piVar3[*pbVar4 + 2];
    pbVar4 = pbVar4 + 1;
    if (piVar1 == (int *)0x0) break;
    piVar3 = piVar1;
    if ((char)*piVar1 == '\x01') {
      return piVar1[1];
    }
  }
  if (*piVar3 != 0) {
    return piVar3[1];
  }
  local_18 = 0x7fffffff;
  iVar6 = 0;
  if (piVar3[0xb] < 1) {
    return local_14;
  }
  do {
    uVar2 = *(uint *)(&DAT_0054af18 + (uint)*(byte *)(piVar3[10] + iVar6) * 4);
    iVar5 = *(int *)(PTR_DAT_0052a1a4 + (arg_1 & 0xff) * 4 + ((uVar2 & 0xff0000) >> 0x10) * -4) +
            *(int *)(PTR_DAT_0052a1a4 + ((arg_1 >> 8 & 0xff) * 4 - ((uVar2 & 0xff00) >> 6))) +
            *(int *)(PTR_DAT_0052a1a4 + ((arg_1 & 0xff0000) >> 0x10) * 4 + (uVar2 & 0xff) * -4);
    if (iVar5 < local_18) {
      local_14 = (uint)*(byte *)(piVar3[10] + iVar6);
      local_18 = iVar5;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < piVar3[0xb]);
  return local_14;
}


