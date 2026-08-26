/*
 * Decompiled function: Ai_SaveGameState
 * Entry Point: 004aa830
 * Size: 698 bytes
 */
#include "magic.h"


void Ai_SaveGameState(void)

{
  DAT_00556928 = 0;
  memcpy(&DAT_00627a90,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_006330f0,&g_MasterCardTable + g_MasterCardCount * 0x34,0x340);
  memcpy(&DAT_00554050,&DAT_0069e730,4000);
  memcpy(&DAT_0054e818,&DAT_006ff710,4000);
  memcpy(&DAT_0054c620,&DAT_006b1590,4000);
  memcpy(&DAT_0054e7d8,&DAT_0063edd0,0x40);
  memcpy(&DAT_0054e790,&DAT_0063ee90,0x40);
  memcpy(&DAT_00555900,&DAT_0063ee30,0x40);
  memcpy(&DAT_005532a0,&DAT_00627870,0x198);
  memcpy(&DAT_00553438,&g_PlayerCreatureCount,8);
  memcpy(&DAT_00554048,&DAT_00696870,8);
  memcpy(&DAT_00555100,&DAT_006a2828,8);
  memcpy(&DAT_005550f8,&DAT_00695e00,8);
  memcpy(&DAT_005501a0,&DAT_006b3000,0x60);
  memcpy(&DAT_0054f7b8,&DAT_006b2d90,0x80);
  memcpy(&DAT_005529b8,&DAT_007006e0,2000);
  memcpy(&DAT_005518f8,&DAT_006a5750,2000);
  DAT_00555980 = g_PlayerHandCardCount;
  DAT_00550480 = g_ScWillyScore;
  DAT_006498f0 = g_ScWillyScore;
  DAT_00554ff0 = DAT_0068a708;
  DAT_0055319c = DAT_006a5f20;
  DAT_0054be40 = g_ActivePlayer;
  memcpy(&DAT_00552938,&DAT_006ff4d0,0x80);
  memcpy(&DAT_00554ff8,&DAT_006fecc0,0x100);
  memcpy(&DAT_00550308,&DAT_006ff390,0x100);
  memcpy(&DAT_005558f8,&g_PlayerActiveCardCount,8);
  if (DAT_006a3f78 < 0) {
    assert(s_ScWilly>_0_0052ce44,s_G__NewMagic_sources_sid_Ai_c_0052ce24,0x176);
  }
  DAT_0054e5e8 = DAT_006a3f78;
  DAT_00550178 = DAT_00695f18;
  DAT_005528cc = DAT_007006d4;
  memcpy(&DAT_00550038,&DAT_00700ec0,0x140);
  memcpy(&DAT_00550450,&DAT_006330d0,0x20);
  memcpy(&DAT_00550180,&DAT_006b2d40,0x1c);
  FUN_0040a1ff();
  return;
}


