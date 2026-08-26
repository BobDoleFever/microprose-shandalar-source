/*
 * Decompiled function: thunk_FUN_1000ad09
 * Entry Point: 100011ef
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall
thunk_FUN_1000ad09(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,
                  int arg_8)

{
  int16_t uval_1;
  int val_2;
  int16_t extraout_var;
  uint32_t uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int32_t uStack_20;
  int iStack_18;
  void *pvStack_14;
  void *pvStack_10;
  uint32_t uStack_c;
  uint32_t uStack_8;
  
  if (arg_7 < 0) {
    arg_5 = arg_5 + arg_7;
    arg_3 = arg_3 - arg_7;
    arg_7 = 0;
  }
  else {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_5 < arg_7) {
      val_2 = CFontDialog::GetWeight(this);
      if (val_2 <= arg_7) {
        return;
      }
      val_2 = CFontDialog::GetWeight(this);
      arg_5 = val_2 - arg_7;
    }
  }
  if (arg_3 < 0) {
    arg_5 = arg_5 + arg_3;
    arg_7 = arg_7 - arg_3;
    arg_3 = 0;
  }
  else if ((0 < arg_5) && (val_2 = CFontDialog::GetWeight(ptr_2), val_2 - arg_5 < arg_3)) {
    val_2 = CFontDialog::GetWeight(ptr_2);
    arg_5 = val_2 - arg_3;
  }
  if (arg_8 < 0) {
    arg_6 = arg_6 + arg_8;
    arg_4 = arg_4 - arg_8;
    arg_8 = 0;
  }
  else {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_6 < arg_8) {
      val_2 = CFontDialog::GetWeight(this);
      if (val_2 <= arg_8) {
        return;
      }
      val_2 = CFontDialog::GetWeight(this);
      arg_6 = val_2 - arg_8;
    }
  }
  if (arg_4 < 0) {
    arg_6 = arg_6 + arg_4;
    arg_8 = arg_8 - arg_4;
    arg_4 = 0;
  }
  else if ((0 < arg_6) && (val_2 = CFontDialog::GetWeight(ptr_2), val_2 - arg_6 < arg_4)) {
    val_2 = CFontDialog::GetWeight(ptr_2);
    arg_6 = val_2 - arg_4;
  }
  if ((0 < arg_5) && (0 < arg_6)) {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_8 <= arg_6) {
      val_2 = CFontDialog::GetWeight(this);
      arg_6 = val_2 - arg_8;
    }
    val_2 = CFontDialog::GetWeight(ptr_2);
    if (val_2 - arg_4 <= arg_6) {
      val_2 = CFontDialog::GetWeight(ptr_2);
      arg_6 = val_2 - arg_4;
    }
    pvStack_14 = (void *)thunk_FUN_1000ac3f(this,arg_7,arg_8 + arg_6 + -1);
    pvStack_10 = (void *)thunk_FUN_1000ac3f(ptr_2,arg_3,arg_6 + arg_4 + -1);
    uStack_8 = thunk_FUN_1000b760((int)this);
    uStack_c = thunk_FUN_1000b760((int)ptr_2);
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_7 <= arg_5) {
      val_2 = CFontDialog::GetWeight(this);
      arg_5 = val_2 - arg_7;
    }
    val_2 = CFontDialog::GetWeight(ptr_2);
    if (val_2 - arg_3 <= arg_5) {
      val_2 = CFontDialog::GetWeight(ptr_2);
      arg_5 = val_2 - arg_3;
    }
    if (0 < arg_5) {
      uval_1 = thunk_FUN_1000b6e0((int)this);
      if (CONCAT22(extraout_var,uval_1) < 9) {
        val_2 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_5;
        while (arg_6 != 0) {
          for (iStack_18 = 0; iStack_18 < (int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3;
              iStack_18 = iStack_18 + 1) {
            if ((*(int *)((int)this + 0x10) == 0) ||
               ((uint32_t)*(uint8_t *)(iStack_18 + (int)pvStack_14) != **(uint32_t **)((int)this + 0x10))) {
              *(uint8_t *)(iStack_18 + (int)pvStack_10) =
                   *(uint8_t *)(iStack_18 + (int)pvStack_14);
            }
          }
          pvStack_14 = (void *)((int)pvStack_14 + uStack_8);
          pvStack_10 = (void *)((int)pvStack_10 + uStack_c);
          arg_6 = arg_6 + -1;
        }
      }
      else {
        val_2 = (int)(uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) >> 3;
        iStack_28 = val_2;
        uStack_20 = 0xffffff;
        if (*(int *)((int)this + 0x10) == 0) {
          while (arg_6 != 0) {
            memmove(pvStack_10,pvStack_14,val_2 * arg_5);
            pvStack_14 = (void *)((int)pvStack_14 + uStack_8);
            pvStack_10 = (void *)((int)pvStack_10 + uStack_c);
            arg_6 = arg_6 + -1;
          }
        }
        else {
          while (arg_6 != 0) {
            iStack_30 = 0;
            for (iStack_24 = 0; iStack_24 < arg_5; iStack_24 = iStack_24 + 1) {
              uStack_34 = *(uint32_t *)(iStack_30 + (int)pvStack_14) & 0xffffff;
              if (**(uint32_t **)((int)this + 0x10) != uStack_34) {
                for (iStack_2c = 0; iStack_2c < val_2; iStack_2c = iStack_2c + 1) {
                  *(uint8_t *)(iStack_30 + iStack_2c + (int)pvStack_10) =
                       *(uint8_t *)((int)&uStack_34 + iStack_2c);
                }
              }
              iStack_30 = iStack_30 + val_2;
            }
            pvStack_14 = (void *)((int)pvStack_14 + uStack_8);
            pvStack_10 = (void *)((int)pvStack_10 + uStack_c);
            arg_6 = arg_6 + -1;
          }
        }
      }
    }
  }
  return;
}


