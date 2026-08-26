/*
 * Decompiled function: Minit_Subsystem_00465602
 * Entry Point: 00465602
 * Size: 983 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x004659aa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Minit_Subsystem_00465602(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_SpellStackDepth = g_SpellStackDepth + 0xc;
  }
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar3 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0040d949(arg_1,7,2), iVar2 != 0)) {
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,0,2);
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_0069f6dc,
                           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (iVar2 != -1) {
        cVar1 = FUN_0041d963(arg_1,arg_2,2);
        *(int *)(&g_CardSlot_ConvertedManaCost + iVar2 * 0x120 + arg_1 * 0x5b20) =
             1 << (cVar1 - 1U & 0x1f);
      }
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
      Minit_Subsystem_004659d9
                (arg_1,arg_2,*(uint *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))
      ;
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((((arg_3 == 0x77) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) &&
        (iVar2 = Minit_Subsystem_00465a19(arg_1,arg_2), _DAT_0063ee20 == g_OverworldPlayerCoordX))
       && (g_OverworldMapGrid == iVar2)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uVar3 = 0;
  }
  return uVar3;
}


