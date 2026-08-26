/*
 * Decompiled function: FUN_1000dfcc
 * Entry Point: 1000dfcc
 * Size: 190 bytes
 */
#include "deckdll.h"


bool FUN_1000dfcc(int arg_1)

{
  int val_1;
  int val_2;
  
  val_1 = arg_1 + -1;
  val_2 = *(int *)(&DAT_102050b0 + val_1 * 0x114);
  if (val_2 != 0) {
    free(*(void **)(&DAT_102050b8 + val_1 * 0x114));
    fclose(*(FILE **)(&DAT_102050b0 + val_1 * 0x114));
    *(int32_t *)(&DAT_102050b8 + val_1 * 0x114) = 0;
    *(int32_t *)(&DAT_102050b0 + val_1 * 0x114) = 0;
    *(int32_t *)(&DAT_102050b4 + val_1 * 0x114) = 0;
  }
  return val_2 != 0;
}


