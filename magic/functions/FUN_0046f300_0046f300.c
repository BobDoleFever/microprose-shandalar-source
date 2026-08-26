/*
 * Decompiled function: FUN_0046f300
 * Entry Point: 0046f300
 * Size: 721 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f300(void)

{
  int local_c;
  int local_8;
  
  g_CurrentTurnPhase = 0;
  g_ActivePlayerPriority = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    (&DAT_00696870)[local_8] = 0;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
      *(undefined4 *)(&DAT_0063ee30 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_0063edd0 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0063ee30 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_00627870 + local_8 * 0xcc) = 0xffffffff;
      *(undefined4 *)(&DAT_00627a20 + local_8 * 0x2c) = 0xffffffff;
      *(undefined4 *)(&DAT_0063eed0 + local_8 * 4) = 0;
    }
  }
  DAT_006fecc0 = 0xffffffff;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((&g_MasterCardTable)[(g_MasterCardCount + local_c) * 0x34] == -1) {
      *(undefined4 *)(&g_MasterCardTypeTable + (g_MasterCardCount + local_c) * 0x34) = 0xffffffff;
    }
  }
  g_PlayerHandCardCount = 0;
  DAT_00680788 = 0xffffffff;
  DAT_00627a88 = 0xffffffff;
  DAT_0063ee88 = 0;
  if (DAT_0067f380 == 0) {
    _DAT_006feebc = _DAT_006feebc | 2;
  }
  else {
    _DAT_006feebc = _DAT_006feebc & 0xfffffffd;
  }
  DAT_00680790 = 0;
  DAT_0063edc8 = 0x30;
  DAT_0063ee70 = 0xffffffff;
  _DAT_006fdbd8 = 0xffffffff;
  _DAT_006a2830 = 0xffffffff;
  DAT_00695ec8 = 0xffffffff;
  DAT_006ff2d4 = 0xffffffff;
  DAT_006fedc0 = 0;
  _DAT_006a4934 = 1;
  DAT_006fe3f8 = 0;
  DAT_0063ee1c = 0;
  DAT_007006d0 = 0;
  DAT_006a5f20 = 0;
  DAT_006ff2d8 = 0xffffffff;
  DAT_007006d4 = 0;
  DAT_00627a10 = 1;
  DAT_006ff684 = 0;
  DAT_006b2d24 = 0;
  DAT_006fd3f0 = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    (&DAT_006b2d40)[local_c] = 0;
  }
  g_OverworldPlayerCoordY = 0xffffffff;
  DAT_006b2d3c = 0xffffffff;
  DAT_006b2d2c = 0xffffffff;
  _DAT_00680780 = 0;
  _DAT_00680784 = 0;
  return;
}


