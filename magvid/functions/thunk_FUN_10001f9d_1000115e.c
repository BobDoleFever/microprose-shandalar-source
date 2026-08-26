/*
 * Decompiled function: thunk_FUN_10001f9d
 * Entry Point: 1000115e
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __thiscall
thunk_FUN_10001f9d(void *this,float arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  undefined3 extraout_var;
  uint8_t auStack_74 [4];
  int iStack_70;
  int iStack_6c;
  uint8_t auStack_4c [4];
  int iStack_48;
  int iStack_44;
  uint16_t uStack_3e;
  int iStack_38;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    thunk_FUN_1000b6ff(*(void **)this,auStack_74);
    thunk_FUN_1000b759(*(void **)this,auStack_4c);
    thunk_FUN_1000b3b1(*(void **)this,&iStack_24);
    thunk_FUN_1000b456(*(void **)this,&iStack_14);
    if (arg_3 == 0) {
      arg_3 = (uint32_t)uStack_3e;
    }
    if ((((arg_3 == 8) || (arg_3 == 0x10)) || (arg_3 == 0x18)) || (arg_3 == 0x20)) {
      if (0.0 < arg_2) {
        arg_5 = ftol();
        arg_6 = ftol();
      }
      uStack_3e = (uint16_t)arg_3;
      iStack_48 = arg_5;
      iStack_44 = arg_6;
      val_3 = ((int)(arg_6 + 3 + (arg_6 + 3 >> 0x1f & 3U)) >> 2) * arg_5 * arg_3 * 4;
      iStack_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      iStack_14 = iStack_24;
      iStack_c = iStack_24 + arg_5;
      iStack_10 = iStack_20;
      iStack_8 = iStack_20 + arg_6;
      val_3 = thunk_FUN_1000b83e(*(void **)this,(int)auStack_4c,iStack_24,iStack_20,
                                 iStack_c + iStack_24,iStack_20 + iStack_8);
      if (val_3 == 0) {
        thunk_FUN_1000b786(*(void **)this,auStack_4c);
        thunk_FUN_1000b4a9(*(void **)this,&iStack_14);
        thunk_FUN_1000b54e(*(void **)this,&iStack_14);
        if ((arg_4 != 0) &&
           (flag_1 = thunk_FUN_1000bd47(*(void **)this,arg_4), CONCAT31(extraout_var,flag_1) == 0)) {
          return 0xfffffffb;
        }
      }
      else {
        iStack_48 = iStack_70;
        iStack_44 = iStack_6c;
        val_3 = ((int)(iStack_6c + 3 + (iStack_6c + 3 >> 0x1f & 3U)) >> 2) * iStack_70 * arg_3 * 4;
        iStack_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
        val_3 = thunk_FUN_1000b83e(*(void **)this,(int)auStack_4c,iStack_24,iStack_20,
                                   iStack_1c + iStack_24,iStack_20 + iStack_18);
        if (val_3 != 0) {
          return 0xfffffffb;
        }
        thunk_FUN_1000b786(*(void **)this,auStack_4c);
        thunk_FUN_1000b4a9(*(void **)this,&iStack_24);
        thunk_FUN_1000b54e(*(void **)this,&iStack_14);
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


