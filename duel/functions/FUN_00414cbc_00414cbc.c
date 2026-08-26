/*
 * Decompiled function: FUN_00414cbc
 * Entry Point: 00414cbc
 * Size: 389 bytes
 */
#include "duel.h"


void FUN_00414cbc(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068f104) &&
           (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
          ((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == arg_1)) &&
         (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == arg_2)) {
        *(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
        Mem_AllocOrFree_004afd1c
                  (arg_3,*(int *)(&DAT_006826e4 + local_c * 0x120 + local_8 * 0x5b20),
                   (int)(char)(&DAT_006826d3)[local_c * 0x120 + local_8 * 0x5b20],
                   *(int *)(&DAT_006826ec + local_c * 0x120 + local_8 * 0x5b20));
      }
    }
  }
  return;
}


