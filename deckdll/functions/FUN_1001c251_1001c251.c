/*
 * Decompiled function: FUN_1001c251
 * Entry Point: 1001c251
 * Size: 196 bytes
 */
#include "deckdll.h"


void FUN_1001c251(HDC hdc,int arg_2,char *str_3)

{
  UINT align;
  char local_34 [20];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (((hdc != (HDC)0x0) && (arg_2 != 0)) && (str_3 != (char *)0x0)) {
    local_20 = (int)*str_3;
    local_1c = (int)str_3[1];
    local_c = (int)str_3[8];
    local_14 = (int)str_3[5];
    local_10 = (int)str_3[7];
    local_18 = (int)str_3[2];
    thunk_FUN_1001c3ea(&local_20,local_34);
    align = SetTextAlign(hdc,2);
    thunk_FUN_1001c5f1(hdc,*(int *)(arg_2 + 8),*(int *)(arg_2 + 4),
                       *(int *)(arg_2 + 0xc) - *(int *)(arg_2 + 4),local_34);
    SetTextAlign(hdc,align);
  }
  return;
}


