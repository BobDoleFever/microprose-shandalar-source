/*
 * Decompiled function: Merchant_ProcessBuy_00407b34
 * Entry Point: 00407b34
 * Size: 776 bytes
 */
#include "magic.h"


void Merchant_ProcessBuy_00407b34(int arg_1)

{
  int iVar1;
  int arg_4;
  int arg_3;
  int arg_2;
  int local_458;
  void *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 auStack_448 [6];
  undefined4 auStack_430 [4];
  uint local_420;
  undefined4 auStack_41c [6];
  undefined4 local_404;
  undefined4 auStack_400 [3];
  char local_3f4 [1000];
  void *local_c;
  undefined4 local_8;
  
  if (*(int *)(&DAT_00701944 + arg_1 * 8) == -1) {
    strcpy(&g_OverworldWorldState,s_The_card_seller_notes___If_you_b_005165fc);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s___you_can_00516628);
  }
  else {
    iVar1 = FUN_00407747(*(int *)(&DAT_00701940 + arg_1 * 8));
    local_420 = (uint)(iVar1 != 0);
    strcpy(&g_OverworldWorldState,s_The_card_seller_suggests___If_yo_005165a0);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + local_420 * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s_with_the_005165d4);
    iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00701940 + (local_420 ^ 1) * 4 + arg_1 * 8));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
    strcat(&g_OverworldWorldState,s_you_already_have__you_can_005165e0);
  }
  Hints_GetNext_0040741b(arg_1);
  strcat(&g_OverworldWorldState,&DAT_00516634);
  Sprite_LoadAll(&local_454,s_BuyButtons_spr_00516638);
  local_c = local_454;
  local_8 = local_450;
  local_404 = local_44c;
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_400[local_458] = auStack_448[local_458];
  }
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_41c[local_458 + 3] = auStack_448[local_458 + 3];
  }
  for (local_458 = 0; local_458 < 3; local_458 = local_458 + 1) {
    auStack_41c[local_458] = auStack_448[local_458 + 6];
  }
  iVar1 = Ai_Util_004c3bc4(0x10f);
  arg_4 = Ai_Util_004c3bc4(0xc5);
  arg_3 = Ai_Util_004c3bc4(0x34);
  arg_2 = Ai_Util_004c3bc4(0xdc);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,iVar1,(int)local_454);
  iVar1 = Ai_Util_004c3bc4(0x85);
  FUN_00407843(&g_OverworldWorldState,local_3f4,iVar1);
  FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xfe,0x140,0xbc);
  Ai_Subsystem_004cd1d1();
  Mem_AllocOrFree_0050fc50(local_c);
  return;
}


