/*
 * Decompiled function: FUN_00406b01
 * Entry Point: 00406b01
 * Size: 75 bytes
 */
#include "magic.h"


bool FUN_00406b01(char *str_1)

{
  FILE *_File;
  
  _File = fopen(str_1,&DAT_0051646c);
  if (_File != (FILE *)0x0) {
    fclose(_File);
  }
  return _File != (FILE *)0x0;
}


