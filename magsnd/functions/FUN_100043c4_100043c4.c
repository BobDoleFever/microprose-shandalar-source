/*
 * Decompiled function: FUN_100043c4
 * Entry Point: 100043c4
 * Size: 348 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100043c4(int arg1,int *arg2)

{
  int val_1;
  int32_t uval_2;
  uint8_t local_1c [4];
  int32_t local_18;
  int32_t local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_10 = *(int **)(arg1 + 0xbc);
  local_8 = local_10;
  val_1 = (**(code **)(*local_10 + 0x24))(local_10,local_1c);
  if (val_1 == 0) {
    if ((local_1c[0] & 2) == 0) {
      if ((local_1c[0] & 1) == 0) {
        *arg2 = (int)local_8;
        uval_2 = 0;
      }
      else {
        for (local_c = 0; local_14 = 0, local_c < 0x10; local_c = local_c + 1) {
          local_10 = *(int **)(arg1 + 0xc0 + local_c * 0xc);
          if (local_10 == (int *)0x0) {
            val_1 = (**(code **)(*DAT_1000ba90 + 0x14))(DAT_1000ba90,local_8,&local_18);
            if (val_1 != 0) {
              return 9;
            }
            *(int32_t *)(arg1 + 0xc0 + local_c * 0xc) = local_18;
            *arg2 = *(int *)(arg1 + 0xc0 + local_c * 0xc);
            return 0;
          }
          val_1 = (**(code **)(*local_10 + 0x24))(local_10,local_1c);
          if (val_1 != 0) {
            return 9;
          }
          if ((local_1c[0] & 1) == 0) {
            *arg2 = (int)local_10;
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


