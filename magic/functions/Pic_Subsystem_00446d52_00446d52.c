/*
 * Decompiled function: Pic_Subsystem_00446d52
 * Entry Point: 00446d52
 * Size: 1260 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_00446d52(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  byte local_c;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
    if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
      return 0;
    }
    if ((g_PlayerManaPool != -1) &&
       (*(code **)(&DAT_0051aec8 + iVar1 * 0x34) != Prompts_Load_00416f1a)) {
      return 0;
    }
    if ((DAT_00525778 != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) == 0)) {
      return 0;
    }
    if (((((DAT_0063edc8 & (byte)(&g_MasterCardColorTable)[iVar1 * 0x34]) != 0) &&
         (iVar2 = FUN_00470ea3(arg1,arg1,arg2), iVar2 != 0)) &&
        ((((byte)g_PlayerHandCardCount & 4) == 0 ||
         ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x3004) != 0)))) &&
       (((g_CurrentTurnPhase == arg1 ||
         ((_DAT_00538bb4 & (int)(char)(&DAT_0051aed5)[iVar1 * 0x34]) != 0)) &&
        (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x74,1 - arg1,0xffffffff), iVar1 != 0)))) {
      return 3;
    }
  }
  else {
    if ((*(int *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) == g_PlayerManaPool) &&
       (g_PlayerManaPool != -1)) {
      if (arg1 == DAT_006a4b5c) {
        DAT_00695f0c = DAT_00695f0c | 4;
        DAT_0068a714 = DAT_0068a714 + 1;
        return 2;
      }
      return 0;
    }
    if (g_PlayerManaPool != -1) {
      iVar1 = Pic_Subsystem_004485d6(arg1,arg2,0x7d,arg1);
      if (iVar1 == 0) {
        return 0;
      }
      local_c = (byte)iVar1;
      DAT_00695f0c = DAT_00695f0c | 1 << (local_c & 0x1f);
      DAT_0068a714 = DAT_0068a714 + 1;
      if (1 < iVar1) {
        return 2;
      }
      return 3;
    }
    if ((((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) &&
         (((&DAT_0051aed0)[iVar1 * 0x34] & 1) != 0)) && ((DAT_0063edc8 & 0x10) != 0)) ||
       ((((&DAT_0051aed0)[iVar1 * 0x34] & 2) != 0 && ((DAT_0063edc8 & 0x20) != 0)))) {
      if ((DAT_00525778 != 0) && (((&DAT_0051aed0)[iVar1 * 0x34] & 2) == 0)) {
        return 0;
      }
      if (((((byte)g_PlayerHandCardCount & 4) == 0) ||
          ((*(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x5004) != 0)) &&
         (((DAT_006a4920 = DAT_006a4920 & 0xfffffffd, g_CurrentTurnPhase == arg1 ||
           ((_DAT_00538bb8 & (int)(char)(&DAT_0051aed5)[iVar1 * 0x34]) != 0)) &&
          ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0 &&
           (iVar1 = Magic_TriggerCardEvent(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))))) {
        if ((DAT_006a4920 & 2) != 0) {
          DAT_00695f0c = DAT_00695f0c | 4;
          return 2;
        }
        DAT_00695f0c = DAT_00695f0c | 2;
        return 3;
      }
    }
    if ((DAT_00695ec4 == 4) && (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)
       ) {
      DAT_006a4920 = DAT_006a4920 | 3;
      DAT_00695f0c = DAT_00695f0c | 4;
      return 2;
    }
    if ((((DAT_00695ec4 == 4) && (arg1 == DAT_0063edc0)) &&
        (((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
       ((((&g_CardSlot_SpecialState)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0 &&
        (iVar1 = FUN_00476675(arg1,arg2), iVar1 != 0)))) {
      DAT_00695f0c = DAT_00695f0c | 2;
      if (g_ActivePlayerPriority == arg1) {
        return 2;
      }
      return 3;
    }
  }
  return 0;
}


