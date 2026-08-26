/*
 * Decompiled function: FUN_00499128
 * Entry Point: 00499128
 * Size: 103 bytes
 */
#include "duel.h"


void FUN_00499128(HWND hwnd)

{
  uint local_6c [25];
  int local_8;
  
  FUN_0044897a(&local_8,(undefined4 *)0x0);
  if (local_8 == 0) {
    Mem_AllocOrFree_004d9630(local_6c,(uint *)s_Your_attack_00505710);
  }
  else {
    FUN_00448412((char *)local_6c);
    FUN_004d9640(local_6c,(uint *)s__s_attack_0050571c);
  }
  SetWindowTextA(hwnd,(LPCSTR)local_6c);
  return;
}


