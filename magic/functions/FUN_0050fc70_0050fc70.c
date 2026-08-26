/*
 * Decompiled function: FUN_0050fc70
 * Entry Point: 0050fc70
 * Size: 70 bytes
 */
#include "magic.h"


size_t FUN_0050fc70(void *arg1,char *str_2)

{
  size_t _Count;
  FILE *_File;
  
  _Count = _msize(arg1);
  _File = fopen(str_2,&DAT_00532768);
  fwrite(arg1,1,_Count,_File);
  fclose(_File);
  return _Count;
}


