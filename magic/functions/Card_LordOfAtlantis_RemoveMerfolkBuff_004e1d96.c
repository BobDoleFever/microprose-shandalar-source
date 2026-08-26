/*
 * Decompiled function: Card_LordOfAtlantis_RemoveMerfolkBuff
 * Entry Point: 004e1d96
 * Size: 214 bytes
 */
#include "magic.h"


undefined4 Card_LordOfAtlantis_RemoveMerfolkBuff(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x1a) && (g_DefendingPlayer != arg_1)) &&
     ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    iVar1 = FUN_0040a1d2(2);
    if (iVar1 != 0) {
      (&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


