/*
 * Decompiled function: Ai_Subsystem_004b69ba
 * Entry Point: 004b69ba
 * Size: 494 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b69ba(int arg_1,int arg_2,char *arg_3)

{
  char local_30 [20];
  int local_1c;
  char local_18 [20];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
    if (*(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a82f + local_1c) != '\0') {
      FUN_004f4a92(arg_3,(char *)(local_1c * 10 + 0x649ff0),1,
                   &DAT_0064a070 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a82f + local_1c) * 10);
      FUN_004f4a92(arg_3,(char *)(local_1c * 10 + 0x649fb0),1,
                   &DAT_0064a070 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a82f + local_1c) * 10);
      FUN_004f4a92(arg_3,s_PLAINSs_0052d3e0,1,s_PLAINS_0052d3d8);
      strcpy(local_30,(char *)(local_1c * 10 + 0x649ff0));
      strcat(local_30,&DAT_0052d3e8);
      strcpy(local_18,&DAT_0064a070 +
                      *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x68a82f + local_1c) * 10);
      strcat(local_18,&DAT_0052d3f0);
      FUN_004f4a92(arg_3,local_30,1,local_18);
      strcpy(local_30,(char *)(local_1c * 10 + 0x649fb0));
      strcat(local_30,&DAT_0052d3f8);
      FUN_004f4a92(arg_3,local_30,1,local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  return;
}


