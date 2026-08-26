/*
 * Decompiled function: Sprite_Load_BK_AMG_0046d333
 * Entry Point: 0046d333
 * Size: 4866 bytes
 */
#include "magic.h"


void Sprite_Load_BK_AMG_0046d333(undefined4 arg_1,int arg_2,int arg_3)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  
  bVar2 = true;
  if (*(int *)(&g_OverworldFoodAmount + arg_2 * 0xb4) == 0) {
    switch(arg_1) {
    case 1:
      pcVar3 = (char *)FUN_0046f172(s_BK_FWZ_spr_00525294);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SFWZ_spr_005252a0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 2:
      pcVar3 = (char *)FUN_0046f172(s_BK_KHT_spr_005252ac);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SB_KHT_spr_005252b8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 3:
      pcVar3 = (char *)FUN_0046f172(s_BK_MWZ_spr_005252c4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SMWZ_spr_005252d0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 4:
      pcVar3 = (char *)FUN_0046f172(s_BK_LRD_spr_005252dc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SB_LRD_spr_005252e8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 5:
      pcVar3 = (char *)FUN_0046f172(s_BK_WG_spr_005252f4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SBK_WG_spr_00525300);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 6:
      pcVar3 = (char *)FUN_0046f172(s_BK_AMG_spr_0052530c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SB_AMG_spr_00525318);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    default:
      bVar2 = false;
      break;
    case 8:
      pcVar3 = (char *)FUN_0046f172(s_W_MWZ_spr_00525324);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SW_MWZ_spr_00525330);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 9:
      pcVar3 = (char *)FUN_0046f172(s_W_FWZ_spr_0052533c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SFWZ_spr_00525348);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 10:
      pcVar3 = (char *)FUN_0046f172(s_W_KHT_spr_00525354);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SKHT_spr_00525360);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0xb:
      pcVar3 = (char *)FUN_0046f172(s_W_LRD_spr_0052536c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SW_LRD_spr_00525378);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0xc:
      pcVar3 = (char *)FUN_0046f172(s_W_WG_spr_00525384);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SW_WG_spr_00525390);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0xd:
      pcVar3 = (char *)FUN_0046f172(s_W_AMG_spr_0052539c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SW_AMG_spr_005253a8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0xf:
      pcVar3 = (char *)FUN_0046f172(s_BU_FWZ_spr_005253b4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SFWZ_spr_005253c0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x10:
      pcVar3 = (char *)FUN_0046f172(s_BU_LRD_spr_005253cc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SU_LRD_spr_005253d8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x11:
      pcVar3 = (char *)FUN_0046f172(s_BU_MWZ_spr_005253e4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SMWZ_spr_005253f0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x12:
      pcVar3 = (char *)FUN_0046f172(s_BU_WRM_spr_005253fc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SWRM_spr_00525408);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x13:
      pcVar3 = (char *)FUN_0046f172(s_B_SFR_spr_00525414);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SB_SFT_spr_00525420);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x14:
      pcVar3 = (char *)FUN_0046f172(s_BU_AMG_spr_0052542c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SU_AMG_spr_00525438);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x16:
      pcVar3 = (char *)FUN_0046f172(s_G_MWZ_spr_00525444);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SMWZ_spr_00525450);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x17:
      pcVar3 = (char *)FUN_0046f172(s_G_KHT_spr_0052545c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SKHT_spr_00525468);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x18:
      pcVar3 = (char *)FUN_0046f172(s_G_FWZ_spr_00525474);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SFWZ_spr_00525480);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x19:
      pcVar3 = (char *)FUN_0046f172(s_G_WRM_spr_0052548c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SWRM_spr_00525498);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x1a:
      pcVar3 = (char *)FUN_0046f172(s_G_LRD_spr_005254a4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SG_LRD_spr_005254b0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x1b:
      pcVar3 = (char *)FUN_0046f172(s_G_AMG_spr_005254bc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SG_AMG_spr_005254c8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x1d:
      pcVar3 = (char *)FUN_0046f172(s_R_FWZ_spr_005254d4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SR_FWZ_spr_005254e0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x1e:
      pcVar3 = (char *)FUN_0046f172(s_R_MWZ_spr_005254ec);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SMWZ_spr_005254f8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x1f:
      pcVar3 = (char *)FUN_0046f172(s_TROLL_spr_00525504);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_STRL_spr_00525510);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x20:
      pcVar3 = (char *)FUN_0046f172(s_R_LRD_spr_0052551c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SR_LRD_spr_00525528);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x21:
      pcVar3 = (char *)FUN_0046f172(s_R_WRM_spr_00525534);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SR_WRM_spr_00525540);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x22:
      pcVar3 = (char *)FUN_0046f172(s_R_AMG_spr_0052554c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SR_AMG_spr_00525558);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x23:
      pcVar3 = (char *)FUN_0046f172(s_R_AMG_spr_00525564);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SR_AMG_spr_00525570);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x24:
      pcVar3 = (char *)FUN_0046f172(s_M_TSK_spr_0052557c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_TSK_spr_00525588);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x25:
      pcVar3 = (char *)FUN_0046f172(s_M_TRL_spr_00525594);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_TRL_spr_005255a0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x26:
      pcVar3 = (char *)FUN_0046f172(s_M_APE_spr_005255ac);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_APE_spr_005255b8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x27:
      pcVar3 = (char *)FUN_0046f172(s_M_CEN2_spr_005255c4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_CEN_spr_005255d0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x28:
      pcVar3 = (char *)FUN_0046f172(s_M_WG_spr_005255dc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_WG_spr_005255e8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x29:
      pcVar3 = (char *)FUN_0046f172(s_M_FNG_spr_005255f4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_FNG_spr_00525600);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2a:
      pcVar3 = (char *)FUN_0046f172(s_M_CEN_spr_0052560c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_CEN2_spr_00525618);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2b:
      pcVar3 = (char *)FUN_0046f172(s_M_LRD_spr_00525624);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SM_LRD_spr_00525630);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2c:
      pcVar3 = (char *)FUN_0046f172(s_M_KHT_spr_0052563c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SKHT_spr_00525648);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2d:
      pcVar3 = (char *)FUN_0046f172(s_M_FWZ_spr_00525654);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SFWZ_spr_00525660);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2e:
      pcVar3 = (char *)FUN_0046f172(s_BK_DJN_spr_0052566c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SDJN_spr_00525678);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x2f:
      pcVar3 = (char *)FUN_0046f172(s_G_DJN_spr_00525684);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SDJN_spr_00525690);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x30:
      pcVar3 = (char *)FUN_0046f172(s_R_DJN_spr_0052569c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SDJN_spr_005256a8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x31:
      pcVar3 = (char *)FUN_0046f172(s_BU_DJN_spr_005256b4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_SDJN_spr_005256c0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x32:
      pcVar3 = (char *)FUN_0046f172(s_DG_BRU_spr_005256cc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_S_DG_spr_005256d8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x33:
      pcVar3 = (char *)FUN_0046f172(s_DG_UWB_spr_005256e4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_S_DG_spr_005256f0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x34:
      pcVar3 = (char *)FUN_0046f172(s_DG_GWR_spr_005256fc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_S_DG_spr_00525708);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x35:
      pcVar3 = (char *)FUN_0046f172(s_DG_RBG_spr_00525714);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_S_DG_spr_00525720);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
      break;
    case 0x36:
      pcVar3 = (char *)FUN_0046f172(s_DG_WUG_spr_0052572c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4),pcVar3);
      pcVar3 = (char *)FUN_0046f172(s_S_DG_spr_00525738);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + arg_3 * 0xb4),pcVar3);
    }
    if (bVar2) {
      iVar1 = *(int *)(&g_OverworldFoodAmount + arg_2 * 0xb4);
      *(int *)(&DAT_006783f0 + arg_2 * 4) = (int)*(short *)(iVar1 + 4);
      *(int *)(&DAT_00678470 + arg_2 * 4) = (int)*(short *)(iVar1 + 6);
      *(int *)(&DAT_00677990 + arg_2 * 4) = (int)*(short *)(iVar1 + 10);
      if (*(int *)(&DAT_00678470 + arg_2 * 4) < *(int *)(&DAT_00677990 + arg_2 * 4)) {
        *(int *)(&DAT_00677990 + arg_2 * 4) = (*(int *)(&DAT_00678470 + arg_2 * 4) * 2) / 3;
      }
      *(undefined4 *)(&DAT_006783f0 + arg_3 * 4) = *(undefined4 *)(&DAT_006783f0 + arg_2 * 4);
      *(undefined4 *)(&DAT_00678470 + arg_3 * 4) = *(undefined4 *)(&DAT_00678470 + arg_2 * 4);
      *(undefined4 *)(&DAT_00677990 + arg_3 * 4) = *(undefined4 *)(&DAT_00677990 + arg_2 * 4);
    }
    else {
      *(undefined4 *)(&g_OverworldFoodAmount + arg_2 * 0xb4) = 0;
    }
  }
  return;
}


