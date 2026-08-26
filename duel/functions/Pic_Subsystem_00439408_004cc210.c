/*
 * Decompiled function: Pic_Subsystem_00439408
 * Entry Point: 004cc210
 * Size: 987 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_00439408(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (iVar2 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120),-1),
       iVar2 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068edfc + DAT_00676510 * 0x20) -
                     *(int *)(&DAT_0068edfc + DAT_00676504 * 0x20)) * 0xc;
    }
    if ((arg_3 == 0x82) &&
       (((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 2) != 0))
    {
      *(uint *)(&DAT_006827c8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
           *(uint *)(&DAT_006827c8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) & 0xfffffffd;
      _DAT_0068f0cc = _DAT_0068f0cc | 2;
    }
    if (((DAT_0068f2c4 == 1) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (((arg_3 == 0x7d) &&
          (iVar2 = FUN_0041bcf0((int *)0x0,0,DAT_00666458,DAT_00666458,DAT_00666458,0x200,2,0,0,0,0,
                                0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x800,0), iVar2 == 0
          )) && (iVar2 = FUN_0041bcf0((int *)0x0,0,DAT_00666458,DAT_00666458,DAT_00666458,0x200,2,0,
                                      0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x400,0)
                , iVar2 != 0)) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (arg_3 == 0x7e) {
        if (DAT_00666458 == 1) {
          local_10 = DAT_00666458;
          local_c = FUN_004d483e(1,2);
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,local_10,local_c,s_Opponent_chooses_to_untap__00508c9c,0);
        }
        else {
          Action_ValidateTarget_0041e2a2
                    (DAT_00666458,DAT_00666458,DAT_00666458,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,
                     0xffffffff,0,0x401,0,s_PROCESSING_Smoke__Select_creatur_00508cb8,0,&local_10);
        }
        *(uint *)(&DAT_006827c8 + local_10 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&DAT_006827c8 + local_10 * 0x5b20 + local_c * 0x120) | 2;
        for (local_8 = 0; local_8 < (int)(&DAT_00666408)[DAT_00666458]; local_8 = local_8 + 1) {
          iVar2 = FUN_0048a33f(DAT_00666458,local_8);
          if (((iVar2 != 0) &&
              (((&DAT_006826cc)[local_8 * 0x120 + DAT_00666458 * 0x5b20] & 0x10) != 0)) &&
             ((((&DAT_004ff594)
                [*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00666458 * 0x5b20) * 0x34] & 2) != 0
              && (((&DAT_006827c8)[local_8 * 0x120 + DAT_00666458 * 0x5b20] & 2) == 0)))) {
            *(uint *)(&DAT_006827c8 + local_8 * 0x120 + DAT_00666458 * 0x5b20) =
                 *(uint *)(&DAT_006827c8 + local_8 * 0x120 + DAT_00666458 * 0x5b20) & 0xfffffffe;
          }
        }
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


