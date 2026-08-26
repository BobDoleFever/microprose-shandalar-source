/*
 * Decompiled function: Ai_Subsystem_004cc56d
 * Entry Point: 004cc56d
 * Size: 595 bytes
 */
#include "magic.h"


int Ai_Subsystem_004cc56d(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,char *str_6,int arg_7)

{
  int iVar1;
  undefined4 local_274;
  char local_26c [600];
  int local_14;
  int local_c;
  uint local_8;
  
  if ((((g_IsAiThinking != 1) && (-1 < arg_1)) && (-1 < arg_2)) && (-1 < arg_3)) {
    strcpy(local_26c,str_6);
    g_OverworldWorldState = 0;
    if (g_CurrentTurnPhase == arg_1) {
      Ai_Subsystem_004b90de(arg_2,arg_3);
      strcat(&g_OverworldWorldState,&DAT_0052e5d8);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_00695e10);
      strcat(&g_OverworldWorldState,s_selects__0052e5cc);
      local_8 = 1;
      local_14 = arg_7;
      for (local_c = 0; iVar1 = local_14, local_c < 1000; local_c = local_c + 1) {
        if (((local_8 != 0) && (local_26c[local_c] == ' ')) &&
           (local_14 = local_14 + -1, iVar1 == 0)) {
          local_26c[local_c] = '>';
          break;
        }
        if (local_26c[local_c] != '\n') {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
        local_8 = (uint)(local_26c[local_c] == '\n');
      }
    }
    strcat(&g_OverworldWorldState,local_26c);
    if ((*(int *)(&g_CardSlot_CardId + arg_3 * 0x120 + arg_2 * 0x5b20) == -1) ||
       (*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == -1)) {
      Ai_Subsystem_004cc9c5(1,0xff);
    }
    if ((g_CurrentTurnPhase == arg_1) && (DAT_006fedc0 == 0)) {
      local_274 = 1;
    }
    else {
      local_274 = 0;
    }
    iVar1 = Ai_Subsystem_004b574d(arg_2,arg_3,arg_4,arg_5,&g_OverworldWorldState,local_274);
    if ((g_CurrentTurnPhase == arg_1) && (DAT_006fedc0 == 0)) {
      arg_7 = iVar1;
    }
  }
  return arg_7;
}


