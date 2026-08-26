/*
 * Decompiled function: Castle_Process_0040b7fa
 * Entry Point: 0040b7fa
 * Size: 1193 bytes
 */
#include "magic.h"


int Castle_Process_0040b7fa(int arg_1)

{
  int iVar1;
  char *str_2;
  uint uVar2;
  uint local_18;
  uint local_14;
  
  if (arg_1 < 0) {
    arg_1 = 0;
  }
  if (DAT_005384d8 < arg_1) {
    arg_1 = DAT_005384d8;
  }
  if (arg_1 == DAT_005384d4) {
    iVar1 = 0;
  }
  else {
    g_OverworldWorldState = '\0';
    while (g_OverworldWorldState == '\0') {
      iVar1 = *(int *)(&DAT_0067a9a0 + arg_1 * 0x10);
      uVar2 = *(uint *)(&DAT_0067a9a4 + arg_1 * 0x10);
      local_14 = *(uint *)(&DAT_0067a9a8 + arg_1 * 0x10);
      local_18 = *(uint *)(&DAT_0067a9ac + arg_1 * 0x10);
      if (*(int *)(&DAT_0067a9a0 + arg_1 * 0x10) == 0) {
        return 0;
      }
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                   (int *)g_DisplaySurfaceScreen,0,0);
      g_OverworldWorldState = '\0';
      switch(iVar1) {
      case 1:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Visited_00517354);
        }
        else {
          strcat(&g_OverworldWorldState,s_Completed_quest_at_00517340);
        }
        Ai_TownEncounter_004c3b19(uVar2 & 0x7f);
        break;
      case 2:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Lost_to_0051737c);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517370);
        }
        Adventure_FormatNewsString(uVar2 & 0x7f,1,0);
        break;
      case 3:
        strcat(&g_OverworldWorldState,s_Explored_00517388);
        FUN_0048e2b0(uVar2 & 0x7f);
        break;
      case 4:
        if ((uVar2 & 0x80) == 0) {
          strcat(&g_OverworldWorldState,s_Entered_005173a0);
        }
        else {
          strcat(&g_OverworldWorldState,s_Defeated_00517394);
        }
        FUN_0048e2b0(uVar2 & 0x7f);
        strcat(&g_OverworldWorldState,&DAT_005173ac);
        str_2 = (char *)Mem_AllocOrFree_00473d7e((uVar2 & 0x7f) + 1);
        strcat(&g_OverworldWorldState,str_2);
        strcat(&g_OverworldWorldState,s_Castle__005173b0);
        break;
      case 5:
        strcat(&g_OverworldWorldState,s_Discovered_a_005173bc);
        FUN_0040eb04(uVar2);
        if ((int)uVar2 < 5) {
          g_OverworldWorldState = '\0';
        }
        break;
      case 6:
        strcat(&g_OverworldWorldState,s_Bought_WM__005173cc);
        strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[uVar2]);
        break;
      case 7:
        strcat(&g_OverworldWorldState,s_Freed_00517360);
        Ai_TownEncounter_004c3b19(uVar2);
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
        iVar1 = (iVar1 + -8) * 0x100 + uVar2;
        strcat(&g_OverworldWorldState,s_Acquired_005173d8);
        Adventure_AppendNewsDetails((int)s_Swamp_0051aea9[iVar1 * 0x34],0);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
        strcat(&g_OverworldWorldState,s_spell_005173e4);
        break;
      case 0xd:
        strcat(&g_OverworldWorldState,s_Saved_00517368);
        Duel_GetCardDrawOriginY(local_14,local_18);
        break;
      case 0x12:
        switch(uVar2 & 0xffff) {
        case 1:
        case 2:
          strcat(&g_OverworldWorldState,s_JUMP__005173ec);
          break;
        case 3:
          strcat(&g_OverworldWorldState,s_SPEED__005173f4);
          break;
        case 4:
          strcat(&g_OverworldWorldState,s_THUNDERED_on_005173fc);
          Adventure_FormatNewsString((int)uVar2 >> 0x10,1,0);
          strcat(&g_OverworldWorldState,&DAT_0051740c);
          break;
        case 5:
          strcat(&g_OverworldWorldState,s_Went_to_aid_of_00517410);
          uVar2 = Duel_GetCardDrawOriginY(local_14,local_18);
          Ai_TownEncounter_004c3b19(uVar2);
        }
      }
      arg_1 = arg_1 + 1;
    }
    DAT_005384e0 = 0xffffffff;
    DAT_005384dc = 0xffffffff;
    if (arg_1 + -1 == DAT_005384d4) {
      iVar1 = 0;
    }
    else {
      FUN_0040bcff(local_14,local_18);
      iVar1 = arg_1 + -1;
      DAT_005384d4 = iVar1;
    }
  }
  return iVar1;
}


