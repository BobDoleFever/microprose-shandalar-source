/*
 * Decompiled function: FUN_1001f9f7
 * Entry Point: 1001f9f7
 * Size: 424 bytes
 */
#include "deckdll.h"


void FUN_1001f9f7(HDC hdc,int *arg_2,int arg_3,int32_t arg_4,int arg_5)

{
  size_t len_1;
  COLORREF local_74;
  char local_70 [100];
  COLORREF local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (arg_3 != 0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    if (arg_5 == 0) {
      local_74 = DAT_1013e1ec;
    }
    else if (arg_5 == 2) {
      local_74 = DAT_1013e618;
    }
    else {
      local_74 = DAT_1013e654;
    }
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_c = 0x808080;
    }
    else {
      local_c = DAT_1013e1f8;
    }
    SetBkMode(hdc,1);
    SelectObject(hdc,DAT_1013e5cc);
    strcpy(local_70,*(char **)(arg_3 + 8));
    SetTextAlign(hdc,0);
    SetTextColor(hdc,local_c);
    len_1 = strlen(local_70);
    TextOutA(hdc,9,1,local_70,len_1);
    SetTextColor(hdc,local_74);
    len_1 = strlen(local_70);
    TextOutA(hdc,8,0,local_70,len_1);
    RestoreDC(hdc,local_8);
  }
  return;
}


