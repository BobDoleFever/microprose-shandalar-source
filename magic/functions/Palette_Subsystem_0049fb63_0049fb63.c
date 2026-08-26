/*
 * Decompiled function: Palette_Subsystem_0049fb63
 * Entry Point: 0049fb63
 * Size: 900 bytes
 */
#include "magic.h"


void Palette_Subsystem_0049fb63(HDC hdc,RECT *arg_2,int arg_3)

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
      local_20 = &DAT_0054b99c;
    }
    else if (*(int *)(arg_3 + 0x10) == 8) {
      local_20 = &DAT_0054b3c4;
    }
    else if (*(int *)(arg_3 + 0x10) == 7) {
      local_20 = &DAT_0054b990;
    }
    else if (*(int *)(arg_3 + 0x10) == 5) {
      local_20 = &DAT_0054b384;
    }
    else if (*(int *)(arg_3 + 0x10) == 2) {
      local_20 = &DAT_0054b984;
    }
    else if (*(int *)(arg_3 + 0x10) == 4) {
      local_20 = &DAT_0054b594;
    }
    else if (*(int *)(arg_3 + 0x10) == 0) {
      local_20 = &DAT_0054b96c;
    }
    else if (*(int *)(arg_3 + 0x10) == 3) {
      local_20 = &DAT_0054b96c;
    }
    else if (*(int *)(arg_3 + 0x10) == 6) {
      if ((*(byte *)(arg_3 + 0xc) & 2) == 0) {
        if ((*(byte *)(arg_3 + 0xc) & 4) == 0) {
          if ((*(byte *)(arg_3 + 0xc) & 0x20) == 0) {
            if ((*(byte *)(arg_3 + 0xd) & 1) == 0) {
              if ((*(byte *)(arg_3 + 0xc) & 8) == 0) {
                iVar1 = strcmp(*(char **)(arg_3 + 4),s_Swamp_0052c1b8);
                if (iVar1 == 0) {
                  local_20 = &DAT_0054b584;
                }
                else {
                  iVar1 = strcmp(*(char **)(arg_3 + 4),s_Plains_0052c1c0);
                  if (iVar1 == 0) {
                    local_20 = &DAT_0054b590;
                  }
                  else {
                    iVar1 = strcmp(*(char **)(arg_3 + 4),s_Mountain_0052c1c8);
                    if (iVar1 == 0) {
                      local_20 = &DAT_0054b8f4;
                    }
                    else {
                      iVar1 = strcmp(*(char **)(arg_3 + 4),s_Forest_0052c1d4);
                      if (iVar1 == 0) {
                        local_20 = &DAT_0054b3c8;
                      }
                      else {
                        iVar1 = strcmp(*(char **)(arg_3 + 4),s_Island_0052c1dc);
                        if (iVar1 == 0) {
                          local_20 = &DAT_0054b748;
                        }
                        else {
                          local_20 = &DAT_0054b998;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_20 = &DAT_0054b998;
              }
            }
            else {
              local_20 = &DAT_0054b378;
            }
          }
          else {
            local_20 = &DAT_0054b924;
          }
        }
        else {
          local_20 = &DAT_0054b974;
        }
      }
      else {
        local_20 = &DAT_0054b998;
      }
    }
    else if (*(int *)(arg_3 + 0x10) == -1) {
      local_20 = &DAT_0054b968;
    }
    else {
      local_20 = &DAT_0054b96c;
    }
    Palette_Subsystem_0049c3ac(local_20);
    if (*local_20 == 0) {
      hbr = GetStockObject(0);
      FillRect(hdc,arg_2,hbr);
    }
    else {
      GetObjectA((HANDLE)*local_20,0x18,local_38);
      SetRect(&local_1c,0,0,200,0x118);
      FUN_004f3bc7(hdc,&local_1c.left,(HANDLE)*local_20,0,0,local_34,(local_30 * 0x3b) / 100);
      local_8 = 0x1e;
      local_c = 0x16;
      SetRect(&local_1c,0,0x16,200,0x34);
      FUN_004f3bc7(hdc,&local_1c.left,(HANDLE)*local_20,0,2,local_34,
                   (((local_30 * 0x3b) / 100) * 0xb) / 100 + 2);
    }
  }
  return;
}


