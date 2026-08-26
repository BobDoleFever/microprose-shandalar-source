/*
 * Decompiled function: thunk_FUN_1001429f
 * Entry Point: 100013ed
 * Size: 5 bytes
 */
#include "deckdll.h"


LRESULT thunk_FUN_1001429f(char *str_1)

{
  size_t len_1;
  int val_2;
  LRESULT LVar3;
  int32_t uStack_208;
  char cStack_204;
  char acStack_203 [499];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uStack_208 = fopen(str_1,&DAT_10042fec);
  if (uStack_208 == (FILE *)0x0) {
    iStack_10 = 0;
  }
  else {
    memset((void *)0x101cded0,0,0x1464);
    if ((DAT_1017646c & 8) != 0) {
      DAT_101628f8 = 0;
      DAT_101cf920 = 0;
    }
    fgets(&cStack_204,0x1f,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162630,acStack_203,0x1f);
    fgets(&cStack_204,0x15,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_1016264f,acStack_203,0x15);
    fgets(&cStack_204,0x51,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162664,acStack_203,0x51);
    fgets(&cStack_204,0x51,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_101626b5,acStack_203,0x51);
    fgets(&cStack_204,0x16,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162706,acStack_203,0x16);
    fgets(&cStack_204,0x10,uStack_208);
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    if (cStack_204 != ';') {
      return 0;
    }
    DAT_1016271c = atoi(acStack_203);
    fgets(&cStack_204,0x10,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162720,acStack_203,0x10);
    fgets(&cStack_204,0x191,uStack_208);
    if (cStack_204 != ';') {
      return 0;
    }
    len_1 = strlen(&cStack_204);
    *(uint8_t *)((int)&uStack_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162730,acStack_203,0x191);
    while ((val_2 = thunk_FUN_1001477a(uStack_208,&cStack_204), val_2 != -1 &&
           (val_2 = thunk_FUN_10014828(&cStack_204), val_2 == 0))) {
      val_2 = thunk_FUN_100147ed(&cStack_204);
      if (val_2 != 0) {
        sscanf(&cStack_204,s___d__d_10042ff0,&iStack_8,&iStack_c);
        if (iStack_c == 0) {
          thunk_FUN_1003947f(6,iStack_8,0,0x101cded0);
        }
        else {
          thunk_FUN_100391f0(iStack_8,iStack_c,0x101cded0);
        }
      }
    }
    fclose(uStack_208);
    iStack_10 = 1;
  }
  LVar3 = 0;
  if (iStack_10 != 0) {
    thunk_FUN_1000880b();
    LVar3 = SendMessageA(DAT_101cf33c,0x401,0,0);
  }
  return LVar3;
}


