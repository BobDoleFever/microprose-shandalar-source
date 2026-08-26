/*
 * Decompiled function: FUN_10009699
 * Entry Point: 10009699
 * Size: 1113 bytes
 */
#include "magvid.h"


void __thiscall
FUN_10009699(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,
            int arg_8)

{
  int16_t uval_1;
  int val_2;
  int16_t extraout_var;
  uint32_t local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int32_t local_20;
  int local_18;
  void *local_14;
  void *local_10;
  uint32_t local_c;
  uint32_t local_8;
  
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
    local_14 = (void *)thunk_FUN_100095cf(this,arg_7,arg_8 + arg_6 + -1);
    local_10 = (void *)thunk_FUN_100095cf(ptr_2,arg_3,arg_6 + arg_4 + -1);
    local_8 = thunk_FUN_1000a200((int)this);
    local_c = thunk_FUN_1000a200((int)ptr_2);
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
      uval_1 = thunk_FUN_1000a130((int)this);
      if (CONCAT22(extraout_var,uval_1) < 9) {
        val_2 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_5;
        while (arg_6 != 0) {
          for (local_18 = 0; local_18 < (int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3;
              local_18 = local_18 + 1) {
            if ((*(int *)((int)this + 0x10) == 0) ||
               ((uint32_t)*(uint8_t *)(local_18 + (int)local_14) != **(uint32_t **)((int)this + 0x10))) {
              *(uint8_t *)(local_18 + (int)local_10) = *(uint8_t *)(local_18 + (int)local_14);
            }
          }
          local_14 = (void *)((int)local_14 + local_8);
          local_10 = (void *)((int)local_10 + local_c);
          arg_6 = arg_6 + -1;
        }
      }
      else {
        val_2 = (int)(uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) >> 3;
        local_28 = val_2;
        local_20 = 0xffffff;
        if (*(int *)((int)this + 0x10) == 0) {
          while (arg_6 != 0) {
            memmove(local_10,local_14,val_2 * arg_5);
            local_14 = (void *)((int)local_14 + local_8);
            local_10 = (void *)((int)local_10 + local_c);
            arg_6 = arg_6 + -1;
          }
        }
        else {
          while (arg_6 != 0) {
            local_30 = 0;
            for (local_24 = 0; local_24 < arg_5; local_24 = local_24 + 1) {
              local_34 = *(uint32_t *)(local_30 + (int)local_14) & 0xffffff;
              if (**(uint32_t **)((int)this + 0x10) != local_34) {
                for (local_2c = 0; local_2c < val_2; local_2c = local_2c + 1) {
                  *(uint8_t *)(local_30 + local_2c + (int)local_10) =
                       *(uint8_t *)((int)&local_34 + local_2c);
                }
              }
              local_30 = local_30 + val_2;
            }
            local_14 = (void *)((int)local_14 + local_8);
            local_10 = (void *)((int)local_10 + local_c);
            arg_6 = arg_6 + -1;
          }
        }
      }
    }
  }
  return;
}


