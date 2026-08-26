/*
 * Decompiled function: FUN_004617c4
 * Entry Point: 004617c4
 * Size: 176 bytes
 */
#include "duel.h"


undefined4 FUN_004617c4(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x1a) && (arg_1 != DAT_00666458)) &&
     ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if ((arg_3 == 0x79) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    DAT_0066642c = 1;
  }
  return 0;
}


