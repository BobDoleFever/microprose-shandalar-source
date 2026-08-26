/*
 * Decompiled function: Palette_DitherScanline
 * Entry Point: 004950b0
 * Size: 864 bytes
 */
#include "magic.h"


undefined4 Palette_DitherScanline(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  uint local_58;
  int local_4c;
  int local_48;
  int local_40;
  undefined *local_3c;
  int local_38;
  int local_18 [6];
  
  local_4c = 1;
  local_3c = &DAT_0052a238 + arg_1 * 0xc0;
  if (DAT_0054b324 == 0) {
    iVar7 = -0x200;
    do {
      if (iVar7 < 0) {
LAB_0049510c:
        PTR_DAT_0052afb8[iVar7] = 0;
      }
      else if (iVar7 < 0x100) {
        PTR_DAT_0052afb8[iVar7] = (char)iVar7;
      }
      else {
        if (iVar7 < 0) goto LAB_0049510c;
        PTR_DAT_0052afb8[iVar7] = 0xff;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x200);
    DAT_0054b324 = 1;
  }
  if (arg_1 != DAT_0052afc0) {
    puVar16 = &DAT_00675ed0;
    do {
      if ((void *)*puVar16 != (void *)0x0) {
        free((void *)*puVar16);
        *puVar16 = 0;
      }
      puVar16 = puVar16 + 1;
    } while (puVar16 < &DAT_00675fd4);
    Palette_AllocErrorDiffusionTable(arg_1,0x675ed0);
    DAT_0052afc0 = arg_1;
  }
  puVar16 = &DAT_0064b8c0;
  piVar10 = local_18 + 1;
  do {
    piVar11 = piVar10 + 1;
    puVar17 = puVar16;
    for (iVar7 = 0x2018; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar17 = 0;
      puVar17 = puVar17 + 1;
    }
    puVar17 = puVar16 + 10;
    puVar16 = puVar16 + 0x2018;
    *piVar10 = (int)puVar17;
    piVar10 = piVar11;
  } while (piVar11 < &stack0x00000000);
  iVar7 = *(int *)(&DAT_0052a1c0 + arg_1 * 4);
  if (0 < arg_4) {
    local_38 = arg_4;
    local_18[0] = arg_6 + arg_5 * 3;
    do {
      if (local_4c < 1) {
        local_48 = -1;
        local_40 = -3;
        iVar8 = arg_5 + -1;
      }
      else {
        iVar8 = 0;
        local_40 = 3;
        local_48 = arg_5;
      }
      iVar13 = iVar8 * 3;
      for (; local_48 != iVar8; iVar8 = iVar8 + local_4c) {
        uVar5 = *(uint *)(iVar13 + arg_3);
        *(uint *)(iVar13 + arg_3) = uVar5 & 0xff000000;
        psVar1 = (short *)(local_18[1] + iVar8 * 8);
        bVar2 = PTR_DAT_0052afb8[(int)(*psVar1 >> 8) + (uVar5 & 0xff)];
        bVar3 = PTR_DAT_0052afb8[(int)(psVar1[1] >> 8) + (uVar5 >> 8 & 0xff)];
        bVar4 = PTR_DAT_0052afb8[(int)(psVar1[2] >> 8) + ((uVar5 & 0xff0000) >> 0x10)];
        uVar14 = (uint)bVar3 << 8 | (uint)bVar4 << 0x10 | (uint)bVar2;
        if (uVar14 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = 0xffffff;
          if (uVar14 != 0xffffff) {
            uVar9 = uVar14 & 0xf8f8f8;
          }
        }
        local_58 = uVar9 >> 8 & 0xff;
        *(uint *)(iVar13 + arg_3) = uVar5 & 0xff000000 | uVar9;
        iVar12 = bVar3 - local_58;
        puVar15 = local_3c;
        local_58 = iVar7;
        if (0 < iVar7) {
          do {
            iVar6 = *(int *)(puVar15 + 0xc);
            psVar1 = (short *)(local_18[*(int *)(puVar15 + 8) + 1] +
                              (*(int *)(puVar15 + 4) + iVar8) * 8);
            *psVar1 = *psVar1 + (short)*(undefined4 *)(iVar6 + ((uint)bVar2 - (uVar9 & 0xff)) * 4);
            psVar1[1] = psVar1[1] + (short)*(undefined4 *)(iVar6 + iVar12 * 4);
            psVar1[2] = psVar1[2] +
                        (short)*(undefined4 *)(iVar6 + ((uint)bVar4 - (uVar9 >> 0x10)) * 4);
            local_58 = local_58 + -1;
            puVar15 = puVar15 + 0x10;
          } while (local_58 != 0);
        }
        iVar13 = iVar13 + local_40;
      }
      Palette_RotateDitherBuffers(local_18 + 1,*(int *)(&DAT_0052a1e8 + arg_1 * 4));
      puVar16 = (undefined4 *)(local_18[*(int *)(&DAT_0052a1e8 + arg_1 * 4)] + -0x28);
      for (iVar8 = (arg_5 + 10U & 0x1fffffff) * 2; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar16 = 0;
        puVar16 = puVar16 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar16 = 0;
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      if (arg_2 != 0) {
        local_4c = -local_4c;
        local_3c = &DAT_0052a238 + ((uint)(local_4c == -1) * 9 + arg_1) * 0xc0;
      }
      arg_3 = arg_3 + local_18[0];
      local_38 = local_38 + -1;
    } while (local_38 != 0);
  }
  return 1;
}


