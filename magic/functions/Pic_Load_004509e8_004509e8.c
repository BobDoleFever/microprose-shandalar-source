/*
 * Decompiled function: Pic_Load_004509e8
 * Entry Point: 004509e8
 * Size: 2212 bytes
 */
#include "magic.h"


int Pic_Load_004509e8(int arg_1,int arg_2,int arg_3,undefined4 arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  char *in_stack_00000018;
  int local_1800;
  void *local_17fc;
  undefined4 local_17f8;
  undefined4 local_17f4;
  undefined4 auStackY_17f0 [6];
  undefined4 auStackY_17d8 [4];
  undefined4 auStackY_17c8 [6];
  undefined4 local_17b0;
  void *apvStackY_17ac [4];
  int local_179c;
  undefined4 local_1798;
  int local_1794;
  int local_1790;
  int local_178c;
  int local_1788;
  int aiStackY_1784 [500];
  int aiStackY_fb4 [500];
  int local_7e4;
  int local_7e0;
  int local_7dc;
  int aiStackY_7d8 [487];
  undefined4 uStackY_3c;
  int *piVar6;
  void *arg_6;
  int iVar7;
  
  Mem_AllocOrFree_00513bd0();
  if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
    if (DAT_0063ee18 == 0) {
      Catalog_LoadPaletteMap(s_todpal_tr_00523e50,(char *)0x0);
      FUN_0050d560(0,0);
      SelectPalette(_hdcScreen,DAT_00626834,0);
      LoadPalNoPic(s_advfac64_pic_00523e5c);
      FUN_00510b70(1,0,0,s_seedeck_pic_00523e6c,(short *)&DAT_0070a130);
      uStackY_3c = 0x450b44;
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      local_1788 = 0;
      for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
        if ((*(int *)(arg_2 + iVar7 * 4) != -1) &&
           ((iVar7 == 0 || (*(int *)(arg_2 + -4 + iVar7 * 4) != *(int *)(arg_2 + iVar7 * 4))))) {
          local_1788 = local_1788 + 1;
        }
      }
      local_7dc = (local_1788 + -1) / 5;
      if (local_7dc == 0) {
        local_7dc = 1;
      }
      local_1790 = (int)(0x54 / (longlong)local_7dc);
      local_7e0 = 0x60;
      local_7dc = 0;
      local_7e4 = 0x10;
      for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
        if ((*(int *)(arg_2 + iVar7 * 4) != -1) &&
           ((iVar7 == 0 || (*(int *)(arg_2 + -4 + iVar7 * 4) != *(int *)(arg_2 + iVar7 * 4))))) {
          aiStackY_fb4[local_7dc] = local_7e0 + 4;
          aiStackY_1784[local_7dc] = local_7e4;
          aiStackY_7d8[local_7dc] = iVar7;
          local_7dc = local_7dc + 1;
          local_7e0 = local_7e0 + 0x38;
          if (0x13f < local_7e0) {
            local_7e0 = 0x60;
            local_7e4 = local_7e4 + local_1790;
          }
        }
      }
      FUN_0040c421(arg_4,0xa0,2,0xff);
      local_179c = -1;
      local_1794 = 0;
      Sprite_LoadAll(&local_17fc,s_BuyButtons_spr_00523e78);
      apvStackY_17ac[3] = local_17fc;
      local_1798 = local_17f8;
      local_17b0 = local_17f4;
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        apvStackY_17ac[local_1800] = (void *)auStackY_17f0[local_1800];
      }
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        auStackY_17c8[local_1800 + 3] = auStackY_17f0[local_1800 + 3];
      }
      for (local_1800 = 0; local_1800 < 3; local_1800 = local_1800 + 1) {
        auStackY_17c8[local_1800] = auStackY_17f0[local_1800 + 6];
      }
      for (iVar7 = 0; iVar7 < local_7dc; iVar7 = iVar7 + 1) {
        FUN_0050b206(*(uint *)(arg_2 + aiStackY_7d8[iVar7] * 4) & 0xfff,aiStackY_fb4[iVar7],
                     aiStackY_1784[iVar7],0,&DAT_00523e88);
      }
      while( true ) {
        do {
          Pic_Subsystem_0044b84b();
          local_178c = -1;
          DAT_0067bda4 = (DAT_0067bda4 * 0x140) / DAT_00522458;
          DAT_0067bda8 = (DAT_0067bda8 * 0xf0) / DAT_0052245c;
          for (iVar7 = 0; iVar7 < local_7dc; iVar7 = iVar7 + 1) {
            if ((((aiStackY_fb4[iVar7] <= DAT_0067bda4) &&
                 (DAT_0067bda4 < aiStackY_fb4[iVar7] + 0x30)) &&
                (aiStackY_1784[iVar7] <= DAT_0067bda8)) &&
               (DAT_0067bda8 < aiStackY_1784[iVar7] + 0x30)) {
              local_178c = aiStackY_7d8[iVar7];
            }
          }
          if ((local_178c != -1) &&
             (*(int *)(arg_2 + local_179c * 4) != *(int *)(arg_2 + local_178c * 4))) {
            FUN_0050b206(*(uint *)(arg_2 + local_178c * 4) & 0xfff,8,0x40,1,&DAT_00523e8c);
            local_179c = local_178c;
          }
          if (arg_5 == 0) {
            if ((DAT_0067bda0 == 0) && (iVar7 = Mem_AllocOrFree_00408089(), iVar7 == 0)) {
              local_1794 = 0;
            }
            else {
              local_1794 = 1;
            }
          }
          else if (((DAT_0067bda0 == 0) && (iVar7 = Mem_AllocOrFree_00408089(), iVar7 == 0)) ||
                  (local_178c == -1)) {
            local_1794 = 0;
          }
          else {
            local_1794 = 1;
          }
        } while (local_1794 == 0);
        if (arg_5 == 0) break;
        iVar7 = Ai_Util_004c3ba3(0x34);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xdc);
        iVar1 = iVar1 / 2;
        piVar6 = (int *)g_DisplaySurfaceBackBuffer;
        iVar2 = Ai_Util_004c3ba3(0x111);
        DVar3 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0xc5);
        uVar4 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        FUN_0050dce0((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar2,uVar4,DVar3,piVar6,iVar1,iVar7);
        strcpy(&g_OverworldWorldState,s_Take_00523e90);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + *(int *)(arg_2 + local_178c * 4) * 0x34);
        strcat(&g_OverworldWorldState,s__Y_N__00523e98);
        arg_6 = apvStackY_17ac[3];
        iVar7 = Ai_Util_004c3ba3(0x10f);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xc5);
        iVar1 = iVar1 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar2,iVar1,iVar7,(int)arg_6);
        FUN_0050b3de(*(uint *)(arg_2 + local_178c * 4) & 0xfff,0x7a,0x29,0x4b,0x70,1,&DAT_00523ea4);
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        FUN_0040c381(&g_OverworldWorldState,0x76,0x20,0x1b);
        iVar7 = FUN_0048ac2f();
        if ((iVar7 == 0x79) || (iVar7 == 0x59)) break;
        iVar7 = Ai_Util_004c3ba3(0x34);
        iVar7 = iVar7 / 2;
        iVar1 = Ai_Util_004c3ba3(0xdc);
        iVar1 = iVar1 / 2;
        piVar6 = (int *)g_DisplaySurfaceScreen;
        iVar2 = Ai_Util_004c3ba3(0x111);
        DVar3 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0xc5);
        uVar4 = iVar2 / 2;
        iVar2 = Ai_Util_004c3ba3(0x34);
        iVar2 = iVar2 / 2;
        iVar5 = Ai_Util_004c3ba3(0xdc);
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,iVar5 / 2,iVar2,uVar4,DVar3,piVar6,iVar1,
                     iVar7);
        FUN_0040a3e1();
      }
      Mem_AllocOrFree_0050fc50(apvStackY_17ac[3]);
      Palette_Subsystem_00496eaf();
    }
    else {
      local_178c = Ai_Subsystem_004cc455((int *)arg_2,arg_3,arg_4,arg_5,in_stack_00000018);
    }
  }
  else {
    local_7dc = 0;
    for (iVar7 = 0; iVar7 < arg_3; iVar7 = iVar7 + 1) {
      if (*(int *)(arg_2 + iVar7 * 4) != -1) {
        aiStackY_7d8[local_7dc] = iVar7;
        local_7dc = local_7dc + 1;
      }
    }
    g_AiDecisionScore = FUN_0040a1d2(local_7dc);
    if (g_CurrentTurnPhase != arg_1) {
      if (g_IsAiThinking == 1) {
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
    }
    local_178c = aiStackY_7d8[g_AiDecisionScore];
  }
  return local_178c;
}


