/*
 * Decompiled function: Ai_PopBoardState
 * Entry Point: 004aafa8
 * Size: 583 bytes
 */
#include "magic.h"


void Ai_PopBoardState(void)

{
  memcpy(&g_ActiveCardsInPlay,&DAT_00633440,0xb640);
  memcpy(&g_MasterCardTable + g_MasterCardCount * 0x34,&DAT_0063ea80,0x340);
  memcpy(&DAT_0069e730,&DAT_0054d648,4000);
  memcpy(&DAT_006ff710,&DAT_005504d8,4000);
  memcpy(&DAT_006b1590,&DAT_00555988,4000);
  memcpy(&DAT_0063edd0,&DAT_00555940,0x40);
  memcpy(&DAT_0063ee90,&DAT_00550498,0x40);
  memcpy(&DAT_0063ee30,&DAT_00550408,0x40);
  memcpy(&DAT_00627870,&DAT_0054e5f0,0x198);
  memcpy(&g_PlayerCreatureCount,&DAT_0054be48,8);
  memcpy(&DAT_00696870,&DAT_00550448,8);
  memcpy(&DAT_006a2828,&DAT_00550470,8);
  memcpy(&DAT_00695e00,&DAT_00550478,8);
  memcpy(&DAT_006b3000,&DAT_005528d0,0x60);
  memcpy(&DAT_006b2d90,&DAT_00551478,0x80);
  memcpy(&DAT_007006e0,&DAT_00555108,2000);
  memcpy(&DAT_006a5750,&DAT_0054be50,2000);
  g_PlayerHandCardCount = DAT_00550300;
  g_ScWillyScore = DAT_00554040;
  DAT_0068a708 = DAT_00550484;
  DAT_006a5f20 = DAT_00550490;
  g_ActivePlayer = DAT_00552930;
  memcpy(&DAT_006ff4d0,&DAT_0054d5c0,0x80);
  memcpy(&DAT_006fecc0,&DAT_005531a0,0x100);
  memcpy(&DAT_006ff390,&DAT_00550200,0x100);
  memcpy(&g_PlayerActiveCardCount,&DAT_00550488,8);
  DAT_006a3f78 = DAT_00553188;
  DAT_00695f18 = DAT_0054e7d0;
  g_SpellStackDepth = DAT_0054e788;
  memcpy(&DAT_006b2d40,&DAT_005558d8,0x1c);
  return;
}


