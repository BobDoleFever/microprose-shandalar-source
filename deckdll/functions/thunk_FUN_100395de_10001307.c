/*
 * Decompiled function: thunk_FUN_100395de
 * Entry Point: 10001307
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100395de(int arg_1,int arg_2,int arg_3)

{
  int *i_ptr_1;
  bool flag_2;
  int32_t uStack_10;
  int32_t uStack_c;
  
  uStack_c = 0;
  flag_2 = false;
  while ((uStack_c < *(int *)(arg_3 + 0xe14) && (!flag_2))) {
    if (*(int *)(arg_3 + uStack_c * 0xc) == arg_1) {
      flag_2 = true;
      if (*(int *)(arg_3 + 4 + uStack_c * 0xc) == arg_2) {
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
        for (uStack_10 = uStack_c; uStack_10 < *(int *)(arg_3 + 0xe14) + -1;
            uStack_10 = uStack_10 + 1) {
          *(int32_t *)(arg_3 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + (uStack_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 4 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + 4 + (uStack_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 8 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + 8 + (uStack_10 * 3 + 3) * 4);
        }
        *(int *)(arg_3 + 0xe14) = *(int *)(arg_3 + 0xe14) + -1;
      }
      else if (arg_2 < *(int *)(arg_3 + 4 + uStack_c * 0xc)) {
        i_ptr_1 = (int *)(arg_3 + 4 + uStack_c * 0xc);
        *i_ptr_1 = *i_ptr_1 - arg_2;
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
      }
      else {
        *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) - arg_2;
        arg_2 = arg_2 - *(int *)(arg_3 + 4 + uStack_c * 0xc);
        flag_2 = false;
        for (uStack_10 = uStack_c; uStack_10 < *(int *)(arg_3 + 0xe14) + -1;
            uStack_10 = uStack_10 + 1) {
          *(int32_t *)(arg_3 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + (uStack_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 4 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + 4 + (uStack_10 * 3 + 3) * 4);
          *(int32_t *)(arg_3 + 8 + uStack_10 * 0xc) =
               *(int32_t *)(arg_3 + 8 + (uStack_10 * 3 + 3) * 4);
        }
        *(int *)(arg_3 + 0xe14) = *(int *)(arg_3 + 0xe14) + -1;
      }
    }
    uStack_c = uStack_c + 1;
  }
  return;
}


