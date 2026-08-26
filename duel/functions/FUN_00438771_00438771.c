/*
 * Decompiled function: FUN_00438771
 * Entry Point: 00438771
 * Size: 487 bytes
 */
#include "duel.h"


LRESULT FUN_00438771(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  LRESULT LVar1;
  
  if (param_2 == 0x4c8) {
    LVar1 = SendMessageA(DAT_00516734,0x181,0,param_4);
    if (LVar1 == -2) {
      LVar1 = SendMessageA(DAT_00516734,0x18b,0,0);
      SendMessageA(DAT_00516734,0x182,LVar1 - 1,0);
      SendMessageA(DAT_00516734,0x182,LVar1 - 2,0);
      SendMessageA(DAT_00516734,0x181,0,param_4);
    }
    return 0;
  }
  if (param_2 < 0x11) {
    if (param_2 == 0x10) {
      ShowWindow(param_1,0);
      return 0;
    }
    switch(param_2) {
    case 1:
      DAT_00516734 = CreateWindowExA(0,s_LISTBOX_004f7190,&DAT_004f718c,0x50240000,0,0,0,0,param_1,
                                     (HMENU)0x0,DAT_00664680,(LPVOID)0x0);
      LVar1 = 0;
      break;
    case 2:
      KillTimer(param_1,1);
      LVar1 = 0;
      break;
    case 3:
      SendMessageA(DAT_00516734,0x184,0,0);
      LVar1 = 0;
      break;
    default:
      goto switchD_00438930_caseD_4;
    case 5:
      MoveWindow(DAT_00516734,0,0,param_4 & 0xffff,param_4 >> 0x10,1);
      LVar1 = 0;
    }
  }
  else {
    if (param_2 == 0x113) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 == 0x201) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
switchD_00438930_caseD_4:
    LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  return LVar1;
}


