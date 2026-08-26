/*
 * Decompiled function: FUN_00472c0c
 * Entry Point: 00472c0c
 * Size: 508 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x00472d06) */

bool FUN_00472c0c(int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,uint arg_5,uint arg_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  if (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0) {
    bVar2 = false;
  }
  else if ((*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) ||
          (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x18) != 0)) {
    bVar2 = false;
  }
  else if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0) ||
          (iVar3 = FUN_004728c3(arg_1,arg_2), iVar3 != 0)) {
    if (((arg_5 & 0x20) == 0) ||
       (uVar4 = FUN_00473179(arg_1,arg_2,0x34,0xffffffff), (uVar4 & 0x420) != 0)) {
      if (((arg_5 & 0x1ff800) == 0) ||
         (cVar1 = FUN_00473cc5((&DAT_006a5f4d)[arg_2 * 0x120 + arg_1 * 0x5b20]),
         (arg_5 & 0x800 << (cVar1 - 1U & 0x1f)) == 0)) {
        if ((arg_6 & arg_5 & 0x1f) == 0) {
          Magic_PayManaCost();
          g_OverworldPlayerCoordX = arg_1;
          g_OverworldMapGrid = arg_2;
          DAT_007006c8 = arg_3;
          DAT_006b2d5c = arg_4;
          g_ActivePalette = 0;
          Magic_ScanCards(0x78);
          bVar2 = g_ActivePalette < 1;
          Magic_TapCardForMana();
        }
        else {
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


