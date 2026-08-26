/*
 * Decompiled function: FUN_004428d2
 * Entry Point: 004428d2
 * Size: 452 bytes
 */
#include "duel.h"


INT_PTR FUN_004428d2(int arg_1,undefined4 arg_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 local_20;
  INT_PTR local_1c;
  uint local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  
  if (arg_1 == 0) {
    local_20 = arg_2;
    local_18 = (uint)(arg_3 != -1);
    local_14 = str_4;
    local_10 = str_5;
    local_c = str_6;
    if ((str_4 == (char *)0x0) || (*str_4 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((str_5 == (char *)0x0) || (*str_5 == '\0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((str_6 == (char *)0x0) || (*str_6 == '\0')) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (((bVar1) || (bVar2)) || (bVar3)) {
      if (arg_3 < 0) {
        arg_3 = 0;
      }
      if (2 < arg_3) {
        arg_3 = 2;
      }
      if ((arg_3 == 0) && (!bVar1)) {
        arg_3 = 1;
      }
      if ((arg_3 == 1) && (!bVar2)) {
        arg_3 = 2;
      }
      if ((arg_3 == 2) && (!bVar3)) {
        arg_3 = 0;
      }
      if ((arg_3 == 0) && (!bVar1)) {
        arg_3 = 1;
      }
      local_1c = arg_3;
      arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe4,DAT_00618990,UI_DialogProc_00442a9b,
                              (LPARAM)&local_20);
    }
  }
  return arg_3;
}


