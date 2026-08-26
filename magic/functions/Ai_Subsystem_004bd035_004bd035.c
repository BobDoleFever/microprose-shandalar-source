/*
 * Decompiled function: Ai_Subsystem_004bd035
 * Entry Point: 004bd035
 * Size: 522 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bd035(int arg_1,int arg_2,byte arg_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120);
  local_c = 1;
  if (((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) == 0) ||
      (((&DAT_0051aed1)[iVar1 * 0x34] & 0x10) == 0)) || (((&DAT_0051aed2)[iVar1 * 0x34] & 1) != 0))
  {
    local_c = 0;
  }
  else {
    if (((arg_3 & 1) != 0) &&
       (((iVar1 < 5 || (*(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) == 0x366)) ||
        ((&DAT_006a5f4c)[arg_1 * 0x5b20 + arg_2 * 0x120] == '@')))) {
      local_c = 0;
    }
    if ((((arg_3 & 2) != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0)) &&
       ((4 < iVar1 &&
        ((*(int *)(&g_MasterCardTypeTable + iVar1 * 0x34) != 0x366 &&
         ((&DAT_006a5f4c)[arg_1 * 0x5b20 + arg_2 * 0x120] != '@')))))) {
      local_c = 0;
    }
    if (((arg_3 & 4) != 0) && (((&DAT_006a5f3e)[arg_1 * 0x5b20 + arg_2 * 0x120] & 4) != 0)) {
      local_c = 0;
    }
    if (((arg_3 & 8) != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) != 0)) {
      local_c = 0;
    }
    if (((arg_3 & 0x10) != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) {
      local_c = 0;
    }
  }
  return local_c;
}


