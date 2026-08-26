/*
 * Decompiled function: FUN_00468261
 * Entry Point: 00468261
 * Size: 285 bytes
 */
#include "duel.h"


bool FUN_00468261(int arg_1,uint arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  iVar1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0
                     ,1,&local_c);
  if (iVar1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = local_c;
    *(undefined4 *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         local_8;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return iVar1 != 0;
}


