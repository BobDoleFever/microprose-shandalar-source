/*
 * Decompiled function: FUN_0047283d
 * Entry Point: 0047283d
 * Size: 383 bytes
 */
#include "duel.h"


/* WARNING: Type propagation algorithm not settling */

void FUN_0047283d(void)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  int local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_0060cc6c;
  local_c = DAT_00664d90;
  local_10 = DAT_00663df0;
  local_14 = DAT_00618ab0;
  local_18 = DAT_00694748;
  local_1c = DAT_006152b0;
  local_20 = DAT_00663df4;
  bVar1 = false;
  local_2c = DAT_00618990;
  local_34 = -1;
  while (local_2c != (HWND)0x0) {
    local_2c = GetWindow(local_2c,3);
    local_30 = 0;
    local_28 = -1;
    while ((local_30 < 7 && (local_28 == -1))) {
      if ((HWND)(&local_20)[local_30] == local_2c) {
        local_28 = local_30;
      }
      local_30 = local_30 + 1;
    }
    if ((local_28 != -1) && (BVar2 = IsWindowVisible(local_2c), BVar2 != 0)) {
      if (local_28 < local_34) {
        bVar1 = true;
      }
      local_34 = local_28;
    }
  }
  if ((bVar1) && (iVar3 = FUN_004729bc((int)&local_20,7), iVar3 != -1)) {
    SetWindowPos((HWND)(&local_20)[iVar3],(HWND)0x1,0,0,0,0,3);
    if (iVar3 + 1 < 7) {
      local_3c = (int)&local_1c + iVar3 * 4;
    }
    else {
      local_3c = 0;
    }
    FUN_00472a3f((HWND)(&local_20)[iVar3],local_3c,7 - (iVar3 + 1));
  }
  return;
}


