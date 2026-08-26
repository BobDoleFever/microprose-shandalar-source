/*
 * Decompiled function: FUN_100333bb
 * Entry Point: 100333bb
 * Size: 268 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * FUN_100333bb(char *str_1,int arg2)

{
  char local_6c [100];
  UINT local_8;
  
  memcpy(&DAT_1013eb38,&DAT_10046638,0x3c);
  strcpy(local_6c,&DAT_10046714);
  strcat(local_6c,str_1);
  _DAT_1013eb38 = GetPrivateProfileIntA(s_Fonts_1004671c,local_6c,0x14,&DAT_101cf960);
  strcpy(local_6c,&DAT_10046724);
  strcat(local_6c,str_1);
  local_8 = GetPrivateProfileIntA(s_Fonts_1004672c,local_6c,0,&DAT_101cf960);
  if (local_8 != 0) {
    _DAT_1013eb48 = 700;
  }
  if (arg2 != 0) {
    DAT_1013eb4c = 1;
  }
  strcpy(local_6c,&DAT_10046734);
  strcat(local_6c,str_1);
  GetPrivateProfileStringA
            (s_Fonts_1004674c,local_6c,s_MS_Sans_Serif_1004673c,&DAT_1013eb54,0x20,&DAT_101cf960);
  return &DAT_1013eb38;
}


