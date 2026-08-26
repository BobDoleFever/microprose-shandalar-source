/*
 * Decompiled function: thunk_FUN_10007c74
 * Entry Point: 10001136
 * Size: 5 bytes
 */
#include "statwin.h"


bool __cdecl thunk_FUN_10007c74(int *ptr_1,int *ptr_2,int *ptr_3)

{
  BOOL BVar1;
  tagRECT tStack_34;
  RECT RStack_24;
  RECT RStack_14;
  
  RStack_14.left = *ptr_2;
  RStack_14.top = ptr_2[1];
  RStack_14.bottom = ptr_2[1] + ptr_2[3];
  RStack_14.right = ptr_2[2] + *ptr_2;
  RStack_24.left = *ptr_3;
  RStack_24.top = ptr_3[1];
  RStack_24.bottom = ptr_3[1] + ptr_3[3];
  RStack_24.right = ptr_3[2] + *ptr_3;
  BVar1 = IntersectRect(&tStack_34,&RStack_14,&RStack_24);
  if (BVar1 != 0) {
    *ptr_1 = tStack_34.left;
    ptr_1[1] = tStack_34.top;
    ptr_1[2] = tStack_34.right - tStack_34.left;
    ptr_1[3] = tStack_34.bottom - tStack_34.top;
  }
  return BVar1 != 0;
}


