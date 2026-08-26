/*
 * Decompiled function: Ai_PushBoardState
 * Entry Point: 004aad61
 * Size: 583 bytes
 */
#include "magic.h"


void Ai_PushBoardState(void)

{
  memcpy(&DAT_00633440,&g_ActiveCardsInPlay,0xb640);
  memcpy(&DAT_0063ea80,&g_MasterCardTable + g_MasterCardCount * 0x34,0x340);
  memcpy(&DAT_0054d648,&DAT_0069e730,4000);
  memcpy(&DAT_005504d8,&DAT_006ff710,4000);
  memcpy(&DAT_00555988,&DAT_006b1590,4000);
  memcpy(&DAT_00555940,&DAT_0063edd0,0x40);
  memcpy(&DAT_00550498,&DAT_0063ee90,0x40);
  memcpy(&DAT_00550408,&DAT_0063ee30,0x40);
  memcpy(&DAT_0054e5f0,&DAT_00627870,0x198);
  memcpy(&DAT_0054be48,&g_PlayerCreatureCount,8);
  memcpy(&DAT_00550448,&DAT_00696870,8);
  memcpy(&DAT_00550470,&DAT_006a2828,8);
  memcpy(&DAT_00550478,&DAT_00695e00,8);
  memcpy(&DAT_005528d0,&DAT_006b3000,0x60);
  memcpy(&DAT_00551478,&DAT_006b2d90,0x80);
  memcpy(&DAT_00555108,&DAT_007006e0,2000);
  memcpy(&DAT_0054be50,&DAT_006a5750,2000);
  DAT_00550300 = g_PlayerHandCardCount;
  DAT_00554040 = g_ScWillyScore;
  DAT_00550484 = DAT_0068a708;
  DAT_00550490 = DAT_006a5f20;
  DAT_00552930 = g_ActivePlayer;
  memcpy(&DAT_0054d5c0,&DAT_006ff4d0,0x80);
  memcpy(&DAT_005531a0,&DAT_006fecc0,0x100);
  memcpy(&DAT_00550200,&DAT_006ff390,0x100);
  memcpy(&DAT_00550488,&g_PlayerActiveCardCount,8);
  DAT_00553188 = DAT_006a3f78;
  DAT_0054e7d0 = DAT_00695f18;
  DAT_0054e788 = g_SpellStackDepth;
  memcpy(&DAT_005558d8,&DAT_006b2d40,0x1c);
  return;
}


