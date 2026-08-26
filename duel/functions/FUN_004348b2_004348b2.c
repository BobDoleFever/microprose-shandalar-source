/*
 * Decompiled function: FUN_004348b2
 * Entry Point: 004348b2
 * Size: 340 bytes
 */
#include "duel.h"


uint FUN_004348b2(undefined4 arg1,undefined4 arg2)

{
  uint arg_1;
  int iVar1;
  size_t sVar2;
  int local_18;
  int local_10;
  int local_c;
  
  if (DAT_0066aaf4 == 1) {
    arg_1 = 0;
  }
  else {
    arg_1 = FUN_00434660(arg1,arg2);
    for (local_c = 0; iVar1 = Mem_AllocOrFree_004d9810(arg_1), local_c < iVar1;
        local_c = local_c + 1) {
      sVar2 = _strlen(&DAT_006679f0 + local_c * 0xfa);
      local_18 = 0;
      for (local_10 = 0; local_10 < (int)sVar2; local_10 = local_10 + 1) {
        if (((&DAT_006679f0)[local_c * 0xfa + local_10] == '\\') &&
           ((&DAT_006679f1)[local_c * 0xfa + local_10] == 'n')) {
          (&DAT_006679f0)[local_c * 0xfa + local_18] = 10;
          local_10 = local_10 + 1;
        }
        else {
          (&DAT_006679f0)[local_c * 0xfa + local_18] = (&DAT_006679f0)[local_c * 0xfa + local_10];
        }
        local_18 = local_18 + 1;
      }
      (&DAT_006679f0)[local_c * 0xfa + local_18] = 0;
    }
  }
  return arg_1;
}


