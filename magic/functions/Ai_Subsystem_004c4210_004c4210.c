/*
 * Decompiled function: Ai_Subsystem_004c4210
 * Entry Point: 004c4210
 * Size: 2676 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c4210(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int arg_1_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  
  arg_1_00 = 1 - arg_1;
  memset(&DAT_006410f0,0,0x780);
  for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_14 = local_14 + 1) {
    if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_14 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1 * 0x5b20);
      iVar3 = (int)(char)(&g_CardSlot_Toughness)[local_14 * 0x120 + arg_1 * 0x5b20];
      iVar1 = *(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x120 + arg_1 * 0x5b20);
      if ((*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (iVar4 = FUN_0040d949(iVar3,3,1), iVar4 != 0)) {
        *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (iVar4 = FUN_0040d949(iVar3,4,3), iVar4 != 0)) {
        *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        iVar4 = FUN_0040d949(iVar3,4,1);
        *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1 * 0x5b20) | 0xe000000;
      uVar2 = *(undefined4 *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20);
      if (g_ActivePlayerPriority == arg_1) {
        if (((&DAT_006a5f3d)[local_14 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20) | 0x14;
        }
        else {
          *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20) | 4;
        }
      }
      DAT_006b2e18 = FUN_00473179(arg_1,local_14,0x32,0xffffffff);
      DAT_00700eb4 = FUN_00473179(arg_1,local_14,0x33,0xffffffff);
      DAT_006ff1ac = FUN_00473179(arg_1,local_14,0x34,0xffffffff);
      uVar5 = FUN_00473cc5((&DAT_0051aebe)[iVar6 * 0x34]);
      if (((DAT_006ff1ac & 0x200) != 0) && (iVar6 = FUN_0040d949(arg_1,uVar5,1), iVar6 == 0)) {
        DAT_006ff1ac = DAT_006ff1ac & 0xfffffdff;
      }
      if (g_CurrentTurnPhase == arg_1) {
        FUN_00473e69(arg_1,local_14,0x8c);
      }
      *(int *)(&DAT_006410f0 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_006410f0 + local_14 * 0xc + arg_1 * 0x3c0) + DAT_006b2e18;
      *(int *)(&DAT_006410f4 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_006410f4 + local_14 * 0xc + arg_1 * 0x3c0) + DAT_00700eb4;
      *(uint *)(&DAT_006410f8 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(uint *)(&DAT_006410f8 + local_14 * 0xc + arg_1 * 0x3c0) | DAT_006ff1ac;
      *(undefined4 *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1 * 0x5b20) = uVar2;
    }
  }
  DAT_00641870 = 0;
  for (local_14 = 0; local_14 < (int)(&g_PlayerActiveCardCount)[arg_1_00]; local_14 = local_14 + 1)
  {
    if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20) != -1) &&
       (((&g_CardSlot_Flags)[local_14 * 0x120 + arg_1_00 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      iVar3 = (int)(char)(&g_CardSlot_Toughness)[local_14 * 0x120 + arg_1_00 * 0x5b20];
      iVar1 = *(int *)(&g_CardSlot_OriginalCardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if ((*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (iVar4 = FUN_0040d949(iVar3,3,1), iVar4 != 0)) {
        *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (iVar4 = FUN_0040d949(iVar3,4,3), iVar4 != 0)) {
        *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_006410f8 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        iVar4 = FUN_0040d949(iVar3,4,1);
        *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f0 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
        iVar4 = FUN_0040d949(iVar3,5,1);
        *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_006410f4 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + arg_1_00 * 0x5b20) | 0xe000000;
      uVar2 = *(undefined4 *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20);
      *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) | 8;
      DAT_006b2e18 = FUN_00473179(arg_1_00,local_14,0x32,0xffffffff);
      DAT_00700eb4 = FUN_00473179(arg_1_00,local_14,0x33,0xffffffff);
      DAT_006ff1ac = FUN_00473179(arg_1_00,local_14,0x34,0xffffffff);
      uVar5 = FUN_00473cc5((&DAT_0051aebe)[iVar6 * 0x34]);
      if (((DAT_006ff1ac & 0x200) != 0) && (iVar6 = FUN_0040d949(arg_1_00,uVar5,1), iVar6 == 0)) {
        DAT_006ff1ac = DAT_006ff1ac & 0xfffffdff;
      }
      if (g_CurrentTurnPhase == arg_1_00) {
        FUN_00473e69(arg_1_00,local_14,0x8c);
      }
      *(int *)(&DAT_006410f0 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_006410f0 + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_006b2e18;
      *(int *)(&DAT_006410f4 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_006410f4 + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_00700eb4;
      *(uint *)(&DAT_006410f8 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(uint *)(&DAT_006410f8 + local_14 * 0xc + arg_1_00 * 0x3c0) | DAT_006ff1ac;
      *(undefined4 *)(&g_CardSlot_Flags + local_14 * 0x120 + arg_1_00 * 0x5b20) = uVar2;
      iVar6 = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043fd7b) {
        DAT_00641870 = DAT_00641870 | 2;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043fe20) {
        DAT_00641870 = DAT_00641870 | 4;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043fe57) {
        DAT_00641870 = DAT_00641870 | 8;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043fde9) {
        DAT_00641870 = DAT_00641870 | 0x10;
      }
      if (*(code **)(&DAT_0051aec8 + iVar6 * 0x34) == Pic_Subsystem_0043fdb2) {
        DAT_00641870 = DAT_00641870 | 0x20;
      }
    }
  }
  if (DAT_00641870 == 0) {
    DAT_00641874 = 0;
  }
  else {
    DAT_00641874 = FUN_0040d949(arg_1_00,7,0);
  }
  FUN_00472fae();
  return;
}


