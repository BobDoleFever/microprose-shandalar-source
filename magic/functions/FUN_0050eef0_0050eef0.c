/*
 * Decompiled function: FUN_0050eef0
 * Entry Point: 0050eef0
 * Size: 497 bytes
 */
#include "magic.h"


undefined4 FUN_0050eef0(int arg1,FILE *fp)

{
  size_t _Count;
  uint nHeight;
  uint uVar1;
  void *_DstBuf;
  uint uVar2;
  HBITMAP pHVar3;
  byte *pbVar4;
  HDC pHVar5;
  int iVar6;
  int iVar7;
  uint _Count_00;
  int iVar8;
  
  iVar6 = arg1 * 0x2a0;
  pbVar4 = &DAT_007077a0 + iVar6;
  fseek(fp,-8,1);
  fread(pbVar4,1,8,fp);
  _Count = ((uint)(byte)(&DAT_007077a1)[iVar6] - (uint)*pbVar4) + 1;
  if ((&DAT_007077a3)[iVar6] == '\0') {
    fseek(fp,-8 - _Count,1);
    fread(&DAT_00707720 + (uint)*pbVar4 + iVar6,1,_Count,fp);
    fseek(fp,8,1);
  }
  nHeight = (uint)(byte)(&DAT_007077a4)[iVar6];
  _Count_00 = (byte)(&DAT_007077a2)[iVar6] * _Count;
  uVar1 = _Count_00 & 1;
  (&DAT_007077a7)[iVar6] = (char)uVar1;
  if (*(void **)(&DAT_007077b4 + iVar6) != (void *)0x0) {
    free(*(void **)(&DAT_007077b4 + iVar6));
  }
  if (*(HGDIOBJ *)(&DAT_007077ac + iVar6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077ac + iVar6));
  }
  if (*(HGDIOBJ *)(&DAT_007077a8 + iVar6) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(&DAT_007077a8 + iVar6));
  }
  iVar8 = (uVar1 + _Count_00) * nHeight;
  _DstBuf = malloc(iVar8 + 10000);
  *(void **)(&DAT_007077b4 + iVar6) = _DstBuf;
  for (uVar2 = nHeight; uVar2 != 0; uVar2 = uVar2 - 1) {
    fread(_DstBuf,1,_Count_00,fp);
    _DstBuf = (void *)((int)_DstBuf + uVar1 + _Count_00);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + iVar6));
  *(HBITMAP *)(&DAT_007077ac + iVar6) = pHVar3;
  pbVar4 = *(byte **)(&DAT_007077b4 + iVar6);
  iVar7 = iVar8;
  if (0 < iVar8) {
    do {
      iVar7 = iVar7 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (iVar7 != 0);
  }
  pHVar3 = CreateBitmap(_Count_00 * 8,nHeight,1,1,*(void **)(&DAT_007077b4 + iVar6));
  *(HBITMAP *)(&DAT_007077a8 + iVar6) = pHVar3;
  pbVar4 = *(byte **)(&DAT_007077b4 + iVar6);
  if (0 < iVar8) {
    do {
      iVar8 = iVar8 + -1;
      *pbVar4 = ~*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (iVar8 != 0);
  }
  if (*(int *)(&DAT_007077b0 + iVar6) == 0) {
    pHVar5 = CreateCompatibleDC((HDC)0x0);
    *(HDC *)(&DAT_007077b0 + iVar6) = pHVar5;
  }
  *(undefined4 *)(&DAT_007077b8 + iVar6) = 0;
  return 0;
}


