/*
 * Decompiled function: FUN_100069c9
 * Entry Point: 100069c9
 * Size: 122 bytes
 */
#include "magvid.h"


void __cdecl FUN_100069c9(LPARAM *ptr_1,short *ptr_2)

{
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&local_24);
  local_14 = (int)*ptr_2;
  local_10 = (int)ptr_2[1];
  local_8 = (local_18 - local_20) + local_10;
  local_c = (local_1c - local_24) + local_14;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&local_14);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}


