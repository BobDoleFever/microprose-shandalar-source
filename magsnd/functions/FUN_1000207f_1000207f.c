/*
 * Decompiled function: FUN_1000207f
 * Entry Point: 1000207f
 * Size: 285 bytes
 */
#include "magsnd.h"


int __cdecl FUN_1000207f(int32_t *ptr_1,int arg_2)

{
  int val_1;
  int *ptr_2;
  int val_2;
  
  val_1 = ptr_1[0xd];
  ptr_2 = ptr_1 + arg_2 + 0xd;
  val_2 = thunk_FUN_1000560f((LPSTR)*ptr_1,ptr_2);
  if ((val_2 == 0) &&
     (val_2 = thunk_FUN_10005f0c((int32_t *)*ptr_2,*(int *)(val_1 + (arg_2 * 3 + -3) * 8 + 0x14))
     , val_2 == 0)) {
    *(uint32_t *)(*ptr_2 + 4) = *(uint32_t *)(*ptr_2 + 4) | 0x20;
    thunk_FUN_10004534(*ptr_2);
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x10;
    *(uint32_t *)(*ptr_2 + 8) = ptr_1[2] & 1 | *(uint32_t *)(*ptr_2 + 8) & 0xfffffffe;
    *(int32_t *)(*ptr_2 + 0x10) = ptr_1[4];
  }
  return val_2;
}


