/*
 * Decompiled function: FUN_0046c09f
 * Entry Point: 0046c09f
 * Size: 271 bytes
 */
#include "magic.h"


undefined4 FUN_0046c09f(WPARAM arg_1,int arg_2,int width,int height)

{
  HGDIOBJ ho;
  undefined4 uVar1;
  int iVar2;
  
  if (arg_1 == 0xffffffff) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    if (((*(int *)(&DAT_00696a20 + arg_1 * 0x10) == 0) ||
        (*(int *)(&DAT_00696a28 + arg_1 * 0x10) != width)) ||
       (*(int *)(&DAT_00696a2c + arg_1 * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10);
      *(undefined4 *)(&DAT_00696a20 + arg_1 * 0x10) = 0;
      iVar2 = FUN_0046bcc0(arg_1,arg_2,width,height);
      if (iVar2 == 0) {
        *(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10) = ho;
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
    uVar1 = FUN_0046c636(arg_1,arg_2,width,height);
  }
  return uVar1;
}


