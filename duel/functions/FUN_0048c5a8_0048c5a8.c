/*
 * Decompiled function: FUN_0048c5a8
 * Entry Point: 0048c5a8
 * Size: 863 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c5a8(int arg_1)

{
  int arg2;
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  uVar1 = DAT_005ef980;
  _DAT_0068dd04 = arg_1;
  _DAT_00666728 = _DAT_00666728 + 1;
  DAT_0068ef48 = DAT_0068ef48 + 1;
  if (9 < DAT_0068ef48) {
    __assert((uint *)s___nScan<10_004fb0d0,(uint *)s_D__Newmagic_sources_sid_Magic_c_004fb0b0,0x7f5)
    ;
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
      if (*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) {
        (&DAT_00666408)[local_8] = local_10 + 1;
      }
    }
  }
  for (local_14 = 0; (local_14 < 500 && (*(int *)(&DAT_00690320 + local_14 * 4) != -1));
      local_14 = local_14 + 1) {
    local_8 = *(int *)(&DAT_00690320 + local_14 * 4);
    arg2 = *(int *)(&DAT_00681ee0 + local_14 * 4);
    if (((*(int *)(&DAT_006826f4 + arg2 * 0x120 + local_8 * 0x5b20) == local_14) &&
        (*(int *)(&DAT_006826c4 + arg2 * 0x120 + local_8 * 0x5b20) != -1)) &&
       ((((&DAT_006826cc)[arg2 * 0x120 + local_8 * 0x5b20] & 2) != 0 ||
        (((&DAT_006826cc)[arg2 * 0x120 + local_8 * 0x5b20] & 0x20) != 0)))) {
      _DAT_00666448 = local_8 * 0x80 + arg2;
      if ((*(int *)(&DAT_006826c4 + arg2 * 0x120 + local_8 * 0x5b20) < 0) ||
         (DAT_00665ed0 + 0x10 < *(int *)(&DAT_006826c4 + arg2 * 0x120 + local_8 * 0x5b20))) {
        FUN_004d7e62(s_ScanCard_error_004fb0dc);
      }
      else {
        (**(code **)(&DAT_004ff5a0 +
                    *(int *)(&DAT_006826c4 + arg2 * 0x120 + local_8 * 0x5b20) * 0x34))
                  (local_8,arg2,arg_1);
        if ((((arg_1 == 0x15) && (DAT_00666458 == local_8)) &&
            (((byte)*(undefined4 *)(&DAT_006826cc + arg2 * 0x120 + local_8 * 0x5b20) & 0x14) == 4))
           && (iVar2 = FUN_0048af80(local_8,arg2), iVar2 == 0)) {
          *(uint *)(&DAT_006826cc + arg2 * 0x120 + local_8 * 0x5b20) =
               *(uint *)(&DAT_006826cc + arg2 * 0x120 + local_8 * 0x5b20) | 0x10;
          DAT_0068f0f4 = 0xffffffff;
          FUN_0048c50b(local_8,arg2,0x81);
        }
      }
    }
  }
  if ((arg_1 == 0x15) && (DAT_00666458 == local_8)) {
    FUN_0048b64f();
  }
  DAT_0068ef48 = DAT_0068ef48 + -1;
  if (DAT_00666418 != -1) {
    (**(code **)(&DAT_004ff5a0 + DAT_00666418 * 0x34))(0,0x4e,arg_1);
  }
  DAT_005ef980 = uVar1;
  return;
}


