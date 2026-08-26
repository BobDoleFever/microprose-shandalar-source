/*
 * Decompiled function: FUN_1001d236
 * Entry Point: 1001d236
 * Size: 435 bytes
 */
#include "deckdll.h"


void FUN_1001d236(HDC hdc,RECT *arg_2,int32_t arg_3,int32_t arg_4)

{
  int arg_1;
  int val_1;
  int local_b0;
  int local_ac;
  uint32_t local_a8;
  int32_t local_a4 [4];
  int32_t local_94;
  int32_t local_c;
  int32_t local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) {
    local_8 = thunk_FUN_1002431f(arg_3,arg_4);
    arg_1 = FUN_101cdebc(local_8);
    if ((DAT_1013f3c4 == arg_1) && (val_1 = thunk_FUN_10024372(arg_3,arg_4), val_1 == DAT_1013f364))
    {
      thunk_FUN_1001ad0b(hdc,arg_2);
    }
    else {
      thunk_FUN_10024331(&local_b0,arg_3,arg_4);
      local_c = thunk_FUN_10013e94(arg_1,local_b0,local_ac);
      memcpy(local_a4,&DAT_10176ab0 + arg_1 * 0x98,0x98);
      local_a8 = thunk_FUN_100241a8(arg_3,arg_4);
      if ((local_a8 & 2) == 0) {
        if ((local_a8 & 0x20) == 0) {
          if ((local_a8 & 8) == 0) {
            if ((local_a8 & 0x10) == 0) {
              if ((local_a8 & 4) != 0) {
                local_94 = 2;
              }
            }
            else {
              local_94 = 7;
            }
          }
          else {
            local_94 = 5;
          }
        }
        else {
          local_94 = 8;
        }
      }
      else {
        local_94 = 1;
      }
      thunk_FUN_1001ae07(hdc,&arg_2->left,local_a4,local_c,2,DAT_1013f380);
    }
  }
  return;
}


