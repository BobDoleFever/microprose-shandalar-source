/*
 * Decompiled function: Palette_Subsystem_00496497
 * Entry Point: 00496497
 * Size: 484 bytes
 */
#include "magic.h"


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


