/*
 * Decompiled function: Pic_Subsystem_0045268f
 * Entry Point: 0045268f
 * Size: 121 bytes
 */
#include "magic.h"


int Pic_Subsystem_0045268f(int arg_1)

{
  int local_8;
  
  if (arg_1 != -1) {
    for (local_8 = 0; local_8 < g_MasterCardCount + 0x10; local_8 = local_8 + 1) {
      if (*(int *)(&g_MasterCardTypeTable + local_8 * 0x34) == arg_1) {
        return local_8;
      }
    }
  }
  return -1;
}


