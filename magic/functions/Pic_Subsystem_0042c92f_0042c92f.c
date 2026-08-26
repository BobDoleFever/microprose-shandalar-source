/*
 * Decompiled function: Pic_Subsystem_0042c92f
 * Entry Point: 0042c92f
 * Size: 292 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042c92f(int arg_1,int arg_2,int arg_3)

{
  if ((((*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0x2c) ||
       (*(int *)(&g_MasterCardTypeTable + arg_3 * 0x34) == 0xea)) &&
      ((char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
      )) && (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
     ) {
    (&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
    ;
    *(undefined4 *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)
          (&g_CardSlot_TypeFlags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120);
  }
  return 0;
}


