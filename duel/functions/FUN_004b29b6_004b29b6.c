/*
 * Decompiled function: FUN_004b29b6
 * Entry Point: 004b29b6
 * Size: 259 bytes
 */
#include "duel.h"


HGDIOBJ FUN_004b29b6(HWND param_1,uint param_2,HDC param_3)

{
  HBRUSH hbr;
  HGDIOBJ pvVar1;
  tagRECT local_18;
  HDC local_8;
  
  if (param_2 < 0x103) {
    if (param_2 == 0x102) {
switchD_004b2ab0_caseD_201:
      EndDialog(param_1,1);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      GetClientRect(param_1,&local_18);
      hbr = GetStockObject(4);
      FillRect(param_3,&local_18,hbr);
      return (HGDIOBJ)0x1;
    }
switchD_004b2ab0_caseD_112:
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    switch(param_2) {
    case 0x110:
      pvVar1 = (HGDIOBJ)0x1;
      break;
    case 0x111:
      EndDialog(param_1,1);
      pvVar1 = (HGDIOBJ)0x1;
      break;
    default:
      goto switchD_004b2ab0_caseD_112;
    case 0x138:
      local_8 = param_3;
      SetTextColor(param_3,0xffffff);
      SetBkMode(local_8,1);
      pvVar1 = GetStockObject(5);
      break;
    case 0x201:
      goto switchD_004b2ab0_caseD_201;
    }
  }
  return pvVar1;
}


