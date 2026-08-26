/*
 * Decompiled function: Pic_Subsystem_0044d31a
 * Entry Point: 0044d31a
 * Size: 629 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044d31a
               (int arg_1,int *arg_2,int *arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
               HANDLE arg_9)

{
  undefined1 local_34 [4];
  int local_30;
  int local_2c;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if ((((arg_1 != 0) && (arg_2 != (int *)0x0)) && (arg_3 != (int *)0x0)) && (arg_9 != (HANDLE)0x0))
  {
    GetObjectA(arg_9,0x18,local_34);
    local_8 = ((arg_3[1] - arg_2[1]) * local_2c) / arg_5;
    for (local_1c = arg_3[1]; local_1c < arg_3[3]; local_1c = local_1c + local_8) {
      SetRect(&local_18,*arg_3,local_1c,*arg_3 + arg_4,local_1c + local_8);
      FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
      SetRect(&local_18,arg_3[2] - arg_4,local_1c,arg_3[2],local_1c + local_8);
      FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,local_30 - arg_8,0,arg_8,local_2c);
    }
    SetRect(&local_18,*arg_3,arg_2[1],arg_3[2],arg_3[1]);
    FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,0,0,(local_30 - arg_7) - arg_8,arg_5);
    SetRect(&local_18,*arg_3,arg_3[3],arg_3[2],arg_2[3]);
    FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,0,local_2c - arg_6,(local_30 - arg_7) - arg_8,arg_6
                );
    for (local_1c = arg_2[1]; local_1c < arg_2[3]; local_1c = local_1c + local_8) {
      SetRect(&local_18,*arg_2,local_1c,*arg_3,local_1c + local_8);
      FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
      SetRect(&local_18,arg_3[2],local_1c,arg_2[2],local_1c + local_8);
      FUN_004f3bc7((HDC)arg_1,&local_18.left,arg_9,(local_30 - arg_7) - arg_8,0,arg_7,local_2c);
    }
  }
  return;
}


