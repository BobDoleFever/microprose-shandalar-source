/*
 * Decompiled function: FUN_10010e1f
 * Entry Point: 10010e1f
 * Size: 1387 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_10010e1f(HWND hwnd,uint32_t arg_2,int32_t arg_3)

{
  HMODULE pHVar1;
  int val_2;
  HWND pHVar3;
  int nHeight;
  BOOL BVar4;
  char *pcVar5;
  LPCSTR pCVar6;
  HDC hDC;
  tagMSG local_2c;
  int32_t local_10;
  HDC local_c;
  HACCEL local_8;
  
  local_10 = 0;
  _DAT_1017646c = arg_2;
  _DAT_101cdea0 = arg_3;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  _getcwd(&DAT_10176990,0x105);
  _chdir(&DAT_10158770);
  pcVar5 = s_CardIDFromType_10042730;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  _FUN_101cdebc = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s_CardTypeFromID_10042740;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_10175eec = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s_CardInDeck_10042750;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_101cf338 = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s_SetCardInDeck_1004275c;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_10176310 = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s_SellPrice_1004276c;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_101625f8 = GetProcAddress(pHVar1,pcVar5);
  pCVar6 = &DAT_10042778;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  deck = GetProcAddress(pHVar1,pCVar6);
  pCVar6 = &DAT_10042780;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_101cfb7c = GetProcAddress(pHVar1,pCVar6);
  pcVar5 = s_Scards_10042788;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_1017697c = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s_szDeckName_10042790;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_10175ee4 = GetProcAddress(pHVar1,pcVar5);
  pcVar5 = s__currentDeck_1004279c;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  DAT_10176484 = GetProcAddress(pHVar1,pcVar5);
  if ((_DAT_1017646c & 1) == 0) {
    if ((((_DAT_1017646c & 4) != 0) || ((_DAT_1017646c & 8) != 0)) &&
       ((_FUN_101cdebc == (FARPROC)0x0 ||
        ((((DAT_10175eec == (FARPROC)0x0 || (DAT_101cf338 == (FARPROC)0x0)) ||
          (DAT_10176310 == (FARPROC)0x0)) ||
         ((DAT_101cfb7c == (FARPROC)0x0 || (DAT_10175ee4 == (FARPROC)0x0)))))))) {
      thunk_FUN_100129a2(s_Deck_Builder_WinMain__Couldn_t_f_100427e4,(HWND)0x0);
      return 0;
    }
  }
  else if (((_FUN_101cdebc == (FARPROC)0x0) || (DAT_101cf338 == (FARPROC)0x0)) ||
          (((DAT_10176310 == (FARPROC)0x0 ||
            (((DAT_101625f8 == (FARPROC)0x0 || (deck == (FARPROC)0x0)) ||
             (DAT_101cfb7c == (FARPROC)0x0)))) ||
           ((DAT_1017697c == (FARPROC)0x0 || (DAT_10176484 == (FARPROC)0x0)))))) {
    thunk_FUN_100129a2(s_Deck_Builder_WinMain__Couldn_t_f_100427ac,(HWND)0x0);
    return 0;
  }
  val_2 = thunk_FUN_100320aa();
  if (val_2 == 0) {
    thunk_FUN_100129a2(s_WinMain__Couldn_t_create_the_pal_1004281c,(HWND)0x0);
    local_2c.wParam = 0;
  }
  else {
    if ((_DAT_1017646c & 1) != 0) {
      _DAT_10162904 = *(int32_t *)DAT_10176484;
    }
    pHVar3 = GetDesktopWindow();
    local_c = GetDC(pHVar3);
    DAT_101625e8 = CreateCompatibleDC(local_c);
    DAT_101cf924 = CreateCompatibleBitmap(local_c,800,800);
    if ((DAT_101625e8 == (HDC)0x0) || (DAT_101cf924 == (HBITMAP)0x0)) {
      thunk_FUN_100129a2(s_WinMain__Couldn_t_create_the_app_10042844,(HWND)0x0);
    }
    thunk_FUN_10031425(DAT_101625e8);
    DAT_101cfb94 = SelectObject(DAT_101625e8,DAT_101cf924);
    hDC = local_c;
    pHVar3 = GetDesktopWindow();
    ReleaseDC(pHVar3,hDC);
    val_2 = thunk_FUN_10031350();
    if (val_2 == 0) {
      thunk_FUN_100129a2(s_WinMain__Couldn_t_load_deck_buil_10042880,(HWND)0x0);
      local_2c.wParam = 0;
    }
    else {
      val_2 = thunk_FUN_1001162f();
      if (val_2 == 0) {
        thunk_FUN_100129a2(s_WinMain__Couldn_t_load_deck_buil_100428ac,(HWND)0x0);
        local_2c.wParam = 0;
      }
      else {
        val_2 = thunk_FUN_10019440();
        if (val_2 == 0) {
          thunk_FUN_100129a2(s_WinMain__Couldn_t_load_the_card_b_100428d8,(HWND)0x0);
          local_2c.wParam = 0;
        }
        else {
          val_2 = thunk_FUN_100127ad();
          if (val_2 == 0) {
            thunk_FUN_100129a2(s_WinMain__Couldn_t_create_the_win_1004290c,(HWND)0x0);
            local_2c.wParam = 0;
          }
          else {
            val_2 = GetSystemMetrics(0);
            nHeight = GetSystemMetrics(1);
            DAT_10176868 = CreateWindowExA(0,s_MAGICDECK_MainClass_10042950,s_Deck_Maker_10042944,
                                           0x90040000,0,0,val_2,nHeight,hwnd,(HMENU)0x0,DAT_101cf334
                                           ,(LPVOID)0x0);
            if (DAT_10176868 == (HWND)0x0) {
              thunk_FUN_100129a2(s_WinMain__Couldn_t_create_the_mai_10042964,(HWND)0x0);
              local_2c.wParam = 0;
            }
            else {
              DAT_10176314 = CreateWindowExA(0,s_CueCardClass_10042994,&DAT_10042990,0x80000000,0,0,
                                             0,0,DAT_10176868,(HMENU)0x0,DAT_101cf334,(LPVOID)0x0);
              if (DAT_10176314 == (HWND)0x0) {
                thunk_FUN_100129a2(s_WinMain__Couldn_t_create_the_cue_100429a4,DAT_10176868);
                local_2c.wParam = 0;
              }
              else {
                local_8 = LoadAcceleratorsA(DAT_101cf334,(LPCSTR)0x66);
                if (local_8 == (HACCEL)0x0) {
                  thunk_FUN_100129a2(s_WinMain__Couldn_t_load_the_accel_100429d4,DAT_10176868);
                  local_2c.wParam = 0;
                }
                else {
                  ShowWindow(DAT_10176868,1);
                  SetTimer(DAT_10176868,0,500,(TIMERPROC)0x0);
                  SetForegroundWindow(DAT_10176868);
                  while (BVar4 = GetMessageA(&local_2c,(HWND)0x0,0,0), BVar4 != 0) {
                    val_2 = TranslateAcceleratorA(DAT_10176868,local_8,&local_2c);
                    if ((val_2 == 0) && (val_2 = thunk_FUN_10011447((int *)&local_2c), val_2 == 0))
                    {
                      TranslateMessage(&local_2c);
                      DispatchMessageA(&local_2c);
                    }
                  }
                  thunk_FUN_10010cda();
                  thunk_FUN_100313ad();
                  thunk_FUN_10019f35();
                  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
                }
              }
            }
          }
        }
      }
    }
  }
  return local_2c.wParam;
}


