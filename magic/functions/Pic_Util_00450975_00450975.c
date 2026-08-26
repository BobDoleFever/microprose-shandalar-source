/*
 * Decompiled function: Pic_Util_00450975
 * Entry Point: 00450975
 * Size: 39 bytes
 */
#include "magic.h"


void Pic_Util_00450975(DWORD arg_1)

{
  PostMessageA(g_MainAppHwnd,0x401,arg_1,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(arg_1);
}


