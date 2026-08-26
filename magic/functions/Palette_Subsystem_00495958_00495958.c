/*
 * Decompiled function: Palette_Subsystem_00495958
 * Entry Point: 00495958
 * Size: 902 bytes
 */
#include "magic.h"


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
         CreateWindowExA(0,s_MAGICGAME_MainClass_0052b29c,s_Magic_0052b294,local_60,1,0,DAT_00522458
                         ,DAT_0052245c,_hwndScreen,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
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


