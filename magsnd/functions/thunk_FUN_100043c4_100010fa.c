/*
 * Decompiled function: thunk_FUN_100043c4
 * Entry Point: 100010fa
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_100043c4(int arg1,int *arg2)

{
  int val_1;
  int32_t uval_2;
  uint8_t abStack_1c [4];
  int32_t uStack_18;
  int32_t uStack_14;
  int *piStack_10;
  int iStack_c;
  int *piStack_8;
  
  piStack_10 = *(int **)(arg1 + 0xbc);
  piStack_8 = piStack_10;
  val_1 = (**(code **)(*piStack_10 + 0x24))(piStack_10,abStack_1c);
  if (val_1 == 0) {
    if ((abStack_1c[0] & 2) == 0) {
      if ((abStack_1c[0] & 1) == 0) {
        *arg2 = (int)piStack_8;
        uval_2 = 0;
      }
      else {
        for (iStack_c = 0; uStack_14 = 0, iStack_c < 0x10; iStack_c = iStack_c + 1) {
          piStack_10 = *(int **)(arg1 + 0xc0 + iStack_c * 0xc);
          if (piStack_10 == (int *)0x0) {
            val_1 = (**(code **)(*DAT_1000ba90 + 0x14))(DAT_1000ba90,piStack_8,&uStack_18);
            if (val_1 != 0) {
              return 9;
            }
            *(int32_t *)(arg1 + 0xc0 + iStack_c * 0xc) = uStack_18;
            *arg2 = *(int *)(arg1 + 0xc0 + iStack_c * 0xc);
            return 0;
          }
          val_1 = (**(code **)(*piStack_10 + 0x24))(piStack_10,abStack_1c);
          if (val_1 != 0) {
            return 9;
          }
          if ((abStack_1c[0] & 1) == 0) {
            *arg2 = (int)piStack_10;
            return 0;
          }
        }
        uval_2 = 9;
      }
    }
    else {
      uval_2 = 9;
    }
  }
  else {
    uval_2 = 9;
  }
  return uval_2;
}


