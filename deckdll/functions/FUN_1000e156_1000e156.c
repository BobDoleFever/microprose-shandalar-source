/*
 * Decompiled function: FUN_1000e156
 * Entry Point: 1000e156
 * Size: 172 bytes
 */
#include "deckdll.h"


size_t FUN_1000e156(int arg_1,int32_t arg_2,int *arg_3)

{
  int32_t *arg1;
  int val_1;
  size_t len_2;
  void *buf_ptr_3;
  
  arg1 = (int32_t *)(&DAT_102050b0 + (arg_1 + -1) * 0x114);
  val_1 = thunk_FUN_1000e0da((int)arg1,arg_2);
  if (val_1 == 0) {
    len_2 = 0xffffffff;
  }
  else {
    if (*arg_3 == 0) {
      buf_ptr_3 = malloc(*(int *)(val_1 + 8) + 0x10);
      *arg_3 = (int)buf_ptr_3;
    }
    fseek((FILE *)*arg1,*(long *)(val_1 + 4),0);
    len_2 = fread((void *)*arg_3,1,*(size_t *)(val_1 + 8),(FILE *)*arg1);
  }
  return len_2;
}


