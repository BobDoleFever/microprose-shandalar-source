/*
 * Decompiled function: FUN_00481586
 * Entry Point: 00481586
 * Size: 2708 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481586(HWND hwnd)

{
  int iVar1;
  HBRUSH arg_3;
  int iVar2;
  DWORD dwStyle;
  int nWidth;
  BOOL BVar3;
  tagRECT local_b4;
  tagRECT local_a4;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined1 local_5c [8];
  int local_54;
  LONG local_44;
  int local_40;
  LONG local_3c;
  int local_38;
  int local_34;
  int local_30;
  RECT local_2c;
  int local_1c;
  HWND local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_44 = GetWindowLongA(hwnd,0);
  local_3c = GetWindowLongA(hwnd,4);
  local_18 = GetDlgItem(hwnd,0);
  local_8 = SendMessageA(local_18,0xe1,0,0);
  Ai_Subsystem_004b74b1(&local_1c,&local_38);
  if ((((local_38 < 0x15) || (0x1d < local_38)) || (iVar1 = Ai_Subsystem_004b7629(), iVar1 == 0)) ||
     ((local_1c == 1 && (local_3c == 0)))) {
    ShowWindow(DAT_006a283c,0);
    ShowWindow(DAT_006a284c,5);
    ShowWindow(hwnd,0);
    ShowWindow(DAT_00539540,0);
    UpdateWindow(DAT_006b2e2c);
    SendMessageA(local_18,0x468,0,0);
    SendMessageA(DAT_006b3064,0x40c,0,0);
    SendMessageA(DAT_006a4924,0x401,0,0);
    SendMessageA(DAT_006b2e2c,0x401,0,0);
    DAT_006b2ff4 = 5;
    _DAT_006b2ff0 = 5;
    _DAT_007006c0 = DAT_006b2e30 / 2;
    DAT_007006c4 = _DAT_007006c0;
  }
  else {
    arg_3 = GetStockObject(1);
    FUN_004f5048(s_LayoutAttackCards_00526da4,0xff00ff,arg_3);
    DAT_00539554 = 10;
    DAT_00539584 = 10;
    _DAT_00539560 = (DAT_006a28b0 * 0xf) / 100;
    _DAT_00539538 = 5;
    local_34 = 2;
    if (DAT_00539544 == (HANDLE)0x0) {
      local_40 = GetSystemMetrics(3);
      local_40 = local_40 * 2;
    }
    else {
      GetObjectA(DAT_00539544,0x18,local_5c);
      iVar1 = GetSystemMetrics(3);
      if (iVar1 * 2 < local_54 / 2) {
        local_40 = local_54 / 2;
      }
      else {
        local_40 = GetSystemMetrics(3);
        local_40 = local_40 * 2;
      }
    }
    local_70 = 0;
    local_60 = 0;
    for (local_64 = 0; local_64 < local_3c; local_64 = local_64 + 1) {
      for (local_68 = 0; local_68 < *(int *)(local_44 + 0xcc + local_64 * 0x19c);
          local_68 = local_68 + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44));
        if ((iVar1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44)),
           local_70 < local_6c)) {
          local_70 = local_6c;
        }
      }
      for (local_68 = 0; local_68 < *(int *)(local_44 + 0x198 + local_64 * 0x19c);
          local_68 = local_68 + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44));
        if ((iVar1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44)
                                   ), local_60 < local_6c)) {
          local_60 = local_6c;
        }
      }
    }
    if (local_1c == 0) {
      local_30 = local_70;
      local_14 = local_60;
    }
    else {
      local_14 = local_70;
      local_30 = local_60;
    }
    iVar1 = local_34;
    if (local_34 <= local_14) {
      iVar1 = local_14;
    }
    DAT_00539570 = iVar1 * DAT_006ff67c + DAT_00539584;
    iVar1 = local_34;
    if (local_34 <= local_30) {
      iVar1 = local_30;
    }
    DAT_00539574 = iVar1 * DAT_006ff67c + DAT_00539570 + local_40 + _DAT_00539538 * 2 + DAT_006b2e30
    ;
    local_c = DAT_006a28b0 / 3;
    local_10 = DAT_006a28b0 / 3;
    SetWindowPos(local_18,(HWND)0x0,0,DAT_00539570 + _DAT_00539538 + DAT_006b2e30,0,0,5);
    local_80 = DAT_00539554 - local_8;
    iVar1 = local_34;
    if (local_34 <= local_14) {
      iVar1 = local_14;
    }
    local_2c.top = DAT_00539570 - iVar1 * DAT_006ff67c;
    local_2c.bottom = DAT_006b2e30 + DAT_00539574;
    if (local_1c == 0) {
      local_88 = DAT_00539574;
      local_7c = DAT_00539570;
    }
    else {
      local_88 = DAT_00539570;
      local_7c = DAT_00539574;
    }
    local_2c.left = local_80;
    local_2c.right = local_80;
    for (local_84 = 0; local_84 < local_3c; local_84 = local_84 + 1) {
      local_74 = local_80;
      local_78 = local_80;
      local_90 = 0;
      for (local_8c = 0; local_8c < *(int *)(local_44 + 0xcc + local_84 * 0x19c);
          local_8c = local_8c + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44));
        if (iVar1 == 0) {
          local_78 = local_90 * local_c + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44),local_78,local_88,
                     DAT_006a28b0,DAT_006b2e30,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_78 + DAT_006a28b0) {
            local_2c.right = local_78 + DAT_006a28b0;
          }
        }
      }
      local_90 = 0;
      for (local_8c = 0; local_8c < *(int *)(local_44 + 0x198 + local_84 * 0x19c);
          local_8c = local_8c + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44));
        if (iVar1 == 0) {
          local_74 = local_90 * local_10 + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44),local_74,local_7c,
                     DAT_006a28b0,DAT_006b2e30,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_74 + DAT_006a28b0) {
            local_2c.right = local_74 + DAT_006a28b0;
          }
        }
      }
      iVar1 = local_74;
      if (local_74 <= local_78) {
        iVar1 = local_78;
      }
      local_80 = iVar1 + _DAT_00539560 + DAT_006a28b0;
    }
    iVar1 = DAT_006a28b0 / 3;
    local_2c.left = local_2c.left - DAT_00539554;
    local_2c.right = local_2c.right + DAT_00539554;
    local_2c.top = local_2c.top - DAT_00539584;
    local_2c.bottom = local_2c.bottom + DAT_00539584;
    iVar2 = DAT_00539554 * 2 + DAT_006a28b0;
    if (local_2c.right - local_2c.left < iVar2) {
      local_2c.right = local_2c.left + iVar2;
    }
    dwStyle = GetWindowLongA(hwnd,-0x10);
    CopyRect(&local_b4,&local_2c);
    AdjustWindowRect(&local_b4,dwStyle,0);
    GetWindowRect(DAT_006a4924,&local_a4);
    iVar2 = local_a4.top - (local_b4.bottom - local_b4.top);
    if (iVar2 < 6) {
      iVar2 = 5;
    }
    nWidth = (local_a4.right - local_a4.left) - iVar1;
    if (local_b4.right - local_b4.left <= nWidth) {
      nWidth = local_b4.right - local_b4.left;
    }
    MoveWindow(DAT_006b2e24,local_a4.left,iVar2,iVar1,local_b4.bottom - local_b4.top,1);
    MoveWindow(hwnd,iVar1 + local_a4.left,iVar2,nWidth,local_b4.bottom - local_b4.top,1);
    GetClientRect(hwnd,&local_b4);
    SetWindowPos(local_18,(HWND)0x0,0,0,local_b4.right,local_40,6);
    UpdateWindow(DAT_006b2e2c);
    UpdateWindow(DAT_006a4924);
    GetClientRect(hwnd,&local_b4);
    if (local_b4.right < local_2c.right - local_2c.left) {
      iVar1 = (local_2c.right - local_2c.left) - local_b4.right;
      SendMessageA(local_18,0xe2,0,iVar1);
      SendMessageA(local_18,0x468,1,0);
      if (local_8 < 0) {
        local_8 = 0;
      }
      if (iVar1 < local_8) {
        local_8 = iVar1;
      }
      SendMessageA(hwnd,0x114,CONCAT31((int3)((uint)(local_8 << 0x10) >> 8),4),(LPARAM)local_18);
    }
    else {
      SendMessageA(local_18,0x468,0,0);
      local_8 = 0;
      SendMessageA(hwnd,0x114,4,(LPARAM)local_18);
    }
    BVar3 = IsWindowVisible(hwnd);
    if ((BVar3 == 0) && (BVar3 = IsWindowVisible(DAT_00539540), BVar3 == 0)) {
      FUN_00482d6f(hwnd);
      ShowWindow(DAT_006a283c,5);
      ShowWindow(DAT_006a284c,0);
      ShowWindow(hwnd,5);
      UpdateWindow(DAT_006b2e24);
      UpdateWindow(hwnd);
      UpdateWindow(DAT_006a283c);
      FUN_004f59f7();
    }
    UpdateWindow(hwnd);
    UpdateWindow(DAT_006b2e2c);
  }
  return;
}


