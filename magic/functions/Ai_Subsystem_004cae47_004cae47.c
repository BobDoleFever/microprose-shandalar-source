/*
 * Decompiled function: Ai_Subsystem_004cae47
 * Entry Point: 004cae47
 * Size: 518 bytes
 */
#include "magic.h"


int Ai_Subsystem_004cae47(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_8;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  local_20 = FUN_00473179(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_00473179(arg1,arg2,0x33,0xffffffff);
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = local_20 + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 3;
  }
  iVar2 = (*(int *)(&DAT_0051aed8 + iVar1 * 0x34) + local_20 + 2) * (local_24 + 2);
  local_8 = iVar2 * 5;
  if (((&DAT_0051aecc)[iVar1 * 0x34] & 0x1f) != 0) {
    local_8 = (iVar2 * 0xf) / 2;
  }
  if (((&DAT_0051aecd)[iVar1 * 0x34] & 2) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&DAT_0051aed0)[iVar1 * 0x34] & 3) != 0) {
    local_8 = local_8 / 2;
  }
  if (*(code **)(&DAT_0051aec8 + iVar1 * 0x34) != SpellChain_GetActiveCount) {
    local_8 = (local_8 * 3) / 2;
  }
  if ((*(uint *)(&DAT_0051aecc + iVar1 * 0x34) & 0x1c0) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&DAT_0051aed0)[iVar1 * 0x34] & 8) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&DAT_0051aed0)[iVar1 * 0x34] & 0x10) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0) {
    local_8 = local_8 << 1;
  }
  return local_8;
}


