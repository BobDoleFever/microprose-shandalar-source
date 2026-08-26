/*
 * Decompiled function: FUN_0049e921
 * Entry Point: 0049e921
 * Size: 383 bytes
 */
#include "duel.h"


void FUN_0049e921(HWND hwnd,int arg2)

{
  int iVar1;
  WPARAM wParam;
  uint local_10c [66];
  
  if ((DAT_005f649c != 0) && (DAT_005f6288 != 0)) {
    if (arg2 == 0) {
      if (DAT_005f64b0 == 0) {
        iVar1 = _rand();
        DAT_005f6498 = iVar1 % DAT_005f649c;
        _sprintf(&DAT_005f66e0,s__s__s_dck_00505e44,&DAT_00664a60,
                 &DAT_005f6cc0 + DAT_005f6498 * 0x80);
        Mem_AllocOrFree_004d9630
                  ((uint *)&DAT_00664b90,(uint *)(&DAT_005f6cc0 + DAT_005f6498 * 0x80));
      }
      else {
        iVar1 = _rand();
        DAT_005f6498 = iVar1 % DAT_005f6288;
        _sprintf(&DAT_005f66e0,s__s__s_dck_00505e50,&DAT_00664a60,
                 &DAT_005f2fb0 + DAT_005f6498 * 0x80);
        Mem_AllocOrFree_004d9630
                  ((uint *)&DAT_00664b90,(uint *)(&DAT_005f2fb0 + DAT_005f6498 * 0x80));
      }
    }
    else {
      wParam = SendDlgItemMessageA(hwnd,0x463,0x147,0,0);
      SendDlgItemMessageA(hwnd,0x463,0x148,wParam,(LPARAM)local_10c);
      _sprintf(&DAT_005f66e0,s__s__s_dck_00505e5c,&DAT_00664a60,local_10c);
      Mem_AllocOrFree_004d9630((uint *)&DAT_00664752,local_10c);
      Mem_AllocOrFree_004d9630((uint *)&DAT_00664b90,local_10c);
    }
  }
  return;
}


