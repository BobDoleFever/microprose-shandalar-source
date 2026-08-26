/*
 * Decompiled function: FUN_00513a70
 * Entry Point: 00513a70
 * Size: 140 bytes
 */
#include "magic.h"


void FUN_00513a70(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6)

{
  HPEN h;
  HGDIOBJ ho;
  LOGPEN local_10;
  
  local_10.lopnStyle = 0;
  local_10.lopnColor = arg_6 & 0xffff | 0x1000000;
  local_10.lopnWidth.x = 0;
  local_10.lopnWidth.y = 0;
  h = CreatePenIndirect(&local_10);
  ho = SelectObject(hdc,h);
  DeleteObject(ho);
  for (; arg_3 < arg_5; arg_3 = arg_3 + 1) {
    MoveToEx(hdc,arg_2,arg_3,(LPPOINT)0x0);
    LineTo(hdc,arg_4,arg_3);
  }
  return;
}


