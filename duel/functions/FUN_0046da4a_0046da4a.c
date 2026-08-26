/*
 * Decompiled function: FUN_0046da4a
 * Entry Point: 0046da4a
 * Size: 2677 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0046da4a(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int arg_3;
  int local_14;
  int local_c;
  
  DAT_0068f100 = 1;
  *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 0x800;
  iVar1 = FUN_0048a33f(arg1,arg2);
  if (((((iVar1 == 0) || (DAT_0068f2c4 != 0x15)) || (DAT_00666458 != arg1)) ||
      ((((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0 ||
       (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)))) ||
     (iVar1 = FUN_0048ad82(arg1,arg2), iVar1 == 0)) {
    if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (DAT_0068f230 == -1)) {
      if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) &&
         ((DAT_0068f230 != -1 &&
          (*(code **)(&DAT_004ff5a0 + *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)
           != Palette_Color_0049ae00)))) {
        local_c = 0;
      }
      else if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (DAT_0068f2c4 != 1)) {
        if (DAT_00676510 == arg1) {
          iVar1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
          if ((DAT_0068edd4 == 0) && ((DAT_0068f2c4 == 0x15 || (DAT_0068f2c4 == 0x17)))) {
            if (((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) &&
                (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
               (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0)) {
              if (((DAT_00666458 == arg1) && (iVar1 = FUN_0048ad82(arg1,arg2), iVar1 != 0)) &&
                 (((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0)) {
                DAT_0068f100 = 0;
                return 0x10;
              }
              if ((DAT_00666458 != arg1) && (DAT_006826b0 != 0)) {
                DAT_0068f100 = 0;
                return 0x20;
              }
            }
            *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
          else {
            if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
                *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                     *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                DAT_0068f100 = 0;
                return 0;
              }
              FUN_0048c367((&DAT_004ff596)[iVar1 * 0x34]);
              if ((DAT_0068edd4 == 0) || ((DAT_006826b4 & (byte)(&DAT_004ff594)[iVar1 * 0x34]) != 0)
                 ) {
                if (((&DAT_004ff594)[iVar1 * 0x34] & 1) != 0) {
                  if (((DAT_00666458 == arg1) && (((byte)DAT_00681eb0 & 1) == 0)) &&
                     ((DAT_0068f2c4 == 0x14 || (DAT_0068f2c4 == 0x1e)))) {
                    DAT_0068f100 = 0;
                    return 4;
                  }
                  *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                       *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                  DAT_0068f100 = 0;
                  return 0;
                }
                if (((DAT_00666458 == DAT_00676510) ||
                    (((DAT_00666458 != DAT_00676510 && (DAT_0068edd4 != 0)) &&
                     ((((&DAT_004ff594)[iVar1 * 0x34] & 0x10) != 0 ||
                      (((&DAT_004ff594)[iVar1 * 0x34] & 0x20) != 0)))))) &&
                   ((iVar2 = FUN_004895b4(arg1,arg1,arg2), iVar2 != 0 &&
                    (((((byte)DAT_00681eb0 & 4) == 0 ||
                      ((*(uint *)(&DAT_004ff5a8 + iVar1 * 0x34) & 0x3004) != 0)) &&
                     ((((&DAT_004ff594)[iVar1 * 0x34] & 0x42) != 0 ||
                      (iVar1 = FUN_0048c907(arg1,arg2,0x74,1 - arg1,0xffffffff), iVar1 != 0))))))))
                {
                  DAT_0068f100 = 0;
                  return 4;
                }
              }
            }
            else {
              if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0))
              {
                DAT_00676500 = DAT_00676500 | 3;
                DAT_00666758 = DAT_00666758 | 4;
                DAT_0068f100 = 0;
                return 2;
              }
              if ((((DAT_00666744 == 4) &&
                   (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
                  (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0)) &&
                 (iVar2 = FUN_0048ed18(arg1,arg2), iVar2 != 0)) {
                DAT_00666758 = DAT_00666758 | 2;
                DAT_0068f100 = 0;
                return 8;
              }
              if (((((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
                    (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0)) &&
                   ((DAT_0068edd4 == 0 && ((DAT_00666458 == arg1 && (DAT_0068f2c4 < 0x1b)))))) &&
                  (iVar2 = FUN_0048ad82(arg1,arg2), iVar2 != 0)) &&
                 ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                  (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
                   2) == 0)))) {
                _DAT_0068f0b4 = 1;
              }
              if (((((((&DAT_004ff5a9)[iVar1 * 0x34] & 0x10) != 0) &&
                    (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                   ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                    (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34]
                     & 2) == 0)))) ||
                  (((((&DAT_004ff5a8)[iVar1 * 0x34] & 1) != 0 && ((DAT_006826b4 & 0x10) != 0)) ||
                   ((((&DAT_004ff5a8)[iVar1 * 0x34] & 2) != 0 && ((DAT_006826b4 & 0x20) != 0))))))
                 && ((((((byte)DAT_00681eb0 & 4) == 0 ||
                       ((*(uint *)(&DAT_004ff5a8 + iVar1 * 0x34) & 0x5004) != 0)) &&
                      (DAT_00676500 = DAT_00676500 & 0xfffffffd,
                      ((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)) &&
                     (iVar1 = FUN_0048c907(arg1,arg2,0x73,1 - arg1,0xffffffff), iVar1 != 0)))) {
                if ((DAT_00676500 & 2) != 0) {
                  DAT_00666758 = DAT_00666758 | 4;
                  DAT_0068f100 = 0;
                  return 2;
                }
                DAT_00666758 = DAT_00666758 | 2;
                DAT_0068f100 = 0;
                return 8;
              }
            }
            *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            local_c = 0;
          }
        }
        else if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0))
        {
          DAT_00676500 = DAT_00676500 | 3;
          DAT_00666758 = DAT_00666758 | 4;
          local_c = 2;
        }
        else {
          *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
          local_c = 0;
        }
      }
      else {
        DAT_0068ecb0 = arg1;
        DAT_00690c48 = arg2;
        DAT_0066642c = 0;
        Magic_ScanCards(0x7d);
        local_c = DAT_0066642c;
      }
    }
    else {
      if (*(int *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068f230) {
        if (arg1 == DAT_00681ec4) {
          local_14 = 2;
        }
        else {
          local_14 = 0;
        }
      }
      else {
        arg_3 = 2;
        iVar2 = 0;
        iVar1 = FUN_0046e4c9(arg1,arg2,0x7d,arg1);
        local_14 = FUN_0049aa14(iVar1,iVar2,arg_3);
      }
      if (local_14 == 0) {
        local_c = 0;
      }
      else {
        DAT_00666758 = DAT_00666758 | 1 << ((byte)local_14 & 0x1f);
        DAT_00666454 = DAT_00666454 + 1;
        local_c = local_14;
      }
    }
  }
  else {
    local_c = 2;
  }
  DAT_0068f100 = 0;
  return local_c;
}


