/*
 * Decompiled function: FUN_0048bba0
 * Entry Point: 0048bba0
 * Size: 487 bytes
 */
#include "magic.h"


undefined4 FUN_0048bba0(int arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int local_b8 [11];
  undefined4 uStack_8c;
  int aiStack_30 [12];
  
  local_b8[0] = 0x100;
  local_b8[1] = 0x200;
  local_b8[2] = 0x400;
  piVar8 = local_b8 + 3;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar8 = 1;
    piVar8 = piVar8 + 1;
  }
  iVar1 = arg_1 + -1;
  aiStack_30[1] = iVar1;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    if (local_b8[iVar3 + 3] == 0) {
      iVar2 = (&DAT_0053aaac)[iVar1 * 2];
    }
    else {
      iVar2 = (&DAT_0053aaa8)[iVar1 * 2];
    }
    iVar1 = iVar2 - DAT_0053aaa0;
    aiStack_30[iVar3 + 2] = iVar1;
    if (iVar1 < 0) {
      iVar1 = 0;
      uVar9 = 0;
      if (0 < iVar4) {
        do {
          uVar9 = uVar9 | local_b8[iVar1 + 3] << ((byte)iVar1 & 0x1f);
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar4);
      }
      iVar6 = 0;
      iVar1 = local_b8[-iVar4];
      if (0 < iVar1) {
        puVar5 = (undefined4 *)(iVar2 * 4 + DAT_0053aaa4);
        do {
          uVar7 = iVar6 << ((byte)iVar4 & 0x1f) | uVar9;
          iVar6 = iVar6 + 1;
          (&DAT_00539e94)[uVar7 * 3] = iVar4;
          (&DAT_00539e90)[uVar7 * 3] = *puVar5;
          (&DAT_00539e98)[uVar7 * 3] = 0xffffffff;
        } while (iVar6 < iVar1);
      }
      local_b8[iVar3 + 4] = 1;
      local_b8[iVar3 + 3] = local_b8[iVar3 + 3] + -1;
LAB_0048bd35:
      iVar2 = iVar3 * 4;
      iVar1 = aiStack_30[iVar3 + 1];
      iVar4 = iVar3;
      if (local_b8[3] < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)((int)local_b8 + iVar2 + 0xc)) break;
        iVar1 = *(int *)((int)aiStack_30 + iVar2);
        *(undefined4 *)((int)local_b8 + iVar2 + 0xc) = 1;
        iVar4 = iVar4 + -1;
        *(int *)((int)local_b8 + iVar2 + 8) = *(int *)((int)local_b8 + iVar2 + 8) + -1;
        iVar2 = iVar2 + -4;
      } while (-1 < local_b8[3]);
    }
    else if (iVar4 == 8) {
      iVar4 = 0;
      uVar9 = 0;
      do {
        uVar9 = uVar9 | local_b8[iVar4 + 3] << ((byte)iVar4 & 0x1f);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
      uStack_8c = 1;
      (&DAT_00539e90)[uVar9 * 3] = 0x7fffffff;
      (&DAT_00539e94)[uVar9 * 3] = 8;
      (&DAT_00539e98)[uVar9 * 3] = iVar1;
      local_b8[iVar3 + 3] = local_b8[iVar3 + 3] + -1;
      goto LAB_0048bd35;
    }
    iVar3 = iVar4;
    if (local_b8[3] < 0) {
      return 0;
    }
  } while( true );
}


