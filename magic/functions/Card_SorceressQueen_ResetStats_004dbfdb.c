/*
 * Decompiled function: Card_SorceressQueen_ResetStats
 * Entry Point: 004dbfdb
 * Size: 746 bytes
 */
#include "magic.h"


void Card_SorceressQueen_ResetStats(int arg_1,int arg_2,int arg_3)

{
  short sVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x90) {
      Ai_GetOpponentPlayerScore(0);
    }
    else {
      if ((arg_3 == 0x6d) &&
         ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
        if (local_c == -1) {
          g_ActivePlayer = 1;
        }
        else {
          (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
          *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
        }
      }
      if (arg_3 == 0x72) {
        iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,
                             (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
        if (iVar2 != -1) {
          sVar1 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)
                               ,0x32,0xffffffff);
          *(short *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = -sVar1;
        }
        *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
  }
  return;
}


