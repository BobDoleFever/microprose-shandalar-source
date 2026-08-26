/*
 * Decompiled function: thunk_FUN_10009e72
 * Entry Point: 10001195
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10009e72(void *this,int y,int width,int height)

{
  int32_t *u_ptr_1;
  void *buf_ptr_2;
  int32_t uval_3;
  size_t _Size;
  int iStack_14;
  uint8_t *puStack_10;
  
  if (*(int *)((int)this + 4) != 0) {
    free(*(void **)((int)this + 4));
  }
  if (*(int *)((int)this + 8) != 0) {
    free(*(void **)((int)this + 8));
  }
  if (height == 8) {
    buf_ptr_2 = malloc(0x428);
    *(void **)((int)this + 4) = buf_ptr_2;
  }
  else {
    buf_ptr_2 = malloc(0x28);
    *(void **)((int)this + 4) = buf_ptr_2;
  }
  if (*(int *)((int)this + 4) == 0) {
    uval_3 = 0;
  }
  else {
    _Size = (((int)(height * y + (height * y >> 0x1f & 7U)) >> 3) + 5U & 0xfffffffc) * width;
    buf_ptr_2 = malloc(_Size);
    *(void **)((int)this + 8) = buf_ptr_2;
    if (*(int *)((int)this + 8) == 0) {
      free(*(void **)((int)this + 4));
      *(int32_t *)((int)this + 4) = 0;
      uval_3 = 0;
    }
    else {
      u_ptr_1 = *(int32_t **)((int)this + 4);
      *u_ptr_1 = 0x28;
      u_ptr_1[1] = y;
      u_ptr_1[2] = width;
      *(int16_t *)(u_ptr_1 + 3) = 1;
      *(short *)((int)u_ptr_1 + 0xe) = (short)height;
      u_ptr_1[4] = 0;
      u_ptr_1[5] = 0;
      u_ptr_1[6] = 0;
      u_ptr_1[7] = 0;
      u_ptr_1[8] = 0;
      u_ptr_1[9] = 0;
      if (height < 9) {
        puStack_10 = (uint8_t *)thunk_FUN_10009530((int)this);
        for (iStack_14 = 0; iStack_14 < 0x100; iStack_14 = iStack_14 + 1) {
          puStack_10[2] = (uint8_t)iStack_14;
          puStack_10[1] = puStack_10[2];
          *puStack_10 = puStack_10[1];
          puStack_10[3] = 0;
          puStack_10 = puStack_10 + 4;
        }
      }
      memset(*(void **)((int)this + 8),0,_Size);
      uval_3 = 1;
    }
  }
  return uval_3;
}


