/*
 * Decompiled function: FUN_10007c74
 * Entry Point: 10007c74
 * Size: 190 bytes
 */
#include "statwin.h"


bool __cdecl FUN_10007c74(int *ptr_1,int *ptr_2,int *ptr_3)

{
  BOOL BVar1;
  tagRECT local_34;
  RECT local_24;
  RECT local_14;
  
  local_14.left = *ptr_2;
  local_14.top = ptr_2[1];
  local_14.bottom = ptr_2[1] + ptr_2[3];
  local_14.right = ptr_2[2] + *ptr_2;
  local_24.left = *ptr_3;
  local_24.top = ptr_3[1];
  local_24.bottom = ptr_3[1] + ptr_3[3];
  local_24.right = ptr_3[2] + *ptr_3;
  BVar1 = IntersectRect(&local_34,&local_14,&local_24);
  if (BVar1 != 0) {
    *ptr_1 = local_34.left;
    ptr_1[1] = local_34.top;
    ptr_1[2] = local_34.right - local_34.left;
    ptr_1[3] = local_34.bottom - local_34.top;
  }
  return BVar1 != 0;
}


