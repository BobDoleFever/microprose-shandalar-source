/*
 * Decompiled function: FUN_0047c2fd
 * Entry Point: 0047c2fd
 * Size: 99 bytes
 */
#include "magic.h"


undefined4 FUN_0047c2fd(int arg_1)

{
  Mem_AllocOrFree_0050fc00();
  DAT_00676d78 = Pic_Load_advfac64_0047c1fe
                           ((undefined4 *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676dd0)[arg_1]);
  DAT_00676d7c = Pic_Load_advfac64_0047c1fe
                           ((undefined4 *)g_DisplaySurfaceBackBuffer,0,0,(&DAT_00676d80)[arg_1]);
  FUN_0050fc20();
  return DAT_00676d78;
}


