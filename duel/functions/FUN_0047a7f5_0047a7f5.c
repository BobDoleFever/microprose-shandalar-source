/*
 * Decompiled function: FUN_0047a7f5
 * Entry Point: 0047a7f5
 * Size: 716 bytes
 */
#include "duel.h"


undefined4 FUN_0047a7f5(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (arg_3 == 1) {
    iVar2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
    uVar3 = FUN_0047a090(arg_1,arg_2,1,iVar2);
  }
  else {
    if (arg_3 == 0x71) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x25);
      }
      if (arg_1 == DAT_00676510) {
        cVar1 = FUN_00439892(5);
        (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (cVar1 + 1U & 0x1f));
      }
      else {
        (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_00692c74;
      }
    }
    if (arg_3 == 0x73) {
      iVar2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uVar3 = FUN_0047a090(arg_1,arg_2,0x73,iVar2);
    }
    else if (arg_3 == 0x6d) {
      iVar2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uVar3 = FUN_0047a090(arg_1,arg_2,0x6d,iVar2);
    }
    else {
      if (arg_3 == 0x72) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x25);
        }
        if (arg_1 == DAT_00676510) {
          cVar1 = FUN_00439892(5);
          (&DAT_006826dc)
          [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] =
               (char)(1 << (cVar1 + 1U & 0x1f));
        }
        else {
          (&DAT_006826dc)
          [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = DAT_00692c74;
        }
      }
      if (arg_3 == 0x7f) {
        iVar2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        uVar3 = FUN_0047a090(arg_1,arg_2,0x7f,iVar2);
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}


