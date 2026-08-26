/*
 * Decompiled function: FUN_00438d5e
 * Entry Point: 00438d5e
 * Size: 271 bytes
 */
#include "duel.h"


undefined4 FUN_00438d5e(WPARAM arg_1,int arg_2,int width,int height)

{
  HGDIOBJ ho;
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) {
    if (((*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) == 0) ||
        (*(int *)(&DAT_0060d5b8 + arg_1 * 0x10) != width)) ||
       (*(int *)(&DAT_0060d5bc + arg_1 * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10);
      *(undefined4 *)(&DAT_0060d5b0 + arg_1 * 0x10) = 0;
      iVar2 = FUN_00438980(arg_1,arg_2,width,height);
      if (iVar2 == 0) {
        *(HGDIOBJ *)(&DAT_0060d5b0 + arg_1 * 0x10) = ho;
        uVar1 = 0;
      }
      else {
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = FUN_004392f3(arg_1,arg_2,width,height);
  }
  return uVar1;
}


