/*
 * Decompiled function: thunk_FUN_1000715a
 * Entry Point: 10001203
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_1000715a(int arg_1)

{
  int32_t uval_1;
  uint8_t auStack_90 [28];
  int iStack_74;
  uint32_t uStack_70;
  int32_t uStack_6c;
  int iStack_68;
  int iStack_60;
  
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  if (*(int *)(arg_1 + 0x10) == 0) {
    uval_1 = 0xfffffff3;
  }
  else {
    AVIStreamInfoA(*(int32_t *)(arg_1 + 0x10),auStack_90,0x8c);
    *(int *)(arg_1 + 0x94) = iStack_68 * iStack_60;
    *(int *)(arg_1 + 0x90) = iStack_60;
    *(int *)(arg_1 + 0x7c) = iStack_74;
    *(uint32_t *)(arg_1 + 0x80) = iStack_74 + uStack_70 / *(uint32_t *)(arg_1 + 0x94);
    *(int32_t *)(arg_1 + 0x84) = uStack_6c;
    if (*(int *)(arg_1 + 0x84) < 0x20) {
      uval_1 = 0;
    }
    else {
      uval_1 = 0xfffffff5;
    }
  }
  return uval_1;
}


