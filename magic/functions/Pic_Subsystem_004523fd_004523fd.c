/*
 * Decompiled function: Pic_Subsystem_004523fd
 * Entry Point: 004523fd
 * Size: 97 bytes
 */
#include "magic.h"


void Pic_Subsystem_004523fd(int arg1,int arg2)

{
  int local_8;
  
  while (local_8 = arg2 + 1, local_8 < 500) {
    *(undefined4 *)(&DAT_0069e72c + local_8 * 4 + arg1 * 2000) =
         *(undefined4 *)(&DAT_0069e730 + local_8 * 4 + arg1 * 2000);
    arg2 = local_8;
  }
  return;
}


