/*
 * Decompiled function: thunk_FUN_10001a02
 * Entry Point: 10001046
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_10001a02(void *this,int arg_2,int arg_3)

{
  int val_1;
  int32_t uStack_b4;
  int32_t uStack_b0;
  int32_t uStack_ac;
  int32_t uStack_a8;
  int32_t uStack_a4;
  int32_t uStack_a0;
  int32_t uStack_9c;
  int32_t uStack_98;
  uint8_t auStack_94 [20];
  uint32_t uStack_80;
  uint32_t uStack_7c;
  int iStack_8;
  
  if ((*(int *)((int)this + 0xc) != 0) || (*(int *)((int)this + 0x10) != 0)) {
    thunk_FUN_10001c16(this);
  }
  *(int32_t *)((int)this + 0x1c) = 0;
  *(int32_t *)((int)this + 0x18) = *(int32_t *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = arg_2;
  *(int32_t *)this = 0;
  *(int32_t *)((int)this + 0x74) = 0;
  iStack_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0xc,0x73646976,0);
  if (iStack_8 == -0x7ffbbf8d) {
    *(int32_t *)((int)this + 0xc) = 0;
    val_1 = -1;
  }
  else {
    iStack_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0x10,0x73647561,0);
    if (iStack_8 == -0x7ffbbf8d) {
      *(int32_t *)((int)this + 0x10) = 0;
    }
    else {
      uStack_b4 = 400;
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      uStack_a0 = 0;
      uStack_9c = 0;
      uStack_98 = 0x14;
      thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),arg_3 + 0x100,&uStack_b4);
    }
    AVIStreamInfoA(*(int32_t *)((int)this + 0xc),auStack_94,0x8c);
    *(float *)((int)this + 0x24) = (float)((float10)uStack_7c / (float10)uStack_80);
    *(int32_t *)((int)this + 0x20) = *(int32_t *)((int)this + 0x24);
    val_1 = thunk_FUN_1000785e(this);
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}


