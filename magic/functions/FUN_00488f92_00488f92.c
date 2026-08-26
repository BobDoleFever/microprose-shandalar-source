/*
 * Decompiled function: FUN_00488f92
 * Entry Point: 00488f92
 * Size: 73 bytes
 */
#include "magic.h"


undefined4 FUN_00488f92(int arg_1)

{
  strcat(&g_OverworldWorldState,&DAT_00527a94 + ((*(int *)(&DAT_005270e4 + arg_1 * 4) != 0) - 1 & 8)
        );
  return *(undefined4 *)(&DAT_005270e4 + arg_1 * 4);
}


