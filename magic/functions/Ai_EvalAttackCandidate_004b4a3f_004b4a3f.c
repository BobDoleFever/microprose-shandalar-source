/*
 * Decompiled function: Ai_EvalAttackCandidate_004b4a3f
 * Entry Point: 004b4a3f
 * Size: 2402 bytes
 */
#include "magic.h"


void Ai_EvalAttackCandidate_004b4a3f(undefined4 arg1,uint arg2)

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
  FUN_004f5048(s_CD_struct_0052d390,0xff0000,pHVar1);
  KillTimer(g_MainAppHwnd,DAT_006fdbd4);
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if (DAT_0068a678 != DAT_006ff2d8) {
    DAT_0068a678 = DAT_006ff2d8;
    InvalidateRect(DAT_006a284c,(RECT *)0x0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  local_10 = Ai_Subsystem_004b42dc();
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
      iVar2 = Ai_Subsystem_004b5cbb(local_14,local_24);
      if (iVar2 == DAT_006ff2e8) {
        *(uint *)(&DAT_0068a73c + local_24 * 0x120 + local_14 * 0x5b20) =
             *(uint *)(&DAT_0068a73c + local_24 * 0x120 + local_14 * 0x5b20) & 0xfffffffd;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  if ((arg2 == 0) || ((arg2 & 0x30) != 0)) {
    if (local_10 != 0) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
          local_30 = local_14;
          local_2c = local_24;
          local_20 = Ai_Subsystem_004b5d2e(local_14,local_24);
          local_1c = Ai_Subsystem_004b5c4b(local_14,local_24);
          local_28 = Ai_Subsystem_004b5cbb(local_14,local_24);
          local_18 = Ai_Subsystem_004b6c5b(local_14,local_24);
          local_c = Ai_Subsystem_004b5de4(local_14,local_24);
          if (((local_1c == -1) || (((local_18 & 0x10000) != 0 && (DAT_006fe43c == 0)))) ||
             ((local_1c == DAT_006ff2e0 &&
              (iVar2 = Ai_Subsystem_004b59d9(local_14,local_24), iVar2 == 0)))) {
            SendMessageA(DAT_0069e720,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006fe400,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006a4924,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006b2e2c,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_0069f744,0x40b,(WPARAM)&local_30,0);
            BVar3 = IsWindowVisible(DAT_006b3064);
            if ((BVar3 != 0) || (iVar2 = Ai_Subsystem_004b7629(), iVar2 != 0)) {
              SendMessageA(DAT_006b3064,0x403,(WPARAM)&local_30,0);
              SendMessageA(DAT_006b3064,0x402,(WPARAM)&local_30,0);
            }
          }
          else if (local_20 == 2) {
            SendMessageA(DAT_0069e720,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006fe400,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006a4924,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006b2e2c,0x40b,(WPARAM)&local_30,0);
          }
          else if (local_1c != DAT_006fd3f4) {
            if (local_20 == 1) {
              SendMessageA(DAT_0069e720,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_006fe400,0x40b,(WPARAM)&local_30,0);
              if (((local_c & 0x10) == 0) ||
                 ((local_28 < DAT_00695e94 &&
                  ((*(int *)(&DAT_006b3084 + local_28 * 0x98) != 2 ||
                   (*(int *)(&DAT_006b3088 + local_28 * 0x98) == 0xda)))))) {
                if (local_14 == 0) {
                  local_44 = DAT_006b2e2c;
                  local_3c = DAT_006a4924;
                }
                else {
                  local_44 = DAT_006a4924;
                  local_3c = DAT_006b2e2c;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
              }
              else {
                Ai_Subsystem_004b5f74(&local_38,local_14,local_24);
                while (((uVar4 = Ai_Subsystem_004b5de4(local_38,local_34), (uVar4 & 0x10) != 0 &&
                        (local_28 = Ai_Subsystem_004b5cbb(local_38,local_34), local_28 != -1)) &&
                       ((DAT_00695e94 <= local_28 ||
                        ((*(int *)(&DAT_006b3084 + local_28 * 0x98) == 2 &&
                         (*(int *)(&DAT_006b3088 + local_28 * 0x98) != 0xda))))))) {
                  Ai_Subsystem_004b5f74(&local_38,local_38,local_34);
                }
                if (local_38 == 0) {
                  local_44 = DAT_006b2e2c;
                  local_3c = DAT_006a4924;
                }
                else {
                  local_44 = DAT_006a4924;
                  local_3c = DAT_006b2e2c;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
                iVar2 = FUN_00483139(DAT_006b3064,&local_38,(undefined4 *)0x0,&local_40,
                                     (undefined4 *)0x0);
                if (iVar2 != 0) {
                  SendMessageA(DAT_006b3064,0x406,(WPARAM)&local_30,(LPARAM)local_40);
                  SendMessageA(DAT_006b3064,0x410,(WPARAM)local_40,0);
                  local_8 = 1;
                  iVar2 = Duel_HitTestCardSlot(local_3c,&local_38,(undefined4 *)0x0,&local_40);
                  if (((iVar2 != 0) && (BVar3 = IsWindowVisible(local_40), BVar3 == 0)) &&
                     (iVar2 = Duel_HitTestCardSlot(local_3c,&local_30,(undefined4 *)0x0,&local_40),
                     iVar2 != 0)) {
                    ShowWindow(local_40,0);
                  }
                }
              }
            }
            else if (local_20 == 0) {
              SendMessageA(DAT_006a4924,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_006b2e2c,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_4c = DAT_006fe400;
              }
              else {
                local_4c = DAT_0069e720;
              }
              SendMessageA(local_4c,0x40b,(WPARAM)&local_30,0);
              if (local_14 == 0) {
                local_50 = DAT_0069e720;
              }
              else {
                local_50 = DAT_006fe400;
              }
              SendMessageA(local_50,0x40a,(WPARAM)&local_30,0);
            }
          }
        }
      }
    }
    SendMessageA(DAT_006a4924,0x400,0,0);
    SendMessageA(DAT_006b2e2c,0x400,0,0);
    pHVar1 = GetStockObject(1);
    FUN_004f5048(s_Align_Attack_Spell_0052d39c,0xff0000,pHVar1);
    Ai_Subsystem_004b74b1((undefined4 *)0x0,&local_48);
    if ((local_48 < 0x15) || (0x1d < local_48)) {
      SendMessageA(DAT_006b3064,0x40c,0,0);
    }
    else {
      SendMessageA(DAT_006b3064,0x412,local_8,0);
    }
    SendMessageA(DAT_006fe3fc,0x412,0,0);
  }
  SendMessageA(DAT_006a4924,0x412,0,0);
  SendMessageA(DAT_006b2e2c,0x412,0,0);
  if ((arg2 == 0) || ((arg2 & 0x20) != 0)) {
    pHVar1 = GetStockObject(2);
    FUN_004f5048(s_Refresh_0052d3b0,0xff0000,pHVar1);
    SendMessageA(DAT_0069e720,0x432,0,0);
    SendMessageA(DAT_006fe400,0x432,0,0);
    SendMessageA(DAT_006a4924,0x432,0,0);
    SendMessageA(DAT_006b2e2c,0x432,0,0);
    BVar3 = IsWindowVisible(DAT_006b3064);
    if (BVar3 != 0) {
      SendMessageA(DAT_006b3064,0x432,0,0);
      UpdateWindow(DAT_006b3064);
    }
    BVar3 = IsWindowVisible(DAT_006fe3fc);
    if (BVar3 != 0) {
      SendMessageA(DAT_006fe3fc,0x432,0,0);
      UpdateWindow(DAT_006fe3fc);
    }
    SendMessageA(DAT_0069f744,0x432,0,0);
  }
  SendMessageA(DAT_006b2530,0x432,0,0);
  SendMessageA(DAT_006ff4a8,0x432,0,0);
  SendMessageA(DAT_006b2d60,0x432,0,0);
  SendMessageA(DAT_006ff560,0x432,0,0);
  SendMessageA(DAT_006fe48c,0x432,0,0);
  SendMessageA(DAT_006ff388,0x432,0,0);
  SendMessageA(DAT_006b2e10,0x432,0,0);
  SendMessageA(DAT_006a4928,0x432,0,0);
  pHVar1 = GetStockObject(0);
  FUN_004f5048(&DAT_0052d3b8,0xff0000,pHVar1);
  UpdateWindow(g_MainAppHwnd);
  return;
}


