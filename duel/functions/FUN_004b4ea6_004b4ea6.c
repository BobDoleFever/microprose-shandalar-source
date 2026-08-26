/*
 * Decompiled function: FUN_004b4ea6
 * Entry Point: 004b4ea6
 * Size: 86 bytes
 */
#include "duel.h"


WPARAM FUN_004b4ea6(void)

{
  DWORD arg_1;
  WPARAM wParam;
  
  arg_1 = GetTickCount();
  Mem_AllocOrFree_004d9830(arg_1);
  FUN_00451e58();
  wParam = Pic_Load_0044ef70(0,DAT_00617434);
  PostMessageA(DAT_00618990,0x401,wParam,0);
  return wParam;
}


