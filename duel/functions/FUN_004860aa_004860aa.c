/*
 * Decompiled function: FUN_004860aa
 * Entry Point: 004860aa
 * Size: 161 bytes
 */
#include "duel.h"


void FUN_004860aa(char *str_1,int arg_2,int arg_3)

{
  if ((str_1 != (char *)0x0) &&
     (Mem_AllocOrFree_004d9630((uint *)str_1,(uint *)&DAT_004faa34), arg_3 != 0)) {
    if (arg_2 == 1) {
      _sprintf(str_1,s_Damage___0__1__counters___d_004faa38,arg_3);
    }
    else if (arg_2 == 2) {
      _sprintf(str_1,s_Mutation___1__1__counters___d_004faa54,arg_3);
    }
    else if (arg_2 == 3) {
      _sprintf(str_1,s_Shackle___0__2__counters___d_004faa74,arg_3);
    }
  }
  return;
}


