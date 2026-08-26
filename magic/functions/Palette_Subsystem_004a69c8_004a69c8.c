/*
 * Decompiled function: Palette_Subsystem_004a69c8
 * Entry Point: 004a69c8
 * Size: 845 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a69c8(HWND hwnd,byte arg_2,byte arg_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  WPARAM wParam;
  int local_8;
  
  SendMessageA(hwnd,0x184,0,0);
  for (local_8 = 0; local_8 < DAT_006a49f4; local_8 = local_8 + 1) {
    bVar1 = false;
    bVar2 = false;
    bVar3 = false;
    if (((((((arg_2 & 2) == 0) || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 1)) &&
          (((arg_2 & 0x20) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 8)))) &&
         (((arg_2 & 4) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 2)))) &&
        (((arg_2 & 0x10) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 7)))) &&
       (((arg_2 & 8) == 0 || (*(int *)(&DAT_006b3080 + local_8 * 0x98) != 5)))) {
      if ((*(int *)(&DAT_006b3080 + local_8 * 0x98) == 4) ||
         (((*(int *)(&DAT_006b3080 + local_8 * 0x98) == 0 ||
           (*(int *)(&DAT_006b3080 + local_8 * 0x98) == 3)) ||
          (*(int *)(&DAT_006b3080 + local_8 * 0x98) == 6)))) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((((((arg_3 & 1) == 0) || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 5)) &&
         (((arg_3 & 2) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 7)))) &&
        ((((arg_3 & 4) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 2)) &&
         (((arg_3 & 8) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 6)))))) &&
       (((((arg_3 & 0x10) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 3)) &&
         (((arg_3 & 0x20) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 4)))) &&
        (((arg_3 & 0x40) == 0 || (*(int *)(&DAT_006b3084 + local_8 * 0x98) != 1)))))) {
      if (*(int *)(&DAT_006b3084 + local_8 * 0x98) == 0) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
    if (((((&DAT_006b307c)[local_8 * 0x98] & 0x80) != 0) ||
        (((&DAT_006b307d)[local_8 * 0x98] & 4) != 0)) ||
       (((&DAT_006b307c)[local_8 * 0x98] & 8) != 0)) {
      bVar3 = true;
    }
    if (((bVar1) && (bVar2)) && (bVar3)) {
      wParam = SendMessageA(hwnd,0x180,0,*(LPARAM *)(&DAT_006b3074 + local_8 * 0x98));
      SendMessageA(hwnd,0x19a,wParam,local_8);
    }
  }
  return;
}


