/*
 * Decompiled function: ___sbh_free_block
 * Entry Point: 00405ca0
 * Size: 136 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Debug */

void __cdecl ___sbh_free_block(int arg_1,int arg_2,char *str_3)

{
  int val_1;
  
  val_1 = arg_2 - *(int *)(arg_1 + 0x810) >> 0xc;
  *(char *)(val_1 + 0x10 + arg_1) = *(char *)(val_1 + 0x10 + arg_1) + *str_3;
  *str_3 = '\0';
  *(uint8_t *)(val_1 + 0x410 + arg_1) = 0xf1;
  if ((*(char *)(val_1 + 0x10 + arg_1) == -0x10) &&
     (DAT_004138a8 = DAT_004138a8 + 1, DAT_004138a8 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


