/*
 * Decompiled function: FUN_00512c00
 * Entry Point: 00512c00
 * Size: 130 bytes
 */
#include "magic.h"


int FUN_00512c00(undefined4 arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,char *str_7)

{
  int arg_1_00;
  int iVar1;
  
  arg_1_00 = _open(str_7,0x8302,0x80);
  iVar1 = arg_1_00;
  if (arg_1_00 != -1) {
    if (arg_6 != 0) {
      FUN_0050eb90(arg_1_00);
    }
    DAT_006261d0 = (uint)(arg_6 != 0);
    iVar1 = Mem_AllocOrFree_00512c90(arg_1_00,Surface_GetLine,arg_1,arg_2,arg_3,arg_4,arg_5);
    _close(arg_1_00);
  }
  return iVar1;
}


