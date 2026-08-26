/*
 * Decompiled function: thunk_FUN_10012ca3
 * Entry Point: 100010d2
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10012ca3(void)

{
  LSTATUS LVar1;
  size_t len_2;
  HKEY pHStack_18;
  BYTE aBStack_14 [12];
  DWORD DStack_8;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042d44,0,(LPSTR)0x0,
                          0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&pHStack_18,&DStack_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)aBStack_14,&DAT_10042d80,(int)DAT_101cf540);
    len_2 = strlen((char *)aBStack_14);
    RegSetValueExA(pHStack_18,s_Consolidate_10042d84,0,1,aBStack_14,len_2 + 1);
    wsprintfA((LPSTR)aBStack_14,&DAT_10042d90,(int)DAT_101cf541);
    len_2 = strlen((char *)aBStack_14);
    RegSetValueExA(pHStack_18,s_Music_10042d94,0,1,aBStack_14,len_2 + 1);
    wsprintfA((LPSTR)aBStack_14,&DAT_10042d9c,(int)DAT_101cf542);
    len_2 = strlen((char *)aBStack_14);
    RegSetValueExA(pHStack_18,s_Effects_10042da0,0,1,aBStack_14,len_2 + 1);
    RegFlushKey(pHStack_18);
    RegCloseKey(pHStack_18);
  }
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_MicroProse_Magic__The_G_10042da8,0,(LPSTR)0x0,
                          0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&pHStack_18,&DStack_8);
  if (LVar1 == 0) {
    wsprintfA((LPSTR)aBStack_14,&DAT_10042de0,(int)DAT_101cf5e3);
    len_2 = strlen((char *)aBStack_14);
    RegSetValueExA(pHStack_18,s_ExpandTextOnBigCard_10042de4,0,1,aBStack_14,len_2 + 1);
    RegFlushKey(pHStack_18);
    RegCloseKey(pHStack_18);
  }
  return;
}


