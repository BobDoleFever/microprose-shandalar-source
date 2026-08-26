/*
 * Decompiled function: FUN_00492b90
 * Entry Point: 00492b90
 * Size: 73 bytes
 */
#include "duel.h"


bool FUN_00492b90(char *str_1)

{
  FILE *fp;
  
  fp = _fopen(str_1,&DAT_0050544c);
  if (fp != (FILE *)0x0) {
    _fclose(fp);
  }
  return fp != (FILE *)0x0;
}


