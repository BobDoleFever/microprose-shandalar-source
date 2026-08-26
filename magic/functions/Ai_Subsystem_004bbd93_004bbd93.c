/*
 * Decompiled function: Ai_Subsystem_004bbd93
 * Entry Point: 004bbd93
 * Size: 507 bytes
 */
#include "magic.h"


void Ai_Subsystem_004bbd93(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6)

{
  int local_8;
  
  if (DAT_006b2d58 != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (DAT_006b2d58 < 1) {
        while (((0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + arg_1 * 0x20) && (DAT_006b2d58 == -1))
               && ((arg_6 == -1 || (arg_4 < arg_6 - g_TurnCounter))))) {
          Ai_Subsystem_004bd3e9(0x6b2d40,6,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
        }
      }
      else {
        while ((0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + arg_1 * 0x20) && (arg_4 < DAT_006b2d58)))
        {
          Ai_Subsystem_004bd3e9(0x6b2d40,6,1,(int *)0x0,0,arg_1,local_8,arg_2,arg_3);
        }
      }
    }
  }
  if (DAT_006b2d40 != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (local_8 != 6) {
        if (DAT_006b2d40 == -1) {
          while ((0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + arg_1 * 0x20) &&
                 ((g_TurnCounter < arg_6 || (arg_6 == -1))))) {
            Ai_Subsystem_004bd3e9(0x6b2d40,0,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
          }
        }
        else {
          while ((0 < DAT_006b2d40 && (0 < *(int *)(&DAT_0063ee90 + local_8 * 4 + arg_1 * 0x20)))) {
            Ai_Subsystem_004bd3e9(0x6b2d40,0,1,(int *)0x0,0,arg_1,local_8,arg_2,arg_3);
          }
        }
      }
    }
  }
  return;
}


