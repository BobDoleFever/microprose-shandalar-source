/*
 * Decompiled function: Card_LordOfAtlantis_PayOrSacrifice
 * Entry Point: 004e1b38
 * Size: 340 bytes
 */
#include "magic.h"


undefined4 Card_LordOfAtlantis_PayOrSacrifice(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  
  if (((arg_3 == 0x15) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 4) != 0)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
    bVar1 = false;
    iVar2 = FUN_0040d949(arg_1,7,2);
    if (iVar2 != 0) {
      iVar2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Pay_2_mana__Lose_3_life__0052ee0c,0);
      if (iVar2 == 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,2);
        if (g_ActivePlayer == 1) {
          g_ActivePlayer = -1;
        }
        else {
          bVar1 = true;
        }
      }
    }
    if (!bVar1) {
      Mem_AllocOrFree_0041df33(arg_1,3,arg_1,arg_2);
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
  }
  return 0;
}


