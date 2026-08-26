/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 0046af37
 * Size: 2076 bytes
 */
#include "duel.h"


undefined4 Palette_Subsystem_004a9137(int arg_1,int arg_2,undefined4 arg_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  
  iVar3 = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
  iVar4 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
  switch(arg_3) {
  case 0:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Time_Elemental_effect__004f9428,0);
    Pic_Subsystem_0044895f(iVar3,iVar4);
    break;
  case 1:
    iVar2 = FUN_00439892(2);
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_casts_Twiddle_to_004f944c);
    if (iVar2 == 0) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f9468);
    }
    else {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_untap__004f9460);
    }
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,&DAT_005f6810,0);
    if (iVar2 == 0) {
      if (((&DAT_006826cc)[iVar3 * 0x5b20 + iVar4 * 0x120] & 0x10) == 0) {
        *(uint *)(&DAT_006826cc + iVar3 * 0x5b20 + iVar4 * 0x120) =
             *(uint *)(&DAT_006826cc + iVar3 * 0x5b20 + iVar4 * 0x120) | 0x10;
        if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34] & 1)
            != 0) {
          DAT_0068f0f4 = 0xffffffff;
        }
        FUN_0048c50b(iVar3,iVar4,0x81);
      }
    }
    else {
      *(uint *)(&DAT_006826cc + iVar3 * 0x5b20 + iVar4 * 0x120) =
           *(uint *)(&DAT_006826cc + iVar3 * 0x5b20 + iVar4 * 0x120) & 0xffffffef;
    }
    break;
  case 2:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Aladdin_s_Ring_effect__004f9470,0);
    FUN_004612b0(arg_1,arg_2,0x71,4);
    break;
  case 3:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Ancestral_Recall__004f9494,0);
    FUN_00487ce1(iVar3);
    FUN_00487ce1(iVar3);
    FUN_00487ce1(iVar3);
    break;
  case 4:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Pandora_s_Box_effect__004f95c0,0);
    FUN_0041a30b();
    break;
  case 5:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Crumble__004f94b0,0);
    cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34];
    iVar2 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                    [*(int *)(&DAT_006826c4 + iVar3 * 0x5b20 + iVar4 * 0x120) * 0x34
                                    ],0,99);
    (&DAT_00681ea8)[iVar3] = (&DAT_00681ea8)[iVar3] + cVar1 + iVar2;
    FUN_0046e571(iVar3,iVar4,2);
    break;
  case 6:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Bottle_of_Suleiman_eff_004f9560,0);
    iVar3 = Ai_Subsystem_004cc56d
                      (arg_1,arg_1,arg_2,-1,-1,s_Call_the_coin_flip__Heads_Tails_004f9588,1);
    iVar4 = FUN_004491fe(s_Bottle_of_Suleiman_004f95ac);
    if (iVar4 == iVar3) {
      iVar3 = FUN_004d7d5e(0x37a);
      iVar3 = Pic_Subsystem_00451291(arg_1,iVar3);
      if (iVar3 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar3);
        *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + iVar3 * 0x120) =
             *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + iVar3 * 0x120) | 0x10;
      }
    }
    else {
      Mem_AllocOrFree_004afd1c(arg_1,5,arg_1,arg_2);
    }
    break;
  case 7:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Disenchant__004f94c0,0);
    FUN_0046e571(iVar3,iVar4,1);
    break;
  case 8:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Healing_Salve__004f94d4,0);
    (&DAT_00681ea8)[iVar3] = (&DAT_00681ea8)[iVar3] + 3;
    break;
  case 9:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_casts_Fissure__004f94ec,0);
    FUN_0046e571(iVar3,iVar4,1);
    break;
  case 10:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Disrupting_Sceptre_eff_004f95e4,0);
    Palette_Color_0049ae00(iVar3,0,0);
    break;
  case 0xb:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Millstone_effect__004f94fc,0);
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      iVar4 = *(int *)(&DAT_006669f0 + iVar3 * 2000);
      if (iVar4 != -1) {
        FUN_004d7acc(iVar3,0);
        iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
        if (iVar4 != -1) {
          FUN_0046f02d(iVar3,iVar4);
          *(undefined4 *)(&DAT_006826c4 + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
        }
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x18);
      }
    }
    break;
  case 0xc:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_The_Hive_effect__004f951c,0);
    iVar3 = FUN_00439892(2);
    iVar4 = FUN_004d7d5e(0x375);
    iVar4 = Pic_Subsystem_00451291(iVar3,iVar4);
    if (iVar4 != -1) {
      Pic_Subsystem_0042ac1f(iVar3,iVar4);
      *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + iVar3 * 0x5b20) =
           *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + iVar3 * 0x5b20) | 0x10;
    }
    break;
  case 0xd:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Nevinyrral_s_Disk_effe_004f9538,0);
    FUN_00467d65(FUN_0041698a,-1);
    break;
  case 0xe:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_casts_Fog_effect__004f960c,0);
    iVar3 = FUN_004a2b00(arg_1,arg_2,DAT_00666438,-1,-1);
    if (iVar3 != -1) {
      *(undefined4 *)(&DAT_00682704 + arg_1 * 0x5b20 + iVar3 * 0x120) = DAT_004f9330;
    }
    break;
  case 0xf:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_activates_Sinbad_effect__004f9620,0);
    iVar4 = FUN_00487ce1(iVar3);
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_Sinbad_draws____004f963c,0);
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + iVar4 * 0x120 + iVar3 * 0x5b20) * 0x34] & 1) == 0)
    {
      FUN_0046f02d(iVar3,iVar4);
      *(undefined4 *)(&DAT_006826c4 + iVar4 * 0x120 + iVar3 * 0x5b20) = 0xffffffff;
      (&DAT_0068ee78)[iVar3] = (&DAT_0068ee78)[iVar3] + -1;
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x18);
      }
    }
    break;
  default:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,iVar3,iVar4,s_made_an_error__004f964c,0);
  }
  return 0;
}


