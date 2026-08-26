/*
 * Decompiled function: Magic_ScanCards
 * Entry Point: 00473f06
 * Size: 864 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Magic_ScanCards(int arg_1)

{
  int arg2;
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  uVar1 = DAT_0067bdb0;
  _DAT_006b1584 = arg_1;
  _DAT_00627a0c = _DAT_00627a0c + 1;
  DAT_006fe3f8 = DAT_006fe3f8 + 1;
  if (9 < DAT_006fe3f8) {
    assert(s___nScan<10_00525d00,s_G__NewMagic_sources_sid_Magic_c_00525ce0,0x7f5);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
      if (*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + local_10 * 0x120) != -1) {
        (&g_PlayerActiveCardCount)[local_8] = local_10 + 1;
      }
    }
  }
  for (local_14 = 0; (local_14 < 500 && (*(int *)(&DAT_007006e0 + local_14 * 4) != -1));
      local_14 = local_14 + 1) {
    local_8 = *(int *)(&DAT_007006e0 + local_14 * 4);
    arg2 = *(int *)(&DAT_006a5750 + local_14 * 4);
    if (((*(int *)(&g_CardSlot_DisplayIndex + local_8 * 0x5b20 + arg2 * 0x120) == local_14) &&
        (*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) != -1)) &&
       ((((&g_CardSlot_Flags)[local_8 * 0x5b20 + arg2 * 0x120] & 2) != 0 ||
        (((&g_CardSlot_Flags)[local_8 * 0x5b20 + arg2 * 0x120] & 0x20) != 0)))) {
      _DAT_0068a704 = local_8 * 0x80 + arg2;
      if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) < 0) ||
         (g_MasterCardCount + 0x10 < *(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120))
         ) {
        Engine_ReportFatalError(s_ScanCard_error_00525d0c);
      }
      else {
        (**(code **)(&DAT_0051aec8 +
                    *(int *)(&g_CardSlot_CardId + local_8 * 0x5b20 + arg2 * 0x120) * 0x34))
                  (local_8,arg2,arg_1);
        if ((((arg_1 == 0x15) && (g_DefendingPlayer == local_8)) &&
            (((byte)*(undefined4 *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) & 0x14) ==
             4)) && (iVar2 = FUN_004728c3(local_8,arg2), iVar2 == 0)) {
          *(uint *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) =
               *(uint *)(&g_CardSlot_Flags + local_8 * 0x5b20 + arg2 * 0x120) | 0x10;
          DAT_006ff2d4 = 0xffffffff;
          FUN_00473e69(local_8,arg2,0x81);
        }
      }
    }
  }
  if ((arg_1 == 0x15) && (g_DefendingPlayer == local_8)) {
    FUN_00472fae();
  }
  DAT_006fe3f8 = DAT_006fe3f8 + -1;
  if (DAT_0068a64c != -1) {
    (**(code **)(&DAT_0051aec8 + DAT_0068a64c * 0x34))(0,0x4e,arg_1);
  }
  DAT_0067bdb0 = uVar1;
  return;
}


