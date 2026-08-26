/*
 * Decompiled function: ColorOctree_BuildClusters
 * Entry Point: 00494120
 * Size: 224 bytes
 */
#include "magic.h"


int ColorOctree_BuildClusters(int *arg_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  size_t local_404;
  undefined4 local_400 [256];
  
  iVar1 = DAT_0054b32c + 1;
  iVar4 = 0;
  local_404 = 0;
  if (DAT_0052a1a0 < iVar1) {
    DAT_0052a1a0 = iVar1;
  }
  if (*arg_1 != 0) {
    return 1;
  }
  piVar5 = arg_1 + 2;
  iVar6 = 8;
  DAT_0054b32c = iVar1;
  do {
    if ((int *)*piVar5 != (int *)0x0) {
      iVar1 = ColorOctree_BuildClusters((int *)*piVar5);
      iVar4 = iVar4 + iVar1;
      local_404 = local_404 + 1;
    }
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (local_404 != 0) {
    local_404 = 0;
    ColorOctree_CollectLeaves(arg_1,(int)local_400,(int *)&local_404);
    pvVar2 = malloc(local_404);
    arg_1[10] = (int)pvVar2;
    arg_1[0xb] = local_404;
    puVar7 = local_400;
    puVar8 = (undefined4 *)arg_1[10];
    for (uVar3 = local_404 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar3 = local_404 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
  }
  DAT_0054b32c = DAT_0054b32c + -1;
  return iVar4;
}


