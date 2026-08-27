/*
 * NedCard/Palette.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 110
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Palette_AllocErrorDiffusionTable
 * Entry Point: 00494c30
 * Size: 311 bytes
 */


undefined4 Palette_AllocErrorDiffusionTable(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *local_10;
  int local_c;
  
  iVar5 = *(int *)(&DAT_0052a210 + arg1 * 4);
  local_c = 0;
  if (0 < *(int *)(&DAT_0052a1c0 + arg1 * 4)) {
    local_10 = (int *)(&DAT_0052a244 + arg1 * 0xc0);
    do {
      iVar1 = local_10[-3];
      iVar2 = *(int *)(arg2 + iVar1 * 4);
      if (iVar2 == 0) {
        pvVar3 = malloc(0x800);
        *(void **)(arg2 + iVar1 * 4) = pvVar3;
        if (pvVar3 == (void *)0x0) {
          assert(s_deltas_EVal_____NULL_0052afe0,s_G__NewMagic_sources_NedCard_Pale_0052aff8,0x4fd);
        }
        iVar6 = -0x400;
        iVar2 = ((iVar5 >> 1) + iVar1 * -0x100) * 0x100;
        do {
          iVar6 = iVar6 + 4;
          *(int *)(*(int *)(arg2 + iVar1 * 4) + 0x3fc + iVar6) =
               iVar2 / *(int *)(&DAT_0052a210 + arg1 * 4);
          iVar2 = iVar2 + iVar1 * 0x100;
        } while (iVar6 < 0x400);
        iVar2 = *(int *)(arg2 + iVar1 * 4) + 0x3fc;
      }
      else {
        iVar2 = iVar2 + 0x400;
      }
      *local_10 = iVar2;
      local_10 = local_10 + 4;
      local_c = local_c + 1;
    } while (local_c < *(int *)(&DAT_0052a1c0 + arg1 * 4));
  }
  iVar5 = *(int *)(&DAT_0052a1c0 + arg1 * 4);
  if (0 < iVar5) {
    piVar4 = (int *)(&DAT_0052a904 + arg1 * 0xc0);
    do {
      iVar5 = iVar5 + -1;
      *piVar4 = *(int *)(arg2 + piVar4[-3] * 4) + 0x3fc;
      piVar4 = piVar4 + 4;
    } while (iVar5 != 0);
  }
  return 0;
}



/*
 * Decompiled function: Palette_DitherScanline
 * Entry Point: 004950b0
 * Size: 864 bytes
 */


undefined4 Palette_DitherScanline(int player,int card_slot,int arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  uint local_58;
  int local_4c;
  int local_48;
  int local_40;
  undefined *local_3c;
  int local_38;
  int local_18 [6];
  
  local_4c = 1;
  local_3c = &DAT_0052a238 + player * 0xc0;
  if (DAT_0054b324 == 0) {
    iVar7 = -0x200;
    do {
      if (iVar7 < 0) {
LAB_0049510c:
        PTR_DAT_0052afb8[iVar7] = 0;
      }
      else if (iVar7 < 0x100) {
        PTR_DAT_0052afb8[iVar7] = (char)iVar7;
      }
      else {
        if (iVar7 < 0) goto LAB_0049510c;
        PTR_DAT_0052afb8[iVar7] = 0xff;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x200);
    DAT_0054b324 = 1;
  }
  if (player != DAT_0052afc0) {
    puVar16 = &DAT_00675ed0;
    do {
      if ((void *)*puVar16 != (void *)0x0) {
        free((void *)*puVar16);
        *puVar16 = 0;
      }
      puVar16 = puVar16 + 1;
    } while (puVar16 < &DAT_00675fd4);
    Palette_AllocErrorDiffusionTable(player,0x675ed0);
    DAT_0052afc0 = player;
  }
  puVar16 = &DAT_0064b8c0;
  piVar10 = local_18 + 1;
  do {
    piVar11 = piVar10 + 1;
    puVar17 = puVar16;
    for (iVar7 = 0x2018; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar17 = 0;
      puVar17 = puVar17 + 1;
    }
    puVar17 = puVar16 + 10;
    puVar16 = puVar16 + 0x2018;
    *piVar10 = (int)puVar17;
    piVar10 = piVar11;
  } while (piVar11 < &stack0x00000000);
  iVar7 = *(int *)(&DAT_0052a1c0 + player * 4);
  if (0 < arg_4) {
    local_38 = arg_4;
    local_18[0] = arg_6 + arg_5 * 3;
    do {
      if (local_4c < 1) {
        local_48 = -1;
        local_40 = -3;
        iVar8 = arg_5 + -1;
      }
      else {
        iVar8 = 0;
        local_40 = 3;
        local_48 = arg_5;
      }
      iVar13 = iVar8 * 3;
      for (; local_48 != iVar8; iVar8 = iVar8 + local_4c) {
        uVar5 = *(uint *)(iVar13 + arg_3);
        *(uint *)(iVar13 + arg_3) = uVar5 & 0xff000000;
        psVar1 = (short *)(local_18[1] + iVar8 * 8);
        bVar2 = PTR_DAT_0052afb8[(int)(*psVar1 >> 8) + (uVar5 & 0xff)];
        bVar3 = PTR_DAT_0052afb8[(int)(psVar1[1] >> 8) + (uVar5 >> 8 & 0xff)];
        bVar4 = PTR_DAT_0052afb8[(int)(psVar1[2] >> 8) + ((uVar5 & 0xff0000) >> 0x10)];
        uVar14 = (uint)bVar3 << 8 | (uint)bVar4 << 0x10 | (uint)bVar2;
        if (uVar14 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = 0xffffff;
          if (uVar14 != 0xffffff) {
            uVar9 = uVar14 & 0xf8f8f8;
          }
        }
        local_58 = uVar9 >> 8 & 0xff;
        *(uint *)(iVar13 + arg_3) = uVar5 & 0xff000000 | uVar9;
        iVar12 = bVar3 - local_58;
        puVar15 = local_3c;
        local_58 = iVar7;
        if (0 < iVar7) {
          do {
            iVar6 = *(int *)(puVar15 + 0xc);
            psVar1 = (short *)(local_18[*(int *)(puVar15 + 8) + 1] +
                              (*(int *)(puVar15 + 4) + iVar8) * 8);
            *psVar1 = *psVar1 + (short)*(undefined4 *)(iVar6 + ((uint)bVar2 - (uVar9 & 0xff)) * 4);
            psVar1[1] = psVar1[1] + (short)*(undefined4 *)(iVar6 + iVar12 * 4);
            psVar1[2] = psVar1[2] +
                        (short)*(undefined4 *)(iVar6 + ((uint)bVar4 - (uVar9 >> 0x10)) * 4);
            local_58 = local_58 + -1;
            puVar15 = puVar15 + 0x10;
          } while (local_58 != 0);
        }
        iVar13 = iVar13 + local_40;
      }
      Palette_RotateDitherBuffers(local_18 + 1,*(int *)(&DAT_0052a1e8 + player * 4));
      puVar16 = (undefined4 *)(local_18[*(int *)(&DAT_0052a1e8 + player * 4)] + -0x28);
      for (iVar8 = (arg_5 + 10U & 0x1fffffff) * 2; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar16 = 0;
        puVar16 = puVar16 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar16 = 0;
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      if (card_slot != 0) {
        local_4c = -local_4c;
        local_3c = &DAT_0052a238 + ((uint)(local_4c == -1) * 9 + player) * 0xc0;
      }
      arg_3 = arg_3 + local_18[0];
      local_38 = local_38 + -1;
    } while (local_38 != 0);
  }
  return 1;
}



/*
 * Decompiled function: Palette_Util_00495410
 * Entry Point: 00495410
 * Size: 25 bytes
 */


void Palette_Util_00495410(void)

{
  ColorOctree_FreeTree(DAT_0054aefc);
  DAT_0054aefc = (int *)0x0;
  return;
}



/*
 * Decompiled function: Palette_Color_00495430
 * Entry Point: 00495430
 * Size: 1017 bytes
 */


undefined4 Palette_Color_00495430(char *str_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined4 *arg_3;
  BITMAPINFO *arg_4;
  undefined4 *arg_5;
  char *pcVar4;
  undefined4 *arg_6;
  char *pcVar5;
  int *arg_7;
  char local_118 [264];
  undefined4 local_10;
  HDC local_c;
  int local_8;
  
  local_10 = 1;
  FUN_004f391e(&DAT_006807a0);
  _chdir(&DAT_006807a0);
  strcpy(&DAT_006ff1b0,&DAT_006807a0);
  strcat(&DAT_006ff1b0,s__PlayDeck_0052b030);
  strcpy(&DAT_006a4a50,&DAT_006807a0);
  strcat(&DAT_006a4a50,s__Faces_0052b03c);
  strcpy(&DAT_006808d0,&DAT_006807a0);
  strcat(&DAT_006808d0,s__CardArt_0052b044);
  strcpy(&DAT_006b2e90,&DAT_006807a0);
  strcat(&DAT_006b2e90,s__DuelArt_0052b050);
  strcpy(&DAT_00696910,&DAT_006807a0);
  strcat(&DAT_00696910,s__DuelSounds_0052b05c);
  strcpy(&DAT_006ff570,&DAT_006b2e90);
  strcat(&DAT_006ff570,s__Duel_dat_0052b068);
  strcpy(&DAT_006a28c0,&DAT_006807a0);
  strcat(&DAT_006a28c0,s__SaveGame_0052b074);
  _mkdir(&DAT_006a28c0);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__CARDS_DAT_0052b080);
  DAT_006a49f4 = FUN_004f6180(local_118);
  if (DAT_006a49f4 == 0) {
    local_10 = 0;
    pcVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_card_data_file_0052b08c;
    sVar1 = strlen(str_1);
    sprintf(str_1 + sVar1,pcVar4,pcVar5);
  }
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__LEGACY_CSV_0052b0b4);
  iVar2 = FUN_004f6b33(local_118);
  if (iVar2 == 0) {
    local_10 = 0;
    pcVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_special_card_d_0052b0c0;
    sVar1 = strlen(str_1);
    sprintf(str_1 + sVar1,pcVar4,pcVar5);
  }
  Palette_Subsystem_004966a0();
  local_c = GetDC((HWND)0x0);
  if (local_c == (HDC)0x0) {
    local_10 = 0;
    strcat(str_1,s_Not_enough_system_resources_to_d_0052b120);
  }
  else {
    iVar2 = GetDeviceCaps(local_c,0xc);
    iVar3 = GetDeviceCaps(local_c,0xe);
    DAT_006ff554 = iVar2 * iVar3;
    ReleaseDC((HWND)0x0,local_c);
  }
  iVar2 = FUN_004f45da();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_create_the_palette_0052b160);
  }
  arg_7 = &DAT_006b2e1c;
  arg_6 = (undefined4 *)&DAT_007006dc;
  arg_5 = &DAT_006ff384;
  arg_4 = (BITMAPINFO *)&DAT_006a4a20;
  arg_3 = &g_HdcBackBuffer;
  iVar2 = GetSystemMetrics(1);
  iVar3 = GetSystemMetrics(0);
  iVar2 = FUN_004f39a4(iVar3,iVar2,arg_3,arg_4,arg_5,arg_6,arg_7);
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_create_the_app_wide_mem_0052b180);
  }
  iVar2 = Palette_Color_0049ae00();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_initialize_for_card_dra_0052b1b4);
  }
  iVar2 = FUN_004f3880();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_initialize_for_utility_d_0052b1dc);
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006fefb0 + local_8 * 0x18) = 0;
  }
  DAT_00680778 = 0;
  for (local_8 = 0; local_8 < 2000; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00696a20 + local_8 * 0x10) = 0;
  }
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006a3f80 + local_8 * 0x18) = 0;
  }
  DAT_006fe404 = 0;
  Glue_Timer_004cd63b();
  return local_10;
}



/*
 * Decompiled function: Palette_Subsystem_00495829
 * Entry Point: 00495829
 * Size: 136 bytes
 */


void Palette_Subsystem_00495829(void)

{
  undefined4 local_8;
  
  Mem_AllocOrFree_004f6b02();
  Mem_AllocOrFree_004f6d88();
  FUN_004f48cb();
  FUN_004f3b2c(g_HdcBackBuffer,DAT_006ff384);
  DAT_006ff384 = (HGDIOBJ)0x0;
  g_HdcBackBuffer = (HDC)0x0;
  FUN_004f38dd();
  Palette_Subsystem_0049b8f5();
  FUN_00478a56();
  for (local_8 = 0; local_8 < DAT_006a49f4; local_8 = local_8 + 1) {
    FUN_0046c1b3(local_8);
  }
  FUN_0046c859();
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004958b1
 * Entry Point: 004958b1
 * Size: 167 bytes
 */


int Palette_Subsystem_004958b1(int player)

{
  char local_7d8 [2000];
  int local_8;
  
  DAT_006fe410 = 1;
  DAT_006a49e8 = player;
  if (player == -1) {
    strcpy(&DAT_006ff310,s_Opponent_0052b208);
  }
  else {
    strcpy(&DAT_006ff310,&DAT_00522600 + player * 0x44);
  }
  local_8 = Palette_Subsystem_00495958(local_7d8);
  if (local_8 == -2) {
    MessageBoxA((HWND)0x0,local_7d8,s_Duel_couldn_t_run_0052b214,0x1030);
  }
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_00495958
 * Entry Point: 00495958
 * Size: 902 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Palette_Subsystem_00495958(char *str_1)

{
  DWORD _Seed;
  HANDLE pvVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 uVar4;
  HWND hWndParent;
  HMENU hMenu;
  HINSTANCE hInstance;
  int iVar5;
  LPVOID lpParam;
  DWORD local_60;
  tagMSG local_5c;
  int local_40;
  _AppBarData local_3c;
  int local_18;
  WPARAM local_14;
  UINT_PTR local_10;
  uint local_c;
  uint local_8;
  
  _Seed = GetTickCount();
  srand(_Seed);
  local_40 = 1;
  *str_1 = '\0';
  iVar5 = 1;
  pvVar1 = GetCurrentThread();
  SetThreadPriority(pvVar1,iVar5);
  local_3c.cbSize = 0x24;
  local_10 = SHAppBarMessage(4,&local_3c);
  local_c = local_10 & 1;
  local_8 = local_10 & 2;
  OutputDebugStringA(s_Main__initializing_critical_sect_0052b228);
  InitializeCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
  DAT_0068a718 = 0;
  DAT_00695e90 = 0;
  DAT_00695ea4 = 1;
  DAT_006808c4 = 0;
  DAT_006b157c = 0;
  DAT_0068a674 = 0;
  _DAT_00696738 = 0;
  Rules_ParseFilter_004ffedf();
  DAT_006fe450 = LoadCursorA(g_AppHInstance,s_Hand1_0052b250);
  DAT_006fe454 = LoadCursorA(g_AppHInstance,s_SwordWait_0052b258);
  DAT_006fe480 = 3;
  _DAT_006fe458 = LoadCursorA(g_AppHInstance,s_Hand2_0052b264);
  _DAT_006fe45c = LoadCursorA(g_AppHInstance,s_Hand3_0052b26c);
  _DAT_006fe460 = LoadCursorA(g_AppHInstance,s_Hand4_0052b274);
  Palette_Subsystem_0049608e();
  OutputDebugStringA(s_Main__creating_windows_0052b27c);
  local_60 = 0x82000000;
  if (1 < (int)DAT_006fe410) {
    local_60 = 0x82040000;
  }
  if ((DAT_006fe410 & 1) == 0) {
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = _hwndScreen;
    hInstance = g_AppHInstance;
    iVar5 = GetSystemMetrics(1);
    iVar2 = GetSystemMetrics(0);
    g_MainAppHwnd =
         CreateWindowExA(0,s_MAGICGAME_MainClass_0052b2b8,s_Magic_0052b2b0,local_60,1,0,iVar2 + -1,
                         iVar5,hWndParent,hMenu,hInstance,lpParam);
  }
  else {
    g_MainAppHwnd =
         CreateWindowExA(0,s_MAGICGAME_MainClass_0052b29c,s_Magic_0052b294,local_60,1,0,g_DisplayScreenWidth
                         ,g_DisplayScreenHeight,_hwndScreen,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  }
  if (g_MainAppHwnd == (HWND)0x0) {
    local_40 = 0;
    strcat(str_1,s_Couldn_t_create_the_main_window_0052b2cc);
  }
  DAT_006ff4b0 = LoadAcceleratorsA(g_AppHInstance,(LPCSTR)0x6f);
  if (((DAT_006fe410 & 4) != 0) || ((DAT_006fe410 & 2) != 0)) {
    Pic_Subsystem_00423980((int)g_MainAppHwnd,0,0);
  }
  Magic_DrawCardPhase();
  if (local_40 == 0) {
    uVar4 = 0xfffffffe;
  }
  else {
    Palette_Subsystem_004963e7();
    while( true ) {
      BVar3 = GetMessageA(&local_5c,(HWND)0x0,0,0);
      if (BVar3 == 0) break;
      Palette_Subsystem_00495cde(&local_5c);
    }
    local_14 = local_5c.wParam;
    Palette_Subsystem_00496230();
    if (DAT_006fe450 != (HCURSOR)0x0) {
      DestroyCursor(DAT_006fe450);
    }
    if (DAT_006fe454 != (HCURSOR)0x0) {
      DestroyCursor(DAT_006fe454);
    }
    for (local_18 = 0; local_18 < DAT_006fe480; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_006fe458 + local_18 * 4) != 0) {
        DestroyCursor(*(HCURSOR *)(&DAT_006fe458 + local_18 * 4));
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
    FUN_00474d0e();
    if (((DAT_006fe410 & 2) != 0) || ((DAT_006fe410 & 4) != 0)) {
      Pic_Subsystem_00423ae1();
    }
    GdiFlush();
    iVar5 = 0;
    pvVar1 = GetCurrentThread();
    SetThreadPriority(pvVar1,iVar5);
    uVar4 = DAT_00627a80;
  }
  return uVar4;
}



/*
 * Decompiled function: Palette_Subsystem_00495cde
 * Entry Point: 00495cde
 * Size: 526 bytes
 */


void Palette_Subsystem_00495cde(MSG *player)

{
  int iVar1;
  BOOL BVar2;
  LRESULT LVar3;
  uint uVar4;
  WPARAM local_8;
  
  iVar1 = TranslateAcceleratorA(g_MainAppHwnd,DAT_006ff4b0,player);
  if ((iVar1 == 0) && (iVar1 = Palette_Subsystem_00495eec((int *)player,0x4b), iVar1 == 0)) {
    if (((DAT_006b1578 == 0) ||
        (((BVar2 = IsWindowVisible(DAT_007006b0), BVar2 == 0 ||
          (LVar3 = SendMessageA(DAT_007006b0,0x402,0,0), LVar3 == 0)) || (player->message != 0x102)))
        ) || (((player->wParam != 0x20 && (player->wParam != 0xd)) && (player->wParam != 0x1b)))) {
      iVar1 = FUN_004088d0((int *)player);
      if ((iVar1 == 0) &&
         (((Palette_Util_00496332(player->hwnd,player->message,player->wParam,player->lParam),
           player->message != 0x201 && (player->message != 0x204)) || (DAT_006b1578 != 0)))) {
        TranslateMessage(player);
        DispatchMessageA(player);
      }
    }
    else {
      uVar4 = SendMessageA(DAT_007006b0,0x402,0,0);
      local_8 = 0xfffffc18;
      if (((uVar4 & 2) == 0) || ((uVar4 & 1) == 0)) {
        if ((player->wParam == 0xd) || (player->wParam == 0x20)) {
          local_8 = 0;
        }
        else if ((player->wParam == 0x1b) && ((uVar4 & 1) != 0)) {
          local_8 = DAT_0068a710;
        }
      }
      else if (player->wParam == 0xd) {
        local_8 = DAT_00695ecc;
      }
      else if (player->wParam == 0x1b) {
        local_8 = DAT_0068a710;
      }
      if (local_8 != 0xfffffc18) {
        SendMessageA(DAT_007006b0,0x401,local_8,0);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_00495eec
 * Entry Point: 00495eec
 * Size: 408 bytes
 */


undefined4 Palette_Subsystem_00495eec(int *arg1,UINT arg2)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  tagPOINT local_1c;
  tagRECT local_14;
  
  iVar2 = arg1[1];
  if (iVar2 != 0xa0) {
    if (iVar2 == 0x113) {
      if ((*arg1 == 0) && (arg1[2] == DAT_0052b02c)) {
        KillTimer((HWND)0x0,DAT_0052b02c);
        DAT_0052b02c = 0;
        GetCursorPos(&local_1c);
        iVar2 = GetSystemMetrics(0xd);
        local_1c.x = local_1c.x + iVar2;
        iVar2 = GetSystemMetrics(0xe);
        local_1c.y = local_1c.y + iVar2;
        GetWindowRect(DAT_00695ea0,&local_14);
        iVar3 = (local_14.right - local_14.left) + local_1c.x;
        iVar2 = GetSystemMetrics(0);
        iVar3 = iVar3 - iVar2;
        if (0 < iVar3) {
          local_1c.x = local_1c.x - iVar3;
        }
        iVar3 = (local_14.bottom - local_14.top) + local_1c.y;
        iVar2 = GetSystemMetrics(1);
        iVar3 = iVar3 - iVar2;
        if (0 < iVar3) {
          local_1c.y = local_1c.y - iVar3;
        }
        SetWindowPos(DAT_00695ea0,(HWND)0x0,local_1c.x,local_1c.y,0,0,5);
        return 1;
      }
      return 0;
    }
    if (iVar2 != 0x200) {
      return 0;
    }
  }
  if (DAT_0052b02c != 0) {
    KillTimer((HWND)0x0,DAT_0052b02c);
    DAT_0052b02c = 0;
  }
  if ((DAT_006fe424 != 0) && (BVar1 = IsWindowVisible(DAT_00695ea0), BVar1 != 0)) {
    DAT_0052b02c = SetTimer((HWND)0x0,0,arg2,(TIMERPROC)0x0);
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_0049608e
 * Entry Point: 0049608e
 * Size: 418 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0049621a) */

undefined4 Palette_Subsystem_0049608e(void)

{
  Ordinal_17();
  Pic_Subsystem_00442010(s_MAGICGAME_MainClass_0052b2f0);
  UI_Register_sPoison_0047c640(s_MAGICGAME_LifeClass_0052b304);
  Palette_Subsystem_00499720(s_MAGICGAME_FullCardClass_0052b318);
  Ai_CalcManaRequirement_004b9120(s_MAGICGAME_ManaSummaryClass_0052b330);
  Pic_Subsystem_0044b9c0(s_MAGICGAME_HandClass_0052b34c);
  Glue_Subsystem_004f04e0(s_MAGICGAME_ChatClass_0052b360);
  Minit_Subsystem_00467880(s_MAGICGAME_CardClass_0052b374);
  Pic_Load_004248b0(s_MAGICGAME_PhaseDisplayClass_0052b388);
  Pic_Load_00424a1e(s_MAGICGAME_AttackPhaseDisplayClas_0052b3a4);
  Glue_Subsystem_004ecee0(s_MAGICGAME_TerritoryClass_0052b3c8);
  UI_CreateWindow_0050bba0(s_MAGICGAME_LibraryClass_0052b3e4);
  Pic_Subsystem_00449340(s_MAGICGAME_GraveyardClass_0052b3fc);
  UI_Register_WINBK_Attack_0047d460(s_MAGICGAME_AttackClass_0052b418);
  Glue_Subsystem_004cd760(s_MAGICGAME_SpellChainClass_0052b430);
  UI_Register_FACE_BLACK_00408e20(s_MAGICGAME_FaceClass_0052b44c);
  UI_CreateWindow_00478b20(s_MAGICGAME_ScrollbarClass_0052b460);
  UI_CreateWindow_0041df60(s_MAGICTHEME_IconButtonClass_0052b47c);
  UI_Register_WINBK_BigCard_00401e65(s_MAGICGAME_BigCardChoiceClass_0052b498);
  UI_CreateWindow_00401c91(s_MAGICGAME_BigCardCardClass_0052b4b8);
  UI_CreateWindow_00501ad0(s_MAGIC_PaletteClass_0052b4d4);
  UI_CreateWindow_004081b0(s_MAGIC_CueCardClass_0052b4e8);
  Pic_Subsystem_004241f0(s_MAGIC_PlayerDirectiveClass_0052b4fc);
  Prompts_Load_00476e60(s_MAGIC_TellUserClass_0052b518);
  return 1;
}



/*
 * Decompiled function: Palette_Subsystem_00496230
 * Entry Point: 00496230
 * Size: 258 bytes
 */


void Palette_Subsystem_00496230(void)

{
  FUN_0047c734(s_MAGICGAME_LifeClass_0052b52c);
  Palette_Subsystem_004997b8(s_MAGICGAME_FullCardClass_0052b540);
  Ai_Subsystem_004b920e(s_MAGICGAME_ManaSummaryClass_0052b558);
  Pic_Subsystem_0044ba83(s_MAGICGAME_HandClass_0052b574);
  Glue_Subsystem_004f0597(s_MAGICGAME_ChatClass_0052b588);
  Minit_Subsystem_0046799f(s_MAGICGAME_CardClass_0052b59c);
  Pic_Subsystem_004249a8(s_MAGICGAME_PhaseDisplayClass_0052b5b0);
  Pic_Subsystem_00424aef(s_MAGICGAME_AttackPhaseDisplayClas_0052b5cc);
  Glue_Subsystem_004ecf94(s_MAGICGAME_TerritoryClass_0052b5f0);
  FUN_0050bcd6(s_MAGICGAME_LibraryClass_0052b60c);
  Pic_Subsystem_004494d1(s_MAGICGAME_GraveyardClass_0052b624);
  FUN_0047d85c(s_MAGICGAME_AttackClass_0052b640);
  Glue_Subsystem_004cda01(s_MAGICGAME_SpellChainClass_0052b658);
  FUN_00409052(s_MAGICGAME_FaceClass_0052b674);
  FUN_00478bd5(s_MAGICGAME_ScrollbarClass_0052b688);
  Mem_AllocOrFree_00401f40(s_MAGICGAME_BigCardChoiceClass_0052b6a4);
  Mem_AllocOrFree_00401d23(s_MAGICGAME_BigCardCardClass_0052b6c4);
  FUN_004082d1(s_MAGIC_CueCardClass_0052b6e0);
  FUN_004770bc(s_MAGIC_TellUserClass_0052b6f4);
  return;
}



/*
 * Decompiled function: Palette_Util_00496332
 * Entry Point: 00496332
 * Size: 37 bytes
 */


undefined4 Palette_Util_00496332(void)

{
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_0049635c
 * Entry Point: 0049635c
 * Size: 134 bytes
 */


undefined4 Palette_Subsystem_0049635c(HWND player,uint y,HWND arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if (y == 0x30f) {
    uVar1 = GDI_RealizePaletteTree_Magic(player,0x30f,arg_3,arg_4);
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar1 = 0;
  }
  else {
    uVar1 = GDI_RealizePaletteTree_Magic(player,y,arg_3,arg_4);
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004963e7
 * Entry Point: 004963e7
 * Size: 176 bytes
 */


undefined4 Palette_Subsystem_004963e7(void)

{
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.lpfnWndProc = Palette_Subsystem_00496497;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(1);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_KimDebug_0052b708;
  RegisterClassA(&local_2c);
  DAT_0064a0bc = CreateWindowExA(0,s_KimDebug_0052b718,&DAT_0052b714,0x80cc0000,10,10,0xfa,0x113,
                                 g_MainAppHwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  return 1;
}



/*
 * Decompiled function: Palette_Subsystem_00496497
 * Entry Point: 00496497
 * Size: 484 bytes
 */


LRESULT Palette_Subsystem_00496497(HWND hwnd,uint y,WPARAM arg_3,uint height)

{
  LRESULT LVar1;
  
  if (y == 0x4c8) {
    LVar1 = SendMessageA(DAT_0054b344,0x181,0,height);
    if (LVar1 == -2) {
      LVar1 = SendMessageA(DAT_0054b344,0x18b,0,0);
      SendMessageA(DAT_0054b344,0x182,LVar1 - 1,0);
      SendMessageA(DAT_0054b344,0x182,LVar1 - 2,0);
      SendMessageA(DAT_0054b344,0x181,0,height);
    }
    return 0;
  }
  if (y < 0x11) {
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
    switch(y) {
    case 1:
      DAT_0054b344 = CreateWindowExA(0,s_LISTBOX_0052b728,&DAT_0052b724,0x50240000,0,0,0,0,hwnd,
                                     (HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      LVar1 = 0;
      break;
    case 2:
      KillTimer(hwnd,1);
      LVar1 = 0;
      break;
    case 3:
      SendMessageA(DAT_0054b344,0x184,0,0);
      LVar1 = 0;
      break;
    default:
      goto switchD_00496653_caseD_4;
    case 5:
      MoveWindow(DAT_0054b344,0,0,height & 0xffff,height >> 0x10,1);
      LVar1 = 0;
    }
  }
  else {
    if (y == 0x113) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x201) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
switchD_00496653_caseD_4:
    LVar1 = DefWindowProcA(hwnd,y,arg_3,height);
  }
  return LVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004966a0
 * Entry Point: 004966a0
 * Size: 304 bytes
 */


undefined4 Palette_Subsystem_004966a0(void)

{
  int iVar1;
  int local_c;
  
  for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
    iVar1 = Ai_Subsystem_004cbcd9(local_c);
    if (iVar1 != -1) {
      if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 1) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 1;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 2) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 3;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 3) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 4;
      }
      else if (*(int *)(&DAT_006b3094 + local_c * 0x98) == 4) {
        (&DAT_0051aed4)[iVar1 * 0x34] = 2;
      }
      else {
        (&DAT_0051aed4)[iVar1 * 0x34] = 1;
      }
    }
  }
  return 1;
}



/*
 * Decompiled function: Palette_Subsystem_00496ccf
 * Entry Point: 00496ccf
 * Size: 81 bytes
 */


uint Palette_Subsystem_00496ccf(void)

{
  uint uVar1;
  char local_7d4 [2000];
  
  local_7d4[0] = '\0';
  uVar1 = Palette_Color_00495430(local_7d4);
  Rules_ParseFilter_004ffedf();
  DAT_00695ea4 = 1;
  return uVar1 | 1;
}



/*
 * Decompiled function: Palette_Util_00496d20
 * Entry Point: 00496d20
 * Size: 16 bytes
 */


void Palette_Util_00496d20(void)

{
  Palette_Subsystem_00495829();
  return;
}



/*
 * Decompiled function: Palette_Subsystem_00496d30
 * Entry Point: 00496d30
 * Size: 383 bytes
 */


int Palette_Subsystem_00496d30(HDC hdc,int *y,WPARAM *arg_3,int height)

{
  tagRECT local_34;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = SaveDC(hdc);
  local_14 = 300;
  local_c = 0xf0;
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,local_14,local_c,(LPSIZE)0x0);
  SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
  SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
  SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
  SetRect(&local_24,0,0,local_14,local_c);
  CopyRect(&local_34,&local_24);
  LPtoDP(hdc,(LPPOINT)&local_34,2);
  if (height != 0) {
    FUN_0047884f(*arg_3,0,local_34.right - local_34.left,local_34.bottom - local_34.top);
  }
  if ((4 < local_34.left) && (4 < local_34.top)) {
    Surface_FillRect((int *)g_DisplaySurfaceScreen,-4,-4,local_14 + 8,local_c + 8,0xff);
  }
  local_8 = FUN_00478763(hdc,&local_24,*arg_3,0);
  if (local_8 == 0) {
    FUN_0046bfc2(hdc,&local_24,*arg_3,0);
  }
  RestoreDC(hdc,local_10);
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_00496eaf
 * Entry Point: 00496eaf
 * Size: 83 bytes
 */


int Palette_Subsystem_00496eaf(void)

{
  undefined4 local_8;
  
  Palette_Subsystem_0049c107();
  FUN_00478a56();
  for (local_8 = 0; local_8 < DAT_006a49f4; local_8 = local_8 + 1) {
    FUN_0046c1b3(local_8);
  }
  FUN_0046c859();
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_00496f10
 * Entry Point: 00496f10
 * Size: 80 bytes
 */


undefined4 Palette_Subsystem_00496f10(void)

{
  ShowWindow(g_MainAppHwnd,0);
  ShowWindow(_hwndScreen,5);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  DAT_0063ee18 = 0;
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_00496f60
 * Entry Point: 00496f60
 * Size: 68 bytes
 */


undefined4 Palette_Subsystem_00496f60(void)

{
  DAT_0063ee18 = 1;
  ShowWindow(_hwndScreen,0);
  ShowWindow(g_MainAppHwnd,5);
  SetFocus(g_MainAppHwnd);
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_00496fa4
 * Entry Point: 00496fa4
 * Size: 408 bytes
 */


undefined4 Palette_Subsystem_00496fa4(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg1 + 0x10),
                        *(int *)(arg1 + 0x14),*(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),
                        iRam0064a0b8);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                   *(uint *)(arg1 + 0x18),*(DWORD *)(arg1 + 0x1c),(int *)g_DisplaySurfaceScreen,
                   *(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),(&DAT_0064a0b0)[arg2]);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/*
 * Decompiled function: Palette_Subsystem_0049713c
 * Entry Point: 0049713c
 * Size: 50 bytes
 */


undefined4 Palette_Subsystem_0049713c(int player)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0052b83c,0xf,100,100,0);
  DAT_0054b34c = *(undefined4 *)(player + 0x2c);
  return 0;
}



/*
 * Decompiled function: Palette_Color_0049716e
 * Entry Point: 0049716e
 * Size: 4152 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Palette_Color_0049716e(undefined4 player,uint card_slot,uint arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 arg_1_00;
  char *str_2;
  int iVar7;
  int *piVar8;
  int local_160;
  undefined *local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_144;
  int local_140;
  uint local_13c;
  byte local_138;
  int local_134;
  int local_130;
  uint local_12c;
  int local_128;
  uint auStack_124 [64];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 1;
  App_ProcessPendingMessages();
  if (arg_4 != 0) {
    FUN_00510b70(1,0,g_DisplayScreenHeight - 0x1e0,s_tradscrn_pic_0052b850,(short *)0x0);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  if (arg_5 != 0) {
    Sprite_LoadAll(&DAT_0064a0b0,s_buyAny_spr_0052b860);
    if (DAT_0052b780 == DAT_0052b770) {
      DAT_0052b780 = Ai_Util_004c3bc4(DAT_0052b780);
      DAT_0052b784 = Ai_Util_004c3bc4(DAT_0052b784);
      DAT_0052b788 = Ai_Util_004c3bc4(DAT_0052b788);
      DAT_0052b78c = Ai_Util_004c3bc4(DAT_0052b78c);
    }
    iVar1 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(iVar1);
    FUN_0041f17e(0x52b770,1,iVar1);
    FUN_0041f213();
  }
  if (arg_3 == 0xffffffff) {
    if (arg_4 != 0) {
      arg_3 = 0;
      DAT_0052b734 = 1;
    }
  }
  else {
    DAT_0052b734 = arg_3;
    arg_3 = 1 << ((byte)arg_3 & 0x1f);
    if (arg_3 == 0x10) {
      arg_3 = 0x30;
    }
  }
  if ((card_slot != 0) && (arg_4 != 0)) {
    _DAT_0052b730 = Card_ColorMaskToColorIndex((byte)card_slot);
  }
  if (arg_4 != 0) {
    DAT_0052b738 = 0xffffffff;
  }
  do {
    if (local_10 != 0) {
      iVar1 = Ai_Util_004c3bc4(0x8c);
      iVar2 = Ai_Util_004c3bc4(0x21);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x132);
      uVar4 = Ai_Util_004c3bc4(0x8b);
      iVar5 = Ai_Util_004c3bc4(0x8c);
      uVar6 = Ai_Util_004c3bc4(0x21);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x8c);
      iVar2 = Ai_Util_004c3bc4(0x1d4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x132);
      uVar4 = Ai_Util_004c3bc4(0x8b);
      iVar5 = Ai_Util_004c3bc4(0x8c);
      uVar6 = Ai_Util_004c3bc4(0x21);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x1bf);
      iVar2 = Ai_Util_004c3bc4(0xb4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x1d);
      uVar4 = Ai_Util_004c3bc4(0x118);
      iVar5 = Ai_Util_004c3bc4(0x1bf);
      uVar6 = Ai_Util_004c3bc4(0xb4);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x158);
      iVar2 = Ai_Util_004c3bc4(0xe9);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x68);
      uVar4 = Ai_Util_004c3bc4(0xae);
      iVar5 = Ai_Util_004c3bc4(0x158);
      uVar6 = Ai_Util_004c3bc4(0xe9);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x10);
      iVar2 = Ai_Util_004c3bc4(0x1db);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x5e);
      uVar4 = Ai_Util_004c3bc4(0x7c);
      iVar5 = Ai_Util_004c3bc4(0x10);
      uVar6 = Ai_Util_004c3bc4(0x1db);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x27);
      iVar2 = Ai_Util_004c3bc4(0xe4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x19);
      uVar4 = Ai_Util_004c3bc4(0xb8);
      iVar5 = Ai_Util_004c3bc4(0x27);
      uVar6 = Ai_Util_004c3bc4(0xe4);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
    }
    local_10 = 0;
    iVar1 = Ai_Util_004c3bc4(0x157);
    iVar2 = Ai_Util_004c3bc4(0xe8);
    piVar8 = (int *)g_DisplaySurfaceScreen;
    DVar3 = Ai_Util_004c3bc4(0x66);
    uVar4 = Ai_Util_004c3bc4(0xac);
    iVar5 = Ai_Util_004c3bc4(0x157);
    uVar6 = Ai_Util_004c3bc4(0xe8);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0x16,0x140,0x34);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    iVar1 = Ai_Util_004c3ba3(0x6b);
    iVar2 = Ai_Util_004c3ba3(0x45);
    iVar5 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_130 = iVar2 / 2 - (iVar5 * 6) / 2;
    for (local_12c = 0; (int)local_12c < 6; local_12c = local_12c + 1) {
      if (local_12c == 0) {
        if (_DAT_0052b730 == 0) {
          local_14c = 0x1b;
        }
        else if (card_slot == 0) {
          local_14c = 0x62;
        }
        else {
          local_14c = 0;
        }
        FUN_0040c421(s_Colorless_0052b86c,iVar1 / 2,local_130,local_14c);
      }
      else {
        if (local_12c == _DAT_0052b730) {
          local_150 = 0x1b;
        }
        else if (card_slot == 0) {
          local_150 = 0x62;
        }
        else {
          local_150 = 0;
        }
        iVar2 = iVar1 / 2;
        iVar5 = local_130;
        arg_1_00 = Mem_AllocOrFree_00473d7e(local_12c);
        FUN_0040c421(arg_1_00,iVar2,iVar5,local_150);
      }
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      local_130 = local_130 + iVar2;
    }
    iVar1 = Ai_Util_004c3ba3(0x215);
    iVar2 = Ai_Util_004c3ba3(0x45);
    iVar5 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_130 = iVar2 / 2 - (iVar5 * 6) / 2;
    local_1c = local_130;
    local_18 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_12c = 0; (int)local_12c < 6; local_12c = local_12c + 1) {
      if (_DAT_0052b730 == 0) {
        if (local_12c == DAT_0052b734) {
          local_158 = 0x1b;
        }
        else if (arg_3 == 0) {
          local_158 = 0x62;
        }
        else {
          local_158 = 0x62;
        }
        if ((int)local_12c < 2) {
          local_15c = (&PTR_DAT_0052b750)[local_12c];
        }
        else {
          local_15c = (undefined *)(&DAT_0052b738)[local_12c];
        }
        FUN_0040c421(local_15c,iVar1 / 2,local_130,local_158);
      }
      else {
        if (local_12c == DAT_0052b734) {
          local_154 = 0x1b;
        }
        else if (arg_3 == 0) {
          local_154 = 0x62;
        }
        else {
          local_154 = 0x62;
        }
        FUN_0040c421((&PTR_DAT_0052b750)[local_12c],iVar1 / 2,local_130,local_154);
      }
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      local_130 = local_130 + iVar2;
    }
    local_13c = DAT_0052b734;
    if ((_DAT_0052b730 == 0) && (1 < (int)DAT_0052b734)) {
      local_140 = DAT_0052b734 - 1;
      local_13c = 6;
    }
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xff,0xfe,0x1ce);
    for (local_12c = 0; (int)local_12c < 5; local_12c = local_12c + 1) {
      Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0xff,local_12c * 0x23 + 0x131,0x1ce);
    }
    iVar1 = Ai_Util_004c3ba3(0x11e);
    local_20 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_20 = (iVar1 / 2) / local_20;
    local_24 = 0;
    local_128 = Ai_Util_004c3ba3(0x66);
    local_128 = local_128 / 2;
    local_130 = Ai_Util_004c3ba3(0x99);
    local_130 = local_130 / 2;
    local_c = local_130;
    local_8 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_12c = 0; (int)local_12c < g_MasterCardCount + -0x29; local_12c = local_12c + 1) {
      if (((_DAT_0052b730 != 0) || (local_13c != 6)) ||
         (iVar1 = Math_Clamp((int)(char)(&DAT_0051aed4)[local_12c * 0x34],1,3), iVar1 == local_140
         )) {
        local_14 = (uint)(char)(&DAT_0051aebe)[local_12c * 0x34];
        if (local_14 == 0) {
          local_14 = 1;
        }
        if ((((((local_14 & 1 << (DAT_0052b730 & 0x1f)) != 0) &&
              ((1 << ((byte)local_13c & 0x1f) &
               (uint)(byte)(&g_MasterCardColorTable)[local_12c * 0x34]) != 0)) &&
             ((((&DAT_0051aed1)[local_12c * 0x34] & 9) == 0 || (DAT_0067b9a4 != 0)))) &&
            ((iVar1 = FUN_00485005(local_12c), iVar1 != 0 &&
             ((card_slot == 0 || ((local_14 & card_slot) != 0)))))) &&
           (((arg_3 == 0 || ((arg_3 & (byte)(&g_MasterCardColorTable)[local_12c * 0x34]) != 0)) &&
            (((&g_MasterCardColorTable)[local_12c * 0x34] != 'B' || (local_13c != 6)))))) {
          local_144 = 0;
          for (local_134 = 0; local_134 < 500; local_134 = local_134 + 1) {
            if ((*(uint *)(&deck + local_134 * 4) & 0xfff) == local_12c) {
              local_144 = local_144 + 1;
            }
          }
          strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + local_12c * 0x34);
          if (local_144 != 0) {
            strcat(&g_OverworldWorldState,&DAT_0052b880);
            str_2 = _itoa(local_144,&DAT_0054b350,10);
            strcat(&g_OverworldWorldState,str_2);
          }
          if (DAT_0052b738 == 0xffffffff) {
            DAT_0052b738 = local_12c;
          }
          if (local_12c == DAT_0052b738) {
            local_160 = 0x1b;
          }
          else {
            iVar1 = Glue_Subsystem_004f0b50(local_12c);
            if (iVar1 < 1) {
              local_160 = 3;
            }
            else {
              local_160 = 0x54;
            }
          }
          FUN_0040c421(&g_OverworldWorldState,local_128,local_130,local_160);
          auStack_124[local_24] = local_12c;
          local_24 = local_24 + 1;
          iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          local_130 = local_130 + iVar1;
          if (local_20 == local_24) {
            local_128 = Ai_Util_004c3ba3(0x219);
            local_128 = local_128 / 2;
            local_130 = Ai_Util_004c3ba3(0x99);
            local_130 = local_130 / 2;
          }
        }
      }
    }
    if (DAT_0052b738 != 0xffffffff) {
      DAT_0052b73c = DAT_0052b738;
      FUN_0050b3de(DAT_0052b738,0x7b,0x33,0x4b,0x70,1,&DAT_0052b884);
    }
    Pic_Subsystem_0044b8aa();
    DAT_0054b34c = -1;
    while ((Pic_Subsystem_0044b84b(), arg_5 == 0 || (DAT_007039c4 == 0))) {
      if (DAT_007039c4 != 0) goto LAB_00497f4a;
      if (arg_5 != 0) {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
      }
    }
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
    if (0 < DAT_0054b34c) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      App_ProcessPendingMessages();
      Palette_Subsystem_00496eaf();
      return 0xffffffff;
    }
LAB_00497f4a:
    iVar5 = DAT_007039c4;
    iVar2 = DAT_0067bda8;
    iVar1 = DAT_0067bda4;
    App_ProcessPendingMessages();
    Pic_Subsystem_0044b8da();
    iVar7 = Ai_Util_004c3ba3(0x66);
    if ((((iVar7 / 2 < iVar2) && (iVar7 = Ai_Util_004c3ba3(0x146), iVar2 < iVar7 / 2)) &&
        (iVar7 = Ai_Util_004c3ba3(0xf6), iVar7 / 2 < iVar1)) &&
       (iVar7 = Ai_Util_004c3ba3(0x18c), iVar1 < iVar7 / 2)) {
      if (arg_5 != 0) {
        FUN_0041f391();
        Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      }
      Palette_Subsystem_00496eaf();
      return DAT_0052b73c;
    }
    if (iVar5 == 0) {
      if (arg_5 != 0) {
        FUN_0041f391();
      }
      Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      Palette_Subsystem_00496eaf();
      return 0xffffffff;
    }
    iVar5 = Ai_Util_004c3ba3(0x6d);
    if (iVar2 < iVar5 / 2) {
      uVar4 = (iVar2 - local_1c) / local_18;
      iVar2 = Ai_Util_004c3bc4(0xac);
      if (iVar1 < iVar2) {
        if (((-1 < (int)uVar4) && ((int)uVar4 < 6)) &&
           ((card_slot == 0 || (local_138 = (byte)uVar4, 1 << (local_138 & 0x1f) == card_slot)))) {
          DAT_0052b738 = 0xffffffff;
          local_10 = 1;
          _DAT_0052b730 = uVar4;
        }
      }
      else {
        iVar2 = Ai_Util_004c3bc4(0x1d6);
        if (((iVar2 < iVar1) && (-1 < (int)uVar4)) && ((int)uVar4 < 6)) {
          DAT_0052b738 = 0xffffffff;
          local_10 = 1;
          DAT_0052b734 = uVar4;
        }
      }
    }
    else {
      iVar5 = Ai_Util_004c3ba3(0x96);
      if ((iVar5 / 2 < iVar2) &&
         (iVar1 = (iVar2 - local_c) / local_8 + (iVar1 / ((int)g_DisplayScreenWidth / 2)) * local_20,
         iVar1 < local_24)) {
        DAT_0052b738 = auStack_124[iVar1];
      }
    }
  } while( true );
}



/*
 * Decompiled function: Palette_Subsystem_004981b5
 * Entry Point: 004981b5
 * Size: 1904 bytes
 */


void Palette_Subsystem_004981b5(int player)

{
  byte arg_1_00;
  char *str_2;
  int aiStack_12c [8];
  int aiStack_10c [7];
  int local_f0 [8];
  int local_d0;
  int aiStack_cc [7];
  int local_b0;
  int aiStack_ac [7];
  int local_90;
  int aiStack_8c [7];
  int local_70;
  int aiStack_6c [7];
  int local_50;
  int local_4c [8];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10 [3];
  
  DAT_0054b348 = 0;
  for (local_24 = 0; local_24 < 8; local_24 = local_24 + 1) {
    aiStack_12c[local_24] = 0;
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      aiStack_10c[local_24 + local_28 * 8] = 0;
    }
  }
  for (local_24 = 0; local_24 < 3; local_24 = local_24 + 1) {
    local_10[local_24] = 0;
  }
  for (local_24 = 0; local_24 < 500; local_24 = local_24 + 1) {
    if (((&DAT_00702151)[local_24 * 4] & 0x40) == 0) {
      DAT_0054b348 = DAT_0054b348 + 1;
      local_18 = *(uint *)(&deck + local_24 * 4) & 0xfff;
      arg_1_00 = (&DAT_0051aebe)[local_18 * 0x34];
      local_2c = (int)(char)arg_1_00;
      if ((&DAT_0051aed4)[local_18 * 0x34] == '\x03') {
        local_10[2] = local_10[2] + 1;
      }
      else if ((&DAT_0051aed4)[local_18 * 0x34] == '\x02') {
        local_10[1] = local_10[1] + 1;
      }
      else {
        local_10[0] = local_10[0] + 1;
      }
      if (((&g_MasterCardColorTable)[local_18 * 0x34] & 1) != 0) {
        for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
          if ((1 << ((byte)local_28 & 0x1f) & (int)(char)(&DAT_0051aebe)[local_18 * 0x34]) != 0) {
            aiStack_12c[local_28] = aiStack_12c[local_28] + 1;
            aiStack_12c[7] = aiStack_12c[7] + 1;
          }
        }
      }
      local_2c = Card_ColorMaskToColorIndex(arg_1_00);
      switch((&g_MasterCardColorTable)[local_18 * 0x34]) {
      case 1:
        aiStack_10c[local_2c] = aiStack_10c[local_2c] + 1;
        local_f0[0] = local_f0[0] + 1;
        break;
      case 2:
        if ((int)*(short *)(&DAT_0051aec2 + local_18 * 0x34) +
            (int)*(short *)(&DAT_0051aec4 + local_18 * 0x34) < 5) {
          local_f0[local_2c + 1] = local_f0[local_2c + 1] + 1;
          local_d0 = local_d0 + 1;
        }
        else {
          aiStack_cc[local_2c] = aiStack_cc[local_2c] + 1;
          local_b0 = local_b0 + 1;
        }
        break;
      case 4:
        aiStack_ac[local_2c] = aiStack_ac[local_2c] + 1;
        local_90 = local_90 + 1;
        break;
      case 8:
        aiStack_8c[local_2c] = aiStack_8c[local_2c] + 1;
        local_70 = local_70 + 1;
        break;
      case 0x10:
      case 0x20:
        aiStack_6c[local_2c] = aiStack_6c[local_2c] + 1;
        local_50 = local_50 + 1;
        break;
      case 0x40:
      case 0x42:
        local_4c[local_2c] = local_4c[local_2c] + 1;
      }
    }
  }
  if (player != 0) {
    FUN_0050d560(0,0);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    local_1c = 0x10;
    local_20 = 0x10;
    strcpy(&g_OverworldWorldState,&DAT_0052b888);
    str_2 = _itoa(DAT_0054b348,&DAT_0054b350,10);
    strcat(&g_OverworldWorldState,str_2);
    strcat(&g_OverworldWorldState,s_cards__0052b88c);
    FUN_0040c381(&g_OverworldWorldState,local_1c,local_20,0xf6);
    FUN_0040c2e9(s_Total_0052b894,0x80,local_20,0xff);
    FUN_0040c2e9(s_Black_0052b89c,0xb0,local_20,0xff);
    FUN_0040c2e9(&DAT_0052b8a4,0xd0,local_20,0xff);
    FUN_0040c2e9(s_Green_0052b8ac,0xf0,local_20,0xff);
    FUN_0040c2e9(&DAT_0052b8b4,0x110,local_20,0xff);
    FUN_0040c2e9(s_White_0052b8b8,0x130,local_20,0xff);
    Surface_DrawLine((int *)g_DisplaySurfaceScreen,0,local_20 * 2 + 0x18,g_DisplayScreenWidth + -1,
                     local_20 * 2 + 0x18,0xf4);
    Surface_DrawLine((int *)g_DisplaySurfaceScreen,0x130,0,0x130,g_DisplayScreenHeight + -1,0xf4);
    local_20 = 0x20;
    FUN_0040c381(&DAT_0052b8c0,local_1c,0x20,0xff);
    Palette_Subsystem_004989a9(local_f0[0],0x80,local_20,0xff);
    for (local_24 = 1; local_24 < 6; local_24 = local_24 + 1) {
      Palette_Subsystem_004989a9(aiStack_12c[local_24],local_24 * 0x20 + 0x90,local_20,0xff);
    }
    for (local_28 = 1; local_20 = local_20 + 0xc, local_28 < 6; local_28 = local_28 + 1) {
      switch(local_28) {
      case 1:
        strcpy(&g_OverworldWorldState,s_Fast_creatures_0052b8c8);
        break;
      case 2:
        strcpy(&g_OverworldWorldState,s_Large_creatures_0052b8d8);
        break;
      case 3:
        strcpy(&g_OverworldWorldState,s_Enchantments_0052b8e8);
        break;
      case 4:
        strcpy(&g_OverworldWorldState,s_Sorceries_0052b8f8);
        break;
      case 5:
        strcpy(&g_OverworldWorldState,s_Fast_effects_0052b904);
      }
      FUN_0040c381(&g_OverworldWorldState,local_1c,local_20,0xff);
      Palette_Subsystem_004989a9(local_f0[local_28 * 8],0x80,local_20,0xff);
      for (local_24 = 1; local_24 < 6; local_24 = local_24 + 1) {
        Palette_Subsystem_004989a9
                  (aiStack_10c[local_24 + local_28 * 8],local_24 * 0x20 + 0x90,local_20,0xff);
      }
    }
    FUN_0040c381(s_Artifacts_0052b914,local_1c,local_20,0xff);
    Palette_Subsystem_004989a9(local_4c[0],0x80,local_20,0xff);
    local_20 = local_20 + 0x18;
    local_1c = 0x80;
    FUN_0040c381(s_Common__0052b920,0x80,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[0],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    FUN_0040c381(s_Uncommon__0052b92c,local_1c,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[1],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    FUN_0040c381(s_Rare__0052b938,local_1c,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[2],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    Ai_Subsystem_004cd1d1();
  }
  local_14 = local_d0;
  if (local_d0 < local_b0) {
    local_14 = local_b0;
  }
  DAT_00626804 = (uint)(local_d0 < local_b0);
  if (local_14 < local_70 + local_50) {
    DAT_00626804 = 2;
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004989a9
 * Entry Point: 004989a9
 * Size: 111 bytes
 */


void Palette_Subsystem_004989a9(int x,int y,int width,undefined4 arg_4)

{
  char *str_2;
  
  g_OverworldWorldState = 0;
  str_2 = _itoa((x * 100) / DAT_0054b348,&DAT_0054b350,10);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_0052b940);
  FUN_0040c2e9(&g_OverworldWorldState,y,width,arg_4);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_00498a18
 * Entry Point: 00498a18
 * Size: 3133 bytes
 */


bool Palette_Subsystem_00498a18(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  int local_50;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int aiStack_34 [8];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 5;
  do {
    local_50 = 0;
    uVar1 = Math_RandomRange(10);
    switch(uVar1) {
    case 0:
      local_44 = 0;
      break;
    case 1:
      local_44 = 1;
      break;
    case 2:
      local_44 = 2;
      break;
    case 3:
      local_44 = 3;
      break;
    case 4:
      local_44 = 4;
      break;
    case 5:
      local_44 = 5;
      break;
    case 6:
      local_44 = 6;
      break;
    case 7:
      local_44 = 7;
      break;
    case 8:
      local_44 = 8;
      break;
    case 9:
      local_44 = 2;
    }
switchD_00498acb_default:
    do {
      do {
        iVar2 = Math_RandomRange(g_MasterCardCount + -0x29);
        if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) == 0) {
          if (local_44 != 2) goto switchD_00498acb_default;
        }
      } while (((&DAT_0051aed6)[iVar2 * 0x34] & 0xc1) == 0);
      bVar5 = false;
      switch(local_44) {
      case 0:
        if ((0 < *(short *)(&DAT_0051aec2 + iVar2 * 0x34)) &&
           (*(short *)(&DAT_0051aec2 + iVar2 * 0x34) < 0x4000)) {
          bVar5 = true;
        }
        break;
      case 1:
        if ((0 < *(short *)(&DAT_0051aec4 + iVar2 * 0x34)) &&
           (*(short *)(&DAT_0051aec4 + iVar2 * 0x34) < 0x4000)) {
          bVar5 = true;
        }
        break;
      case 2:
        if (('\0' < (char)(&DAT_0051aebf)[iVar2 * 0x34]) &&
           (-1 < (char)(&DAT_0051aec0)[iVar2 * 0x34])) {
          bVar5 = true;
        }
        break;
      case 3:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x20) != 0;
        break;
      case 4:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x1f) != 0;
        break;
      case 5:
        bVar5 = ((&DAT_0051aecd)[iVar2 * 0x34] & 2) != 0;
        break;
      case 6:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x40) != 0;
        break;
      case 7:
        bVar5 = ((&DAT_0051aecd)[iVar2 * 0x34] & 1) != 0;
        break;
      case 8:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x80) != 0;
      }
      local_50 = local_50 + 1;
      if (bVar5) {
        iVar3 = Math_RandomRange(4);
        if (DAT_0067f380 <= iVar3) {
          local_38 = 0;
          goto LAB_00498ff5;
        }
        local_10 = -1;
        switch(local_44) {
        case 0:
          strcpy(&g_OverworldWorldState,s_What_is_the_power_rating_of_the_0052b944);
          local_10 = (int)*(short *)(&DAT_0051aec2 + iVar2 * 0x34);
          break;
        case 1:
          strcpy(&g_OverworldWorldState,s_What_is_the_toughness_of_the_0052b968);
          local_10 = (int)*(short *)(&DAT_0051aec4 + iVar2 * 0x34);
          break;
        case 2:
          strcpy(&g_OverworldWorldState,s_What_is_the_total_casting_cost_o_0052b988);
          local_10 = (int)(char)(&DAT_0051aebf)[iVar2 * 0x34] +
                     (int)(char)(&DAT_0051aec0)[iVar2 * 0x34];
          break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          strcpy(&g_OverworldWorldState,s_What_special_ability_does_the_0052b9b0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
          strcat(&g_OverworldWorldState,s_have__Swampwalk_Islandwalk_Fores_0052b9d0);
          strcat(&g_OverworldWorldState,s_Plainswalk_Flying_Banding_Trampl_0052ba0c);
        }
        if (local_10 == -1) {
          local_3c = FUN_00489710(&g_OverworldWorldState,0x50,100);
          local_c = local_3c;
          if ((*(uint *)(&DAT_0051aecc + iVar2 * 0x34) & 1 << ((byte)local_3c & 0x1f)) == 0) {
            local_c = 99;
          }
        }
        else {
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
          strcat(&g_OverworldWorldState,s___0_1_2_3_4_5_6_7_8__0052ba50);
          local_c = Math_Clamp(local_10,0,8);
          local_3c = FUN_00489710(&g_OverworldWorldState,0x50,100);
        }
        Glue_Subsystem_004eadb7(1);
        Ai_Subsystem_004cc50a
                  (iVar2,(-(uint)(local_3c == local_c) & 0x12) + 0xbc,
                   s_Correct_0052ba70 + ((local_3c == local_c) - 1 & 8));
        Ai_Subsystem_004cd1d1();
        bVar5 = local_3c != local_c;
        goto LAB_0049971a;
      }
    } while (local_50 < 4);
  } while( true );
LAB_00498ff5:
  if (local_14 <= local_38) {
    local_c = Math_RandomRange(local_14);
    aiStack_34[local_c] = iVar2;
    strcpy(&g_OverworldWorldState,s_Which_of_these_spells_0052ba80);
    switch(local_44) {
    case 0:
      strcat(&g_OverworldWorldState,s_has_a_power_of_0052ba98);
      pcVar4 = _itoa((int)*(short *)(&DAT_0051aec2 + iVar2 * 0x34),&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      break;
    case 1:
      strcat(&g_OverworldWorldState,s_has_a_toughness_of_0052baa8);
      pcVar4 = _itoa((int)*(short *)(&DAT_0051aec4 + iVar2 * 0x34),&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      break;
    case 2:
      strcat(&g_OverworldWorldState,s_requires_0052babc);
      pcVar4 = _itoa((int)(char)(&DAT_0051aebf)[iVar2 * 0x34],&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,&DAT_0052bac8);
      iVar3 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar2 * 0x34]);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(iVar3);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_and_0052bacc);
      pcVar4 = _itoa((int)(char)(&DAT_0051aec0)[iVar2 * 0x34],&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_generic_mana_to_cast_0052bad4);
      break;
    case 3:
      strcat(&g_OverworldWorldState,s_has_flying_ability_0052baec);
      break;
    case 4:
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 1) != 0) {
        strcat(&g_OverworldWorldState,s_has_swampwalk_0052bb00);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 8) != 0) {
        strcat(&g_OverworldWorldState,s_has_mountainwalk_0052bb10);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 2) != 0) {
        strcat(&g_OverworldWorldState,s_has_islandwalk_0052bb24);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 4) != 0) {
        strcat(&g_OverworldWorldState,s_has_forestwalk_0052bb34);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 0x10) != 0) {
        strcat(&g_OverworldWorldState,s_has_plainswalk_0052bb44);
      }
      strcat(&g_OverworldWorldState,s_ability_0052bb54);
      break;
    case 5:
      strcat(&g_OverworldWorldState,s_has_regeneration_ability_0052bb60);
      break;
    case 6:
      strcat(&g_OverworldWorldState,s_has_banding_ability_0052bb7c);
      break;
    case 7:
      strcat(&g_OverworldWorldState,s_has_first_strike_ability_0052bb90);
      break;
    case 8:
      strcat(&g_OverworldWorldState,s_has_trample_ability_0052bbac);
    }
    strcat(&g_OverworldWorldState,&DAT_0052bbc0);
    for (local_38 = 0; local_38 < local_14; local_38 = local_38 + 1) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + aiStack_34[local_38] * 0x34);
      strcat(&g_OverworldWorldState,&DAT_0052bbc4);
    }
    iVar2 = FUN_00489710(&g_OverworldWorldState,0x50,100);
    Glue_Subsystem_004eadb7(1);
    Ai_Subsystem_004cc50a
              (aiStack_34[local_c],(-(uint)(iVar2 == local_c) & 0x12) + 0xbc,
               s_The_correct_answer_is__0052bbc8);
    Ai_Subsystem_004cd1d1();
    bVar5 = iVar2 != local_c;
LAB_0049971a:
    return !bVar5;
  }
LAB_00499001:
  do {
    do {
      local_8 = Math_RandomRange(g_MasterCardCount + -0x29);
      if (((&g_MasterCardColorTable)[local_8 * 0x34] & 2) == 0) {
        if (local_44 != 2) goto LAB_00499001;
      }
    } while (((&DAT_0051aed6)[local_8 * 0x34] & 0xc1) == 0);
    bVar5 = false;
    switch(local_44) {
    case 0:
      bVar5 = *(short *)(&DAT_0051aec2 + local_8 * 0x34) != *(short *)(&DAT_0051aec2 + iVar2 * 0x34)
      ;
      break;
    case 1:
      bVar5 = *(short *)(&DAT_0051aec4 + local_8 * 0x34) != *(short *)(&DAT_0051aec4 + iVar2 * 0x34)
      ;
      break;
    case 2:
      if (((&DAT_0051aebe)[local_8 * 0x34] == (&DAT_0051aebe)[iVar2 * 0x34]) &&
         (((&DAT_0051aebf)[local_8 * 0x34] != (&DAT_0051aebf)[iVar2 * 0x34] ||
          ((&DAT_0051aebe)[local_8 * 0x34] != (&DAT_0051aebe)[iVar2 * 0x34])))) {
        bVar5 = true;
      }
      break;
    case 3:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x20) == 0;
      break;
    case 4:
      bVar5 = (*(uint *)(&DAT_0051aecc + local_8 * 0x34) & *(uint *)(&DAT_0051aecc + iVar2 * 0x34) &
              0x1f) == 0;
      break;
    case 5:
      bVar5 = ((&DAT_0051aecd)[local_8 * 0x34] & 2) == 0;
      break;
    case 6:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x40) == 0;
      break;
    case 7:
      bVar5 = ((&DAT_0051aecd)[local_8 * 0x34] & 1) == 0;
      break;
    case 8:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x80) == 0;
    }
    for (local_40 = 0; local_40 < local_38; local_40 = local_40 + 1) {
      if (aiStack_34[local_40] == aiStack_34[local_38]) {
        bVar5 = false;
      }
    }
  } while (!bVar5);
  aiStack_34[local_38] = local_8;
  local_38 = local_38 + 1;
  goto LAB_00498ff5;
}



/*
 * Decompiled function: Palette_Subsystem_00499720
 * Entry Point: 00499720
 * Size: 152 bytes
 */


bool Palette_Subsystem_00499720(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0x803;
  local_2c.lpfnWndProc = Palette_Subsystem_004997e6;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x14;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = GetStockObject(4);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  DAT_0054b360 = CreatePopupMenu();
  return AVar1 != 0;
}



/*
 * Decompiled function: Palette_Subsystem_004997b8
 * Entry Point: 004997b8
 * Size: 46 bytes
 */


void Palette_Subsystem_004997b8(void)

{
  if (DAT_0054b360 != (HMENU)0x0) {
    DestroyMenu(DAT_0054b360);
  }
  DAT_0054b360 = (HMENU)0x0;
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004997e6
 * Entry Point: 004997e6
 * Size: 4913 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Palette_Subsystem_004997e6(HWND hwnd,uint uMsg,int *wParam,int *lParam)

{
  POINT Point;
  byte bVar1;
  int *piVar2;
  LONG LVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  HBRUSH pHVar7;
  DWORD DVar8;
  HWND pHVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  LRESULT LVar13;
  tagPOINT local_30c;
  int local_304;
  tagPOINT local_300;
  tagRECT local_2f8;
  int local_2e8;
  int local_2e4;
  uint local_2e0;
  HDC local_2dc;
  tagPAINTSTRUCT local_2d8;
  int local_298;
  tagRECT local_294;
  uint local_284;
  DWORD local_280;
  int local_264;
  int local_260;
  int local_25c;
  int local_258;
  int *local_254;
  char local_250 [264];
  ULONG_PTR local_148;
  char local_144 [264];
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  LONG local_c;
  int *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      local_14 = GetWindowLongA(hwnd,0xc);
      local_c = GetWindowLongA(hwnd,0x10);
      if ((((local_8 == (int *)0xffffffff) || (DAT_006ff2e8 == local_8)) ||
          (DAT_006a49f4 + -1 < (int)local_8)) && ((DAT_006fe444 == 2 && (hwnd == DAT_0069f744)))) {
        SendMessageA(hwnd,0x113,1,0);
        LVar13 = DefWindowProcA(hwnd,0xf,(WPARAM)wParam,(LPARAM)lParam);
        return LVar13;
      }
      if (DAT_00695e94 == local_8) {
        local_284 = Ai_Subsystem_004b59d9(local_10,local_18);
      }
      else if (DAT_0068a694 == local_8) {
        Ai_Subsystem_004b650c(local_10,local_18,(int *)&local_2e0,&local_2e4);
        local_284 = local_2e4 << 0x10 | local_2e0 & 0xffff;
      }
      else {
        local_284 = 0;
      }
      if ((local_10 == -1) || (local_18 == -1)) {
        local_298 = 0;
      }
      else {
        bVar1 = Ai_Subsystem_004b6356(local_10,local_18);
        local_298 = Card_ColorMaskToColorIndex(bVar1);
      }
      if (local_14 != local_284) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_c != local_298) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_280 = GetTickCount();
      GetClientRect(hwnd,&local_294);
      local_2dc = BeginPaint(hwnd,&local_2d8);
      if (local_2dc != (HDC)0x0) {
        GDI_RealizeAndFlushPalette_Magic(local_2dc);
        if (DAT_0068a674 != 0) {
          pHVar7 = GetStockObject(0);
          FillRect(local_2dc,&local_294,pHVar7);
          Sleep(200);
        }
        if (DAT_006a49f4 + -1 < (int)local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if (((int)local_8 < 0) || (DAT_006ff2e8 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if ((((DAT_00695e94 == local_8) || (DAT_0068a70c == local_8)) ||
                 (DAT_0068a694 == local_8)) || (DAT_006a2848 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18);
          if (iVar5 == -1) {
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          }
          else {
            Palette_Subsystem_0049eda9
                      (g_HdcBackBuffer,&local_294.left,(int)local_8,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else if (DAT_006ff2dc == local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18);
          if (iVar5 == -1) {
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
          }
          else {
            Palette_Subsystem_0049ebf6(g_HdcBackBuffer,&local_294,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        }
        else {
          pHVar7 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_294,pHVar7);
          if (((local_10 == -1) || (local_18 == -1)) ||
             (iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18), iVar5 == -1)) {
            if (local_8 == (int *)0xffffffff) {
              Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_294);
              local_2e8 = 1;
            }
            else {
              local_2e8 = Palette_Subsystem_0049c7c7
                                    (g_HdcBackBuffer,&local_294.left,
                                     (WPARAM *)(&DAT_006b3070 + (int)local_8 * 0x98),0,0,
                                     DAT_006fe430);
            }
          }
          else {
            local_2e8 = Palette_Subsystem_0049d843
                                  (g_HdcBackBuffer,&local_294.left,
                                   (int)(&DAT_006b3070 + (int)local_8 * 0x98),local_10,local_18,0,
                                   DAT_006fe430);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          if (local_2e8 == 0) {
            if (((local_10 == -1) || (local_18 == -1)) ||
               (iVar5 = Ai_Subsystem_004b5cbb(local_10,local_18), iVar5 == -1)) {
              if (local_8 != (int *)0xffffffff) {
                Palette_Subsystem_0049c7c7
                          (g_HdcBackBuffer,&local_294.left,
                           (WPARAM *)(&DAT_006b3070 + (int)local_8 * 0x98),0,2,DAT_006fe430);
              }
            }
            else {
              Palette_Subsystem_0049d843
                        (g_HdcBackBuffer,&local_294.left,(int)(&DAT_006b3070 + (int)local_8 * 0x98),
                         local_10,local_18,2,DAT_006fe430);
            }
            BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          }
        }
        EndPaint(hwnd,&local_2d8);
        local_14 = local_284;
        SetWindowLongA(hwnd,0xc,local_284);
        local_c = local_298;
        SetWindowLongA(hwnd,0x10,local_298);
      }
      DVar8 = GetTickCount();
      _DAT_00696738 = _DAT_00696738 + (DVar8 - local_280);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = (int *)0xffffffff;
      SetWindowLongA(hwnd,0,-1);
      local_10 = 0xffffffff;
      local_18 = -1;
      SetWindowLongA(hwnd,4,-1);
      SetWindowLongA(hwnd,8,local_18);
      local_14 = 0;
      SetWindowLongA(hwnd,0xc,0);
      local_c = 0;
      SetWindowLongA(hwnd,0x10,0);
      local_254 = lParam;
      local_25c = lParam[5];
      local_264 = lParam[4];
      local_260 = (local_264 * 200) / 300;
      local_258 = (local_25c * 300) / 200;
      iVar5 = abs(local_258 - local_264);
      iVar6 = abs(local_260 - local_25c);
      if (4 < iVar5 + iVar6) {
        if (local_260 < local_25c) {
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_260,local_264,6);
        }
        else {
          SetWindowPos(hwnd,(HWND)0x0,0,0,local_25c,local_258,6);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar13 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,(LPARAM)lParam);
      return LVar13;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x112) {
    if (uMsg == 0x111) {
      uVar4 = (uint)wParam & 0xffff;
      if (uVar4 == 1) {
        DAT_006fe430 = (uint)(DAT_006fe430 == 0);
        Rules_ParseFilter_0050065d();
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      else if (uVar4 == 100) {
        local_3c = (int *)GetWindowLongA(hwnd,0);
        if (DAT_006ff2e8 == local_3c) {
          local_3c = (int *)0xc1b;
        }
        if (local_3c != (int *)0xffffffff) {
          strcpy(local_144,&DAT_006807a0);
          strcat(local_144,s__duel_hlp_0052bbe4);
          WinHelpA(g_MainAppHwnd,local_144,1,(ULONG_PTR)local_3c);
        }
      }
      else if (uVar4 == 0x65) {
        local_148 = 0x7e7;
        strcpy(local_250,&DAT_006807a0);
        strcat(local_250,s__duel_hlp_0052bbf0);
        WinHelpA(g_MainAppHwnd,local_250,1,local_148);
      }
      return 0;
    }
    if (uMsg == 0x46) {
      DefWindowProcA(hwnd,0x46,(WPARAM)wParam,(LPARAM)lParam);
      iVar5 = lParam[4];
      iVar6 = lParam[5];
      iVar10 = (iVar6 * 200) / 300;
      iVar11 = (iVar5 * 300) / 200;
      iVar12 = abs(iVar10 - iVar5);
      iVar6 = abs(iVar11 - iVar6);
      if (iVar12 + iVar6 < 5) {
        return 0;
      }
      if (iVar10 < iVar5) {
        lParam[4] = iVar10;
      }
      else {
        lParam[5] = iVar11;
      }
      return 0;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      AppendMenuA(DAT_0054b360,0,1,s_Expand_text_box_0052bbfc);
      if (DAT_006fe430 != 0) {
        CheckMenuItem(DAT_0054b360,1,8);
      }
      AppendMenuA(DAT_0054b360,0,100,s_Help_for_this_card____0052bc0c);
      AppendMenuA(DAT_0054b360,0,0x65,s_Help____0052bc24);
      return 0;
    }
    if (uMsg == 0x113) {
      if ((wParam == (int *)0x1) && (DAT_006fe444 == 2)) {
        GetCursorPos(&local_30c);
        Point.y = local_30c.y;
        Point.x = local_30c.x;
        pHVar9 = WindowFromPoint(Point);
        if (pHVar9 != hwnd) {
          SendMessageA(hwnd,0x201,1,0);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
      pHVar9 = GetParent(hwnd);
      if (pHVar9 != g_MainAppHwnd) {
        return 0;
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == (int *)0x0)) {
        local_304 = GetMenuItemCount(DAT_0054b360);
        while (local_304 != 0) {
          local_304 = local_304 + -1;
          DeleteMenu(DAT_0054b360,0,0x400);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_300.x = (uint)lParam & 0xffff;
      local_300.y = (uint)lParam >> 0x10;
      ClientToScreen(hwnd,&local_300);
      SetRect(&local_2f8,local_300.x,local_300.y,local_300.x + 1,local_300.y + 1);
      TrackPopupMenu(DAT_0054b360,2,local_300.x,local_300.y,0,hwnd,&local_2f8);
      return 0;
    }
    if (uMsg == 0x201) {
      if (DAT_006fe444 == 2) {
        ShowWindow(hwnd,0);
        KillTimer(hwnd,1);
      }
      return 0;
    }
  }
  else if (uMsg < 0x402) {
    if (uMsg == 0x401) {
      local_8 = wParam;
      local_30 = lParam;
      if (((((DAT_00695e94 == wParam) || (DAT_0068a70c == wParam)) || (DAT_0068a694 == wParam)) ||
          (DAT_006a2848 == wParam)) &&
         (((lParam == (int *)0x0 || (*lParam == -1)) || (lParam[1] == -1)))) {
        return 0;
      }
      if (((lParam != (int *)0x0) && (*lParam != -1)) && (lParam[1] == -1)) {
        return 0;
      }
      if (lParam == (int *)0x0) {
        local_10 = -1;
        local_18 = -1;
      }
      else {
        local_10 = *lParam;
        local_18 = lParam[1];
      }
      local_34 = 0;
      piVar2 = (int *)GetWindowLongA(hwnd,0);
      if (piVar2 != local_8) {
        local_34 = 1;
      }
      LVar3 = GetWindowLongA(hwnd,4);
      if ((LVar3 != local_10) || (LVar3 = GetWindowLongA(hwnd,8), LVar3 != local_18)) {
        local_34 = 1;
      }
      if (local_34 == 0) {
        SendMessageA(hwnd,0x432,0,0);
      }
      else {
        SetWindowLongA(hwnd,0,(LONG)local_8);
        SetWindowLongA(hwnd,4,local_10);
        SetWindowLongA(hwnd,8,local_18);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_006fe444 == 2) {
        ShowWindow(hwnd,5);
        if (hwnd == DAT_0069f744) {
          SetTimer(hwnd,1,12000,(TIMERPROC)0x0);
        }
        BringWindowToTop(hwnd);
      }
      return 0;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      LVar13 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar13;
    }
  }
  else {
    switch(uMsg) {
    case 0x40b:
      local_38 = wParam;
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      if ((*local_38 == local_10) && (local_38[1] == local_18)) {
        SendMessageA(hwnd,0x401,0xffffffff,0);
        return 1;
      }
      return 0;
    case 0x432:
      local_8 = (int *)GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,4);
      local_18 = GetWindowLongA(hwnd,8);
      local_14 = GetWindowLongA(hwnd,0xc);
      if (DAT_00695e94 == local_8) {
        local_20 = Ai_Subsystem_004b59d9(local_10,local_18);
      }
      else if (DAT_0068a694 == local_8) {
        Ai_Subsystem_004b650c(local_10,local_18,(int *)&local_28,&local_2c);
        local_20 = local_2c << 0x10 | local_28 & 0xffff;
      }
      else {
        local_20 = 0;
      }
      local_c = GetWindowLongA(hwnd,0x10);
      if ((local_10 == -1) || (local_18 == -1)) {
        local_24 = 0;
      }
      else {
        bVar1 = Ai_Subsystem_004b6356(local_10,local_18);
        local_24 = Card_ColorMaskToColorIndex(bVar1);
      }
      if (local_20 != local_14) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (local_c != local_24) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if ((local_10 != -1) && (local_18 != -1)) {
        iVar5 = Ai_Subsystem_004b6696(local_10,local_18);
        if (iVar5 != 0) {
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
        piVar2 = (int *)Ai_Subsystem_004b5cbb(local_10,local_18);
        if (piVar2 != local_8) {
          InvalidateRect(hwnd,(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      local_1c = wParam;
      local_1c = (int *)GetWindowLongA(hwnd,0);
      InvalidateRect(hwnd,(RECT *)0x0,0);
      return 0;
    case 0x437:
      return 0;
    }
  }
  LVar13 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return LVar13;
}



/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 0049ae00
 * Size: 2805 bytes
 */


undefined4 Palette_Color_0049ae00(void)

{
  int iVar1;
  LOGFONTA *pLVar2;
  HPEN pHVar3;
  undefined4 uVar4;
  char local_118 [264];
  int local_10;
  int local_c;
  int local_8;
  
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Magim____TTF_0052bc2c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Magis____TTF_0052bc3c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0127m__TTF_0052bc4c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0085m__TTF_0052bc5c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0298m__TTF_0052bc6c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0299m__TTF_0052bc7c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0300m__TTF_0052bc8c);
  AddFontResourceA(local_118);
  DAT_0052a1b8 = 3;
  sprintf(local_118,s__s_Damage_pic_0052bc9c,&DAT_006808d0);
  DAT_0054b9a0 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardCounters_pic_0052bcac,&DAT_006808d0);
  DAT_0054b734 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_ManaSymbols_pic_0052bcc0,&DAT_006808d0);
  DAT_0054b9ac = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardSets_pic_0052bcd4,&DAT_006808d0);
  DAT_0054b580 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Abilities_pic_0052bce4,&DAT_006808d0);
  DAT_0054b960 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_ManaStripes_pic_0052bcf8,&DAT_006808d0);
  DAT_0054b59c = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Summon_pic_0052bd0c,&DAT_006808d0);
  DAT_0054b740 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Dying_pic_0052bd1c,&DAT_006808d0);
  DAT_0054b3cc = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Target_pic_0052bd2c,&DAT_006808d0);
  DAT_0054b598 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CantTarget_pic_0052bd3c,&DAT_006808d0);
  DAT_0054b98c = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_WillUntap_pic_0052bd50,&DAT_006808d0);
  DAT_0054b3d8 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardBack_pic_0052bd64,&DAT_006808d0);
  DAT_0054b920 = Pic_Load_00423833(local_118);
  Pic_Subsystem_00424500(s_prompts_txt_0052bd80,s_COLORWORDS_0052bd74);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649f70),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x64a030),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy(&DAT_00649f30 + local_c * 10,&g_OverworldGoldAmount + iVar1);
  }
  Pic_Subsystem_00424500(s_prompts_txt_0052bd98,s_LANDWORDS_0052bd8c);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649ff0),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649fb0),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy(&DAT_0064a070 + local_c * 10,&g_OverworldGoldAmount + iVar1);
  }
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardTitle_0052bda4,0);
  DAT_0054b8e4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardSubtitle_0052bdb4,0);
  DAT_0054b3d4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardPT_0052bdc4,0);
  DAT_0054b730 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardText_0052bdd0,0);
  DAT_0054b73c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardText_0052bddc,1);
  DAT_0054b994 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_SmallCardTitle_0052bde8,0);
  DAT_0054b95c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_SmallCardPT_0052bdf8,0);
  DAT_0054b58c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_Damage_0052be04,0);
  DAT_0054b380 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_IDTag_0052be0c,0);
  DAT_0054b744 = CreateFontIndirectA(pLVar2);
  DAT_0054b738 = FUN_004f5cbc(0xbe);
  DAT_0054b978 = FUN_004f5cbc(0xca);
  DAT_0054b588 = FUN_004f5cbc(0xc9);
  DAT_0054b57c = FUN_004f5cbc(0xbf);
  DAT_0054b9a8 = FUN_004f5cbc(0xd8);
  DAT_0054b9e4 = FUN_004f5cbc(0x31);
  DAT_0054b9a4 = FUN_004f5cbc(0x9e);
  DAT_0054b570 = FUN_004f5cbc(0x9e);
  DAT_0054b37c = FUN_004f5cbc(0x7c);
  DAT_0054b574 = FUN_004f5cbc(0x2f);
  DAT_0054b578 = FUN_004f5cbc(0xbf);
  DAT_0054b3d0 = FUN_004f5cbc(0x5d);
  DAT_0054b980 = FUN_004f5cbc(0x1f);
  DAT_0054b9ec = FUN_004f5cbc(0xc9);
  DAT_0054b8e0 = FUN_004f5cbc(0xc4);
  DAT_0054b9f0 = FUN_004f5cbc(0xc4);
  DAT_0054b964 = CreatePen(0,0,DAT_0054b9f0);
  DAT_0054b970 = CreatePen(6,2,DAT_0054b3d0);
  DAT_0054b9e8 = CreatePen(6,2,DAT_0054b980);
  local_8 = 1;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    pHVar3 = CreatePen(6,3,(local_c * 0x14 & 0xffU) << 8 | (uint)(byte)((char)local_c * '\n') |
                           (uint)(byte)((char)local_c * 'K') << 0x10);
    *(HPEN *)(&DAT_0054b8f8 + local_c * 4) = pHVar3;
    if (*(int *)(&DAT_0054b8f8 + local_c * 4) == 0) {
      local_8 = 0;
    }
  }
  DAT_0054b97c = CreateSolidBrush(DAT_0054b738);
  DAT_0054b988 = CreateSolidBrush(DAT_0054b978);
  DAT_0054b96c = 0;
  DAT_0054b594 = 0;
  DAT_0054b990 = 0;
  DAT_0054b99c = 0;
  DAT_0054b984 = 0;
  DAT_0054b3c4 = 0;
  DAT_0054b384 = 0;
  DAT_0054b974 = 0;
  DAT_0054b378 = 0;
  DAT_0054b998 = 0;
  DAT_0054b388 = 0;
  DAT_0054b924 = 0;
  DAT_0054b8f4 = 0;
  DAT_0054b584 = 0;
  DAT_0054b748 = 0;
  DAT_0054b590 = 0;
  DAT_0054b3c8 = 0;
  DAT_0054b968 = 0;
  if (((((((((DAT_0054b9a0 == 0) || (DAT_0054b734 == 0)) || (DAT_0054b9ac == 0)) ||
          ((DAT_0054b580 == 0 || (DAT_0054b960 == 0)))) || (DAT_0054b59c == 0)) ||
        (((DAT_0054b740 == 0 || (DAT_0054b3cc == 0)) ||
         ((DAT_0054b598 == 0 ||
          (((DAT_0054b98c == 0 || (DAT_0054b3d8 == 0)) || (DAT_0054b920 == 0)))))))) ||
       ((DAT_0054b8e4 == (HFONT)0x0 || (DAT_0054b3d4 == (HFONT)0x0)))) ||
      (((DAT_0054b73c == (HFONT)0x0 ||
        (((DAT_0054b994 == (HFONT)0x0 || (DAT_0054b95c == (HFONT)0x0)) ||
         ((DAT_0054b58c == (HFONT)0x0 ||
          (((DAT_0054b380 == (HFONT)0x0 || (DAT_0054b744 == (HFONT)0x0)) ||
           (DAT_0054b964 == (HPEN)0x0)))))))) ||
       (((DAT_0054b970 == (HPEN)0x0 || (DAT_0054b9e8 == (HPEN)0x0)) || (local_8 == 0)))))) ||
     ((DAT_0054b97c == (HBRUSH)0x0 || (DAT_0054b988 == (HBRUSH)0x0)))) {
    Palette_Subsystem_0049b8f5();
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}



/*
 * Decompiled function: Palette_Subsystem_0049b8f5
 * Entry Point: 0049b8f5
 * Size: 2066 bytes
 */


void Palette_Subsystem_0049b8f5(void)

{
  char local_110 [264];
  int local_8;
  
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Magim____TTF_0052be14);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Magis____TTF_0052be24);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Tt0127m__TTF_0052be34);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Tt0085m__TTF_0052be44);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Tt0298m__TTF_0052be54);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Tt0299m__TTF_0052be64);
  RemoveFontResourceA(local_110);
  strcpy(local_110,&DAT_006807a0);
  strcat(local_110,s__Tt0300m__TTF_0052be74);
  RemoveFontResourceA(local_110);
  if (DAT_0054b9a0 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b9a0);
    DAT_0054b9a0 = (HANDLE)0x0;
  }
  if (DAT_0054b734 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b734);
    DAT_0054b734 = (HANDLE)0x0;
  }
  if (DAT_0054b9ac != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b9ac);
    DAT_0054b9ac = (HANDLE)0x0;
  }
  if (DAT_0054b580 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b580);
    DAT_0054b580 = (HANDLE)0x0;
  }
  if (DAT_0054b960 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b960);
    DAT_0054b960 = (HANDLE)0x0;
  }
  if (DAT_0054b59c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b59c);
    DAT_0054b59c = (HANDLE)0x0;
  }
  if (DAT_0054b740 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b740);
    DAT_0054b740 = (HANDLE)0x0;
  }
  if (DAT_0054b3cc != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3cc);
    DAT_0054b3cc = (HANDLE)0x0;
  }
  if (DAT_0054b598 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b598);
    DAT_0054b598 = (HANDLE)0x0;
  }
  if (DAT_0054b98c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b98c);
    DAT_0054b98c = (HANDLE)0x0;
  }
  if (DAT_0054b3d8 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3d8);
    DAT_0054b3d8 = (HANDLE)0x0;
  }
  if (DAT_0054b920 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b920);
    DAT_0054b920 = (HANDLE)0x0;
  }
  if (DAT_0054b384 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b384);
    DAT_0054b384 = (HANDLE)0x0;
  }
  if (DAT_0054b3c4 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3c4);
    DAT_0054b3c4 = (HANDLE)0x0;
  }
  if (DAT_0054b984 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b984);
    DAT_0054b984 = (HANDLE)0x0;
  }
  if (DAT_0054b99c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b99c);
    DAT_0054b99c = (HANDLE)0x0;
  }
  if (DAT_0054b990 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b990);
    DAT_0054b990 = (HANDLE)0x0;
  }
  if (DAT_0054b594 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b594);
    DAT_0054b594 = (HANDLE)0x0;
  }
  if (DAT_0054b96c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b96c);
    DAT_0054b96c = (HANDLE)0x0;
  }
  if (DAT_0054b3c8 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3c8);
    DAT_0054b3c8 = (HANDLE)0x0;
  }
  if (DAT_0054b590 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b590);
    DAT_0054b590 = (HANDLE)0x0;
  }
  if (DAT_0054b748 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b748);
    DAT_0054b748 = (HANDLE)0x0;
  }
  if (DAT_0054b584 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b584);
    DAT_0054b584 = (HANDLE)0x0;
  }
  if (DAT_0054b8f4 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b8f4);
    DAT_0054b8f4 = (HANDLE)0x0;
  }
  if (DAT_0054b924 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b924);
    DAT_0054b924 = (HANDLE)0x0;
  }
  if (DAT_0054b388 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b388);
    DAT_0054b388 = (HANDLE)0x0;
  }
  if (DAT_0054b998 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b998);
    DAT_0054b998 = (HANDLE)0x0;
  }
  if (DAT_0054b378 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b378);
    DAT_0054b378 = (HANDLE)0x0;
  }
  if (DAT_0054b974 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b974);
    DAT_0054b974 = (HANDLE)0x0;
  }
  if (DAT_0054b968 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b968);
    DAT_0054b968 = (HANDLE)0x0;
  }
  if (DAT_0054b8e4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b8e4);
  }
  DAT_0054b8e4 = (HGDIOBJ)0x0;
  if (DAT_0054b3d4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b3d4);
  }
  DAT_0054b3d4 = (HGDIOBJ)0x0;
  if (DAT_0054b730 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b730);
  }
  DAT_0054b730 = (HGDIOBJ)0x0;
  if (DAT_0054b73c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b73c);
  }
  DAT_0054b73c = (HGDIOBJ)0x0;
  if (DAT_0054b994 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b994);
  }
  DAT_0054b994 = (HGDIOBJ)0x0;
  if (DAT_0054b95c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b95c);
  }
  DAT_0054b95c = (HGDIOBJ)0x0;
  if (DAT_0054b58c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b58c);
  }
  DAT_0054b58c = (HGDIOBJ)0x0;
  if (DAT_0054b380 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b380);
  }
  DAT_0054b380 = (HGDIOBJ)0x0;
  if (DAT_0054b744 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b744);
  }
  DAT_0054b744 = (HGDIOBJ)0x0;
  if (DAT_0054b964 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b964);
  }
  DAT_0054b964 = (HGDIOBJ)0x0;
  if (DAT_0054b970 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b970);
  }
  DAT_0054b970 = (HGDIOBJ)0x0;
  if (DAT_0054b9e8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b9e8);
  }
  DAT_0054b9e8 = (HGDIOBJ)0x0;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0054b8f8 + local_8 * 4) != 0) {
      DeleteObject(*(HGDIOBJ *)(&DAT_0054b8f8 + local_8 * 4));
      *(undefined4 *)(&DAT_0054b8f8 + local_8 * 4) = 0;
    }
  }
  if (DAT_0054b97c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b97c);
  }
  DAT_0054b97c = (HGDIOBJ)0x0;
  if (DAT_0054b988 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0054b988);
  }
  DAT_0054b988 = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049c107
 * Entry Point: 0049c107
 * Size: 677 bytes
 */


void Palette_Subsystem_0049c107(void)

{
  if (DAT_0054b384 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b384);
    DAT_0054b384 = (HANDLE)0x0;
  }
  if (DAT_0054b3c4 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3c4);
    DAT_0054b3c4 = (HANDLE)0x0;
  }
  if (DAT_0054b984 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b984);
    DAT_0054b984 = (HANDLE)0x0;
  }
  if (DAT_0054b99c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b99c);
    DAT_0054b99c = (HANDLE)0x0;
  }
  if (DAT_0054b990 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b990);
    DAT_0054b990 = (HANDLE)0x0;
  }
  if (DAT_0054b594 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b594);
    DAT_0054b594 = (HANDLE)0x0;
  }
  if (DAT_0054b96c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b96c);
    DAT_0054b96c = (HANDLE)0x0;
  }
  if (DAT_0054b3c8 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b3c8);
    DAT_0054b3c8 = (HANDLE)0x0;
  }
  if (DAT_0054b590 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b590);
    DAT_0054b590 = (HANDLE)0x0;
  }
  if (DAT_0054b748 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b748);
    DAT_0054b748 = (HANDLE)0x0;
  }
  if (DAT_0054b584 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b584);
    DAT_0054b584 = (HANDLE)0x0;
  }
  if (DAT_0054b8f4 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b8f4);
    DAT_0054b8f4 = (HANDLE)0x0;
  }
  if (DAT_0054b924 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b924);
    DAT_0054b924 = (HANDLE)0x0;
  }
  if (DAT_0054b388 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b388);
    DAT_0054b388 = (HANDLE)0x0;
  }
  if (DAT_0054b998 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b998);
    DAT_0054b998 = (HANDLE)0x0;
  }
  if (DAT_0054b378 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b378);
    DAT_0054b378 = (HANDLE)0x0;
  }
  if (DAT_0054b974 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b974);
    DAT_0054b974 = (HANDLE)0x0;
  }
  if (DAT_0054b968 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0054b968);
    DAT_0054b968 = (HANDLE)0x0;
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049c3ac
 * Entry Point: 0049c3ac
 * Size: 794 bytes
 */


undefined4 Palette_Subsystem_0049c3ac(int *player)

{
  undefined4 uVar1;
  int iVar2;
  char local_170 [264];
  char local_68 [100];
  
  if (player == (int *)0x0) {
    uVar1 = 0;
  }
  else if (*player == 0) {
    if (player == &DAT_0054b384) {
      strcpy(local_68,s_CARDBK_Green_0052be84);
    }
    else if (player == &DAT_0054b3c4) {
      strcpy(local_68,s_CARDBK_White_0052be94);
    }
    else if (player == &DAT_0054b984) {
      strcpy(local_68,s_CARDBK_Blue_0052bea4);
    }
    else if (player == &DAT_0054b99c) {
      strcpy(local_68,s_CARDBK_Black_0052beb0);
    }
    else if (player == &DAT_0054b990) {
      strcpy(local_68,s_CARDBK_Red_0052bec0);
    }
    else if (player == &DAT_0054b594) {
      strcpy(local_68,s_CARDBK_Gold_0052becc);
    }
    else if (player == &DAT_0054b96c) {
      strcpy(local_68,s_CARDBK_Artifact_0052bed8);
    }
    else if (player == &DAT_0054b3c8) {
      strcpy(local_68,s_CARDBK_GreenLand_0052bee8);
    }
    else if (player == &DAT_0054b590) {
      strcpy(local_68,s_CARDBK_WhiteLand_0052befc);
    }
    else if (player == &DAT_0054b748) {
      strcpy(local_68,s_CARDBK_BlueLand_0052bf10);
    }
    else if (player == &DAT_0054b584) {
      strcpy(local_68,s_CARDBK_BlackLand_0052bf20);
    }
    else if (player == &DAT_0054b8f4) {
      strcpy(local_68,s_CARDBK_RedLand_0052bf34);
    }
    else if (player == &DAT_0054b924) {
      strcpy(local_68,s_CARDBK_DarklandsLand_0052bf44);
    }
    else if (player == &DAT_0054b388) {
      strcpy(local_68,s_CARDBK_FallenEmpiresLand_0052bf5c);
    }
    else if (player == &DAT_0054b998) {
      strcpy(local_68,s_CARDBK_AntiquitiesLand_0052bf78);
    }
    else if (player == &DAT_0054b378) {
      strcpy(local_68,s_CARDBK_LegendsLand_0052bf90);
    }
    else if (player == &DAT_0054b974) {
      strcpy(local_68,s_CARDBK_ArabianNightsLand_0052bfa4);
    }
    else if (player == &DAT_0054b968) {
      strcpy(local_68,s_CARDBK_Special_0052bfc0);
    }
    else {
      strcpy(local_68,&DAT_0052bfd0);
    }
    if (local_68[0] != '\0') {
      sprintf(local_170,s__s__s_pic_0052bfd4,&DAT_006808d0,local_68);
      iVar2 = Pic_Load_00423833(local_170);
      *player = iVar2;
    }
    if (*player == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_0049c6cb
 * Entry Point: 0049c6cb
 * Size: 252 bytes
 */


void Palette_Subsystem_0049c6cb(HDC hdc,RECT *arg2)

{
  int iVar1;
  int iVar2;
  HBRUSH pHVar3;
  tagRECT local_14;
  
  if ((hdc != (HDC)0x0) && (arg2 != (RECT *)0x0)) {
    if (DAT_0054b920 == (HANDLE)0x0) {
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
    }
    else {
      iVar1 = ((arg2->right - arg2->left) * 3) / 100;
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      iVar2 = ((arg2->bottom - arg2->top) * 2) / 100;
      if (iVar2 < 2) {
        iVar2 = 1;
      }
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
      SetRect(&local_14,arg2->left + iVar1,arg2->top + iVar2,arg2->right - iVar1,
              arg2->bottom - iVar2);
      FUN_004f3b5f((int)hdc,(int)&local_14,DAT_0054b920);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049c7c7
 * Entry Point: 0049c7c7
 * Size: 4215 bytes
 */


undefined4
Palette_Subsystem_0049c7c7(HDC hdc,int *card_slot,WPARAM *arg_3,int arg_4,uint arg_5,int arg_6)

{
  HGDIOBJ pvVar1;
  size_t sVar2;
  int iVar3;
  HBRUSH pHVar4;
  LPCSTR pCVar5;
  WPARAM WVar6;
  undefined *local_1fc;
  undefined1 local_1f0 [4];
  int local_1ec;
  int local_1e8;
  int local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  tagTEXTMETRICA local_1cc;
  tagRECT local_194;
  int local_184;
  uint local_180;
  tagRECT local_17c;
  char local_16c [100];
  WPARAM local_108;
  int *local_104;
  tagRECT local_100;
  HBRUSH local_f0;
  tagRECT local_ec;
  tagRECT local_dc;
  int local_cc;
  COLORREF local_c8;
  int local_c4;
  tagRECT local_c0;
  char local_b0 [52];
  tagRECT local_7c;
  undefined4 local_6c;
  HANDLE local_68;
  tagRECT local_64;
  tagRECT local_54;
  int local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == (WPARAM *)0x0)) {
    local_6c = 0;
  }
  else {
    local_30 = SaveDC(hdc);
    local_c4 = 200;
    local_2c = 300;
    SetMapMode(hdc,7);
    SetWindowExtEx(hdc,local_c4,local_2c,(LPSIZE)0x0);
    SetViewportExtEx(hdc,card_slot[2] - *card_slot,card_slot[3] - card_slot[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,local_c4 / 2,local_2c / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*card_slot + (card_slot[2] - *card_slot) / 2,card_slot[1] + (card_slot[3] - card_slot[1]) / 2,
                     (LPPOINT)0x0);
    local_44 = 6;
    local_28 = 6;
    SetRect(&local_40,0xc,9,0xbc,0x16);
    SetRect(&local_24,0xc,8,0xbe,0x14);
    SetRect(&local_ec,0x15,0x19,0xb5,0xa4);
    SetRect(&local_64,0xc,0xa9,0xba,0xb4);
    SetRect(&local_14,0xc,0xa9,0xba,0xb4);
    SetRect(&local_54,0x1c,0xb9,0xae,0x10c);
    SetRect(&local_7c,0x14,0xb4,0xb6,0x10f);
    SetRect(&local_c0,0xc,0x114,0xbc,0x124);
    SetRect(&local_dc,0xc,0x114,0xbc,0x124);
    if (((arg_3[3] == 0xffffffff) || ((arg_3[3] & 0x10) != 0)) || ((arg_3[3] & 0x80) != 0)) {
      local_f0 = CreateSolidBrush(DAT_0054b738);
      SelectObject(hdc,local_f0);
    }
    else {
      local_f0 = CreateSolidBrush(DAT_0054b978);
      SelectObject(hdc,local_f0);
    }
    pvVar1 = GetStockObject(8);
    SelectObject(hdc,pvVar1);
    RoundRect(hdc,0,0,local_c4,local_2c,local_44 / 2,local_28 / 2);
    pvVar1 = GetStockObject(4);
    SelectObject(hdc,pvVar1);
    if (local_f0 != (HBRUSH)0x0) {
      DeleteObject(local_f0);
    }
    if (arg_3[4] == 1) {
      local_104 = &DAT_0054b99c;
    }
    else if (arg_3[4] == 8) {
      local_104 = &DAT_0054b3c4;
    }
    else if (arg_3[4] == 7) {
      local_104 = &DAT_0054b990;
    }
    else if (arg_3[4] == 5) {
      local_104 = &DAT_0054b384;
    }
    else if (arg_3[4] == 2) {
      local_104 = &DAT_0054b984;
    }
    else if (arg_3[4] == 4) {
      local_104 = &DAT_0054b594;
    }
    else if (arg_3[4] == 0) {
      local_104 = &DAT_0054b96c;
    }
    else if (arg_3[4] == 3) {
      local_104 = &DAT_0054b96c;
    }
    else if (arg_3[4] == 6) {
      if ((arg_3[3] & 2) == 0) {
        if ((arg_3[3] & 4) == 0) {
          if ((arg_3[3] & 0x20) == 0) {
            if ((*(byte *)((int)arg_3 + 0xd) & 1) == 0) {
              if ((arg_3[3] & 8) == 0) {
                iVar3 = strcmp((char *)arg_3[1],s_Swamp_0052bfe0);
                if (iVar3 == 0) {
                  local_104 = &DAT_0054b584;
                }
                else {
                  iVar3 = strcmp((char *)arg_3[1],s_Plains_0052bfe8);
                  if (iVar3 == 0) {
                    local_104 = &DAT_0054b590;
                  }
                  else {
                    iVar3 = strcmp((char *)arg_3[1],s_Mountain_0052bff0);
                    if (iVar3 == 0) {
                      local_104 = &DAT_0054b8f4;
                    }
                    else {
                      iVar3 = strcmp((char *)arg_3[1],s_Forest_0052bffc);
                      if (iVar3 == 0) {
                        local_104 = &DAT_0054b3c8;
                      }
                      else {
                        iVar3 = strcmp((char *)arg_3[1],s_Island_0052c004);
                        if (iVar3 == 0) {
                          local_104 = &DAT_0054b748;
                        }
                        else {
                          local_104 = &DAT_0054b998;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_104 = &DAT_0054b998;
              }
            }
            else {
              local_104 = &DAT_0054b378;
            }
          }
          else {
            local_104 = &DAT_0054b924;
          }
        }
        else {
          local_104 = &DAT_0054b974;
        }
      }
      else {
        local_104 = &DAT_0054b998;
      }
    }
    else if (arg_3[4] == 0xffffffff) {
      local_104 = &DAT_0054b968;
    }
    else {
      local_104 = &DAT_0054b96c;
    }
    Palette_Subsystem_0049c3ac(local_104);
    SetRect(&local_100,local_44,local_28,local_c4 - local_44,local_2c - local_28);
    if (*local_104 == 0) {
      pHVar4 = GetStockObject(0);
      FillRect(hdc,&local_100,pHVar4);
    }
    else {
      FUN_004f3b5f((int)hdc,(int)&local_100,(HANDLE)*local_104);
    }
    local_68 = (HANDLE)*local_104;
    local_cc = 1;
    local_c8 = FUN_004f5cbc(0xbf);
    SelectObject(hdc,DAT_0054b8e4);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_0054b588);
    OffsetRect(&local_40,local_cc,local_cc);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    OffsetRect(&local_40,-local_cc,-local_cc);
    SetTextColor(hdc,local_c8);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    local_108 = 100;
    SelectObject(hdc,DAT_0054b730);
    if ((arg_3[0x1f] != 0) || (arg_3[0x20] != 0)) {
      local_b0[0] = '\0';
      if (arg_3[0x1f] == local_108) {
        strcat(local_b0,&DAT_0052c00c);
      }
      else if ((int)local_108 < (int)arg_3[0x1f]) {
        iVar3 = arg_3[0x1f] - local_108;
        pCVar5 = &DAT_0052c010;
        sVar2 = strlen(local_b0);
        wsprintfA(local_b0 + sVar2,pCVar5,iVar3);
      }
      else {
        WVar6 = arg_3[0x1f];
        pCVar5 = &DAT_0052c018;
        sVar2 = strlen(local_b0);
        wsprintfA(local_b0 + sVar2,pCVar5,WVar6);
      }
      strcat(local_b0,&DAT_0052c01c);
      if (arg_3[0x20] == local_108) {
        strcat(local_b0,&DAT_0052c020);
      }
      else if ((int)local_108 < (int)arg_3[0x20]) {
        iVar3 = arg_3[0x20] - local_108;
        pCVar5 = &DAT_0052c024;
        sVar2 = strlen(local_b0);
        wsprintfA(local_b0 + sVar2,pCVar5,iVar3);
      }
      else {
        WVar6 = arg_3[0x20];
        pCVar5 = &DAT_0052c02c;
        sVar2 = strlen(local_b0);
        wsprintfA(local_b0 + sVar2,pCVar5,WVar6);
      }
      SetTextColor(hdc,DAT_0054b588);
      OffsetRect(&local_dc,local_cc,local_cc);
      DrawTextA(hdc,local_b0,-1,&local_dc,0x26);
      OffsetRect(&local_dc,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_b0,-1,&local_dc,0x26);
    }
    SelectObject(hdc,DAT_0054b3d4);
    SetBkMode(hdc,1);
    if ((arg_3[5] != 0xffffffff) && (arg_3[5] != 0)) {
      if ((arg_3[5] == 2) && ((arg_3[6] == 0 || (arg_3[6] == 0xda)))) {
        strcpy(local_16c,s_Enchantment_0052c030);
      }
      else {
        if ((arg_3[6] == 0) || (arg_3[6] == 0xda)) {
          local_1fc = &DAT_0052c03c;
        }
        else {
          local_1fc = (&PTR_DAT_00528cc8)[arg_3[6]];
        }
        sprintf(local_16c,s__s__s_0052c040,(&PTR_DAT_00528ca0)[arg_3[5]],local_1fc);
      }
      SetTextColor(hdc,DAT_0054b588);
      OffsetRect(&local_64,local_cc,local_cc);
      DrawTextA(hdc,local_16c,-1,&local_64,0x24);
      OffsetRect(&local_64,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_16c,-1,&local_64,0x24);
    }
    if (arg_3[0x10] != 0) {
      wsprintfA(local_b0,s_Illus___s_0052c048,arg_3[0x10]);
      SetTextColor(hdc,DAT_0054b588);
      OffsetRect(&local_c0,local_cc,local_cc);
      DrawTextA(hdc,local_b0,-1,&local_c0,0x824);
      OffsetRect(&local_c0,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_b0,-1,&local_c0,0x824);
    }
    if (((arg_3[5] != 5) && (arg_3[5] != 8)) && (arg_3[5] != 0)) {
      Palette_Subsystem_0049dc11(hdc,(int)&local_24,(char *)(arg_3 + 10));
    }
    if (arg_3[3] != 0xffffffff) {
      Palette_Subsystem_0049da83((int)hdc,(int)&local_14,arg_3[3]);
    }
    if (DAT_00695ea4 != 0) {
      CopyRect(&local_17c,&local_ec);
      LPtoDP(hdc,(LPPOINT)&local_17c,2);
      if ((arg_5 & 0xf) == 0) {
        iVar3 = FUN_0047865c(*arg_3,arg_4);
        if (iVar3 == 0) {
          FUN_0046bfc2(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          FUN_00478763(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      else if ((arg_5 & 0xf) == 1) {
        iVar3 = FUN_0047865c(*arg_3,arg_4);
        if (iVar3 == 0) {
          if (((arg_5 & 0x10) != 0) && (iVar3 = FUN_0046bf31(*arg_3,arg_4), iVar3 != 0)) {
            FUN_0046bfc2(hdc,&local_ec,*arg_3,arg_4);
          }
          FUN_00478370(*arg_3,arg_4,local_17c.right - local_17c.left,
                       local_17c.bottom - local_17c.top);
        }
        FUN_00478763(hdc,&local_ec,*arg_3,arg_4);
      }
      else {
        iVar3 = FUN_0047865c(*arg_3,arg_4);
        if (((iVar3 == 0) && ((arg_5 & 0x10) != 0)) &&
           (iVar3 = FUN_0046bf31(*arg_3,arg_4), iVar3 != 0)) {
          FUN_0046bfc2(hdc,&local_ec,*arg_3,arg_4);
        }
        iVar3 = FUN_00478370(*arg_3,arg_4,local_17c.right - local_17c.left,
                             local_17c.bottom - local_17c.top);
        if (iVar3 == 0) {
          FUN_0046bfc2(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          FUN_00478763(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      local_6c = FUN_004786f3(*arg_3,arg_4,local_17c.right - local_17c.left,
                              local_17c.bottom - local_17c.top);
    }
    SetTextColor(hdc,DAT_0054b9ec);
    SetBkMode(hdc,1);
    if (arg_6 != 0) {
      SelectObject(hdc,DAT_0054b73c);
      local_180 = Palette_Subsystem_0049e53b(hdc,(int)&local_54,arg_3[0x1d]);
      local_180 = local_180 >> 0x10;
      GetTextMetricsA(hdc,&local_1cc);
      CopyRect(&local_194,&local_54);
      local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 2;
      SelectObject(hdc,DAT_0054b994);
      DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&local_194,0x410);
      local_184 = local_194.bottom - local_54.top;
      if (local_54.bottom - local_54.top < local_184) {
        local_1d8 = local_54.top - local_7c.top;
        local_54.top = local_54.bottom - local_184;
        local_7c.top = local_54.top - local_1d8;
        if (local_68 == (HANDLE)0x0) {
          pHVar4 = GetStockObject(0);
          FillRect(hdc,&local_7c,pHVar4);
        }
        else {
          GetObjectA(local_68,0x18,local_1f0);
          local_1d0 = 0x359;
          local_1d4 = 0x140;
          FUN_004f3bc7(hdc,&local_7c.left,local_68,(local_1ec * 0x49) / 1000,
                       (local_1e8 * 0x25d) / 1000,(local_1ec * 0x359) / 1000,
                       (local_1e8 * 0x140) / 1000);
        }
      }
    }
    SelectObject(hdc,DAT_0054b73c);
    local_180 = Palette_Subsystem_0049e5bc(hdc,&local_54.left,(char *)arg_3[0x1d],1);
    local_180 = local_180 >> 0x10;
    GetTextMetricsA(hdc,&local_1cc);
    CopyRect(&local_194,&local_54);
    local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 3;
    SelectObject(hdc,DAT_0054b994);
    DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&local_194,0x10);
    RestoreDC(hdc,local_30);
  }
  return local_6c;
}



/*
 * Decompiled function: Palette_Subsystem_0049d843
 * Entry Point: 0049d843
 * Size: 576 bytes
 */


undefined4
Palette_Subsystem_0049d843(HDC hdc,int *card_slot,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7)

{
  byte player;
  undefined4 uVar1;
  char local_2a0 [500];
  int local_ac;
  int local_a8;
  WPARAM local_a4 [4];
  int local_94;
  char *local_30;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (card_slot == (int *)0x0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    local_8 = Ai_Subsystem_004b5cbb(arg_4,arg_5);
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else {
      memcpy(local_a4,&DAT_006b3070 + local_8 * 0x98,0x98);
      local_ac = local_94;
      player = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_a8 = Card_ColorMaskToColorIndex(player);
      if (((((local_ac == 1) || (local_ac == 8)) ||
           ((local_ac == 7 || ((local_ac == 5 || (local_ac == 2)))))) ||
          ((local_ac == 6 && (local_a8 != 0)))) || ((local_ac == 3 && (local_a8 != 0)))) {
        if (local_a8 == 1) {
          local_94 = 1;
        }
        else if (local_a8 == 5) {
          local_94 = 8;
        }
        else if (local_a8 == 3) {
          local_94 = 5;
        }
        else if (local_a8 == 4) {
          local_94 = 7;
        }
        else if (local_a8 == 2) {
          local_94 = 2;
        }
      }
      strcpy(local_2a0,*(char **)(&DAT_006b30e4 + local_8 * 0x98));
      Ai_Subsystem_004b68b3(arg_4,arg_5,local_2a0);
      Ai_Subsystem_004b69ba(arg_4,arg_5,local_2a0);
      local_30 = local_2a0;
      local_c = FUN_00478aa4(local_8,arg_4,arg_5);
      uVar1 = Palette_Subsystem_0049c7c7(hdc,card_slot,local_a4,local_c,arg_6,arg_7);
    }
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_0049da83
 * Entry Point: 0049da83
 * Size: 398 bytes
 */


void Palette_Subsystem_0049da83(int player,int card_slot,uint arg_3)

{
  undefined1 local_44 [4];
  int local_40;
  int local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  if ((((((player != 0) && (card_slot != 0)) && ((arg_3 & 0x800) == 0)) &&
       ((arg_3 != 0xffffffff && ((arg_3 & 0x10) == 0)))) &&
      (((arg_3 & 0x80) == 0 && (DAT_0054b580 != (HANDLE)0x0)))) &&
     (((arg_3 & 0x2e) != 0 || ((arg_3 & 0x100) != 0)))) {
    GetObjectA(DAT_0054b580,0x18,local_44);
    local_24 = local_40 / 10;
    local_2c = local_3c;
    if ((arg_3 & 0x20) == 0) {
      if ((arg_3 & 0x100) == 0) {
        if ((arg_3 & 4) == 0) {
          if ((arg_3 & 2) == 0) {
            if ((arg_3 & 8) != 0) {
              local_20 = local_24 << 3;
            }
          }
          else {
            local_20 = local_24 * 6;
          }
        }
        else {
          local_20 = local_24 << 2;
        }
      }
      else {
        local_20 = local_24 * 2;
      }
    }
    else {
      local_20 = 0;
    }
    local_c = local_24 + local_20;
    local_8 = *(int *)(card_slot + 0xc) - *(int *)(card_slot + 4);
    local_28 = (local_8 * local_24) / local_3c;
    SetRect(&local_1c,*(int *)(card_slot + 8) - local_28,*(int *)(card_slot + 4),*(int *)(card_slot + 8),
            *(int *)(card_slot + 4) + local_8);
    FUN_004f3eaa((HDC)player,&local_1c.left,DAT_0054b580,local_24,local_2c,local_20,0,local_c,0);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049dc11
 * Entry Point: 0049dc11
 * Size: 196 bytes
 */


void Palette_Subsystem_0049dc11(HDC hdc,int card_slot,char *str_3)

{
  UINT align;
  char local_34 [20];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (((hdc != (HDC)0x0) && (card_slot != 0)) && (str_3 != (char *)0x0)) {
    local_20 = (int)*str_3;
    local_1c = (int)str_3[1];
    local_c = (int)str_3[8];
    local_14 = (int)str_3[5];
    local_10 = (int)str_3[7];
    local_18 = (int)str_3[2];
    Palette_Subsystem_0049ddaa(&local_20,local_34);
    align = SetTextAlign(hdc,2);
    Palette_Subsystem_0049dfb1
              (hdc,*(int *)(card_slot + 8),*(int *)(card_slot + 4),
               *(int *)(card_slot + 0xc) - *(int *)(card_slot + 4),local_34);
    SetTextAlign(hdc,align);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049dcd5
 * Entry Point: 0049dcd5
 * Size: 213 bytes
 */


int Palette_Subsystem_0049dcd5(HDC hdc,char *str_2)

{
  BOOL BVar1;
  int local_50;
  int local_4c;
  tagTEXTMETRICA local_48;
  _ABC local_10;
  
  if (str_2 == (char *)0x0) {
    local_4c = 0;
  }
  else {
    GetTextMetricsA(hdc,&local_48);
    local_4c = 0;
    for (; *str_2 != '\0'; str_2 = str_2 + 1) {
      if ((*str_2 < -0x12) || ((uint)(int)*str_2 < 0x80000000)) {
        BVar1 = GetCharABCWidthsA(hdc,(int)*str_2,(int)*str_2,&local_10);
        if (BVar1 == 0) {
          GetCharWidthA(hdc,(int)*str_2,(int)*str_2,&local_50);
          local_4c = local_4c + local_50;
        }
        else {
          local_4c = local_10.abcB + local_10.abcC + local_10.abcA + local_4c;
        }
      }
      else {
        local_4c = local_4c + local_48.tmHeight;
      }
    }
  }
  return local_4c;
}



/*
 * Decompiled function: Palette_Subsystem_0049ddaa
 * Entry Point: 0049ddaa
 * Size: 519 bytes
 */


int Palette_Subsystem_0049ddaa(int *arg1,char *str_2)

{
  int local_58;
  int local_54;
  int local_50;
  char local_4c [52];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg1 == (int *)0x0) || (str_2 == (char *)0x0)) {
    local_50 = 0;
  }
  else {
    local_10 = arg1[5];
    local_8 = arg1[3];
    local_14 = arg1[4];
    local_58 = arg1[1];
    local_54 = arg1[2];
    local_18 = *arg1;
    local_50 = 0;
    if (local_18 != 0) {
      if (local_18 == -1) {
        local_4c[0] = -0x10;
        local_50 = 1;
      }
      else if (local_18 == 0x48) {
        local_4c[0] = -0x10;
        local_50 = 1;
      }
      else if ((local_18 < 1) || (9 < local_18)) {
        if (local_18 == 10) {
          local_4c[0] = -0x11;
          local_50 = 1;
        }
      }
      else {
        local_4c[0] = (char)local_18 + -0xf;
        local_50 = 1;
      }
    }
    local_c = 0;
    while (local_c == 0) {
      if (local_10 == 0) {
        if (local_8 == 0) {
          if (local_14 == 0) {
            if (local_58 == 0) {
              if (local_54 == 0) {
                local_4c[local_50] = '\0';
                local_c = 1;
              }
              else {
                local_4c[local_50] = -3;
                local_50 = local_50 + 1;
                local_54 = local_54 + -1;
              }
            }
            else {
              local_4c[local_50] = -2;
              local_50 = local_50 + 1;
              local_58 = local_58 + -1;
            }
          }
          else {
            local_4c[local_50] = -4;
            local_50 = local_50 + 1;
            local_14 = local_14 + -1;
          }
        }
        else {
          local_4c[local_50] = -1;
          local_50 = local_50 + 1;
          local_8 = local_8 + -1;
        }
      }
      else {
        local_4c[local_50] = -5;
        local_50 = local_50 + 1;
        local_10 = local_10 + -1;
      }
    }
    if ((((local_18 == 0) && (local_50 == 0)) && (local_10 == 0)) &&
       (((local_8 == 0 && (local_14 == 0)) && ((local_58 == 0 && (local_54 == 0)))))) {
      local_4c[0] = -0xf;
      local_4c[1] = 0;
    }
    if (str_2 != (char *)0x0) {
      strcpy(str_2,local_4c);
    }
  }
  return local_50;
}



/*
 * Decompiled function: Palette_Subsystem_0049dfb1
 * Entry Point: 0049dfb1
 * Size: 736 bytes
 */


uint Palette_Subsystem_0049dfb1(HDC hdc,int card_slot,int arg_3,LONG arg_4,char *str_5)

{
  uint uVar1;
  HFONT pHVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  LOGFONTA local_d4;
  int local_98;
  int local_94;
  HFONT local_90;
  tagTEXTMETRICA local_8c;
  int local_54;
  UINT local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined4 local_2f;
  _ABC local_10;
  
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 400;
  local_38 = 0;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0;
  local_32 = 0;
  local_31 = 0;
  local_30 = 0;
  puVar5 = &local_2f;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  if ((hdc == (HDC)0x0) || (str_5 == (char *)0x0)) {
    uVar1 = 0;
  }
  else {
    local_94 = SaveDC(hdc);
    memcpy(&local_d4,&local_4c,0x3c);
    local_d4.lfHeight = arg_4;
    strcpy(local_d4.lfFaceName,s_REGULAR_0052c054);
    local_90 = CreateFontIndirectA(&local_d4);
    if (local_90 == (HFONT)0x0) {
      local_90 = GetStockObject(0xd);
    }
    SelectObject(hdc,local_90);
    GetTextMetricsA(hdc,&local_8c);
    local_54 = local_8c.tmHeight;
    local_98 = local_8c.tmHeight;
    local_50 = GetTextAlign(hdc);
    if (((byte)local_50 & 0x18) == 0x18) {
      arg_3 = arg_3 - local_8c.tmAscent;
    }
    else if ((local_50 & 8) != 0) {
      arg_3 = arg_3 - local_8c.tmHeight;
    }
    if (((byte)local_50 & 6) == 6) {
      iVar4 = Palette_Subsystem_0049dcd5(hdc,str_5);
      card_slot = card_slot - iVar4 / 2;
    }
    else if ((local_50 & 2) != 0) {
      iVar4 = Palette_Subsystem_0049dcd5(hdc,str_5);
      card_slot = card_slot - iVar4;
    }
    SetTextAlign(hdc,0);
    for (; *str_5 != '\0'; str_5 = str_5 + 1) {
      if ((*str_5 < -0x12) || ((uint)(int)*str_5 < 0x80000000)) {
        GetCharABCWidthsA(hdc,(int)*str_5,(int)*str_5,&local_10);
        TextOutA(hdc,card_slot,arg_3,str_5,1);
        card_slot = local_10.abcC + local_10.abcB + card_slot + local_10.abcA;
      }
      else {
        Palette_Subsystem_0049e291((int)hdc,*str_5,card_slot,arg_3,local_98,local_54);
        card_slot = card_slot + local_98;
      }
    }
    SetTextAlign(hdc,local_50);
    RestoreDC(hdc,local_94);
    pHVar2 = GetStockObject(0xd);
    if (pHVar2 != local_90) {
      DeleteObject(local_90);
    }
    sVar3 = strlen(str_5);
    uVar1 = sVar3 * local_98 & 0xffff | local_54 << 0x10;
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_0049e291
 * Entry Point: 0049e291
 * Size: 682 bytes
 */


void Palette_Subsystem_0049e291(int player,char card_slot,int arg_3,int arg_4,int arg_5,int arg_6)

{
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (((player != 0) && (-0x13 < card_slot)) && (card_slot < '\0')) {
    GetObjectA(DAT_0054b9ac,0x18,local_3c);
    local_20 = local_34;
    local_24 = local_34;
    local_8 = local_38 - local_34;
    if (card_slot == -0x10) {
      local_1c = 0;
    }
    else if (card_slot == -0xf) {
      local_1c = local_34;
    }
    else if (card_slot == -0xe) {
      local_1c = local_34 * 2;
    }
    else if (card_slot == -0xd) {
      local_1c = local_34 * 3;
    }
    else if (card_slot == -0xc) {
      local_1c = local_34 << 2;
    }
    else if (card_slot == -0xb) {
      local_1c = local_34 * 5;
    }
    else if (card_slot == -10) {
      local_1c = local_34 * 6;
    }
    else if (card_slot == -9) {
      local_1c = local_34 * 7;
    }
    else if (card_slot == -8) {
      local_1c = local_34 << 3;
    }
    else if (card_slot == -7) {
      local_1c = local_34 * 9;
    }
    else if (card_slot == -6) {
      local_1c = local_34 * 10;
    }
    else if (card_slot == -0x11) {
      local_1c = local_34 * 0xb;
    }
    else if (card_slot == -5) {
      local_1c = local_34 * 0xc;
    }
    else if (card_slot == -4) {
      local_1c = local_34 * 0xd;
    }
    else if (card_slot == -3) {
      local_1c = local_34 * 0xe;
    }
    else if (card_slot == -2) {
      local_1c = local_34 * 0xf;
    }
    else if (card_slot == -1) {
      local_1c = local_34 << 4;
    }
    else if (card_slot == -0x12) {
      local_1c = local_34 * 0x11;
    }
    SetRect(&local_18,arg_3,arg_4,arg_5 + arg_3,arg_6 + arg_4);
    FUN_004f3eaa((HDC)player,&local_18.left,DAT_0054b9ac,local_20,local_24,local_1c,0,local_8,0);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049e53b
 * Entry Point: 0049e53b
 * Size: 129 bytes
 */


undefined4 Palette_Subsystem_0049e53b(HDC hdc,int card_slot,int arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  
  if (((hdc == (HDC)0x0) || (card_slot == 0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    IntersectClipRect(hdc,0,0,1,1);
    uVar1 = Palette_Subsystem_0049e5bc(hdc,(int *)card_slot,(char *)arg_3,0);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_0049e5bc
 * Entry Point: 0049e5bc
 * Size: 1594 bytes
 */


uint Palette_Subsystem_0049e5bc(HDC hdc,int *y,char *str_3,int height)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  HGDIOBJ pvVar6;
  size_t sVar7;
  char local_b0 [52];
  int local_7c;
  int local_78;
  size_t local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64;
  int local_60;
  tagTEXTMETRICA local_5c;
  int local_24;
  tagRECT local_20;
  tagSIZE local_10;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (y == (int *)0x0)) || (str_3 == (char *)0x0)) {
    uVar3 = 0;
  }
  else if (*str_3 == '\0') {
    uVar3 = 0;
  }
  else {
    local_70 = SaveDC(hdc);
    local_64 = 0;
    local_8 = 0;
    GetTextMetricsA(hdc,&local_5c);
    iVar4 = local_5c.tmExternalLeading + local_5c.tmHeight;
    SetRect(&local_20,0,0,0,local_5c.tmHeight);
    LPtoDP(hdc,(LPPOINT)&local_20,2);
    SetRect(&local_20,0,0,local_20.bottom - local_20.top,0);
    DPtoLP(hdc,(LPPOINT)&local_20,2);
    local_7c = ((local_20.right - local_20.left) * 0x4b) / 100;
    iVar5 = ((local_20.right - local_20.left) * 0x55) / 100;
    local_24 = (local_5c.tmHeight * 0x4b) / 100;
    local_78 = local_5c.tmHeight;
    IntersectClipRect(hdc,*y,y[1],y[2],y[3]);
    pvVar6 = GetStockObject(4);
    SelectObject(hdc,pvVar6);
    pvVar6 = GetStockObject(8);
    SelectObject(hdc,pvVar6);
    local_60 = *y;
    local_6c = y[1];
    while (*str_3 != '\0') {
      if (*str_3 == ' ') {
        local_68 = 0;
        local_b0[0] = *str_3;
        iVar1 = local_68;
        while( true ) {
          local_68 = iVar1 + 1;
          str_3 = str_3 + 1;
          if ((*str_3 == '\0') || (*str_3 != ' ')) break;
          local_b0[iVar1 + 1] = *str_3;
          iVar1 = local_68;
        }
        local_b0[iVar1 + 1] = '\0';
        GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
        if ((y[2] < local_10.cx + local_60) || (local_60 <= *y)) {
          uVar3 = local_60 - *y;
          if (local_60 - *y <= (int)local_64) {
            uVar3 = local_64;
          }
          local_6c = local_6c + iVar4;
          local_60 = *y;
          local_64 = uVar3;
        }
        else {
          sVar7 = strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
      }
      else if ((*str_3 == '\0') || (*str_3 != '\n')) {
        if ((*str_3 < -0x12) || ((uint)(int)*str_3 < 0x80000000)) {
          local_68 = 0;
          local_b0[0] = *str_3;
          iVar1 = local_68;
          while( true ) {
            local_68 = iVar1 + 1;
            str_3 = str_3 + 1;
            if (((*str_3 == '\0') || (*str_3 == ' ')) ||
               ((*str_3 == '\n' || ((-0x13 < *str_3 && (*str_3 < '\0')))))) break;
            local_b0[iVar1 + 1] = *str_3;
            iVar1 = local_68;
          }
          local_b0[iVar1 + 1] = '\0';
          GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + iVar4;
            local_60 = *y;
          }
          sVar7 = strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
        else {
          local_68 = 0;
          local_b0[0] = *str_3;
          pcVar2 = str_3;
          iVar1 = local_68;
          while( true ) {
            local_68 = iVar1 + 1;
            str_3 = pcVar2 + 1;
            if (((*str_3 == '\0') || (*str_3 < -0x12)) || ((uint)(int)*str_3 < 0x80000000)) break;
            local_b0[iVar1 + 1] = *str_3;
            pcVar2 = str_3;
            iVar1 = local_68;
          }
          local_b0[iVar1 + 1] = '\0';
          local_10.cx = local_68 * local_7c;
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + iVar4;
            local_60 = *y;
          }
          local_74 = strlen(local_b0);
          for (local_68 = 0; local_68 < (int)local_74; local_68 = local_68 + 1) {
            if (height == 0) {
              Ellipse(hdc,local_60 + (iVar5 - local_7c) / 2,local_6c + (local_78 - local_24) / 2,
                      local_7c + (iVar5 - local_7c) / 2 + local_60,
                      local_24 + (local_78 - local_24) / 2 + local_6c);
            }
            else {
              Palette_Subsystem_0049e291
                        ((int)hdc,(char)*(undefined4 *)(local_b0 + local_68),
                         local_60 + (iVar5 - local_7c) / 2,local_6c + (local_78 - local_24) / 2,
                         local_7c,local_24);
            }
            local_60 = local_60 + iVar5;
          }
          if (*str_3 == ':') {
            local_b0[0] = *str_3;
            str_3 = pcVar2 + 2;
            local_68 = 1;
            local_b0[1] = 0;
            GetTextExtentPoint32A(hdc,local_b0,1,&local_10);
            sVar7 = strlen(local_b0);
            TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
            local_60 = local_60 + local_10.cx;
          }
        }
      }
      else {
        str_3 = str_3 + 1;
        local_6c = local_6c + iVar4;
        local_60 = *y;
      }
    }
    uVar3 = local_60 - *y;
    if (local_60 - *y <= (int)local_64) {
      uVar3 = local_64;
    }
    local_8 = (iVar4 + local_6c) - y[1];
    local_64 = uVar3;
    RestoreDC(hdc,local_70);
    uVar3 = local_8 << 0x10 | local_64 & 0xffff;
  }
  return uVar3;
}



/*
 * Decompiled function: Palette_Subsystem_0049ebf6
 * Entry Point: 0049ebf6
 * Size: 435 bytes
 */


void Palette_Subsystem_0049ebf6(HDC hdc,RECT *card_slot,int arg_3,int arg_4)

{
  int player;
  int iVar1;
  int local_b0;
  int local_ac;
  uint local_a8;
  WPARAM local_a4 [4];
  undefined4 local_94;
  int local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (card_slot != (RECT *)0x0)) {
    local_8 = Ai_Subsystem_004b6d35(arg_3,arg_4);
    player = Ai_Subsystem_004cbd67(local_8);
    if ((DAT_006ff2dc == player) &&
       (iVar1 = Ai_Subsystem_004b6e3b(arg_3,arg_4), iVar1 == DAT_006a3f74)) {
      Palette_Subsystem_0049c6cb(hdc,card_slot);
    }
    else {
      Ai_Subsystem_004b6da5(&local_b0,arg_3,arg_4);
      local_c = FUN_00478aa4(player,local_b0,local_ac);
      memcpy(local_a4,&DAT_006b3070 + player * 0x98,0x98);
      local_a8 = Ai_Subsystem_004b6356(arg_3,arg_4);
      if ((local_a8 & 2) == 0) {
        if ((local_a8 & 0x20) == 0) {
          if ((local_a8 & 8) == 0) {
            if ((local_a8 & 0x10) == 0) {
              if ((local_a8 & 4) != 0) {
                local_94 = 2;
              }
            }
            else {
              local_94 = 7;
            }
          }
          else {
            local_94 = 5;
          }
        }
        else {
          local_94 = 8;
        }
      }
      else {
        local_94 = 1;
      }
      Palette_Subsystem_0049c7c7(hdc,&card_slot->left,local_a4,local_c,2,DAT_006fe430);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049eda9
 * Entry Point: 0049eda9
 * Size: 2852 bytes
 */


void Palette_Subsystem_0049eda9(HDC hdc,int *card_slot,int arg_3,int arg_4,int arg_5)

{
  byte player;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_354 [400];
  int local_1c4;
  int local_1c0;
  char local_1bc [100];
  char local_158;
  char local_157;
  undefined1 local_156;
  int local_f4;
  uint local_f0;
  int local_ec;
  char local_e8 [52];
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [10];
  undefined1 auStack_6e [10];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_44;
  undefined4 auStack_40 [4];
  undefined4 local_30;
  char *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) {
    local_b0 = Ai_Subsystem_004b6023(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (arg_3 == DAT_00695e94) {
      uVar1 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b928,s_Damage___d_0052c05c,uVar1);
      player = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_b4 = Card_ColorMaskToColorIndex(player);
      if (local_b4 == 1) {
        strcat(&DAT_0054b928,s__Black__0052c068);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_0054b928,s__Blue__0052c074);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_0054b928,s__Red__0052c07c);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_0054b928,s__Green__0052c084);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_0054b928,s__White__0052c090);
      }
    }
    else if (DAT_0068a70c == arg_3) {
      iVar2 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b928,s_Hunting___s_0052c09c,(&PTR_DAT_00528cc8)[iVar2]);
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809e4 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809ec + local_a0 * 0x14));
    }
    else {
      DAT_0054b928 = 0;
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_e8,&DAT_0054b928);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b928,local_e8,iVar2);
    }
    local_ec = Ai_Subsystem_004b5cbb(local_ac,local_a8);
    if ((local_ec == 0x361) || (local_ec == 0x360)) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809e4 + local_ec * 0x14));
    }
    local_98 = &DAT_0054b928;
    local_9c = &DAT_0054b928;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0;
    local_88 = 0xffffffff;
    local_84 = 0xffffffff;
    local_80 = 0xffffffff;
    local_7c = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_78[local_a4] = 0;
    }
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_6e[local_a4] = 0;
    }
    local_64 = 0xffffffff;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0xffffffff;
    for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
      auStack_40[local_a4] = 0;
    }
    local_30 = 0xffffffff;
    if (arg_3 == DAT_00695e94) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e0 + local_a0 * 0x14));
    }
    else if (DAT_0068a70c == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809f0 + local_a0 * 0x14));
    }
    else {
      DAT_0054b5a0 = '\0';
    }
    Ai_Subsystem_004b68b3(arg_4,arg_5,&DAT_0054b5a0);
    Ai_Subsystem_004b69ba(arg_4,arg_5,&DAT_0054b5a0);
    local_1bc[1] = 0;
    local_1bc[0] = -0x12;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0a8,0,local_1bc);
    local_1bc[0] = -2;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0ac,0,local_1bc);
    local_1bc[0] = -3;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b0,0,local_1bc);
    local_1bc[0] = -5;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b4,0,local_1bc);
    local_1bc[0] = -4;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b8,0,local_1bc);
    local_1bc[0] = -1;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0bc,0,local_1bc);
    local_158 = '|';
    local_156 = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      local_1bc[0] = (char)local_a4 + -0xf;
      local_157 = (char)local_a4 + '0';
      FUN_004f4a92(&DAT_0054b5a0,&local_158,0,local_1bc);
    }
    Ai_Subsystem_004b650c(arg_4,arg_5,&local_1c0,&local_f4);
    sprintf(local_1bc,s___d___d_0052c0c0,local_1c0,local_f4);
    FUN_004f4a92(&DAT_0054b5a0,s___X___X_0052c0c8,0,local_1bc);
    sprintf(local_1bc,s__0___d_0052c0d0,local_f4);
    FUN_004f4a92(&DAT_0054b5a0,s__0___X_0052c0d8,0,local_1bc);
    sprintf(local_1bc,s___d__0_0052c0e0,local_1c0);
    FUN_004f4a92(&DAT_0054b5a0,s___X__0_0052c0e8,0,local_1bc);
    if (local_a0 == 0x132) {
      local_f0 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      if (local_f0 == 1) {
        strcpy(local_1bc,s_swampwalk_0052c0f0);
      }
      else if (local_f0 == 0x10) {
        strcpy(local_1bc,s_plainswalk_0052c0fc);
      }
      else if (local_f0 == 4) {
        strcpy(local_1bc,s_forestwalk_0052c108);
      }
      else if (local_f0 == 8) {
        strcpy(local_1bc,s_mountainwalk_0052c114);
      }
      else if (local_f0 == 2) {
        strcpy(local_1bc,s_islandwalk_0052c124);
      }
      else {
        strcpy(local_1bc,&DAT_0052c130);
      }
      FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c134,0,local_1bc);
    }
    if (local_a0 == 0x21b) {
      local_f0 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      local_1c4 = 0;
      strcpy(local_1bc,&DAT_0052c138);
      if ((local_f0 & 0x20) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c13c);
        }
        strcat(local_1bc,s_flying_0052c144);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x100) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c14c);
        }
        strcat(local_1bc,s_first_strike_0052c154);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x40) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c164);
        }
        strcat(local_1bc,s_banding_0052c16c);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x80) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c174);
        }
        strcat(local_1bc,s_trample_0052c17c);
        local_1c4 = 1;
      }
      FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c184,0,local_1bc);
      Ai_Subsystem_004b650c(arg_4,arg_5,&local_1c0,&local_f4);
      sprintf(local_1bc,s___d___d_0052c188,local_1c0,local_f4);
      FUN_004f4a92(&DAT_0054b5a0,s___X___X_0052c190,0,local_1bc);
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_354,&DAT_0054b5a0);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b5a0,local_354,iVar2);
    }
    if (arg_3 == DAT_00695e94) {
      uVar3 = Ai_Subsystem_004b6c5b(arg_4,arg_5);
      if ((DAT_0054b5a0 != '\0') && (DAT_0054b5a0 != '\n')) {
        strcat(&DAT_0054b5a0,&DAT_0052c198);
      }
      if ((uVar3 & 0x100000) != 0) {
        strcat(&DAT_0054b5a0,s_First_strike_0052c19c);
      }
      if ((uVar3 & 0x80000) != 0) {
        strcat(&DAT_0054b5a0,s_Trample_0052c1ac);
      }
    }
    local_2c = &DAT_0054b5a0;
    local_28 = &DAT_0052c1b4;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    Palette_Subsystem_0049c7c7(hdc,card_slot,&local_a0,local_8,2,DAT_006fe430);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049f8cd
 * Entry Point: 0049f8cd
 * Size: 662 bytes
 */


void Palette_Subsystem_0049f8cd(HDC hdc,int *card_slot,WPARAM *arg_3,int arg_4,int arg_5)

{
  HGDIOBJ h;
  int iVar1;
  tagRECT local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) && (arg_3 != (WPARAM *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,card_slot[2] - *card_slot,card_slot[3] - card_slot[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*card_slot,card_slot[1],(LPPOINT)0x0);
    Palette_Subsystem_0049fb63(hdc,(RECT *)card_slot,(int)arg_3);
    Palette_Subsystem_004a11fa(hdc,card_slot,(char *)arg_3[2],0,1);
    h = GetStockObject(5);
    SelectObject(hdc,h);
    SelectObject(hdc,DAT_0054b964);
    Rectangle(hdc,0,0,200,0x118);
    if (DAT_00695ea4 != 0) {
      SetMapMode(hdc,1);
      local_28 = card_slot[2] - *card_slot;
      local_2c = card_slot[3] - card_slot[1];
      local_30 = (local_28 * 0x12) / 0xe4;
      local_34 = (local_2c * 0xb) / 100 + (local_2c * 8) / 100 + -2;
      local_1c = ((local_28 * 0xd3) / 0xe4 - local_30) + 1;
      local_24 = (local_2c * 0xb2) / 0xbf - local_34;
      SetRect(&local_44,local_30,local_34,local_30 + local_1c,local_24 + local_34);
      iVar1 = FUN_0046bf31(*arg_3,arg_4);
      if (iVar1 == 0) {
        FUN_0046bcc0(*arg_3,arg_4,local_1c,local_24);
      }
      else if (arg_5 != 0) {
        FUN_0046c09f(*arg_3,arg_4,local_1c,local_24);
      }
      local_20 = FUN_0046bfc2(hdc,&local_44,*arg_3,arg_4);
      if (local_20 == 0) {
        FUN_00478763(hdc,&local_44,*arg_3,arg_4);
      }
    }
    RestoreDC(hdc,local_8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049fb63
 * Entry Point: 0049fb63
 * Size: 900 bytes
 */


void Palette_Subsystem_0049fb63(HDC hdc,RECT *card_slot,int arg_3)

{
  int iVar1;
  HBRUSH hbr;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  int *local_20;
  tagRECT local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((hdc != (HDC)0x0) && (card_slot != (RECT *)0x0)) && (arg_3 != 0)) {
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_20 = &DAT_0054b99c;
    }
    else if (*(int *)(arg_3 + 0x10) == 8) {
      local_20 = &DAT_0054b3c4;
    }
    else if (*(int *)(arg_3 + 0x10) == 7) {
      local_20 = &DAT_0054b990;
    }
    else if (*(int *)(arg_3 + 0x10) == 5) {
      local_20 = &DAT_0054b384;
    }
    else if (*(int *)(arg_3 + 0x10) == 2) {
      local_20 = &DAT_0054b984;
    }
    else if (*(int *)(arg_3 + 0x10) == 4) {
      local_20 = &DAT_0054b594;
    }
    else if (*(int *)(arg_3 + 0x10) == 0) {
      local_20 = &DAT_0054b96c;
    }
    else if (*(int *)(arg_3 + 0x10) == 3) {
      local_20 = &DAT_0054b96c;
    }
    else if (*(int *)(arg_3 + 0x10) == 6) {
      if ((*(byte *)(arg_3 + 0xc) & 2) == 0) {
        if ((*(byte *)(arg_3 + 0xc) & 4) == 0) {
          if ((*(byte *)(arg_3 + 0xc) & 0x20) == 0) {
            if ((*(byte *)(arg_3 + 0xd) & 1) == 0) {
              if ((*(byte *)(arg_3 + 0xc) & 8) == 0) {
                iVar1 = strcmp(*(char **)(arg_3 + 4),s_Swamp_0052c1b8);
                if (iVar1 == 0) {
                  local_20 = &DAT_0054b584;
                }
                else {
                  iVar1 = strcmp(*(char **)(arg_3 + 4),s_Plains_0052c1c0);
                  if (iVar1 == 0) {
                    local_20 = &DAT_0054b590;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(arg_3 + 4),s_Mountain_0052c1c8);
                    if (iVar1 == 0) {
                      local_20 = &DAT_0054b8f4;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(arg_3 + 4),s_Forest_0052c1d4);
                      if (iVar1 == 0) {
                        local_20 = &DAT_0054b3c8;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(arg_3 + 4),s_Island_0052c1dc);
                        if (iVar1 == 0) {
                          local_20 = &DAT_0054b748;
                        }
                        else {
                          local_20 = &DAT_0054b998;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_20 = &DAT_0054b998;
              }
            }
            else {
              local_20 = &DAT_0054b378;
            }
          }
          else {
            local_20 = &DAT_0054b924;
          }
        }
        else {
          local_20 = &DAT_0054b974;
        }
      }
      else {
        local_20 = &DAT_0054b998;
      }
    }
    else if (*(int *)(arg_3 + 0x10) == -1) {
      local_20 = &DAT_0054b968;
    }
    else {
      local_20 = &DAT_0054b96c;
    }
    Palette_Subsystem_0049c3ac(local_20);
    if (*local_20 == 0) {
      hbr = GetStockObject(0);
      FillRect(hdc,card_slot,hbr);
    }
    else {
      GetObjectA((HANDLE)*local_20,0x18,local_38);
      SetRect(&local_1c,0,0,200,0x118);
      FUN_004f3bc7(hdc,&local_1c.left,(HANDLE)*local_20,0,0,local_34,(local_30 * 0x3b) / 100);
      local_8 = 0x1e;
      local_c = 0x16;
      SetRect(&local_1c,0,0x16,200,0x34);
      FUN_004f3bc7(hdc,&local_1c.left,(HANDLE)*local_20,0,2,local_34,
                   (((local_30 * 0x3b) / 100) * 0xb) / 100 + 2);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_0049fee7
 * Entry Point: 0049fee7
 * Size: 490 bytes
 */


void Palette_Subsystem_0049fee7(HDC hdc,int *y,uint width,uint height)

{
  size_t sVar1;
  LPCSTR pCVar2;
  char local_14 [12];
  int local_8;
  
  if ((hdc != (HDC)0x0) && (y != (int *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
    local_14[0] = '\0';
    if ((width & 0x4000) == 0) {
      pCVar2 = &DAT_0052c1e8;
      sVar1 = strlen(local_14);
      wsprintfA(local_14 + sVar1,pCVar2,width);
    }
    else {
      strcat(local_14,&DAT_0052c1e4);
    }
    strcat(local_14,&DAT_0052c1ec);
    if ((height & 0x4000) == 0) {
      pCVar2 = &DAT_0052c1f4;
      sVar1 = strlen(local_14);
      wsprintfA(local_14 + sVar1,pCVar2,height);
    }
    else {
      strcat(local_14,&DAT_0052c1f0);
    }
    SelectObject(hdc,DAT_0054b58c);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_14);
    TextOutA(hdc,0xca,0x11a,local_14,sVar1);
    SetTextColor(hdc,DAT_0054b9a4);
    sVar1 = strlen(local_14);
    TextOutA(hdc,0xc6,0x116,local_14,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a00d1
 * Entry Point: 004a00d1
 * Size: 361 bytes
 */


void Palette_Subsystem_004a00d1(HDC hdc,int *card_slot,undefined4 arg_3)

{
  size_t sVar1;
  char local_1c [12];
  int local_10;
  int local_c;
  int local_8;
  
  if ((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,100,0x8c,(LPSIZE)0x0);
    SetViewportExtEx(hdc,card_slot[2] - *card_slot,card_slot[3] - card_slot[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*card_slot,card_slot[1],(LPPOINT)0x0);
    sprintf(local_1c,&DAT_0052c1f8,arg_3);
    SelectObject(hdc,DAT_0054b58c);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    local_c = 100;
    local_10 = 0x8c;
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_1c);
    TextOutA(hdc,local_c + -1,local_10 + -1,local_1c,sVar1);
    SetTextColor(hdc,DAT_0054b570);
    sVar1 = strlen(local_1c);
    TextOutA(hdc,local_c + -3,local_10 + -3,local_1c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a023a
 * Entry Point: 004a023a
 * Size: 344 bytes
 */


undefined4 Palette_Subsystem_004a023a(HDC hdc,int card_slot,undefined4 arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  char local_1c [8];
  tagRECT local_14;
  
  if ((hdc == (HDC)0x0) || (card_slot == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    Palette_Subsystem_004a0392(&local_14,(int *)card_slot);
    uVar1 = FUN_004f3e29(hdc,&local_14,DAT_0054b9a0);
    sprintf(local_1c,&DAT_0052c1fc,arg_3);
    SelectObject(hdc,DAT_0054b380);
    SetTextAlign(hdc,0);
    SetBkMode(hdc,1);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    SetTextColor(hdc,DAT_0054b588);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    OffsetRect(&local_14,-2,-2);
    SetTextColor(hdc,DAT_0054b570);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004a0392
 * Entry Point: 004a0392
 * Size: 212 bytes
 */


void Palette_Subsystem_004a0392(LPRECT arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      iVar1 = arg2[2];
      iVar2 = *arg2;
      iVar3 = arg2[3];
      iVar4 = arg2[1];
      arg1->left = *arg2 + ((iVar1 - iVar2) * 0x41) / 100;
      arg1->right = arg2[2] - ((iVar1 - iVar2) * 3) / 100;
      arg1->top = arg2[1] + ((iVar3 - iVar4) * 8) / 100;
      arg1->bottom = arg2[1] + ((iVar3 - iVar4) * 0x1c) / 100;
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a0466
 * Entry Point: 004a0466
 * Size: 548 bytes
 */


void Palette_Subsystem_004a0466(HDC hdc,int *card_slot,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  char local_20 [8];
  int local_18;
  tagRECT local_14;
  
  if ((((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) && ((arg_3 == 0 || (arg_3 == 1)))) &&
     (((arg_4 != -1 && (arg_5 != 0)) && (iVar1 = Ai_Subsystem_004b5d2e(arg_3,arg_4), iVar1 == 1))))
  {
    local_18 = SaveDC(hdc);
    local_14.left = *card_slot + ((card_slot[2] - *card_slot) * 0x50) / 100;
    local_14.top = card_slot[1];
    local_14.right = *card_slot + ((card_slot[2] - *card_slot) * 0x5f) / 100;
    local_14.bottom = card_slot[1] + ((card_slot[3] - card_slot[1]) * 0xe) / 100;
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    sprintf(local_20,&DAT_0052c200,arg_4);
    SelectObject(hdc,DAT_0054b744);
    if (arg_3 == 0) {
      SetBkColor(hdc,DAT_0054b37c);
    }
    else {
      SetBkColor(hdc,DAT_0054b574);
    }
    OffsetRect(&local_14,1,1);
    SetTextColor(hdc,DAT_0054b588);
    SetBkMode(hdc,2);
    DrawTextA(hdc,local_20,-1,&local_14,0x25);
    OffsetRect(&local_14,-1,-1);
    SetTextColor(hdc,DAT_0054b578);
    SetBkMode(hdc,1);
    DrawTextA(hdc,local_20,-1,&local_14,0x25);
    RestoreDC(hdc,local_18);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a068a
 * Entry Point: 004a068a
 * Size: 385 bytes
 */


undefined4 Palette_Subsystem_004a068a(int x,int y,int width,int height)

{
  int local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  int local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  tagRECT local_30;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((x == 0) || (y == 0)) {
    local_5c = 0;
  }
  else if ((width < 0) || (0x16 < width)) {
    local_5c = 0;
  }
  else if (DAT_0054b734 == (HANDLE)0x0) {
    local_5c = 0;
  }
  else {
    Palette_Subsystem_004a080b(&local_30,(int *)y,height);
    GetObjectA(DAT_0054b734,0x18,local_58);
    local_34 = local_54;
    local_40 = local_50 / 0x18;
    local_20 = local_30.bottom - local_30.top;
    local_18 = (local_54 * local_20) / local_40;
    local_68 = local_18;
    if (1 < height) {
      local_68 = ((local_30.right - local_30.left) - local_18) / (height + -1);
    }
    local_1c = width * local_40;
    local_38 = local_50 - local_40;
    local_60 = local_30.right - local_18;
    for (local_3c = 0; local_3c < height; local_3c = local_3c + 1) {
      SetRect(&local_14,local_60,local_30.top,local_18 + local_60,local_20 + local_30.top);
      FUN_004f3eaa((HDC)x,&local_14.left,DAT_0054b734,local_34,local_40,0,local_1c,0,local_38);
      local_60 = local_60 - local_68;
    }
    local_5c = 1;
  }
  return local_5c;
}



/*
 * Decompiled function: Palette_Subsystem_004a080b
 * Entry Point: 004a080b
 * Size: 446 bytes
 */


void Palette_Subsystem_004a080b(LPRECT player,int *card_slot,int arg_3)

{
  int local_58;
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (player != (LPRECT)0x0) {
    if (card_slot == (int *)0x0) {
      SetRect(player,0,0,0,0);
    }
    else if (arg_3 == 0) {
      SetRect(player,0,0,0,0);
    }
    else {
      SetRect(&local_24,0,0,0,0);
      if (DAT_0054b734 != (HANDLE)0x0) {
        local_14 = *card_slot + ((card_slot[2] - *card_slot) * 7) / 100;
        local_c = card_slot[2] - ((card_slot[2] - *card_slot) * 10) / 100;
        local_10 = card_slot[1] + ((card_slot[3] - card_slot[1]) * 8) / 100;
        local_8 = card_slot[1] + ((card_slot[3] - card_slot[1]) * 0x23) / 100;
        GetObjectA(DAT_0054b734,0x18,local_4c);
        local_30 = local_48;
        local_34 = local_44 / 0x18;
        local_2c = local_8 - local_10;
        local_28 = (local_48 * local_2c) / local_34;
        for (local_58 = local_28;
            (local_c < (arg_3 + -1) * local_58 + local_28 + local_14 && (1 < local_58));
            local_58 = local_58 + -1) {
        }
        SetRect(&local_24,local_14,local_10,(arg_3 + -1) * local_58 + local_28 + local_14,
                local_10 + local_2c);
      }
      CopyRect(player,&local_24);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a09c9
 * Entry Point: 004a09c9
 * Size: 823 bytes
 */


undefined4 Palette_Subsystem_004a09c9(int player,int *card_slot,int arg_3,int arg_4,int arg_5)

{
  int yTop;
  int local_6c;
  int local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  int local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((player == 0) || (card_slot == (int *)0x0)) {
    local_5c = 0;
  }
  else if (arg_4 + arg_3 + arg_5 == 0) {
    local_5c = 1;
  }
  else if (DAT_0054b734 == (HANDLE)0x0) {
    local_5c = 0;
  }
  else {
    GetObjectA(DAT_0054b734,0x18,local_58);
    local_34 = local_54;
    local_40 = local_50 / 0x18;
    local_2c = card_slot[3] - card_slot[1];
    local_20 = (card_slot[2] - *card_slot) / 3;
    local_18 = *card_slot;
    local_28 = local_20 + local_18;
    local_30 = local_20 + local_28;
    yTop = card_slot[1];
    local_38 = local_50 - local_40;
    local_1c = (local_54 * local_2c) / local_40;
    for (local_6c = local_1c; (local_20 < (arg_5 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_5 + -1) * local_6c + local_18;
    for (local_3c = 0; local_3c < arg_5; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x14;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_004f3eaa((HDC)player,&local_14.left,DAT_0054b734,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    for (local_6c = local_1c; (local_20 < (arg_4 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_4 + -1) * local_6c + local_28;
    for (local_3c = 0; local_3c < arg_4; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x16;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_004f3eaa((HDC)player,&local_14.left,DAT_0054b734,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    for (local_6c = local_1c; (local_20 < (arg_3 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_3 + -1) * local_6c + local_30;
    for (local_3c = 0; local_3c < arg_3; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x15;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_004f3eaa((HDC)player,&local_14.left,DAT_0054b734,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    local_5c = 1;
  }
  return local_5c;
}



/*
 * Decompiled function: Palette_Subsystem_004a0d00
 * Entry Point: 004a0d00
 * Size: 663 bytes
 */


void Palette_Subsystem_004a0d00(HDC hdc,undefined4 *card_slot,uint arg_3)

{
  int arg_5;
  undefined1 local_dc [4];
  int local_d8;
  int local_d4;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  undefined4 local_b0;
  uint local_ac [20];
  int local_5c [17];
  tagRECT local_18;
  int local_8;
  
  local_ac[0] = 0x20;
  local_ac[1] = 0x400;
  local_ac[2] = 0x40;
  local_ac[3] = 0x80;
  local_ac[4] = 0x100;
  local_ac[5] = 0x200;
  local_ac[6] = 1;
  local_ac[7] = 2;
  local_ac[8] = 4;
  local_ac[9] = 8;
  local_ac[10] = 0x10;
  local_ac[0xb] = 0x800;
  local_ac[0xc] = 0x1000;
  local_ac[0xd] = 0x2000;
  local_ac[0xe] = 0x4000;
  local_ac[0xf] = 0x8000;
  local_ac[0x10] = 0x10000;
  local_5c[0] = 0xb;
  local_5c[1] = 0x10;
  local_5c[2] = 0xd;
  local_5c[3] = 0xc;
  local_5c[4] = 0xe;
  local_5c[5] = 0xf;
  local_5c[6] = 3;
  local_5c[7] = 2;
  local_5c[8] = 0;
  local_5c[9] = 1;
  local_5c[10] = 4;
  local_5c[0xb] = 8;
  local_5c[0xc] = 7;
  local_5c[0xd] = 5;
  local_5c[0xe] = 6;
  local_5c[0xf] = 9;
  local_5c[0x10] = 10;
  local_ac[0x11] = 0x11;
  if (((hdc != (HDC)0x0) && (card_slot != (undefined4 *)0x0)) && (arg_3 != 0)) {
    local_c0 = SaveDC(hdc);
    if (DAT_0054b960 != (HANDLE)0x0) {
      GetObjectA(DAT_0054b960,0x18,local_dc);
      local_b8 = local_d8;
      arg_5 = local_d4 / (int)(local_ac[0x11] + 1);
      local_8 = 0;
      local_b4 = local_d4 - arg_5;
      local_b0 = *card_slot;
      local_c4 = card_slot[3] - arg_5;
      for (local_bc = 0; local_bc < (int)local_ac[0x11]; local_bc = local_bc + 1) {
        if ((arg_3 & local_ac[local_bc]) != 0) {
          Palette_Subsystem_004a0f97(&local_18,local_ac[local_bc],card_slot,arg_3);
          local_ac[0x12] = 0;
          local_ac[0x13] = local_5c[local_bc] * arg_5;
          FUN_004f3eaa(hdc,&local_18.left,DAT_0054b960,local_b8,arg_5,0,local_ac[0x13],local_8,
                       local_b4);
        }
      }
    }
    RestoreDC(hdc,local_c0);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a0f97
 * Entry Point: 004a0f97
 * Size: 611 bytes
 */


void Palette_Subsystem_004a0f97(LPRECT player,uint y,int *width,uint height)

{
  undefined1 local_94 [4];
  int local_90;
  int local_8c;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64 [18];
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_64[0] = 0x20;
  local_64[1] = 0x400;
  local_64[2] = 0x40;
  local_64[3] = 0x80;
  local_64[4] = 0x100;
  local_64[5] = 0x200;
  local_64[6] = 1;
  local_64[7] = 2;
  local_64[8] = 4;
  local_64[9] = 8;
  local_64[10] = 0x10;
  local_64[0xb] = 0x800;
  local_64[0xc] = 0x1000;
  local_64[0xd] = 0x2000;
  local_64[0xe] = 0x4000;
  local_64[0xf] = 0x8000;
  local_64[0x10] = 0x10000;
  local_64[0x11] = 0x11;
  if (player != (LPRECT)0x0) {
    if (width == (int *)0x0) {
      SetRect(player,0,0,0,0);
    }
    else if (height == 0) {
      SetRect(player,0,0,0,0);
    }
    else {
      local_74 = ((width[2] - *width) * 0x11) / 100;
      local_8 = local_74;
      if (DAT_0054b960 != (HANDLE)0x0) {
        GetObjectA(DAT_0054b960,0x18,local_94);
        local_78 = local_90;
        local_7c = local_8c / (int)(local_64[0x11] + 1);
        local_8 = (local_74 * local_7c) / local_90;
      }
      local_68 = *width + 1;
      local_70 = (width[3] + -1) - local_8;
      SetRect(&local_1c,0,0,0,0);
      local_c = 1;
      for (local_6c = 0; local_6c < (int)local_64[0x11]; local_6c = local_6c + 1) {
        if ((height & local_64[local_6c]) != 0) {
          if (local_64[local_6c] == y) {
            SetRect(&local_1c,local_68,local_70,local_74 + local_68,local_8 + local_70);
          }
          local_68 = local_68 + local_74 + 1;
          if (((local_c < 3) &&
              (width[2] - ((width[2] - *width) * 0x19) / 100 < local_74 + local_68)) ||
             ((2 < local_c && (width[2] < local_74 + local_68)))) {
            local_68 = *width + 1;
            local_70 = local_70 - (local_8 + 1);
            local_c = local_c + 1;
          }
        }
      }
      CopyRect(player,&local_1c);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a11fa
 * Entry Point: 004a11fa
 * Size: 445 bytes
 */


void Palette_Subsystem_004a11fa(HDC hdc,int *card_slot,char *str_3,int arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_70;
  char local_6c [100];
  int local_8;
  
  if (((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) && (str_3 != (char *)0x0)) {
    strcpy(local_6c,str_3);
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,card_slot[2] - *card_slot,card_slot[3] - card_slot[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*card_slot,card_slot[1],(LPPOINT)0x0);
    if (arg_4 == 0) {
      local_70 = DAT_0054b57c;
    }
    else if (arg_4 == 2) {
      local_70 = DAT_0054b9a8;
    }
    else {
      local_70 = DAT_0054b9e4;
    }
    SelectObject(hdc,DAT_0054b95c);
    SetTextAlign(hdc,0);
    if (arg_5 == 0) {
      SetBkMode(hdc,2);
      SetBkColor(hdc,DAT_0054b8e0);
    }
    else {
      SetBkMode(hdc,1);
    }
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_6c);
    TextOutA(hdc,5,1,local_6c,sVar1);
    SetTextColor(hdc,local_70);
    SetBkMode(hdc,1);
    sVar1 = strlen(local_6c);
    TextOutA(hdc,2,-2,local_6c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a13b7
 * Entry Point: 004a13b7
 * Size: 424 bytes
 */


void Palette_Subsystem_004a13b7(HDC hdc,int *card_slot,int arg_3,undefined4 arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_74;
  char local_70 [100];
  COLORREF local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) && (arg_3 != 0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,card_slot[2] - *card_slot,card_slot[3] - card_slot[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*card_slot,card_slot[1],(LPPOINT)0x0);
    if (arg_5 == 0) {
      local_74 = DAT_0054b57c;
    }
    else if (arg_5 == 2) {
      local_74 = DAT_0054b9a8;
    }
    else {
      local_74 = DAT_0054b9e4;
    }
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_c = 0x808080;
    }
    else {
      local_c = DAT_0054b588;
    }
    SetBkMode(hdc,1);
    SelectObject(hdc,DAT_0054b95c);
    strcpy(local_70,*(char **)(arg_3 + 8));
    SetTextAlign(hdc,0);
    SetTextColor(hdc,local_c);
    sVar1 = strlen(local_70);
    TextOutA(hdc,9,1,local_70,sVar1);
    SetTextColor(hdc,local_74);
    sVar1 = strlen(local_70);
    TextOutA(hdc,8,0,local_70,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a155f
 * Entry Point: 004a155f
 * Size: 1541 bytes
 */


void Palette_Subsystem_004a155f(HDC hdc,int *card_slot,int arg_3,int arg_4,int arg_5)

{
  byte player;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_f4;
  char local_e8 [52];
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined1 *local_9c;
  char *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [10];
  undefined1 auStack_6e [10];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_44;
  undefined4 auStack_40 [4];
  undefined4 local_30;
  undefined1 *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (card_slot != (int *)0x0)) {
    local_b0 = Ai_Subsystem_004b6023(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (DAT_00695e94 == arg_3) {
      uVar1 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b390,s_Damage___d_0052c208,uVar1);
      player = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_b4 = Card_ColorMaskToColorIndex(player);
      if (local_b4 == 1) {
        strcat(&DAT_0054b390,s__Black__0052c214);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_0054b390,s__Blue__0052c220);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_0054b390,s__Red__0052c228);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_0054b390,s__Green__0052c230);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_0054b390,s__White__0052c23c);
      }
    }
    else if (DAT_0068a70c == arg_3) {
      iVar2 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b390,s_Hunting___s_0052c248,(&PTR_DAT_00528cc8)[iVar2]);
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809e4 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809ec + local_a0 * 0x14));
    }
    else if (DAT_006ff2dc == arg_3) {
      strcpy(&DAT_0054b390,s_Activation_0052c254);
    }
    else {
      DAT_0054b390 = 0;
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_e8,&DAT_0054b390);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b390,local_e8,iVar2);
    }
    iVar2 = Ai_Subsystem_004b5cbb(local_ac,local_a8);
    if ((iVar2 == 0x361) || (iVar2 == 0x360)) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809e4 + iVar2 * 0x14));
    }
    local_98 = &DAT_0054b390;
    local_9c = &DAT_0054b390;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0xffffffff;
    local_88 = 0xffffffff;
    local_84 = 0xffffffff;
    local_80 = 0xffffffff;
    local_7c = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_78[local_a4] = 0;
    }
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_6e[local_a4] = 0;
    }
    local_64 = 0xffffffff;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0xffffffff;
    for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
      auStack_40[local_a4] = 0;
    }
    local_30 = 0xffffffff;
    if (DAT_00695e94 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e0 + local_a0 * 0x14));
    }
    else if (DAT_0068a70c == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809f0 + local_a0 * 0x14));
    }
    else {
      DAT_0054b3e0 = 0;
    }
    local_2c = &DAT_0054b3e0;
    local_28 = &DAT_0052c260;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    Palette_Subsystem_0049f8cd(hdc,card_slot,&local_a0,local_8,1);
    Palette_Subsystem_004a2401(hdc,card_slot,arg_4,arg_5);
    iVar2 = Ai_Subsystem_004b65bf(arg_4,arg_5);
    uVar3 = (uint)(iVar2 == arg_4);
    iVar2 = Ai_Subsystem_004b673e(arg_4,arg_5);
    Palette_Subsystem_004a11fa(hdc,card_slot,local_98,iVar2,uVar3);
    if (DAT_00695e94 == arg_3) {
      uVar3 = Ai_Subsystem_004b6c5b(arg_4,arg_5);
      local_f4 = 0;
      if ((uVar3 & 0x100000) != 0) {
        local_f4 = 0x100;
      }
      if ((uVar3 & 0x80000) != 0) {
        local_f4 = local_f4 | 0x80;
      }
      if ((DAT_006fe42c != 0) && (local_f4 != 0)) {
        Palette_Subsystem_004a0d00(hdc,card_slot,local_f4);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a1b64
 * Entry Point: 004a1b64
 * Size: 677 bytes
 */


void Palette_Subsystem_004a1b64
               (HDC hdc,RECT *card_slot,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int iVar1;
  uint arg_5_00;
  int local_b0 [2];
  uint local_a8;
  int local_a4;
  uint local_a0;
  undefined *local_9c;
  char *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [10];
  undefined1 auStack_6e [10];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_44;
  undefined4 auStack_40 [4];
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (card_slot != (RECT *)0x0)) {
    if ((DAT_006ff2dc == arg_3) &&
       (iVar1 = Ai_Subsystem_004b6e3b(arg_4,arg_5), iVar1 == DAT_006a3f74)) {
      Palette_Subsystem_0049c6cb(hdc,card_slot);
      Palette_Subsystem_004a11fa(hdc,&card_slot->left,s_Activation_0052c264,0,1);
    }
    else {
      local_a8 = Ai_Subsystem_004b6023(local_b0,arg_4,arg_5);
      local_8 = local_a8 >> 0x10;
      local_a0 = local_a8 & 0xffff;
      if (DAT_006ff2dc == arg_3) {
        strcpy(&DAT_0054b9b0,s_Activation_0052c270);
      }
      else {
        DAT_0054b9b0 = 0;
      }
      local_98 = &DAT_0054b9b0;
      local_9c = &DAT_0054b9b0;
      local_94 = 0xffffffff;
      local_90 = 0xffffffff;
      local_8c = 0xffffffff;
      local_88 = 0xffffffff;
      local_84 = 0xffffffff;
      local_80 = 0xffffffff;
      local_7c = 0;
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_78[local_a4] = 0;
      }
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_6e[local_a4] = 0;
      }
      local_64 = 0xffffffff;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0xffffffff;
      for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
        auStack_40[local_a4] = 0;
      }
      local_30 = 0xffffffff;
      DAT_0054b750 = 0;
      local_2c = &DAT_0054b750;
      local_28 = &DAT_0052c27c;
      local_24 = 0;
      local_20 = 0;
      local_44 = 0;
      local_c = 0;
      Palette_Subsystem_0049f8cd(hdc,&card_slot->left,&local_a0,local_8,1);
      Palette_Subsystem_004a2401(hdc,&card_slot->left,arg_6,arg_7);
      iVar1 = Ai_Subsystem_004b65bf(arg_4,arg_5);
      arg_5_00 = (uint)(iVar1 == arg_4);
      iVar1 = Ai_Subsystem_004b673e(arg_4,arg_5);
      Palette_Subsystem_004a11fa(hdc,&card_slot->left,local_98,iVar1,arg_5_00);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a1e09
 * Entry Point: 004a1e09
 * Size: 1528 bytes
 */


void Palette_Subsystem_004a1e09(HDC hdc,int *y,int width,int height)

{
  byte player;
  uint uVar1;
  uint width_00;
  int iVar2;
  int width_01;
  HGDIOBJ h;
  int in_stack_00000020;
  int in_stack_00000024;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  WPARAM local_a4;
  char *local_a0;
  char *local_9c;
  int local_94;
  int local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (local_8 = Ai_Subsystem_004b5cbb(width,height), local_8 != -1)) {
    local_a8 = SaveDC(hdc);
    memcpy(&local_a4,&DAT_006b3070 + local_8 * 0x98,0x98);
    local_b0 = local_94;
    player = Ai_Subsystem_004b6356(width,height);
    local_ac = Card_ColorMaskToColorIndex(player);
    if (((((local_b0 == 1) || (local_b0 == 8)) ||
         ((local_b0 == 7 || ((local_b0 == 5 || (local_b0 == 2)))))) ||
        ((local_b0 == 6 && (local_ac != 0)))) || ((local_b0 == 3 && (local_ac != 0)))) {
      if (local_ac == 1) {
        local_94 = 1;
      }
      else if (local_ac == 5) {
        local_94 = 8;
      }
      else if (local_ac == 3) {
        local_94 = 5;
      }
      else if (local_ac == 4) {
        local_94 = 7;
      }
      else if (local_ac == 2) {
        local_94 = 2;
      }
    }
    if (in_stack_00000020 != 0) {
      local_9c = s_Activation_0052c280;
      local_a0 = s_Activation_0052c280;
      local_94 = -1;
    }
    if (in_stack_00000024 != 0) {
      local_9c = s_Upkeep_0052c28c;
      local_a0 = s_Upkeep_0052c28c;
      local_94 = -1;
    }
    local_c = FUN_00478aa4(local_8,width,height);
    Palette_Subsystem_0049f8cd(hdc,y,&local_a4,local_c,1);
    Palette_Subsystem_004a2401(hdc,y,width,height);
    if ((DAT_006fe428 != 0) && (uVar1 = Ai_Subsystem_004b613b(width,height), (uVar1 & 2) != 0)) {
      uVar1 = Ai_Subsystem_004b621a(width,height);
      width_00 = Ai_Subsystem_004b61ac(width,height);
      Palette_Subsystem_0049fee7(hdc,y,width_00,uVar1);
    }
    uVar1 = Ai_Subsystem_004b613b(width,height);
    if ((((uVar1 & 2) != 0) || (DAT_006fe440 != 0)) &&
       (uVar1 = Ai_Subsystem_004b5de4(width,height), (uVar1 & 1) != 0)) {
      Palette_Subsystem_004a26f8(hdc,y);
    }
    uVar1 = Ai_Subsystem_004b613b(width,height);
    if (((uVar1 & 2) != 0) && (iVar2 = Ai_Subsystem_004b6eab(width,height), iVar2 == 2)) {
      Palette_Subsystem_004a277f(hdc,y);
    }
    local_b4 = Ai_Subsystem_004b6288(width,height);
    if ((DAT_006fe42c != 0) && (local_b4 != 0)) {
      Palette_Subsystem_004a0d00(hdc,y,local_b4);
    }
    local_b8 = Ai_Subsystem_004b5bdd(width,height);
    if (local_b8 != 0) {
      Palette_Subsystem_004a023a(hdc,(int)y,local_b8);
    }
    local_c8 = *y + ((y[2] - *y) * 7) / 100;
    local_c0 = y[2] - ((y[2] - *y) * 10) / 100;
    local_c4 = y[1] + ((y[3] - y[1]) * 8) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    iVar2 = Ai_Subsystem_004b5a46(width,height);
    local_cc = iVar2;
    if (iVar2 != 0) {
      width_01 = Palette_Subsystem_004a2b7e(local_8);
      Palette_Subsystem_004a068a((int)hdc,(int)y,width_01,iVar2);
    }
    local_c4 = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x3e) / 100;
    Ai_Subsystem_004b5ab8(width,height,&local_d0,&local_d4,&local_d8);
    Palette_Subsystem_004a09c9((int)hdc,&local_c8,local_d0,local_d4,local_d8);
    iVar2 = Ai_Subsystem_004b65bf(width,height);
    uVar1 = (uint)(iVar2 == width);
    iVar2 = Ai_Subsystem_004b673e(width,height);
    Palette_Subsystem_004a11fa(hdc,y,local_9c,iVar2,uVar1);
    if ((width == 0) && (uVar1 = Ai_Subsystem_004b6432(0,height), (uVar1 & 0x40000) != 0)) {
      SelectObject(hdc,DAT_0054b970);
      h = GetStockObject(5);
      SelectObject(hdc,h);
      Rectangle(hdc,*y,y[1],y[2],y[3]);
    }
    RestoreDC(hdc,local_a8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2401
 * Entry Point: 004a2401
 * Size: 759 bytes
 */


void Palette_Subsystem_004a2401(HDC hdc,int *y,int width,int height)

{
  int iVar1;
  int local_68;
  int local_64;
  int local_60 [5];
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (iVar1 = Ai_Subsystem_004b5c4b(width,height), iVar1 != -1)) {
    local_30 = SaveDC(hdc);
    iVar1 = Ai_Subsystem_004b6623(width,height);
    if (iVar1 != 0) {
      local_60[4] = Ai_Subsystem_004b63c4(width,height);
      Ai_Subsystem_004b75d8(local_60);
      for (local_60[3] = 0; local_60[3] < 2; local_60[3] = local_60[3] + 1) {
        for (local_60[2] = 0; local_60[2] < local_60[local_60[3]]; local_60[2] = local_60[2] + 1) {
          Ai_Subsystem_004b5f74(&local_68,local_60[3],local_60[2]);
          iVar1 = Ai_Subsystem_004b5cbb(local_60[3],local_60[2]);
          if (((iVar1 == 0x11d) && (local_68 == width)) && (local_64 == height)) {
            local_60[4] = local_60[4] | 8;
          }
        }
      }
      GetObjectA(DAT_0054b59c,0x18,local_4c);
      local_24 = local_48 / 2;
      local_34 = local_44 / 6;
      SetRect(&local_18,(y[2] + ((local_24 * 7) / 0x14) * -6) - local_24,y[1] + 1,-1,-1);
      IntersectClipRect(hdc,*y,y[1],y[2],y[1] + ((y[3] - y[1]) * 0xf) / 100);
      for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
        if ((local_60[4] & 1 << ((byte)local_2c & 0x1f)) != 0) {
          local_20 = 0;
          if (local_2c == 5) {
            local_1c = 0;
          }
          else if (local_2c == 2) {
            local_1c = local_34;
          }
          else if (local_2c == 1) {
            local_1c = local_34 * 2;
          }
          else if (local_2c == 4) {
            local_1c = local_34 * 3;
          }
          else if (local_2c == 3) {
            local_1c = local_34 << 2;
          }
          else if (local_2c == 0) {
            local_1c = local_34 * 5;
          }
          else if (local_2c == 6) {
            local_1c = local_34 * 5;
          }
          local_8 = local_24;
          local_28 = local_1c;
          FUN_004f3eaa(hdc,&local_18.left,DAT_0054b59c,local_24,local_34,0,local_1c,local_24,
                       local_1c);
        }
        OffsetRect(&local_18,(local_24 * 7) / 0x14,0);
      }
    }
    RestoreDC(hdc,local_30);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a26f8
 * Entry Point: 004a26f8
 * Size: 135 bytes
 */


void Palette_Subsystem_004a26f8(undefined4 arg1,undefined4 arg2)

{
  FUN_004f3e29(arg1,arg2,DAT_0054b740);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a277f
 * Entry Point: 004a277f
 * Size: 135 bytes
 */


void Palette_Subsystem_004a277f(undefined4 arg1,undefined4 arg2)

{
  FUN_004f3e29(arg1,arg2,DAT_0054b3cc);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2806
 * Entry Point: 004a2806
 * Size: 153 bytes
 */


void Palette_Subsystem_004a2806(HDC hdc,int *arg2)

{
  HBRUSH h;
  HGDIOBJ pvVar1;
  
  SetROP2(hdc,0xd);
  h = CreateHatchBrush(3,0x808080);
  SetBkMode(hdc,1);
  SelectObject(hdc,h);
  pvVar1 = GetStockObject(8);
  SelectObject(hdc,pvVar1);
  Rectangle(hdc,*arg2,arg2[1],arg2[2],arg2[3]);
  pvVar1 = GetStockObject(0);
  SelectObject(hdc,pvVar1);
  DeleteObject(h);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a289f
 * Entry Point: 004a289f
 * Size: 294 bytes
 */


uint Palette_Subsystem_004a289f(HDC hdc,int *y,int width,int height)

{
  int nSavedDC;
  uint uVar1;
  uint local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((hdc == (HDC)0x0) || (y == (int *)0x0)) {
    local_1c = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    local_14 = *y + ((y[2] - *y) * 10) / 100;
    local_c = y[2] - ((y[2] - *y) * 10) / 100;
    local_10 = y[1] + ((y[3] - y[1]) * 10) / 100;
    local_8 = y[3] - ((y[3] - y[1]) * 10) / 100;
    local_1c = 1;
    if (width != 0) {
      local_1c = FUN_004f3e29(hdc,&local_14,DAT_0054b598);
      local_1c = local_1c & 1;
    }
    if (height == 0) {
      uVar1 = FUN_004f3e29(hdc,&local_14,DAT_0054b98c);
      local_1c = local_1c & uVar1;
    }
    RestoreDC(hdc,nSavedDC);
  }
  return local_1c;
}



/*
 * Decompiled function: Palette_Subsystem_004a29c5
 * Entry Point: 004a29c5
 * Size: 150 bytes
 */


void Palette_Subsystem_004a29c5(HDC hdc,int *card_slot,int arg_3)

{
  HPEN h;
  int nSavedDC;
  HGDIOBJ h_00;
  
  h = CreatePen(6,3,DAT_0054b980);
  if (arg_3 != 0) {
    nSavedDC = SaveDC(hdc);
    SelectObject(hdc,h);
    h_00 = GetStockObject(5);
    SelectObject(hdc,h_00);
    Rectangle(hdc,*card_slot,card_slot[1],card_slot[2],card_slot[3]);
    RestoreDC(hdc,nSavedDC);
  }
  DeleteObject(h);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2a5b
 * Entry Point: 004a2a5b
 * Size: 72 bytes
 */


void Palette_Subsystem_004a2a5b(undefined4 player,int *card_slot,byte arg_3)

{
  tagRECT local_14;
  
  if (((arg_3 & 1) != 0) && ((arg_3 & 2) != 0)) {
    Palette_Subsystem_004a2aa3(&local_14,card_slot);
    FUN_004f3e29(player,&local_14,DAT_0054b3d8);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2aa3
 * Entry Point: 004a2aa3
 * Size: 219 bytes
 */


void Palette_Subsystem_004a2aa3(LPRECT arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  
  if (arg1 != (LPRECT)0x0) {
    if (arg2 == (int *)0x0) {
      SetRect(arg1,0,0,0,0);
    }
    else {
      iVar1 = ((arg2[2] - *arg2) * 0x3c) / 100;
      iVar2 = ((arg2[3] - arg2[1]) * 0x3c) / 100;
      arg1->left = *arg2 + ((arg2[2] - *arg2) - iVar1) / 2;
      arg1->right = arg1->left + iVar1;
      arg1->top = arg2[1] + ((arg2[3] - arg2[1]) - iVar2) / 2;
      arg1->bottom = arg1->top + iVar2;
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2b7e
 * Entry Point: 004a2b7e
 * Size: 592 bytes
 */


undefined4 Palette_Subsystem_004a2b7e(int player)

{
  undefined4 local_8;
  
  if (player == 0x1d7) {
    local_8 = 0;
  }
  else if (player == 0x244) {
    local_8 = 1;
  }
  else if (player == 0x248) {
    local_8 = 2;
  }
  else if (player == 0x296) {
    local_8 = 3;
  }
  else if (player == 0x2fd) {
    local_8 = 4;
  }
  else if (player == 0x354) {
    local_8 = 5;
  }
  else if (player == 0x1e4) {
    local_8 = 6;
  }
  else if (player == 0x26) {
    local_8 = 6;
  }
  else if (player == 0xf6) {
    local_8 = 7;
  }
  else if (player == 0x34) {
    local_8 = 8;
  }
  else if (player == 0x120) {
    local_8 = 9;
  }
  else if (player == 0x7b) {
    local_8 = 10;
  }
  else if (player == 0x80) {
    local_8 = 0xb;
  }
  else if (player == 0x5e) {
    local_8 = 0xc;
  }
  else if (player == 0x353) {
    local_8 = 0xc;
  }
  else if (player == 0x92) {
    local_8 = 0xd;
  }
  else if (player == 0x2e0) {
    local_8 = 0xe;
  }
  else if (player == 0xd7) {
    local_8 = 0xf;
  }
  else if (player == 0xdc) {
    local_8 = 0x10;
  }
  else if (player == 0x367) {
    local_8 = 0x11;
  }
  else if (player == 0x21a) {
    local_8 = 0x12;
  }
  else if (player == 0x216) {
    local_8 = 0x13;
  }
  else if (player == 0xf8) {
    local_8 = 6;
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_004a2dce
 * Entry Point: 004a2dce
 * Size: 270 bytes
 */


void Palette_Subsystem_004a2dce(char *str_1,char *str_2,int arg_3)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  char *local_14;
  char *local_8;
  
  if ((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) {
    bVar1 = false;
    local_8 = str_2;
    pcVar2 = local_8;
    while (local_8 = pcVar2, !bVar1) {
      while ((*local_8 != '\0' && (iVar3 = strncmp(local_8,&DAT_0052c294,2), iVar3 != 0))) {
        local_8 = local_8 + 1;
      }
      if (*local_8 == '\0') {
        bVar1 = true;
        pcVar2 = local_8;
      }
      else {
        iVar3 = atoi(local_8 + 2);
        pcVar2 = local_8 + 2;
        if (iVar3 == arg_3) {
          local_8 = local_8 + 3;
          local_14 = str_1;
          while ((*local_8 != '\0' && (iVar3 = strncmp(local_8,&DAT_0052c298,2), iVar3 != 0))) {
            *local_14 = *local_8;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          *local_14 = '\0';
          bVar1 = true;
          pcVar2 = local_8;
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Util_004a2edc
 * Entry Point: 004a2edc
 * Size: 11 bytes
 */


void Palette_Util_004a2edc(void)

{
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a2ef0
 * Entry Point: 004a2ef0
 * Size: 4766 bytes
 */


undefined4 Palette_Subsystem_004a2ef0(int player)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  int local_460;
  void *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  int local_8;
  
  local_c = s_x_sound_damb1_wav_0052c370;
  local_18 = 0;
  local_8 = 0;
  if (player < 5) {
    FUN_0040b3c2(4,player);
  }
  else {
    FUN_0040b3c2(3,player);
  }
  DAT_00649c1c = 0;
  FUN_0040a2c0();
  Palette_Subsystem_004a5f7c();
  *(int *)(&DAT_0067f018 + player * 0x30) = *(int *)(&DAT_0067f018 + player * 0x30) + 1;
  DAT_0054bd24 = player;
  DAT_006498fc = 0;
  for (local_2c = 0; local_2c < 0xd; local_2c = local_2c + 1) {
    for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
      uVar2 = rand();
      *(uint *)(&DAT_0054ba18 + local_2c * 0x34 + local_24 * 4) = uVar2 & 3;
    }
  }
  if (player < 5) {
    Sprite_LoadCount(&DAT_006786b0,
                     (&PTR_s_dungeon3_spr_0052c2b0)[(char)(&DAT_0067f00c)[player * 0x30]],0x3c);
  }
  else {
    iVar4 = Math_RandomRange(3);
    Sprite_LoadAll(&DAT_006786b0,(&PTR_s_dungeon1_spr_0052c2a8)[iVar4]);
  }
  Glue_Subsystem_004ebe61(s_x_sound_dambloop_wav_0052c384,100);
  Glue_Subsystem_004ebdca(100,0x50,0);
  Pic_Subsystem_00423f10(100,1);
  Mem_AllocOrFree_00510e20(2,s_CaveBkgd_pic_0052c39c);
  Sprite_LoadAll(&local_450,s_dungbutt_spr_0052c3ac);
  DAT_0054ba14 = local_450;
  DAT_0054be30 = local_44c;
  DAT_0054be34 = local_448;
  DAT_0054be38 = local_444;
  for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
    do {
      switch((((byte)(&DAT_0067f00d)[player * 0x30] & 0x80) >> 6) + local_10) {
      case 0:
        local_50 = 4;
        break;
      case 1:
        local_50 = 6;
        break;
      case 2:
        local_50 = 8;
        break;
      case 3:
        local_50 = 0xc;
        break;
      case 4:
        local_50 = 0x10;
        break;
      case 5:
        local_50 = 0x12;
        break;
      case 6:
        local_50 = 0x12;
      }
      if (player < 5) {
        uVar3 = Math_RandomRange(6);
        switch(uVar3) {
        case 0:
          local_50 = 10;
          break;
        case 1:
          local_50 = 0xb;
          break;
        case 2:
          local_50 = 0xc;
          break;
        case 3:
          local_50 = 0xd;
          break;
        case 4:
          local_50 = 0xe;
          break;
        case 5:
          local_50 = 0x10;
        }
        if (local_10 == 4) {
          local_50 = 0x12;
        }
      }
      uVar3 = Glue_Subsystem_004ea97c((int)(char)(&DAT_0067f00c)[player * 0x30],local_50);
      *(undefined4 *)(&DAT_0054ba00 + local_10 * 4) = uVar3;
    } while (*(int *)(&DAT_0054ba00 + local_10 * 4) == 0);
    FUN_0046e70d(local_10,local_10 + 8);
    Sprite_Load_BK_AMG_0046d333(*(undefined4 *)(&DAT_0054ba00 + local_10 * 4),local_10,local_10 + 8)
    ;
    if ((player < 5) && (local_10 == 4)) {
      uVar3 = Glue_Subsystem_004ea97c((int)(char)(&DAT_0067f00c)[player * 0x30],0x14);
      *(undefined4 *)(&DAT_0054ba00 + local_10 * 4) = uVar3;
    }
    *(undefined4 *)(&DAT_0067f2d0 + local_10 * 0x14) = 0xffffffff;
  }
  for (local_20 = 0; (int)local_20 < 0xf; local_20 = local_20 + 1) {
    for (local_28 = 0; (int)local_28 < 0xd; local_28 = local_28 + 1) {
      *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 1;
      if ((((local_20 == 0) || (local_28 == 0)) || (0xd < (int)local_20)) || (0xb < (int)local_28))
      {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((local_20 & 1) == 0) && ((local_28 & 1) == 0)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((int)local_20 < 3) && ((int)local_28 < 3)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((int)local_20 < 3) && (9 < (int)local_28)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if ((0xb < (int)local_20) && ((int)local_28 < 3)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if ((0xb < (int)local_20) && (9 < (int)local_28)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
    }
  }
  local_48 = 7;
  DAT_0054bd28 = 7;
  DAT_00649900 = 7;
  local_44 = 0xc;
  DAT_0054bd2c = 0xc;
  DAT_00649904 = 0xc;
  DAT_00649dbc = 1;
  do {
    iVar4 = Math_RandomRange(7);
    local_20 = iVar4 * 2;
    iVar4 = Math_RandomRange(6);
    local_28 = iVar4 * 2;
    iVar4 = Math_RandomRange(2);
    if (iVar4 == 0) {
      local_28 = local_28 + 1;
    }
    else {
      local_20 = local_20 + 1;
    }
    memcpy(&DAT_00649910,&DAT_00649c20,0x30c);
    *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
    local_38 = Palette_Subsystem_004a41fd();
    if (local_38 == 0) {
      memcpy(&DAT_00649c20,&DAT_00649910,0x30c);
    }
  } while (local_38 < 2);
  DAT_0054bd2c = DAT_0054bd2c + -1;
  Palette_Subsystem_004a5603(DAT_0054bd28,DAT_0054bd2c);
  Palette_Subsystem_004a4a47(0,1,player);
  Ai_Subsystem_004cd1d1();
  Palette_Subsystem_004a4a47(0,0,player);
  local_3c = Math_RandomRange(0x5a);
  local_3c = local_3c + 0x5a;
  Mem_AllocOrFree_005016f9();
  local_38 = 1;
  do {
    iVar4 = Mem_AllocOrFree_00501721();
    if (local_3c < iVar4) {
      if ((local_c[0xc] != '5') || (local_18 == 0)) {
        do {
          local_30 = Math_RandomRange(5);
          local_30 = local_30 + 0x31;
        } while (local_c[0xc] == local_30);
        local_c[0xc] = (char)local_30;
        Pic_Subsystem_00423b93(0x65);
        Glue_Subsystem_004ec5be(local_c,0x65,0);
        iVar4 = Math_RandomRange(100);
        iVar4 = iVar4 + -0x32;
        iVar8 = 100;
        iVar5 = Math_RandomRange(0x14);
        Glue_Subsystem_004ebd62(0x65,iVar5 + 0x50,iVar8,iVar4);
        if ((local_c[0xc] == '5') && (local_18 == 0)) {
          local_18 = Math_RandomRange(3);
          local_18 = local_18 + 2;
          local_3c = Math_RandomRange(0x1e);
          local_3c = local_3c + 0x3c;
        }
        else {
          local_3c = Math_RandomRange(0x5a);
          local_3c = local_3c + 0x78;
        }
        Mem_AllocOrFree_005016f9();
        goto LAB_004a36e4;
      }
      local_18 = local_18 + -1;
      iVar4 = Math_RandomRange(100);
      iVar4 = iVar4 + -0x32;
      iVar8 = 100;
      iVar5 = Math_RandomRange(0x14);
      Glue_Subsystem_004ebd62(0x65,iVar5 + 0x50,iVar8,iVar4);
      local_3c = Math_RandomRange(0x3c);
      local_3c = local_3c + 0x1e;
      Mem_AllocOrFree_005016f9();
    }
    else {
LAB_004a36e4:
      Pic_Subsystem_0044b84b();
      iVar4 = Mem_AllocOrFree_0040810f();
      if ((iVar4 == 0) || (DAT_0067bda0 != 0)) {
        if (DAT_0067bda0 != 0) {
          local_38 = Palette_Subsystem_004a610e(DAT_0067bda4,DAT_0067bda8);
        }
        local_40 = -1;
        local_30 = FUN_0048ac2f();
        if (local_30 < 0x4701) {
          if (local_30 != 0x4700) {
            if (local_30 == 0x1b) {
              local_38 = 0;
            }
            goto LAB_004a403e;
          }
          local_14 = DAT_0054bd28;
          local_1c = DAT_0054bd2c + -1;
          DAT_0052c2a0 = 3;
          local_40 = 1;
        }
        else if (local_30 == 0x4900) {
          local_1c = DAT_0054bd2c;
          local_14 = DAT_0054bd28 + 1;
          DAT_0052c2a0 = 5;
          local_40 = 3;
        }
        else if (local_30 == 0x4f00) {
          local_1c = DAT_0054bd2c;
          local_14 = DAT_0054bd28 + -1;
          DAT_0052c2a0 = 1;
          local_40 = 7;
        }
        else {
          if (local_30 != 0x5100) goto LAB_004a403e;
          local_14 = DAT_0054bd28;
          local_1c = DAT_0054bd2c + 1;
          DAT_0052c2a0 = 7;
          local_40 = 5;
        }
        if ((((-1 < local_14) && (local_14 < 0xf)) && (-1 < local_1c)) &&
           ((local_1c < 0xd && (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) != 0)))) {
          if (((&DAT_00649c20)[local_1c * 4 + local_14 * 0x34] & 0xf0) != 0) {
            if (local_40 != 0) {
              Palette_Subsystem_004a486f(local_40,1);
            }
            local_34 = (int)(*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) +
                            (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) >> 0x1f & 0xfU
                            )) >> 4 & 0xf;
            if (DAT_00649c1c != 0) {
              local_34 = 0xf;
            }
            switch(local_34) {
            case 1:
              Glue_Subsystem_004ebcdc(s_x_sound_dice_wav_0052c3bc,0xf,100,100,0);
              uVar2 = rand();
              if ((uVar2 & 1) == 0) goto LAB_004a38ef;
              iVar4 = Math_RandomRange(3);
              DAT_006498fc = DAT_006498fc + iVar4 + 1U;
              uVar2 = iVar4 + 1U;
              while( true ) {
                DAT_00522454 = uVar2;
                strcpy(&g_OverworldWorldState,s_You_get_0052c3d0);
                Palette_Subsystem_004a5e4c();
                strcat(&g_OverworldWorldState,s_in_the_next_duel__0052c3dc);
                if (DAT_00522454 != 0xffffffff) break;
LAB_004a38ef:
                do {
                  do {
                    iVar4 = Math_RandomRange(500);
                    local_34 = *(uint *)(&deck + iVar4 * 4);
                  } while ((int)local_34 < 6);
                } while (((local_34 & 0x4000) != 0) ||
                        (local_34 = local_34 & 0xfff, uVar2 = local_34,
                        ((&g_MasterCardColorTable)[local_34 * 0x34] & 0x42) == 0));
              }
              FUN_004896be(&g_OverworldWorldState,100,0x50);
              *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              Palette_Subsystem_004a4a47(0,0,player);
              break;
            case 2:
              Glue_Subsystem_004ebcdc(s_x_sound_scroll_wav_0052c3f0,0xf,100,100,0);
              iVar4 = Palette_Subsystem_00498a18();
              if (iVar4 == 0) {
                Glue_Subsystem_004ebcdc(s_x_sound_dsummon_wav_0052c404,0xf,100,100,0);
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x61;
                local_14 = DAT_0054bd28;
                local_1c = DAT_0054bd2c;
                local_40 = 0;
              }
              else {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              }
              Palette_Subsystem_004a4a47(0,0,player);
              break;
            case 3:
            case 4:
            case 5:
            case 6:
              iVar4 = Palette_Subsystem_004a5722(player,local_34 - 3,0);
              if (iVar4 == 0) {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0;
                local_14 = DAT_0054bd28;
                local_1c = DAT_0054bd2c;
                local_40 = 0;
                if (((&DAT_0067f014)[player * 0x30] & 1) != 0) {
                  local_38 = 0;
                  local_8 = 1;
                  Ai_Subsystem_004c05ba();
                }
                FUN_0040b3c2(2,*(undefined4 *)(&DAT_0054b9f4 + local_34 * 4));
              }
              else {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
                FUN_0040b3c2(2,*(uint *)(&DAT_0054b9f4 + local_34 * 4) | 0x80);
              }
              Palette_Subsystem_004a4a47(0,0,player);
              break;
            case 7:
              local_4c = 0;
              do {
                local_34 = Math_RandomRange(3);
                if (*(int *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30) != -1) break;
                local_4c = local_4c + 1;
              } while (local_4c < 100);
              if (*(int *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30) == -1) {
                iVar4 = Math_RandomRange(100);
                iVar4 = iVar4 * (DAT_0067f380 + 2) + 100;
                bVar1 = false;
                iVar4 = iVar4 - iVar4 % 10;
                Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_0052c454,0xf,100,100,0);
                Gold = Gold + iVar4;
                sprintf(&g_OverworldWorldState,s_Found__d_Gold_and_bag_with_0052c46c,iVar4);
                for (local_460 = 1; local_460 < 6; local_460 = local_460 + 1) {
                  iVar5 = Math_RandomRange(2);
                  if (iVar5 != 0) {
                    uVar3 = Mem_AllocOrFree_00473d7e(local_460);
                    pcVar7 = s__d__s_0052c488;
                    iVar8 = iVar5;
                    sVar6 = strlen(&g_OverworldWorldState);
                    sprintf(&g_OverworldWorldState + sVar6,pcVar7,iVar8,uVar3);
                    bVar1 = true;
                    *(int *)(&DAT_0067bdbc + local_460 * 4) =
                         *(int *)(&DAT_0067bdbc + local_460 * 4) + iVar5;
                  }
                }
                if (bVar1) {
                  pcVar7 = s_Jewels_0052c490;
                  sVar6 = strlen(&g_OverworldWorldState);
                  sprintf(&DAT_0062684f + sVar6,pcVar7);
                }
                else {
                  sprintf(&g_OverworldWorldState,s_Found__d_Gold_0052c49c,iVar4);
                }
                FUN_0040b3c2(0x13,100);
                FUN_004896be(&g_OverworldWorldState,100,0x50);
              }
              else {
                Glue_Subsystem_004ebcdc(s_x_sound_findcard_wav_0052c418,0xf,100,100,0);
                FUN_0040acfd(s_staceybk_pic_0052c430);
                FUN_0040b3c2(0x13,*(uint *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30) | 0x10000);
                FUN_0050b3de(*(int *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30),0x22,0x53,0x4b,
                             0x70,1,&DAT_0052c440);
                Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0x1b,0x90,0x93);
                App_ProcessPendingMessages();
                Ai_Subsystem_004cd1d1();
                Palette_Subsystem_004a4a47(0,0,player);
                iVar4 = Pic_Subsystem_00451e40
                                  (*(uint *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30));
                *(uint *)(&deck + iVar4 * 4) = *(uint *)(&deck + iVar4 * 4) | 0x4000;
                *(undefined4 *)(&DAT_0067eff0 + local_34 * 4 + player * 0x30) = 0xffffffff;
              }
              *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              Palette_Subsystem_004a4a47(0,0,player);
              break;
            case 0xf:
              if (player < 5) {
                Mem_AllocOrFree_0050fc50(DAT_0054ba14);
                Mem_AllocOrFree_0050fc50(DAT_006786b0);
                iVar4 = Palette_Subsystem_004a5722(player,4,1);
                if (iVar4 != 0) {
                  Action_PromptTarget_0049239e(player);
                }
                Ai_Subsystem_004c05ba();
                Palette_Subsystem_004a5fdc();
                DAT_00522454 = 0xffffffff;
                DAT_00627a7c = 0;
                DAT_006498fc = 0;
                return 0;
              }
            }
            Palette_Subsystem_004a5603(local_14,local_1c);
            if (DAT_0054be2c != 0) {
              Palette_Subsystem_004a4a47(0,0,player);
            }
            SetFocus(_hwndScreen);
          }
          if (local_40 != 0) {
            Palette_Subsystem_004a486f(local_40,0);
          }
          App_ProcessPendingMessages();
          DAT_0054bd28 = local_14;
          DAT_0054bd2c = local_1c;
          Palette_Subsystem_004a5603(local_14,local_1c);
          if (DAT_0054be2c != 0) {
            Palette_Subsystem_004a4a47(0,0,player);
          }
          if ((DAT_0054bd28 == local_48) && (DAT_0054bd2c == local_44)) {
            local_38 = 0;
          }
        }
      }
    }
LAB_004a403e:
    if (local_38 == 0) {
      if (player < 5) {
        if (local_8 != 0) {
          strcpy(&g_OverworldWorldState,s_You_are_unceremoniously_booted_f_0052c4ac);
          pcVar7 = (char *)Mem_AllocOrFree_00473d7e(player + 1);
          strcat(&g_OverworldWorldState,pcVar7);
          strcat(&g_OverworldWorldState,s_Wizard__0052c4f0);
          Glue_Subsystem_004ebcdc(s_x_sound_dsummon_wav_0052c4fc,0xf,100,100,0);
          FUN_004896be(&g_OverworldWorldState,0xa0,0x78);
        }
      }
      else {
        FUN_0040c889(0x40,*(int *)(&DAT_0067f000 + player * 0x30),
                     *(int *)(&DAT_0067f004 + player * 0x30));
        *(uint *)(&DAT_0067f010 + player * 0x30) =
             *(uint *)(&DAT_0067f010 + player * 0x30) & 0xfffffffe;
        *(uint *)(&DAT_0067f010 + player * 0x30) = *(uint *)(&DAT_0067f010 + player * 0x30) | 6;
        do {
          do {
            local_20 = Math_RandomRange(0x40);
            local_28 = Math_RandomRange(0x40);
            FUN_0040c7c0(local_20,local_28);
            iVar4 = Surface_GetPixelColor(local_20, local_28);
          } while (iVar4 == 0);
          uVar2 = FUN_0040c7c0(local_20,local_28);
        } while ((uVar2 & 0x30) != 0);
        *(uint *)(&DAT_0067f000 + player * 0x30) = local_20;
        *(uint *)(&DAT_0067f004 + player * 0x30) = local_28;
        FUN_0040c81c(0x40,local_20,local_28);
      }
      DAT_00627a7c = 0;
      DAT_00522454 = 0xffffffff;
      DAT_006498fc = 0;
      Mem_AllocOrFree_0050fc50(DAT_0054ba14);
      Mem_AllocOrFree_0050fc50(DAT_006786b0);
      Ai_Subsystem_004c05ba();
      Palette_Subsystem_004a5fdc();
      Pic_Subsystem_00423c82(100);
      uVar3 = Pic_Subsystem_00423b93(100);
      return uVar3;
    }
  } while( true );
}



/*
 * Decompiled function: Palette_Subsystem_004a41fd
 * Entry Point: 004a41fd
 * Size: 1379 bytes
 */


int Palette_Subsystem_004a41fd(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int card_slot;
  int arg_3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
    for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
      (&DAT_0054bd68)[local_18 + local_10 * 0xd] = 0;
    }
  }
  Palette_Subsystem_004a4760(DAT_0054bd28,DAT_0054bd2c,0);
  local_28 = 99;
  cVar1 = '\0';
  local_20 = 1;
  local_24 = 0;
  local_8 = 0;
  for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
    for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
      if ((*(int *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) != 0) &&
         ((local_10 != DAT_0054bd28 || (local_18 != DAT_0054bd2c)))) {
        if ((&DAT_0054bd68)[local_18 + local_10 * 0xd] == '\0') {
          local_20 = 0;
        }
        local_30 = 0;
        for (local_14 = 1; local_14 < 9; local_14 = local_14 + 2) {
          if (*(int *)(&DAT_00649c20 +
                      (*(int *)(&DAT_00522378 + local_14 * 4) + local_10) * 0x34 +
                      (*(int *)(&DAT_005223e0 + local_14 * 4) + local_18) * 4) != 0) {
            local_30 = local_30 + 1;
          }
        }
        if (local_30 == 1) {
          if (((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < '\x10') || (local_18 == local_24))
          {
            local_20 = 0;
          }
          else if (local_18 != local_24) {
            local_8 = local_8 + 1;
            local_24 = local_18;
            if ((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < local_28) {
              local_28 = (int)(char)(&DAT_0054bd68)[local_18 + local_10 * 0xd];
            }
            if (cVar1 < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) {
              cVar1 = (&DAT_0054bd68)[local_18 + local_10 * 0xd];
            }
          }
        }
      }
    }
  }
  if ((local_20 != 0) && (2 < local_8)) {
    local_24 = 0;
    local_8 = 0;
    for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
      for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
        if ((*(int *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) != 0) &&
           ((local_10 != DAT_0054bd28 || (local_18 != DAT_0054bd2c)))) {
          local_2c = 0;
          local_30 = 0;
          for (local_14 = 1; local_14 < 9; local_14 = local_14 + 2) {
            if (*(int *)(&DAT_00649c20 +
                        (*(int *)(&DAT_00522378 + local_14 * 4) + local_10) * 0x34 +
                        (*(int *)(&DAT_005223e0 + local_14 * 4) + local_18) * 4) != 0) {
              local_30 = local_30 + 1;
            }
            if (*(int *)(&DAT_00649c20 +
                        ((&DAT_005223e4)[local_14] + local_18) * 4 +
                        ((&DAT_0052237c)[local_14] + local_10) * 0x34) != 0) {
              local_2c = local_2c + 1;
            }
          }
          if (local_30 == 1) {
            if ((('\x0f' < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) &&
                (local_18 != local_24)) && (local_18 != local_24)) {
              local_8 = local_8 + 1;
              local_24 = local_18;
              if ((DAT_0054bd24 < 5) && (local_8 == 1)) {
                *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                     *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | 0xf0;
              }
              else {
                *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                     *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | 0x70;
              }
            }
          }
          else {
            iVar3 = *(int *)(&DAT_0067f018 + DAT_0054bd24 * 0x30) + DAT_0067f380;
            if (2 < iVar3) {
              iVar3 = 3;
            }
            if (((((local_28 - (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) + 1) % (5 - iVar3)
                  == 0) && ((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < cVar1)) &&
               ('\a' < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd])) {
              arg_3 = 6;
              card_slot = 0;
              cVar2 = (&DAT_0054bd68)[local_18 + local_10 * 0xd];
              iVar3 = Math_RandomRange(6);
              local_1c = Math_Clamp(((int)((cVar2 - local_28) + (cVar2 - local_28 >> 0x1f & 3U))
                                      >> 2) + -2 + iVar3 + local_2c + local_30,card_slot,arg_3);
              iVar3 = Math_RandomRange(DAT_0067f380 + 3);
              if (iVar3 == 0) {
                local_1c = 1;
              }
              *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                   *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | local_1c << 4;
            }
          }
        }
      }
    }
    local_20 = 2;
  }
  return local_20;
}



/*
 * Decompiled function: Palette_Subsystem_004a4760
 * Entry Point: 004a4760
 * Size: 271 bytes
 */


void Palette_Subsystem_004a4760(int player,int card_slot,int arg_3)

{
  int arg_3_00;
  int arg_1_00;
  int arg_2_00;
  int local_10;
  
  arg_3_00 = arg_3 + 1;
  arg_3._0_1_ = (undefined1)arg_3_00;
  (&DAT_0054bd68)[card_slot + player * 0xd] = (undefined1)arg_3;
  for (local_10 = 1; local_10 < 9; local_10 = local_10 + 2) {
    arg_1_00 = *(int *)(&DAT_00522378 + local_10 * 4) + player;
    arg_2_00 = *(int *)(&DAT_005223e0 + local_10 * 4) + card_slot;
    if (((*(int *)(&DAT_00649c20 + arg_2_00 * 4 + arg_1_00 * 0x34) != 0) &&
        ((((&DAT_0054bd68)[arg_2_00 + arg_1_00 * 0xd] == '\0' ||
          (arg_3_00 < (char)(&DAT_0054bd68)[arg_2_00 + arg_1_00 * 0xd])) && (-1 < arg_1_00)))) &&
       (((arg_1_00 < 0xf && (-1 < arg_2_00)) && (arg_2_00 < 0xd)))) {
      Palette_Subsystem_004a4760(arg_1_00,arg_2_00,arg_3_00);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a486f
 * Entry Point: 004a486f
 * Size: 472 bytes
 */


void Palette_Subsystem_004a486f(int arg1,int arg2)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  Palette_Subsystem_004a554b(DAT_0054bd28,DAT_0054bd2c,&local_10,&local_14);
  for (local_c = 1; (int)local_c <= (int)((-(uint)(arg2 == 0) & 4) + 4); local_c = local_c + 1) {
    iVar1 = local_10 - DAT_00678430 / 2;
    local_8 = local_14 - DAT_006779d0;
    FUN_0040c5d9(g_DisplaySurfaceBackBuffer,iVar1 / 2,local_8 / 2,DAT_00678430 / 2,DAT_006784b0 / 2,
                 g_DisplaySurfaceScreen,iVar1 / 2,local_8 / 2);
    iVar1 = Ai_Util_004c3bc4(local_10);
    iVar1 = iVar1 - DAT_00678430 / 2;
    local_8 = Ai_Util_004c3bc4(local_14);
    local_8 = local_8 - DAT_006779d0;
    if (local_c == 8) {
      local_1c = 0;
    }
    else {
      local_1c = (local_c & 3) + 1;
    }
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1,local_8,
                      (&DAT_00679424)[DAT_0052c2a0 * 5 + local_1c]);
    if (local_c == 8) {
      local_20 = 0;
    }
    else {
      local_20 = (local_c & 3) + 1;
    }
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1,local_8,
                      (&DAT_00679370)[DAT_0052c2a0 * 5 + local_20]);
    local_10 = local_10 +
               ((int)((&DAT_0052237c)[arg1 - 2U & 7] * 0x10 +
                     ((&DAT_0052237c)[arg1 - 2U & 7] * 0x10 >> 0x1f & 3U)) >> 2);
    local_14 = local_14 +
               ((int)((&DAT_005223e4)[arg1 - 2U & 7] * 0x10 +
                     ((&DAT_005223e4)[arg1 - 2U & 7] * 0x10 >> 0x1f & 7U)) >> 3);
    FUN_00501736(5);
    App_ProcessPendingMessages();
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a4a47
 * Entry Point: 004a4a47
 * Size: 2575 bytes
 */


void Palette_Subsystem_004a4a47(int player,int card_slot,int arg_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_48;
  int local_44;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (card_slot == 0) {
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
  }
  iVar1 = Ai_Util_004c3ba3(0xf0);
  iVar2 = Ai_Util_004c3ba3(0x140);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen,0,0,
                     iVar2,iVar1);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  g_OverworldWorldState = 0;
  FUN_0048e2b0(arg_3);
  iVar1 = FUN_0040c465(&g_OverworldWorldState);
  local_44 = 0;
  iVar2 = (int)*(short *)(DAT_0054be30 + 4);
  iVar3 = (int)*(short *)(DAT_0054be34 + 4);
  for (local_30 = *(short *)(DAT_0054be38 + 4) + iVar2 + -0x32; local_30 < iVar1;
      local_30 = local_30 + iVar3) {
    local_44 = local_44 + 1;
  }
  iVar1 = Ai_Util_004c3bc4(0x140);
  local_48 = (iVar1 - (local_44 * iVar3) / 2) - iVar2;
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be30);
  local_48 = local_48 + iVar2;
  while (local_44 != 0) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be34);
    local_48 = local_48 + iVar3;
    local_44 = local_44 + -1;
  }
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be38);
  iVar3 = 0xff;
  iVar2 = 0x12;
  iVar1 = Ai_Util_004c3bc4(0x140);
  FUN_0040c421(&g_OverworldWorldState,iVar1,iVar2,iVar3);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  if (DAT_00522454 != -1) {
    g_OverworldWorldState = 0;
    Palette_Subsystem_004a5e4c();
    iVar2 = 0x30;
    iVar1 = Ai_Util_004c3bc4(0x140);
    FUN_0040d269((int)g_DisplaySurfaceScreen,0xd0,iVar1,iVar2);
  }
  for (local_14 = 0xe; -1 < local_14; local_14 = local_14 + -1) {
    for (local_1c = 0; (int)local_1c < 0xd; local_1c = local_1c + 1) {
      Palette_Subsystem_004a554b(local_14,local_1c,&local_24,&local_28);
      if ((player == 0) && (((&DAT_00649c21)[local_1c * 4 + local_14 * 0x34] & 1) == 0)) {
        if ((((-1 < local_24) && (-1 < local_28)) && (local_24 < 0x241)) &&
           ((local_28 < 0x191 && (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) == 0))))
        {
          local_20 = 0;
          for (local_8 = 1; local_8 < 9; local_8 = local_8 + 2) {
            if (((&DAT_00649c21)
                 [(*(int *)(&DAT_00522378 + local_8 * 4) + local_14) * 0x34 +
                  (*(int *)(&DAT_005223e0 + local_8 * 4) + local_1c) * 4] & 1) != 0) {
              local_20 = local_20 + 1;
            }
          }
          if (1 < (int)local_20) {
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_00678700,0x40,
                       0x40);
          }
        }
      }
      else {
        if (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) != 0) {
          local_20 = (uint)(*(int *)(&DAT_00649c20 + (local_14 + 1) * 0x34 + local_1c * 4) == 0);
          if ((&DAT_00649c1c)[local_14 * 0xd + local_1c] == 0) {
            local_20 = local_20 | 2;
          }
          switch(*(undefined4 *)(&DAT_0054ba18 + local_1c * 4 + local_14 * 0x34)) {
          case 0:
            break;
          case 1:
            local_20 = local_20 + 4;
            break;
          case 2:
            local_20 = local_20 + 0x18;
            break;
          case 3:
            local_20 = local_20 + 0x1c;
          }
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,
                     (&DAT_006786b0)[local_20],0x40,0x40);
          local_20 = (uint)(*(int *)(local_14 * 0x34 + 0x649c24 + local_1c * 4) == 0);
          if (*(int *)(&DAT_00649c20 + (local_14 + -1) * 0x34 + local_1c * 4) == 0) {
            local_20 = local_20 | 2;
          }
          if (local_1c == 0xc) {
            local_20 = local_20 | 1;
          }
          if ((local_1c & 1) != 0) {
            local_20 = local_20 + 4;
          }
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,
                     *(undefined4 *)(&DAT_006786e0 + local_20 * 4),0x40,0x40);
        }
        g_OverworldWorldState = 0;
        if ((((&DAT_00649c20)[local_1c * 4 + local_14 * 0x34] & 0xf0) != 0) || (local_1c == 0xc)) {
          local_20 = (int)(*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) +
                          (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) >> 0x1f & 0xfU))
                     >> 4 & 0xf;
          switch(local_20) {
          case 1:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d8,0x40,
                       0x40);
            break;
          case 2:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d4,0x40,
                       0x40);
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          case 6:
            break;
          case 7:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d0,0x40,
                       0x40);
            break;
          case 0xf:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_00678774,0x40,
                       0x40);
          }
          if (((int)local_20 < 3) || (6 < (int)local_20)) {
            if (local_1c == 0xc) {
              strcpy(&g_OverworldWorldState,&DAT_0052c510);
            }
            FUN_0040c336(&g_OverworldWorldState,local_24 / 2,local_28 / 2 + -2,0xff);
          }
          else {
            local_20 = local_20 - 3;
            strcpy(&g_OverworldWorldState,
                   &DAT_00522600 + *(int *)(&DAT_0054ba00 + local_20 * 4) * 0x44);
            local_2c = 5;
            for (local_18 = 1; local_18 < 9; local_18 = local_18 + 2) {
              local_8 = (int)(char)(&DAT_0054bd68)
                                   [*(int *)(&DAT_005223e0 + local_18 * 4) + local_1c +
                                    (*(int *)(&DAT_00522378 + local_18 * 4) + local_14) * 0xd];
              if ((local_8 != 0) && (local_8 < (char)(&DAT_0054bd68)[local_1c + local_14 * 0xd])) {
                local_2c = local_18;
              }
            }
            iVar1 = *(int *)(&g_OverworldFoodAmount +
                            (local_20 * 4 + 0x20) * 0x2d + (local_2c + 2U & 7) * 0x14);
            iVar2 = Ai_Util_004c3bc4(local_28 + 4);
            iVar2 = iVar2 - *(int *)(&DAT_00677990 + local_20 * 4);
            iVar3 = Ai_Util_004c3bc4(local_24 + 4);
            Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                              iVar3 - *(int *)(&DAT_006783f0 + local_20 * 4) / 2,iVar2,iVar1);
            iVar1 = *(int *)(&g_OverworldFoodAmount + local_20 * 0xb4 + (local_2c + 2U & 7) * 0x14);
            iVar2 = Ai_Util_004c3bc4(local_28 + 4);
            iVar2 = iVar2 - *(int *)(&DAT_00677990 + local_20 * 4);
            iVar3 = Ai_Util_004c3bc4(local_24 + 4);
            Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                              iVar3 - *(int *)(&DAT_006783f0 + local_20 * 4) / 2,iVar2,iVar1);
          }
        }
        if ((DAT_0054bd28 == local_14) && (DAT_0054bd2c == local_1c)) {
          local_c = local_24;
          local_10 = local_28;
        }
      }
    }
  }
  if ((card_slot != 0) && (*(int *)(&DAT_0067effc + arg_3 * 0x30) != -1)) {
    local_20 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_3 * 0x30));
    strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + local_20 * 0x34);
    strcat(&g_OverworldWorldState,s_in_effect__0052c518);
    iVar1 = DAT_0054ba14;
    iVar2 = Ai_Util_004c3ba3(0x10f);
    iVar2 = iVar2 / 2;
    iVar3 = Ai_Util_004c3ba3(0xc5);
    iVar3 = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3(0x34);
    iVar4 = iVar4 / 2;
    iVar5 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar4,iVar3,iVar2,iVar1);
    FUN_0050b3de(local_20,0x7a,0x29,0x4b,0x70,1,&DAT_0052c524);
    FUN_0040c381(&g_OverworldWorldState,0x76,0x20,0x1b);
  }
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  if (card_slot == 0) {
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  else {
    FUN_0050e040((int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                 (int *)g_DisplaySurfaceBackBuffer,0,0);
  }
  iVar1 = (&DAT_00679424)[DAT_0052c2a0 * 5];
  iVar2 = Ai_Util_004c3bc4(local_10);
  iVar2 = iVar2 - DAT_006779d4;
  iVar3 = Ai_Util_004c3bc4(local_c);
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar3 - DAT_00678434 / 2,iVar2,iVar1);
  iVar1 = (&DAT_00679370)[DAT_0052c2a0 * 5];
  iVar2 = Ai_Util_004c3bc4(local_10);
  iVar2 = iVar2 - DAT_006779d0;
  iVar3 = Ai_Util_004c3bc4(local_c);
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar3 - DAT_00678430 / 2,iVar2,iVar1);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a554b
 * Entry Point: 004a554b
 * Size: 59 bytes
 */


void Palette_Subsystem_004a554b(int x,int y,int *width,int *height)

{
  *width = x * 0x20 + y * 0x20 + -0x60;
  *height = x * -0x10 + y * 0x10 + 0x110;
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a5586
 * Entry Point: 004a5586
 * Size: 125 bytes
 */


void Palette_Subsystem_004a5586(int x,int y,int *width,int *height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (x * 0x280) / g_DisplayScreenWidth;
  iVar2 = ((y * 3 + -0x30) * 0xa0) / g_DisplayScreenHeight;
  iVar3 = (iVar1 + 0x60) / 2 - (iVar2 + -0x110);
  *width = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
  iVar1 = iVar2 + -0x110 + (iVar1 + 0x60) / 2;
  *height = ((int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5) + 1;
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a5603
 * Entry Point: 004a5603
 * Size: 287 bytes
 */


void Palette_Subsystem_004a5603(int arg1,int arg2)

{
  int local_10;
  int local_c;
  int local_8;
  
  *(uint *)(&DAT_00649c20 + arg2 * 4 + arg1 * 0x34) =
       *(uint *)(&DAT_00649c20 + arg2 * 4 + arg1 * 0x34) | 0x100;
  DAT_0054be2c = 0;
  for (local_8 = 1; local_8 < 9; local_8 = local_8 + 2) {
    local_c = arg1;
    local_10 = arg2;
    while( true ) {
      local_c = local_c + *(int *)(&DAT_00522378 + local_8 * 4);
      local_10 = local_10 + *(int *)(&DAT_005223e0 + local_8 * 4);
      if ((((local_c < 0) || (0xe < local_c)) || (local_10 < 0)) ||
         ((0xc < local_10 || (*(int *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) == 0))))
      break;
      if (((&DAT_00649c21)[local_c * 0x34 + local_10 * 4] & 1) == 0) {
        DAT_0054be2c = 1;
      }
      *(uint *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) =
           *(uint *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) | 0x100;
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a5722
 * Entry Point: 004a5722
 * Size: 1834 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Palette_Subsystem_004a5722(int player,int card_slot,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 arg_2_00;
  int iVar3;
  uint width;
  int arg_4;
  char *str_5;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  LPVOID local_c;
  int local_8;
  
  for (local_14 = 0; local_14 < 500; local_14 = local_14 + 1) {
    local_10 = *(uint *)(&deck + local_14 * 4) & 0xfff;
    if ((((&DAT_0067f014)[player * 0x30] & 0x80) != 0) &&
       (_DAT_0063ee14 = 0, ((&g_MasterCardColorTable)[local_10 * 0x34] & 0x30) != 0)) {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
    if ((((&DAT_0067f014)[player * 0x30] & 0x40) != 0) &&
       (_DAT_0063ee14 = 0, ((&g_MasterCardColorTable)[local_10 * 0x34] & 0x40) != 0)) {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
    if ((((&DAT_0067f014)[player * 0x30] & 0x10) != 0) &&
       (_DAT_0063ee14 = 0,
       1 << ((&DAT_0067f00c)[player * 0x30] & 0x1f) == (int)(char)(&DAT_0051aebe)[local_10 * 0x34]))
    {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
  }
  DAT_006b2d64 = (int)(char)(&DAT_0067f00c)[player * 0x30];
  if (*(int *)(&DAT_0067effc + player * 0x30) != -1) {
    DAT_0068a64c = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + player * 0x30));
  }
  local_c = *(LPVOID *)(&DAT_0054ba00 + card_slot * 4);
  DAT_00695df0 = (int)(char)(&DAT_00522629)[(int)local_c * 0x44];
  DAT_0063ee24 = 0;
  if (card_slot != 4) {
    _g_PlayerLifeTotals = 0x10;
  }
  if (player < 5) {
    DAT_00695df0 = 2;
    local_18 = card_slot + DAT_0067f380 + -3;
    if (-1 < local_18) {
      cVar1 = (&DAT_0067f00c)[player * 0x30];
      iVar2 = Math_Clamp(local_18,0,2);
      DAT_006b2fe0 = Pic_Subsystem_0045268f
                               (*(int *)(&DAT_00527f10 + (cVar1 * 3 + -3) * 4 + iVar2 * 4));
    }
  }
  iVar2 = -1;
  width = 0;
  arg_2_00 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_c * 0x44));
  FUN_004909d3((int)local_c,arg_2_00,width,iVar2);
  Glue_Subsystem_004ebcdc(s_x_sound_dngnduel_wav_0052c528,0xf,100,100,0);
  if (player < 5) {
    strcpy(&g_OverworldWorldState,s_Exploring_the_Castle____0052c540);
  }
  else {
    strcpy(&g_OverworldWorldState,s_Exploring_the_Dungeon____0052c55c);
  }
  strcat(&g_OverworldWorldState,s_you_encounter_0052c578);
  Glue_Subsystem_004eaa19((int)local_c,1,0);
  strcat(&g_OverworldWorldState,&DAT_0052c588);
  if (DAT_006b2fe0 != -1) {
    cVar1 = (&DAT_0067f00c)[player * 0x30];
    iVar2 = Math_Clamp(local_18,0,2);
    local_18 = *(int *)(&DAT_00527f10 + (cVar1 * 3 + -3) * 4 + iVar2 * 4);
    strcat(&g_OverworldWorldState,&DAT_0052c58c);
    Glue_Subsystem_004eaa19((int)local_c,0,0);
    strcat(&g_OverworldWorldState,s_has_a_0052c590);
    iVar2 = Pic_Subsystem_0045268f(local_18);
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
    strcat(&g_OverworldWorldState,&DAT_0052c598);
  }
  if (DAT_0068a64c != -1) {
    strcat(&g_OverworldWorldState,&DAT_0052c59c);
    iVar2 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + player * 0x30));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
    strcat(&g_OverworldWorldState,s_starts_in_play__0052c5a0);
  }
  FUN_004896be(&g_OverworldWorldState,100,0x50);
  for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
    (&DAT_006b2dd0)[local_18] = 0xffffffff;
    (&DAT_006b2d90)[local_18] = (&DAT_006b2dd0)[local_18];
  }
  Glue_Subsystem_004eccd7();
  do {
    do {
      local_18 = Math_RandomRange(500);
    } while (*(int *)(&deck + local_18 * 4) == -1);
  } while ((((&DAT_00702151)[local_18 * 4] & 0x40) != 0) ||
          ((*(uint *)(&deck + local_18 * 4) & 0xfff) < 5));
  DAT_006b2d90 = *(uint *)(&deck + local_18 * 4) & 0xfff;
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    DAT_00522454 = -1;
  }
  g_PlayerCreatureCount = Minit_Subsystem_00452827();
  iVar2 = Minit_Subsystem_00452827();
  g_PlayerCreatureCount = iVar2 + DAT_00627a7c;
  g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_006498fc;
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_00522454;
  }
  DAT_00627868 = g_PlayerCreatureCount;
  if (arg_3 == 0) {
    Pic_Subsystem_00423c82(100);
  }
  else {
    Pic_Subsystem_00423c82(100);
    do {
      Pic_Subsystem_00424020(100,&local_1c);
    } while (local_1c == 1);
    Pic_Subsystem_00423b93(100);
  }
  local_8 = Pic_Load_0044ef70(0xffffffff,local_c);
  LoadPalNoPic(s_advfac64_pic_0052c5b4);
  FUN_005115a0(0,(short)DAT_00530d9c);
  if ((local_8 != 1) && (local_8 == 0)) {
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      if ((&DAT_006b2d90)[local_14] != -1) {
        strcpy(&g_OverworldWorldState,s_Lost_this_card_0052c5c4);
        Mem_AllocOrFree_00510e20(1,s_losedul2_pic_0052c5d4);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
        str_5 = &g_OverworldWorldState;
        arg_4 = 1;
        iVar2 = Ai_Util_004c3bc4(10);
        iVar2 = Math_RandomRange(iVar2);
        iVar2 = iVar2 + 0x50;
        iVar3 = Ai_Util_004c3bc4(10);
        iVar3 = Math_RandomRange(iVar3);
        FUN_0050b206(DAT_006b2d90,iVar3 + local_14 * 0x62 + 0x21,iVar2,arg_4,str_5);
        App_ProcessPendingMessages();
        Ai_Subsystem_004cd1d1();
        FUN_00489630((&DAT_006b2d90)[local_14]);
      }
    }
  }
  if (((&DAT_0067f014)[player * 0x30] & 1) != 0) {
    DAT_006498fc = DAT_006498fc + (g_PlayerCreatureCount - DAT_00627868);
    DAT_00627a7c = 0;
  }
  if (((&DAT_0067f014)[player * 0x30] & 2) != 0) {
    DAT_00627a7c = 0;
    DAT_006498fc = 0;
  }
  DAT_00522454 = 0xffffffff;
  if (arg_3 == 0) {
    Glue_Subsystem_004ebe61(s_x_sound_dambloop_wav_0052c5e4,100);
    Glue_Subsystem_004ebdca(100,0x50,0);
    Pic_Subsystem_00423f10(100,1);
  }
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_004a5e4c
 * Entry Point: 004a5e4c
 * Size: 304 bytes
 */


void Palette_Subsystem_004a5e4c(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Minit_Subsystem_00452827();
  if (DAT_00522454 == 5) {
    DAT_00522454 = -1;
  }
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    strcat(&g_OverworldWorldState,&DAT_0052c5fc);
    pcVar2 = _itoa(DAT_00522454,&DAT_0054bd58,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,&DAT_0052c600);
    pcVar2 = _itoa(iVar1 + DAT_00627a7c + DAT_006498fc,&DAT_0054bd58,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s___Lives_0052c604);
  }
  if (DAT_00522454 == 0) {
    strcat(&g_OverworldWorldState,s_First_Move_0052c610);
  }
  if (5 < DAT_00522454) {
    strcat(&g_OverworldWorldState,&DAT_0052c61c);
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_00522454 * 0x34);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a5f7c
 * Entry Point: 004a5f7c
 * Size: 96 bytes
 */


void Palette_Subsystem_004a5f7c(void)

{
  undefined4 arg2;
  
  arg2 = FUN_0050d0b0(9,g_DisplayScreenWidth,0x81,8);
  FUN_0050d370(9,arg2);
  *(undefined4 *)(PTR_DAT_0052c2ec + 0x20) = 1;
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0,g_DisplayScreenWidth,0x80,(int *)PTR_DAT_0052c2ec,0,0);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a5fdc
 * Entry Point: 004a5fdc
 * Size: 60 bytes
 */


void Palette_Subsystem_004a5fdc(void)

{
  Surface_BlitToDevice((int *)PTR_DAT_0052c2ec,0,0,g_DisplayScreenWidth,0x80,(int *)g_DisplaySurfaceWork,0,0);
  FUN_0050d2a0(9);
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a6018
 * Entry Point: 004a6018
 * Size: 246 bytes
 */


void Palette_Subsystem_004a6018(void)

{
  undefined4 uVar1;
  char local_48 [8];
  char local_40 [56];
  int local_8;
  
  for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
    Mem_AllocOrFree_0050fc00();
    strcpy(local_48,(&PTR_s_dungeon1_spr_0052c2a8)[local_8]);
    strcpy(local_40,&DAT_0052c620);
    Mem_AllocOrFree_00510e20(1,local_48);
    for (local_8 = 0; local_8 < 0x18; local_8 = local_8 + 1) {
      uVar1 = Sprite_EncodeFromSurface
                        (1,(local_8 % 0xc) * 0x41 + 1,(local_8 / 0xc) * 0x41 + 1,0x40,0x40);
      (&DAT_006786b0)[local_8] = (void *)uVar1;
    }
    strcpy(local_40,&DAT_0052c628);
    FUN_0050fc70(DAT_006786b0,local_48);
    Mem_AllocOrFree_0050fc50(DAT_006786b0);
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a610e
 * Entry Point: 004a610e
 * Size: 397 bytes
 */


undefined4 Palette_Subsystem_004a610e(int arg1,int arg2)

{
  int player;
  undefined4 uVar1;
  int arg_1_00;
  int local_44 [10];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_44[1] = 0x4800;
  local_44[2] = 0x4900;
  local_44[3] = 0x4d00;
  local_44[4] = 0x5100;
  local_44[5] = 0x5000;
  local_44[6] = 0x4f00;
  local_44[7] = 0x4b00;
  local_44[8] = 0x4700;
  Palette_Subsystem_004a5586(arg1,arg2,local_44,&local_8);
  if ((DAT_00649900 == local_44[0]) && (DAT_00649904 == local_8)) {
    FUN_0040816b(0x1b);
    uVar1 = 0;
  }
  else {
    Palette_Subsystem_004a554b(DAT_0054bd28,DAT_0054bd2c,&local_18,&local_1c);
    local_18 = Ai_Util_004c3bc4(local_18);
    local_1c = Ai_Util_004c3bc4(local_1c);
    player = arg1 - local_18;
    arg_1_00 = local_1c - arg2;
    local_10 = abs(player);
    local_14 = abs(arg_1_00);
    if ((player < 0) || (arg_1_00 < 0)) {
      if ((player < 0) || (-1 < arg_1_00)) {
        if ((player < 0) && (arg_1_00 < 0)) {
          local_c = 4;
        }
        else if ((player < 0) && (-1 < arg_1_00)) {
          local_c = 6;
        }
      }
      else {
        local_c = 2;
      }
    }
    else {
      local_c = 0;
    }
    FUN_0040816b(local_44[local_c + 2]);
    uVar1 = 1;
  }
  return uVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004a62a0
 * Entry Point: 004a62a0
 * Size: 208 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Palette_Subsystem_004a62a0(undefined4 player,int card_slot,int arg_3)

{
  INT_PTR IVar1;
  int local_10;
  int local_c;
  
  _DAT_0052c638 = player;
  if (card_slot != -1) {
    _DAT_0052c630 = card_slot;
  }
  if (arg_3 != -1) {
    _DAT_0052c634 = arg_3;
  }
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe0,g_MainAppHwnd,Palette_Subsystem_004a6370,
                          0x52c630);
  if (IVar1 == -1) {
    local_c = -1;
  }
  else {
    local_c = -1;
    local_10 = 0;
    while ((local_10 < g_MasterCardCount && (local_c == -1))) {
      if (*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == IVar1) {
        local_c = local_10;
      }
      local_10 = local_10 + 1;
    }
  }
  return local_c;
}



/*
 * Decompiled function: Palette_Subsystem_004a6370
 * Entry Point: 004a6370
 * Size: 1581 bytes
 */


undefined4 Palette_Subsystem_004a6370(HWND hwnd,uint uMsg,uint wParam,byte *lParam)

{
  uint uVar1;
  HWND pHVar2;
  UINT UVar3;
  WPARAM WVar4;
  LRESULT nResult;
  undefined4 uVar5;
  byte bVar6;
  int nIndex;
  byte bVar7;
  LONG dwNewLong;
  
  if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      uVar5 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return uVar5;
    }
    if (uMsg == 0x110) {
      DAT_0054be3c = (uint *)lParam;
      if (*(int *)(lParam + 8) != 0) {
        SetWindowTextA(hwnd,*(LPCSTR *)(lParam + 8));
      }
      SendDlgItemMessageA(hwnd,0x3f2,0x401,0xffffffff,0);
      dwNewLong = 1;
      nIndex = 0xc;
      pHVar2 = GetDlgItem(hwnd,0x3f2);
      SetWindowLongA(pHVar2,nIndex,dwNewLong);
      if ((*(byte *)DAT_0054be3c & 2) == 0) {
        if ((*(byte *)DAT_0054be3c & 4) == 0) {
          if ((*(byte *)DAT_0054be3c & 8) == 0) {
            if ((*(byte *)DAT_0054be3c & 0x10) == 0) {
              CheckDlgButton(hwnd,0x3f8,1);
            }
            else {
              CheckDlgButton(hwnd,0x3f7,1);
            }
          }
          else {
            CheckDlgButton(hwnd,0x3f6,1);
          }
        }
        else {
          CheckDlgButton(hwnd,0x3f5,1);
        }
      }
      else {
        CheckDlgButton(hwnd,0x3f4,1);
      }
      if ((*(byte *)((int)DAT_0054be3c + 4) & 1) == 0) {
        if ((*(byte *)((int)DAT_0054be3c + 4) & 2) == 0) {
          if ((*(byte *)((int)DAT_0054be3c + 4) & 4) == 0) {
            if ((*(byte *)((int)DAT_0054be3c + 4) & 8) == 0) {
              if ((*(byte *)((int)DAT_0054be3c + 4) & 0x10) == 0) {
                if ((*(byte *)((int)DAT_0054be3c + 4) & 0x20) == 0) {
                  CheckDlgButton(hwnd,0x3fa,1);
                }
                else {
                  CheckDlgButton(hwnd,0x3fd,1);
                }
              }
              else {
                CheckDlgButton(hwnd,0x3fd,1);
              }
            }
            else {
              CheckDlgButton(hwnd,0x3fc,1);
            }
          }
          else {
            CheckDlgButton(hwnd,0x3fb,1);
          }
        }
        else {
          CheckDlgButton(hwnd,0x3f9,1);
        }
      }
      else {
        CheckDlgButton(hwnd,0x3fe,1);
      }
      bVar7 = (byte)*(undefined4 *)((int)DAT_0054be3c + 4);
      bVar6 = (byte)*DAT_0054be3c;
      pHVar2 = GetDlgItem(hwnd,0x3f3);
      Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
      pHVar2 = GetDlgItem(hwnd,0x3f3);
      SetFocus(pHVar2);
      return 0;
    }
    if (uMsg == 0x111) {
      uVar1 = wParam & 0xffff;
      if (uVar1 < 0x3f4) {
        if (uVar1 == 0x3f3) {
          if (wParam >> 0x10 == 1) {
            WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x188,0,0);
            WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x199,WVar4,0);
            SendDlgItemMessageA(hwnd,0x3f2,0x401,WVar4,0);
          }
          else if (wParam >> 0x10 == 2) {
            pHVar2 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,1,(LPARAM)pHVar2);
          }
        }
        else if (uVar1 == 1) {
          WVar4 = SendDlgItemMessageA(hwnd,0x3f3,0x188,0,0);
          nResult = SendDlgItemMessageA(hwnd,0x3f3,0x199,WVar4,0);
          EndDialog(hwnd,nResult);
        }
        else if (uVar1 == 2) {
          EndDialog(hwnd,-1);
        }
      }
      else {
        switch(uVar1) {
        case 0x3f4:
        case 0x3f5:
        case 0x3f6:
        case 0x3f7:
        case 0x3f8:
          if (wParam >> 0x10 == 0) {
            *DAT_0054be3c = 0;
            UVar3 = IsDlgButtonChecked(hwnd,0x3f4);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 2;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f8);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 0x20;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f5);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 4;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f7);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 0x10;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f6);
            if (UVar3 != 0) {
              *DAT_0054be3c = *DAT_0054be3c | 8;
            }
            bVar7 = (byte)DAT_0054be3c[1];
            bVar6 = (byte)*DAT_0054be3c;
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            SetFocus(pHVar2);
          }
          break;
        case 0x3f9:
        case 0x3fa:
        case 0x3fb:
        case 0x3fc:
        case 0x3fd:
        case 0x3fe:
          if (wParam >> 0x10 == 0) {
            DAT_0054be3c[1] = 0;
            UVar3 = IsDlgButtonChecked(hwnd,0x3fe);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 1;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3f9);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 2;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fb);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 4;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fc);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 8;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fd);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 0x30;
            }
            UVar3 = IsDlgButtonChecked(hwnd,0x3fa);
            if (UVar3 != 0) {
              DAT_0054be3c[1] = DAT_0054be3c[1] | 0x40;
            }
            bVar7 = (byte)DAT_0054be3c[1];
            bVar6 = (byte)*DAT_0054be3c;
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            Palette_Subsystem_004a69c8(pHVar2,bVar6,bVar7);
            pHVar2 = GetDlgItem(hwnd,0x3f3);
            SetFocus(pHVar2);
          }
        }
      }
      return 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a69c8
 * Entry Point: 004a69c8
 * Size: 845 bytes
 */


void Palette_Subsystem_004a69c8(HWND hwnd,byte card_slot,byte arg_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  WPARAM wParam;
  int local_8;
  
  SendMessageA(hwnd,0x184,0,0);
  for (local_8 = 0; local_8 < DAT_006a49f4; local_8 = local_8 + 1) {
    bVar1 = false;
    bVar2 = false;
    bVar3 = false;
    if (((((((card_slot & 2) == 0) || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 1)) &&
          (((card_slot & 0x20) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 8)))) &&
         (((card_slot & 4) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 2)))) &&
        (((card_slot & 0x10) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 7)))) &&
       (((card_slot & 8) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 5)))) {
      if ((*(int *)(&DAT_006b3080 + local_8 * 0x98) == 4) ||
         (((*(int *)(&DAT_006b3080 + local_8 * 0x98) == 0 ||
           (*(int *)(&DAT_006b3080 + local_8 * 0x98) == 3)) ||
          (*(int *)(&DAT_006b3080 + local_8 * 0x98) == 6)))) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((((((arg_3 & 1) == 0) || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 5)) &&
         (((arg_3 & 2) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 7)))) &&
        ((((arg_3 & 4) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 2)) &&
         (((arg_3 & 8) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 6)))))) &&
       (((((arg_3 & 0x10) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 3)) &&
         (((arg_3 & 0x20) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 4)))) &&
        (((arg_3 & 0x40) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 1)))))) {
      if (*(int *)(&DAT_006b3084 + local_8 * 0x98) == 0) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
    if (((((&DAT_006b307c)[local_8 * 0x98] & 0x80) != 0) ||
        (((&DAT_006b307d)[local_8 * 0x98] & 4) != 0)) ||
       (((&DAT_006b307c)[local_8 * 0x98] & 8) != 0)) {
      bVar3 = true;
    }
    if (((bVar1) && (bVar2)) && (bVar3)) {
      wParam = SendMessageA(hwnd,0x180,0,*(LPARAM *)(&DAT_006b3074 + local_8 * 0x98));
      SendMessageA(hwnd,0x19a,wParam,local_8);
    }
  }
  return;
}



/*
 * Decompiled function: Palette_Subsystem_004a6d20
 * Entry Point: 004a6d20
 * Size: 408 bytes
 */


int Palette_Subsystem_004a6d20(int player,int card_slot,int arg_3)

{
  int iVar1;
  uint uVar2;
  int local_14;
  int local_10;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  do {
    if ((1 < local_8) || (local_10 != 0)) {
      return local_10;
    }
    local_14 = 0;
    while ((local_14 < (int)(&g_PlayerActiveCardCount)[local_8] && (local_10 == 0))) {
      if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_CardSlot_Flags)[local_14 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        if (*(int *)(&DAT_006b3088 +
                    *(int *)(&g_MasterCardTypeTable +
                            *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) *
                            0x34) * 0x98) != arg_3) {
          iVar1 = Palette_Subsystem_004a6eb8
                            (*(int *)(&DAT_006b3088 +
                                     *(int *)(&g_MasterCardTypeTable +
                                             *(int *)(&g_CardSlot_CardId +
                                                     local_14 * 0x120 + local_8 * 0x5b20) * 0x34) *
                                     0x98));
          if (iVar1 != arg_3) goto LAB_004a6d5f;
        }
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
        {
          uVar2 = Glue_Subsystem_004d0a42(player,card_slot);
          if ((*(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + local_8 * 0x5b20) & uVar2) == 0
             ) {
            local_10 = 1;
          }
        }
      }
LAB_004a6d5f:
      local_14 = local_14 + 1;
    }
    local_8 = local_8 + 1;
  } while( true );
}



/*
 * Decompiled function: Palette_Subsystem_004a6eb8
 * Entry Point: 004a6eb8
 * Size: 104 bytes
 */


int Palette_Subsystem_004a6eb8(int player)

{
  int local_8;
  
  local_8 = -1;
  switch(player) {
  case 8:
  case 0x11:
  case 0x4a:
  case 0x57:
  case 0x5a:
  case 0x6a:
  case 0x94:
    local_8 = player + 1;
    break;
  case 9:
  case 0x12:
  case 0x4b:
  case 0x58:
  case 0x5b:
  case 0x6b:
  case 0x95:
    local_8 = player + -1;
    break;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x59:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  }
  return local_8;
}



/*
 * Decompiled function: Palette_Subsystem_004a6fef
 * Entry Point: 004a6fef
 * Size: 1486 bytes
 */


undefined4 Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 arg_10;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (flags == 0x71) {
    local_8 = g_ActivePalette;
    uVar1 = Palette_Subsystem_004a75bd(1 - spell_id);
    Palette_Subsystem_004a771b(spell_id,target_id,uVar1);
    g_ActivePalette = local_8;
  }
  if (flags == 0x73) {
    if (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) == 0))
       && ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
           (iVar2 = Font_DrawString(spell_id, 3, 2), iVar2 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0x10;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      uVar1 = *(undefined4 *)
               (&g_CardSlot_ConvertedManaCost +
               *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      arg_10 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = UI_PaintBigCardInfo((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11,arg_12,arg_13,uVar1,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
  }
  else {
    if ((((flags == 0x6d) &&
         ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (iVar2 = Palette_Subsystem_004a6d20
                           (spell_id,target_id,
                            *(int *)(&g_CardSlot_ConvertedManaCost +
                                    *(int *)(&g_CardSlot_TypeFlags +
                                            target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                                    (char)(&g_CardSlot_DamageReceived)
                                          [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20)),
        iVar2 != 0)) && (Ai_CalcManaRequirement_004ba890(spell_id,3,2), g_ActivePlayer != 1)) {
      Pic_Subsystem_00424500(s_prompts_txt_0052cb50,s_ASWANJAGUAR_0052cb44);
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_DamageReceived)
                                    [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,uVar7,
                         uVar8,uVar9,uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_10;
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_14;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        local_c = *(undefined4 *)
                   (&DAT_006b3088 +
                   *(int *)(&g_MasterCardTypeTable +
                           *(int *)(&g_CardSlot_CardId + local_14 * 0x5b20 + local_10 * 0x120) *
                           0x34) * 0x98);
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost +
                      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) *
                      0x120 + (char)(&g_CardSlot_DamageReceived)
                                    [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = Glue_Subsystem_004d0a42(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar2,uVar7,
                         uVar8,uVar9,uVar10,uVar11);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x22);
        }
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),1);
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a75bd
 * Entry Point: 004a75bd
 * Size: 147 bytes
 */


int Palette_Subsystem_004a75bd(int player)

{
  int arg2;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while ((local_8 < 500 && (*(int *)(&DAT_0069e730 + local_8 * 4 + player * 2000) != -1))) {
    local_8 = local_8 + 1;
  }
  arg2 = Math_RandomRange(local_8);
  local_c = Palette_Subsystem_004a7650(player,arg2);
  if (local_c == 0) {
    local_c = Palette_Subsystem_004a7650(player,0);
  }
  return local_c;
}



/*
 * Decompiled function: Palette_Subsystem_004a7650
 * Entry Point: 004a7650
 * Size: 203 bytes
 */


int Palette_Subsystem_004a7650(int arg1,int arg2)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = arg2;
  local_10 = 0;
  g_ActivePalette = -1;
  while ((local_c < 500 && (local_10 == 0))) {
    iVar1 = *(int *)(&DAT_0069e730 + local_c * 4 + arg1 * 2000);
    if ((iVar1 != -1) &&
       (*(int *)(&DAT_006b3084 + *(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) * 0x98) == 7)) {
      local_10 = *(int *)(&DAT_006b3088 + *(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) * 0x98);
      g_ActivePalette = iVar1;
    }
    local_c = local_c + 1;
  }
  return local_10;
}



/*
 * Decompiled function: Palette_Subsystem_004a771b
 * Entry Point: 004a771b
 * Size: 249 bytes
 */


int Palette_Subsystem_004a771b(int player,int card_slot,undefined4 arg_3)

{
  int iVar1;
  
  iVar1 = Card_ApplyTriggerEffect(player, card_slot, DAT_006fefac, player, card_slot);
  if (iVar1 != -1) {
    *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + player * 0x5b20) | 0x20;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + player * 0x5b20) = arg_3;
    if (player != 0) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + player * 0x5b20) | 0x1000;
    }
    (&g_CardSlot_DamageReceived)[player * 0x5b20 + card_slot * 0x120] = (undefined1)player;
    *(int *)(&g_CardSlot_TypeFlags + player * 0x5b20 + card_slot * 0x120) = iVar1;
  }
  return iVar1;
}



/*
 * Decompiled function: Palette_Subsystem_004a7814
 * Entry Point: 004a7814
 * Size: 529 bytes
 */


undefined4 Palette_Subsystem_004a7814(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,7,2);
    if ((iVar1 == 0) ||
       ((*(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) & 0x20014) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    Ai_CalcLifeAdvantage(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = Palette_Subsystem_004a7d05(player,card_slot), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(player,0,2);
      if (g_ActivePlayer != 1) {
        Ai_CalcManaRequirement_004ba890(player,4,-1);
      }
      if (g_ActivePlayer != 1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120) =
             g_TurnCounter;
        *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) =
             *(uint *)(&g_CardSlot_Flags + player * 0x5b20 + card_slot * 0x120) | 0x10;
      }
    }
    if ((arg_3 == 0x72) &&
       (0 < *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120))) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x27);
      }
      Palette_Subsystem_004a7a25
                (g_DialogPromptHwnd,g_DuelArenaHwnd,
                 *(int *)(&g_CardSlot_ConvertedManaCost + player * 0x5b20 + card_slot * 0x120));
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + player * 0x5b20 + card_slot * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + player * 0x5b20 + card_slot * 0x120) * 0x120) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Palette_Subsystem_004a7a25
 * Entry Point: 004a7a25
 * Size: 424 bytes
 */


int Palette_Subsystem_004a7a25(int player,int card_slot,int arg_3)

{
  int local_514;
  int local_50c;
  int local_508;
  int local_504 [320];
  
  local_514 = Palette_Subsystem_004a7bcd(player,card_slot,(int)local_504);
  local_508 = 0;
  for (; (local_508 < arg_3 && (local_514 != 0)); local_514 = local_514 + -1) {
    local_50c = Math_RandomRange(local_514);
    FUN_00415d48(local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    if ((*(int *)(&DAT_006b3088 +
                 *(int *)(&g_MasterCardTypeTable +
                         *(int *)(&g_CardSlot_CardId +
                                 local_504[local_50c * 2] * 0x5b20 +
                                 local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x58) ||
       (*(int *)(&DAT_006b3088 +
                *(int *)(&g_MasterCardTypeTable +
                        *(int *)(&g_CardSlot_CardId +
                                local_504[local_50c * 2] * 0x5b20 +
                                local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x57)) {
      Card_ApplyTriggerEffect(player,card_slot,DAT_00695df4,local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    }
    for (; local_50c < local_514; local_50c = local_50c + 1) {
      local_504[local_50c * 2] = local_504[local_50c * 2 + 2];
      local_504[local_50c * 2 + 1] = local_504[local_50c * 2 + 3];
    }
    local_508 = local_508 + 1;
  }
  return local_508;
}



/*
 * Decompiled function: Palette_Subsystem_004a7bcd
 * Entry Point: 004a7bcd
 * Size: 312 bytes
 */


int Palette_Subsystem_004a7bcd(int player,int card_slot,int arg_3)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) != -1) &&
          (((&g_CardSlot_Flags)[local_8 * 0x5b20 + local_10 * 0x120] & 2) != 0)) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) * 0x34] & 2) != 0)) {
        uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
        if ((*(uint *)(&g_CardSlot_Abilities2 + local_8 * 0x5b20 + local_10 * 0x120) & uVar1) == 0)
        {
          *(int *)(arg_3 + local_c * 8) = local_8;
          *(int *)(arg_3 + 4 + local_c * 8) = local_10;
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}



/*
 * Decompiled function: Palette_Subsystem_004a7d05
 * Entry Point: 004a7d05
 * Size: 311 bytes
 */


int Palette_Subsystem_004a7d05(int arg1,int arg2)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_c == 0))) {
    local_10 = 0;
    while ((local_10 < (int)(&g_PlayerActiveCardCount)[local_8] && (local_c == 0))) {
      if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)) {
        uVar1 = Glue_Subsystem_004d0a42(arg1,arg2);
        if ((*(uint *)(&g_CardSlot_Abilities2 + local_10 * 0x120 + local_8 * 0x5b20) & uVar1) == 0)
        {
          local_c = 1;
        }
      }
      local_10 = local_10 + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_c;
}



/*
 * Decompiled function: Palette_Subsystem_004a7e3c
 * Entry Point: 004a7e3c
 * Size: 238 bytes
 */


undefined4 Palette_Subsystem_004a7e3c(int player,int card_slot,int arg_3)

{
  if ((((arg_3 == 0x82) &&
       (*(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    *(uint *)(&DAT_006a6038 +
             *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) =
         *(uint *)(&DAT_006a6038 +
                  *(int *)(&g_CardSlot_OriginalCardId + card_slot * 0x120 + player * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[card_slot * 0x120 + player * 0x5b20] * 0x5b20) &
         0xfffffffc;
    Pic_Subsystem_0044867e(player,card_slot,1);
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a7f2a
 * Entry Point: 004a7f2a
 * Size: 487 bytes
 */


undefined4 Palette_Subsystem_004a7f2a(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_504 [320];
  
  if (arg_3 == 0x73) {
    iVar1 = Font_DrawString(player,3,2);
    if ((iVar1 == 0) || (iVar1 = Font_DrawString(player,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_006b2d40 = 1;
      Ai_CalcManaRequirement_004ba890(player,3,2);
      if (g_ActivePlayer != 1) {
        uVar2 = Math_RandomRange(0x14);
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) = uVar2;
        iVar1 = Palette_Subsystem_004a7bcd(player,card_slot,(int)local_504);
        iVar1 = Math_RandomRange(iVar1);
        *(undefined4 *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) =
             local_504[iVar1 * 2];
        *(undefined4 *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) =
             local_504[iVar1 * 2 + 1];
        (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 1;
      }
    }
    if ((arg_3 == 0x72) && ((&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] != '\0')) {
      Palette_Subsystem_004a8111
                (player,card_slot,
                 *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20));
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Palette_Subsystem_004a8111
 * Entry Point: 004a8111
 * Size: 3040 bytes
 */


undefined4 Palette_Subsystem_004a8111(int player,int card_slot,int arg_3)

{
  byte bVar1;
  short sVar2;
  uint arg_11;
  int iVar3;
  uint arg_12;
  uint arg_13;
  int iVar4;
  int iVar5;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  int local_c;
  int local_8;
  
  arg_20 = 0;
  arg_19 = 0;
  arg_18 = 0;
  arg_17 = 0xffffffff;
  arg_16 = 0xffffffff;
  iVar5 = -1;
  iVar4 = -1;
  arg_13 = 0;
  arg_12 = 0;
  arg_11 = Glue_Subsystem_004d0a42(player,card_slot);
  iVar4 = Rules_ParseFilter_0040360b
                    (*(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20),
                     *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20),(char *)0x0
                     ,player,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,iVar5,arg_16,arg_17,arg_18,
                     arg_19,arg_20);
  if (iVar4 == 0) {
    g_ActivePlayer = 1;
  }
  else {
    iVar4 = *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20);
    iVar5 = *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
    local_c = -1;
    if ((((-1 < arg_3) && (arg_3 < 0x14)) && (arg_3 != 0xd)) && (arg_3 != 1)) {
      strcpy(&g_OverworldWorldState,s_casts_Berserk__0052c698 + arg_3 * 0x32);
      Ai_Subsystem_004cc56d(player,player,card_slot,iVar4,iVar5,&g_OverworldWorldState,0);
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x24);
      }
    }
    switch(arg_3) {
    case 0:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + player * 0x5b20) = 0x80;
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + player * 0x5b20) =
             *(undefined2 *)(&g_CardSlot_Counters + iVar4 * 0x5b20 + iVar5 * 0x120);
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) | 0x4000;
      }
      break;
    case 1:
      if (*(short *)(&g_CardSlot_Counters + iVar4 * 0x5b20 + iVar5 * 0x120) < 3) {
        Ai_Subsystem_004cc56d
                  (player,player,card_slot,iVar4,iVar5,s_activates_Tawnos_s_Wand_effect__0052cb7c,0);
        local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_00696734,iVar4,iVar5);
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x24);
        }
      }
      else {
        g_ActivePlayer = 1;
        Ai_Subsystem_004cc56d
                  (player,player,card_slot,iVar4,iVar5,s_fizzles_attempting_Tawnos_s_Wand_0052cba0,0);
      }
      break;
    case 2:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + player * 0x5b20) = 4;
        sVar2 = Math_Clamp(4,0,*(short *)(&DAT_006a5f46 + iVar4 * 0x5b20 + iVar5 * 0x120) + -1);
        *(short *)(&DAT_006a5f4a + local_c * 0x120 + player * 0x5b20) = -sVar2;
      }
      break;
    case 3:
      bVar1 = Card_SetTapState(player,card_slot,3);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 4:
      bVar1 = Card_SetTapState(player,card_slot,5);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 5:
      bVar1 = Card_SetTapState(player,card_slot,4);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 6:
      Card_ApplyCombatDamage(iVar4, iVar5, 3, g_DialogPromptHwnd, g_DuelArenaHwnd);
      break;
    case 7:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_Abilities2 + local_c * 0x120 + player * 0x5b20) = 0;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + player * 0x5b20) = 0x20;
      }
      break;
    case 8:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + player * 0x5b20) = 3;
        *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + player * 0x5b20) = 3;
      }
      break;
    case 9:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_0069f6dc,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + player * 0x5b20) = 0x40;
      }
      *(undefined4 *)(&g_CardSlot_Abilities2 + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 10:
      bVar1 = Card_SetTapState(player,card_slot,1);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xb:
      bVar1 = Card_SetTapState(player,card_slot,2);
      (&DAT_006a5f4d)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xc:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) | 0x800000;
      }
      *(undefined4 *)(&g_CardSlot_Abilities2 + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 0xd:
      iVar3 = Ai_Subsystem_004cc56d
                        (player,player,card_slot,iVar4,iVar5,s_casts_Twiddle__Tap__Untap__0052cb5c,
                         (*(uint *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x10) >> 4
                        );
      if (iVar3 == 0) {
        FUN_00415d48(iVar4,iVar5);
      }
      else {
        *(uint *)(&g_CardSlot_Flags + iVar4 * 0x5b20 + iVar5 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + iVar4 * 0x5b20 + iVar5 * 0x120) & 0xffffffef;
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x24);
      }
      break;
    case 0xe:
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a2854,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006a5f48 + local_c * 0x120 + player * 0x5b20) = 0xfffe;
        *(undefined2 *)(&DAT_006a5f4a + local_c * 0x120 + player * 0x5b20) = 0;
      }
      break;
    case 0xf:
      FUN_0041da41(iVar4,iVar5);
      break;
    case 0x10:
      Card_ApplyCombatDamage(iVar4,iVar5,1,g_DialogPromptHwnd,g_DuelArenaHwnd);
      break;
    case 0x11:
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006b3060)
              && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
             (((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == iVar4 &&
              (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == iVar5)))
             ) {
            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) =
                 *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_8 * 0x5b20) & 0xfeffffff
            ;
          }
        }
      }
      local_c = Card_ApplyTriggerEffect(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006b3060,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + player * 0x5b20) | 0x1000000;
        *(ushort *)(&DAT_006a5f48 + local_c * 0x120 + player * 0x5b20) =
             -(*(ushort *)
                (&DAT_0051aec2 +
                *(int *)(&g_CardSlot_CardId + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34) & 0xbfff);
        *(ushort *)(&DAT_006a5f4a + local_c * 0x120 + player * 0x5b20) =
             2 - (*(ushort *)
                   (&DAT_0051aec4 +
                   *(int *)(&g_CardSlot_CardId + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34) & 0xbfff);
      }
      break;
    case 0x12:
      iVar3 = Card_TapForMana(iVar4, iVar5, 0x32, 0xffffffff);
      (&g_PlayerCreatureCount)[iVar4] = (&g_PlayerCreatureCount)[iVar4] + iVar3;
      Pic_Subsystem_0044867e(iVar4,iVar5,4);
      break;
    case 0x13:
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2c);
        Sleep(0xdac);
      }
      *(short *)(&DAT_006a5f4a + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(short *)(&DAT_006a5f4a + iVar4 * 0x5b20 + iVar5 * 0x120) + -1;
      *(int *)(&DAT_006a5f7c + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(int *)(&DAT_006a5f7c + iVar4 * 0x5b20 + iVar5 * 0x120) + 0x1000000;
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2b);
      }
      break;
    default:
      Ai_Subsystem_004cc56d(player,player,card_slot,iVar4,iVar5,s_made_an_error__0052cbcc,0);
    }
    if (local_c != -1) {
      iVar4 = FUN_00478aa4(*(int *)(&DAT_0052c640 + arg_3 * 4),player,card_slot);
      *(uint *)(&DAT_006a5f74 + local_c * 0x120 + player * 0x5b20) =
           iVar4 << 0x10 | *(uint *)(&DAT_0052c640 + arg_3 * 4);
    }
  }
  (&g_CardSlot_TurnPlayed)
  [*(int *)(&g_CardSlot_TapState + card_slot * 0x120 + player * 0x5b20) * 0x5b20 +
   *(int *)(&g_CardSlot_SicknessState + card_slot * 0x120 + player * 0x5b20) * 0x120] = 0;
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a8d46
 * Entry Point: 004a8d46
 * Size: 658 bytes
 */


undefined4 Palette_Subsystem_004a8d46(int player,int card_slot,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int arg_1_00;
  int local_50c;
  undefined4 local_508 [320];
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((g_ActivePlayerPriority == player) && (iVar1 = Font_DrawString(player,7,3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == card_slot)) && (g_OverworldPlayerCoordX == player)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20) =
           g_TurnCounter;
    }
    if (arg_3 == 0x71) {
      for (local_50c = 0;
          local_50c < *(int *)(&g_CardSlot_ConvertedManaCost + card_slot * 0x120 + player * 0x5b20);
          local_50c = local_50c + 1) {
        iVar1 = Math_RandomRange(0x10);
        if (*(int *)(&DAT_0052cb00 + iVar1 * 4) != 0) {
          arg_1_00 = Palette_Subsystem_004a8fd8
                               (player,card_slot,(int)local_508,*(uint *)(&DAT_0052cb00 + iVar1 * 4));
          if (arg_1_00 == 0) {
            g_ActivePlayer = 1;
          }
          else {
            local_8 = Math_RandomRange(arg_1_00);
            *(undefined4 *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20) =
                 local_508[local_8 * 2];
            *(undefined4 *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20) =
                 local_508[local_8 * 2 + 1];
            (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 1;
          }
        }
        if (g_ActivePlayer == 1) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_fizzle_0052cbdc);
            Sleep(0x5dc);
            Ai_Util_004cc42d(&DAT_0052cbe4);
          }
          g_ActivePlayer = 0;
        }
        else {
          Palette_Subsystem_004a9137(player,card_slot,iVar1);
        }
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2d);
      }
      (&g_CardSlot_TurnPlayed)[card_slot * 0x120 + player * 0x5b20] = 0;
      Pic_Subsystem_0044867e(player,card_slot,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/*
 * Decompiled function: Palette_Subsystem_004a8fd8
 * Entry Point: 004a8fd8
 * Size: 351 bytes
 */


int Palette_Subsystem_004a8fd8(int player,int card_slot,int width,uint height)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8]; local_10 = local_10 + 1)
    {
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) != -1) &&
          (((&g_CardSlot_Flags)[local_8 * 0x5b20 + local_10 * 0x120] & 2) != 0)) &&
         ((height & (byte)(&g_MasterCardColorTable)
                          [*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) * 0x34
                          ]) != 0)) {
        uVar1 = Glue_Subsystem_004d0a42(player,card_slot);
        if ((*(uint *)(&g_CardSlot_Abilities2 + local_8 * 0x5b20 + local_10 * 0x120) & uVar1) == 0)
        {
          *(int *)(width + local_c * 8) = local_8;
          *(int *)(width + 4 + local_c * 8) = local_10;
          local_c = local_c + 1;
        }
      }
    }
    if ((height & 0x100) != 0) {
      *(int *)(width + local_c * 8) = local_8;
      *(undefined4 *)(width + 4 + local_c * 8) = 0xffffffff;
      local_c = local_c + 1;
    }
  }
  return local_c;
}



/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 004a9137
 * Size: 2076 bytes
 */


undefined4 Palette_Subsystem_004a9137(int player,int card_slot,undefined4 arg_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  
  iVar3 = *(int *)(&g_CardSlot_CombatTarget + card_slot * 0x120 + player * 0x5b20);
  iVar4 = *(int *)(&g_CardSlot_AttachedAura + card_slot * 0x120 + player * 0x5b20);
  switch(arg_3) {
  case 0:
    Ai_Subsystem_004cc56d
              (player,player,card_slot,iVar3,iVar4,s_activates_Time_Elemental_effect__0052cbe8,0);
    FUN_0041da41(iVar3,iVar4);
    break;
  case 1:
    iVar2 = Math_RandomRange(2);
    strcpy(&g_OverworldWorldState,s_casts_Twiddle_to_0052cc0c);
    if (iVar2 == 0) {
      strcat(&g_OverworldWorldState,&DAT_0052cc28);
    }
    else {
      strcat(&g_OverworldWorldState,s_untap__0052cc20);
    }
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,&g_OverworldWorldState,0);
    if (iVar2 == 0) {
      if (((&g_CardSlot_Flags)[iVar3 * 0x5b20 + iVar4 * 0x120] & 0x10) == 0) {
        *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) =
             *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) | 0x10;
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34] & 1) != 0) {
          DAT_006ff2d4 = 0xffffffff;
        }
        FUN_00473e69(iVar3,iVar4,0x81);
      }
    }
    else {
      *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + iVar3 * 0x5b20 + iVar4 * 0x120) & 0xffffffef;
    }
    break;
  case 2:
    Ai_Subsystem_004cc56d
              (player,player,card_slot,iVar3,iVar4,s_activates_Aladdin_s_Ring_effect__0052cc30,0);
    Glue_Subsystem_004dfb23(player,card_slot,0x71,4);
    break;
  case 3:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_casts_Ancestral_Recall__0052cc54,0);
    FUN_0046f5d1(iVar3);
    FUN_0046f5d1(iVar3);
    FUN_0046f5d1(iVar3);
    break;
  case 4:
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_activates_Pandora_s_Box_effect__0052cd80,0);
    Minit_Subsystem_0046758c();
    break;
  case 5:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_casts_Crumble__0052cc70,0);
    cVar1 = (&DAT_0051aebf)[*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34];
    iVar2 = Math_Clamp((int)(char)(&DAT_0051aec0)
                                    [*(int *)(&g_CardSlot_CardId + iVar3 * 0x5b20 + iVar4 * 0x120) *
                                     0x34],0,99);
    (&g_PlayerCreatureCount)[iVar3] = (&g_PlayerCreatureCount)[iVar3] + cVar1 + iVar2;
    Pic_Subsystem_0044867e(iVar3,iVar4,2);
    break;
  case 6:
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_activates_Bottle_of_Suleiman_eff_0052cd20,0);
    iVar3 = Ai_Subsystem_004cc56d
                      (player,player,card_slot,-1,-1,s_Call_the_coin_flip__Heads_Tails_0052cd48,1);
    iVar4 = Ai_Subsystem_004b7d38(s_Bottle_of_Suleiman_0052cd6c);
    if (iVar4 == iVar3) {
      iVar3 = Pic_Subsystem_0045268f(0x37a);
      iVar3 = Pic_Subsystem_00451291(player,iVar3);
      if (iVar3 != -1) {
        Pic_Subsystem_0042ac1f(player,iVar3);
        *(uint *)(&g_CardSlot_Abilities1 + player * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&g_CardSlot_Abilities1 + player * 0x5b20 + iVar3 * 0x120) | 0x10;
      }
    }
    else {
      Mem_AllocOrFree_0041df33(player,5,player,card_slot);
    }
    break;
  case 7:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_casts_Disenchant__0052cc80,0);
    Pic_Subsystem_0044867e(iVar3,iVar4,1);
    break;
  case 8:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_casts_Healing_Salve__0052cc94,0);
    (&g_PlayerCreatureCount)[iVar3] = (&g_PlayerCreatureCount)[iVar3] + 3;
    break;
  case 9:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_casts_Fissure__0052ccac,0);
    Pic_Subsystem_0044867e(iVar3,iVar4,1);
    break;
  case 10:
    Ai_Subsystem_004cc56d
              (player,player,card_slot,iVar3,iVar4,s_activates_Disrupting_Sceptre_eff_0052cda4,0);
    Prompts_Load_0046fa40(iVar3,0,0);
    break;
  case 0xb:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_activates_Millstone_effect__0052ccbc,0);
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      iVar4 = *(int *)(&DAT_0069e730 + iVar3 * 2000);
      if (iVar4 != -1) {
        Pic_Subsystem_004523fd(iVar3,0);
        iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
        if (iVar4 != -1) {
          Pic_Subsystem_0044913a(iVar3,iVar4);
          *(undefined4 *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
        }
      }
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x18);
      }
    }
    break;
  case 0xc:
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_activates_The_Hive_effect__0052ccdc,0);
    iVar3 = Math_RandomRange(2);
    iVar4 = Pic_Subsystem_0045268f(0x375);
    iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
    if (iVar4 != -1) {
      Pic_Subsystem_0042ac1f(iVar3,iVar4);
      *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + iVar3 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + iVar3 * 0x5b20) | 0x10;
    }
    break;
  case 0xd:
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_activates_Nevinyrral_s_Disk_effe_0052ccf8,0);
    Glue_Subsystem_004e65e1(Minit_Subsystem_00463c10,-1);
    break;
  case 0xe:
    Ai_Subsystem_004cc56d(player,player,card_slot,-1,-1,s_casts_Fog_effect__0052cdcc,0);
    iVar3 = Card_ApplyTriggerEffect(player,card_slot,DAT_0068a670,-1,-1);
    if (iVar3 != -1) {
      *(undefined4 *)(&DAT_006a5f74 + player * 0x5b20 + iVar3 * 0x120) = DAT_0052caf0;
    }
    break;
  case 0xf:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_activates_Sinbad_effect__0052cde0,0);
    iVar4 = FUN_0046f5d1(iVar3);
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_Sinbad_draws____0052cdfc,0);
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) * 0x34] & 1) == 0) {
      Pic_Subsystem_0044913a(iVar3,iVar4);
      *(undefined4 *)(&g_CardSlot_CardId + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
      (&DAT_006b3008)[iVar3] = (&DAT_006b3008)[iVar3] + -1;
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x18);
      }
    }
    break;
  default:
    Ai_Subsystem_004cc56d(player,player,card_slot,iVar3,iVar4,s_made_an_error__0052ce0c,0);
  }
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a99a0
 * Entry Point: 004a99a0
 * Size: 3718 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Palette_Subsystem_004a99a0(int player)

{
  uint uVar1;
  int iVar2;
  uint local_9c;
  uint auStack_98 [20];
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if ((g_IsAiThinking == 1) || (DAT_00633434 != 0)) {
    local_30 = 1 - player;
    local_c = 0;
    local_38 = 0;
    local_8 = 0;
    local_28 = 0;
    local_9c = 0;
    local_34 = 2;
    if (((g_PlayerHandCardCount & 1) == 0) && (0 < (&DAT_006b3008)[player] + DAT_00627a14)) {
      for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[player];
          local_2c = local_2c + 1) {
        if (*(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120) != -1) {
          if ((((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 2) != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120) * 0x34] & 2) != 0))
          {
            local_34 = local_34 | 0x7c;
          }
          if (((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 0x12) == 0) {
            if ((((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120) * 0x34] & 1) !=
                 0) && (local_8 = 1, (&DAT_006a5f4c)[player * 0x5b20 + local_2c * 0x120] != '\0')) {
              local_38 = local_38 + 1;
            }
            if ((&DAT_0051aec0)
                [*(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120) * 0x34] == -1) {
              local_38 = local_38 + 99;
            }
            local_c = local_c + 1;
          }
        }
      }
      if (local_8 != 0) {
        local_10 = 0;
        local_8 = 0;
        for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[player];
            local_2c = local_2c + 1) {
          local_20 = *(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120);
          if ((local_20 != -1) &&
             (((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 0x12) == 0)) {
            local_40 = (uint)(char)(&DAT_0051aebe)[local_20 * 0x34];
            if ((((&g_MasterCardColorTable)[local_20 * 0x34] & 1) != 0) &&
               (local_9c = local_9c | local_40, local_40 == 0)) {
              local_10 = 1;
            }
            if ((local_34 & (byte)(&g_MasterCardColorTable)[local_20 * 0x34]) != 0) {
              for (local_48 = 1; local_48 < 6; local_48 = local_48 + 1) {
                if ((local_40 & 1 << ((byte)local_48 & 0x1f)) != 0) {
                  if (*(int *)(&DAT_0063ee30 + local_48 * 4 + player * 0x20) + 1 ==
                      (int)(char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_28 = local_28 | 1 << ((byte)local_48 & 0x1f);
                  }
                  if (*(int *)(&DAT_0063ee30 + local_48 * 4 + player * 0x20) + 1 <
                      (int)(char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_8 = local_8 | 1 << ((byte)local_48 & 0x1f);
                  }
                  iVar2 = abs((int)(char)(&DAT_0051aec0)[local_20 * 0x34]);
                  if (*(int *)(&DAT_0063ee4c + player * 0x20) <
                      iVar2 + (char)(&DAT_0051aebf)[local_20 * 0x34]) {
                    local_8 = local_8 | 0xff;
                  }
                }
              }
            }
          }
        }
        local_3c = 999;
        local_24 = local_9c;
        for (local_2c = 0; (int)local_2c < 6; local_2c = local_2c + 1) {
          if (0 < *(int *)(&DAT_006ff690 + local_2c * 4 + player * 0x20)) {
            local_8 = local_8 | 1 << ((byte)local_2c & 0x1f);
          }
          if (((local_9c & 1 << ((byte)local_2c & 0x1f)) != 0) &&
             (*(int *)(&DAT_0063ee30 + local_2c * 4 + player * 0x20) -
              *(int *)(&DAT_006ff690 + local_2c * 4 + player * 0x20) < local_3c)) {
            local_3c = *(int *)(&DAT_0063ee30 + local_2c * 4 + player * 0x20) -
                       *(int *)(&DAT_006ff690 + local_2c * 4 + player * 0x20);
            local_24 = 1 << ((byte)local_2c & 0x1f);
          }
        }
        if (local_9c == 0) {
          if ((g_IsAiThinking != 1) && (local_10 != 0)) {
            DAT_0052ce1c = 1;
            Ai_CalcCardAdvantage();
          }
          local_40 = 99;
        }
        else {
          local_18 = local_24;
          if ((local_8 & local_9c) != 0) {
            local_18 = local_8 & local_9c;
          }
          local_34 = local_28 & local_9c;
          uVar1 = local_34;
          if ((local_34 == 0) && (uVar1 = local_18, local_10 != 0)) {
            local_40 = 0xffffffff;
          }
          else {
            do {
              local_18 = uVar1;
              local_40 = Math_RandomRange(7);
              uVar1 = local_18;
            } while ((local_18 & 1 << ((byte)local_40 & 0x1f)) == 0);
          }
          if (g_IsAiThinking == 1) {
            g_AiDecisionScore = local_40;
            DAT_006fefa8 = 0xffffffff;
            iVar2 = Math_RandomRange(4);
            if ((iVar2 == 0) && (DAT_006a2838 == 0)) {
              g_AiDecisionScore = 0xfffffffe;
            }
            if ((((local_28 == 0) && (local_8 == 0)) && (local_10 == 0)) &&
               ((local_c < 7 && (3 < *(int *)(&DAT_0063ee4c + player * 0x20) - local_38)))) {
              g_AiDecisionScore = 0xfffffffe;
            }
          }
          else {
            DAT_0052ce1c = 1;
            Ai_CalcCardAdvantage();
            local_40 = g_AiDecisionScore;
          }
        }
        local_44 = 0xffffffff;
        for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[player];
            local_2c = local_2c + 1) {
          local_20 = *(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120);
          if (((((local_20 != -1) &&
                (((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 0x12) == 0)) &&
               (((&g_MasterCardColorTable)[local_20 * 0x34] & 1) != 0)) &&
              ((((local_40 == 0xffffffff &&
                 ((&DAT_006a5f4c)[player * 0x5b20 + local_2c * 0x120] == '\0')) ||
                ((1 << ((byte)local_40 & 0x1f) &
                 (int)(char)(&DAT_006a5f4c)[player * 0x5b20 + local_2c * 0x120]) != 0)) ||
               (local_9c == 0)))) && ((local_44 == 0xffffffff || (4 < local_20)))) {
            local_44 = local_2c;
          }
        }
        if ((g_IsAiThinking == 1) && ((local_9c != 0 || (local_10 != 0)))) {
          if (g_AiDecisionScore == 0xfffffffe) {
            DAT_006fefa8 = 0xffffffff;
          }
          else {
            DAT_006fefa8 = player << 8 | local_44 | 0x1000;
          }
          DAT_0052ce1c = 1;
          Ai_EvaluateCreaturePower();
          if (g_AiDecisionScore != 0xfffffffe) {
            if (0xf < DAT_006a2844) {
              DAT_006a2844 = DAT_006a2844 + -1;
            }
            *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
                 *(undefined4 *)(&g_CardSlot_CardId + player * 0x5b20 + local_44 * 0x120);
            *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = local_44;
            DAT_006a2844 = DAT_006a2844 + 1;
          }
        }
        if (g_AiDecisionScore != 0xfffffffe) {
          return local_44;
        }
        if ((local_9c == 0) && (local_10 == 0)) {
          return local_44;
        }
        g_PlayerHandCardCount = g_PlayerHandCardCount | 1;
      }
    }
    local_1c = 0;
    _DAT_0054d640 = 2;
    _DAT_005528c8 = 0x20;
    if (0x16 < g_ScWillyScore) {
      _DAT_0054d640 = 4;
      _DAT_005528c8 = 0x40;
    }
    if (g_ScWillyScore < 0x15) {
      _DAT_0054d640 = 1;
      _DAT_005528c8 = 0x10;
    }
    if (0x1d < g_ScWillyScore) {
      _DAT_0054d640 = 8;
      _DAT_005528c8 = 0xffffff80;
    }
    if (g_ScWillyScore == 0x1f) {
      _DAT_0054d640 = 0xf;
      _DAT_005528c8 = 0xfffffff0;
    }
    for (local_2c = 0; (int)local_2c < (int)(&g_PlayerActiveCardCount)[player];
        local_2c = local_2c + 1) {
      local_20 = *(int *)(&g_CardSlot_CardId + player * 0x5b20 + local_2c * 0x120);
      if (local_20 != -1) {
        if (((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 2) == 0) {
          if (((_DAT_0054d640 & (int)(char)(&DAT_0051aed5)[local_20 * 0x34]) != 0) &&
             (((&g_MasterCardColorTable)[local_20 * 0x34] & 0x7e) != 0)) {
            local_40 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[local_20 * 0x34]);
            iVar2 = FUN_00470ea3(player,player,local_2c);
            if ((iVar2 != 0) &&
               ((((&g_MasterCardColorTable)[local_20 * 0x34] & 0x3c) == 0 ||
                (iVar2 = (**(code **)(&DAT_0051aec8 + local_20 * 0x34))(player,local_2c,0x74),
                iVar2 != 0)))) {
              auStack_98[local_1c] = local_2c;
              local_1c = local_1c + 1;
            }
          }
        }
        else if ((((((&g_CardSlot_Flags)[player * 0x5b20 + local_2c * 0x120] & 0x34) == 0) &&
                  ((*(uint *)(&DAT_0051aed0 + local_20 * 0x34) & 0x1003) != 0x1000)) &&
                 ((_DAT_005528c8 & (int)(char)(&DAT_0051aed5)[local_20 * 0x34]) != 0)) &&
                (iVar2 = Magic_TriggerCardEvent(player,local_2c,0x73,1 - player,0xffffffff),
                iVar2 != 0)) {
          auStack_98[local_1c] = local_2c;
          local_1c = local_1c + 1;
        }
      }
    }
    if (local_1c == 0) {
      DAT_006a2840 = -1;
      DAT_0052ce20 = 0;
      if (DAT_006a2838 == 1) {
        DAT_006fe40c = -1;
      }
      uVar1 = 0xffffffff;
    }
    else {
      if (g_IsAiThinking == 1) {
        if (DAT_0069f6d8 == -9999) {
          DAT_00680790 = 0;
        }
        if ((DAT_006b1580 == 0x19) && (local_1c < 3)) {
          DAT_00680790 = DAT_00680790 | 1;
        }
      }
      auStack_98[local_1c] = 0xffffffff;
      local_1c = local_1c + 1;
      if (g_IsAiThinking == 1) {
        if ((DAT_006a2840 == -1) || (DAT_006a2838 != 0)) {
          g_AiDecisionScore = Math_RandomRange(local_1c);
          if (DAT_006a2838 != 0) {
            g_AiDecisionScore = local_1c - 1;
            if (DAT_006a2838 == 1) {
              iVar2 = Math_Clamp(local_1c * local_1c,10,0x14);
              DAT_006fe40c = iVar2 * (DAT_0067f380 + 1) * 5;
            }
            DAT_006a2838 = -1;
          }
          DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                            player * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120)
                                  & 2) == 0) & 0xfffff000) + 0x2000 | auStack_98[g_AiDecisionScore]
                         | (player == 0) - 1 & 0x100;
          DAT_0052ce1c = 2;
          Ai_EvaluateCreaturePower();
        }
        else {
          local_14 = Ai_Util_004ab510();
          uVar1 = DAT_0052ce20;
          if ((DAT_0052ce20 == 0) && (DAT_006a2840 < local_14)) {
            DAT_006a2840 = local_14;
          }
          if (local_14 == DAT_006a2840) {
            g_AiDecisionScore = DAT_0052ce20;
            DAT_0052ce20 = DAT_0052ce20 + 1;
            if (local_1c + -1 <= (int)uVar1) {
              DAT_006a2840 = DAT_006a2840 + 1;
              DAT_0052ce20 = 0;
            }
          }
          if (DAT_006a2840 < local_14) {
            g_AiDecisionScore = local_1c - 1;
          }
          if (local_14 < DAT_006a2840) {
            DAT_0052ce1c = 2;
            Ai_CalcCardAdvantage();
            Ai_Util_004ab525();
            if (local_1c <= (int)g_AiDecisionScore) {
              g_AiDecisionScore = local_1c - 1;
            }
          }
          DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                            player * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120)
                                  & 2) == 0) & 0xfffff000) + 0x2000 | auStack_98[g_AiDecisionScore]
                         | (player == 0) - 1 & 0x100;
          DAT_0052ce1c = 2;
          Ai_EvaluateCreaturePower();
          if ((local_1c - 1U == g_AiDecisionScore) && (local_14 < DAT_006a2840)) {
            DAT_006a2840 = -1;
            DAT_0052ce20 = 0;
          }
        }
      }
      else {
        DAT_0052ce1c = 2;
        Ai_CalcCardAdvantage();
        if (local_1c <= (int)g_AiDecisionScore) {
          g_AiDecisionScore = local_1c - 1;
        }
      }
      if (auStack_98[g_AiDecisionScore] != 0xffffffff) {
        if (0xf < DAT_006a2844) {
          DAT_006a2844 = DAT_006a2844 + -1;
        }
        *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
             *(undefined4 *)
              (&g_CardSlot_CardId + player * 0x5b20 + auStack_98[g_AiDecisionScore] * 0x120);
        *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = auStack_98[g_AiDecisionScore];
        DAT_006a2844 = DAT_006a2844 + 1;
      }
      uVar1 = auStack_98[g_AiDecisionScore];
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



