/*
 * Decompiled function: FUN_00488598
 * Entry Point: 00488598
 * Size: 202 bytes
 */
#include "duel.h"


undefined4 FUN_00488598(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  bVar3 = DAT_00666744 == 0xd3;
  if (bVar3) {
    DAT_004fab48 = 1;
  }
  iVar1 = FUN_00488662(arg1,arg2,0);
  if (((iVar1 == 0) || (iVar1 = FUN_00488662(arg1,arg2,1), iVar1 == 0)) ||
     (iVar1 = Ai_ChooseBlockers(arg1,arg2), iVar1 == 0)) {
    if (bVar3) {
      DAT_004fab48 = 0;
    }
    uVar2 = 0;
  }
  else {
    if (bVar3) {
      DAT_004fab48 = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}


