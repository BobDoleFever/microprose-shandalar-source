/*
 * Decompiled function: FUN_1001429f
 * Entry Point: 1001429f
 * Size: 1243 bytes
 */
#include "deckdll.h"


LRESULT FUN_1001429f(char *str_1)

{
  size_t len_1;
  int val_2;
  LRESULT LVar3;
  int32_t local_208;
  char local_204;
  char local_203 [499];
  int local_10;
  int local_c;
  int local_8;
  
  local_208 = fopen(str_1,&DAT_10042fec);
  if (local_208 == (FILE *)0x0) {
    local_10 = 0;
  }
  else {
    memset((void *)0x101cded0,0,0x1464);
    if ((DAT_1017646c & 8) != 0) {
      DAT_101628f8 = 0;
      DAT_101cf920 = 0;
    }
    fgets(&local_204,0x1f,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162630,local_203,0x1f);
    fgets(&local_204,0x15,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_1016264f,local_203,0x15);
    fgets(&local_204,0x51,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162664,local_203,0x51);
    fgets(&local_204,0x51,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_101626b5,local_203,0x51);
    fgets(&local_204,0x16,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162706,local_203,0x16);
    fgets(&local_204,0x10,local_208);
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    if (local_204 != ';') {
      return 0;
    }
    DAT_1016271c = atoi(local_203);
    fgets(&local_204,0x10,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162720,local_203,0x10);
    fgets(&local_204,0x191,local_208);
    if (local_204 != ';') {
      return 0;
    }
    len_1 = strlen(&local_204);
    *(uint8_t *)((int)&local_208 + len_1 + 3) = 0;
    strncpy(&DAT_10162730,local_203,0x191);
    while ((val_2 = thunk_FUN_1001477a(local_208,&local_204), val_2 != -1 &&
           (val_2 = thunk_FUN_10014828(&local_204), val_2 == 0))) {
      val_2 = thunk_FUN_100147ed(&local_204);
      if (val_2 != 0) {
        sscanf(&local_204,s___d__d_10042ff0,&local_8,&local_c);
        if (local_c == 0) {
          thunk_FUN_1003947f(6,local_8,0,0x101cded0);
        }
        else {
          thunk_FUN_100391f0(local_8,local_c,0x101cded0);
        }
      }
    }
    fclose(local_208);
    local_10 = 1;
  }
  LVar3 = 0;
  if (local_10 != 0) {
    thunk_FUN_1000880b();
    LVar3 = SendMessageA(DAT_101cf33c,0x401,0,0);
  }
  return LVar3;
}


