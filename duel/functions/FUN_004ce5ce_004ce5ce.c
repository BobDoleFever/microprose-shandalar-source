/*
 * Decompiled function: FUN_004ce5ce
 * Entry Point: 004ce5ce
 * Size: 677 bytes
 */
#include "duel.h"


void FUN_004ce5ce(int x,int y,int width,uint height)

{
  undefined4 arg_10;
  int iVar1;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (width == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    arg_10 = FUN_004521e2(x,y);
    FUN_0041bcf0((int *)0x0,0,x,2,2,0x200,2,0,0,arg_10,arg_11_00,arg_12_00,arg_13_00,arg_14,
                 arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((width == 0x6c) && (DAT_00690c48 == y)) && (DAT_0068ecb0 == x)) {
      iVar1 = FUN_00468130(x,x,y);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (width == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(x,y);
      iVar1 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                         *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),(undefined1 *)0x0,x,2,2,
                         0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,arg_15,arg_16,arg_17,arg_18,arg_19,
                         arg_20);
      if (iVar1 == 0) {
        FUN_0046e571(x,y,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[y * 0x120 + x * 0x5b20] = (&DAT_00682718)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + y * 0x120 + x * 0x5b20);
      }
      (&DAT_006827b8)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((*(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) == DAT_00690c48) &&
        ((char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] == DAT_0068ecb0)) &&
       ((DAT_00690c48 != -1 &&
        ((((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x20) == 0 && (width == 0x34)))))) {
      DAT_0066642c = DAT_0066642c | height;
    }
  }
  return;
}


