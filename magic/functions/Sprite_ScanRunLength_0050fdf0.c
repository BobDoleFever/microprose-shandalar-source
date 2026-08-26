/*
 * Decompiled function: Sprite_ScanRunLength
 * Entry Point: 0050fdf0
 * Size: 154 bytes
 */
#include "magic.h"


int Sprite_ScanRunLength(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((-1 < arg_2) && (-1 < arg_3)) {
    bVar4 = arg_4 != 0;
    iVar1 = Surface_GetPixel(arg_1,arg_2,arg_3);
    if (arg_4 == 0) {
      arg_4 = arg_5;
    }
    iVar3 = 0;
    if (0 < arg_4) {
      do {
        iVar2 = Surface_GetPixel(arg_1,arg_2,arg_3);
        if (iVar2 != iVar1) break;
        iVar3 = iVar3 + 1;
        arg_2 = arg_2 + (uint)bVar4;
        arg_3 = arg_3 + (uint)(arg_5 != 0);
      } while (iVar3 < arg_4);
    }
    if (iVar3 != arg_4) {
      return iVar3;
    }
  }
  return -1;
}


