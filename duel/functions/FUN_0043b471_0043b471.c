/*
 * Decompiled function: FUN_0043b471
 * Entry Point: 0043b471
 * Size: 970 bytes
 */
#include "duel.h"


HWND FUN_0043b471(HWND param_1,int param_2)

{
  int iVar1;
  HGDIOBJ pvVar2;
  int iVar3;
  int local_834;
  int local_830;
  int local_82c;
  int local_820;
  int local_818;
  WPARAM local_814 [500];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  uint local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  GetWindowRect(param_1,&local_24);
  local_14.left = local_24.left;
  local_14.top = local_24.top;
  GetClientRect(DAT_00618990,&local_24);
  local_14.right = (local_24.right * 0x4b) / 100;
  local_14.bottom = local_24.bottom;
  GetClientRect(param_1,&local_24);
  local_2c = local_24.bottom;
  iVar1 = (local_24.right * 0x3c) / 100;
  local_44 = 5;
  local_40 = 5;
  local_3c = (((local_14.right - local_14.left) + -10) - local_24.right) / iVar1 + 1;
  local_28 = (uint)(param_1 != DAT_00618978);
  local_30 = CreateWindowExA(0,s_ExpandedGraveyard_004f7800,
                             s_Graveyard_list_004f77dc + ((param_2 != 0) - 1 & 0x10),0x80000000,0,0,
                             0,0,DAT_00618990,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  if (local_30 == (HWND)0x0) {
    local_30 = (HWND)0x0;
  }
  else {
    if (param_2 == 0) {
      pvVar2 = GetStockObject(0);
      SetClassLongA(local_30,-10,(LONG)pvVar2);
    }
    else {
      pvVar2 = GetStockObject(4);
      SetClassLongA(local_30,-10,(LONG)pvVar2);
    }
    local_830 = local_44;
    local_38 = local_40;
    if (param_2 == 0) {
      local_820 = FUN_004486f6(local_814,local_28);
    }
    else {
      local_820 = FUN_00448653(local_814,local_28);
    }
    local_82c = 0;
    local_818 = local_820;
    while (local_818 = local_818 + -1, -1 < local_818) {
      local_34 = CreateWindowExA(0,s_GraveyardCards_004f7838,
                                 s_Graveyard_card_004f7814 + ((param_2 != 0) - 1 & 0x10),0x54000000,
                                 local_830,local_38,local_24.right,local_2c,local_30,(HMENU)0x1,
                                 DAT_00664680,(LPVOID)0x0);
      if (local_34 != (HWND)0x0) {
        local_82c = local_82c + 1;
        SendMessageA(local_34,0x401,local_814[local_818],0);
        local_830 = local_830 + iVar1;
        if (local_82c % local_3c == 0) {
          local_830 = local_44;
          local_38 = local_38 + local_40 + local_2c;
        }
      }
    }
    if (local_820 == 0) {
      DestroyWindow(local_30);
      local_30 = (HWND)0x0;
    }
    else {
      BringWindowToTop(local_30);
      iVar3 = local_3c + -1;
      if (local_820 + -1 <= local_3c + -1) {
        iVar3 = local_820 + -1;
      }
      local_14.right = iVar3 * iVar1 + local_44 * 2 + local_14.left + local_24.right;
      local_834 = local_820 / local_3c;
      if (local_820 % local_3c != 0) {
        local_834 = local_834 + 1;
      }
      local_14.bottom =
           (local_40 + local_2c) * (local_834 + -1) + local_40 * 2 + local_14.top + local_2c;
      GetClientRect(DAT_00618990,&local_24);
      if (local_24.bottom < local_14.bottom) {
        OffsetRect(&local_14,0,-(local_14.bottom - local_24.bottom));
      }
      MoveWindow(local_30,local_14.left,local_14.top,local_14.right - local_14.left,
                 local_14.bottom - local_14.top,1);
      ShowWindow(local_30,5);
    }
  }
  return local_30;
}


