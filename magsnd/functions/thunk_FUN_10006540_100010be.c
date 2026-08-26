/*
 * Decompiled function: thunk_FUN_10006540
 * Entry Point: 100010be
 * Size: 5 bytes
 */
#include "magsnd.h"


void * __cdecl thunk_FUN_10006540(int *ptr_1,int32_t arg_2,int32_t *ptr_3,int32_t arg_4)

{
  void *ptr_1_00;
  int val_1;
  
  ptr_1_00 = operator_new(0x204);
  memset(ptr_1_00,0,0x204);
  *(int32_t *)((int)ptr_1_00 + 0xa8) = 0x14;
  *(int32_t *)((int)ptr_1_00 + 0xac) = arg_4;
  *(int32_t *)((int)ptr_1_00 + 0xb0) = arg_2;
  *(int32_t **)((int)ptr_1_00 + 0xb8) = ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x78) = *ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x7c) = ptr_3[1];
  *(int32_t *)((int)ptr_1_00 + 0x80) = ptr_3[2];
  *(int32_t *)((int)ptr_1_00 + 0x84) = ptr_3[3];
  *(int16_t *)((int)ptr_1_00 + 0x88) = *(int16_t *)(ptr_3 + 4);
  val_1 = (**(code **)(*ptr_1 + 0xc))(ptr_1,(int)ptr_1_00 + 0xa8,(int)ptr_1_00 + 0xbc,0);
  if (val_1 != 0) {
    operator_delete(ptr_1_00);
    ptr_1_00 = (void *)0x0;
  }
  return ptr_1_00;
}


