/*
 * Decompiled function: Palette_Subsystem_004a4760
 * Entry Point: 004a4760
 * Size: 271 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a4760(int arg_1,int arg_2,int arg_3)

{
  int arg_3_00;
  int arg_1_00;
  int arg_2_00;
  int local_10;
  
  arg_3_00 = arg_3 + 1;
  arg_3._0_1_ = (undefined1)arg_3_00;
  (&DAT_0054bd68)[arg_2 + arg_1 * 0xd] = (undefined1)arg_3;
  for (local_10 = 1; local_10 < 9; local_10 = local_10 + 2) {
    arg_1_00 = *(int *)(&DAT_00522378 + local_10 * 4) + arg_1;
    arg_2_00 = *(int *)(&DAT_005223e0 + local_10 * 4) + arg_2;
    if (((*(int *)(&DAT_00649c20 + arg_2_00 * 4 + arg_1_00 * 0x34) != 0) &&
        ((((&DAT_0054bd68)[arg_2_00 + arg_1_00 * 0xd] == '\0' ||
          (arg_3_00 < (char)(&DAT_0054bd68)[arg_2_00 + arg_1_00 * 0xd])) && (-1 < arg_1_00)))) &&
       (((arg_1_00 < 0xf && (-1 < arg_2_00)) && (arg_2_00 < 0xd)))) {
      Palette_Subsystem_004a4760(arg_1_00,arg_2_00,arg_3_00);
    }
  }
  return;
}


