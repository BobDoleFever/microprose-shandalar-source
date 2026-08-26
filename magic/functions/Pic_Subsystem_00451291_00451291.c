/*
 * Decompiled function: Pic_Subsystem_00451291
 * Entry Point: 00451291
 * Size: 186 bytes
 */
#include "magic.h"


int Pic_Subsystem_00451291(int arg1,int arg2)

{
  int local_8;
  
  if (arg2 != -1) {
    for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
      if (*(int *)(&g_ActiveCardsInPlay + local_8 * 0x120 + arg1 * 0x5b20) == -1) {
        Pic_Subsystem_0045134b(arg1,arg2,local_8);
        if ((int)(&g_PlayerActiveCardCount)[arg1] <= local_8) {
          (&g_PlayerActiveCardCount)[arg1] = local_8 + 1;
          return local_8;
        }
        return local_8;
      }
    }
    Engine_ReportFatalError(s_AddCard_error_00523ea8);
  }
  return -1;
}


