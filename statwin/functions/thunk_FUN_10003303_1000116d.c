/*
 * Decompiled function: thunk_FUN_10003303
 * Entry Point: 1000116d
 * Size: 5 bytes
 */
#include "statwin.h"


void thunk_FUN_10003303(CFontDialog *ptr_1,LPCSTR arg_2)

{
  int val_1;
  int width;
  int32_t *unaff_FS_OFFSET;
  uint8_t auStack_48 [8];
  int iStack_40;
  int iStack_3c;
  CPrintPreviewState aCStack_38 [24];
  int32_t auStack_20 [2];
  int iStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10003459;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_38);
  uStack_8 = 0;
  val_1 = GetSystemMetrics(0);
  width = GetSystemMetrics(1);
  thunk_FUN_10009e72(ptr_1,val_1,width,0x18);
  val_1 = thunk_FUN_1000a2e4(aCStack_38,(HWND)0x0,arg_2,0x18);
  if (val_1 == 0) {
    uStack_8 = 0xffffffff;
    FUN_10003450();
    FUN_10003463();
    return;
  }
  thunk_FUN_1000acc2(aCStack_38,auStack_20);
  (**(code **)(*(int *)ptr_1 + 0x14))(auStack_48);
  if ((iStack_40 == iStack_18) && (iStack_3c == iStack_14)) {
    thunk_FUN_1000ad09(aCStack_38,ptr_1,0,0,iStack_18,iStack_14,0,0);
  }
  else if ((iStack_18 < iStack_40) && (iStack_14 < iStack_3c)) {
    thunk_FUN_1000ad09(aCStack_38,ptr_1,(iStack_40 - iStack_18) / 2,(iStack_3c - iStack_14) / 2,
                       iStack_18,iStack_14,0,0);
  }
  uStack_8 = 0xffffffff;
  FUN_10003450();
  FUN_10003463();
  return;
}


