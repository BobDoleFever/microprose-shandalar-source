/*
 * Decompiled function: thunk_FUN_1000e0da
 * Entry Point: 100013ac
 * Size: 5 bytes
 */
#include "deckdll.h"


void * thunk_FUN_1000e0da(int arg1,uint8_t *arg2)

{
  void *buf_ptr_1;
  int aiStack_c [2];
  
  aiStack_c[0] = thunk_FUN_1000e202(arg2);
  if ((*(int *)(arg1 + 0xc) == 0) || (**(int **)(arg1 + 0xc) != aiStack_c[0])) {
    buf_ptr_1 = bsearch(aiStack_c,*(void **)(arg1 + 8),*(size_t *)(arg1 + 4),0xc,
                     (_PtFuncCompare *)&LAB_100011d1);
    *(void **)(arg1 + 0xc) = buf_ptr_1;
  }
  else {
    buf_ptr_1 = *(void **)(arg1 + 0xc);
  }
  return buf_ptr_1;
}


