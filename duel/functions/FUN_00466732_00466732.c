/*
 * Decompiled function: FUN_00466732
 * Entry Point: 00466732
 * Size: 992 bytes
 */
#include "duel.h"


undefined4 FUN_00466732(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_18;
  int local_10;
  
  if (arg_3 == 0x3c) {
    (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] | 0x3f;
  }
  if (arg_3 == 0x1a) {
    arg1 = 1 - arg_1;
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      if ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
        local_18 = arg_2;
      }
      else {
        local_18 = (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg1]; local_10 = local_10 + 1) {
        if ((((char)(&DAT_006826de)[arg1 * 0x5b20 + local_10 * 0x120] == local_18) &&
            ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] !=
             '\0')) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] & 2)
            != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,local_10);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        if (((&DAT_004ff595)
             [*(int *)(&DAT_006826c4 +
                      arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120)
              * 0x34] != '\0') &&
           (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 +
                      arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120)
              * 0x34] & 2) != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,
                       (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        }
      }
      else {
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg1]; local_10 = local_10 + 1) {
          iVar2 = FUN_0048a33f(arg1,local_10);
          if (((iVar2 != 0) && ((&DAT_006826de)[arg1 * 0x5b20 + local_10 * 0x120] == cVar1)) &&
             (((&DAT_004ff595)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] !=
               '\0' && (((&DAT_004ff594)
                         [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_10 * 0x120) * 0x34] & 2) !=
                        0)))) {
            FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,local_10);
          }
        }
      }
    }
  }
  return 0;
}


