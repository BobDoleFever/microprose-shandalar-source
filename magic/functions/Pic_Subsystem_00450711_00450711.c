/*
 * Decompiled function: Pic_Subsystem_00450711
 * Entry Point: 00450711
 * Size: 302 bytes
 */
#include "magic.h"


void Pic_Subsystem_00450711(undefined4 *arg_1,undefined4 *arg_2,undefined4 *arg_3)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  for (local_10 = 0; local_10 < 7; local_10 = local_10 + 1) {
    if (((&g_MasterCardColorTable)[*(int *)(&DAT_006aba54 + local_10 * 0x120) * 0x34] & 1) != 0) {
      local_8 = local_8 + 1;
    }
    if (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + local_10 * 0x120) * 0x34] & 1) != 0
       ) {
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


