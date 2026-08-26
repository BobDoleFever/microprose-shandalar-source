/*
 * Decompiled function: FUN_00484ecd
 * Entry Point: 00484ecd
 * Size: 292 bytes
 */
#include "magic.h"


int FUN_00484ecd(int x,int y,int width,undefined4 arg_4)

{
  int iVar1;
  int local_8;
  
  if (DAT_0063ee18 == 0) {
    iVar1 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    switch(width) {
    case 0x32:
      local_8 = (int)*(short *)(&DAT_0051aec2 + iVar1 * 0x34);
      break;
    case 0x33:
      local_8 = (int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34);
      break;
    case 0x34:
      local_8 = *(int *)(&DAT_0051aecc + iVar1 * 0x34);
      break;
    case 0x35:
      local_8 = (int)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20);
      break;
    case 0x36:
      local_8 = (int)(char)(&DAT_0051aebe)[iVar1 * 0x34];
      break;
    default:
      local_8 = 0;
    }
  }
  else {
    local_8 = FUN_00473179(x,y,width,arg_4);
  }
  return local_8;
}


