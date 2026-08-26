/*
 * Decompiled function: FUN_004238e7
 * Entry Point: 004238e7
 * Size: 900 bytes
 */
#include "duel.h"


void FUN_004238e7(HDC hdc,RECT *arg_2,int arg_3)

{
  int iVar1;
  HBRUSH hbr;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  int *local_20;
  tagRECT local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) && (arg_3 != 0)) {
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_20 = &DAT_0050b1f4;
    }
    else if (*(int *)(arg_3 + 0x10) == 8) {
      local_20 = &DAT_0050ac1c;
    }
    else if (*(int *)(arg_3 + 0x10) == 7) {
      local_20 = &DAT_0050b1e8;
    }
    else if (*(int *)(arg_3 + 0x10) == 5) {
      local_20 = &DAT_0050abdc;
    }
    else if (*(int *)(arg_3 + 0x10) == 2) {
      local_20 = &DAT_0050b1dc;
    }
    else if (*(int *)(arg_3 + 0x10) == 4) {
      local_20 = &DAT_0050adec;
    }
    else if (*(int *)(arg_3 + 0x10) == 0) {
      local_20 = &DAT_0050b1c4;
    }
    else if (*(int *)(arg_3 + 0x10) == 3) {
      local_20 = &DAT_0050b1c4;
    }
    else if (*(int *)(arg_3 + 0x10) == 6) {
      if ((*(byte *)(arg_3 + 0xc) & 2) == 0) {
        if ((*(byte *)(arg_3 + 0xc) & 4) == 0) {
          if ((*(byte *)(arg_3 + 0xc) & 0x20) == 0) {
            if ((*(byte *)(arg_3 + 0xd) & 1) == 0) {
              if ((*(byte *)(arg_3 + 0xc) & 8) == 0) {
                iVar1 = _strcmp(*(char **)(arg_3 + 4),s_Swamp_004f35cc);
                if (iVar1 == 0) {
                  local_20 = &DAT_0050addc;
                }
                else {
                  iVar1 = _strcmp(*(char **)(arg_3 + 4),s_Plains_004f35d4);
                  if (iVar1 == 0) {
                    local_20 = &DAT_0050ade8;
                  }
                  else {
                    iVar1 = _strcmp(*(char **)(arg_3 + 4),s_Mountain_004f35dc);
                    if (iVar1 == 0) {
                      local_20 = &DAT_0050b14c;
                    }
                    else {
                      iVar1 = _strcmp(*(char **)(arg_3 + 4),s_Forest_004f35e8);
                      if (iVar1 == 0) {
                        local_20 = &DAT_0050ac20;
                      }
                      else {
                        iVar1 = _strcmp(*(char **)(arg_3 + 4),s_Island_004f35f0);
                        if (iVar1 == 0) {
                          local_20 = &DAT_0050afa0;
                        }
                        else {
                          local_20 = &DAT_0050b1f0;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_20 = &DAT_0050b1f0;
              }
            }
            else {
              local_20 = &DAT_0050abd0;
            }
          }
          else {
            local_20 = &DAT_0050b17c;
          }
        }
        else {
          local_20 = &DAT_0050b1cc;
        }
      }
      else {
        local_20 = &DAT_0050b1f0;
      }
    }
    else if (*(int *)(arg_3 + 0x10) == -1) {
      local_20 = &DAT_0050b1c0;
    }
    else {
      local_20 = &DAT_0050b1c4;
    }
    Pic_Load_s_s_00420120(local_20);
    if (*local_20 == 0) {
      hbr = GetStockObject(0);
      FillRect(hdc,arg_2,hbr);
    }
    else {
      GetObjectA((HANDLE)*local_20,0x18,local_38);
      SetRect(&local_1c,0,0,200,0x118);
      FUN_00470a16(hdc,&local_1c.left,(HANDLE)*local_20,0,0,local_34,(local_30 * 0x3b) / 100);
      local_8 = 0x1e;
      local_c = 0x16;
      SetRect(&local_1c,0,0x16,200,0x34);
      FUN_00470a16(hdc,&local_1c.left,(HANDLE)*local_20,0,2,local_34,
                   (((local_30 * 0x3b) / 100) * 0xb) / 100 + 2);
    }
  }
  return;
}


