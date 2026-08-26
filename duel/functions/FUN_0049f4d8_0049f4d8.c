/*
 * Decompiled function: FUN_0049f4d8
 * Entry Point: 0049f4d8
 * Size: 82 bytes
 */
#include "duel.h"


bool FUN_0049f4d8(char *str_1,undefined4 arg2)

{
  FILE *fp;
  
  fp = _fopen(str_1,&DAT_00505e84);
  if (fp != (FILE *)0x0) {
    _fscanf(fp,s_______00505e88,arg2);
  }
  return fp != (FILE *)0x0;
}


