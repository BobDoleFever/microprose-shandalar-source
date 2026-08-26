/*
 * Decompiled function: FUN_1000715a
 * Entry Point: 1000715a
 * Size: 222 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_1000715a(int arg_1)

{
  int32_t uval_1;
  uint8_t local_90 [28];
  int local_74;
  uint32_t local_70;
  int32_t local_6c;
  int local_68;
  int local_60;
  
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  if (*(int *)(arg_1 + 0x10) == 0) {
    uval_1 = 0xfffffff3;
  }
  else {
    AVIStreamInfoA(*(int32_t *)(arg_1 + 0x10),local_90,0x8c);
    *(int *)(arg_1 + 0x94) = local_68 * local_60;
    *(int *)(arg_1 + 0x90) = local_60;
    *(int *)(arg_1 + 0x7c) = local_74;
    *(uint32_t *)(arg_1 + 0x80) = local_74 + local_70 / *(uint32_t *)(arg_1 + 0x94);
    *(int32_t *)(arg_1 + 0x84) = local_6c;
    if (*(int *)(arg_1 + 0x84) < 0x20) {
      uval_1 = 0;
    }
    else {
      uval_1 = 0xfffffff5;
    }
  }
  return uval_1;
}


