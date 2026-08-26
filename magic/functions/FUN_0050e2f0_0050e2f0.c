/*
 * Decompiled function: FUN_0050e2f0
 * Entry Point: 0050e2f0
 * Size: 1021 bytes
 */
#include "magic.h"


void FUN_0050e2f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  undefined8 *arg_1;
  uint *puVar10;
  int iVar11;
  int iStack00000004;
  int *in_stack_00002018;
  int in_stack_0000201c;
  int in_stack_00002020;
  int in_stack_00002024;
  int in_stack_00002028;
  int *in_stack_0000202c;
  int in_stack_00002030;
  int in_stack_00002034;
  uint in_stack_00002038;
  int in_stack_0000203c;
  int in_stack_00002040;
  int in_stack_00002044;
  
  Mem_AllocOrFree_00513bd0();
  if ((DAT_00624160 == 0) || (in_stack_00002040 == -100000)) {
    DAT_00622934 = (in_stack_00002024 << 0x10) / (int)in_stack_00002038;
    uVar4 = 0;
    DAT_00620928 = (in_stack_00002028 << 0x10) / in_stack_0000203c;
    DAT_0062293c = 0x800;
    DAT_00620124 = 0x800;
    puVar8 = &DAT_00620930;
    do {
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
      uVar4 = uVar4 + DAT_00622934;
    } while (puVar8 < &DAT_00622930);
    uVar4 = 0;
    puVar8 = &DAT_0061e120;
    do {
      *puVar8 = uVar4;
      puVar8 = puVar8 + 1;
      uVar4 = uVar4 + DAT_00620928;
    } while (puVar8 < &DAT_00620120);
    DAT_00624160 = 1;
  }
  else {
    if (in_stack_00002040 < 0) {
      iVar9 = 0;
      uVar4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uVar4 = uVar4 - DAT_00622934;
      } while ((int)uVar4 >> 0x10 != in_stack_00002040);
      memmove(&DAT_00620930 + -iVar9,&DAT_00620930,(DAT_0062293c + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_00620930 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00622934;
          puVar8 = puVar10;
        } while ((uint *)((int)&DAT_0062092c + 3U) < puVar10);
      }
    }
    else if (0 < in_stack_00002040) {
      iVar9 = 0;
      uVar4 = DAT_00620930 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uVar4 = uVar4 + DAT_00622934;
      } while ((int)uVar4 >> 0x10 != in_stack_00002040);
      uVar6 = DAT_0062293c - iVar9;
      puVar8 = &DAT_00620930 + iVar9;
      puVar10 = &DAT_00620930;
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint *)((int)puVar8 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      if ((int)uVar6 < DAT_0062293c) {
        iVar9 = DAT_0062293c - uVar6;
        puVar8 = &DAT_00620930 + uVar6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00622934;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    if (in_stack_00002044 < 0) {
      iVar9 = 0;
      uVar4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + -1;
        uVar4 = uVar4 - DAT_00620928;
      } while ((int)uVar4 >> 0x10 != in_stack_00002044);
      memmove(&DAT_0061e120 + -iVar9,&DAT_0061e120,(DAT_00620124 + iVar9) * 4);
      if (-1 < -1 - iVar9) {
        puVar8 = &DAT_0061e120 + (-1 - iVar9);
        do {
          puVar10 = puVar8 + -1;
          *puVar8 = puVar8[1] - DAT_00620928;
          puVar8 = puVar10;
        } while ((uint *)((int)&DAT_0061e11c + 3U) < puVar10);
      }
    }
    else if (0 < in_stack_00002044) {
      iVar9 = 0;
      uVar4 = DAT_0061e120 & 0xffff;
      do {
        iVar9 = iVar9 + 1;
        uVar4 = uVar4 + DAT_00620928;
      } while ((int)uVar4 >> 0x10 != in_stack_00002044);
      uVar6 = DAT_00620124 - iVar9;
      puVar8 = &DAT_0061e120 + iVar9;
      puVar10 = &DAT_0061e120;
      for (uVar4 = uVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(char *)puVar10 = (char)*puVar8;
        puVar8 = (uint *)((int)puVar8 + 1);
        puVar10 = (uint *)((int)puVar10 + 1);
      }
      if ((int)uVar6 < DAT_00620124) {
        iVar9 = DAT_00620124 - uVar6;
        puVar8 = &DAT_0061e120 + uVar6;
        do {
          iVar9 = iVar9 + -1;
          *puVar8 = puVar8[-1] + DAT_00620928;
          puVar8 = puVar8 + 1;
        } while (iVar9 != 0);
      }
    }
    DAT_0062092c = DAT_0062092c + in_stack_00002040;
    DAT_00622940 = DAT_00622940 + in_stack_00002044;
  }
  if (0 < DAT_0062293c) {
    iVar9 = DAT_0062293c;
    iVar5 = 0;
    do {
      iVar9 = iVar9 + -1;
      *(int *)(&stack0x00000014 + iVar5) =
           (*(int *)((int)&DAT_00620930 + iVar5) >> 0x10) - DAT_0062092c;
      iVar5 = iVar5 + 4;
    } while (iVar9 != 0);
  }
  if ((*in_stack_00002018 == 0) || (*in_stack_0000202c == 0)) {
    iVar9 = 0;
  }
  else {
    iVar9 = 1;
  }
  AssertOrLog(iVar9,0x5325e0,0x435,s_MScaledRectCopy_only_works_on_me_00532658);
  iVar9 = (&DAT_0070a850)[*in_stack_00002018];
  iVar5 = (&DAT_0070a850)[*in_stack_0000202c];
  iVar1 = *(int *)(iVar9 + 0x2c);
  iVar2 = *(int *)(iVar9 + 0x20);
  iVar3 = *(int *)(iVar5 + 0x20);
  iVar9 = *(int *)(iVar9 + 0x18);
  arg_1 = (undefined8 *)
          (in_stack_00002030 +
          (*(int *)(iVar5 + 0x2c) + iVar3) * in_stack_00002034 + *(int *)(iVar5 + 0x18));
  if (0 < in_stack_0000203c) {
    puVar8 = &DAT_0061e120;
    iVar5 = -1;
    iStack00000004 = in_stack_0000203c;
    do {
      iVar11 = ((int)*puVar8 >> 0x10) - DAT_00622940;
      if (iVar5 == iVar11) {
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,in_stack_00002038);
        iVar11 = iVar5;
      }
      else {
        iVar5 = 0;
        if (0 < (int)in_stack_00002038) {
          do {
            iVar7 = iVar5 + 1;
            (&DAT_00623158)[iVar5] =
                 *(undefined1 *)
                  (*(int *)(&stack0x00000014 + iVar5 * 4) +
                  iVar2 * iVar11 + in_stack_0000201c + (iVar1 + iVar2) * in_stack_00002020 + iVar9);
            iVar5 = iVar7;
          } while (iVar7 < (int)in_stack_00002038);
        }
        Mem_AllocOrFree_004f1e20(arg_1,(undefined8 *)&DAT_00623158,in_stack_00002038);
      }
      puVar8 = puVar8 + 1;
      arg_1 = (undefined8 *)((int)arg_1 + iVar3);
      iStack00000004 = iStack00000004 + -1;
      iVar5 = iVar11;
    } while (iStack00000004 != 0);
  }
  return;
}


