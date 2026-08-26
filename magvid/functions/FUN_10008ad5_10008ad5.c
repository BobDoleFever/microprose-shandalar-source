/*
 * Decompiled function: FUN_10008ad5
 * Entry Point: 10008ad5
 * Size: 365 bytes
 */
#include "magvid.h"


int __cdecl FUN_10008ad5(int *ptr_1)

{
  uint16_t uval_1;
  bool flag_2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_18;
  int local_14;
  
  flag_2 = FUN_10008c4c(ptr_1);
  if (CONCAT31(extraout_var,flag_2) == 0) {
    uval_1 = *(uint16_t *)((int)ptr_1 + 10);
  }
  else {
    uval_1 = *(uint16_t *)((int)ptr_1 + 0xe);
  }
  if (uval_1 == 1) {
    local_18 = 2;
  }
  else if (uval_1 == 4) {
    local_18 = 0x10;
  }
  else if (uval_1 == 8) {
    local_18 = 0x100;
  }
  else {
    local_18 = 0;
  }
  flag_2 = FUN_10008c4c(ptr_1);
  if ((CONCAT31(extraout_var_00,flag_2) != 0) && (ptr_1[8] != 0)) {
    local_18 = ptr_1[8];
  }
  if (uval_1 == 1) {
    local_14 = 2;
  }
  else if (uval_1 == 4) {
    local_14 = 0x10;
  }
  else if (uval_1 == 8) {
    local_14 = 0x100;
  }
  else {
    local_14 = 0;
  }
  if ((local_14 != 0) && (local_14 < local_18)) {
    local_18 = local_14;
  }
  if (8 < uval_1) {
    local_18 = 0;
  }
  return local_18;
}


