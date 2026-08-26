/*
 * Decompiled function: FUN_10012ca3
 * Entry Point: 10012ca3
 * Size: 396 bytes
 */
#include "deckdll.h"


void FUN_10012ca3(void)

{
  LSTATUS LVar1;
  size_t len_2;
  HKEY local_18;
  BYTE local_14 [12];
  DWORD local_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042d44,0,(LPSTR)0x0,
                          0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_10042d80,(int)DAT_101cf540);
    len_2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Consolidate_10042d84,0,1,local_14,len_2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_10042d90,(int)DAT_101cf541);
    len_2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Music_10042d94,0,1,local_14,len_2 + 1);
    wsprintfA((LPSTR)local_14,&DAT_10042d9c,(int)DAT_101cf542);
    len_2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_Effects_10042da0,0,1,local_14,len_2 + 1);
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042da8,0,(LPSTR)0x0,
                          0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_18,&local_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)local_14,&DAT_10042de0,(int)DAT_101cf5e3);
    len_2 = strlen((char *)local_14);
    RegSetValueExA(local_18,s_ExpandTextOnBigCard_10042de4,0,1,local_14,len_2 + 1);
    RegFlushKey(local_18);
    RegCloseKey(local_18);
  }
  return;
}


