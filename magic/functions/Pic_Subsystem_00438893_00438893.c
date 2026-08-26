/*
 * Decompiled function: Pic_Subsystem_00438893
 * Entry Point: 00438893
 * Size: 258 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00438893(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((g_DefendingPlayer == arg_1) && ((g_PlayerHandCardCount & 1) != 0)) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffffe;
      if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      else {
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
      }
    }
    if (arg_3 == 0x22) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


