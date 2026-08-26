/*
 * Decompiled function: Palette_Color_0049716e
 * Entry Point: 0049716e
 * Size: 4152 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Palette_Color_0049716e(undefined4 arg_1,uint arg_2,uint arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 arg_1_00;
  char *str_2;
  int iVar7;
  int *piVar8;
  int local_160;
  undefined *local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_144;
  int local_140;
  uint local_13c;
  byte local_138;
  int local_134;
  int local_130;
  uint local_12c;
  int local_128;
  uint auStack_124 [64];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 1;
  FUN_0040a3e1();
  if (arg_4 != 0) {
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_tradscrn_pic_0052b850,(short *)0x0);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  if (arg_5 != 0) {
    Sprite_LoadAll(&DAT_0064a0b0,s_buyAny_spr_0052b860);
    if (DAT_0052b780 == DAT_0052b770) {
      DAT_0052b780 = Ai_Util_004c3bc4(DAT_0052b780);
      DAT_0052b784 = Ai_Util_004c3bc4(DAT_0052b784);
      DAT_0052b788 = Ai_Util_004c3bc4(DAT_0052b788);
      DAT_0052b78c = Ai_Util_004c3bc4(DAT_0052b78c);
    }
    iVar1 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(iVar1);
    FUN_0041f17e(0x52b770,1,iVar1);
    FUN_0041f213();
  }
  if (arg_3 == 0xffffffff) {
    if (arg_4 != 0) {
      arg_3 = 0;
      DAT_0052b734 = 1;
    }
  }
  else {
    DAT_0052b734 = arg_3;
    arg_3 = 1 << ((byte)arg_3 & 0x1f);
    if (arg_3 == 0x10) {
      arg_3 = 0x30;
    }
  }
  if ((arg_2 != 0) && (arg_4 != 0)) {
    _DAT_0052b730 = FUN_00473cc5((byte)arg_2);
  }
  if (arg_4 != 0) {
    DAT_0052b738 = 0xffffffff;
  }
  do {
    if (local_10 != 0) {
      iVar1 = Ai_Util_004c3bc4(0x8c);
      iVar2 = Ai_Util_004c3bc4(0x21);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x132);
      uVar4 = Ai_Util_004c3bc4(0x8b);
      iVar5 = Ai_Util_004c3bc4(0x8c);
      uVar6 = Ai_Util_004c3bc4(0x21);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x8c);
      iVar2 = Ai_Util_004c3bc4(0x1d4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x132);
      uVar4 = Ai_Util_004c3bc4(0x8b);
      iVar5 = Ai_Util_004c3bc4(0x8c);
      uVar6 = Ai_Util_004c3bc4(0x21);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x1bf);
      iVar2 = Ai_Util_004c3bc4(0xb4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x1d);
      uVar4 = Ai_Util_004c3bc4(0x118);
      iVar5 = Ai_Util_004c3bc4(0x1bf);
      uVar6 = Ai_Util_004c3bc4(0xb4);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x158);
      iVar2 = Ai_Util_004c3bc4(0xe9);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x68);
      uVar4 = Ai_Util_004c3bc4(0xae);
      iVar5 = Ai_Util_004c3bc4(0x158);
      uVar6 = Ai_Util_004c3bc4(0xe9);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x10);
      iVar2 = Ai_Util_004c3bc4(0x1db);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x5e);
      uVar4 = Ai_Util_004c3bc4(0x7c);
      iVar5 = Ai_Util_004c3bc4(0x10);
      uVar6 = Ai_Util_004c3bc4(0x1db);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
      iVar1 = Ai_Util_004c3bc4(0x27);
      iVar2 = Ai_Util_004c3bc4(0xe4);
      piVar8 = (int *)g_DisplaySurfaceScreen;
      DVar3 = Ai_Util_004c3bc4(0x19);
      uVar4 = Ai_Util_004c3bc4(0xb8);
      iVar5 = Ai_Util_004c3bc4(0x27);
      uVar6 = Ai_Util_004c3bc4(0xe4);
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
    }
    local_10 = 0;
    iVar1 = Ai_Util_004c3bc4(0x157);
    iVar2 = Ai_Util_004c3bc4(0xe8);
    piVar8 = (int *)g_DisplaySurfaceScreen;
    DVar3 = Ai_Util_004c3bc4(0x66);
    uVar4 = Ai_Util_004c3bc4(0xac);
    iVar5 = Ai_Util_004c3bc4(0x157);
    uVar6 = Ai_Util_004c3bc4(0xe8);
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,uVar6,iVar5,uVar4,DVar3,piVar8,iVar2,iVar1);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0x16,0x140,0x34);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    iVar1 = Ai_Util_004c3ba3(0x6b);
    iVar2 = Ai_Util_004c3ba3(0x45);
    iVar5 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_130 = iVar2 / 2 - (iVar5 * 6) / 2;
    for (local_12c = 0; (int)local_12c < 6; local_12c = local_12c + 1) {
      if (local_12c == 0) {
        if (_DAT_0052b730 == 0) {
          local_14c = 0x1b;
        }
        else if (arg_2 == 0) {
          local_14c = 0x62;
        }
        else {
          local_14c = 0;
        }
        FUN_0040c421(s_Colorless_0052b86c,iVar1 / 2,local_130,local_14c);
      }
      else {
        if (local_12c == _DAT_0052b730) {
          local_150 = 0x1b;
        }
        else if (arg_2 == 0) {
          local_150 = 0x62;
        }
        else {
          local_150 = 0;
        }
        iVar2 = iVar1 / 2;
        iVar5 = local_130;
        arg_1_00 = Mem_AllocOrFree_00473d7e(local_12c);
        FUN_0040c421(arg_1_00,iVar2,iVar5,local_150);
      }
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      local_130 = local_130 + iVar2;
    }
    iVar1 = Ai_Util_004c3ba3(0x215);
    iVar2 = Ai_Util_004c3ba3(0x45);
    iVar5 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_130 = iVar2 / 2 - (iVar5 * 6) / 2;
    local_1c = local_130;
    local_18 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_12c = 0; (int)local_12c < 6; local_12c = local_12c + 1) {
      if (_DAT_0052b730 == 0) {
        if (local_12c == DAT_0052b734) {
          local_158 = 0x1b;
        }
        else if (arg_3 == 0) {
          local_158 = 0x62;
        }
        else {
          local_158 = 0x62;
        }
        if ((int)local_12c < 2) {
          local_15c = (&PTR_DAT_0052b750)[local_12c];
        }
        else {
          local_15c = (undefined *)(&DAT_0052b738)[local_12c];
        }
        FUN_0040c421(local_15c,iVar1 / 2,local_130,local_158);
      }
      else {
        if (local_12c == DAT_0052b734) {
          local_154 = 0x1b;
        }
        else if (arg_3 == 0) {
          local_154 = 0x62;
        }
        else {
          local_154 = 0x62;
        }
        FUN_0040c421((&PTR_DAT_0052b750)[local_12c],iVar1 / 2,local_130,local_154);
      }
      iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      local_130 = local_130 + iVar2;
    }
    local_13c = DAT_0052b734;
    if ((_DAT_0052b730 == 0) && (1 < (int)DAT_0052b734)) {
      local_140 = DAT_0052b734 - 1;
      local_13c = 6;
    }
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xff,0xfe,0x1ce);
    for (local_12c = 0; (int)local_12c < 5; local_12c = local_12c + 1) {
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xff,local_12c * 0x23 + 0x131,0x1ce);
    }
    iVar1 = Ai_Util_004c3ba3(0x11e);
    local_20 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_20 = (iVar1 / 2) / local_20;
    local_24 = 0;
    local_128 = Ai_Util_004c3ba3(0x66);
    local_128 = local_128 / 2;
    local_130 = Ai_Util_004c3ba3(0x99);
    local_130 = local_130 / 2;
    local_c = local_130;
    local_8 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_12c = 0; (int)local_12c < g_MasterCardCount + -0x29; local_12c = local_12c + 1) {
      if (((_DAT_0052b730 != 0) || (local_13c != 6)) ||
         (iVar1 = FUN_0040a305((int)(char)(&DAT_0051aed4)[local_12c * 0x34],1,3), iVar1 == local_140
         )) {
        local_14 = (uint)(char)(&DAT_0051aebe)[local_12c * 0x34];
        if (local_14 == 0) {
          local_14 = 1;
        }
        if ((((((local_14 & 1 << (DAT_0052b730 & 0x1f)) != 0) &&
              ((1 << ((byte)local_13c & 0x1f) &
               (uint)(byte)(&g_MasterCardColorTable)[local_12c * 0x34]) != 0)) &&
             ((((&DAT_0051aed1)[local_12c * 0x34] & 9) == 0 || (DAT_0067b9a4 != 0)))) &&
            ((iVar1 = FUN_00485005(local_12c), iVar1 != 0 &&
             ((arg_2 == 0 || ((local_14 & arg_2) != 0)))))) &&
           (((arg_3 == 0 || ((arg_3 & (byte)(&g_MasterCardColorTable)[local_12c * 0x34]) != 0)) &&
            (((&g_MasterCardColorTable)[local_12c * 0x34] != 'B' || (local_13c != 6)))))) {
          local_144 = 0;
          for (local_134 = 0; local_134 < 500; local_134 = local_134 + 1) {
            if ((*(uint *)(&deck + local_134 * 4) & 0xfff) == local_12c) {
              local_144 = local_144 + 1;
            }
          }
          strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + local_12c * 0x34);
          if (local_144 != 0) {
            strcat(&g_OverworldWorldState,&DAT_0052b880);
            str_2 = _itoa(local_144,&DAT_0054b350,10);
            strcat(&g_OverworldWorldState,str_2);
          }
          if (DAT_0052b738 == 0xffffffff) {
            DAT_0052b738 = local_12c;
          }
          if (local_12c == DAT_0052b738) {
            local_160 = 0x1b;
          }
          else {
            iVar1 = Duel_UpdateCardMotionStep(local_12c);
            if (iVar1 < 1) {
              local_160 = 3;
            }
            else {
              local_160 = 0x54;
            }
          }
          FUN_0040c421(&g_OverworldWorldState,local_128,local_130,local_160);
          auStack_124[local_24] = local_12c;
          local_24 = local_24 + 1;
          iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
          local_130 = local_130 + iVar1;
          if (local_20 == local_24) {
            local_128 = Ai_Util_004c3ba3(0x219);
            local_128 = local_128 / 2;
            local_130 = Ai_Util_004c3ba3(0x99);
            local_130 = local_130 / 2;
          }
        }
      }
    }
    if (DAT_0052b738 != 0xffffffff) {
      DAT_0052b73c = DAT_0052b738;
      FUN_0050b3de(DAT_0052b738,0x7b,0x33,0x4b,0x70,1,&DAT_0052b884);
    }
    Pic_Subsystem_0044b8aa();
    DAT_0054b34c = -1;
    while ((Pic_Subsystem_0044b84b(), arg_5 == 0 || (DAT_007039c4 == 0))) {
      if (DAT_007039c4 != 0) goto LAB_00497f4a;
      if (arg_5 != 0) {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
      }
    }
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
    if (0 < DAT_0054b34c) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      FUN_0040a3e1();
      Palette_Subsystem_00496eaf();
      return 0xffffffff;
    }
LAB_00497f4a:
    iVar5 = DAT_007039c4;
    iVar2 = DAT_0067bda8;
    iVar1 = DAT_0067bda4;
    FUN_0040a3e1();
    Pic_Subsystem_0044b8da();
    iVar7 = Ai_Util_004c3ba3(0x66);
    if ((((iVar7 / 2 < iVar2) && (iVar7 = Ai_Util_004c3ba3(0x146), iVar2 < iVar7 / 2)) &&
        (iVar7 = Ai_Util_004c3ba3(0xf6), iVar7 / 2 < iVar1)) &&
       (iVar7 = Ai_Util_004c3ba3(0x18c), iVar1 < iVar7 / 2)) {
      if (arg_5 != 0) {
        FUN_0041f391();
        Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      }
      Palette_Subsystem_00496eaf();
      return DAT_0052b73c;
    }
    if (iVar5 == 0) {
      if (arg_5 != 0) {
        FUN_0041f391();
      }
      Mem_AllocOrFree_0050fc50(DAT_0064a0b0);
      Palette_Subsystem_00496eaf();
      return 0xffffffff;
    }
    iVar5 = Ai_Util_004c3ba3(0x6d);
    if (iVar2 < iVar5 / 2) {
      uVar4 = (iVar2 - local_1c) / local_18;
      iVar2 = Ai_Util_004c3bc4(0xac);
      if (iVar1 < iVar2) {
        if (((-1 < (int)uVar4) && ((int)uVar4 < 6)) &&
           ((arg_2 == 0 || (local_138 = (byte)uVar4, 1 << (local_138 & 0x1f) == arg_2)))) {
          DAT_0052b738 = 0xffffffff;
          local_10 = 1;
          _DAT_0052b730 = uVar4;
        }
      }
      else {
        iVar2 = Ai_Util_004c3bc4(0x1d6);
        if (((iVar2 < iVar1) && (-1 < (int)uVar4)) && ((int)uVar4 < 6)) {
          DAT_0052b738 = 0xffffffff;
          local_10 = 1;
          DAT_0052b734 = uVar4;
        }
      }
    }
    else {
      iVar5 = Ai_Util_004c3ba3(0x96);
      if ((iVar5 / 2 < iVar2) &&
         (iVar1 = (iVar2 - local_c) / local_8 + (iVar1 / ((int)DAT_00522458 / 2)) * local_20,
         iVar1 < local_24)) {
        DAT_0052b738 = auStack_124[iVar1];
      }
    }
  } while( true );
}


