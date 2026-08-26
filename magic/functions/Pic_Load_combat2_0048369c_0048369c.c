/*
 * Decompiled function: Pic_Load_combat2_0048369c
 * Entry Point: 0048369c
 * Size: 3951 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Load_combat2_0048369c(int arg1,int arg2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int local_3c;
  int local_38;
  int local_34;
  int local_24;
  uint local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    _DAT_00539598 = 0;
    iVar1 = 1 - arg1;
    DAT_0063ee78 = 0;
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      if (local_18 == g_CurrentTurnPhase) {
        local_3c = 0x174;
      }
      else {
        local_3c = 0xac;
      }
      for (local_34 = 0; local_34 < 7; local_34 = local_34 + 1) {
        for (local_1c = 0; (int)local_1c < *(int *)(&DAT_0063ee90 + local_34 * 4 + local_18 * 0x20);
            local_1c = local_1c + 1) {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,0x68,local_3c + 3,0x14,0xe,
                           (-(uint)(local_18 == 0) & 0x23) + 0xdc);
          Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,0x66,local_3c,
                            *(int *)(&DAT_0067f390 + local_34 * 4));
          local_3c = local_3c + -0x10;
        }
      }
    }
    local_3c = 0x86;
    local_38 = 0x82;
    local_8 = 0x41;
    local_10 = 0x82;
    for (local_c = 0; local_c <= *(int *)(&DAT_006ff4b8 + arg1 * 4); local_c = local_c + 1) {
      local_1c = (&g_PlayerActiveCardCount)[arg1];
      do {
        local_1c = local_1c - 1;
        iVar3 = local_8;
        if ((int)local_1c < 0) goto LAB_004837f3;
      } while ((*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + arg1 * 0x5b20) == -1) ||
              (*(int *)(&g_CardSlot_DisplayIndex + local_1c * 0x120 + arg1 * 0x5b20) != local_c));
      if (((&g_CardSlot_Flags)[local_1c * 0x120 + arg1 * 0x5b20] & 2) == 0) {
        Mem_AllocOrFree_00484ebb(arg1,local_1c,(local_1c & 0xf) + 0xff,local_3c);
        local_3c = local_3c + -0x12;
      }
      else if ((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + arg1 * 0x5b20) * 0x34] == '\x01') {
        local_34 = 1;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
              local_24 = local_24 + 1) {
            if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20) ==
                  local_1c) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == arg1)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (local_18,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(arg1,local_1c,(local_1c & 7) + 1,local_38);
        local_38 = local_38 + -8;
      }
      else if (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + arg1 * 0x5b20) == -1) {
        local_34 = 1;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
              local_24 = local_24 + 1) {
            if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20) ==
                  local_1c) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == arg1)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (local_18,local_24,local_8 + (int)(4 / (longlong)local_34),
                         local_10 + (int)(8 / (longlong)local_34));
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(arg1,local_1c,local_8,local_10);
        local_10 = local_10 + -6;
        iVar3 = local_8 + 0x33;
        if (0xe0 < local_8 + 0x33) {
          iVar3 = local_8 + -0x62;
        }
      }
LAB_004837f3:
      local_8 = iVar3;
    }
    local_38 = 0x2a;
    local_8 = 0x41;
    local_10 = 0x2a;
    for (local_c = 0; local_c <= *(int *)(&DAT_006ff4b8 + iVar1 * 4); local_c = local_c + 1) {
      local_1c = (&g_PlayerActiveCardCount)[iVar1];
      iVar3 = local_8;
      while (local_8 = iVar3, local_1c = local_1c - 1, -1 < (int)local_1c) {
        iVar3 = local_8;
        if (((*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + iVar1 * 0x5b20) != -1) &&
            (*(int *)(&g_CardSlot_DisplayIndex + local_1c * 0x120 + iVar1 * 0x5b20) == local_c)) &&
           (((&g_CardSlot_Flags)[local_1c * 0x120 + iVar1 * 0x5b20] & 2) != 0)) {
          if ((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + iVar1 * 0x5b20) * 0x34] == '\x01') {
            local_34 = 1;
            for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
                  local_24 = local_24 + 1) {
                if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20)
                      == local_1c) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == iVar1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (local_18,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(iVar1,local_1c,(local_1c & 7) + 1,local_38);
            local_38 = local_38 + -8;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + iVar1 * 0x5b20) == -1) {
            local_34 = 1;
            for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
                  local_24 = local_24 + 1) {
                if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20)
                      == local_1c) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == iVar1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (local_18,local_24,local_8 + (int)(4 / (longlong)local_34),
                             local_10 + (int)(8 / (longlong)local_34));
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(iVar1,local_1c,local_8,local_10);
            local_10 = local_10 + -6;
            iVar3 = local_8 + 0x33;
            if (0xe0 < local_8 + 0x33) {
              iVar3 = local_8 + -0x62;
            }
          }
        }
      }
    }
    switch(g_ScWillyScore) {
    case 0:
    case 1:
      strcpy(&g_OverworldWorldState,s_UNTAP_00526ed8);
      break;
    case 2:
    case 4:
      strcpy(&g_OverworldWorldState,s_UPKEEP_00526ee0);
      break;
    default:
      strcpy(&g_OverworldWorldState,&DAT_00526f10);
      break;
    case 10:
      strcpy(&g_OverworldWorldState,&DAT_00526ee8);
      break;
    case 0x14:
      strcpy(&g_OverworldWorldState,&DAT_00526ef0);
      break;
    case 0x15:
    case 0x17:
    case 0x19:
    case 0x1a:
    case 0x1b:
      strcpy(&g_OverworldWorldState,s_ATTACK_00526ef8);
      break;
    case 0x1e:
      strcpy(&g_OverworldWorldState,s_MAIN2_00526f00);
      break;
    case 0x1f:
    case 0x20:
    case 0x22:
      strcpy(&g_OverworldWorldState,s_HEALING_00526f08);
    }
    FUN_0040c3cc(&g_OverworldWorldState,0x248,4,(-(uint)(g_DefendingPlayer == 0) & 0x23) + 0xdc);
    if (DAT_0068a64c == -1) {
      FUN_0040c274(&DAT_00701830,4,4,0);
    }
    else {
      FUN_0040c274(s_Swamp_0051aea9 + DAT_0068a64c * 0x34,4,4,0xff);
    }
    g_OverworldWorldState = 0;
    pcVar2 = _itoa(DAT_006b300c + DAT_00627a14,&DAT_005395a0,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s_cards_00526f18);
    FUN_0040c274(&g_OverworldWorldState,4,0x12,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,400,0x84,0x20,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0x192,0x80,0x1e,3);
    FUN_0040c421(s_Our_Hero_00526f20,(int)DAT_00522458 / 2,0x194,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,0,0x84,0x22,0);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0,0x80,0x20,0xd8);
    FUN_0040c421(&DAT_00695e10,(int)DAT_00522458 / 2,0x12,0xdc);
    iVar3 = FUN_0040a305((&g_PlayerCreatureCount)[arg1],0x19,100);
    iVar3 = (int)(400 / (longlong)iVar3);
    for (local_1c = 0; (int)local_1c < (int)(&g_PlayerCreatureCount)[arg1]; local_1c = local_1c + 1)
    {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (local_1c * iVar3 + (int)DAT_00522458 / 2) -
                        ((&g_PlayerCreatureCount)[arg1] * iVar3) / 2,0x1a0,DAT_0067f3a8);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f2c);
    iVar4 = 10;
    pcVar2 = &DAT_005395a0;
    iVar3 = FUN_0040a305((&g_PlayerCreatureCount)[arg1],0,99);
    pcVar2 = _itoa(iVar3,pcVar2,iVar4);
    strcat(&g_OverworldWorldState,pcVar2);
    if ((&DAT_00696870)[arg1] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f30);
      pcVar2 = _itoa((&DAT_00696870)[arg1],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,&DAT_00526f34);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f38);
    FUN_0040c3cc(&g_OverworldWorldState,(int)DAT_00522458 / 2,0x1a0,0);
    iVar3 = FUN_0040a305((&g_PlayerCreatureCount)[iVar1],0x19,100);
    iVar3 = (int)(400 / (longlong)iVar3);
    for (local_1c = 0; (int)local_1c < (int)(&g_PlayerCreatureCount)[iVar1]; local_1c = local_1c + 1
        ) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (local_1c * iVar3 + (int)DAT_00522458 / 2) -
                        ((&g_PlayerCreatureCount)[iVar1] * iVar3) / 2,4,DAT_0067f3ac);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f3c);
    iVar4 = 10;
    pcVar2 = &DAT_005395a0;
    iVar3 = FUN_0040a305((&g_PlayerCreatureCount)[iVar1],0,99);
    pcVar2 = _itoa(iVar3,pcVar2,iVar4);
    strcat(&g_OverworldWorldState,pcVar2);
    if ((&DAT_00696870)[iVar1] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f40);
      pcVar2 = _itoa((&DAT_00696870)[iVar1],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,&DAT_00526f44);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f48);
    FUN_0040c3cc(&g_OverworldWorldState,(int)DAT_00522458 / 2,4,0xff);
    Pic_Subsystem_00452708(&DAT_005395b0);
    if (g_DefendingPlayer == g_CurrentTurnPhase) {
      if (g_ScWillyScore < 0x15) {
        strcpy(&g_OverworldWorldState,s_ATTACK_00526f4c + ((DAT_0063ee78 != 0) - 1 & 8));
      }
      else {
        strcpy(&g_OverworldWorldState,s_CHARGE__00526f5c + ((0 < DAT_006a5f20) - 1 & 8));
        if (0x1d < g_ScWillyScore) {
          strcpy(&g_OverworldWorldState,&DAT_00526f6c);
        }
      }
      if (((byte)g_PlayerHandCardCount & 0x80) != 0) {
        FUN_00483590(&g_OverworldWorldState,0x127,200);
      }
      if (g_ActivePlayer == -1) {
        FUN_00483590(s_Cancel_00526f74,0x10,200);
      }
      if (g_ActivePlayer != -1) {
        FUN_00483590(s_Concede_00526f7c,0x18,200);
      }
    }
    if (arg2 == 0) {
      *(undefined4 *)g_DisplaySurfaceScreen = 0;
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                   (int *)g_DisplaySurfaceScreen,0,0);
    }
    else {
      FUN_0050d520(1);
      *(undefined4 *)g_DisplaySurfaceScreen = 0;
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                   (int *)g_DisplaySurfaceScreen,0,0);
      FUN_0050d4e0(0);
    }
    Mem_AllocOrFree_00510e20(1,s_combat2_pic_00526f84);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
    Pic_Subsystem_0044b8aa();
  }
  return;
}


