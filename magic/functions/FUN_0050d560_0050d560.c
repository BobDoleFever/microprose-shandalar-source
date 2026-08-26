/*
 * Decompiled function: FUN_0050d560
 * Entry Point: 0050d560
 * Size: 152 bytes
 */
#include "magic.h"


void FUN_0050d560(int arg1,int arg2)

{
  int iVar1;
  HBRUSH hbr;
  RECT local_1c;
  LOGBRUSH local_c;
  
  local_c.lbStyle = 0;
  iVar1 = (&DAT_0070a850)[arg1];
  local_c.lbColor =
       ((byte)(&DAT_0070a452)[arg2 * 4] | 0x200) << 0x10 |
       (uint)(byte)(&DAT_0070a451)[arg2 * 4] << 8 | (uint)(byte)(&DAT_0070a450)[arg2 * 4];
  hbr = CreateBrushIndirect(&local_c);
  local_1c.top = 0;
  local_1c.left = 0;
  local_1c.right = *(LONG *)(iVar1 + 0x20);
  local_1c.bottom = *(LONG *)(iVar1 + 0x24);
  FillRect(*(HDC *)(iVar1 + 4),&local_1c,hbr);
  DeleteObject(hbr);
  return;
}


