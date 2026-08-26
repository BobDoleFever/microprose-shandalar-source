/*
 * Decompiled function: FUN_100129f0
 * Entry Point: 100129f0
 * Size: 691 bytes
 */
#include "deckdll.h"


void FUN_100129f0(void)

{
  LSTATUS LVar1;
  HKEY local_70;
  BYTE local_6c [100];
  DWORD local_8;
  
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042c2c,0,1,&local_70);
  if (LVar1 == 0) {
    local_8 = 10;
    LVar1 = RegQueryValueExA(local_70,s_Consolidate_10042c68,(LPDWORD)0x0,(LPDWORD)0x0,local_6c,
                             &local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_6c,&DAT_10042c74,&DAT_101cf540);
    }
    else {
      DAT_101cf540 = 1;
    }
    LVar1 = RegQueryValueExA(local_70,s_Music_10042c78,(LPDWORD)0x0,(LPDWORD)0x0,local_6c,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_6c,&DAT_10042c80,&DAT_101cf541);
    }
    else {
      DAT_101cf541 = 1;
    }
    LVar1 = RegQueryValueExA(local_70,s_Effects_10042c84,(LPDWORD)0x0,(LPDWORD)0x0,local_6c,&local_8
                            );
    if (LVar1 == 0) {
      sscanf((char *)local_6c,&DAT_10042c8c,&DAT_101cf542);
    }
    else {
      DAT_101cf542 = 1;
    }
    RegCloseKey(local_70);
  }
  else {
    DAT_101cf540 = 1;
    DAT_101cf541 = 1;
    DAT_101cf542 = 1;
  }
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042c90,0,1,&local_70);
  if (LVar1 == 0) {
    local_8 = 100;
    LVar1 = RegQueryValueExA(local_70,&DAT_10042cbc,(LPDWORD)0x0,(LPDWORD)0x0,local_6c,&local_8);
    if (LVar1 == 0) {
      strcpy(&DAT_101cf543,(char *)local_6c);
    }
    else {
      strcpy(&DAT_101cf543,&DAT_10042cc4);
    }
    local_8 = 100;
    LVar1 = RegQueryValueExA(local_70,s_Email_10042ccc,(LPDWORD)0x0,(LPDWORD)0x0,local_6c,&local_8);
    if (LVar1 == 0) {
      strcpy(&DAT_101cf593,(char *)local_6c);
    }
    else {
      strcpy(&DAT_101cf593,s_User_E_Mail_10042cd4);
    }
    RegCloseKey(local_70);
  }
  else {
    strcpy(&DAT_101cf593,s_User_E_Mail_10042ce8);
  }
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042cf4,0,1,&local_70);
  if (LVar1 == 0) {
    local_8 = 100;
    LVar1 = RegQueryValueExA(local_70,s_ExpandTextOnBigCard_10042d2c,(LPDWORD)0x0,(LPDWORD)0x0,
                             local_6c,&local_8);
    if (LVar1 == 0) {
      sscanf((char *)local_6c,&DAT_10042d40,&DAT_101cf5e3);
    }
    else {
      DAT_101cf5e3 = 0;
    }
    RegCloseKey(local_70);
  }
  else {
    DAT_101cf5e3 = 0;
  }
  return;
}


