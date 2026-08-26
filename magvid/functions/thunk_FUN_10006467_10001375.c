/*
 * Decompiled function: thunk_FUN_10006467
 * Entry Point: 10001375
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10006467(LPARAM *ptr_1)

{
  void *this;
  int val_1;
  bool flag_2;
  undefined3 extraout_var;
  int16_t *ptr_1_00;
  int val_3;
  uint8_t *puStack_18;
  int iStack_14;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if ((CONCAT31(extraout_var,flag_2) != 0) &&
       ((*(int *)((int)this + 4) != 0 &&
        (ptr_1_00 = operator_new(0x408), ptr_1_00 != (int16_t *)0x0)))) {
      puStack_18 = (uint8_t *)thunk_FUN_10007080(*(int *)((int)this + 4));
      for (iStack_14 = 0; iStack_14 < 0x100; iStack_14 = iStack_14 + 1) {
        *(uint8_t *)(ptr_1_00 + iStack_14 * 2 + 2) = puStack_18[2];
        *(uint8_t *)((int)ptr_1_00 + iStack_14 * 4 + 5) = puStack_18[1];
        *(uint8_t *)(ptr_1_00 + iStack_14 * 2 + 3) = *puStack_18;
        *(uint8_t *)((int)ptr_1_00 + iStack_14 * 4 + 7) = 4;
        puStack_18 = puStack_18 + 4;
      }
      *ptr_1_00 = 0x300;
      ptr_1_00[1] = 0x100;
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      val_3 = thunk_FUN_10002227(this,(int)ptr_1_00);
      if (val_3 == 0) {
        thunk_FUN_10005ce8((int)ptr_1,0);
      }
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      if (ptr_1_00 != (int16_t *)0x0) {
        operator_delete(ptr_1_00);
      }
    }
  }
  return;
}


