/*
 * Decompiled function: SpellChain_UpdateLayout
 * Entry Point: 004cffda
 * Size: 1550 bytes
 */
#include "magic.h"


void SpellChain_UpdateLayout(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  BOOL BVar2;
  int iVar3;
  DWORD dwStyle;
  int local_8c;
  int local_88 [2];
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  LONG local_4c;
  tagRECT local_48;
  int local_38;
  int local_34;
  undefined4 local_30;
  tagRECT local_2c;
  tagRECT local_1c;
  HWND local_c;
  LRESULT local_8;
  
  LVar1 = GetWindowLongA(hwnd,0);
  local_4c = GetWindowLongA(hwnd,4);
  local_c = GetDlgItem(hwnd,0);
  local_8 = SendMessageA(local_c,0xe1,0,0);
  if (local_4c == 0) {
    BVar2 = IsWindowVisible(hwnd);
    if ((BVar2 != 0) || (BVar2 = IsWindowVisible(DAT_00565940), BVar2 != 0)) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00565940,0);
      UpdateWindow(DAT_006b2e2c);
    }
    if (arg2 != (LPRECT)0x0) {
      SetRect(arg2,0,0,0,0);
    }
  }
  else {
    GetWindowRect(local_c,&local_2c);
    iVar3 = local_2c.bottom - local_2c.top;
    local_54 = 5;
    local_50 = 5;
    local_70 = 5;
    local_7c = (int)(DAT_006a28b0 + (DAT_006a28b0 >> 0x1f & 3U)) >> 2;
    local_30 = 0;
    for (local_5c = 0; local_5c < local_4c; local_5c = local_5c + 1) {
      if (*(int *)(LVar1 + 0x54 + local_5c * 0x58) != 0) {
        local_30 = 1;
      }
    }
    SetRect(&local_48,500,500,0,0);
    local_58 = local_54;
    local_80 = local_50;
    local_74 = local_50 + DAT_006b2e30 / 2 + DAT_006b2e30;
    for (local_5c = 0; local_5c < local_4c; local_5c = local_5c + 1) {
      SendMessageA(*(HWND *)(LVar1 + local_5c * 0x58),0x401,(WPARAM)local_88,0);
      if (local_88[0] == 0) {
        local_60 = local_74;
        local_34 = (local_74 - DAT_006b2e30) - local_70;
      }
      else {
        local_60 = local_80;
        local_34 = local_80 + DAT_006b2e30 + local_70;
      }
      MoveWindow(*(HWND *)(LVar1 + local_5c * 0x58),local_58,local_60,DAT_006a28b0,DAT_006b2e30,1);
      if (local_58 < local_48.left) {
        local_48.left = local_58;
      }
      if (local_48.right < local_58 + DAT_006a28b0) {
        local_48.right = local_58 + DAT_006a28b0;
      }
      if (local_60 < local_48.top) {
        local_48.top = local_60;
      }
      if (local_48.bottom < local_60 + DAT_006b2e30) {
        local_48.bottom = local_60 + DAT_006b2e30;
      }
      local_78 = local_58;
      for (local_68 = 0; local_68 < *(int *)(LVar1 + 0x54 + local_5c * 0x58);
          local_68 = local_68 + 1) {
        MoveWindow(*(HWND *)(local_68 * 4 + local_5c * 0x58 + 4 + LVar1),local_78,local_34,
                   DAT_006a28b0,DAT_006b2e30,1);
        if (local_78 < local_48.left) {
          local_48.left = local_78;
        }
        if (local_48.right < local_78 + DAT_006a28b0) {
          local_48.right = local_78 + DAT_006a28b0;
        }
        if (local_34 < local_48.top) {
          local_48.top = local_34;
        }
        if (local_48.bottom < local_34 + DAT_006b2e30) {
          local_48.bottom = local_34 + DAT_006b2e30;
        }
        local_78 = local_78 + local_7c;
      }
      local_58 = local_58 + DAT_006a28b0 + 5;
      if (*(int *)(LVar1 + 0x54 + local_5c * 0x58) != 0) {
        local_58 = local_58 + (*(int *)(LVar1 + 0x54 + local_5c * 0x58) + -1) * local_7c;
      }
    }
    local_58 = local_58 + -5 + local_54;
    local_48.right = local_48.right + local_48.left;
    local_48.left = 0;
    local_48.top = 0;
    local_48.bottom = local_48.bottom + local_50;
    local_2c.left = 0;
    local_2c.right = local_58 + -5 + local_54;
    local_2c.top = 0;
    local_2c.bottom = local_50 * 2 + local_74 + DAT_006b2e30 + iVar3;
    BVar2 = 0;
    dwStyle = GetWindowLongA(hwnd,-0x10);
    AdjustWindowRect(&local_2c,dwStyle,BVar2);
    GetWindowRect(DAT_006a4924,&local_1c);
    local_58 = local_1c.left;
    local_60 = local_1c.top - (local_2c.bottom - local_2c.top);
    if (local_60 < 1) {
      local_60 = 0;
    }
    local_64 = local_1c.right - local_1c.left;
    if (local_2c.right - local_2c.left <= local_1c.right - local_1c.left) {
      local_64 = local_2c.right - local_2c.left;
    }
    local_6c = local_2c.bottom - local_2c.top;
    MoveWindow(hwnd,local_1c.left,local_60,local_64,local_6c,1);
    local_c = GetDlgItem(hwnd,0);
    if (local_64 < local_2c.right - local_2c.left) {
      local_38 = 0;
      local_8c = (local_2c.right - local_2c.left) - local_64;
      SendMessageA(local_c,0xe2,0,local_8c);
      SendMessageA(local_c,0x468,1,0);
    }
    else {
      SendMessageA(local_c,0x468,0,0);
    }
    SendMessageA(local_c,0xe3,(WPARAM)&local_38,(LPARAM)&local_8c);
    if (local_8 < local_38) {
      local_8 = local_38;
    }
    if (local_8c < local_8) {
      local_8 = local_8c;
    }
    SendMessageA(local_c,0xe0,0,0);
    SendMessageA(local_c,0x114,CONCAT31((int3)((uint)(local_8 << 0x10) >> 8),4),(LPARAM)local_c);
    BVar2 = IsWindowVisible(hwnd);
    if ((BVar2 == 0) && (BVar2 = IsWindowVisible(DAT_00565940), BVar2 == 0)) {
      ShowWindow(hwnd,5);
      FUN_004f59f7();
    }
    UpdateWindow(hwnd);
    if (arg2 != (LPRECT)0x0) {
      CopyRect(arg2,&local_48);
    }
  }
  return;
}


