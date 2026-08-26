/*
 * Decompiled function: FUN_00512b50
 * Entry Point: 00512b50
 * Size: 66 bytes
 */
#include "magic.h"


undefined4 FUN_00512b50(void *arg_1)

{
  undefined1 local_1;
  
  local_1 = 0xc;
  fwrite(&local_1,1,1,DAT_00703934);
  fwrite(arg_1,3,0x100,DAT_00703934);
  return 0;
}


