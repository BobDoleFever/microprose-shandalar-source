/*
 * Decompiled function: FUN_0050f350
 * Entry Point: 0050f350
 * Size: 59 bytes
 */
#include "magic.h"


BOOL FUN_0050f350(int arg_1)

{
  BOOL BVar1;
  int iVar2;
  
  iVar2 = arg_1 * 0x2a0;
  if (*(int *)(&DAT_007077b8 + iVar2) == 0) {
    return 0;
  }
  DeleteObject(*(HGDIOBJ *)(&DAT_007077bc + iVar2));
  BVar1 = RemoveFontResourceA(&DAT_007077c0 + iVar2);
  return BVar1;
}


