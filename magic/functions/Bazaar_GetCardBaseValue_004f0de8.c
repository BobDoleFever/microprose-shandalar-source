/*
 * Decompiled function: Bazaar_GetCardBaseValue
 * Entry Point: 004f0de8
 * Size: 95 bytes
 */
#include "magic.h"


int Bazaar_GetCardBaseValue(int arg_1)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0;
      (iVar1 = g_MasterCardCount + 0x10, local_8 < g_MasterCardCount + 0x10 &&
      (iVar1 = local_8,
      *(int *)(&g_MasterCardTypeTable + local_8 * 0x34) != *(int *)(&Scards + arg_1 * 0x10)));
      local_8 = local_8 + 1) {
  }
  return iVar1;
}


