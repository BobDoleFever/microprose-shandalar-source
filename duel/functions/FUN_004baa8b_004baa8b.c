/*
 * Decompiled function: FUN_004baa8b
 * Entry Point: 004baa8b
 * Size: 823 bytes
 */
#include "duel.h"


void FUN_004baa8b(HWND hwnd)

{
  int local_58;
  int local_54;
  int local_50;
  LONG local_4c;
  LONG local_48;
  LONG local_44;
  LONG local_40;
  LONG local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  HWND local_28;
  LONG local_24;
  int local_20;
  int local_1c;
  LONG local_18;
  int local_14;
  LONG local_10;
  int local_c;
  int local_8;
  
  local_1c = 8;
  local_48 = GetWindowLongA(hwnd,4);
  local_24 = GetWindowLongA(hwnd,0);
  local_44 = GetWindowLongA(hwnd,8);
  local_40 = GetWindowLongA(hwnd,0xc);
  local_3c = GetWindowLongA(hwnd,0x10);
  local_4c = GetWindowLongA(hwnd,0x14);
  local_10 = GetWindowLongA(hwnd,0x18);
  local_18 = GetWindowLongA(hwnd,0x1c);
  FUN_004bb037(DAT_0061534c,DAT_0061898c,local_44,local_40,local_3c,local_4c,&local_14,&local_8,
               &local_58,&local_54);
  if ((DAT_006152b0 == hwnd) || ((DAT_00663df4 == hwnd && (DAT_0060cc60 != 0)))) {
    local_20 = local_1c;
    if (local_48 <= local_1c) {
      local_20 = local_48;
    }
    local_38 = local_54 * 2 + local_58 * 2 + DAT_0061534c;
    if (local_48 == 0) {
      local_c = local_8 + local_14;
    }
    else {
      local_c = (local_20 + -1) * DAT_00664d4c + local_8 + local_14 + DAT_0061898c;
    }
    if (0 < local_48) {
      local_2c = local_54 + local_58;
      local_30 = (local_c - local_8) - DAT_0061898c;
      local_34 = local_18;
      local_28 = (HWND)0x0;
      for (local_50 = 1; local_50 <= local_20; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),local_2c,local_30,DAT_0061534c,DAT_0061898c,1)
        ;
        if (local_28 == (HWND)0x0) {
          BringWindowToTop(*(HWND *)(local_24 + local_34 * 4));
        }
        else {
          SetWindowPos(*(HWND *)(local_24 + local_34 * 4),local_28,0,0,0,0,3);
        }
        local_28 = *(HWND *)(local_24 + local_34 * 4);
        if (local_34 == 0) {
          local_34 = local_48;
        }
        local_34 = local_34 + -1;
        local_30 = local_30 - DAT_00664d4c;
      }
      for (local_50 = local_20; local_50 < local_48; local_50 = local_50 + 1) {
        MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
        if (local_34 == 0) {
          local_34 = local_48;
        }
        local_34 = local_34 + -1;
      }
    }
    UpdateWindow(hwnd);
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,local_c,6);
  }
  else {
    local_38 = local_54 * 2 + local_58 * 2 + DAT_0061534c;
    local_c = local_8 + local_14;
    for (local_34 = 0; local_34 < local_48; local_34 = local_34 + 1) {
      MoveWindow(*(HWND *)(local_24 + local_34 * 4),-1,-1,0,0,1);
    }
    SetWindowPos(hwnd,(HWND)0x0,0,0,local_38,local_c,6);
  }
  return;
}


