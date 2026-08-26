/*
 * Decompiled function: FUN_00437c33
 * Entry Point: 00437c33
 * Size: 901 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00437c33(undefined1 *param_1)

{
  DWORD DVar1;
  HANDLE pvVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 uVar5;
  HWND hWndParent;
  HMENU hMenu;
  HINSTANCE hInstance;
  int iVar6;
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
  
  DVar1 = GetTickCount();
  FUN_004d9830(DVar1);
  local_40 = 1;
  *param_1 = 0;
  iVar6 = 1;
  pvVar2 = GetCurrentThread();
  SetThreadPriority(pvVar2,iVar6);
  local_3c.cbSize = 0x24;
  local_10 = SHAppBarMessage(4,&local_3c);
  local_c = local_10 & 1;
  local_8 = local_10 & 2;
  OutputDebugStringA(s_Main__initializing_critical_sect_004f6c90);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
  DAT_00601618 = 0;
  DAT_0060cc60 = 0;
  DAT_0060cc70 = 1;
  DAT_005f77f0 = 0;
  DAT_0061815c = 0;
  DAT_00601580 = 0;
  _DAT_0060d494 = 0;
  FUN_0048111e();
  DAT_00663e30 = LoadCursorA(DAT_00664680,s_Hand1_004f6cb8);
  DAT_00663e34 = LoadCursorA(DAT_00664680,s_SwordWait_004f6cc0);
  DAT_00663e60 = 3;
  _DAT_00663e38 = LoadCursorA(DAT_00664680,s_Hand2_004f6ccc);
  _DAT_00663e3c = LoadCursorA(DAT_00664680,s_Hand3_004f6cd4);
  _DAT_00663e40 = LoadCursorA(DAT_00664680,s_Hand4_004f6cdc);
  FUN_00438368();
  OutputDebugStringA(s_Main__creating_windows_004f6ce4);
  local_60 = 0x82000000;
  if (1 < (int)DAT_00663dfc) {
    local_60 = 0x82040000;
  }
  if ((DAT_00663dfc & 1) == 0) {
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = DAT_005f67ec;
    hInstance = DAT_00664680;
    iVar6 = GetSystemMetrics(1);
    iVar3 = GetSystemMetrics(0);
    DAT_00618990 = CreateWindowExA(0,s_MAGICGAME_MainClass_004f6d20,s_Magic_004f6d18,local_60,1,0,
                                   iVar3 + -1,iVar6,hWndParent,hMenu,hInstance,lpParam);
  }
  else {
    DAT_00618990 = CreateWindowExA(0,s_MAGICGAME_MainClass_004f6d04,s_Magic_004f6cfc,local_60,1,0,
                                   DAT_005071c8,DAT_005071cc,DAT_005f67ec,(HMENU)0x0,DAT_00664680,
                                   (LPVOID)0x0);
  }
  if (DAT_00618990 == (HWND)0x0) {
    local_40 = 0;
    FUN_004d9640(param_1,s_Couldn_t_create_the_main_window_004f6d34);
  }
  DAT_00664c2c = LoadAcceleratorsA(DAT_00664680,(LPCSTR)0x6f);
  if (((DAT_00663dfc & 4) != 0) || ((DAT_00663dfc & 2) != 0)) {
    Sound_Init(DAT_00618990,0,0);
  }
  FUN_0048d320();
  if (local_40 == 0) {
    uVar5 = 0xfffffffe;
  }
  else {
    FUN_004386c1();
    while( true ) {
      BVar4 = GetMessageA(&local_5c,(HWND)0x0,0,0);
      if (BVar4 == 0) break;
      FUN_00437fb8(&local_5c);
    }
    local_14 = local_5c.wParam;
    FUN_0043850a();
    if (DAT_00663e30 != (HCURSOR)0x0) {
      DestroyCursor(DAT_00663e30);
    }
    if (DAT_00663e34 != (HCURSOR)0x0) {
      DestroyCursor(DAT_00663e34);
    }
    for (local_18 = 0; local_18 < DAT_00663e60; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_00663e38 + local_18 * 4) != 0) {
        DestroyCursor(*(HCURSOR *)(&DAT_00663e38 + local_18 * 4));
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
    FUN_0048d3af();
    if (((DAT_00663dfc & 2) != 0) || ((DAT_00663dfc & 4) != 0)) {
      CloseSnd();
    }
    GdiFlush();
    iVar6 = 0;
    pvVar2 = GetCurrentThread();
    SetThreadPriority(pvVar2,iVar6);
    uVar5 = DAT_006679e0;
  }
  return uVar5;
}


