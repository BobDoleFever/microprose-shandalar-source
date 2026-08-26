/*
 * Decompiled function: FUN_100334c7
 * Entry Point: 100334c7
 * Size: 383 bytes
 */
#include "deckdll.h"


/* WARNING: Type propagation algorithm not settling */

void FUN_100334c7(void)

{
  bool flag_1;
  BOOL BVar2;
  int val_3;
  int local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int local_20;
  int32_t local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  int32_t local_8;
  
  local_8 = DAT_101628d8;
  local_c = DAT_101cfb88;
  local_10 = DAT_101cdea8;
  local_14 = DAT_10176a98;
  local_18 = DAT_1013f1a8;
  local_1c = DAT_1016a610;
  local_20 = DAT_101cdeac;
  flag_1 = false;
  local_2c = DAT_10176868;
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
        flag_1 = true;
      }
      local_34 = local_28;
    }
  }
  if ((flag_1) && (val_3 = thunk_FUN_10033646((int)&local_20,7), val_3 != -1)) {
    SetWindowPos((HWND)(&local_20)[val_3],(HWND)0x1,0,0,0,0,3);
    if (val_3 + 1 < 7) {
      local_3c = (int)&local_1c + val_3 * 4;
    }
    else {
      local_3c = 0;
    }
    thunk_FUN_100336c9((HWND)(&local_20)[val_3],local_3c,7 - (val_3 + 1));
  }
  return;
}


