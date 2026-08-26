/*
 * Decompiled function: thunk_FUN_10006a43
 * Entry Point: 1000122b
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10006a43(LPARAM *ptr_1)

{
  tagRECT tStack_34;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  GetWindowRect((HWND)ptr_1[4],&tStack_34);
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&iStack_14);
  iStack_24 = (tStack_34.right - tStack_34.left) / 2 - (iStack_c - iStack_14) / 2;
  iStack_1c = (iStack_c - iStack_14) + iStack_24;
  iStack_20 = (tStack_34.bottom - tStack_34.top) / 2 - (iStack_8 - iStack_10) / 2;
  iStack_18 = (iStack_8 - iStack_10) + iStack_20;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&iStack_24);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}


