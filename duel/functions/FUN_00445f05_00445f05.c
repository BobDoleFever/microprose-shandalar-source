/*
 * Decompiled function: FUN_00445f05
 * Entry Point: 00445f05
 * Size: 2404 bytes
 */
#include "duel.h"


void FUN_00445f05(undefined4 arg1,uint arg2)

{
  HBRUSH pHVar1;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  HWND local_50;
  HWND local_4c;
  int local_48;
  HWND local_44;
  HWND local_40;
  HWND local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  WPARAM local_8;
  
  pHVar1 = GetStockObject(0);
  FUN_00471e86(s_CD_struct_004f7eb0,0xff0000,pHVar1);
  KillTimer(DAT_00618990,DAT_00663610);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (DAT_00601584 != DAT_0068f0f8) {
    DAT_00601584 = DAT_0068f0f8;
    InvalidateRect(DAT_006152ec,(RECT *)0x0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  local_10 = FUN_004457a2();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
      iVar2 = FUN_00447184(local_14,local_24);
      if (iVar2 == DAT_0068f108) {
        *(uint *)(&DAT_0060162c + local_24 * 0x120 + local_14 * 0x5b20) =
             *(uint *)(&DAT_0060162c + local_24 * 0x120 + local_14 * 0x5b20) & 0xfffffffd;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if ((arg2 == 0) || ((arg2 & 0x30) != 0)) {
    if (local_10 != 0) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
          local_30 = local_14;
          local_2c = local_24;
          local_20 = FUN_004471f7(local_14,local_24);
          local_1c = FUN_00447114(local_14,local_24);
          local_28 = FUN_00447184(local_14,local_24);
          local_18 = FUN_00448124(local_14,local_24);
          local_c = FUN_004472ad(local_14,local_24);
          if (((local_1c == -1) || (((local_18 & 0x10000) != 0 && (DAT_00663e1c == 0)))) ||
             ((DAT_0068f104 == local_1c && (iVar2 = FUN_00446ea2(local_14,local_24), iVar2 == 0))))
          {
            SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006152e0,0x40b,(WPARAM)&local_30,0);
            BVar3 = IsWindowVisible(DAT_00618ab0);
            if ((BVar3 != 0) || (iVar2 = FUN_00448af2(), iVar2 != 0)) {
              SendMessageA(DAT_00618ab0,0x403,(WPARAM)&local_30,0);
              SendMessageA(DAT_00618ab0,0x402,(WPARAM)&local_30,0);
            }
          }
          else if (local_20 == 2) {
            SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
          }
          else if (DAT_0068eee0 != local_1c) {
            if (local_20 == 1) {
              SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
              if (((local_c & 0x10) == 0) ||
                 ((local_28 < DAT_00666720 &&
                  ((*(int *)(&DAT_00618ad4 + local_28 * 0x98) != 2 ||
                   (*(int *)(&DAT_00618ad8 + local_28 * 0x98) == 0xda)))))) {
                if (local_14 == 0) {
                  local_44 = DAT_00618988;
                  local_3c = DAT_00617378;
                }
                else {
                  local_44 = DAT_00617378;
                  local_3c = DAT_00618988;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
              }
              else {
                FUN_0044743d(&local_38,local_14,local_24);
                while (((uVar4 = FUN_004472ad(local_38,local_34), (uVar4 & 0x10) != 0 &&
                        (local_28 = FUN_00447184(local_38,local_34), local_28 != -1)) &&
                       ((DAT_00666720 <= local_28 ||
                        ((*(int *)(&DAT_00618ad4 + local_28 * 0x98) == 2 &&
                         (*(int *)(&DAT_00618ad8 + local_28 * 0x98) != 0xda))))))) {
                  FUN_0044743d(&local_38,local_38,local_34);
                }
                if (local_38 == 0) {
                  local_44 = DAT_00618988;
                  local_3c = DAT_00617378;
                }
                else {
                  local_44 = DAT_00617378;
                  local_3c = DAT_00618988;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
                iVar2 = FUN_004994f8(DAT_00618ab0,&local_38,(undefined4 *)0x0,&local_40,
                                     (undefined4 *)0x0);
                if (iVar2 != 0) {
                  SendMessageA(DAT_00618ab0,0x406,(WPARAM)&local_30,(LPARAM)local_40);
                  SendMessageA(DAT_00618ab0,0x410,(WPARAM)local_40,0);
                  local_8 = 1;
                  iVar2 = FUN_004b26c4(local_3c,&local_38,(undefined4 *)0x0,&local_40);
                  if (((iVar2 != 0) && (BVar3 = IsWindowVisible(local_40), BVar3 == 0)) &&
                     (iVar2 = FUN_004b26c4(local_3c,&local_30,(undefined4 *)0x0,&local_40),
                     iVar2 != 0)) {
                    ShowWindow(local_40,0);
                  }
                }
              }
            }
            else if (local_20 == 0) {
              SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_4c = DAT_00663df4;
              }
              else {
                local_4c = DAT_006152b0;
              }
              SendMessageA(local_4c,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_50 = DAT_006152b0;
              }
              else {
                local_50 = DAT_00663df4;
              }
              SendMessageA(local_50,0x40a,(WPARAM)&local_30,0);
            }
          }
        }
      }
    }
    SendMessageA(DAT_00617378,0x400,0,0);
    SendMessageA(DAT_00618988,0x400,0,0);
    pHVar1 = GetStockObject(1);
    FUN_00471e86(s_Align_Attack_Spell_004f7ebc,0xff0000,pHVar1);
    FUN_0044897a((undefined4 *)0x0,&local_48);
    if ((local_48 < 0x15) || (0x1d < local_48)) {
      SendMessageA(DAT_00618ab0,0x40c,0,0);
    }
    else {
      SendMessageA(DAT_00618ab0,0x412,local_8,0);
    }
    SendMessageA(DAT_00663df0,0x412,0,0);
  }
  SendMessageA(DAT_00617378,0x412,0,0);
  SendMessageA(DAT_00618988,0x412,0,0);
  if ((arg2 == 0) || ((arg2 & 0x20) != 0)) {
    pHVar1 = GetStockObject(2);
    FUN_00471e86(s_Refresh_004f7ed0,0xff0000,pHVar1);
    SendMessageA(DAT_006152b0,0x432,0,0);
    SendMessageA(DAT_00663df4,0x432,0,0);
    SendMessageA(DAT_00617378,0x432,0,0);
    SendMessageA(DAT_00618988,0x432,0,0);
    BVar3 = IsWindowVisible(DAT_00618ab0);
    if (BVar3 != 0) {
      SendMessageA(DAT_00618ab0,0x432,0,0);
      UpdateWindow(DAT_00618ab0);
    }
    BVar3 = IsWindowVisible(DAT_00663df0);
    if (BVar3 != 0) {
      SendMessageA(DAT_00663df0,0x432,0,0);
      UpdateWindow(DAT_00663df0);
    }
    SendMessageA(DAT_006152e0,0x432,0,0);
  }
  SendMessageA(DAT_00618160,0x432,0,0);
  SendMessageA(DAT_00664c28,0x432,0,0);
  SendMessageA(DAT_00618950,0x432,0,0);
  SendMessageA(DAT_00664c34,0x432,0,0);
  SendMessageA(DAT_00663e68,0x432,0,0);
  SendMessageA(DAT_00664c04,0x432,0,0);
  SendMessageA(DAT_00618978,0x432,0,0);
  SendMessageA(DAT_0061737c,0x432,0,0);
  pHVar1 = GetStockObject(0);
  FUN_00471e86(&DAT_004f7ed8,0xff0000,pHVar1);
  UpdateWindow(DAT_00618990);
  return;
}


