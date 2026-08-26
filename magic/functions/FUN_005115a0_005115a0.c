/*
 * Decompiled function: FUN_005115a0
 * Entry Point: 005115a0
 * Size: 784 bytes
 */
#include "magic.h"


int FUN_005115a0(short arg1,short arg2)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  bool bVar13;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar11 = (int)arg2;
  iVar3 = (int)(0x3fc0 / (longlong)iVar11);
  if (DAT_0070a880 != 8) {
    return (uint)(ushort)((ulonglong)(0x3fc0 / (longlong)iVar11) >> 0x10) << 0x10;
  }
  local_2c = CONCAT11((undefined1)arg1,(undefined1)arg1);
  local_2a = (undefined1)arg1;
  iVar9 = 0x2ff;
  puVar8 = DAT_00532804;
  puVar12 = DAT_00532808;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 1;
    bVar13 = iVar9 != 0;
    iVar9 = iVar9 + -1;
  } while (bVar13);
  sVar2 = 0;
  do {
    iVar9 = (int)sVar2;
    sVar2 = sVar2 + 1;
    puVar10 = (undefined2 *)(DAT_00532804 + iVar9 * 3);
    *puVar10 = local_2c;
    *(undefined1 *)(puVar10 + 1) = (undefined1)arg1;
  } while (sVar2 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  local_10 = (int)arg1;
  local_c = local_10;
  local_8 = local_10;
  puVar4 = (undefined4 *)FUN_00510fc0((int *)&local_2c,&local_10);
  sVar2 = 0;
  local_1c = *puVar4;
  local_18 = puVar4[1];
  local_14 = puVar4[2];
  do {
    iVar9 = (int)sVar2;
    pbVar7 = DAT_00532808 + iVar9 * 3;
    (&DAT_00705500)[iVar9 * 4] = (uint)*pbVar7;
    (&DAT_00705504)[iVar9 * 4] = (uint)pbVar7[1];
    (&DAT_00705508)[iVar9 * 4] = (uint)pbVar7[2];
    puVar4 = (undefined4 *)FUN_00510fc0((int *)&local_2c,&DAT_00705500 + iVar9 * 4);
    (&DAT_007039e0)[iVar9 * 3] = *puVar4;
    (&DAT_007039e4)[iVar9 * 3] = puVar4[1];
    (&DAT_007039e8)[iVar9 * 3] = puVar4[2];
    (&DAT_007045e4)[iVar9 * 3] = (local_18 - (&DAT_007039e4)[iVar9 * 3]) / iVar11;
    if ((int)(&DAT_007039e4)[iVar9 * 3] < local_18) {
      iVar5 = 0x1000;
    }
    else {
      iVar5 = -0x1000;
    }
    sVar2 = sVar2 + 1;
    (&DAT_007045e4)[iVar9 * 3] = iVar5 / iVar11;
  } while (sVar2 < 0x100);
  local_3e = arg2;
  if (0 < arg2) {
    do {
      sVar2 = 0;
      do {
        iVar11 = (int)sVar2;
        if (local_14 == 0) {
          local_38 = (&DAT_007039e0)[iVar11 * 3];
          local_34 = (&DAT_007039e4)[iVar11 * 3];
          local_30 = (&DAT_007039e8)[iVar11 * 3] - local_3e * iVar3;
          if (local_30 < 1) {
            local_30 = 0;
          }
        }
        else {
          local_38 = (&DAT_007039e0)[iVar11 * 3];
          local_34 = (&DAT_007045e4)[iVar11 * 3] * (int)local_3e + (&DAT_007039e4)[iVar11 * 3];
          if (0xfff < local_34) {
            local_34 = 0x1000;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          local_30 = iVar3 * local_3e + (&DAT_007039e8)[iVar11 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        iVar5 = (int)sVar2;
        piVar6 = (int *)FUN_00511120((uint *)&local_2c,&local_38);
        (&DAT_00705500)[iVar5 * 4] = *piVar6;
        (&DAT_00705504)[iVar5 * 4] = piVar6[1];
        iVar9 = iVar5 * 3;
        (&DAT_00705508)[iVar5 * 4] = piVar6[2];
        (&DAT_0070550c)[iVar5 * 4] = piVar6[3];
        iVar11 = (&DAT_00705500)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9] = (char)iVar11;
        iVar11 = (&DAT_00705504)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9 + 1] = (char)iVar11;
        iVar11 = (&DAT_00705508)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        sVar2 = sVar2 + 1;
        DAT_00532804[iVar9 + 2] = (char)iVar11;
      } while (sVar2 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + -1;
    } while (local_3e != 0);
  }
  iVar3 = 0x2ff;
  puVar8 = DAT_00532808;
  puVar12 = DAT_00532804;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 1;
    bVar13 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar13);
  iVar3 = FUN_0050e8b0((short *)&DAT_0070a130);
  return iVar3;
}


