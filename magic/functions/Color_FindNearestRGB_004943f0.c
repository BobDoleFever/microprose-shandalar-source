/*
 * Decompiled function: Color_FindNearestRGB
 * Entry Point: 004943f0
 * Size: 325 bytes
 */
#include "magic.h"


undefined4 Color_FindNearestRGB(uint arg_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int local_14;
  uint local_10;
  
  Color_QuantizeRGBToPalette(arg_1,(uint *)&DAT_0054b318);
  pbVar4 = &DAT_0054b318;
  piVar3 = DAT_0054aefc;
  do {
    piVar1 = (int *)piVar3[*pbVar4 + 2];
    pbVar4 = pbVar4 + 1;
    if (piVar1 == (int *)0x0) {
      if (*piVar3 != 0) {
        return *(undefined4 *)(&DAT_0054af18 + piVar3[1] * 4);
      }
      local_14 = 0x7fffffff;
      iVar6 = 0;
      if (0 < piVar3[0xb]) {
        do {
          uVar2 = *(uint *)(&DAT_0054af18 + (uint)*(byte *)(iVar6 + piVar3[10]) * 4);
          iVar5 = *(int *)(PTR_DAT_0052a1a4 +
                          ((arg_1 & 0xff0000) >> 0x10) * 4 + ((uVar2 & 0xff0000) >> 0x10) * -4) +
                  *(int *)(PTR_DAT_0052a1a4 + ((arg_1 >> 8 & 0xff) * 4 - ((uVar2 & 0xff00) >> 6))) +
                  *(int *)(PTR_DAT_0052a1a4 + (arg_1 & 0xff) * 4 + (uVar2 & 0xff) * -4);
          if (iVar5 < local_14) {
            local_14 = iVar5;
            local_10 = (uint)*(byte *)(iVar6 + piVar3[10]);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < piVar3[0xb]);
      }
      return *(undefined4 *)(&DAT_0054af18 + local_10 * 4);
    }
    piVar3 = piVar1;
  } while ((char)*piVar1 != '\x01');
  return *(undefined4 *)(&DAT_0054af18 + piVar1[1] * 4);
}


