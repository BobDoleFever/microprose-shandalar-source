/*
 * Decompiled function: thunk_FUN_1000e474
 * Entry Point: 10001325
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int16_t * thunk_FUN_1000e474(char *str_1,char *str_2)

{
  char acStack_124 [256];
  int16_t *puStack_24;
  int iStack_20;
  FILE *pFStack_1c;
  int iStack_18;
  char *pcStack_14;
  int iStack_10;
  uint32_t uStack_c;
  uint32_t uStack_8;
  
  iStack_18 = 0;
  puStack_24 = &DAT_10202ad0;
  DAT_10202ad0 = 0x300;
  pFStack_1c = fopen(str_1,&DAT_1004238c);
  if (pFStack_1c == (FILE *)0x0) {
    puStack_24 = (int16_t *)0x0;
  }
  else {
    if (DAT_1012925c != (int *)0x0) {
      thunk_FUN_1000e9d4(DAT_1012925c);
    }
    DAT_1012925c = (int *)thunk_FUN_1000e440();
    fgets(acStack_124,0xff,pFStack_1c);
    while ((pFStack_1c->_flag & 0x10) == 0) {
      sscanf(acStack_124,s__d____d__d__d_10042390,&iStack_18,&iStack_10,&iStack_20,&uStack_c);
      pcStack_14 = strchr(acStack_124,0x2d);
      pcStack_14 = pcStack_14 + 1;
      pcStack_14 = strchr(pcStack_14,0x2d);
      pcStack_14 = pcStack_14 + 1;
      thunk_FUN_1000e8f4(DAT_1012925c,pcStack_14,iStack_18);
      uStack_8 = iStack_20 << 8 | iStack_10 << 0x10 | uStack_c;
      *(uint32_t *)(&DAT_10128a30 + iStack_18 * 4) = uStack_8;
      *(uint8_t *)(puStack_24 + iStack_18 * 2 + 2) = (uint8_t)iStack_10;
      *(uint8_t *)((int)puStack_24 + iStack_18 * 4 + 5) = (uint8_t)iStack_20;
      *(uint8_t *)(puStack_24 + iStack_18 * 2 + 3) = (uint8_t)uStack_c;
      if ((iStack_18 == 0) || (iStack_18 == 0xff)) {
        *(uint8_t *)((int)puStack_24 + iStack_18 * 4 + 7) = 0;
      }
      else {
        *(uint8_t *)((int)puStack_24 + iStack_18 * 4 + 7) = 1;
      }
      fgets(acStack_124,0xff,pFStack_1c);
    }
    DAT_10129248 = 0;
    DAT_10041568 = 0;
    _DAT_10128a28 = thunk_FUN_1000e7bd(DAT_1012925c);
    DAT_10041568 = DAT_10041568 + -1;
    puStack_24[1] = 0x100;
    fclose(pFStack_1c);
    pFStack_1c = (FILE *)0x0;
    if (str_2 != (char *)0x0) {
      pFStack_1c = fopen(str_2,&DAT_100423a0);
    }
    if (pFStack_1c != (FILE *)0x0) {
      fread(&DAT_10202ad0,0x404,1,pFStack_1c);
      fclose(pFStack_1c);
    }
    *(uint8_t *)((int)puStack_24 + 0x403) = 0;
    *(uint8_t *)((int)puStack_24 + 7) = *(uint8_t *)((int)puStack_24 + 0x403);
    thunk_FUN_1000eae7();
    thunk_FUN_1000e6cc();
  }
  return puStack_24;
}


