/*
 * Decompiled function: Minit_Subsystem_0045a575
 * Entry Point: 0040d2fa
 * Size: 532 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_0045a575(int spell_id,int target_id)

{
  bool bVar1;
  int iVar2;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  do {
    FUN_00434660(s_prompts_txt_004f27fc,s_TETRAVITE_004f27f0);
    arg_20 = &local_10;
    arg_19 = 1;
    arg_18 = &DAT_006679f0;
    arg_17 = 0;
    arg_16 = 0;
    arg_15 = 0;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = -1;
    iVar2 = FUN_004d7d5e(0x37b);
    iVar2 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,2,0x200,0,0,0,0,0,0,iVar2,arg_12,arg_13,arg_14,arg_15,arg_16,
                       arg_17,arg_18,arg_19,arg_20);
    if (iVar2 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      bVar1 = true;
      Mem_AllocOrFree_004d9630
                ((uint *)&DAT_005f6810,(uint *)s_Illegal_target__tetravite_not_re_004f2808);
      if ((((char)(&DAT_006826d3)[local_10 * 0x5b20 + local_c * 0x120] == DAT_00690af0) &&
          (*(int *)(&DAT_006826ec + local_10 * 0x5b20 + local_c * 0x120) == DAT_0068efa0)) &&
         (Mem_AllocOrFree_004d9630
                    ((uint *)&DAT_005f6810,(uint *)s_Illegal_target__only_one_move_pe_004f283c),
         *(int *)(&DAT_006826e4 + local_10 * 0x5b20 + local_c * 0x120) == 0)) {
        FUN_00467e37(DAT_00690af0,DAT_0068efa0);
        FUN_0046e571(local_10,local_c,4);
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                     *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) + 1;
        local_8 = local_8 + 1;
        bVar1 = false;
      }
      if ((bVar1) && (DAT_0066aaf4 != 1)) {
        Mem_AllocOrFree_00450eed(&DAT_005f6810);
        Sleep(2000);
        Mem_AllocOrFree_00450eed(&DAT_004f2868);
      }
    }
  } while ((DAT_00681ea4 != 1) && (local_8 == 0));
  DAT_005f6810 = 0;
  return 0;
}


