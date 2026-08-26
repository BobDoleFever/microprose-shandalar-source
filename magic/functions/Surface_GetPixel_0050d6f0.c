/*
 * Decompiled function: Surface_GetPixel
 * Entry Point: 0050d6f0
 * Size: 198 bytes
 */
#include "magic.h"


uint Surface_GetPixel(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  COLORREF CVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  
  iVar1 = (&DAT_0070a850)[arg_1];
  if (arg_1 == 0) {
    CVar2 = GetPixel(_hdcScreen,arg_2,arg_3);
    pbVar4 = &DAT_0070a450;
    uVar3 = 0;
    uVar5 = (-(uint)(DAT_0070a880 == 0x10) & 0xfffffff9) + 0xff;
    while ((((*pbVar4 & uVar5) != (CVar2 & 0xff) || ((pbVar4[1] & uVar5) != (CVar2 >> 8 & 0xff))) ||
           ((pbVar4[2] & uVar5) != (CVar2 >> 0x10 & 0xff)))) {
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 4;
      if (0xff < (int)uVar3) {
        return 0xffffffff;
      }
    }
  }
  else {
    uVar3 = (uint)*(byte *)((*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_3 +
                            *(int *)(iVar1 + 0x18) + arg_2);
  }
  return uVar3;
}


