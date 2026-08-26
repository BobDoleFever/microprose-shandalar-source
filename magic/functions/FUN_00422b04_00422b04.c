/*
 * Decompiled function: FUN_00422b04
 * Entry Point: 00422b04
 * Size: 1026 bytes
 */
#include "magic.h"


void FUN_00422b04(int arg_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_38;
  uint local_34;
  int local_2c [6];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_1 == 0x12) {
    local_38 = 1;
  }
  else {
    local_38 = 2;
  }
  local_2c[0] = 0xbf;
  local_2c[1] = 0xbc;
  local_2c[2] = 0xb7;
  local_2c[3] = 0xf4;
  local_2c[4] = 0xf6;
  local_34 = arg_1 * 3;
  iVar8 = 0x80;
  iVar7 = 0;
  piVar6 = (int *)g_DisplaySurfaceWork;
  DVar1 = Ai_Util_004c3bc4(0x7f);
  uVar2 = Ai_Util_004c3bc4(0x173);
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0x154,uVar2,DVar1,piVar6,iVar7,iVar8);
  for (local_14 = 0; local_14 < local_38; local_14 = local_14 + 1) {
    local_10 = 0;
    for (; (local_10 < 3 && ((int)local_34 < 0x37)); local_34 = local_34 + 1) {
      if ((*(int *)(&DAT_00538858 + local_34 * 8) != 0) ||
         ((*(int *)(&DAT_0053885c + local_34 * 8) != 0 || (DAT_0067b9a4 != 0)))) {
        local_c = *(int *)(&DAT_00538858 + local_34 * 8);
        local_2c[5] = *(int *)(&DAT_0053885c + local_34 * 8);
        iVar7 = local_c + local_2c[5];
        if (iVar7 < 2) {
          iVar7 = 1;
        }
        iVar7 = (local_c * 100) / iVar7;
        if (local_c < local_2c[5]) {
          if ((local_2c[5] - local_c < 6) || (0x19 < iVar7)) {
            if ((local_c + local_2c[5] < 5) || (0x28 < iVar7)) {
              local_8 = 2;
            }
            else {
              local_8 = 1;
            }
          }
          else {
            local_8 = 0;
          }
        }
        else if ((local_c - local_2c[5] < 6) || (iVar7 < 0x4b)) {
          if ((local_c + local_2c[5] < 5) || (iVar7 < 0x3d)) {
            local_8 = 2;
          }
          else {
            local_8 = 3;
          }
        }
        else {
          local_8 = 4;
        }
        iVar8 = Ai_Util_004c3bc4(local_14 << 6);
        iVar8 = iVar8 + 0x80;
        iVar3 = Ai_Util_004c3bc4(0x7c);
        iVar3 = iVar3 * local_10;
        iVar7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        piVar6 = (int *)g_DisplaySurfaceWork;
        iVar4 = Ai_Util_004c3bc4(3);
        DVar1 = (iVar7 + -2) - iVar4;
        uVar2 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) - 2;
        iVar7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        uVar5 = (int)local_34 >> 0x1f;
        iVar4 = Ai_Util_004c3bc4(3);
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,
                     *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) *
                     (((local_34 ^ uVar5) - uVar5 & 7 ^ uVar5) - uVar5) + 1,
                     iVar7 * ((int)(local_34 + (uVar5 & 7)) >> 3) + iVar4 + 1,uVar2,DVar1,piVar6,
                     iVar3,iVar8);
        *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 4;
        iVar7 = Ai_Util_004c3bc4(local_14 * 0x40 + -3);
        iVar8 = Ai_Util_004c3bc4(0x20);
        iVar3 = iVar7 + iVar8 + 0x80;
        iVar7 = Ai_Util_004c3bc4(0x7c);
        iVar7 = iVar7 * local_10;
        iVar8 = Ai_Util_004c3bc4(0x5e);
        FUN_0040d269((int)g_DisplaySurfaceWork,local_2c[local_8],iVar7 + iVar8,iVar3);
        *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 1;
        iVar7 = Ai_Util_004c3bc4(local_14 << 6);
        iVar8 = Ai_Util_004c3bc4(0x36);
        iVar3 = iVar7 + iVar8 + 0x80;
        iVar7 = Ai_Util_004c3bc4(0x7c);
        iVar7 = iVar7 * local_10;
        iVar8 = Ai_Util_004c3bc4(0x3e);
        FUN_0040d269((int)g_DisplaySurfaceWork,0xb7,iVar7 + iVar8,iVar3);
      }
      local_10 = local_10 + 1;
    }
  }
  iVar7 = Ai_Util_004c3bc4(0x43);
  iVar8 = Ai_Util_004c3bc4(0xf6);
  piVar6 = (int *)g_DisplaySurfaceScreen;
  iVar3 = Ai_Util_004c3bc4(0x40);
  DVar1 = iVar3 * 2 - 2;
  iVar3 = Ai_Util_004c3bc4(0x7c);
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0x80,iVar3 * 3 - 2,DVar1,piVar6,iVar8,iVar7);
  DAT_00538ac8 = arg_1;
  return;
}


