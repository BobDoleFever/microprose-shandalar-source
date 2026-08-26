/*
 * Decompiled function: FUN_00466b12
 * Entry Point: 00466b12
 * Size: 583 bytes
 */
#include "duel.h"


undefined4 FUN_00466b12(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_c;
  
  if ((((arg_3 == 0x1a) && (arg1 = 1 - arg_1, arg_1 != DAT_00666458)) &&
      ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    cVar1 = (&DAT_006826de)
            [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
    if (cVar1 == -1) {
      FUN_004a2b00(arg_1,arg_2,DAT_0068ed08,arg1,
                   (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      *(uint *)(&DAT_006826f8 +
               arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120) =
           *(uint *)(&DAT_006826f8 +
                    arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120) |
           0x8000;
    }
    else {
      for (local_c = 0; local_c < (int)(&DAT_00666408)[arg1]; local_c = local_c + 1) {
        iVar2 = FUN_0048a33f(arg1,local_c);
        if ((iVar2 != 0) && ((&DAT_006826de)[local_c * 0x120 + arg1 * 0x5b20] == cVar1)) {
          FUN_004a2b00(arg_1,arg_2,DAT_0068ed08,arg1,local_c);
          *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg1 * 0x5b20) | 0x8000;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


