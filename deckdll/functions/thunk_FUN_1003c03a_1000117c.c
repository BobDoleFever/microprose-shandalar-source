/*
 * Decompiled function: thunk_FUN_1003c03a
 * Entry Point: 1000117c
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1003c03a(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,HGDIOBJ arg_6)

{
  int iStack_1c;
  int iStack_18;
  tagSIZE tStack_14;
  int iStack_c;
  int iStack_8;
  
  thunk_FUN_1003c9e0();
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,1000,0x2ee,(LPSIZE)0x0);
  SetViewportExtEx(hdc,arg_4 - arg_2,arg_5 - arg_3,(LPSIZE)0x0);
  SelectObject(hdc,arg_6);
  SetBkMode(hdc,1);
  GetTextExtentPoint32A(hdc,s_Enchantments_1004bc10,0xc,&tStack_14);
  thunk_FUN_1003c467(hdc,tStack_14.cx,tStack_14.cy,&iStack_8,&iStack_18,&iStack_1c,&iStack_c);
  thunk_FUN_1003c100(hdc,tStack_14.cx,tStack_14.cy,iStack_8,iStack_18,iStack_1c,iStack_c);
  return;
}


