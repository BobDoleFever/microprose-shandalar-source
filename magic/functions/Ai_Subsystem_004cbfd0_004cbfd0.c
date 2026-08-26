/*
 * Decompiled function: Ai_Subsystem_004cbfd0
 * Entry Point: 004cbfd0
 * Size: 131 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cbfd0(int arg_1,int arg_2,int *arg_3)

{
  if (arg_3 != (int *)0x0) {
    *arg_3 = (int)(char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20];
    arg_3[1] = *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return *(undefined4 *)(&DAT_006a5f74 + arg_2 * 0x120 + arg_1 * 0x5b20);
}


