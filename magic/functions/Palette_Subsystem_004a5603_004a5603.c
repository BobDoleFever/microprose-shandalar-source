/*
 * Decompiled function: Palette_Subsystem_004a5603
 * Entry Point: 004a5603
 * Size: 287 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a5603(int arg1,int arg2)

{
  int local_10;
  int local_c;
  int local_8;
  
  *(uint *)(&DAT_00649c20 + arg2 * 4 + arg1 * 0x34) =
       *(uint *)(&DAT_00649c20 + arg2 * 4 + arg1 * 0x34) | 0x100;
  DAT_0054be2c = 0;
  for (local_8 = 1; local_8 < 9; local_8 = local_8 + 2) {
    local_c = arg1;
    local_10 = arg2;
    while( true ) {
      local_c = local_c + *(int *)(&DAT_00522378 + local_8 * 4);
      local_10 = local_10 + *(int *)(&DAT_005223e0 + local_8 * 4);
      if ((((local_c < 0) || (0xe < local_c)) || (local_10 < 0)) ||
         ((0xc < local_10 || (*(int *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) == 0))))
      break;
      if (((&DAT_00649c21)[local_c * 0x34 + local_10 * 4] & 1) == 0) {
        DAT_0054be2c = 1;
      }
      *(uint *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) =
           *(uint *)(&DAT_00649c20 + local_c * 0x34 + local_10 * 4) | 0x100;
    }
  }
  return;
}


