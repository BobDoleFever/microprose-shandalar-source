/*
 * Decompiled function: FUN_004cb69a
 * Entry Point: 004cb69a
 * Size: 258 bytes
 */
#include "duel.h"


undefined4 FUN_004cb69a(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((DAT_00666458 == arg_1) && ((DAT_00681eb0 & 1) != 0)) {
      DAT_00681eb0 = DAT_00681eb0 & 0xfffffffe;
      if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else {
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


