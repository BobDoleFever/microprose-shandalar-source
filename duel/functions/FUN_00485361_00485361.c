/*
 * Decompiled function: FUN_00485361
 * Entry Point: 00485361
 * Size: 550 bytes
 */
#include "duel.h"


undefined4 FUN_00485361(HWND hwnd)

{
  LONG arg1;
  LONG arg2;
  uint uVar1;
  uint uVar2;
  HWND pHVar3;
  undefined4 local_24;
  undefined4 local_14;
  undefined4 local_10;
  
  arg1 = GetWindowLongA(hwnd,0);
  arg2 = GetWindowLongA(hwnd,4);
  uVar1 = FUN_00447604(arg1,arg2);
  uVar2 = FUN_0044781f(arg1,arg2);
  local_24 = -1;
  local_10 = 0xffffffff;
  pHVar3 = GetParent(hwnd);
  if (DAT_006152b0 == pHVar3) {
    local_24 = 0;
    local_10 = 2;
  }
  else if (DAT_00663df4 == pHVar3) {
    local_24 = 1;
    local_10 = 2;
  }
  else if (DAT_00617378 == pHVar3) {
    local_24 = 0;
    local_10 = 1;
  }
  else if (DAT_00618988 == pHVar3) {
    local_24 = 1;
    local_10 = 1;
  }
  else if (pHVar3 == DAT_00618978) {
    local_24 = 0;
    local_10 = 0x10;
  }
  else if (pHVar3 == DAT_0061737c) {
    local_24 = 1;
    local_10 = 0x10;
  }
  if ((((((DAT_00664780 == -1) || (DAT_00664780 == arg1)) &&
        ((DAT_00664784 == 0xffffffff || ((DAT_00664784 == 0 || ((uVar1 & DAT_00664784) != 0)))))) &&
       (((DAT_00664788 == 0xffffffff || ((DAT_00664788 == 0 || ((uVar2 & DAT_00664788) != 0)))) ||
        ((((DAT_00664788 & 0x100) != 0 && ((uVar1 & 0x40) != 0)) ||
         (((DAT_00664788 & 0x200) != 0 && ((uVar1 & 1) != 0)))))))) &&
      ((DAT_0066478c == -1 || (DAT_0066478c == local_24)))) &&
     ((DAT_00664790 == 0xffffffff || ((local_10 & DAT_00664790) != 0)))) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


