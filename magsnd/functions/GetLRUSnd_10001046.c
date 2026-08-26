/*
 * Decompiled function: GetLRUSnd
 * Entry Point: 10001046
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl GetLRUSnd(int *ptr_1,int arg_2,int arg_3)

{
  int iStack_14;
  int iStack_10;
  uint32_t uStack_c;
  int32_t uStack_8;
  
                    /* 0x1046  27  GetLRUSnd */
  uStack_8 = 0;
  uStack_c = 0xffffffff;
  if (((arg_3 == 0) || (arg_3 <= arg_2)) || (0xff < arg_3)) {
    iStack_10 = 0;
    arg_3 = 0xff;
  }
  else {
    iStack_10 = arg_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  do {
    if (arg_3 <= iStack_10) {
LAB_100035b3:
      *ptr_1 = iStack_14;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      return uStack_8;
    }
    if (*(int *)(&DAT_1000a648 + iStack_10 * 4) == 0) {
      iStack_14 = iStack_10;
      uStack_8 = 1;
      goto LAB_100035b3;
    }
    if (*(uint32_t *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0xc) < uStack_c) {
      uStack_c = *(uint32_t *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0xc);
      iStack_14 = *(int *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0x10);
    }
    iStack_10 = iStack_10 + 1;
  } while( true );
}


