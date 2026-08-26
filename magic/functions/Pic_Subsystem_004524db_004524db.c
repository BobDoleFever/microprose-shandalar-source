/*
 * Decompiled function: Pic_Subsystem_004524db
 * Entry Point: 004524db
 * Size: 118 bytes
 */
#include "magic.h"


void Pic_Subsystem_004524db(int arg1,undefined4 arg2)

{
  int local_8;
  
  for (local_8 = 499; 0 < local_8; local_8 = local_8 + -1) {
    *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_0069e72c + local_8 * 4 + arg1 * 2000);
  }
  *(undefined4 *)(&DAT_0069e730 + arg1 * 2000) = arg2;
  return;
}


