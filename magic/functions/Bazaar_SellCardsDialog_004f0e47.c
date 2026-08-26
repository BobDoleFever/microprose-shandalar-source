/*
 * Decompiled function: Bazaar_SellCardsDialog
 * Entry Point: 004f0e47
 * Size: 1899 bytes
 */
#include "magic.h"


int Bazaar_SellCardsDialog(int arg_1)

{
  int iVar1;
  uint arg_1_00;
  char *str_2;
  uint local_17a0;
  int local_1798;
  int local_1794;
  int local_1790;
  int aiStackY_178c [500];
  int local_fbc;
  int aiStackY_fb8 [500];
  int aiStackY_7e8 [493];
  undefined4 uStackY_34;
  int iVar2;
  int iVar3;
  
  Mem_AllocOrFree_00513bd0();
  Adventure_LoadFacePalette(1);
  local_1798 = 0;
  do {
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    FUN_0050d560(*(int *)g_DisplaySurfaceScreen,(-(uint)(arg_1 == 0) & 0xffffff0f) + 0xf4);
    Duel_TriggerCardDrawAnimation();
    iVar3 = 0;
    for (iVar2 = 0; iVar2 < 500; iVar2 = iVar2 + 1) {
    }
    local_1794 = 0;
    for (iVar2 = 499; -1 < iVar2; iVar2 = iVar2 + -1) {
      if (*(int *)(&deck + iVar2 * 4) != -1) {
        if (g_MasterCardCount + -0x1d < (int)(*(uint *)(&deck + iVar2 * 4) & 0xfff)) {
          *(undefined4 *)(&deck + iVar2 * 4) = 0xffffffff;
        }
        else if (local_1798 == 1) {
          if (((&DAT_00702151)[iVar2 * 4] & 0x40) == 0) goto LAB_004f108c;
        }
        else if ((local_1798 != 2) || (((&DAT_00702151)[iVar2 * 4] & 0x40) != 0)) {
LAB_004f108c:
          if (local_1798 == 0) {
            local_17a0 = *(uint *)(&deck + iVar2 * 4) & 0xc000;
          }
          else {
            local_17a0 = 0;
          }
          iVar2 = (0x28 < DAT_0067bde8) - 1;
          FUN_00484e2d(*(uint *)(&deck + local_17a0 * 4) & 0xfff,
                       (*(uint *)(&deck + local_17a0 * 4) & 7) + iVar3 + 4,iVar2,local_17a0,iVar2);
          iVar1 = iVar3 + 4;
          iVar2 = Ai_Util_004c3ba3(iVar1);
          aiStackY_fb8[local_1794] = iVar2;
          iVar2 = 0x4f1127;
          iVar1 = Ai_Util_004c3ba3(iVar1);
          aiStackY_178c[local_1794] = iVar1;
          aiStackY_7e8[local_1794] = iVar2;
          local_1794 = local_1794 + 1;
          iVar3 = iVar3 + 0x40;
          if (0x13f < iVar3) {
            iVar3 = 0;
          }
        }
      }
    }
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    uStackY_34 = 0x4f11b4;
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
    if (arg_1 == 0) {
      Ai_Subsystem_004cd1d1();
      return 0;
    }
    if (0 < arg_1) {
      FUN_0040c3cc(s_F1__all_cards__F2__active_cards__00530004,0xa0,2,0);
    }
    Pic_Subsystem_0044b8aa();
    do {
      Pic_Subsystem_0044b84b();
      if (DAT_0067bda0 != 0) break;
      iVar2 = Mem_AllocOrFree_00408089();
    } while (iVar2 == 0);
    Pic_Subsystem_0044b8da();
    if (DAT_0067bda0 == 0) {
      local_fbc = FUN_0048ac2f();
      if (local_fbc == 0x72) {
        FUN_00484691(4,0);
      }
      else if (local_fbc == 0x52) {
        FUN_00484691(4,1);
      }
      else if (local_fbc == 0x62) {
        FUN_00484691(1,0);
      }
      else if (local_fbc == 0x42) {
        FUN_00484691(1,1);
      }
      else if (local_fbc == 0x75) {
        FUN_00484691(2,0);
      }
      else if (local_fbc == 0x55) {
        FUN_00484691(2,1);
      }
      else if (local_fbc == 0x67) {
        FUN_00484691(3,0);
      }
      else if (local_fbc == 0x47) {
        FUN_00484691(3,1);
      }
      else if (local_fbc == 0x77) {
        FUN_00484691(5,0);
      }
      else if (local_fbc == 0x57) {
        FUN_00484691(5,1);
      }
      else if (local_fbc == 0x3b00) {
        local_1798 = 0;
      }
      else if (local_fbc == 0x3c00) {
        local_1798 = 1;
      }
      else if (local_fbc == 0x3d00) {
        local_1798 = 2;
      }
      else {
        if (local_fbc != 0x3f00) {
          return -1;
        }
        Palette_Subsystem_004981b5(1);
      }
    }
    else {
      local_1790 = -1;
      for (iVar2 = 0; iVar2 < local_1794; iVar2 = iVar2 + 1) {
        if ((((aiStackY_fb8[iVar2] <= DAT_0067bda4) && (DAT_0067bda4 < aiStackY_fb8[iVar2] + 0x62))
            && (aiStackY_178c[iVar2] <= DAT_0067bda8)) &&
           (DAT_0067bda8 < aiStackY_178c[iVar2] + 0x74)) {
          local_1790 = aiStackY_7e8[iVar2];
        }
      }
      if (arg_1 == -1) {
        return local_1790;
      }
      if (local_1790 == -1) {
        return local_1794;
      }
      if (DAT_0067bda0 == 2) {
        arg_1_00 = *(uint *)(&deck + local_1790 * 4) & 0xfff;
        iVar2 = SellPrice(arg_1_00);
        strcpy(&g_OverworldWorldState,s_Sell_00530048);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + arg_1_00 * 0x34);
        strcat(&g_OverworldWorldState,s_for_00530050);
        str_2 = _itoa(iVar2,&DAT_00565a10,10);
        strcat(&g_OverworldWorldState,str_2);
        strcat(&g_OverworldWorldState,s_gold___Y_N__00530058);
        Ai_Subsystem_004cc50a(arg_1_00,0xf6,&g_OverworldWorldState);
        iVar3 = FUN_0048ac2f();
        if (iVar3 == 0x79) {
          Gold = Gold + iVar2;
          Pic_Subsystem_00452065(local_1790);
        }
      }
      if (DAT_0067bda0 == 1) {
        *(uint *)(&deck + local_1790 * 4) = *(uint *)(&deck + local_1790 * 4) ^ 0x4000;
      }
      FUN_0040a3e1();
    }
  } while( true );
}


