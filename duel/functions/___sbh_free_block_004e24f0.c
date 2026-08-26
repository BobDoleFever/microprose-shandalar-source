/*
 * Decompiled function: ___sbh_free_block
 * Entry Point: 004e24f0
 * Size: 136 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 1998 Debug */

void ___sbh_free_block(int arg_1,int arg_2,char *str_3)

{
  int iVar1;
  
  iVar1 = arg_2 - *(int *)(arg_1 + 0x810) >> 0xc;
  *(char *)(iVar1 + 0x10 + arg_1) = *(char *)(iVar1 + 0x10 + arg_1) + *str_3;
  *str_3 = '\0';
  *(undefined1 *)(iVar1 + 0x410 + arg_1) = 0xf1;
  if ((*(char *)(iVar1 + 0x10 + arg_1) == -0x10) &&
     (DAT_0050a1f8 = DAT_0050a1f8 + 1, DAT_0050a1f8 == 0x20)) {
    ___sbh_decommit_pages(0x10);
  }
  return;
}


