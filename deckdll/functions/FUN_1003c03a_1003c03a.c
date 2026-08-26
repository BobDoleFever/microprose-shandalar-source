/*
 * Decompiled function: FUN_1003c03a
 * Entry Point: 1003c03a
 * Size: 198 bytes
 */
#include "deckdll.h"


void FUN_1003c03a(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,HGDIOBJ arg_6)

{
  int local_1c;
  int local_18;
  tagSIZE local_14;
  int local_c;
  int local_8;
  
  thunk_FUN_1003c9e0();
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,1000,0x2ee,(LPSIZE)0x0);
  SetViewportExtEx(hdc,arg_4 - arg_2,arg_5 - arg_3,(LPSIZE)0x0);
  SelectObject(hdc,arg_6);
  SetBkMode(hdc,1);
  GetTextExtentPoint32A(hdc,s_Enchantments_1004bc10,0xc,&local_14);
  thunk_FUN_1003c467(hdc,local_14.cx,local_14.cy,&local_8,&local_18,&local_1c,&local_c);
  thunk_FUN_1003c100(hdc,local_14.cx,local_14.cy,local_8,local_18,local_1c,local_c);
  return;
}


