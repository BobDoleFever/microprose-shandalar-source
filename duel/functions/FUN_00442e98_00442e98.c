/*
 * Decompiled function: FUN_00442e98
 * Entry Point: 00442e98
 * Size: 355 bytes
 */
#include "duel.h"


undefined4 FUN_00442e98(HWND param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  HWND pHVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return 0;
    }
    if (param_2 == 0x110) {
      SetWindowLongA(param_1,8,param_4[1]);
      SetDlgItemTextA(param_1,0x42e,(LPCSTR)*param_4);
      if (param_4[1] == 1) {
        pHVar1 = GetDlgItem(param_1,6);
        SetFocus(pHVar1);
      }
      else {
        pHVar1 = GetDlgItem(param_1,7);
        SetFocus(pHVar1);
      }
      return 0;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 6) {
        EndDialog(param_1,1);
      }
      else if ((param_3 & 0xffff) == 7) {
        EndDialog(param_1,0);
      }
      return 1;
    }
  }
  else if ((0x30e < param_2) && (param_2 < 0x312)) {
    uVar2 = FUN_00472b60(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}


