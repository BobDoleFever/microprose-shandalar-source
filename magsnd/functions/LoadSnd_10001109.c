/*
 * Decompiled function: LoadSnd
 * Entry Point: 10001109
 * Size: 5 bytes
 */
#include "magsnd.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl LoadSnd(LPSTR arg_1,int arg_2,int arg_3)

{
  int val_1;
  
                    /* 0x1109  3  LoadSnd */
  if (((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0)) || (arg_2 == 0)) {
    if ((0x100 < arg_2) || (arg_2 < 0)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  else {
    if ((0x10f < arg_2) || (arg_2 < 0x100)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  if ((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 2 & 1) == 0)) {
    val_1 = thunk_FUN_100055b0(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
    if (val_1 != 0) {
      *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
      return val_1;
    }
  }
  else {
    if ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0) {
      val_1 = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
    }
    else {
      val_1 = thunk_FUN_1000667b(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      if ((*(uint32_t *)(arg_3 + 0x1c) >> 5 & 1) == 0) {
        thunk_FUN_1000630c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4));
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) & 0xffffffbf;
      }
      else {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 0x40;
      }
      _DAT_1000a430 = _DAT_1000a430 + 1;
    }
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 0x20;
    thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
  }
  thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
  *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
  if ((arg_3 != 0) && (*(int *)(arg_3 + 0x18) != 0)) {
    *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x14) = *(int32_t *)(arg_3 + 0x18);
  }
  return 0;
}


