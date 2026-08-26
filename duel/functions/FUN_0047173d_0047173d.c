/*
 * Decompiled function: FUN_0047173d
 * Entry Point: 0047173d
 * Size: 417 bytes
 */
#include "duel.h"


void FUN_0047173d(int arg_1,int arg_2,RECT *arg_3)

{
  int arg_3_00;
  int iVar1;
  undefined4 arg_6;
  undefined4 uVar2;
  uint arg_2_00;
  int local_28;
  tagRECT local_14;
  
  if (((arg_1 != 0) && (arg_2 != 0)) && (arg_3 != (RECT *)0x0)) {
    CopyRect(&local_14,arg_3);
    arg_3_00 = *(int *)(arg_1 + 4);
    arg_2_00 = (uint)*(ushort *)(arg_1 + 0xe);
    while( true ) {
      local_14.bottom = local_14.bottom + -1;
      local_14.right = local_14.right + -1;
      if (local_14.right <= local_14.left) break;
      for (local_28 = local_14.left; local_28 < local_14.right; local_28 = local_28 + 1) {
        iVar1 = local_28 - local_14.left;
        arg_6 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,local_14.left + iVar1,local_14.top);
        uVar2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,local_14.left,local_14.bottom - iVar1);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,local_14.left + iVar1,local_14.top,uVar2);
        uVar2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,local_14.right - iVar1,local_14.bottom);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,local_14.left,local_14.bottom - iVar1,uVar2);
        uVar2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,local_14.right,local_14.top + iVar1);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,local_14.right - iVar1,local_14.bottom,uVar2);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,local_14.right,local_14.top + iVar1,arg_6);
      }
      local_14.left = local_14.left + 1;
      local_14.top = local_14.top + 1;
    }
  }
  return;
}


