/*
 * Decompiled function: FUN_10023c58
 * Entry Point: 10023c58
 * Size: 197 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_10023c58(int32_t arg1,short arg2)

{
  uint16_t uval_1;
  uint16_t uval_2;
  
  DAT_10140730 = 10;
  DAT_10140731 = 5;
  DAT_10140732 = 1;
  DAT_10140733 = 8;
  DAT_10140734 = 0;
  uval_1 = (uint16_t)arg1;
  DAT_10140738 = uval_1 - 1;
  DAT_10140736 = 0;
  DAT_1014073a = arg2 + -1;
  _DAT_1014073c = 0;
  _DAT_1014073e = 0;
  DAT_10140770 = 0;
  DAT_10140771 = 1;
  uval_2 = (uint16_t)((int)arg1 >> 0x1f);
  DAT_10140772 = uval_1 + (((uval_1 ^ uval_2) - uval_2 & 1 ^ uval_2) - uval_2);
  _DAT_10140774 = 1;
  _DAT_10140776 = 0;
  _DAT_10140778 = 0;
  fwrite(&DAT_10140730,0x80,1,DAT_1013f728);
  return 0;
}


