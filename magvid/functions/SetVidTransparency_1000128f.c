/*
 * Decompiled function: SetVidTransparency
 * Entry Point: 1000128f
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidTransparency(int arg1,int arg2)

{
  int *i_ptr_1;
  int32_t uval_2;
  
                    /* 0x128f  19  SetVidTransparency */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 0;
  }
  else {
    i_ptr_1 = *(int **)(*(int *)(&DAT_10010868 + arg1 * 4) + 8);
    if (i_ptr_1 == (int *)0x0) {
      uval_2 = 2;
    }
    else if (*i_ptr_1 == 0) {
      uval_2 = 2;
    }
    else {
      thunk_FUN_1000bbec((void *)*i_ptr_1,arg2);
      uval_2 = 0;
    }
  }
  return uval_2;
}


