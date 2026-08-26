/*
 * Decompiled function: FUN_00481c8e
 * Entry Point: 00481c8e
 * Size: 628 bytes
 */
#include "duel.h"


void FUN_00481c8e(void)

{
  LSTATUS LVar1;
  HKEY local_2c;
  BYTE local_28 [32];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_004f9e4c,0,1,
                        &local_2c);
  if (LVar1 == 0) {
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Difficulty_004fa190,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa19c,&DAT_00664730);
    }
    else {
      DAT_00664730 = 1;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_PlayerDeck_004fa1a0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      _sprintf(&DAT_00664734,&DAT_004fa1ac,local_28);
    }
    else {
      DAT_00664734 = 0;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_OpponentDeck_004fa1b0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      _sprintf(&DAT_00664752,&DAT_004fa1c0,local_28);
    }
    else {
      DAT_00664752 = 0;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_004fa1c4,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1cc,&DAT_00664770);
    }
    else {
      DAT_00664770 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Match_004fa1d0,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1d8,&DAT_00664774);
    }
    else {
      DAT_00664774 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_004fa1dc,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      _sscanf((char *)local_28,&DAT_004fa1e4,&DAT_00664778);
    }
    else {
      DAT_00664778 = 1;
    }
    RegCloseKey(local_2c);
  }
  else {
    DAT_00664730 = 1;
    DAT_00664734 = 0;
    DAT_00664752 = 0;
    DAT_00664770 = 1;
    DAT_00664774 = 1;
    DAT_00664778 = 1;
  }
  return;
}


