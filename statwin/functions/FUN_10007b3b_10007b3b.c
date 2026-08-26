/*
 * Decompiled function: FUN_10007b3b
 * Entry Point: 10007b3b
 * Size: 290 bytes
 */
#include "statwin.h"


int __thiscall FUN_10007b3b(void *this,int *ptr_2,int arg_3)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t *unaff_FS_OFFSET;
  int32_t local_24;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10007c59;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((*(int *)((int)this + 0x10) != 0) && (*(void **)((int)this + 0x10) != (void *)0x0)) {
    thunk_FUN_10004250(*(void **)((int)this + 0x10),1);
  }
  *(int32_t *)((int)this + 0x10) = 0;
  this_00 = operator_new(0x18);
  local_8 = 0;
  if (this_00 == (CPrintPreviewState *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = CPrintPreviewState::CPrintPreviewState(this_00);
  }
  local_8 = 0xffffffff;
  *(int32_t *)((int)this + 0x10) = local_24;
  thunk_FUN_10009e72(*(void **)((int)this + 0x10),ptr_2[2],ptr_2[3],0x18);
  val_1 = thunk_FUN_10005d98(this,arg_3,ptr_2);
  if ((val_1 == 0) && (val_1 = thunk_FUN_10006212(this,arg_3,ptr_2), val_1 == 0)) {
    val_1 = 0;
  }
  *unaff_FS_OFFSET = local_10;
  return val_1;
}


