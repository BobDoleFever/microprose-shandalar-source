/*
 * Decompiled function: FUN_00500a5b
 * Entry Point: 00500a5b
 * Size: 634 bytes
 */
#include "magic.h"


void FUN_00500a5b(void)

{
  LSTATUS LVar1;
  HKEY local_2c;
  BYTE local_28 [32];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,PTR_s_Software_MicroProse_Magic__The_G_005309a8,0,1,
                        &local_2c);
  if (LVar1 == 0) {
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Difficulty_00530cec,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530cf8,&DAT_006fee70);
    }
    else {
      DAT_006fee70 = 1;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_PlayerDeck_00530cfc,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee74,&DAT_00530d08,local_28);
    }
    else {
      DAT_006fee74 = 0;
    }
    local_8 = 0x1e;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_OpponentDeck_00530d0c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,
                             &local_8);
    if (LVar1 == 0) {
      sprintf(&DAT_006fee92,&DAT_00530d1c,local_28);
    }
    else {
      DAT_006fee92 = 0;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d20,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d28,&DAT_006feeb0);
    }
    else {
      DAT_006feeb0 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,s_Match_00530d2c,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d34,&DAT_006feeb4);
    }
    else {
      DAT_006feeb4 = 1;
    }
    local_8 = 10;
    local_28[0] = '\0';
    LVar1 = RegQueryValueExA(local_2c,&DAT_00530d38,(LPDWORD)0x0,(LPDWORD)0x0,local_28,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_28,&DAT_00530d40,&DAT_006feeb8);
    }
    else {
      DAT_006feeb8 = 1;
    }
    RegCloseKey(local_2c);
  }
  else {
    DAT_006fee70 = 1;
    DAT_006fee74 = 0;
    DAT_006fee92 = 0;
    DAT_006feeb0 = 1;
    DAT_006feeb4 = 1;
    DAT_006feeb8 = 1;
  }
  return;
}


