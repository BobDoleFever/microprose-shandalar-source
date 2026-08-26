/*
 * Decompiled function: Pic_Subsystem_0044d61a
 * Entry Point: 004bb0c2
 * Size: 92 bytes
 */
#include "duel.h"


void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 arg_3)

{
  _sprintf(str_1,s__s___d__005087b4,s_Your_hand_0050879c + ((hwnd == DAT_006152b0) - 1 & 0xc),arg_3)
  ;
  SetWindowTextA(hwnd,str_1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  return;
}


