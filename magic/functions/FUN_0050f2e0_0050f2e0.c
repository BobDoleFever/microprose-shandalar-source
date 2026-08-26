/*
 * Decompiled function: FUN_0050f2e0
 * Entry Point: 0050f2e0
 * Size: 108 bytes
 */
#include "magic.h"


HFONT FUN_0050f2e0(int arg1,LONG arg2)

{
  HANDLE h;
  HFONT pHVar1;
  int iVar2;
  LOGFONTA local_3c;
  
  iVar2 = arg1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar2) == 0) {
    return (HFONT)0x0;
  }
  h = *(HANDLE *)(&DAT_007077bc + iVar2);
  GetObjectA(h,0x3c,&local_3c);
  DeleteObject(h);
  local_3c.lfHeight = arg2;
  (&DAT_007077a4)[iVar2] = (char)arg2;
  pHVar1 = CreateFontIndirectA(&local_3c);
  *(HFONT *)(&DAT_007077bc + iVar2) = pHVar1;
  return pHVar1;
}


