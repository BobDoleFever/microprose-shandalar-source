/*
 * Decompiled function: FUN_100395de
 * Entry Point: 100395de
 * Size: 498 bytes
 */
#include "deckdll.h"


void FUN_100395de(int arg_1,int arg_2,int arg_3)

{
  int *i_ptr_1;
  bool flag_2;
  int32_t local_10;
  int32_t local_c;
  
  local_c = 0;
  flag_2 = false;
  while ((local_c < *(int *)(arg_3 + 0xe14) && (!flag_2))) {
    if (*(int *)(arg_3 + local_c * 0xc) == arg_1) {
      flag_2 = true;
      if (*(int *)(arg_3 + 4 + local_c * 0xc) == arg_2) {
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
        for (local_10 = local_c; local_10 < *(int *)(arg_3 + 0xe14) + -1; local_10 = local_10 + 1) {
          *(int32_t *)(arg_3 + local_10 * 0xc) = *(int32_t *)(arg_3 + (local_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 4 + local_10 * 0xc) =
               *(int32_t *)(arg_3 + 4 + (local_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 8 + local_10 * 0xc) =
               *(int32_t *)(arg_3 + 8 + (local_10 * 3 + 3) * 4);
        }
        *(int *)(arg_3 + 0xe14) = *(int *)(arg_3 + 0xe14) + -1;
      }
      else if (arg_2 < *(int *)(arg_3 + 4 + local_c * 0xc)) {
        i_ptr_1 = (int *)(arg_3 + 4 + local_c * 0xc);
        *i_ptr_1 = *i_ptr_1 - arg_2;
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
      }
      else {
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
        arg_2 = arg_2 - *(int *)(arg_3 + 4 + local_c * 0xc);
        flag_2 = false;
        for (local_10 = local_c; local_10 < *(int *)(arg_3 + 0xe14) + -1; local_10 = local_10 + 1) {
          *(int32_t *)(arg_3 + local_10 * 0xc) = *(int32_t *)(arg_3 + (local_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 4 + local_10 * 0xc) =
               *(int32_t *)(arg_3 + 4 + (local_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 8 + local_10 * 0xc) =
               *(int32_t *)(arg_3 + 8 + (local_10 * 3 + 3) * 4);
        }
        *(int *)(arg_3 + 0xe14) = *(int *)(arg_3 + 0xe14) + -1;
      }
    }
    local_c = local_c + 1;
  }
  return;
}


