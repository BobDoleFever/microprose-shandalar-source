/*
 * Decompiled function: FUN_00513200
 * Entry Point: 00513200
 * Size: 664 bytes
 */
#include "magic.h"


void FUN_00513200(int arg_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  
  iVar7 = DAT_006261e8;
  uVar6 = (undefined1)arg_1;
  if (DAT_006261e8 == -1) {
    iVar7 = 0;
    DAT_006261e8 = 0;
    FUN_005135e0(8,0xb);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + iVar3) = iVar7;
      *(int *)(DAT_006261e4 + -0xc + iVar3) = iVar7;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(DAT_006261e4 + -8 + iVar3) = 0xffffffff;
    } while (iVar3 < 0xc00);
    if (iVar7 < 0xffb) {
      iVar7 = iVar7 * 0xc;
      do {
        iVar7 = iVar7 + 0xc;
        *(undefined4 *)(DAT_006261e4 + -0xc + iVar7) = 0xffffffff;
      } while (iVar7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
    DAT_006261d8 = 1;
    DAT_006261dc = arg_1;
    g_OverworldWorldState = uVar6;
    return;
  }
  iVar2 = DAT_006261d8 + 1;
  puVar1 = &g_OverworldWorldState + DAT_006261d8;
  DAT_006261d8 = iVar2;
  *puVar1 = uVar6;
  iVar3 = DAT_006261d8;
  if (iVar7 < iVar2) {
    DAT_006261e8 = iVar2;
  }
  uVar4 = 0;
  (&g_OverworldWorldState)[DAT_006261d8] = 0;
  if (0 < iVar3) {
    iVar7 = 0;
    do {
      uVar4 = uVar4 + (int)*(short *)(&g_OverworldWorldState + iVar7);
      iVar7 = iVar7 + 2;
    } while (iVar7 < DAT_006261d8);
  }
  uVar4 = uVar4 & 0x7fff;
  if (uVar4 == 0) {
    uVar4 = DAT_006261d8 * 0x25 & 0x7fff;
  }
  uVar5 = uVar4 % 0xffb;
  iVar7 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uVar5 * 0xc);
    if (*DAT_00702924 == -1) break;
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == DAT_006261dc)) goto LAB_0051338a;
    if (iVar7 == -1) {
      iVar7 = 0xff9 - uVar4 % 0xff9;
    }
    if (iVar7 == 0) {
      iVar7 = DAT_006261d8 * 0x89;
    }
    uVar5 = (int)(uVar5 + iVar7) % 0xffb;
  }
  uVar5 = 0xffffffff;
LAB_0051338a:
  if (uVar5 != 0xffffffff) {
    DAT_006261dc = uVar5;
    return;
  }
  *DAT_00702924 = arg_1;
  DAT_00702924[1] = DAT_006261dc;
  DAT_00702924[2] = DAT_006261ec;
  DAT_006261ec = DAT_006261ec + 1;
  FUN_005135e0(DAT_006261bc,*(uint *)(DAT_006261e4 + 8 + DAT_006261dc * 0xc));
  DAT_006261dc = arg_1;
  DAT_006261d8 = 1;
  g_OverworldWorldState = uVar6;
  if ((1 << ((byte)DAT_006261bc & 0x1f) < DAT_006261ec) &&
     (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
    iVar3 = 0;
    iVar7 = 0;
    do {
      iVar3 = iVar3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + iVar3) = iVar7;
      *(int *)(DAT_006261e4 + -0xc + iVar3) = iVar7;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(DAT_006261e4 + -8 + iVar3) = 0xffffffff;
    } while (iVar3 < 0xc00);
    if (iVar7 < 0xffb) {
      iVar7 = iVar7 * 0xc;
      do {
        iVar7 = iVar7 + 0xc;
        *(undefined4 *)(DAT_006261e4 + -0xc + iVar7) = 0xffffffff;
      } while (iVar7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
  }
  return;
}


