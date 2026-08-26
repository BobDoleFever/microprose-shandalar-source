/*
 * Decompiled function: FUN_00481491
 * Entry Point: 00481491
 * Size: 245 bytes
 */
#include "magic.h"


undefined4 FUN_00481491(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < arg_3; local_c = local_c + 1) {
    if (*(int *)(arg_2 + local_c * 4) != 0) {
      iVar1 = FUN_0046bc92(*(HWND *)(arg_2 + local_c * 4));
      if (iVar1 == arg_1) {
        FUN_00481491(*(int *)(arg_2 + local_c * 4),arg_2,arg_3);
        DestroyWindow(*(HWND *)(arg_2 + local_c * 4));
        *(undefined4 *)(arg_2 + local_c * 4) = 0;
      }
    }
  }
  for (local_c = 0; local_c < arg_3; local_c = local_c + 1) {
    if (*(int *)(arg_2 + local_c * 4) == arg_1) {
      DestroyWindow(*(HWND *)(arg_2 + local_c * 4));
      *(undefined4 *)(arg_2 + local_c * 4) = 0;
      local_8 = 1;
    }
  }
  return local_8;
}


