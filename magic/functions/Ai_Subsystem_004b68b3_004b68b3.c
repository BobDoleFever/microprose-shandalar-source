/*
 * Decompiled function: Ai_Subsystem_004b68b3
 * Entry Point: 004b68b3
 * Size: 263 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b68b3(int arg_1,int arg_2,char *arg_3)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if (*(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a829 + local_8) != '\0') {
      FUN_004f4a92(arg_3,(char *)(local_8 * 10 + 0x649f70),1,
                   &DAT_00649f30 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a829 + local_8) * 10);
      FUN_004f4a92(arg_3,(char *)(local_8 * 10 + 0x64a030),1,
                   &DAT_00649f30 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a829 + local_8) * 10);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}


