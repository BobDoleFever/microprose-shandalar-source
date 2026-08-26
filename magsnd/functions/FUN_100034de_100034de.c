/*
 * Decompiled function: FUN_100034de
 * Entry Point: 100034de
 * Size: 245 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_100034de(int *ptr_1,int arg_2,int arg_3)

{
  int local_14;
  int local_10;
  uint32_t local_c;
  int32_t local_8;
  
  local_8 = 0;
  local_c = 0xffffffff;
  if (((arg_3 == 0) || (arg_3 <= arg_2)) || (0xff < arg_3)) {
    local_10 = 0;
    arg_3 = 0xff;
  }
  else {
    local_10 = arg_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  do {
    if (arg_3 <= local_10) {
LAB_100035b3:
      *ptr_1 = local_14;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      return local_8;
    }
    if (*(int *)(&DAT_1000a648 + local_10 * 4) == 0) {
      local_14 = local_10;
      local_8 = 1;
      goto LAB_100035b3;
    }
    if (*(uint32_t *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0xc) < local_c) {
      local_c = *(uint32_t *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0xc);
      local_14 = *(int *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0x10);
    }
    local_10 = local_10 + 1;
  } while( true );
}


