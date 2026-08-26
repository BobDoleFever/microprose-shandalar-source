/*
 * Decompiled function: thunk_FUN_1001c251
 * Entry Point: 1000166d
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001c251(HDC hdc,int arg_2,char *str_3)

{
  UINT align;
  char acStack_34 [20];
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  if (((hdc != (HDC)0x0) && (arg_2 != 0)) && (str_3 != (char *)0x0)) {
    iStack_20 = (int)*str_3;
    iStack_1c = (int)str_3[1];
    iStack_c = (int)str_3[8];
    iStack_14 = (int)str_3[5];
    iStack_10 = (int)str_3[7];
    iStack_18 = (int)str_3[2];
    thunk_FUN_1001c3ea(&iStack_20,acStack_34);
    align = SetTextAlign(hdc,2);
    thunk_FUN_1001c5f1(hdc,*(int *)(arg_2 + 8),*(int *)(arg_2 + 4),
                       *(int *)(arg_2 + 0xc) - *(int *)(arg_2 + 4),acStack_34);
    SetTextAlign(hdc,align);
  }
  return;
}


