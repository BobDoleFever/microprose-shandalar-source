/*
 * Decompiled function: Palette_Subsystem_0049f8cd
 * Entry Point: 0049f8cd
 * Size: 662 bytes
 */
#include "magic.h"


void Palette_Subsystem_0049f8cd(HDC hdc,int *arg_2,WPARAM *arg_3,int arg_4,int arg_5)

{
  HGDIOBJ h;
  int iVar1;
  tagRECT local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (arg_3 != (WPARAM *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    Palette_Subsystem_0049fb63(hdc,(RECT *)arg_2,(int)arg_3);
    Palette_Subsystem_004a11fa(hdc,arg_2,(char *)arg_3[2],0,1);
    h = GetStockObject(5);
    SelectObject(hdc,h);
    SelectObject(hdc,DAT_0054b964);
    Rectangle(hdc,0,0,200,0x118);
    if (DAT_00695ea4 != 0) {
      SetMapMode(hdc,1);
      local_28 = arg_2[2] - *arg_2;
      local_2c = arg_2[3] - arg_2[1];
      local_30 = (local_28 * 0x12) / 0xe4;
      local_34 = (local_2c * 0xb) / 100 + (local_2c * 8) / 100 + -2;
      local_1c = ((local_28 * 0xd3) / 0xe4 - local_30) + 1;
      local_24 = (local_2c * 0xb2) / 0xbf - local_34;
      SetRect(&local_44,local_30,local_34,local_30 + local_1c,local_24 + local_34);
      iVar1 = FUN_0046bf31(*arg_3,arg_4);
      if (iVar1 == 0) {
        FUN_0046bcc0(*arg_3,arg_4,local_1c,local_24);
      }
      else if (arg_5 != 0) {
        FUN_0046c09f(*arg_3,arg_4,local_1c,local_24);
      }
      local_20 = FUN_0046bfc2(hdc,&local_44,*arg_3,arg_4);
      if (local_20 == 0) {
        FUN_00478763(hdc,&local_44,*arg_3,arg_4);
      }
    }
    RestoreDC(hdc,local_8);
  }
  return;
}


