/*
 * Decompiled function: Prompts_Load_00463fcd
 * Entry Point: 00463fcd
 * Size: 856 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_00463fcd(int spell_id,int target_id,int flags)

{
  int iVar1;
  
  if ((((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
     (*(int *)(&DAT_0068ee80 + spell_id * 4) < 2)) {
    DAT_0068f2d4 = DAT_0068f2d4 + -0xa8;
  }
  if (flags == 0x87) {
    iVar1 = FUN_00464325(spell_id,target_id);
    if (iVar1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
  }
  if ((((flags == 0x85) && (target_id == DAT_00690c48)) &&
      ((spell_id == DAT_0068ecb0 &&
       ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0 &&
        (spell_id == DAT_00666458)))))) && (DAT_00681eb4 == spell_id)) {
    *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
    iVar1 = FUN_00464325(spell_id,target_id);
    if (iVar1 == 0) {
      DAT_0068f2c0 = DAT_0068f2c0 + 1;
    }
  }
  if (((flags == 4) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
    iVar1 = FUN_00464325(spell_id,target_id);
    if (iVar1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x100000;
      FUN_00451482(0,0x20);
      FUN_00434660(s_prompts_txt_004f8d40,s_LORD_OF_THE_PIT_004f8d30);
      iVar1 = FUN_00468383(spell_id);
      *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xffefffff;
      FUN_0046e571(spell_id,iVar1,3);
    }
  }
  if (flags == 0x86) {
    FUN_0045102d(spell_id,spell_id,target_id,-1,-1,s_Lord_of_the_Pit_deals_7_damage__004f8d4c,0);
    Mem_AllocOrFree_004afd1c(spell_id,7,DAT_00690af0,DAT_0068efa0);
  }
  if (flags == 199) {
    iVar1 = FUN_00464325(spell_id,target_id);
    if (iVar1 == 0) {
      Mem_AllocOrFree_004afd1c(spell_id,7,DAT_00690af0,DAT_0068efa0);
    }
  }
  if (((flags == 0x22) || (flags == 199)) &&
     ((target_id == DAT_00690c48 && (spell_id == DAT_0068ecb0)))) {
    *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
  }
  if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + -0x30;
  }
  if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + 0x30;
  }
  return 0;
}


