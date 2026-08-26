/*
 * Decompiled function: Pic_Subsystem_00449223
 * Entry Point: 00449223
 * Size: 121 bytes
 */
#include "magic.h"


void Pic_Subsystem_00449223(int arg1,int arg2)

{
  int local_8;
  
  for (local_8 = arg2; local_8 < 499; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_006ff714 + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_006ffedc + arg1 * 2000) = 0xffffffff;
  return;
}


