/*
 * Decompiled function: FUN_005126b0
 * Entry Point: 005126b0
 * Size: 132 bytes
 */
#include "magic.h"


undefined4 FUN_005126b0(byte *arg_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  iVar6 = (int)DAT_00703982;
  do {
    if (iVar6 < 1) {
      return 1;
    }
    uVar2 = fgetc(DAT_00703930);
    bVar1 = (byte)uVar2;
    if ((bVar1 & 0xc0) == 0xc0) {
      uVar3 = uVar2 & 0x3f;
      iVar4 = fgetc(DAT_00703930);
      bVar1 = (byte)iVar4;
      if (uVar3 < 2) goto LAB_00512722;
      if (uVar3 != 0) {
        pbVar7 = arg_1;
        for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(uint *)pbVar7 = CONCAT22(CONCAT11(bVar1,bVar1),CONCAT11(bVar1,bVar1));
          pbVar7 = pbVar7 + 4;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pbVar7 = bVar1;
          pbVar7 = pbVar7 + 1;
        }
        arg_1 = arg_1 + uVar3;
      }
      iVar4 = -uVar3;
    }
    else {
LAB_00512722:
      *arg_1 = bVar1;
      arg_1 = arg_1 + 1;
      iVar4 = -1;
    }
    iVar6 = iVar6 + iVar4;
  } while( true );
}


