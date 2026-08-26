/*
 * Decompiled function: thunk_FUN_10004512
 * Entry Point: 10001208
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_10004512(void *this,int32_t *ptr_2,int arg_3)

{
  void *buf_ptr_1;
  CPrintPreviewState *this_00;
  int32_t *u_ptr_2;
  int val_3;
  int32_t *puVar4;
  int32_t *puVar5;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_138;
  char acStack_12c [256];
  CPrintPreviewState aCStack_2c [24];
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int iStack_8;
  
  iStack_8 = 0xffffffff;
  puStack_c = &LAB_100049b4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_2c);
  iStack_8 = 0;
  buf_ptr_1 = operator_new(0x34);
  *(void **)this = buf_ptr_1;
  *(int *)((int)this + 4) = arg_3;
  *(int32_t *)((int)this + 4) = 2;
  *(int32_t *)((int)this + 0x1c) = 0;
  this_00 = operator_new(0x18);
  iStack_8._0_1_ = 1;
  if (this_00 == (CPrintPreviewState *)0x0) {
    uStack_138 = 0;
  }
  else {
    uStack_138 = CPrintPreviewState::CPrintPreviewState(this_00);
  }
  iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
  *(int32_t *)((int)this + 0xc) = uStack_138;
  u_ptr_2 = ptr_2;
  puVar4 = *(int32_t **)this;
  for (val_3 = 0xd; val_3 != 0; val_3 = val_3 + -1) {
    *puVar4 = *u_ptr_2;
    u_ptr_2 = u_ptr_2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_1000432f(acStack_12c,PTR_s_statwin__10012ac0,PTR_s_wizbg_bmp_10012ac8);
  val_3 = (**(code **)**(int32_t **)((int)this + 0xc))(0,acStack_12c,0x18);
  if (val_3 != 0) {
    thunk_FUN_10007805((int)this);
    iStack_14 = thunk_FUN_1000a9b8(*(int *)((int)this + 0xc));
    if (iStack_14 == 0) {
      buf_ptr_1 = operator_new(0x2c);
      *(void **)((int)this + 8) = buf_ptr_1;
    }
    else {
      u_ptr_2 = (int32_t *)thunk_FUN_100042a0(*(int *)((int)this + 0xc));
      buf_ptr_1 = operator_new(iStack_14 * 4 + 0x28);
      *(void **)((int)this + 8) = buf_ptr_1;
      if (*(int *)((int)this + 8) != 0) {
        puVar4 = u_ptr_2;
        puVar5 = *(int32_t **)((int)this + 8);
        for (val_3 = 10; val_3 != 0; val_3 = val_3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        memcpy((void *)(*(int *)((int)this + 8) + 0x28),u_ptr_2 + 10,iStack_14 << 2);
      }
    }
    u_ptr_2 = (int32_t *)thunk_FUN_100042a0(*(int *)((int)this + 0xc));
    puVar4 = *(int32_t **)((int)this + 8);
    for (val_3 = 0xb; val_3 != 0; val_3 = val_3 + -1) {
      *puVar4 = *u_ptr_2;
      u_ptr_2 = u_ptr_2 + 1;
      puVar4 = puVar4 + 1;
    }
    switch(arg_3) {
    case 0:
      thunk_FUN_10006870(this,(int)ptr_2);
      thunk_FUN_10006b3f(this,(int)ptr_2);
      thunk_FUN_100059af(this,(int)ptr_2);
      thunk_FUN_100065ce(this);
      break;
    case 1:
      iStack_8 = 0xffffffff;
      FUN_100049ab();
      FUN_100049be();
      return;
    case 2:
      if (4 < *(uint8_t *)(*(int *)this + 0x2d)) {
        iStack_8 = 0xffffffff;
        FUN_100049ab();
        FUN_100049be();
        return;
      }
      thunk_FUN_10006b3f(this,(int)ptr_2);
      thunk_FUN_10006870(this,(int)ptr_2);
      thunk_FUN_100059af(this,(int)ptr_2);
      thunk_FUN_100065ce(this);
      break;
    case 3:
      iStack_8 = 0xffffffff;
      FUN_100049ab();
      FUN_100049be();
      return;
    default:
      *(int32_t *)((int)this + 4) = 0;
      thunk_FUN_10006870(this,(int)ptr_2);
      thunk_FUN_100059af(this,(int)ptr_2);
      thunk_FUN_100065ce(this);
    }
    thunk_FUN_10004afa(this);
    *(int32_t *)((int)this + 0x20) = 1;
    if (*(void **)((int)this + 0xc) != (void *)0x0) {
      thunk_FUN_10004250(*(void **)((int)this + 0xc),1);
    }
    *(int32_t *)((int)this + 0xc) = 0;
    operator_delete(*(void **)this);
    *(int32_t *)this = 0;
    if ((*(int *)((int)this + 0x10) != 0) && (*(void **)((int)this + 0x10) != (void *)0x0)) {
      thunk_FUN_10004250(*(void **)((int)this + 0x10),1);
    }
    *(int32_t *)((int)this + 0x10) = 0;
    iStack_8 = 0xffffffff;
    FUN_100049ab();
    FUN_100049be();
    return;
  }
  iStack_8 = 0xffffffff;
  FUN_100049ab();
  FUN_100049be();
  return;
}


