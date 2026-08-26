/*
 * Decompiled function: thunk_FUN_10006b3f
 * Entry Point: 100010c3
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_10006b3f(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t *unaff_FS_OFFSET;
  int *piStack_130;
  char acStack_128 [256];
  int32_t uStack_28;
  int32_t uStack_24;
  int32_t uStack_20;
  int32_t uStack_1c;
  int *piStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10006ce6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  for (iStack_14 = 0; iStack_14 < 5; iStack_14 = iStack_14 + 1) {
    if (*(int *)(arg_2 + iStack_14 * 4) != 0) {
      this_00 = operator_new(0x18);
      uStack_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        piStack_130 = (int *)0x0;
      }
      else {
        piStack_130 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      uStack_8 = 0xffffffff;
      piStack_18 = piStack_130;
      thunk_FUN_1000432f(acStack_128,PTR_s_statwin__10012ac0,"wht-sprt.bmp" + iStack_14 * 0x110);
      val_1 = (**(code **)*piStack_18)(0,acStack_128,0x18);
      if (val_1 == 0) break;
      val_1 = iStack_14 * 0x110;
      uStack_28 = *(int32_t *)(&DAT_1000ed78 + val_1);
      uStack_24 = *(int32_t *)(&DAT_1000ed7c + val_1);
      uStack_20 = *(int32_t *)(&DAT_1000ed80 + val_1);
      uStack_1c = *(int32_t *)(&DAT_1000ed84 + val_1);
      thunk_FUN_10004200(piStack_18,0xff00);
      (**(code **)(*piStack_18 + 0x18))
                (*(int32_t *)((int)this + 0xc),uStack_28,uStack_24,uStack_20,uStack_1c,0,0);
      if (piStack_18 != (int *)0x0) {
        thunk_FUN_10004250(piStack_18,1);
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}


