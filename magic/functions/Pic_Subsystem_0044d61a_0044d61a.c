/*
 * Decompiled function: Pic_Subsystem_0044d61a
 * Entry Point: 0044d61a
 * Size: 93 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044d61a(char *str_1,HWND hwnd,undefined4 arg_3)

{
  sprintf(str_1,s__s___d__00523b68,s_Your_hand_00523b50 + ((hwnd == DAT_0069e720) - 1 & 0xc),arg_3);
  SetWindowTextA(hwnd,str_1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  return;
}


