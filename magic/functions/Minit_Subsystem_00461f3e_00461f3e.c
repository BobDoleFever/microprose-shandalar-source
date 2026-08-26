/*
 * Decompiled function: Minit_Subsystem_00461f3e
 * Entry Point: 00461f3e
 * Size: 389 bytes
 */
#include "magic.h"


void Minit_Subsystem_00461f3e(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0) &&
           (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == arg_1)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == arg_2)) {
        *(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
        Mem_AllocOrFree_0041df33
                  (arg_3,*(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x120 + local_8 * 0x5b20
                                 ),
                   (int)(char)(&g_CardSlot_DamageReceived)[local_c * 0x120 + local_8 * 0x5b20],
                   *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_8 * 0x5b20));
      }
    }
  }
  return;
}


