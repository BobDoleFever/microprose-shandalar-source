/*
 * Decompiled function: FUN_0046cc45
 * Entry Point: 0046cc45
 * Size: 1260 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046cc45(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  byte local_c;
  
  iVar1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
    if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
      return 0;
    }
    if ((DAT_0068f230 != -1) && (*(code **)(&DAT_004ff5a0 + iVar1 * 0x34) != Palette_Color_0049ae00)
       ) {
      return 0;
    }
    if ((DAT_004fab48 != 0) && (((&DAT_004ff594)[iVar1 * 0x34] & 0x20) == 0)) {
      return 0;
    }
    if (((((DAT_006826b4 & (byte)(&DAT_004ff594)[iVar1 * 0x34]) != 0) &&
         (iVar2 = FUN_004895b4(arg1,arg1,arg2), iVar2 != 0)) &&
        ((((byte)DAT_00681eb0 & 4) == 0 || ((*(uint *)(&DAT_004ff5a8 + iVar1 * 0x34) & 0x3004) != 0)
         ))) && (((DAT_00676510 == arg1 ||
                  ((_DAT_0052243c & (int)(char)(&DAT_004ff5ad)[iVar1 * 0x34]) != 0)) &&
                 (iVar1 = FUN_0048c907(arg1,arg2,0x74,1 - arg1,0xffffffff), iVar1 != 0)))) {
      return 3;
    }
  }
  else {
    if ((*(int *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068f230) &&
       (DAT_0068f230 != -1)) {
      if (arg1 == DAT_00681ec4) {
        DAT_00666758 = DAT_00666758 | 4;
        DAT_00666454 = DAT_00666454 + 1;
        return 2;
      }
      return 0;
    }
    if (DAT_0068f230 != -1) {
      iVar1 = FUN_0046e4c9(arg1,arg2,0x7d,arg1);
      if (iVar1 == 0) {
        return 0;
      }
      local_c = (byte)iVar1;
      DAT_00666758 = DAT_00666758 | 1 << (local_c & 0x1f);
      DAT_00666454 = DAT_00666454 + 1;
      if (1 < iVar1) {
        return 2;
      }
      return 3;
    }
    if ((((((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) &&
         (((&DAT_004ff5a8)[iVar1 * 0x34] & 1) != 0)) && ((DAT_006826b4 & 0x10) != 0)) ||
       ((((&DAT_004ff5a8)[iVar1 * 0x34] & 2) != 0 && ((DAT_006826b4 & 0x20) != 0)))) {
      if ((DAT_004fab48 != 0) && (((&DAT_004ff5a8)[iVar1 * 0x34] & 2) == 0)) {
        return 0;
      }
      if (((((byte)DAT_00681eb0 & 4) == 0) ||
          ((*(uint *)(&DAT_004ff5a8 + iVar1 * 0x34) & 0x5004) != 0)) &&
         (((DAT_00676500 = DAT_00676500 & 0xfffffffd, DAT_00676510 == arg1 ||
           ((_DAT_00522440 & (int)(char)(&DAT_004ff5ad)[iVar1 * 0x34]) != 0)) &&
          ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0 &&
           (iVar1 = FUN_0048c907(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))))) {
        if ((DAT_00676500 & 2) != 0) {
          DAT_00666758 = DAT_00666758 | 4;
          return 2;
        }
        DAT_00666758 = DAT_00666758 | 2;
        return 3;
      }
    }
    if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
      DAT_00676500 = DAT_00676500 | 3;
      DAT_00666758 = DAT_00666758 | 4;
      return 2;
    }
    if ((((DAT_00666744 == 4) && (arg1 == DAT_00681eb4)) &&
        (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
       ((((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0 &&
        (iVar1 = FUN_0048ed18(arg1,arg2), iVar1 != 0)))) {
      DAT_00666758 = DAT_00666758 | 2;
      if (DAT_00676504 == arg1) {
        return 2;
      }
      return 3;
    }
  }
  return 0;
}


