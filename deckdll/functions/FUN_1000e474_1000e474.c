/*
 * Decompiled function: FUN_1000e474
 * Entry Point: 1000e474
 * Size: 600 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int16_t * FUN_1000e474(char *str_1,char *str_2)

{
  char local_124 [256];
  int16_t *local_24;
  int local_20;
  FILE *local_1c;
  int local_18;
  char *local_14;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  local_18 = 0;
  local_24 = &DAT_10202ad0;
  DAT_10202ad0 = 0x300;
  local_1c = fopen(str_1,&DAT_1004238c);
  if (local_1c == (FILE *)0x0) {
    local_24 = (int16_t *)0x0;
  }
  else {
    if (DAT_1012925c != (int *)0x0) {
      thunk_FUN_1000e9d4(DAT_1012925c);
    }
    DAT_1012925c = (int *)thunk_FUN_1000e440();
    fgets(local_124,0xff,local_1c);
    while ((local_1c->_flag & 0x10) == 0) {
      sscanf(local_124,s__d____d__d__d_10042390,&local_18,&local_10,&local_20,&local_c);
      local_14 = strchr(local_124,0x2d);
      local_14 = local_14 + 1;
      local_14 = strchr(local_14,0x2d);
      local_14 = local_14 + 1;
      thunk_FUN_1000e8f4(DAT_1012925c,local_14,local_18);
      local_8 = local_20 << 8 | local_10 << 0x10 | local_c;
      *(uint32_t *)(&DAT_10128a30 + local_18 * 4) = local_8;
      *(uint8_t *)(local_24 + local_18 * 2 + 2) = (uint8_t)local_10;
      *(uint8_t *)((int)local_24 + local_18 * 4 + 5) = (uint8_t)local_20;
      *(uint8_t *)(local_24 + local_18 * 2 + 3) = (uint8_t)local_c;
      if ((local_18 == 0) || (local_18 == 0xff)) {
        *(uint8_t *)((int)local_24 + local_18 * 4 + 7) = 0;
      }
      else {
        *(uint8_t *)((int)local_24 + local_18 * 4 + 7) = 1;
      }
      fgets(local_124,0xff,local_1c);
    }
    DAT_10129248 = 0;
    DAT_10041568 = 0;
    _DAT_10128a28 = thunk_FUN_1000e7bd(DAT_1012925c);
    DAT_10041568 = DAT_10041568 + -1;
    local_24[1] = 0x100;
    fclose(local_1c);
    local_1c = (FILE *)0x0;
    if (str_2 != (char *)0x0) {
      local_1c = fopen(str_2,&DAT_100423a0);
    }
    if (local_1c != (FILE *)0x0) {
      fread(&DAT_10202ad0,0x404,1,local_1c);
      fclose(local_1c);
    }
    *(uint8_t *)((int)local_24 + 0x403) = 0;
    *(uint8_t *)((int)local_24 + 7) = *(uint8_t *)((int)local_24 + 0x403);
    thunk_FUN_1000eae7();
    thunk_FUN_1000e6cc();
  }
  return local_24;
}


