/*
 * Decompiled function: FUN_0047ec25
 * Entry Point: 0047ec25
 * Size: 103 bytes
 */
#include "duel.h"


void FUN_0047ec25(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  undefined4 local_8;
  
  arg_1 = arg_1 + (arg_7 * arg_4 + arg_3) * 3;
  for (local_8 = 0; local_8 < arg_6; local_8 = local_8 + 1) {
    FUN_0047ee28((undefined8 *)arg_1,(undefined8 *)arg_2,arg_5 * 3);
    arg_1 = arg_1 + arg_7 * 3;
    arg_2 = arg_2 + arg_5 * 3;
  }
  return;
}


