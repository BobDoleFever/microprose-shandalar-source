/*
 * Decompiled function: FUN_0040d2fa
 * Entry Point: 0040d2fa
 * Size: 532 bytes
 */
#include "duel.h"


undefined4 FUN_0040d2fa(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    FUN_00434660(s_prompts_txt_004f27fc,s_TETRAVITE_004f27f0);
    uVar2 = FUN_004d7d5e(0x37b,0xffffffff,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0,1,&local_10);
    iVar3 = FUN_0041e2a2(param_1,2,2,0x200,0,0,0,0,0,0,uVar2);
    if (iVar3 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      bVar1 = true;
      FUN_004d9630(&DAT_005f6810,s_Illegal_target__tetravite_not_re_004f2808);
      if ((((char)(&DAT_006826d3)[local_10 * 0x5b20 + local_c * 0x120] == DAT_00690af0) &&
          (*(int *)(&DAT_006826ec + local_10 * 0x5b20 + local_c * 0x120) == DAT_0068efa0)) &&
         (FUN_004d9630(&DAT_005f6810,s_Illegal_target__only_one_move_pe_004f283c),
         *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) == 0)) {
        FUN_00467e37(DAT_00690af0,DAT_0068efa0);
        FUN_0046e571(local_10,local_c,4);
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                     *(int *)(&DAT_006827b0 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) + 1;
        local_8 = local_8 + 1;
        bVar1 = false;
      }
      if ((bVar1) && (DAT_0066aaf4 != 1)) {
        FUN_00450eed(&DAT_005f6810);
        Sleep(2000);
        FUN_00450eed(&DAT_004f2868);
      }
    }
  } while ((DAT_00681ea4 != 1) && (local_8 == 0));
  DAT_005f6810 = 0;
  return 0;
}


