/*
 * Decompiled function: thunk_FUN_1000af14
 * Entry Point: 100010dc
 * Size: 5 bytes
 */
#include "magvid.h"


DWORD __thiscall thunk_FUN_1000af14(void *this,int32_t arg_2,int32_t arg_3)

{
  DWORD DVar1;
  int32_t uval_2;
  BOOL BVar3;
  int val_4;
  int32_t uStack_14;
  
  if (*(int *)((int)this + 0x10) == 0) {
    DVar1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      uStack_14 = *(int32_t *)((int)this + 400);
    }
    else {
      uStack_14 = *(int32_t *)((int)this + 0x19c);
    }
    if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
      (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                (*(int32_t *)((int)this + 0x17c),*(int32_t *)((int)this + 0x16c),
                 *(int32_t *)((int)this + 0x170),*(int32_t *)((int)this + 0x174),
                 *(int32_t *)((int)this + 0x178),
                 *(int *)((int)this + 0x16c) + *(int *)((int)this + 0x3c),
                 *(int *)((int)this + 0x170) + *(int *)((int)this + 0x40));
    }
    DVar1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),uStack_14,0,0,
                         *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38));
    if (DVar1 == 0) {
      if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
        memcpy((void *)((int)this + 0x16c),(void *)((int)this + 0x15c),0x10);
      }
      if (*(int *)((int)this + 0x184) != 0) {
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 0xc))(0,0);
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 8))(uval_2);
        (**(code **)(**(int **)((int)this + 0x184) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,uval_2);
      }
      if (DAT_100275d0 == 0) {
        if ((*(int *)((int)this + 0x44) == *(int *)((int)this + 0x34)) &&
           (*(int *)((int)this + 0x48) == *(int *)((int)this + 0x38))) {
          BVar3 = BitBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x4c),
                         *(int *)((int)this + 0x50),*(int *)((int)this + 0x54),
                         *(int *)((int)this + 0x58),*(HDC *)((int)this + 0x1a0),0,0,0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        else {
          BVar3 = StretchBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x3c),
                             *(int *)((int)this + 0x40),*(int *)((int)this + 0x44),
                             *(int *)((int)this + 0x48),*(HDC *)((int)this + 0x1a0),
                             *(int *)((int)this + 0x2c),*(int *)((int)this + 0x30),
                             *(int *)((int)this + 0x34),*(int *)((int)this + 0x38),0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        GdiFlush();
      }
      else {
        val_4 = DrawDibDraw(*(int32_t *)((int)this + 8),*(int32_t *)((int)this + 4),
                            *(int32_t *)((int)this + 0x3c),*(int32_t *)((int)this + 0x40),
                            *(int32_t *)((int)this + 0x44),*(int32_t *)((int)this + 0x48),
                            *(int32_t *)((int)this + 0x18),uStack_14,0,0,
                            *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        if (val_4 == 0) {
          return 0;
        }
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}


