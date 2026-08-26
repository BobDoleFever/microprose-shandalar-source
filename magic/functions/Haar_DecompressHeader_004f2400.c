/*
 * Decompiled function: Haar_DecompressHeader
 * Entry Point: 004f2400
 * Size: 431 bytes
 */
#include "magic.h"


undefined4 Haar_DecompressHeader(undefined4 *arg1,int *arg2)

{
  undefined4 *puVar1;
  int arg_3;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *local_20;
  undefined4 *local_18;
  int local_c;
  
  iVar2 = arg2[7] / (int)(2 - (uint)(arg2[10] == 1));
  iVar3 = iVar2 / (int)(2 - (uint)(*arg2 == 0));
  iVar3 = iVar3 * iVar3;
  iVar6 = arg2[9];
  piVar7 = (int *)arg2[0x68] + 1;
  arg_3 = *(int *)arg2[0x68];
  *piVar7 = -0x80000000;
  iVar4 = FUN_0048b950((uint *)(piVar7 + arg_3),piVar7,arg_3);
  puVar8 = (undefined4 *)((int)(piVar7 + arg_3) + iVar4);
  local_c = 0;
  if (0 < arg2[10]) {
    local_20 = arg2 + 0x17;
    local_18 = arg1;
    uVar11 = iVar6 * iVar6;
    do {
      puVar1 = local_18 + iVar2 * iVar2 + 0x20;
      puVar12 = puVar8;
      puVar9 = local_18;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar9 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_0048c070(local_18 + uVar11,puVar8 + uVar11,*local_20);
      puVar9 = (undefined4 *)((int)(puVar8 + uVar11) + *local_20);
      puVar8 = puVar9;
      puVar12 = puVar1;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      FUN_0048c070(puVar1 + uVar11,puVar10,local_20[4]);
      puVar9 = (undefined4 *)((int)puVar10 + local_20[4]);
      puVar8 = puVar9;
      puVar12 = puVar1 + iVar3 + 0x20;
      for (uVar5 = uVar11 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar10 = puVar9 + uVar11;
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      FUN_0048c070(puVar1 + iVar3 + 0x20 + uVar11,puVar10,local_20[8]);
      piVar7 = local_20 + 8;
      local_20 = local_20 + 1;
      puVar8 = (undefined4 *)((int)puVar10 + *piVar7);
      local_18 = local_18 + iVar2 * iVar2 + iVar3 * 2 + 0x40;
      local_c = local_c + 1;
    } while (local_c < arg2[10]);
  }
  return 0;
}


