/*
 * Decompiled function: FUN_10003303
 * Entry Point: 10003303
 * Size: 333 bytes
 */
#include "statwin.h"


void FUN_10003303(CFontDialog *ptr_1,LPCSTR arg_2)

{
  int val_1;
  int width;
  int32_t *unaff_FS_OFFSET;
  uint8_t local_48 [8];
  int local_40;
  int local_3c;
  CPrintPreviewState local_38 [24];
  int32_t local_20 [2];
  int local_18;
  int local_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10003459;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(local_38);
  local_8 = 0;
  val_1 = GetSystemMetrics(0);
  width = GetSystemMetrics(1);
  thunk_FUN_10009e72(ptr_1,val_1,width,0x18);
  val_1 = thunk_FUN_1000a2e4(local_38,(HWND)0x0,arg_2,0x18);
  if (val_1 == 0) {
    local_8 = 0xffffffff;
    FUN_10003450();
    FUN_10003463();
    return;
  }
  thunk_FUN_1000acc2(local_38,local_20);
  (**(code **)(*(int *)ptr_1 + 0x14))(local_48);
  if ((local_40 == local_18) && (local_3c == local_14)) {
    thunk_FUN_1000ad09(local_38,ptr_1,0,0,local_18,local_14,0,0);
  }
  else if ((local_18 < local_40) && (local_14 < local_3c)) {
    thunk_FUN_1000ad09(local_38,ptr_1,(local_40 - local_18) / 2,(local_3c - local_14) / 2,local_18,
                       local_14,0,0);
  }
  local_8 = 0xffffffff;
  FUN_10003450();
  FUN_10003463();
  return;
}


