/*
 * Decompiled function: FUN_00484691
 * Entry Point: 00484691
 * Size: 167 bytes
 */
#include "magic.h"


void FUN_00484691(byte arg1,int arg2)

{
  int local_c;
  
  for (local_c = 0; local_c < 500; local_c = local_c + 1) {
    if ((*(int *)(&deck + local_c * 4) != -1) &&
       ((1 << (arg1 & 0x1f) &
        (int)(char)(&DAT_0051aebe)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0)) {
      if (arg2 == 0) {
        *(uint *)(&deck + local_c * 4) = *(uint *)(&deck + local_c * 4) | 0x4000;
      }
      else {
        *(uint *)(&deck + local_c * 4) = *(uint *)(&deck + local_c * 4) & 0xffffbfff;
      }
    }
  }
  return;
}


