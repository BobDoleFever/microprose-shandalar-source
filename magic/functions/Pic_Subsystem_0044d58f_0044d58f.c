/*
 * Decompiled function: Pic_Subsystem_0044d58f
 * Entry Point: 0044d58f
 * Size: 139 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044d58f
               (undefined4 arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,
               int *arg_8,int *arg_9,int *arg_10)

{
  if (arg_3 == 0) {
    *arg_7 = 0;
    *arg_8 = 0;
    *arg_9 = 0;
    *arg_10 = 0;
  }
  else {
    *arg_7 = (arg_2 * 0x1f) / 100;
    *arg_8 = (*arg_7 * arg_4) / arg_3;
    *arg_9 = (*arg_7 * arg_5) / arg_3;
    *arg_10 = (*arg_7 * arg_6) / arg_3;
  }
  return;
}


