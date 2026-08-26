/*
 * Decompiled function: Adventure_NewsFlash_EnemyAttack
 * Entry Point: 004eade5
 * Size: 1279 bytes
 */
#include "magic.h"


void Adventure_NewsFlash_EnemyAttack(void)

{
  int *piVar1;
  byte arg_1;
  undefined4 uVar2;
  char *str_2;
  int aiStack_80 [7];
  uint local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int aiStack_50 [7];
  int aiStack_34 [7];
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (DAT_006410b0 == 0) {
    FUN_0040a3e1();
    for (local_18 = 0; local_18 < 7; local_18 = local_18 + 1) {
      aiStack_34[local_18] = -1;
      aiStack_80[local_18] = 0;
    }
    for (local_18 = 0; local_18 < 0x80; local_18 = local_18 + 1) {
      if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
        uVar2 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_18 * 100),
                             *(int *)(&DAT_0067bdf8 + local_18 * 100));
        arg_1 = Adventure_GetLocationEncounterIndex(uVar2);
        local_60 = FUN_00473cc5(arg_1);
        aiStack_34[local_60] = *(int *)(&DAT_0067bdf4 + local_18 * 100);
        aiStack_50[local_60] = *(int *)(&DAT_0067bdf8 + local_18 * 100);
      }
      if ((&DAT_0067be01)[local_18 * 100] != '\0') {
        piVar1 = (int *)((int)aiStack_80 +
                        ((int)(*(uint *)(&DAT_0067be00 + local_18 * 100) & 0xffffff3f) >> 6));
        *piVar1 = *piVar1 + 1;
      }
    }
    local_5c = 0x7fff;
    local_60 = -1;
    for (local_64 = 0; (int)local_64 < 0x80; local_64 = local_64 + 1) {
      if (((((&DAT_0067be01)[local_64 * 100] == '\0') &&
           (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 4)) &&
          (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 1)) &&
         (*(int *)(&DAT_0067bdf0 + local_64 * 100) != 5)) {
        local_58 = 0x7fff;
        for (local_18 = 1; local_18 < 6; local_18 = local_18 + 1) {
          if (aiStack_34[local_18] != -1) {
            local_10 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_64 * 100) - aiStack_34[local_18],
                                    *(int *)(&DAT_0067bdf8 + local_64 * 100) - aiStack_50[local_18])
            ;
            if (local_10 < local_58) {
              local_58 = local_10;
              local_60 = local_18;
            }
          }
        }
        local_8 = FUN_0040a1d2(0x80);
        local_8 = local_8 + aiStack_80[local_60] * 0x20;
        if (local_8 < local_5c) {
          local_5c = local_8;
          local_c = local_64;
          local_54 = local_60;
        }
      }
    }
    local_60 = local_54;
    local_64 = local_c;
    if (local_54 != -1) {
      local_18 = 7;
      switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
      case 0:
        local_14 = 4;
        break;
      case 1:
        local_14 = 6;
        break;
      case 2:
        local_14 = 8;
        break;
      case 3:
        local_14 = 0xc;
        break;
      default:
        if (((&DAT_0067bdf8)[local_c * 100] & 1) == 0) {
          local_14 = 0x10;
        }
        else {
          local_14 = 0xc;
        }
      }
      FUN_0046e70d(7,0xf);
      uVar2 = Adventure_CheckMonsterEncounter(local_60,local_14);
      *(undefined4 *)(&DAT_0067f2d0 + local_18 * 0x14) = uVar2;
      *(int *)(&DAT_0067f2d4 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf4 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2d8 + local_18 * 0x14) =
           *(int *)(&DAT_0067bdf8 + local_64 * 100) * 0x20 + 0x10;
      *(int *)(&DAT_0067f2dc + local_18 * 0x14) = local_60;
      DAT_006410b4 = DAT_006410b4 + 1;
      FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + local_64 * 100),
                   *(int *)(&DAT_0067bdf8 + local_64 * 100));
      Adventure_Audio_PlayEffect(s_x_sound_newsflash_wav_0052f510,0x97,100,100,0);
      FUN_0040a95d(s_newsback_pic_0052f528);
      strcpy(&g_OverworldWorldState,s_____NEWS_FLASH_____0052f538);
      str_2 = (char *)Mem_AllocOrFree_00473d7e(local_60);
      strcat(&g_OverworldWorldState,str_2);
      strcat(&g_OverworldWorldState,s_Wizard_sends_0052f550);
      Adventure_FormatNewsString(*(int *)(&DAT_0067f2d0 + local_18 * 0x14),1,0);
      strcat(&g_OverworldWorldState,s_to_attack_0052f560);
      Ai_TownEncounter_004c3b19(local_64);
      strcat(&g_OverworldWorldState,&DAT_0052f56c);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xbe,0x140,0xf7);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      Ai_Subsystem_004c05ba();
      DAT_006410b0 = 1;
    }
  }
  return;
}


