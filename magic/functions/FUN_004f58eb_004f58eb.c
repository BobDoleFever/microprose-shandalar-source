/*
 * Decompiled function: FUN_004f58eb
 * Entry Point: 004f58eb
 * Size: 268 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004f58eb(char *str_1,int arg2)

{
  char local_6c [100];
  UINT local_8;
  
  memcpy(&DAT_0061d7f8,&DAT_00530188,0x3c);
  strcpy(local_6c,&DAT_00530264);
  strcat(local_6c,str_1);
  _DAT_0061d7f8 = GetPrivateProfileIntA(s_Fonts_0053026c,local_6c,0x14,&DAT_006ff570);
  strcpy(local_6c,&DAT_00530274);
  strcat(local_6c,str_1);
  local_8 = GetPrivateProfileIntA(s_Fonts_0053027c,local_6c,0,&DAT_006ff570);
  if (local_8 != 0) {
    _DAT_0061d808 = 700;
  }
  if (arg2 != 0) {
    DAT_0061d80c = 1;
  }
  strcpy(local_6c,&DAT_00530284);
  strcat(local_6c,str_1);
  GetPrivateProfileStringA
            (s_Fonts_0053029c,local_6c,s_MS_Sans_Serif_0053028c,&DAT_0061d814,0x20,&DAT_006ff570);
  return &DAT_0061d7f8;
}


