/*
 * Decompiled function: FUN_0050a9bf
 * Entry Point: 0050a9bf
 * Size: 1228 bytes
 */
#include "magic.h"


int FUN_0050a9bf(int arg_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0x28;
  switch((&g_MasterCardColorTable)[arg_1 * 0x34]) {
  case 2:
  case 0x42:
    if ((*(ushort *)(&DAT_0051aec2 + arg_1 * 0x34) & 0xbfff) == 0xfffe) {
      local_10 = (int)*(short *)(&DAT_0051aec2 + arg_1 * 0x34);
    }
    else {
      local_10 = ((int)*(short *)(&DAT_0051aec2 + arg_1 * 0x34) & 0xffffbfffU) + 3;
    }
    if ((*(ushort *)(&DAT_0051aec4 + arg_1 * 0x34) & 0xbfff) == 0xfffe) {
      local_c = (int)*(short *)(&DAT_0051aec4 + arg_1 * 0x34);
    }
    else {
      local_c = ((int)*(short *)(&DAT_0051aec4 + arg_1 * 0x34) & 0xffffbfffU) + 3;
    }
    local_c = (*(int *)(&DAT_0051aed8 + arg_1 * 0x34) + local_10) * local_c;
    local_8 = local_c * 5;
    if (((&DAT_0051aecc)[arg_1 * 0x34] & 0x1f) != 0) {
      local_8 = (local_c * 0xf) / 2;
    }
    if (((&DAT_0051aecd)[arg_1 * 0x34] & 2) != 0) {
      local_8 = (local_8 * 3) / 2;
    }
    if (*(code **)(&DAT_0051aec8 + arg_1 * 0x34) != SpellChain_GetActiveCount) {
      local_8 = (local_8 * 3) / 2;
    }
    if ((*(uint *)(&DAT_0051aecc + arg_1 * 0x34) & 0x1c0) != 0) {
      local_8 = (local_8 * 3) / 2;
    }
    if (((&DAT_0051aed0)[arg_1 * 0x34] & 8) != 0) {
      local_8 = local_8 * 3;
    }
    if (((&DAT_0051aed0)[arg_1 * 0x34] & 0x10) != 0) {
      local_8 = local_8 * 3;
    }
    iVar1 = abs((int)(char)(&DAT_0051aec0)[arg_1 * 0x34]);
    local_8 = local_8 / ((char)(&DAT_0051aebf)[arg_1 * 0x34] + iVar1 + 1);
    break;
  case 4:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[arg_1 * 0x34]);
    iVar1 = (iVar1 + (char)(&DAT_0051aebf)[arg_1 * 0x34] + *(int *)(&DAT_0051aed8 + arg_1 * 0x34)) *
            5 + 5;
    local_8 = iVar1 * 5;
    if (((&DAT_0051aed0)[arg_1 * 0x34] & 3) != 0) {
      local_8 = iVar1 * 10;
    }
    break;
  case 8:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[arg_1 * 0x34]);
    local_8 = ((iVar1 + (char)(&DAT_0051aebf)[arg_1 * 0x34] + *(int *)(&DAT_0051aed8 + arg_1 * 0x34)
               ) * 4 + 4) * 5;
    break;
  case 0x10:
  case 0x20:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[arg_1 * 0x34]);
    local_8 = *(int *)(&DAT_0051aed8 + arg_1 * 0x34) * 0x14 +
              ((iVar1 + (char)(&DAT_0051aebf)[arg_1 * 0x34]) * 5 + 5) * 8;
    if ((&DAT_0051aec0)[arg_1 * 0x34] == -1) {
      local_8 = (local_8 * 3) / 2;
    }
    break;
  case 0x40:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[arg_1 * 0x34]);
    local_8 = (int)(0xfa / (longlong)(*(int *)(&DAT_0051aed8 + arg_1 * 0x34) + iVar1 + 2));
  }
  iVar1 = Pic_Subsystem_00452551(arg_1);
  if (iVar1 == 2) {
    local_8 = FUN_0040a305(local_8 * 2,100,9999);
  }
  else if (iVar1 == 3) {
    local_8 = FUN_0040a305(local_8 << 2,200,9999);
  }
  else if (iVar1 == 4) {
    local_8 = FUN_0040a305(local_8 << 3,200,9999);
  }
  if (((&DAT_0051aed1)[arg_1 * 0x34] & 2) != 0) {
    local_8 = local_8 << 1;
  }
  if (((&DAT_0051aed1)[arg_1 * 0x34] & 4) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  return local_8;
}


