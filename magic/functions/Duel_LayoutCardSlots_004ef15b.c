/*
 * Decompiled function: Duel_LayoutCardSlots
 * Entry Point: 004ef15b
 * Size: 1264 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Duel_LayoutCardSlots(HWND hwnd,int *arg_2,int arg_3,int *arg_4,int *arg_5,int arg_6)

{
  int iVar1;
  uint uVar2;
  uint local_24;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((((hwnd != (HWND)0x0) && (arg_2 != (int *)0x0)) &&
      (iVar1 = Ai_Subsystem_004b5cbb(*arg_2,arg_2[1]), iVar1 != -1)) &&
     ((arg_4 != (int *)0x0 && (arg_5 != (int *)0x0)))) {
    local_24 = (uint)(DAT_006a4924 != hwnd);
    GetClientRect(hwnd,&local_14);
    uVar2 = Ai_Subsystem_004b613b(*arg_2,arg_2[1]);
    if (((uVar2 & 2) == 0) || (uVar2 = Ai_Subsystem_004b613b(*arg_2,arg_2[1]), (uVar2 & 1) != 0)) {
      uVar2 = Ai_Subsystem_004b613b(*arg_2,arg_2[1]);
      if ((uVar2 & 1) == 0) {
        iVar1 = Ai_Subsystem_004b5cbb(*arg_2,arg_2[1]);
        if (iVar1 == DAT_00695e94) {
          local_18 = *(int *)(&DAT_006b2ff0 + local_24 * 4);
          local_1c = *(int *)(&DAT_007006c0 + local_24 * 4);
          if (arg_6 != 0) {
            *(int *)(&DAT_007006c0 + local_24 * 4) =
                 *(int *)(&DAT_007006c0 + local_24 * 4) + DAT_006ff67c;
          }
        }
        else {
          local_1c = *(int *)(&DAT_006a49d8 + local_24 * 4);
          local_18 = *(int *)(&DAT_006a29d0 + local_24 * 4) + arg_3;
          iVar1 = Duel_GetHoveredCardSlot(hwnd,arg_2);
          if (0 < iVar1) {
            local_1c = local_1c + DAT_006ff67c * iVar1;
          }
          if (arg_6 != 0) {
            if (iVar1 != 0) {
              *(int *)(&DAT_006a49d8 + local_24 * 4) =
                   *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c * iVar1;
            }
            *(int *)(&DAT_006a49d8 + local_24 * 4) =
                 *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c;
            *(int *)(&DAT_006a49d8 + local_24 * 4) =
                 *(int *)(&DAT_006a49d8 + local_24 * 4) + DAT_006ff67c / 2;
            if ((local_14.bottom + -10) - DAT_006b2e30 < *(int *)(&DAT_006a49d8 + local_24 * 4)) {
              *(int *)(&DAT_006a49d8 + local_24 * 4) = DAT_006b2e30 / 2;
              *(int *)(&DAT_006a29d0 + local_24 * 4) =
                   *(int *)(&DAT_006a29d0 + local_24 * 4) - DAT_006a28b0 / 2;
            }
          }
        }
      }
      else {
        local_1c = *(int *)(&DAT_006b2e80 + local_24 * 4);
        local_18 = *(int *)(&DAT_006a3f68 + local_24 * 4) + arg_3;
        iVar1 = Duel_GetHoveredCardSlot(hwnd,arg_2);
        if (0 < iVar1) {
          local_1c = local_1c + DAT_006ff67c * iVar1 + 5;
        }
        if (arg_6 != 0) {
          if (iVar1 != 0) {
            *(int *)(&DAT_006b2e80 + local_24 * 4) =
                 *(int *)(&DAT_006b2e80 + local_24 * 4) + DAT_006ff67c * iVar1 + 5;
          }
          *(int *)(&DAT_006b2e80 + local_24 * 4) =
               *(int *)(&DAT_006b2e80 + local_24 * 4) + DAT_006ff67c;
          if ((local_14.bottom + -5) - DAT_006b2e30 < *(int *)(&DAT_006b2e80 + local_24 * 4)) {
            *(int *)(&DAT_006b2e80 + local_24 * 4) = DAT_006b2e30 / 2;
            *(int *)(&DAT_006a3f68 + local_24 * 4) =
                 *(int *)(&DAT_006a3f68 + local_24 * 4) - DAT_006a28b0 / 2;
          }
        }
      }
    }
    else {
      local_18 = *(int *)(&DAT_006ff378 + local_24 * 4);
      local_1c = *(int *)(&DAT_00695f00 + local_24 * 4) - arg_3 / 2;
      if (arg_6 != 0) {
        *(int *)(&DAT_006ff378 + local_24 * 4) =
             *(int *)(&DAT_006ff378 + local_24 * 4) + DAT_006a28b0 + _DAT_006ff1a4;
        if (local_14.right + DAT_006a28b0 * -2 < *(int *)(&DAT_006ff378 + local_24 * 4)) {
          DAT_0052fc94 = (DAT_0052fc94 + 1) % 3;
          if (DAT_0052fc94 == 0) {
            *(undefined4 *)(&DAT_006ff378 + local_24 * 4) = 5;
          }
          else if (DAT_0052fc94 == 1) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = DAT_006a28b0 / 3;
          }
          else if (DAT_0052fc94 == 2) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = DAT_006a28b0 / 6;
          }
          else {
            *(int *)(&DAT_006ff378 + local_24 * 4) = DAT_006a28b0 / 2;
          }
          *(int *)(&DAT_00695f00 + local_24 * 4) =
               *(int *)(&DAT_00695f00 + local_24 * 4) - (DAT_006b2e30 + _DAT_006b3068);
        }
        if (*(int *)(&DAT_00695f00 + local_24 * 4) < 0) {
          DAT_00695ed4 = DAT_00695ed4 + (DAT_006b2e30 * 0x28) / 100;
          if ((local_14.bottom + -10) - DAT_006b2e30 < DAT_00695ed4) {
            DAT_00695ed4 = 10;
          }
          *(LONG *)(&DAT_00695f00 + local_24 * 4) = (local_14.bottom - DAT_00695ed4) - DAT_006b2e30;
          if (DAT_0052fc94 == 0) {
            *(undefined4 *)(&DAT_006ff378 + local_24 * 4) = 5;
          }
          else if (DAT_0052fc94 == 1) {
            *(int *)(&DAT_006ff378 + local_24 * 4) = DAT_006a28b0 / 3;
          }
          else {
            *(int *)(&DAT_006ff378 + local_24 * 4) = DAT_006a28b0 / 6;
          }
          _DAT_006ff1a4 = _DAT_006ff1a4 + 10;
        }
      }
    }
  }
  *arg_4 = local_18;
  *arg_5 = local_1c;
  return;
}


