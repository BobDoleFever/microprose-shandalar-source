/*
 * Decompiled function: Ai_RestoreGameState
 * Entry Point: 004aaaea
 * Size: 631 bytes
 */
#include "magic.h"


void Ai_RestoreGameState(void)

{
  memcpy(&g_ActiveCardsInPlay,&DAT_00627a90,0xb640);
  memcpy(&g_MasterCardTable + g_MasterCardCount * 0x34,&DAT_006330f0,0x340);
  memcpy(&DAT_0069e730,&DAT_00554050,4000);
  memcpy(&DAT_006ff710,&DAT_0054e818,4000);
  memcpy(&DAT_006b1590,&DAT_0054c620,4000);
  memcpy(&DAT_0063edd0,&DAT_0054e7d8,0x40);
  memcpy(&DAT_0063ee90,&DAT_0054e790,0x40);
  memcpy(&DAT_0063ee30,&DAT_00555900,0x40);
  memcpy(&DAT_00627870,&DAT_005532a0,0x198);
  memcpy(&g_PlayerCreatureCount,&DAT_00553438,8);
  memcpy(&DAT_00696870,&DAT_00554048,8);
  memcpy(&DAT_006a2828,&DAT_00555100,8);
  memcpy(&DAT_00695e00,&DAT_005550f8,8);
  memcpy(&DAT_006b3000,&DAT_005501a0,0x60);
  memcpy(&DAT_006b2d90,&DAT_0054f7b8,0x80);
  memcpy(&DAT_007006e0,&DAT_005529b8,2000);
  memcpy(&DAT_006a5750,&DAT_005518f8,2000);
  g_PlayerHandCardCount = DAT_00555980;
  g_ScWillyScore = DAT_00550480;
  DAT_0068a708 = DAT_00554ff0;
  DAT_006a5f20 = DAT_0055319c;
  g_ActivePlayer = DAT_0054be40;
  memcpy(&DAT_006ff4d0,&DAT_00552938,0x80);
  memcpy(&DAT_006fecc0,&DAT_00554ff8,0x100);
  memcpy(&DAT_006ff390,&DAT_00550308,0x100);
  memcpy(&g_PlayerActiveCardCount,&DAT_005558f8,8);
  DAT_006a3f78 = DAT_0054e5e8;
  DAT_00695f18 = DAT_00550178;
  DAT_007006d4 = DAT_005528cc;
  memcpy(&DAT_00700ec0,&DAT_00550038,0x140);
  memcpy(&DAT_006330d0,&DAT_00550450,0x20);
  memcpy(&DAT_006b2d40,&DAT_00550180,0x1c);
  Mem_AllocOrFree_0040a240();
  return;
}


