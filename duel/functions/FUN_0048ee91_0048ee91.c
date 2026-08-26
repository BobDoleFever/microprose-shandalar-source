/*
 * Decompiled function: FUN_0048ee91
 * Entry Point: 0048ee91
 * Size: 470 bytes
 */
#include "duel.h"


void FUN_0048ee91(int arg_1)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_10;
  
  iVar2 = 1 - arg_1;
  for (local_10 = 0; local_10 < (int)(&DAT_00666408)[arg_1]; local_10 = local_10 + 1) {
    if ((*(int *)(&DAT_006826c4 + local_10 * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((byte)*(undefined4 *)(&DAT_006826cc + local_10 * 0x120 + arg_1 * 0x5b20) & 6) == 6)) {
      bVar1 = false;
      for (local_18 = 0; local_18 < (int)(&DAT_00666408)[iVar2]; local_18 = local_18 + 1) {
        if ((*(int *)(&DAT_006826c4 + local_18 * 0x120 + iVar2 * 0x5b20) != -1) &&
           ((char)(&DAT_006826de)[local_18 * 0x120 + iVar2 * 0x5b20] == local_10)) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        for (local_18 = 0; local_18 < (int)(&DAT_00666408)[arg_1]; local_18 = local_18 + 1) {
          if ((local_18 == local_10) ||
             (((char)(&DAT_006826de)[local_18 * 0x120 + arg_1 * 0x5b20] == local_10 &&
              (((byte)*(undefined4 *)(&DAT_006826cc + local_18 * 0x120 + arg_1 * 0x5b20) & 6) == 6))
             )) {
            *(uint *)(&DAT_006826cc + local_18 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + local_18 * 0x120 + arg_1 * 0x5b20) | 0x200;
          }
        }
      }
    }
  }
  return;
}


