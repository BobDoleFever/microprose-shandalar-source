/*
 * Decompiled function: Ai_Subsystem_004bb9f3
 * Entry Point: 004bb9f3
 * Size: 422 bytes
 */
#include "magic.h"


void Ai_Subsystem_004bb9f3(int x,int arg_2,int *arg_3,int height)

{
  ushort uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    while ((0 < (int)(&DAT_006b2d40)[local_8] &&
           (0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + x * 0x20)))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,local_8,1,(int *)0x0,0,x,local_8,arg_2,arg_3);
    }
  }
  while (((0 < DAT_006b2d58 && (0 < *(int *)(&DAT_0063ee90 + x * 0x20))) && (height < DAT_006b2d58))
        ) {
    Ai_Subsystem_004bd3e9(0x6b2d40,6,1,(int *)0x0,0,x,0,arg_2,arg_3);
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&DAT_00627a20 + local_c * 4 + x * 0x2c) != -1))) {
    uVar1 = *(ushort *)(&DAT_00627a20 + local_c * 4 + x * 0x2c);
    uVar2 = *(uint *)(&DAT_00627a20 + local_c * 4 + x * 0x2c);
    while ((0 < *(int *)(&DAT_0063ee90 + (uint)uVar1 * 4 + x * 0x20) &&
           (0 < (int)(&DAT_006b2d40)[uVar2 >> 0x10]))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,uVar2 >> 0x10,1,(int *)0x0,0,x,(uint)uVar1,arg_2,arg_3);
    }
    local_c = local_c + 1;
  }
  return;
}


