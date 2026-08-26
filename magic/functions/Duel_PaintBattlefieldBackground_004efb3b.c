/*
 * Decompiled function: Duel_PaintBattlefieldBackground
 * Entry Point: 004efb3b
 * Size: 259 bytes
 */
#include "magic.h"


HGDIOBJ Duel_PaintBattlefieldBackground(HWND hwnd,uint arg_2,HDC hdc)

{
  HBRUSH hbr;
  HGDIOBJ pvVar1;
  tagRECT local_18;
  HDC local_8;
  
  if (arg_2 < 0x103) {
    if (arg_2 == 0x102) {
switchD_004efc35_caseD_201:
      EndDialog(hwnd,1);
      return (HGDIOBJ)0x1;
    }
    if (arg_2 == 0x14) {
      GetClientRect(hwnd,&local_18);
      hbr = GetStockObject(4);
      FillRect(hdc,&local_18,hbr);
      return (HGDIOBJ)0x1;
    }
switchD_004efc35_caseD_112:
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    switch(arg_2) {
    case 0x110:
      pvVar1 = (HGDIOBJ)0x1;
      break;
    case 0x111:
      EndDialog(hwnd,1);
      pvVar1 = (HGDIOBJ)0x1;
      break;
    default:
      goto switchD_004efc35_caseD_112;
    case 0x138:
      local_8 = hdc;
      SetTextColor(hdc,0xffffff);
      SetBkMode(local_8,1);
      pvVar1 = GetStockObject(5);
      break;
    case 0x201:
      goto switchD_004efc35_caseD_201;
    }
  }
  return pvVar1;
}


