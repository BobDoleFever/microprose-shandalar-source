/*
 * Decompiled function: FUN_00512ba0
 * Entry Point: 00512ba0
 * Size: 95 bytes
 */
#include "magic.h"


int FUN_00512ba0(undefined4 arg1,char *str_2)

{
  int arg_1;
  int iVar1;
  
  arg_1 = _open(str_2,0x8302,0x80);
  iVar1 = arg_1;
  if (arg_1 != -1) {
    DAT_006261d0 = 0;
    iVar1 = Mem_AllocOrFree_00512c90(arg_1,Surface_GetLine,arg1,0,0,0x140,200);
    _close(arg_1);
  }
  return iVar1;
}


