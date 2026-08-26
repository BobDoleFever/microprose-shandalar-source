/*
 * Decompiled function: Palette_DitherBitmapRGB
 * Entry Point: 00494820
 * Size: 984 bytes
 */
#include "magic.h"


uint * Palette_DitherBitmapRGB(uint *arg_1,int arg_2,uint *arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined8 *arg_1_00;
  uint local_5c;
  int local_58;
  int local_54;
  uint local_50;
  undefined *local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_18 [6];
  
  local_54 = 1;
  local_4c = &DAT_0052a238 + (int)arg_1 * 0xc0;
  if (arg_1 == (uint *)0x0) {
    DAT_0052afbc = arg_1;
    return (uint *)0x0;
  }
  if (arg_1 == (uint *)0x1) {
    DAT_0052afbc = arg_1;
    puVar4 = (uint *)Palette_RemapBitmapRGB(arg_3,arg_4,arg_5,arg_6);
    return puVar4;
  }
  if (DAT_0054b328 == 0) {
    iVar6 = -0x200;
    do {
      if (iVar6 < 0) {
LAB_004948ce:
        PTR_DAT_0052afb8[iVar6] = 0;
      }
      else if (iVar6 < 0x100) {
        PTR_DAT_0052afb8[iVar6] = (char)iVar6;
      }
      else {
        if (iVar6 < 0) goto LAB_004948ce;
        PTR_DAT_0052afb8[iVar6] = 0xff;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x200);
    DAT_0054b328 = 1;
  }
  if (arg_1 != DAT_0052afbc) {
    puVar13 = &DAT_00675ed0;
    do {
      if ((void *)*puVar13 != (void *)0x0) {
        free((void *)*puVar13);
        *puVar13 = 0;
      }
      puVar13 = puVar13 + 1;
    } while (puVar13 < &DAT_00675fd4);
    Palette_AllocErrorDiffusionTable((int)arg_1,0x675ed0);
    DAT_0052afbc = arg_1;
  }
  piVar10 = local_18 + 1;
  arg_1_00 = (undefined8 *)&DAT_0064b8c0;
  do {
    piVar11 = piVar10 + 1;
    Haar_Transform2D_Inverse(arg_1_00,0,0x8060);
    *piVar10 = (int)(arg_1_00 + 5);
    piVar10 = piVar11;
    arg_1_00 = arg_1_00 + 0x100c;
  } while (piVar11 < &stack0x00000000);
  iVar6 = *(int *)(&DAT_0052a1c0 + (int)arg_1 * 4);
  puVar4 = arg_1;
  if (0 < arg_4) {
    local_3c = arg_4;
    local_18[0] = arg_6 + arg_5 * 3;
    do {
      if (local_54 < 1) {
        local_48 = -1;
        local_40 = -3;
        iVar12 = arg_5 + -1;
      }
      else {
        iVar12 = 0;
        local_40 = 3;
        local_48 = arg_5;
      }
      local_58 = iVar12 * 3;
      if (local_48 != iVar12) {
        do {
          uVar2 = *(uint *)((int)arg_3 + local_58);
          uVar7 = uVar2 & 0xffffff;
          *(uint *)((int)arg_3 + local_58) = uVar2 & 0xff000000;
          psVar1 = (short *)(local_18[1] + iVar12 * 8);
          uVar9 = 0;
          if (uVar7 == 0) {
            uVar5 = 0;
            local_50 = 0;
            local_5c = 0;
          }
          else {
            uVar5 = 0xffffff;
            if (uVar7 == 0xffffff) {
              uVar9 = 0xff;
              local_50 = 0xff;
              local_5c = 0xff;
            }
            else {
              local_5c = (uint)(byte)PTR_DAT_0052afb8[(int)(*psVar1 >> 8) + (uVar2 & 0xff)];
              local_50 = (uint)(byte)PTR_DAT_0052afb8[(int)(psVar1[1] >> 8) + (uVar7 >> 8 & 0xff)];
              uVar9 = (uint)(byte)PTR_DAT_0052afb8
                                  [(int)(psVar1[2] >> 8) + ((uVar2 & 0xff0000) >> 0x10)];
              uVar5 = Color_FindNearestRGB(local_50 << 8 | uVar9 << 0x10 | local_5c);
            }
          }
          *(uint *)((int)arg_3 + local_58) = *(uint *)((int)arg_3 + local_58) | uVar5;
          for (puVar8 = local_4c; puVar8 < local_4c + iVar6 * 0x10; puVar8 = puVar8 + 0x10) {
            iVar3 = *(int *)(puVar8 + 0xc);
            psVar1 = (short *)(local_18[*(int *)(puVar8 + 8) + 1] +
                              (*(int *)(puVar8 + 4) + iVar12) * 8);
            *psVar1 = *psVar1 + (short)*(undefined4 *)(iVar3 + (local_5c - (uVar5 & 0xff)) * 4);
            psVar1[1] = psVar1[1] +
                        (short)*(undefined4 *)(iVar3 + (local_50 - (uVar5 >> 8 & 0xff)) * 4);
            psVar1[2] = psVar1[2] + (short)*(undefined4 *)(iVar3 + (uVar9 - (uVar5 >> 0x10)) * 4);
          }
          iVar12 = iVar12 + local_54;
          local_58 = local_58 + local_40;
        } while (iVar12 != local_48);
      }
      Palette_RotateDitherBuffers(local_18 + 1,*(int *)(&DAT_0052a1e8 + (int)arg_1 * 4));
      puVar13 = (undefined4 *)(local_18[*(int *)(&DAT_0052a1e8 + (int)arg_1 * 4)] + -0x28);
      for (iVar12 = (arg_5 + 10U & 0x1fffffff) * 2; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined1 *)puVar13 = 0;
        puVar13 = (undefined4 *)((int)puVar13 + 1);
      }
      if (arg_2 != 0) {
        local_54 = -local_54;
        local_4c = &DAT_0052a238 + ((uint)(local_54 == -1) * 9 + (int)arg_1) * 0xc0;
      }
      puVar4 = (uint *)((int)arg_3 + local_18[0]);
      local_3c = local_3c + -1;
      arg_3 = puVar4;
    } while (local_3c != 0);
  }
  return puVar4;
}


