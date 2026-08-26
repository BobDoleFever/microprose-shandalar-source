/*
 * Decompiled function: FUN_0050e8b0
 * Entry Point: 0050e8b0
 * Size: 735 bytes
 */
#include "magic.h"


void FUN_0050e8b0(short *arg_1)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  
  sVar1 = arg_1[1];
  psVar8 = arg_1;
  puVar10 = &DAT_0070a130;
  for (uVar4 = (uint)(int)(short)(sVar1 + 2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar10 = *(undefined4 *)psVar8;
    psVar8 = psVar8 + 2;
    puVar10 = puVar10 + 1;
  }
  for (uVar4 = (int)(short)(sVar1 + 2) & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)puVar10 = (char)*psVar8;
    psVar8 = (short *)((int)psVar8 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  uVar5 = (uint)*(byte *)(arg_1 + 2);
  uVar4 = (-(uint)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
  uVar6 = (uint)*(byte *)((int)arg_1 + 5);
  bVar3 = (byte)uVar4;
  if (DAT_005326d4 == *arg_1) {
    if (uVar5 <= uVar6) {
      iVar11 = uVar5 * 4;
      pbVar9 = (byte *)((int)arg_1 + uVar5 * 3 + 6);
      iVar7 = (uVar6 - uVar5) + 1;
      do {
        bVar2 = (byte)(((uint)*pbVar9 * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a450)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11 + 2) = bVar2;
        bVar2 = (byte)(((uint)pbVar9[1] * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a451)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11 + 1) = bVar2;
        bVar2 = (byte)(((uint)pbVar9[2] * 0xff) / 0x3f) & bVar3;
        (&DAT_0070a452)[iVar11] = bVar2;
        *(byte *)((int)&DAT_0070a890 + iVar11) = bVar2;
        (&DAT_0070a453)[iVar11] = 1;
        *(undefined1 *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
        if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
          uVar5 = uVar4 * 0x10000 | uVar4 * 0x100 | uVar4;
          *(uint *)(&DAT_0070a450 + iVar11) = uVar5 & 0x1fefefe;
          *(uint *)((int)&DAT_0070a890 + iVar11) = uVar5 & 0xfefefe;
        }
        iVar11 = iVar11 + 4;
        pbVar9 = pbVar9 + 3;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else if ((DAT_005326d0 == *arg_1) && (uVar5 <= uVar6)) {
    iVar11 = uVar5 * 4;
    pbVar9 = (byte *)((int)arg_1 + uVar5 * 3 + 6);
    iVar7 = (uVar6 - uVar5) + 1;
    do {
      bVar2 = *pbVar9;
      (&DAT_0070a450)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11 + 2) = bVar2 & bVar3;
      bVar2 = pbVar9[1];
      (&DAT_0070a451)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11 + 1) = bVar2 & bVar3;
      bVar2 = pbVar9[2];
      (&DAT_0070a452)[iVar11] = bVar2 & bVar3;
      *(byte *)((int)&DAT_0070a890 + iVar11) = bVar2 & bVar3;
      (&DAT_0070a453)[iVar11] = 1;
      *(undefined1 *)((int)&DAT_0070a890 + iVar11 + 3) = 0;
      if ((*(int *)((int)&DAT_0070a890 + iVar11) == 0xffffff) && (iVar11 != 0x3fc)) {
        uVar5 = (uVar4 * 0x10000 | uVar4 * 0x100 | uVar4) & 0xfefefe;
        *(uint *)((int)&DAT_0070a890 + iVar11) = uVar5;
        *(uint *)(&DAT_0070a450 + iVar11) = uVar5;
        (&DAT_0070a453)[iVar11] = 1;
      }
      iVar11 = iVar11 + 4;
      pbVar9 = pbVar9 + 3;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  DAT_0070a452 = 0;
  DAT_0070a451 = 0;
  DAT_0070a450 = 0;
  DAT_0070a453 = 0;
  DAT_0070a890._0_1_ = 0;
  DAT_0070a890._1_1_ = 0;
  DAT_0070a890._2_1_ = 0;
  DAT_0070a890._3_1_ = 0;
  DAT_0070a847 = 1;
  DAT_0070a84b = 1;
  DAT_0070a84f = 0;
  DAT_0070ac87 = 0;
  DAT_0070ac8c = 0xff;
  DAT_0070ac8d = 0xff;
  DAT_0070ac8e = 0xff;
  DAT_0070ac8f = 0;
  AnimatePalette(_hLibPal,0,0x100,(PALETTEENTRY *)&DAT_0070a450);
  if (DAT_0070a850 != 0) {
    RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  }
  piVar12 = &DAT_0070a854;
  do {
    if (*piVar12 != 0) {
      SetDIBColorTable(*(HDC *)(*piVar12 + 4),0,0x100,(RGBQUAD *)&DAT_0070a890);
    }
    piVar12 = piVar12 + 1;
  } while (piVar12 < &DAT_0070a878);
  DAT_00623150 = FindWindowExA((HWND)0x0,(HWND)0x0,s_ShowPaletteClass_005326ac,
                               s_Current_Palette_005326c0);
  if (DAT_00623150 != (HWND)0x0) {
    InvalidateRect(DAT_00623150,(RECT *)0x0,0);
    UpdateWindow(DAT_00623150);
  }
  DAT_00532558 = 1;
  return;
}


