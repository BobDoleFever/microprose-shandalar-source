/*
 * Decompiled function: FUN_0049b7f0
 * Entry Point: 0049b7f0
 * Size: 675 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049b7f0(undefined4 arg_1,undefined4 arg_2,char *str_3)

{
  HWND hWnd;
  int iVar1;
  uint uVar2;
  char local_7dc [2000];
  int local_c;
  HWND local_8;
  
  local_7dc[0] = '\0';
  hWnd = FindWindowA(s_MAGICGAME_MainClass_00505994,(LPCSTR)0x0);
  if (hWnd == (HWND)0x0) {
    local_8 = FindWindowA((LPCSTR)0x0,s_Magic__The_Gathering_005059a8);
    if ((local_8 == (HWND)0x0) || (iVar1 = __strnicmp(str_3,s__MTGshell_005059c0,9), iVar1 == 0)) {
      DAT_00664680 = arg_1;
      DAT_00663dfc = 0x14;
      Mem_AllocOrFree_004d9630((uint *)&DAT_00664b90,(uint *)s_Opponent_005059cc);
      Mem_AllocOrFree_004d9630((uint *)&DAT_006015b0,(uint *)&DAT_005059d8);
      FUN_00451e58();
      FUN_0049ac00();
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
      DAT_005f67e8 = 0;
      DAT_005f6c58 = 0;
      DAT_005f6494 = 0;
      DAT_005f76c0 = 0;
      DAT_005f6cb0 = 1;
      DAT_005f649c = 0;
      DAT_005f6498 = 0;
      DAT_005f6288 = 0;
      DAT_0068ee60 = 0xffffffff;
      DAT_00666418 = 0xffffffff;
      uVar2 = Save_ProcessGame_00437710(local_7dc);
      DAT_005f67ec = 0;
      DAT_005f6280 = 0;
      DAT_00617434 = 0xffffffff;
      FUN_00481c8e();
      DAT_0068f0b0 = 0;
      DAT_0068f0f8 = 0xffffffff;
      DAT_005f2f50 = DAT_00664730;
      DAT_005f64b0 = DAT_00664770;
      DAT_005f64ac = 0;
      DAT_005f64a8 = 0;
      DAT_005f67f0 = 0;
      DAT_005f628c = DAT_00664774;
      DAT_005f6294 = 0x3c;
      DAT_005f64a0 = 0;
      DAT_005f76c4 = 2;
      DAT_005f6c54 = 1;
      DAT_005f64a4 = DAT_00664778;
      DAT_004f71c4 = 0;
      _DAT_004f71c0 = 0;
      _deck = 0xffffffff;
      if (((uVar2 & 1) == 0) ||
         (local_c = UI_Register_MAGICGAME_MainClass_00437c33(local_7dc), local_c == -2)) {
        MessageBoxA((HWND)0x0,local_7dc,s_Magic__The_Gathering_duel_couldn_005059dc,0x1030);
      }
      FUN_00437b05();
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
    }
    else {
      PostMessageA(local_8,0x400,1,0);
    }
  }
  else {
    ShowWindow(hWnd,9);
    SetForegroundWindow(hWnd);
  }
  return 0;
}


