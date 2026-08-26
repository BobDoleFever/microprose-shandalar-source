/*
 * Decompiled function: FUN_0043433a
 * Entry Point: 0043433a
 * Size: 188 bytes
 */
#include "duel.h"


bool FUN_0043433a(int arg_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = arg_1 + -1;
  iVar2 = *(int *)(&DAT_006c0cb0 + iVar1 * 0x114);
  if (iVar2 != 0) {
    FUN_004db150(*(undefined4 *)(&DAT_006c0cb8 + iVar1 * 0x114));
    _fclose(*(FILE **)(&DAT_006c0cb0 + iVar1 * 0x114));
    *(undefined4 *)(&DAT_006c0cb8 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_006c0cb0 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_006c0cb4 + iVar1 * 0x114) = 0;
  }
  return iVar2 != 0;
}


