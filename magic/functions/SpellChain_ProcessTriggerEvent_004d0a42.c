/*
 * Decompiled function: SpellChain_ProcessTriggerEvent
 * Entry Point: 004d0a42
 * Size: 645 bytes
 */
#include "magic.h"


uint SpellChain_ProcessTriggerEvent(int arg1,int arg2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == DAT_006fd3f4) {
    local_8 = *(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20);
  }
  else {
    local_8 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  }
  if (((&g_MasterCardColorTable)[local_8 * 0x34] & 4) == 0) {
    if (((&g_MasterCardColorTable)[local_8 * 0x34] & 0x10) == 0) {
      if (((&g_MasterCardColorTable)[local_8 * 0x34] & 0x20) == 0) {
        if (((&g_MasterCardColorTable)[local_8 * 0x34] & 8) == 0) {
          iVar2 = FUN_00473cc5((&DAT_006a5f4d)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_0041d9d2(arg1,arg2,iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f);
        }
        else {
          iVar2 = FUN_00473cc5((&DAT_006a5f4d)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_0041d9d2(arg1,arg2,iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x100000;
        }
      }
      else {
        iVar2 = FUN_00473cc5((&DAT_006a5f4d)[arg2 * 0x120 + arg1 * 0x5b20]);
        cVar1 = FUN_0041d9d2(arg1,arg2,iVar2);
        uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x80000;
      }
    }
    else {
      iVar2 = FUN_00473cc5((&DAT_006a5f4d)[arg2 * 0x120 + arg1 * 0x5b20]);
      cVar1 = FUN_0041d9d2(arg1,arg2,iVar2);
      uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x40000;
    }
  }
  else {
    iVar2 = FUN_00473cc5((&DAT_006a5f4d)[arg2 * 0x120 + arg1 * 0x5b20]);
    cVar1 = FUN_0041d9d2(arg1,arg2,iVar2);
    uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x20000;
  }
  return uVar3;
}


