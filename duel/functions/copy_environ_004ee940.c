/*
 * Decompiled function: copy_environ
 * Entry Point: 004ee940
 * Size: 255 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 1998 Debug */

int * __cdecl copy_environ(int *arg_1)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  undefined4 arg_2;
  char *arg_3;
  undefined4 arg_4;
  int local_14;
  int *local_10;
  int *local_c;
  
  local_14 = 0;
  local_10 = arg_1;
  if (arg_1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    while( true ) {
      if (*local_10 == 0) break;
      local_14 = local_14 + 1;
      local_10 = local_10 + 1;
    }
    piVar1 = (int *)__malloc_dbg(local_14 * 4 + 4,2,"setenv.c",0x146);
    if (piVar1 == (int *)0x0) {
      __amsg_exit(9);
    }
    local_c = piVar1;
    for (local_10 = arg_1; *local_10 != 0; local_10 = local_10 + 1) {
      arg_4 = 0x14f;
      arg_3 = "setenv.c";
      arg_2 = 2;
      sVar2 = _strlen((char *)*local_10);
      iVar3 = __malloc_dbg(sVar2 + 1,arg_2,arg_3,arg_4);
      *local_c = iVar3;
      if (*local_c != 0) {
        Mem_AllocOrFree_004d9630((uint *)*local_c,(uint *)*local_10);
      }
      local_c = local_c + 1;
    }
    *local_c = 0;
  }
  return piVar1;
}


