/*
 * Decompiled function: Ai_Subsystem_004bd459
 * Entry Point: 004bd459
 * Size: 151 bytes
 */
#include "magic.h"


int Ai_Subsystem_004bd459(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int iVar1;
  undefined4 local_8;
  
  if (arg_5 == 0) {
    local_8 = 1;
  }
  else if (*(int *)(arg_1 + arg_2 * 4) == -1) {
    if (arg_6 == -1) {
      local_8 = *(int *)(arg_3 + arg_4 * 4);
    }
    else {
      local_8 = *(int *)(arg_3 + arg_4 * 4);
      if (arg_6 - arg_7 <= local_8) {
        local_8 = arg_6 - arg_7;
      }
    }
  }
  else {
    local_8 = *(int *)(arg_3 + arg_4 * 4);
    iVar1 = *(int *)(arg_1 + arg_2 * 4);
    if (iVar1 <= local_8) {
      local_8 = iVar1;
    }
  }
  return local_8;
}


