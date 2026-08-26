/*
 * Decompiled function: FUN_10001f9d
 * Entry Point: 10001f9d
 * Size: 645 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_10001f9d(void *this,float arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  undefined3 extraout_var;
  uint8_t local_74 [4];
  int local_70;
  int local_6c;
  uint8_t local_4c [4];
  int local_48;
  int local_44;
  uint16_t local_3e;
  int local_38;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    thunk_FUN_1000b6ff(*(void **)this,local_74);
    thunk_FUN_1000b759(*(void **)this,local_4c);
    thunk_FUN_1000b3b1(*(void **)this,&local_24);
    thunk_FUN_1000b456(*(void **)this,&local_14);
    if (arg_3 == 0) {
      arg_3 = (uint32_t)local_3e;
    }
    if ((((arg_3 == 8) || (arg_3 == 0x10)) || (arg_3 == 0x18)) || (arg_3 == 0x20)) {
      if (0.0 < arg_2) {
        arg_5 = ftol();
        arg_6 = ftol();
      }
      local_3e = (uint16_t)arg_3;
      local_48 = arg_5;
      local_44 = arg_6;
      val_3 = ((int)(arg_6 + 3 + (arg_6 + 3 >> 0x1f & 3U)) >> 2) * arg_5 * arg_3 * 4;
      local_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      local_14 = local_24;
      local_c = local_24 + arg_5;
      local_10 = local_20;
      local_8 = local_20 + arg_6;
      val_3 = thunk_FUN_1000b83e(*(void **)this,(int)local_4c,local_24,local_20,local_c + local_24,
                                 local_20 + local_8);
      if (val_3 == 0) {
        thunk_FUN_1000b786(*(void **)this,local_4c);
        thunk_FUN_1000b4a9(*(void **)this,&local_14);
        thunk_FUN_1000b54e(*(void **)this,&local_14);
        if ((arg_4 != 0) &&
           (flag_1 = thunk_FUN_1000bd47(*(void **)this,arg_4), CONCAT31(extraout_var,flag_1) == 0)) {
          return 0xfffffffb;
        }
      }
      else {
        local_48 = local_70;
        local_44 = local_6c;
        val_3 = ((int)(local_6c + 3 + (local_6c + 3 >> 0x1f & 3U)) >> 2) * local_70 * arg_3 * 4;
        local_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
        val_3 = thunk_FUN_1000b83e(*(void **)this,(int)local_4c,local_24,local_20,
                                   local_1c + local_24,local_20 + local_18);
        if (val_3 != 0) {
          return 0xfffffffb;
        }
        thunk_FUN_1000b786(*(void **)this,local_4c);
        thunk_FUN_1000b4a9(*(void **)this,&local_24);
        thunk_FUN_1000b54e(*(void **)this,&local_14);
      }
      thunk_FUN_100027a0((int)this);
      uval_2 = 0;
    }
    else {
      uval_2 = 0xfffffffb;
    }
  }
  else {
    uval_2 = 0xfffffffc;
  }
  return uval_2;
}


