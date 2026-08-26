/*
 * Decompiled function: FUN_004d6362
 * Entry Point: 004d6362
 * Size: 302 bytes
 */
#include "duel.h"


void FUN_004d6362(undefined4 *arg_1,undefined4 *arg_2,undefined4 *arg_3)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  for (local_10 = 0; local_10 < 7; local_10 = local_10 + 1) {
    if (((&DAT_004ff594)[*(int *)(&DAT_006881e4 + local_10 * 0x120) * 0x34] & 1) != 0) {
      local_8 = local_8 + 1;
    }
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120) * 0x34] & 1) != 0) {
      local_c = local_c + 1;
    }
  }
  if (local_c == 0) {
    *arg_1 = 1;
  }
  else if (local_c == 7) {
    *arg_1 = 2;
  }
  else {
    *arg_1 = 0;
  }
  if (local_8 == 0) {
    *arg_2 = 1;
  }
  else if (local_8 == 7) {
    *arg_2 = 2;
  }
  else {
    *arg_2 = 0;
  }
  if ((local_8 < 2) || (5 < local_8)) {
    *arg_3 = 1;
  }
  else {
    *arg_3 = 0;
  }
  return;
}


