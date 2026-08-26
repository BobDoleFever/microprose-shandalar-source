/*
 * Decompiled function: FUN_0046ab25
 * Entry Point: 0046ab25
 * Size: 549 bytes
 */
#include "magic.h"


undefined4 FUN_0046ab25(HWND hwnd)

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
  uVar1 = Ai_Subsystem_004b613b(arg1,arg2);
  uVar2 = Ai_Subsystem_004b6356(arg1,arg2);
  local_24 = -1;
  local_10 = 0xffffffff;
  pHVar3 = GetParent(hwnd);
  if (pHVar3 == DAT_0069e720) {
    local_24 = 0;
    local_10 = 2;
  }
  else if (DAT_006fe400 == pHVar3) {
    local_24 = 1;
    local_10 = 2;
  }
  else if (DAT_006a4924 == pHVar3) {
    local_24 = 0;
    local_10 = 1;
  }
  else if (DAT_006b2e2c == pHVar3) {
    local_24 = 1;
    local_10 = 1;
  }
  else if (pHVar3 == DAT_006b2e10) {
    local_24 = 0;
    local_10 = 0x10;
  }
  else if (pHVar3 == DAT_006a4928) {
    local_24 = 1;
    local_10 = 0x10;
  }
  if ((((((DAT_006feec0 == -1) || (DAT_006feec0 == arg1)) &&
        ((DAT_006feec4 == 0xffffffff || ((DAT_006feec4 == 0 || ((uVar1 & DAT_006feec4) != 0)))))) &&
       (((DAT_006feec8 == 0xffffffff || ((DAT_006feec8 == 0 || ((uVar2 & DAT_006feec8) != 0)))) ||
        ((((DAT_006feec8 & 0x100) != 0 && ((uVar1 & 0x40) != 0)) ||
         (((DAT_006feec8 & 0x200) != 0 && ((uVar1 & 1) != 0)))))))) &&
      ((DAT_006feecc == -1 || (DAT_006feecc == local_24)))) &&
     ((DAT_006feed0 == 0xffffffff || ((local_10 & DAT_006feed0) != 0)))) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


