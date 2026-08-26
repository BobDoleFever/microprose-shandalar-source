/*
 * Decompiled function: FUN_00500cd5
 * Entry Point: 00500cd5
 * Size: 418 bytes
 */
#include "magic.h"


void FUN_00500cd5(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_00530d44,DAT_006fee70);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Difficulty_00530d48,0,1,local_14,sVar2 + 1);
    sVar2 = strlen(&DAT_006fee74);
    RegSetValueExA(local_18,s_PlayerDeck_00530d54,0,1,&DAT_006fee74,sVar2 + 1);
    sVar2 = strlen(&DAT_006fee92);
    RegSetValueExA(local_18,s_OpponentDeck_00530d60,0,1,&DAT_006fee92,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d70,DAT_006feeb0);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_00530d74,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d7c,DAT_006feeb4);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Match_00530d80,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_00530d88,DAT_006feeb8);
    sVar2 = strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_00530d8c,0,1,local_14,sVar2 + 1);
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}


