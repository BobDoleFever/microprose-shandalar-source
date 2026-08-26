/*
 * Decompiled function: Magic_UntapTurnPhase
 * Entry Point: 00474588
 * Size: 945 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_UntapTurnPhase(void)

{
  byte arg_1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    *(undefined4 *)(&DAT_006ff6b0 + local_10 * 4) = 0;
    *(undefined4 *)(&DAT_006ff690 + local_10 * 4) = *(undefined4 *)(&DAT_006ff6b0 + local_10 * 4);
    *(undefined4 *)(&DAT_006b2fc0 + local_10 * 4) = *(undefined4 *)(&DAT_006ff690 + local_10 * 4);
    *(undefined4 *)(&DAT_006b2fa0 + local_10 * 4) = *(undefined4 *)(&DAT_006b2fc0 + local_10 * 4);
    *(undefined4 *)(&DAT_006b2e60 + local_10 * 4) = *(undefined4 *)(&DAT_006b2fa0 + local_10 * 4);
    *(undefined4 *)(&DAT_006b2e40 + local_10 * 4) = *(undefined4 *)(&DAT_006b2e60 + local_10 * 4);
  }
  DAT_006a282c = 0;
  DAT_006a2828 = 0;
  DAT_00695e04 = 0;
  _DAT_00695e00 = 0;
  DAT_006a4a14 = 0;
  _DAT_006a4a10 = 0;
  for (local_10 = 0; local_10 < 0x18; local_10 = local_10 + 1) {
    *(undefined4 *)(&DAT_006b3000 + local_10 * 4) = 0;
  }
  _DAT_006b3000 = g_PlayerCreatureCount;
  DAT_006b3004 = DAT_006a4a04;
  for (local_c = 0; local_c < 2; local_c = local_c + 1) {
    (&DAT_006b3008)[local_c] = 0;
    for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c]; local_10 = local_10 + 1)
    {
      iVar1 = FUN_00471c32(local_c,local_10);
      if (iVar1 == 0) {
        if (*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) {
          (&DAT_006b3008)[local_c] = (&DAT_006b3008)[local_c] + 1;
        }
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20);
        arg_1 = (&DAT_0051aebe)[iVar1 * 0x34];
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          iVar2 = FUN_00473179(local_c,local_10,0x32,0xffffffff);
          iVar3 = FUN_00473179(local_c,local_10,0x33,0xffffffff);
          iVar4 = FUN_00473cc5(arg_1);
          *(int *)(&DAT_006b2e40 + iVar4 * 4 + local_c * 0x20) =
               *(int *)(&DAT_006b2e40 + iVar4 * 4 + local_c * 0x20) + iVar2;
          *(int *)(&DAT_006b2e5c + local_c * 0x20) =
               *(int *)(&DAT_006b2e5c + local_c * 0x20) + iVar2;
          iVar2 = FUN_00473cc5(arg_1);
          *(int *)(&DAT_006b2fa0 + iVar2 * 4 + local_c * 0x20) =
               *(int *)(&DAT_006b2fa0 + iVar2 * 4 + local_c * 0x20) + iVar3;
          *(int *)(&DAT_006b2fbc + local_c * 0x20) =
               *(int *)(&DAT_006b2fbc + local_c * 0x20) + iVar3;
          *(int *)(&DAT_006a4a10 + local_c * 4) = *(int *)(&DAT_006a4a10 + local_c * 4) + 1;
        }
        (&DAT_006a2828)[local_c] =
             (&DAT_006a2828)[local_c] | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          *(int *)(&DAT_006b3010 + local_c * 4) = *(int *)(&DAT_006b3010 + local_c * 4) + 1;
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) != 0) {
          (&DAT_006b3018)[local_c] = (&DAT_006b3018)[local_c] + 1;
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 4) != 0) {
          *(int *)(&DAT_006b3020 + local_c * 4) = *(int *)(&DAT_006b3020 + local_c * 4) + 1;
        }
      }
    }
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      if (*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) != -1) {
        *(uint *)(&DAT_00695e00 + local_c * 4) =
             *(uint *)(&DAT_00695e00 + local_c * 4) |
             (uint)(byte)(&g_MasterCardColorTable)
                         [*(int *)(&DAT_006ff710 + local_10 * 4 + local_c * 2000) * 0x34];
      }
    }
  }
  return;
}


