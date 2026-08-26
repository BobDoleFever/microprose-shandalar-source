/*
 * Decompiled function: FUN_0046b887
 * Entry Point: 0046b887
 * Size: 164 bytes
 */
#include "magic.h"


void FUN_0046b887(char *str_1,int arg_2,int arg_3)

{
  if ((str_1 != (char *)0x0) && (strcpy(str_1,&DAT_00524fcc), arg_3 != 0)) {
    if (arg_2 == 1) {
      sprintf(str_1,s_Damage___0__1__counters___d_00524fd0,arg_3);
    }
    else if (arg_2 == 2) {
      sprintf(str_1,s_Mutation___1__1__counters___d_00524fec,arg_3);
    }
    else if (arg_2 == 3) {
      sprintf(str_1,s_Shackle___0__2__counters___d_0052500c,arg_3);
    }
  }
  return;
}


