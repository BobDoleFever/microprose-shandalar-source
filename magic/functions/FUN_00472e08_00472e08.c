/*
 * Decompiled function: FUN_00472e08
 * Entry Point: 00472e08
 * Size: 260 bytes
 */
#include "magic.h"


int FUN_00472e08(int x,int y,undefined4 arg_3,undefined4 arg_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20);
  uVar1 = (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20];
  *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xfffffff7;
  (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = 0xff;
  iVar3 = FUN_00472b91(x,y,arg_3,arg_4);
  if (iVar3 == 0) {
    *(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) = uVar2;
    (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = uVar1;
  }
  return iVar3;
}


