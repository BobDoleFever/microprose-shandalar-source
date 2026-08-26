/*
 * Decompiled function: FUN_00472317
 * Entry Point: 00472317
 * Size: 571 bytes
 */
#include "duel.h"


void FUN_00472317(int arg_1,HANDLE arg_2,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  size_t c;
  tagSIZE *psizl;
  RECT local_f8;
  HGDIOBJ local_e8;
  tagRECT local_e4;
  CHAR local_d4 [200];
  tagSIZE local_c;
  
  hdc = *(HDC *)(arg_1 + 0x18);
  CopyRect(&local_e4,(RECT *)(arg_1 + 0x1c));
  GetWindowTextA(*(HWND *)(arg_1 + 0x14),local_d4,200);
  FUN_004707a4(hdc);
  OffsetRect(&local_e4,-*(int *)(arg_1 + 0x1c),-*(int *)(arg_1 + 0x20));
  if ((*(byte *)(arg_1 + 0x10) & 1) == 0) {
    if (((*(byte *)(arg_1 + 0x10) & 4) == 0) && ((*(byte *)(arg_1 + 0x10) & 2) == 0)) {
      FUN_004709ae((int)hdc,(int)&local_e4,arg_2);
    }
    else {
      FUN_004709ae((int)hdc,(int)&local_e4,arg_4);
    }
  }
  else {
    FUN_004709ae((int)hdc,(int)&local_e4,arg_3);
    OffsetRect(&local_e4,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_e8 = (HGDIOBJ)SendMessageA(*(HWND *)(arg_1 + 0x14),0x31,0,0);
  SelectObject(hdc,local_e8);
  DrawTextA(hdc,local_d4,-1,&local_e4,0x25);
  if ((arg_6 != 0) && ((*(byte *)(arg_1 + 0x10) & 0x10) != 0)) {
    psizl = &local_c;
    c = _strlen(local_d4);
    GetTextExtentPoint32A(hdc,local_d4,c,psizl);
    local_f8.left = ((local_e4.right - local_e4.left) / 2 - local_c.cx / 2) + -3;
    local_f8.right = local_c.cx + local_f8.left + 6;
    local_f8.top = ((local_e4.bottom - local_e4.top) / 2 - local_c.cy / 2) + -3;
    local_f8.bottom = local_c.cy + local_f8.top + 6;
    DrawFocusRect(hdc,&local_f8);
  }
  return;
}


