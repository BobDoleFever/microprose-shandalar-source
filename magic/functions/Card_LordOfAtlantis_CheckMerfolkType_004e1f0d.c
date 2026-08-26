/*
 * Decompiled function: Card_LordOfAtlantis_CheckMerfolkType
 * Entry Point: 004e1f0d
 * Size: 190 bytes
 */
#include "magic.h"


undefined4 Card_LordOfAtlantis_CheckMerfolkType(int arg1,int arg2)

{
  if (((char)(&g_CardSlot_Toughness)[arg2 * 0x120 + arg1 * 0x5b20] == DAT_005659a4) &&
     (*(int *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) == DAT_00565994)) {
    *(undefined4 *)(&g_CardSlot_OriginalCardId + arg2 * 0x120 + arg1 * 0x5b20) = DAT_00565990;
  }
  return 0;
}


