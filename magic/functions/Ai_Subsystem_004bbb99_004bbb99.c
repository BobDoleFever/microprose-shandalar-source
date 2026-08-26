/*
 * Decompiled function: Ai_Subsystem_004bbb99
 * Entry Point: 004bbb99
 * Size: 506 bytes
 */
#include "magic.h"


void Ai_Subsystem_004bbb99(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6)

{
  ushort uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    if ((&DAT_006b2d40)[local_8] == -1) {
      while ((0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + arg_1 * 0x20) &&
             ((g_TurnCounter < arg_6 || (arg_6 == -1))))) {
        Ai_Subsystem_004bd3e9(0x6b2d40,local_8,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
      }
    }
  }
  if (DAT_006b2d58 == -1) {
    while (((0 < *(int *)(&DAT_0063ee90 + arg_1 * 0x20) && (arg_4 < DAT_006b2d58)) &&
           ((g_TurnCounter < arg_6 || (arg_6 == -1))))) {
      Ai_Subsystem_004bd3e9(0x6b2d40,6,1,arg_5,arg_6,arg_1,0,arg_2,arg_3);
    }
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&DAT_00627a20 + local_c * 4 + arg_1 * 0x2c) != -1))) {
    uVar1 = *(ushort *)(&DAT_00627a20 + local_c * 4 + arg_1 * 0x2c);
    uVar2 = *(uint *)(&DAT_00627a20 + local_c * 4 + arg_1 * 0x2c);
    if ((&DAT_006b2d40)[uVar2 >> 0x10] == -1) {
      while ((0 < *(int *)(&DAT_0063ee90 + (uint)uVar1 * 4 + arg_1 * 0x20) &&
             ((g_TurnCounter < arg_6 || (arg_6 == -1))))) {
        Ai_Subsystem_004bd3e9(0x6b2d40,uVar2 >> 0x10,1,arg_5,arg_6,arg_1,(uint)uVar1,arg_2,arg_3);
      }
    }
    local_c = local_c + 1;
  }
  return;
}


