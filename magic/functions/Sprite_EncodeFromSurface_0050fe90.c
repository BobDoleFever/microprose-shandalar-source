/*
 * Decompiled function: Sprite_EncodeFromSurface
 * Entry Point: 0050fe90
 * Size: 841 bytes
 */
#include "magic.h"


void Sprite_EncodeFromSurface(int arg_1,int arg_2,int arg_3,uint arg_4,int arg_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  int local_40c;
  undefined4 local_404;
  char local_400 [1024];
  
  local_40c = 0;
  iVar11 = arg_3 + 1 + arg_5;
  iVar3 = arg_2 + -1;
  if ((iVar3 < 0) || (iVar11 < 0)) {
    local_404 = -1;
  }
  else {
    local_404 = (uint)(arg_4 != 0xfffffffe);
    iVar4 = Surface_GetPixel(arg_1,iVar3,iVar11);
    iVar16 = arg_4 + 2;
    if (arg_4 == 0xfffffffe) {
      iVar16 = 0;
    }
    iVar15 = 0;
    iVar12 = iVar3;
    if (0 < iVar16) {
      do {
        iVar5 = Surface_GetPixel(arg_1,iVar12,iVar11);
        if (iVar5 != iVar4) break;
        iVar15 = iVar15 + 1;
        iVar12 = iVar12 + local_404;
      } while (iVar15 < iVar16);
    }
    local_404 = -1;
    if (iVar15 != iVar16) {
      local_404 = iVar15;
    }
  }
  iVar11 = arg_3 + -1;
  if ((iVar3 < 0) || (iVar11 < 0)) {
    iVar11 = -1;
  }
  else {
    iVar4 = 0;
    iVar16 = Surface_GetPixel(arg_1,iVar3,iVar11);
    iVar12 = arg_5 + 2;
    if (0 < iVar12) {
      do {
        iVar15 = Surface_GetPixel(arg_1,iVar3,iVar11);
        if (iVar15 != iVar16) break;
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + (uint)(arg_5 != -2);
      } while (iVar4 < iVar12);
    }
    iVar11 = -1;
    if (iVar12 != iVar4) {
      iVar11 = iVar4;
    }
  }
  piVar2 = DAT_0062517c;
  piVar14 = DAT_0062517c + 4;
  do {
    Surface_GetLine((undefined4 *)local_400,arg_1,arg_2,arg_3 + local_40c,arg_4);
    pcVar10 = local_400;
    uVar7 = arg_4;
    cVar1 = local_400[0];
    while ((cVar1 == '\0' && (uVar7 != 0))) {
      cVar1 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
      uVar7 = uVar7 - 1;
    }
  } while ((pcVar10 + -arg_4 == local_400) && (local_40c = local_40c + 1, local_40c < arg_5));
  *(undefined2 *)(piVar2 + 1) = (undefined2)arg_4;
  *(short *)((int)piVar2 + 6) = (short)arg_5;
  *(undefined2 *)(piVar2 + 2) = (undefined2)local_404;
  *(short *)((int)piVar2 + 10) = (short)iVar11;
  *(short *)(piVar2 + 3) = (short)local_40c;
  *(short *)((int)piVar2 + 0xe) = (short)arg_5 - (short)local_40c;
  for (; local_40c < arg_5; local_40c = local_40c + 1) {
    pcVar10 = local_400;
    uVar7 = arg_4;
    cVar1 = local_400[0];
    while ((cVar1 == '\0' && (uVar7 != 0))) {
      cVar1 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
      uVar7 = uVar7 - 1;
    }
    uVar7 = (int)pcVar10 - (int)local_400;
    if (arg_4 == uVar7) {
      *(undefined1 *)piVar14 = 0xff;
      piVar14 = (int *)((int)piVar14 + 1);
    }
    else {
      *(char *)piVar14 = (char)uVar7;
      puVar13 = (undefined1 *)((int)piVar14 + 1);
      cVar1 = *(char *)((int)&local_404 + arg_4 + 3);
      iVar11 = (int)&local_404 + arg_4 + 3;
      iVar3 = iVar11;
      uVar9 = arg_4;
      while ((cVar1 == '\0' && (uVar9 != 0))) {
        cVar1 = *(char *)(iVar3 + -1);
        iVar3 = iVar3 + -1;
        uVar9 = uVar9 - 1;
      }
      uVar9 = iVar3 + ((arg_4 - uVar7) - iVar11);
      pvVar6 = memchr(local_400 + uVar7,0,uVar9);
      if (pvVar6 == (void *)0x0) {
        *puVar13 = 0xfe;
        puVar13 = (undefined1 *)((int)piVar14 + 2);
      }
      *puVar13 = (char)uVar9;
      pcVar10 = local_400 + uVar7;
      pcVar17 = puVar13 + 1;
      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar10;
        pcVar10 = pcVar10 + 4;
        pcVar17 = pcVar17 + 4;
      }
      piVar14 = (int *)(puVar13 + 1 + uVar9);
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar17 = *pcVar10;
        pcVar10 = pcVar10 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    Surface_GetLine((undefined4 *)local_400,arg_1,arg_2,arg_3 + local_40c + 1,arg_4);
  }
  cVar1 = *(char *)((int)piVar14 + -1);
  DAT_0062517c = piVar14;
  while (cVar1 == -1) {
    *(short *)((int)piVar2 + 0xe) = *(short *)((int)piVar2 + 0xe) + -1;
    cVar1 = *(char *)((int)DAT_0062517c + -2);
    DAT_0062517c = (int *)((int)DAT_0062517c + -1);
  }
  if (((uint)DAT_0062517c & 1) != 0) {
    DAT_0062517c = (int *)((int)DAT_0062517c + 1);
  }
  if (((uint)DAT_0062517c & 2) != 0) {
    DAT_0062517c = (int *)((int)DAT_0062517c + 2);
  }
  *DAT_0062517c = -1;
  *piVar2 = (int)DAT_0062517c - (int)piVar2;
  return;
}


