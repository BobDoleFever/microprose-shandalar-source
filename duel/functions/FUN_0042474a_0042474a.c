/*
 * Decompiled function: FUN_0042474a
 * Entry Point: 0042474a
 * Size: 823 bytes
 */
#include "duel.h"


undefined4 FUN_0042474a(int arg_1,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  int yTop;
  int local_6c;
  int local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  int local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((arg_1 == 0) || (arg_2 == (int *)0x0)) {
    local_5c = 0;
  }
  else if (arg_5 + arg_4 + arg_3 == 0) {
    local_5c = 1;
  }
  else if (DAT_0050af8c == (HANDLE)0x0) {
    local_5c = 0;
  }
  else {
    GetObjectA(DAT_0050af8c,0x18,local_58);
    local_34 = local_54;
    local_40 = local_50 / 0x18;
    local_2c = arg_2[3] - arg_2[1];
    local_20 = (arg_2[2] - *arg_2) / 3;
    local_18 = *arg_2;
    local_28 = local_20 + local_18;
    local_30 = local_20 + local_28;
    yTop = arg_2[1];
    local_38 = local_50 - local_40;
    local_1c = (local_54 * local_2c) / local_40;
    for (local_6c = local_1c; (local_20 < (arg_5 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_5 + -1) * local_6c + local_18;
    for (local_3c = 0; local_3c < arg_5; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x14;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_00470cfa((HDC)arg_1,&local_14.left,DAT_0050af8c,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    for (local_6c = local_1c; (local_20 < (arg_4 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_4 + -1) * local_6c + local_28;
    for (local_3c = 0; local_3c < arg_4; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x16;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_00470cfa((HDC)arg_1,&local_14.left,DAT_0050af8c,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    for (local_6c = local_1c; (local_20 < (arg_3 + -1) * local_6c + local_1c && (2 < local_6c));
        local_6c = local_6c + -1) {
    }
    local_60 = (arg_3 + -1) * local_6c + local_30;
    for (local_3c = 0; local_3c < arg_3; local_3c = local_3c + 1) {
      local_24 = local_40 * 0x15;
      SetRect(&local_14,local_60,yTop,local_1c + local_60,local_2c + yTop);
      FUN_00470cfa((HDC)arg_1,&local_14.left,DAT_0050af8c,local_34,local_40,0,local_24,0,local_38);
      local_60 = local_60 - local_6c;
    }
    local_5c = 1;
  }
  return local_5c;
}


