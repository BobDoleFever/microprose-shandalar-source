/*
 * Decompiled function: FUN_00481f02
 * Entry Point: 00481f02
 * Size: 418 bytes
 */
#include "duel.h"


void FUN_00481f02(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e4c,0,
                          (LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_004fa1e8,DAT_00664730);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_Difficulty_004fa1ec,0,1,local_14,sVar2 + 1);
    sVar2 = _strlen(&DAT_00664734);
    RegSetValueExA(local_18,s_PlayerDeck_004fa1f8,0,1,&DAT_00664734,sVar2 + 1);
    sVar2 = _strlen(&DAT_00664752);
    RegSetValueExA(local_18,s_OpponentDeck_004fa204,0,1,&DAT_00664752,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa214,DAT_00664770);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_004fa218,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa220,DAT_00664774);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,s_Match_004fa224,0,1,local_14,sVar2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_004fa22c,DAT_00664778);
    sVar2 = _strlen((char *)local_14);
    RegSetValueExA(local_18,&DAT_004fa230,0,1,local_14,sVar2 + 1);
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}


