/*
 * Decompiled function: Ai_Subsystem_004bd3e9
 * Entry Point: 004bd3e9
 * Size: 112 bytes
 */
#include "magic.h"


void Ai_Subsystem_004bd3e9
               (int arg_1,int arg_2,int arg_3,int *arg_4,undefined4 arg_5,int arg_6,int arg_7,
               int arg_8,int *arg_9)

{
  int *piVar1;
  
  FUN_0040d8b7(arg_6,arg_7,arg_3);
  if (*(int *)(arg_1 + arg_2 * 4) == -1) {
    *arg_4 = *arg_4 + arg_3;
  }
  else {
    piVar1 = (int *)(arg_1 + arg_2 * 4);
    *piVar1 = *piVar1 - arg_3;
  }
  piVar1 = (int *)(arg_8 + arg_7 * 4);
  *piVar1 = *piVar1 + arg_3;
  Ai_Subsystem_004bd563(arg_7,arg_3);
  *arg_9 = *arg_9 + arg_3;
  return;
}


