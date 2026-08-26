/*
 * Decompiled function: FUN_10020449
 * Entry Point: 10020449
 * Size: 1528 bytes
 */
#include "deckdll.h"


void FUN_10020449(HDC hdc,RECT *arg_2,int width,int height)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t width_00;
  int val_3;
  int width_01;
  HGDIOBJ h;
  int stack_arg;
  int stack_arg;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  uint32_t local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  WPARAM local_a4;
  char *local_a0;
  char *local_9c;
  int local_94;
  int local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) &&
     (local_8 = thunk_FUN_100241ba(width,height), local_8 != -1)) {
    local_a8 = SaveDC(hdc);
    memcpy(&local_a4,&DAT_10176ab0 + local_8 * 0x98,0x98);
    local_b0 = local_94;
    uval_1 = thunk_FUN_100241a8(width,height);
    local_ac = thunk_FUN_10024196(uval_1);
    if (((((local_b0 == 1) || (local_b0 == 8)) ||
         ((local_b0 == 7 || ((local_b0 == 5 || (local_b0 == 2)))))) ||
        ((local_b0 == 6 && (local_ac != 0)))) || ((local_b0 == 3 && (local_ac != 0)))) {
      if (local_ac == 1) {
        local_94 = 1;
      }
      else if (local_ac == 5) {
        local_94 = 8;
      }
      else if (local_ac == 3) {
        local_94 = 5;
      }
      else if (local_ac == 4) {
        local_94 = 7;
      }
      else if (local_ac == 2) {
        local_94 = 2;
      }
    }
    if (stack_arg != 0) {
      local_9c = s_Activation_10043968;
      local_a0 = s_Activation_10043968;
      local_94 = -1;
    }
    if (stack_arg != 0) {
      local_9c = s_Upkeep_10043974;
      local_a0 = s_Upkeep_10043974;
      local_94 = -1;
    }
    local_c = thunk_FUN_10013e94(local_8,width,height);
    thunk_FUN_1001df0d(hdc,arg_2,&local_a4,local_c,1);
    thunk_FUN_10020a41(hdc,&arg_2->left,width,height);
    if ((DAT_1013f378 != 0) && (uval_2 = thunk_FUN_10024284(width,height), (uval_2 & 2) != 0)) {
      uval_2 = thunk_FUN_100242a8(width,height);
      width_00 = thunk_FUN_10024296(width,height);
      thunk_FUN_1001e527(hdc,&arg_2->left,width_00,uval_2);
    }
    uval_2 = thunk_FUN_10024284(width,height);
    if ((((uval_2 & 2) != 0) || (DAT_1013f390 != 0)) &&
       (uval_2 = thunk_FUN_10024272(width,height), (uval_2 & 1) != 0)) {
      thunk_FUN_10020d38(hdc,arg_2);
    }
    uval_2 = thunk_FUN_10024284(width,height);
    if (((uval_2 & 2) != 0) && (val_3 = thunk_FUN_10024360(width,height), val_3 == 2)) {
      thunk_FUN_10020dbf(hdc,arg_2);
    }
    local_b4 = thunk_FUN_10024260(width,height);
    if ((DAT_1013f37c != 0) && (local_b4 != 0)) {
      thunk_FUN_1001f340(hdc,&arg_2->left,local_b4);
    }
    local_b8 = thunk_FUN_1002424e(width,height);
    if (local_b8 != 0) {
      thunk_FUN_1001e87a(hdc,&arg_2->left,local_b8);
    }
    local_c8 = arg_2->left + ((arg_2->right - arg_2->left) * 7) / 100;
    local_c0 = arg_2->right - ((arg_2->right - arg_2->left) * 10) / 100;
    local_c4 = arg_2->top + ((arg_2->bottom - arg_2->top) * 8) / 100;
    local_bc = arg_2->top + ((arg_2->bottom - arg_2->top) * 0x23) / 100;
    val_3 = thunk_FUN_10024231(width,height);
    local_cc = val_3;
    if (val_3 != 0) {
      width_01 = thunk_FUN_100211be(local_8);
      thunk_FUN_1001ecca(hdc,(int)arg_2,width_01,val_3);
    }
    local_c4 = arg_2->top + ((arg_2->bottom - arg_2->top) * 0x23) / 100;
    local_bc = arg_2->top + ((arg_2->bottom - arg_2->top) * 0x3e) / 100;
    thunk_FUN_10024243(width,height,&local_d0,&local_d4,&local_d8);
    thunk_FUN_1001f009((int)hdc,&local_c8,local_d0,local_d4,local_d8);
    val_3 = thunk_FUN_1002421f(width,height);
    uval_2 = (uint32_t)(val_3 == width);
    val_3 = thunk_FUN_1002420d(width,height);
    thunk_FUN_1001f83a(hdc,&arg_2->left,local_9c,val_3,uval_2);
    if ((width == 0) && (uval_2 = thunk_FUN_1002430d(0,height), (uval_2 & 0x40000) != 0)) {
      SelectObject(hdc,DAT_1013e5e0);
      h = GetStockObject(5);
      SelectObject(hdc,h);
      Rectangle(hdc,arg_2->left,arg_2->top,arg_2->right,arg_2->bottom);
    }
    RestoreDC(hdc,local_a8);
  }
  return;
}


