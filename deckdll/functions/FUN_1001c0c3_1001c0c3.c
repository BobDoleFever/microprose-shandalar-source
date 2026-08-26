/*
 * Decompiled function: FUN_1001c0c3
 * Entry Point: 1001c0c3
 * Size: 398 bytes
 */
#include "deckdll.h"


void FUN_1001c0c3(HDC hdc,int arg_2,uint32_t arg_3)

{
  uint8_t local_44 [4];
  int local_40;
  int local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  if ((((((hdc != (HDC)0x0) && (arg_2 != 0)) && ((arg_3 & 0x800) == 0)) &&
       ((arg_3 != 0xffffffff && ((arg_3 & 0x10) == 0)))) &&
      (((arg_3 & 0x80) == 0 && (DAT_1013e1f0 != (HANDLE)0x0)))) &&
     (((arg_3 & 0x2e) != 0 || ((arg_3 & 0x100) != 0)))) {
    GetObjectA(DAT_1013e1f0,0x18,local_44);
    local_24 = local_40 / 10;
    local_2c = local_3c;
    if ((arg_3 & 0x20) == 0) {
      if ((arg_3 & 0x100) == 0) {
        if ((arg_3 & 4) == 0) {
          if ((arg_3 & 2) == 0) {
            if ((arg_3 & 8) != 0) {
              local_20 = local_24 << 3;
            }
          }
          else {
            local_20 = local_24 * 6;
          }
        }
        else {
          local_20 = local_24 << 2;
        }
      }
      else {
        local_20 = local_24 * 2;
      }
    }
    else {
      local_20 = 0;
    }
    local_c = local_24 + local_20;
    local_8 = *(int *)(arg_2 + 0xc) - *(int *)(arg_2 + 4);
    local_28 = (local_8 * local_24) / local_3c;
    SetRect(&local_1c,*(int *)(arg_2 + 8) - local_28,*(int *)(arg_2 + 4),*(int *)(arg_2 + 8),
            *(int *)(arg_2 + 4) + local_8);
    thunk_FUN_1003197a(hdc,&local_1c.left,DAT_1013e1f0,local_24,local_2c,local_20,0,local_c,0);
  }
  return;
}


