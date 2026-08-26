/*
 * Decompiled function: FUN_1001911d
 * Entry Point: 1001911d
 * Size: 325 bytes
 */
#include "deckdll.h"


void FUN_1001911d(HWND hwnd,POINT *arg_2,int arg_3)

{
  BOOL BVar1;
  tagRECT local_4c;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  GetClientRect(hwnd,&local_4c);
  if (1 < *(int *)(&DAT_10176af4 + arg_3 * 0x98)) {
    SetRect(&local_14,local_4c.right + -0x23,local_4c.top + 0x32,local_4c.right + -10,
            local_4c.top + 0x4b);
    local_2c = -1;
    for (local_28 = 0; local_28 < *(int *)(&DAT_10176af4 + arg_3 * 0x98); local_28 = local_28 + 1) {
      if (*(int *)(&DAT_10176af8 + arg_3 * 0x98) == local_28) {
        CopyRect(&local_3c,&local_14);
      }
      BVar1 = PtInRect(&local_14,*arg_2);
      if (BVar1 != 0) {
        local_2c = local_28;
        CopyRect(&local_24,&local_14);
      }
      OffsetRect(&local_14,0,0x19);
    }
    if (local_2c != -1) {
      InvalidateRect(hwnd,&local_3c,0);
      *(int *)(&DAT_10176af8 + arg_3 * 0x98) = local_2c;
      InvalidateRect(hwnd,&local_24,0);
      InvalidateRect(hwnd,(RECT *)0x0,0);
    }
  }
  return;
}


