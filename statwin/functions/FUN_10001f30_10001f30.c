/*
 * Decompiled function: StatWin_RegisterWindowClass
 * Entry Point: 10001f30
 * Size: 583 bytes
 */
#include "statwin.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t StatWin_RegisterWindowClass(HINSTANCE hInstance,int32_t arg_2)

{
  int32_t *ptr_1;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_1c;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10002188;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  switch(arg_2) {
  case 0:
    if (DAT_100117a4 != (int32_t *)0x0) {
      if (DAT_100117a4 != (int32_t *)0x0) {
        thunk_FUN_100041b0(DAT_100117a4,1);
      }
      DAT_100117a4 = (int32_t *)0x0;
    }
    if (DAT_1001178c != 0) {
      thunk_FUN_1000160f();
    }
    if (DAT_10011790 != 0) {
      thunk_FUN_10009766();
    }
    UnregisterClassA(PTR_s_STATWINCLASS_100117a0,DAT_10013150);
    break;
  case 1:
    DAT_1001316c = hInstance;
    ptr_1 = operator_new(0x28);
    local_8 = 0;
    if (ptr_1 == (int32_t *)0x0) {
      local_1c = (int32_t *)0x0;
    }
    else {
      local_1c = thunk_FUN_10004407(ptr_1);
    }
    local_8 = 0xffffffff;
    DAT_100117a4 = local_1c;
    if (local_1c == (int32_t *)0x0) {
      uval_2 = 0;
      goto LAB_10002192;
    }
    val_1 = thunk_FUN_10009640(0,DAT_1001316c,0);
    DAT_10011790 = (uint32_t)(val_1 == 0);
    val_1 = thunk_FUN_100014b0(0,0,3);
    DAT_1001178c = (uint32_t)(val_1 == 0);
    _DAT_10013140 = 3;
    _DAT_10013144 = &LAB_100010fa;
    _DAT_10013148 = 0;
    _DAT_1001314c = 0;
    DAT_10013150 = DAT_1001316c;
    _DAT_10013154 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10013158 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_1001315c = GetStockObject(4);
    _DAT_10013160 = 0;
    _DAT_10013164 = PTR_s_STATWINCLASS_100117a0;
    RegisterClassA((WNDCLASSA *)&DAT_10013140);
    break;
  case 2:
    break;
  case 3:
  }
  uval_2 = 1;
LAB_10002192:
  *unaff_FS_OFFSET = local_10;
  return uval_2;
}


