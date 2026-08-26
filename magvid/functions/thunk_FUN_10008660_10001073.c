/*
 * Decompiled function: thunk_FUN_10008660
 * Entry Point: 10001073
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall thunk_FUN_10008660(void *this,char *str_2)

{
  DWORD DVar1;
  
  strcpy(this,str_2);
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x80) = DVar1;
  return;
}


