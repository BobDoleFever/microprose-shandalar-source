/*
 * Decompiled function: FUN_005112b0
 * Entry Point: 005112b0
 * Size: 747 bytes
 */
#include "magic.h"


int FUN_005112b0(short arg1,short arg2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10 [4];
  
  iVar6 = (int)arg2;
  iVar1 = (int)(0x4000 / (longlong)iVar6);
  if (DAT_0070a880 != 8) {
    return (uint)(ushort)((ulonglong)(0x4000 / (longlong)iVar6) >> 0x10) << 0x10;
  }
  puVar2 = &DAT_0070a130;
  puVar8 = &DAT_007051e0;
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  local_2c = (int)arg1;
  local_28 = local_2c;
  local_24 = local_2c;
  puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&local_2c);
  local_1c = *puVar2;
  local_18 = puVar2[1];
  local_14 = puVar2[2];
  sVar7 = 0;
  FUN_0050e8b0((short *)&DAT_0070a130);
  do {
    iVar5 = (int)sVar7;
    pbVar9 = (byte *)(iVar5 * 3 + DAT_00532804);
    (&DAT_00705500)[iVar5 * 4] = (uint)*pbVar9;
    (&DAT_00705504)[iVar5 * 4] = (uint)pbVar9[1];
    (&DAT_00705508)[iVar5 * 4] = (uint)pbVar9[2];
    puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&DAT_00705500 + iVar5 * 4);
    (&DAT_007039e0)[iVar5 * 3] = *puVar2;
    (&DAT_007039e4)[iVar5 * 3] = puVar2[1];
    (&DAT_007039e8)[iVar5 * 3] = puVar2[2];
    iVar4 = (local_18 - (&DAT_007039e4)[iVar5 * 3]) / iVar6;
    (&DAT_007045e4)[iVar5 * 3] = iVar4;
    if ((int)(&DAT_007039e4)[iVar5 * 3] < local_18) {
      iVar3 = 0x1000;
    }
    else {
      iVar3 = -0x1000;
    }
    sVar7 = sVar7 + 1;
    (&DAT_007045e4)[iVar5 * 3] = iVar3 / iVar6 + iVar4;
  } while (sVar7 < 0x100);
  local_3e = 1;
  if (0 < arg2) {
    do {
      sVar7 = 0;
      do {
        iVar6 = (int)sVar7;
        if (local_14 == 0) {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007039e4)[iVar6 * 3];
          local_30 = (&DAT_007039e8)[iVar6 * 3] - iVar1;
          (&DAT_007039e8)[iVar6 * 3] = local_30;
        }
        else {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007045e4)[iVar6 * 3] * (int)local_3e + (&DAT_007039e4)[iVar6 * 3];
          if (0xfbf < local_34) {
            local_34 = 0xfc0;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          iVar4 = iVar1;
          if (local_14 < (int)(&DAT_007039e8)[iVar6 * 3]) {
            iVar4 = -iVar1;
          }
          (&DAT_007039e8)[iVar6 * 3] = (&DAT_007039e8)[iVar6 * 3] + iVar4;
          local_30 = (&DAT_007039e8)[iVar6 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        if (local_30 < 1) {
          local_30 = 0;
        }
        iVar4 = (int)sVar7;
        sVar7 = sVar7 + 1;
        puVar2 = (undefined4 *)FUN_00511120(local_10,&local_38);
        (&DAT_00705500)[iVar4 * 4] = *puVar2;
        (&DAT_00705504)[iVar4 * 4] = puVar2[1];
        iVar6 = iVar4 * 3;
        (&DAT_00705508)[iVar4 * 4] = puVar2[2];
        (&DAT_0070550c)[iVar4 * 4] = puVar2[3];
        *(undefined1 *)(DAT_00532804 + iVar6) = *(undefined1 *)(&DAT_00705500 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 1 + iVar6) = *(undefined1 *)(&DAT_00705504 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 2 + iVar6) = *(undefined1 *)(&DAT_00705508 + iVar4 * 4);
      } while (sVar7 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + 1;
    } while (local_3e <= arg2);
  }
  sVar7 = 0;
  do {
    iVar1 = (int)sVar7;
    sVar7 = sVar7 + 1;
    iVar1 = iVar1 * 3;
    *(undefined1 *)(DAT_00532804 + iVar1) = (undefined1)local_2c;
    *(undefined1 *)(DAT_00532804 + 1 + iVar1) = (undefined1)local_28;
    *(undefined1 *)(DAT_00532804 + 2 + iVar1) = (undefined1)local_24;
  } while (sVar7 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  iVar1 = FUN_0050d560(0,0);
  return iVar1;
}


