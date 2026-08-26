/*
 * Decompiled function: thunk_FUN_100333bb
 * Entry Point: 1000170d
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * thunk_FUN_100333bb(char *str_1,int arg2)

{
  char acStack_6c [100];
  UINT UStack_8;
  
  memcpy(&DAT_1013eb38,&DAT_10046638,0x3c);
  strcpy(acStack_6c,&DAT_10046714);
  strcat(acStack_6c,str_1);
  _DAT_1013eb38 = GetPrivateProfileIntA(s_Fonts_1004671c,acStack_6c,0x14,&DAT_101cf960);
  strcpy(acStack_6c,&DAT_10046724);
  strcat(acStack_6c,str_1);
  UStack_8 = GetPrivateProfileIntA(s_Fonts_1004672c,acStack_6c,0,&DAT_101cf960);
  if (UStack_8 != 0) {
    _DAT_1013eb48 = 700;
  }
  if (arg2 != 0) {
    DAT_1013eb4c = 1;
  }
  strcpy(acStack_6c,&DAT_10046734);
  strcat(acStack_6c,str_1);
  GetPrivateProfileStringA
            (s_Fonts_1004674c,acStack_6c,s_MS_Sans_Serif_1004673c,&DAT_1013eb54,0x20,&DAT_101cf960);
  return &DAT_1013eb38;
}


