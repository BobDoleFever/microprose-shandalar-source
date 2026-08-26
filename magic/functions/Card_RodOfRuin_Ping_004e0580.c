/*
 * Decompiled function: Card_RodOfRuin_Ping
 * Entry Point: 004e0580
 * Size: 565 bytes
 */
#include "magic.h"


uint Card_RodOfRuin_Ping(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    uVar1 = (&DAT_006a2828)[arg_1] & 0x40;
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
      if (iVar2 != 0) {
        *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f48 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) *
           -2;
      *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006a5f4a + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) *
           -2;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


