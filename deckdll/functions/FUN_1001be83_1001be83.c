/*
 * Decompiled function: FUN_1001be83
 * Entry Point: 1001be83
 * Size: 576 bytes
 */
#include "deckdll.h"


int32_t FUN_1001be83(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5,uint32_t arg_6,int arg_7)

{
  int32_t uval_1;
  char local_2a0 [500];
  int local_ac;
  int local_a8;
  int32_t local_a4 [4];
  int local_94;
  char *local_30;
  int32_t local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == 0)) {
    uval_1 = 0;
  }
  else {
    local_8 = thunk_FUN_100241ba(arg_4,arg_5);
    if (local_8 == -1) {
      uval_1 = 0;
    }
    else {
      memcpy(local_a4,&DAT_10176ab0 + local_8 * 0x98,0x98);
      local_ac = local_94;
      uval_1 = thunk_FUN_100241a8(arg_4,arg_5);
      local_a8 = thunk_FUN_10024196(uval_1);
      if (((((local_ac == 1) || (local_ac == 8)) ||
           ((local_ac == 7 || ((local_ac == 5 || (local_ac == 2)))))) ||
          ((local_ac == 6 && (local_a8 != 0)))) || ((local_ac == 3 && (local_a8 != 0)))) {
        if (local_a8 == 1) {
          local_94 = 1;
        }
        else if (local_a8 == 5) {
          local_94 = 8;
        }
        else if (local_a8 == 3) {
          local_94 = 5;
        }
        else if (local_a8 == 4) {
          local_94 = 7;
        }
        else if (local_a8 == 2) {
          local_94 = 2;
        }
      }
      strcpy(local_2a0,*(char **)(&DAT_10176b24 + local_8 * 0x98));
      thunk_FUN_10024180(arg_4,arg_5,local_2a0);
      thunk_FUN_1002418b(arg_4,arg_5,local_2a0);
      local_30 = local_2a0;
      local_c = thunk_FUN_10013e94(local_8,arg_4,arg_5);
      uval_1 = thunk_FUN_1001ae07(hdc,arg_2,local_a4,local_c,arg_6,arg_7);
    }
  }
  return uval_1;
}


