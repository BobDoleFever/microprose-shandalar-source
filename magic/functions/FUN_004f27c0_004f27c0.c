/*
 * Decompiled function: FUN_004f27c0
 * Entry Point: 004f27c0
 * Size: 1153 bytes
 */
#include "magic.h"


uint * FUN_004f27c0(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  uint *puVar14;
  uint *puVar15;
  int iStack00000004;
  uint *puStack00000008;
  uint *puStack00000010;
  int iStack00000014;
  int iStack0000001c;
  int *piStack00000020;
  uint *in_stack_00005028;
  int *in_stack_0000502c;
  int in_stack_00005030;
  int in_stack_00005034;
  
  Mem_AllocOrFree_00513bd0();
  if (in_stack_0000502c != (int *)0x0) {
    iVar2 = in_stack_0000502c[7];
    iVar9 = in_stack_0000502c[8];
    if (in_stack_0000502c[0x6a] == 0) {
      puStack00000008 =
           (uint *)Haar_DecompressWaveletImage(in_stack_0000502c,(undefined8 *)&DAT_005663e0);
    }
    else {
      puStack00000008 = (uint *)in_stack_0000502c[0x6b];
    }
    uVar7 = in_stack_00005030 * 3;
    iVar5 = in_stack_0000502c[7];
    iVar8 = (DAT_00530068 - (int)uVar7 % DAT_00530068) % DAT_00530068;
    if (in_stack_00005028 == (uint *)0x0) {
      in_stack_00005028 = (uint *)&DAT_005e0be0;
    }
    iVar4 = 0;
    iVar1 = in_stack_00005030;
    piVar10 = (int *)&stack0x00000024;
    if (0 < in_stack_00005030) {
      do {
        iVar12 = iVar4 >> 8;
        iVar4 = iVar4 + (iVar2 << 0x10) / in_stack_00005030;
        iVar1 = iVar1 + -1;
        *piVar10 = iVar12;
        piVar10 = piVar10 + 1;
      } while (iVar1 != 0);
    }
    iVar2 = in_stack_0000502c[8];
    puStack00000010 = in_stack_00005028;
    if (iVar2 < in_stack_00005034) {
      puStack00000010 =
           (uint *)((int)in_stack_00005028 + (uVar7 + iVar8) * (in_stack_00005034 - iVar2));
    }
    iStack0000001c = 0;
    if (0 < iVar2) {
      puVar15 = puStack00000010;
      do {
        puVar3 = (uint *)&stack0x00000024;
        puVar14 = puVar15;
        iStack00000004 = in_stack_00005030;
        if (0 < in_stack_00005030) {
          do {
            pbVar13 = (byte *)(((int)*puVar3 >> 8) * 3 + (int)puStack00000008);
            puVar15 = (uint *)((int)puVar14 + 3);
            *(byte *)puVar14 =
                 (char)(((uint)pbVar13[3] - (uint)*pbVar13) * (*puVar3 & 0xff) >> 8) + *pbVar13;
            *(byte *)((int)puVar14 + 1) =
                 (char)(((uint)pbVar13[4] - (uint)pbVar13[1]) * (*puVar3 & 0xff) >> 8) + pbVar13[1];
            *(byte *)((int)puVar14 + 2) =
                 (char)(((uint)pbVar13[5] - (uint)pbVar13[2]) * (*puVar3 & 0xff) >> 8) + pbVar13[2];
            iStack00000004 = iStack00000004 + -1;
            puVar3 = puVar3 + 1;
            puVar14 = puVar15;
          } while (iStack00000004 != 0);
        }
        puStack00000008 = (uint *)((int)puStack00000008 + iVar5 * 3);
        iStack0000001c = iStack0000001c + 1;
        puVar15 = (uint *)((int)puVar15 + iVar8);
      } while (iStack0000001c < in_stack_0000502c[8]);
    }
    iVar5 = 0;
    iVar2 = in_stack_00005034;
    piStack00000020 = (int *)&stack0x00004024;
    if (0 < in_stack_00005034) {
      do {
        iVar1 = iVar5 >> 8;
        iVar5 = iVar5 + (iVar9 << 0x10) / in_stack_00005034;
        iVar2 = iVar2 + -1;
        *piStack00000020 = iVar1;
        piStack00000020 = piStack00000020 + 1;
      } while (iVar2 != 0);
    }
    uVar11 = uVar7 + iVar8;
    if (in_stack_00005034 < in_stack_0000502c[8]) {
      puVar15 = (uint *)((int)in_stack_00005028 + (in_stack_0000502c[8] + -1) * uVar11);
      puVar3 = (uint *)&stack0x00000024;
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar6 = uVar11 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)puVar3 = (char)*puVar15;
        puVar15 = (uint *)((int)puVar15 + 1);
        puVar3 = (uint *)((int)puVar3 + 1);
      }
    }
    if (0 < in_stack_00005030) {
      iStack00000004 = in_stack_00005030;
      puStack00000008 = in_stack_00005028;
      do {
        puVar15 = (uint *)&stack0x00004024;
        puVar3 = puStack00000008;
        iStack00000014 = in_stack_00005034 + -1;
        if (0 < in_stack_00005034 + -1) {
          do {
            iVar9 = (int)*puVar15 >> 8;
            iVar2 = in_stack_0000502c[8] + -2;
            if (iVar9 <= in_stack_0000502c[8] + -2) {
              iVar2 = iVar9;
            }
            puVar14 = (uint *)(iVar2 * uVar11 + (int)puStack00000010);
            *(byte *)puVar3 =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11) - (uint)(byte)*puVar14) *
                        (*puVar15 & 0xff) >> 8) + (byte)*puVar14;
            *(byte *)((int)puVar3 + 1) =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11 + 1) -
                        (uint)*(byte *)((int)puVar14 + 1)) * (*puVar15 & 0xff) >> 8) +
                 *(byte *)((int)puVar14 + 1);
            *(byte *)((int)puVar3 + 2) =
                 (char)(((uint)*(byte *)((int)puVar14 + uVar11 + 2) -
                        (uint)*(byte *)((int)puVar14 + 2)) * (*puVar15 & 0xff) >> 8) +
                 *(byte *)((int)puVar14 + 2);
            iStack00000014 = iStack00000014 + -1;
            puVar3 = (uint *)((int)puVar3 + uVar11);
            puVar15 = puVar15 + 1;
          } while (iStack00000014 != 0);
        }
        puStack00000010 = (uint *)((int)puStack00000010 + 3);
        puStack00000008 = (uint *)((int)puStack00000008 + 3);
        iStack00000004 = iStack00000004 + -1;
      } while (iStack00000004 != 0);
    }
    if (in_stack_00005034 < in_stack_0000502c[8]) {
      puVar15 = (uint *)&stack0x00000024;
      puVar3 = (uint *)((int)in_stack_00005028 + (in_stack_00005034 + -1) * uVar11);
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(char *)puVar3 = (char)*puVar15;
        puVar15 = (uint *)((int)puVar15 + 1);
        puVar3 = (uint *)((int)puVar3 + 1);
      }
    }
    else {
      puVar15 = (uint *)((int)in_stack_00005028 + (in_stack_00005034 + -1) * uVar11);
      for (uVar6 = uVar11 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined1 *)puVar15 = 0;
        puVar15 = (uint *)((int)puVar15 + 1);
      }
    }
    uVar11 = (int)uVar7 >> 0x1f;
    uVar7 = 4 - (((uVar7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11);
    uVar11 = (int)uVar7 >> 0x1f;
    iVar2 = ((uVar7 ^ uVar11) - uVar11 & 3 ^ uVar11) - uVar11;
    if (DAT_0052a1b8 == (uint *)0x0) {
      Palette_RemapBitmapRGB(in_stack_00005028,in_stack_00005034,in_stack_00005030,iVar2);
    }
    else if (DAT_006ff554 == 0x10) {
      Palette_DitherScanline
                ((int)DAT_0052a1b8,DAT_0052a1bc,(int)in_stack_00005028,in_stack_00005034,
                 in_stack_00005030,iVar2);
    }
    else if (DAT_006ff554 == 8) {
      Palette_DitherBitmapRGB
                (DAT_0052a1b8,DAT_0052a1bc,in_stack_00005028,in_stack_00005034,in_stack_00005030,
                 iVar2);
    }
    return in_stack_00005028;
  }
  return (uint *)0x0;
}


