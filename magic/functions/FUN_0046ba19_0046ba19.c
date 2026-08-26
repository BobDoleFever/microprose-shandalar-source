/*
 * Decompiled function: FUN_0046ba19
 * Entry Point: 0046ba19
 * Size: 272 bytes
 */
#include "magic.h"


void FUN_0046ba19(HDC hdc,int y,undefined4 arg_3,undefined4 arg_4)

{
  size_t sVar1;
  char local_18 [12];
  int local_c;
  HFONT local_8;
  
  local_c = SaveDC(hdc);
  sprintf(local_18,s__d__d_0052502c,arg_3,arg_4);
  local_8 = CreateFontA(0x12,0,0,0,400,0,0,0,0,0,0,0,0x12,s_Times_New_Roman_00525034);
  SelectObject(hdc,local_8);
  SetBkMode(hdc,1);
  SetTextAlign(hdc,2);
  SetTextColor(hdc,0xffffff);
  sVar1 = strlen(local_18);
  TextOutA(hdc,*(int *)(y + 8),*(int *)(y + 4) + 1,local_18,sVar1);
  SetTextColor(hdc,0x808080);
  sVar1 = strlen(local_18);
  TextOutA(hdc,*(int *)(y + 8) + -1,*(int *)(y + 4),local_18,sVar1);
  RestoreDC(hdc,local_c);
  DeleteObject(local_8);
  return;
}


