/*
 * Decompiled function: FUN_10006a43
 * Entry Point: 10006a43
 * Size: 182 bytes
 */
#include "magvid.h"


void __cdecl FUN_10006a43(LPARAM *ptr_1)

{
  tagRECT local_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  GetWindowRect((HWND)ptr_1[4],&local_34);
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&local_14);
  local_24 = (local_34.right - local_34.left) / 2 - (local_c - local_14) / 2;
  local_1c = (local_c - local_14) + local_24;
  local_20 = (local_34.bottom - local_34.top) / 2 - (local_8 - local_10) / 2;
  local_18 = (local_8 - local_10) + local_20;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&local_24);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}


