/*
 * Decompiled function: FUN_100391f0
 * Entry Point: 100391f0
 * Size: 236 bytes
 */
#include "deckdll.h"


void FUN_100391f0(int arg_1,int arg_2,int arg_3)

{
  int *i_ptr_1;
  bool flag_2;
  int local_c;
  
  local_c = 0;
  flag_2 = false;
  while ((local_c < *(int *)(arg_3 + 0xe14) && (!flag_2))) {
    if (*(int *)(arg_3 + local_c * 0xc) == arg_1) {
      i_ptr_1 = (int *)(arg_3 + 4 + local_c * 0xc);
      *i_ptr_1 = *i_ptr_1 + arg_2;
      *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) + arg_2;
      flag_2 = true;
    }
    local_c = local_c + 1;
  }
  if (!flag_2) {
    *(int *)(arg_3 + *(int *)(arg_3 + 0xe14) * 0xc) = arg_1;
    *(int *)(arg_3 + 4 + *(int *)(arg_3 + 0xe14) * 0xc) = arg_2;
    *(int32_t *)(arg_3 + 8 + *(int *)(arg_3 + 0xe14) * 0xc) = (&DAT_10176ab4)[arg_1 * 0x26];
    *(int *)(arg_3 + 0xe14) = *(int *)(arg_3 + 0xe14) + 1;
    *(int *)(arg_3 + 0xe10) = *(int *)(arg_3 + 0xe10) + arg_2;
  }
  return;
}


