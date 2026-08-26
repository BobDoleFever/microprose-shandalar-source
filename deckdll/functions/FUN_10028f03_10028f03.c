/*
 * Decompiled function: FUN_10028f03
 * Entry Point: 10028f03
 * Size: 80 bytes
 */
#include "deckdll.h"


void FUN_10028f03(int arg_1)

{
  if ((arg_1 != -1) && (*(int *)(&DAT_10162910 + arg_1 * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_10162910 + arg_1 * 0x10));
    *(int32_t *)(&DAT_10162910 + arg_1 * 0x10) = 0;
  }
  return;
}


