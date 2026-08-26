/*
 * Decompiled function: FUN_00490233
 * Entry Point: 00490233
 * Size: 309 bytes
 */
#include "duel.h"


LRESULT FUN_00490233(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  HWND pHVar1;
  uint lParam;
  LRESULT LVar2;
  tagPOINT *lpPoints;
  UINT cPoints;
  tagPOINT local_c;
  
  if (param_2 < 0x10) {
    if ((param_2 == 0xf) || ((param_2 != 0 && (param_2 < 3)))) goto LAB_00490247;
  }
  else if (param_2 < 0x203) {
    if (0x200 < param_2) {
      local_c.x = param_4 & 0xffff;
      local_c.y = param_4 >> 0x10;
      cPoints = 1;
      lpPoints = &local_c;
      pHVar1 = GetParent(param_1);
      MapWindowPoints(param_1,pHVar1,lpPoints,cPoints);
      lParam = local_c.y << 0x10 | local_c.x & 0xffffU;
      pHVar1 = GetParent(param_1);
      SendMessageA(pHVar1,param_2,param_3,lParam);
      return 0;
    }
    if (param_2 == 0x14) {
LAB_00490247:
      LVar2 = CallWindowProcA(FUN_00482299,param_1,param_2,param_3,param_4);
      return LVar2;
    }
  }
  else if ((0x30e < param_2) && (param_2 < 0x312)) goto LAB_00490247;
  LVar2 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar2;
}


