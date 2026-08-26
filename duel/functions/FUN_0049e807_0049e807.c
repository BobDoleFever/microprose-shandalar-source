/*
 * Decompiled function: FUN_0049e807
 * Entry Point: 0049e807
 * Size: 282 bytes
 */
#include "duel.h"


void FUN_0049e807(HWND hwnd,int arg2)

{
  int iVar1;
  WPARAM wParam;
  uint local_10c [66];
  
  if (DAT_005f6288 != 0) {
    if (arg2 == 1) {
      iVar1 = _rand();
      iVar1 = iVar1 % DAT_005f6288;
      _sprintf(&DAT_005f65d0,s__s__s_dck_00505e2c,&DAT_00664a60,&DAT_005f2fb0 + iVar1 * 0x80);
      Mem_AllocOrFree_004d9630((uint *)&DAT_006015b0,(uint *)(&DAT_005f2fb0 + iVar1 * 0x80));
    }
    else if (1 < arg2) {
      wParam = SendDlgItemMessageA(hwnd,0x462,0x147,0,0);
      SendDlgItemMessageA(hwnd,0x462,0x148,wParam,(LPARAM)local_10c);
      _sprintf(&DAT_005f65d0,s__s__s_dck_00505e38,&DAT_00664a60,local_10c);
      Mem_AllocOrFree_004d9630((uint *)&DAT_00664734,local_10c);
      Mem_AllocOrFree_004d9630((uint *)&DAT_006015b0,local_10c);
    }
  }
  return;
}


