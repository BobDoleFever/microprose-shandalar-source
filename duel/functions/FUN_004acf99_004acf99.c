/*
 * Decompiled function: FUN_004acf99
 * Entry Point: 004acf99
 * Size: 1250 bytes
 */
#include "duel.h"


undefined4 FUN_004acf99(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    if (DAT_0068ecd0 == -1) {
      FUN_0043071d(0);
      bVar2 = FUN_004af7bb(param_1,param_2,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar2 & 0x1f));
      uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x1047,0,0,uVar3);
    }
    else {
      bVar2 = FUN_004af7bb(param_1,param_2,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,2,0,0);
      iVar4 = FUN_0041c0ab(DAT_0068ecd0,DAT_0068eccc,0,param_1,2,2,0,0,0,0,0,1 << (bVar2 & 0x1f));
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_0050644c,s_RED_BLAST_00506440);
        bVar2 = FUN_004af7bb(param_1,param_2,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_10);
        uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar2 & 0x1f));
        iVar4 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,0x1047,0,0,uVar3);
        if (iVar4 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
          *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068ecd0;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_8 = 0;
      if (DAT_0068ecd0 == -1) {
        bVar2 = FUN_004af7bb(param_1,param_2,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        uVar3 = FUN_004521e2(param_1,param_2,1 << (bVar2 & 0x1f));
        iVar4 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0x200,0,0,0,uVar3);
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        bVar2 = FUN_004af7bb(param_1,param_2,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,2,0,0);
        iVar4 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0,0,0,0,0,1 << (bVar2 & 0x1f));
        if (iVar4 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_10 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
        local_c = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
        cVar1 = (&DAT_006826dd)[local_10 * 0x5b20 + local_c * 0x120];
        bVar2 = FUN_004af7bb(param_1,param_2,2);
        if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
          FUN_0046e571(local_10,local_c,2);
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


