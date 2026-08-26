/*
 * Decompiled function: Palette_Subsystem_00498a18
 * Entry Point: 00498a18
 * Size: 3133 bytes
 */
#include "magic.h"


bool Palette_Subsystem_00498a18(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  int local_50;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int aiStack_34 [8];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 5;
  do {
    local_50 = 0;
    uVar1 = FUN_0040a1d2(10);
    switch(uVar1) {
    case 0:
      local_44 = 0;
      break;
    case 1:
      local_44 = 1;
      break;
    case 2:
      local_44 = 2;
      break;
    case 3:
      local_44 = 3;
      break;
    case 4:
      local_44 = 4;
      break;
    case 5:
      local_44 = 5;
      break;
    case 6:
      local_44 = 6;
      break;
    case 7:
      local_44 = 7;
      break;
    case 8:
      local_44 = 8;
      break;
    case 9:
      local_44 = 2;
    }
switchD_00498acb_default:
    do {
      do {
        iVar2 = FUN_0040a1d2(g_MasterCardCount + -0x29);
        if (((&g_MasterCardColorTable)[iVar2 * 0x34] & 2) == 0) {
          if (local_44 != 2) goto switchD_00498acb_default;
        }
      } while (((&DAT_0051aed6)[iVar2 * 0x34] & 0xc1) == 0);
      bVar5 = false;
      switch(local_44) {
      case 0:
        if ((0 < *(short *)(&DAT_0051aec2 + iVar2 * 0x34)) &&
           (*(short *)(&DAT_0051aec2 + iVar2 * 0x34) < 0x4000)) {
          bVar5 = true;
        }
        break;
      case 1:
        if ((0 < *(short *)(&DAT_0051aec4 + iVar2 * 0x34)) &&
           (*(short *)(&DAT_0051aec4 + iVar2 * 0x34) < 0x4000)) {
          bVar5 = true;
        }
        break;
      case 2:
        if (('\0' < (char)(&DAT_0051aebf)[iVar2 * 0x34]) &&
           (-1 < (char)(&DAT_0051aec0)[iVar2 * 0x34])) {
          bVar5 = true;
        }
        break;
      case 3:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x20) != 0;
        break;
      case 4:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x1f) != 0;
        break;
      case 5:
        bVar5 = ((&DAT_0051aecd)[iVar2 * 0x34] & 2) != 0;
        break;
      case 6:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x40) != 0;
        break;
      case 7:
        bVar5 = ((&DAT_0051aecd)[iVar2 * 0x34] & 1) != 0;
        break;
      case 8:
        bVar5 = ((&DAT_0051aecc)[iVar2 * 0x34] & 0x80) != 0;
      }
      local_50 = local_50 + 1;
      if (bVar5) {
        iVar3 = FUN_0040a1d2(4);
        if (DAT_0067f380 <= iVar3) {
          local_38 = 0;
          goto LAB_00498ff5;
        }
        local_10 = -1;
        switch(local_44) {
        case 0:
          strcpy(&g_OverworldWorldState,s_What_is_the_power_rating_of_the_0052b944);
          local_10 = (int)*(short *)(&DAT_0051aec2 + iVar2 * 0x34);
          break;
        case 1:
          strcpy(&g_OverworldWorldState,s_What_is_the_toughness_of_the_0052b968);
          local_10 = (int)*(short *)(&DAT_0051aec4 + iVar2 * 0x34);
          break;
        case 2:
          strcpy(&g_OverworldWorldState,s_What_is_the_total_casting_cost_o_0052b988);
          local_10 = (int)(char)(&DAT_0051aebf)[iVar2 * 0x34] +
                     (int)(char)(&DAT_0051aec0)[iVar2 * 0x34];
          break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          strcpy(&g_OverworldWorldState,s_What_special_ability_does_the_0052b9b0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
          strcat(&g_OverworldWorldState,s_have__Swampwalk_Islandwalk_Fores_0052b9d0);
          strcat(&g_OverworldWorldState,s_Plainswalk_Flying_Banding_Trampl_0052ba0c);
        }
        if (local_10 == -1) {
          local_3c = FUN_00489710(&g_OverworldWorldState,0x50,100);
          local_c = local_3c;
          if ((*(uint *)(&DAT_0051aecc + iVar2 * 0x34) & 1 << ((byte)local_3c & 0x1f)) == 0) {
            local_c = 99;
          }
        }
        else {
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
          strcat(&g_OverworldWorldState,s___0_1_2_3_4_5_6_7_8__0052ba50);
          local_c = FUN_0040a305(local_10,0,8);
          local_3c = FUN_00489710(&g_OverworldWorldState,0x50,100);
        }
        Adventure_LoadFacePalette(1);
        Ai_Subsystem_004cc50a
                  (iVar2,(-(uint)(local_3c == local_c) & 0x12) + 0xbc,
                   s_Correct_0052ba70 + ((local_3c == local_c) - 1 & 8));
        Ai_Subsystem_004cd1d1();
        bVar5 = local_3c != local_c;
        goto LAB_0049971a;
      }
    } while (local_50 < 4);
  } while( true );
LAB_00498ff5:
  if (local_14 <= local_38) {
    local_c = FUN_0040a1d2(local_14);
    aiStack_34[local_c] = iVar2;
    strcpy(&g_OverworldWorldState,s_Which_of_these_spells_0052ba80);
    switch(local_44) {
    case 0:
      strcat(&g_OverworldWorldState,s_has_a_power_of_0052ba98);
      pcVar4 = _itoa((int)*(short *)(&DAT_0051aec2 + iVar2 * 0x34),&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      break;
    case 1:
      strcat(&g_OverworldWorldState,s_has_a_toughness_of_0052baa8);
      pcVar4 = _itoa((int)*(short *)(&DAT_0051aec4 + iVar2 * 0x34),&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      break;
    case 2:
      strcat(&g_OverworldWorldState,s_requires_0052babc);
      pcVar4 = _itoa((int)(char)(&DAT_0051aebf)[iVar2 * 0x34],&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,&DAT_0052bac8);
      iVar3 = FUN_00473cc5((&DAT_0051aebe)[iVar2 * 0x34]);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(iVar3);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_and_0052bacc);
      pcVar4 = _itoa((int)(char)(&DAT_0051aec0)[iVar2 * 0x34],&DAT_0054b350,10);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_generic_mana_to_cast_0052bad4);
      break;
    case 3:
      strcat(&g_OverworldWorldState,s_has_flying_ability_0052baec);
      break;
    case 4:
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 1) != 0) {
        strcat(&g_OverworldWorldState,s_has_swampwalk_0052bb00);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 8) != 0) {
        strcat(&g_OverworldWorldState,s_has_mountainwalk_0052bb10);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 2) != 0) {
        strcat(&g_OverworldWorldState,s_has_islandwalk_0052bb24);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 4) != 0) {
        strcat(&g_OverworldWorldState,s_has_forestwalk_0052bb34);
      }
      if (((&DAT_0051aecc)[iVar2 * 0x34] & 0x10) != 0) {
        strcat(&g_OverworldWorldState,s_has_plainswalk_0052bb44);
      }
      strcat(&g_OverworldWorldState,s_ability_0052bb54);
      break;
    case 5:
      strcat(&g_OverworldWorldState,s_has_regeneration_ability_0052bb60);
      break;
    case 6:
      strcat(&g_OverworldWorldState,s_has_banding_ability_0052bb7c);
      break;
    case 7:
      strcat(&g_OverworldWorldState,s_has_first_strike_ability_0052bb90);
      break;
    case 8:
      strcat(&g_OverworldWorldState,s_has_trample_ability_0052bbac);
    }
    strcat(&g_OverworldWorldState,&DAT_0052bbc0);
    for (local_38 = 0; local_38 < local_14; local_38 = local_38 + 1) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + aiStack_34[local_38] * 0x34);
      strcat(&g_OverworldWorldState,&DAT_0052bbc4);
    }
    iVar2 = FUN_00489710(&g_OverworldWorldState,0x50,100);
    Adventure_LoadFacePalette(1);
    Ai_Subsystem_004cc50a
              (aiStack_34[local_c],(-(uint)(iVar2 == local_c) & 0x12) + 0xbc,
               s_The_correct_answer_is__0052bbc8);
    Ai_Subsystem_004cd1d1();
    bVar5 = iVar2 != local_c;
LAB_0049971a:
    return !bVar5;
  }
LAB_00499001:
  do {
    do {
      local_8 = FUN_0040a1d2(g_MasterCardCount + -0x29);
      if (((&g_MasterCardColorTable)[local_8 * 0x34] & 2) == 0) {
        if (local_44 != 2) goto LAB_00499001;
      }
    } while (((&DAT_0051aed6)[local_8 * 0x34] & 0xc1) == 0);
    bVar5 = false;
    switch(local_44) {
    case 0:
      bVar5 = *(short *)(&DAT_0051aec2 + local_8 * 0x34) != *(short *)(&DAT_0051aec2 + iVar2 * 0x34)
      ;
      break;
    case 1:
      bVar5 = *(short *)(&DAT_0051aec4 + local_8 * 0x34) != *(short *)(&DAT_0051aec4 + iVar2 * 0x34)
      ;
      break;
    case 2:
      if (((&DAT_0051aebe)[local_8 * 0x34] == (&DAT_0051aebe)[iVar2 * 0x34]) &&
         (((&DAT_0051aebf)[local_8 * 0x34] != (&DAT_0051aebf)[iVar2 * 0x34] ||
          ((&DAT_0051aebe)[local_8 * 0x34] != (&DAT_0051aebe)[iVar2 * 0x34])))) {
        bVar5 = true;
      }
      break;
    case 3:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x20) == 0;
      break;
    case 4:
      bVar5 = (*(uint *)(&DAT_0051aecc + local_8 * 0x34) & *(uint *)(&DAT_0051aecc + iVar2 * 0x34) &
              0x1f) == 0;
      break;
    case 5:
      bVar5 = ((&DAT_0051aecd)[local_8 * 0x34] & 2) == 0;
      break;
    case 6:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x40) == 0;
      break;
    case 7:
      bVar5 = ((&DAT_0051aecd)[local_8 * 0x34] & 1) == 0;
      break;
    case 8:
      bVar5 = ((&DAT_0051aecc)[local_8 * 0x34] & 0x80) == 0;
    }
    for (local_40 = 0; local_40 < local_38; local_40 = local_40 + 1) {
      if (aiStack_34[local_40] == aiStack_34[local_38]) {
        bVar5 = false;
      }
    }
  } while (!bVar5);
  aiStack_34[local_38] = local_8;
  local_38 = local_38 + 1;
  goto LAB_00498ff5;
}


