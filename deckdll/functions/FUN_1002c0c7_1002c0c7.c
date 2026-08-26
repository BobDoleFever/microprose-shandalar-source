/*
 * Decompiled function: FUN_1002c0c7
 * Entry Point: 1002c0c7
 * Size: 345 bytes
 */
#include "deckdll.h"


int32_t FUN_1002c0c7(int *arg_1,int arg_2,LPRECT arg_3)

{
  tagRECT local_18;
  int local_8;
  
  local_8 = (arg_1[3] - arg_1[1]) + -2;
  SetRect(&local_18,*arg_1 + 1,arg_1[1] + 1,*arg_1 + local_8 + 1,arg_1[3] + -2);
  if (((DAT_1017646c & 2) == 0) && ((DAT_1017646c & 0xc) == 0)) {
    OffsetRect(&local_18,local_8 * (arg_2 + -0xd),0);
  }
  else {
    OffsetRect(&local_18,local_8 * (arg_2 + -10),0);
  }
  if (0xc < arg_2) {
    local_18.left = local_18.left + -0x10;
    local_18.right = local_18.right + -0x10;
  }
  if ((0x13 < arg_2) && (arg_2 < 0x17)) {
    local_18.left = local_18.left + local_8 * -2;
    local_18.right = local_18.right + local_8 * -2;
  }
  if (0x16 < arg_2) {
    local_18.left = local_18.left - (local_8 + 0x10);
    local_18.right = local_18.right - (local_8 + 0x10);
  }
  if (0x1b < arg_2) {
    local_18.left = local_18.left - (0x10 - local_8);
    local_18.right = local_18.right - (0x10 - local_8);
  }
  CopyRect(arg_3,&local_18);
  return 1;
}


