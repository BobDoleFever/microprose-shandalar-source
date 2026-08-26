/*
 * Decompiled function: Ai_ChooseBlockers
 * Entry Point: 00489247
 * Size: 877 bytes
 */
#include "duel.h"


undefined4 Ai_ChooseBlockers(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  FUN_0048c367((&DAT_004ff596)[iVar1 * 0x34]);
  if (iVar1 == -1) {
    FUN_0048e251();
    uVar3 = 0;
  }
  else {
    if (((&DAT_004ff594)[iVar1 * 0x34] != '\x01') &&
       (((&DAT_004ff594)[iVar1 * 0x34] != ' ' || (((&DAT_004ff5a9)[iVar1 * 0x34] & 0x10) == 0)))) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Cast_004fafd4);
      FUN_0044a5a4(arg1,arg2);
      FUN_0048e32b(-2,DAT_0068f2c4,&DAT_005f6810,0x6c);
    }
    *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffffdf;
    *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 2;
    DAT_00681eb0 = DAT_00681eb0 & 0xffffffdf;
    if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == iVar1) {
      *(uint *)(&DAT_0066aad0 + arg1 * 4) =
           *(uint *)(&DAT_0066aad0 + arg1 * 4) | (uint)(byte)(&DAT_004ff594)[iVar1 * 0x34];
      if (DAT_0066aaf4 != 1) {
        if (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0) {
          FUN_0048d00c(0x11);
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 0x40) != 0) {
          FUN_0048d00c(0);
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 4) != 0) {
          FUN_0048d00c(3);
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 0x10) != 0) {
          FUN_0048d00c(6);
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 0x20) != 0) {
          FUN_0048d00c(7);
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 8) != 0) {
          FUN_0048d00c(0x10);
        }
      }
      FUN_0048dd43();
      uVar2 = DAT_0068edd0;
      uVar3 = DAT_00666754;
      DAT_00666754 = arg1;
      DAT_0068edd0 = arg2;
      FUN_0048e8a8(DAT_00666458,0xd3,s_Casting_004fafdc,0);
      DAT_00666754 = uVar3;
      DAT_0068edd0 = uVar2;
      Pic_Subsystem_004475a4(arg1);
      DAT_0066641c = 0xffffffff;
      DAT_0066644c = 0xffffffff;
      if (DAT_00681ea4 == 1) {
        if (DAT_0066aaf4 != 1) {
          Mem_AllocOrFree_00450eed(s_fizzle_004fafe4);
          Sleep(2000);
          Mem_AllocOrFree_00450eed(&DAT_004fafec);
        }
        DAT_00690c44 = 1;
        DAT_00681ea4 = 0;
        uVar3 = 0;
      }
      else {
        DAT_00681ea4 = 0;
        FUN_00451482(0,0xff);
        uVar3 = 1;
      }
    }
    else {
      FUN_0048e251();
      uVar3 = 0;
    }
  }
  return uVar3;
}


