/*
 * Decompiled function: Adventure_EnterTownLocation
 * Entry Point: 004e73a0
 * Size: 1405 bytes
 */
#include "magic.h"


undefined4 Adventure_EnterTownLocation(void)

{
  bool bVar1;
  byte arg_1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  clock_t cVar6;
  int local_c;
  
  bVar1 = false;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  Ai_Subsystem_004cd3eb();
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    *(undefined4 *)(&g_PlayerLifeTotals + local_c * 4) = 8;
  }
  Hints_Load_004071ce();
  Csv_ReadConcise_0040659f();
  Mem_AllocOrFree_00512220(1,1,DAT_00677690);
  Pic_Subsystem_0044b8aa();
  Pic_Subsystem_0044b8da();
  GdiGetBatchLimit();
  GdiSetBatchLimit(100);
  LoadPalNoPic(s_advfac64_pic_0052f0c0);
  Sprite_LoadAll(&DAT_006781d0,s_dbox_spr_0052f0d0);
  do {
    iVar2 = Sprite_Load_begin_0047a2e6();
    FUN_005112b0(0,(short)DAT_00530d9c);
    switch(iVar2) {
    case 0:
      while( true ) {
        DAT_0067f380 = Pic_Load_menu2_hi_0047abf1();
        FUN_005112b0(0,(short)DAT_00530d9c);
        if (DAT_0067f380 == -1) break;
        while( true ) {
          DAT_0052effc = Pic_Load_menu3_but1_0047b208();
          DAT_006410d8 = DAT_0052effc;
          DAT_006fe448 = DAT_0052effc;
          DAT_006fe44c = FUN_0040a1d2(3);
          FUN_005112b0(0,(short)DAT_00530d9c);
          if (DAT_006410d8 == -1) break;
          DAT_006ff678 = Sprite_Load__16faces_0047b899();
          FUN_005112b0(0,(short)DAT_00530d9c);
          if (DAT_006ff678 != -1) {
            DAT_0052f000 = 1 << ((byte)DAT_0052effc & 0x1f);
            LoadPalNoPic(s_advfac64_pic_0052f0dc);
            Mem_AllocOrFree_00510e20(1,PTR_s_advinter800_pic_00530d98);
            FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                         (int *)g_DisplaySurfaceScreen,0,0);
            DAT_0067f388 = 0;
            Palette_Subsystem_00496ccf();
            bVar1 = true;
            *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
            FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xff,0x140,0xbc);
            DAT_0064101c = 1;
            FUN_0046e960();
            Pic_Subsystem_0044d680();
            FUN_0048e306();
            Gold = (5 - DAT_0067f380) * 0x32;
            DAT_0052f00c = 0;
            goto switchD_004e765f_default;
          }
        }
      }
      break;
    case 1:
      DAT_0067f388 = 0;
      iVar4 = Mem_AllocOrFree_0048e108();
      FUN_0048c72a(iVar4);
    default:
switchD_004e765f_default:
      for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
        if (*(int *)(&DAT_0067bdf0 + local_c * 100) == 5) {
          uVar3 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_c * 100),
                               *(int *)(&DAT_0067bdf8 + local_c * 100));
          arg_1 = Adventure_GetLocationEncounterIndex(uVar3);
          iVar4 = FUN_00473cc5(arg_1);
          *(undefined4 *)(&DAT_006410c0 + (iVar4 + -1) * 4) = 1;
        }
      }
      FUN_00409d10();
      if (!bVar1) {
        Palette_Subsystem_00496ccf();
      }
      Castle_Process_0046c8b0();
      FUN_0041edd4();
      Adventure_Map_RedrawViewport();
      if (iVar2 != 0) {
        Pic_Subsystem_004520b2();
      }
      LoadPalNoPic(s_advfac64_pic_0052f108);
      Ai_Subsystem_004c05ba();
      if (iVar2 == 0) {
        do {
          do {
            iVar2 = FUN_0040a1d2(0x40);
            DAT_0052eff0 = iVar2 * 0x20 + 0x10;
            iVar2 = FUN_0040a1d2(0x40);
            DAT_0052eff4 = iVar2 * 0x20 + 0x10;
            uVar3 = FUN_0040c761((int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                                 (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
            uVar5 = Adventure_GetLocationEncounterIndex(uVar3);
          } while ((uVar5 & DAT_0052f000) == 0);
          uVar5 = FUN_0040c7c0((int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                               (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
        } while ((uVar5 & 0x10) != 0);
      }
      DAT_005659bc = 0;
      DAT_0067bde8 = 0;
      DAT_0067f3b8 = 0;
      for (local_c = 0; local_c < 500; local_c = local_c + 1) {
        if ((*(int *)(&deck + local_c * 4) != -1) &&
           (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_c * 4] & 0x40) == 0)) {
          DAT_0067f3b8 = DAT_0067f3b8 + 1;
        }
      }
      do {
        Mem_AllocOrFree_005016f9();
        Ai_Subsystem_004be643(DAT_0052eff0,DAT_0052eff4,DAT_005659dc);
        DAT_005659dc = 0;
        do {
          cVar6 = clock();
        } while (cVar6 < 0x3c);
        clock();
        if ((DAT_007039c4 & 2) != 0) {
          Adventure_PromptLocationMenu();
        }
        Adventure_ExitTownLocation();
        Adventure_PlayLocationMusic();
        Adventure_UpdateWorldMapLoop();
        Adventure_TriggerDuelFromEncounter();
        Pic_Subsystem_0044b84b();
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        DAT_0067f37c = DAT_0067f37c + 1;
        FUN_0040a3e1();
        Mem_AllocOrFree_0040a422();
      } while (DAT_006fe3f0 == 0);
      FUN_005112b0(0,(short)DAT_00530d9c);
      FUN_00409db6();
      uVar3 = Palette_Util_00496d20();
      return uVar3;
    case 2:
      DAT_0067f388 = 0;
      FUN_0048c72a(3);
      goto switchD_004e765f_default;
    case 3:
      goto switchD_004e765f_default;
    case 4:
      DAT_006fe3f0 = 1;
      return 0;
    }
  } while( true );
}


