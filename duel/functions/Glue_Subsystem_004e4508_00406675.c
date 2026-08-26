/*
 * Decompiled function: Glue_Subsystem_004e4508
 * Entry Point: 00406675
 * Size: 706 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e4508(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if ((DAT_00676510 == arg_1) && (DAT_0066aaf4 != 1)) {
        iVar2 = FUN_004512d1(arg_1,s_Drafna_s_Restoration__004f22fc,0,s_My_graveyard_004f22ec,
                             s_Opponent_s_graveyard_004f22d4,(char *)0x0);
        if (iVar2 == 0) {
          local_c = arg_1;
        }
        else {
          local_c = 1 - arg_1;
        }
        local_8 = Palette_Subsystem_004a5722
                            (arg_1,(int *)(&DAT_0068f370 + local_c * 2000),500,
                             s_Pick_an_artifact_004f2318,1,&DAT_004f2314);
        if ((local_8 != 0xffffffff) &&
           (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + local_c * 2000) * 0x34] & 0x40)
            == 0)) {
          local_8 = 0xffffffff;
        }
      }
      else {
        local_c = arg_1;
        local_8 = FUN_0040800f(arg_1,0x40);
      }
      if (((local_8 == 0xffffffff) || (*(int *)(&DAT_0068f370 + local_8 * 4 + local_c * 2000) == -1)
          ) || (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + local_c * 2000) * 0x34] &
                0x40) == 0)) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c << 8 | local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar2 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (((iVar2 != -1) && (*(int *)(&DAT_0068f370 + iVar2 * 4 + local_c * 2000) != -1)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + iVar2 * 4 + local_c * 2000) * 0x34] & 0x40) != 0
         )) {
        FUN_004d7baa(local_c,*(undefined4 *)(&DAT_0068f370 + iVar2 * 4 + local_c * 2000));
        *(undefined4 *)(&DAT_0068f370 + iVar2 * 4 + local_c * 2000) = 0xffffffff;
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


