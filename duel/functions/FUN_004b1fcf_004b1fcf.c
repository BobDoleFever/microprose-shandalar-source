/*
 * Decompiled function: FUN_004b1fcf
 * Entry Point: 004b1fcf
 * Size: 1271 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b1fcf(HWND hwnd,int *arg_2,int arg_3,int *arg_4,int *arg_5,int arg_6)

{
  int iVar1;
  uint uVar2;
  uint local_24;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((((hwnd != (HWND)0x0) && (arg_2 != (int *)0x0)) &&
      (iVar1 = FUN_00447184(*arg_2,arg_2[1]), iVar1 != -1)) &&
     ((arg_4 != (int *)0x0 && (arg_5 != (int *)0x0)))) {
    local_24 = (uint)(DAT_00617378 != hwnd);
    GetClientRect(hwnd,&local_14);
    uVar2 = FUN_00447604(*arg_2,arg_2[1]);
    if (((uVar2 & 2) == 0) || (uVar2 = FUN_00447604(*arg_2,arg_2[1]), (uVar2 & 1) != 0)) {
      uVar2 = FUN_00447604(*arg_2,arg_2[1]);
      if ((uVar2 & 1) == 0) {
        iVar1 = FUN_00447184(*arg_2,arg_2[1]);
        if (iVar1 == DAT_00666720) {
          local_18 = *(int *)(&DAT_00618aa8 + local_24 * 4);
          local_1c = *(int *)(&DAT_00664da0 + local_24 * 4);
          if (arg_6 != 0) {
            *(int *)(&DAT_00664da0 + local_24 * 4) =
                 *(int *)(&DAT_00664da0 + local_24 * 4) + DAT_00664d4c;
          }
        }
        else {
          local_1c = *(int *)(&DAT_00617428 + local_24 * 4);
          local_18 = *(int *)(&DAT_00615460 + local_24 * 4) + arg_3;
          iVar1 = FUN_004b27eb(hwnd,arg_2);
          if (0 < iVar1) {
            local_1c = local_1c + DAT_00664d4c * iVar1;
          }
          if (arg_6 != 0) {
            if (iVar1 != 0) {
              *(int *)(&DAT_00617428 + local_24 * 4) =
                   *(int *)(&DAT_00617428 + local_24 * 4) + DAT_00664d4c * iVar1;
            }
            *(int *)(&DAT_00617428 + local_24 * 4) =
                 *(int *)(&DAT_00617428 + local_24 * 4) + DAT_00664d4c;
            *(int *)(&DAT_00617428 + local_24 * 4) =
                 *(int *)(&DAT_00617428 + local_24 * 4) + DAT_00664d4c / 2;
            if ((local_14.bottom + -10) - DAT_0061898c < *(int *)(&DAT_00617428 + local_24 * 4)) {
              *(int *)(&DAT_00617428 + local_24 * 4) = DAT_0061898c / 2;
              *(int *)(&DAT_00615460 + local_24 * 4) =
                   *(int *)(&DAT_00615460 + local_24 * 4) - DAT_0061534c / 2;
            }
          }
        }
      }
      else {
        local_1c = *(int *)(&DAT_00618998 + local_24 * 4);
        local_18 = *(int *)(&DAT_006169f8 + local_24 * 4) + arg_3;
        iVar1 = FUN_004b27eb(hwnd,arg_2);
        if (0 < iVar1) {
          local_1c = local_1c + DAT_00664d4c * iVar1 + 5;
        }
        if (arg_6 != 0) {
          if (iVar1 != 0) {
            *(int *)(&DAT_00618998 + local_24 * 4) =
                 *(int *)(&DAT_00618998 + local_24 * 4) + DAT_00664d4c * iVar1 + 5;
          }
          *(int *)(&DAT_00618998 + local_24 * 4) =
               *(int *)(&DAT_00618998 + local_24 * 4) + DAT_00664d4c;
          if ((local_14.bottom + -5) - DAT_0061898c < *(int *)(&DAT_00618998 + local_24 * 4)) {
            *(int *)(&DAT_00618998 + local_24 * 4) = DAT_0061898c / 2;
            *(int *)(&DAT_006169f8 + local_24 * 4) =
                 *(int *)(&DAT_006169f8 + local_24 * 4) - DAT_0061534c / 2;
          }
        }
      }
    }
    else {
      local_18 = *(int *)(&DAT_00664bf8 + local_24 * 4);
      local_1c = *(int *)(&DAT_0060ccb0 + local_24 * 4) - arg_3 / 2;
      if (arg_6 != 0) {
        *(int *)(&DAT_00664bf8 + local_24 * 4) =
             *(int *)(&DAT_00664bf8 + local_24 * 4) + DAT_0061534c + _DAT_00664a58;
        if (local_14.right + DAT_0061534c * -2 < *(int *)(&DAT_00664bf8 + local_24 * 4)) {
          DAT_00506594 = (DAT_00506594 + 1) % 3;
          if (DAT_00506594 == 0) {
            *(undefined4 *)(&DAT_00664bf8 + local_24 * 4) = 5;
          }
          else if (DAT_00506594 == 1) {
            *(int *)(&DAT_00664bf8 + local_24 * 4) = DAT_0061534c / 3;
          }
          else if (DAT_00506594 == 2) {
            *(int *)(&DAT_00664bf8 + local_24 * 4) = DAT_0061534c / 6;
          }
          else {
            *(int *)(&DAT_00664bf8 + local_24 * 4) = DAT_0061534c / 2;
          }
          *(int *)(&DAT_0060ccb0 + local_24 * 4) =
               *(int *)(&DAT_0060ccb0 + local_24 * 4) - (DAT_0061898c + _DAT_00618ab4);
        }
        if (*(int *)(&DAT_0060ccb0 + local_24 * 4) < 0) {
          DAT_0060cc7c = DAT_0060cc7c + (DAT_0061898c * 0x28) / 100;
          if ((local_14.bottom + -10) - DAT_0061898c < DAT_0060cc7c) {
            DAT_0060cc7c = 10;
          }
          *(LONG *)(&DAT_0060ccb0 + local_24 * 4) = (local_14.bottom - DAT_0060cc7c) - DAT_0061898c;
          if (DAT_00506594 == 0) {
            *(undefined4 *)(&DAT_00664bf8 + local_24 * 4) = 5;
          }
          else if (DAT_00506594 == 1) {
            *(int *)(&DAT_00664bf8 + local_24 * 4) = DAT_0061534c / 3;
          }
          else {
            *(int *)(&DAT_00664bf8 + local_24 * 4) = DAT_0061534c / 6;
          }
          _DAT_00664a58 = _DAT_00664a58 + 10;
        }
      }
    }
  }
  *arg_4 = local_18;
  *arg_5 = local_1c;
  return;
}


