/*
 * Decompiled function: thunk_FUN_100049cf
 * Entry Point: 10001159
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_100049cf(void *this,int arg_2,int arg_3)

{
  uint32_t arg_2_00;
  int32_t uStack_8;
  
  arg_2_00 = (uint32_t)*(uint8_t *)(arg_2 + 0x2d);
  if (arg_3 == 1) {
    if (*(int *)(arg_2 + arg_2_00 * 4) == 0) {
      thunk_FUN_10006d86(this,arg_2_00);
    }
    else {
      thunk_FUN_1000735d(this,arg_2_00);
    }
  }
  uStack_8 = 0;
  do {
    if (4 < uStack_8) {
LAB_10004ac8:
      thunk_FUN_10008419(this,arg_2);
      thunk_FUN_100080e7(this,arg_2);
      thunk_FUN_1000814f(this,arg_2);
      return 0;
    }
    if (*(uint8_t *)(uStack_8 + 0x28 + arg_2) < *(uint8_t *)(*(int *)this + 0x28 + uStack_8)) {
      thunk_FUN_10006d86(this,uStack_8);
      if (*(int *)(arg_2 + uStack_8 * 4) != 0) {
        thunk_FUN_1000735d(this,uStack_8);
      }
      *(int32_t *)(*(int *)this + uStack_8 * 4) = 0xffffffff;
      *(int32_t *)(*(int *)this + 0x14 + uStack_8 * 4) = 0xffffffff;
      goto LAB_10004ac8;
    }
    uStack_8 = uStack_8 + 1;
  } while( true );
}


