/*
 * Decompiled function: FUN_004178f0
 * Entry Point: 004178f0
 * Size: 1108 bytes
 */
#include "duel.h"


undefined4 FUN_004178f0(int x,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (((width == 0x6c) && (y == DAT_00690c48)) && (x == DAT_0068ecb0)) {
    FUN_00468097(x,y,height);
  }
  if ((((DAT_0068f230 == 0xcc) && (iVar2 = FUN_004680fc(x,y), iVar2 != 0)) &&
      ((y == DAT_00690c48 && ((x == DAT_0068ecb0 && (DAT_00681ec4 == x)))))) &&
     ((((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 4) != 0 ||
      (((&DAT_006826de)[y * 0x120 + x * 0x5b20] != -1 && (x != DAT_00666458)))))) {
    if (width == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (width == 0x7e) {
      FUN_00467eef(x,y);
    }
  }
  if (((width == 0x32) && (y == DAT_00690c48)) && (x == DAT_0068ecb0)) {
    iVar2 = FUN_004680fc(x,y);
    DAT_0066642c = DAT_0066642c + iVar2;
  }
  uVar1 = DAT_0068ed04;
  if (((width == 0x73) && (DAT_0068f2c4 == 4)) &&
     ((x == DAT_00666458 &&
      ((((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0 && (DAT_00681eb4 == x)))))) {
    iVar2 = FUN_004680fc(x,y);
    if ((iVar2 < height) && (iVar2 = FUN_0049b309(x,7,1), iVar2 != 0)) {
      return 1;
    }
  }
  else if (width == 0x90) {
    iVar2 = FUN_0049b309(x,7,1);
    iVar5 = 0;
    iVar3 = FUN_004680fc(x,y);
    DAT_00666410 = FUN_0049aa14(height - iVar3,iVar5,iVar2);
  }
  else {
    if (((width == 0x6d) && (y == DAT_00690c48)) && (x == DAT_0068ecb0)) {
      iVar2 = FUN_004680fc(x,y);
      DAT_0068ed04 = height - iVar2;
      if (x == DAT_00676510) {
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,-1);
        *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = uVar4;
      }
      else {
        iVar2 = FUN_0049b309(x,7,1);
        iVar5 = 0;
        iVar3 = FUN_004680fc(x,y);
        iVar2 = FUN_0049aa14(height - iVar3,iVar5,iVar2);
        uVar4 = Ai_CalcManaRequirement_004ba890(x,0,iVar2);
        *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = uVar4;
      }
      DAT_0068ed04 = uVar1;
      if (DAT_00681ea4 == 1) {
        *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = 0;
      }
      else {
        *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    if ((width == 0x72) &&
       (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006827b4 + y * 0x120 + x * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + y * 0x120 + x * 0x5b20) * 0x5b20) != -1)) {
      iVar5 = 0;
      iVar2 = *(int *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20);
      iVar3 = FUN_004680fc(DAT_00690af0,DAT_0068efa0);
      iVar2 = FUN_0049aa14(iVar2 + iVar3,iVar5,height);
      FUN_00468097(DAT_00690af0,DAT_0068efa0,iVar2);
    }
  }
  return 0;
}


