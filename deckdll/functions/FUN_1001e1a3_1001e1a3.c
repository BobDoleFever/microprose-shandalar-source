/*
 * Decompiled function: FUN_1001e1a3
 * Entry Point: 1001e1a3
 * Size: 900 bytes
 */
#include "deckdll.h"


void FUN_1001e1a3(HDC hdc,RECT *arg_2,int arg_3)

{
  int val_1;
  HBRUSH hbr;
  uint8_t local_38 [4];
  int local_34;
  int local_30;
  int *local_20;
  tagRECT local_1c;
  int32_t local_c;
  int32_t local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) && (arg_3 != 0)) {
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_20 = &DAT_1013e60c;
    }
    else if (*(int *)(arg_3 + 0x10) == 8) {
      local_20 = &DAT_1013e034;
    }
    else if (*(int *)(arg_3 + 0x10) == 7) {
      local_20 = &DAT_1013e600;
    }
    else if (*(int *)(arg_3 + 0x10) == 5) {
      local_20 = &DAT_1013dff4;
    }
    else if (*(int *)(arg_3 + 0x10) == 2) {
      local_20 = &DAT_1013e5f4;
    }
    else if (*(int *)(arg_3 + 0x10) == 4) {
      local_20 = &DAT_1013e204;
    }
    else if (*(int *)(arg_3 + 0x10) == 0) {
      local_20 = &DAT_1013e5dc;
    }
    else if (*(int *)(arg_3 + 0x10) == 3) {
      local_20 = &DAT_1013e5dc;
    }
    else if (*(int *)(arg_3 + 0x10) == 6) {
      if ((*(uint8_t *)(arg_3 + 0xc) & 2) == 0) {
        if ((*(uint8_t *)(arg_3 + 0xc) & 4) == 0) {
          if ((*(uint8_t *)(arg_3 + 0xc) & 0x20) == 0) {
            if ((*(uint8_t *)(arg_3 + 0xd) & 1) == 0) {
              if ((*(uint8_t *)(arg_3 + 0xc) & 8) == 0) {
                val_1 = strcmp(*(char **)(arg_3 + 4),s_Swamp_100438a0);
                if (val_1 == 0) {
                  local_20 = &DAT_1013e1f4;
                }
                else {
                  val_1 = strcmp(*(char **)(arg_3 + 4),s_Plains_100438a8);
                  if (val_1 == 0) {
                    local_20 = &DAT_1013e200;
                  }
                  else {
                    val_1 = strcmp(*(char **)(arg_3 + 4),s_Mountain_100438b0);
                    if (val_1 == 0) {
                      local_20 = &DAT_1013e564;
                    }
                    else {
                      val_1 = strcmp(*(char **)(arg_3 + 4),s_Forest_100438bc);
                      if (val_1 == 0) {
                        local_20 = &DAT_1013e038;
                      }
                      else {
                        val_1 = strcmp(*(char **)(arg_3 + 4),s_Island_100438c4);
                        if (val_1 == 0) {
                          local_20 = &DAT_1013e3b8;
                        }
                        else {
                          local_20 = &DAT_1013e608;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_20 = &DAT_1013e608;
              }
            }
            else {
              local_20 = &DAT_1013dfe8;
            }
          }
          else {
            local_20 = &DAT_1013e594;
          }
        }
        else {
          local_20 = &DAT_1013e5e4;
        }
      }
      else {
        local_20 = &DAT_1013e608;
      }
    }
    else if (*(int *)(arg_3 + 0x10) == -1) {
      local_20 = &DAT_1013e5d8;
    }
    else {
      local_20 = &DAT_1013e5dc;
    }
    thunk_FUN_1001a9ec(local_20);
    if (*local_20 == 0) {
      hbr = GetStockObject(0);
      FillRect(hdc,arg_2,hbr);
    }
    else {
      GetObjectA((HANDLE)*local_20,0x18,local_38);
      SetRect(&local_1c,0,0,200,0x118);
      thunk_FUN_10031697(hdc,&local_1c.left,(HANDLE)*local_20,0,0,local_34,(local_30 * 0x3b) / 100);
      local_8 = 0x1e;
      local_c = 0x16;
      SetRect(&local_1c,0,0x16,200,0x34);
      thunk_FUN_10031697(hdc,&local_1c.left,(HANDLE)*local_20,0,2,local_34,
                         (((local_30 * 0x3b) / 100) * 0xb) / 100 + 2);
    }
  }
  return;
}


