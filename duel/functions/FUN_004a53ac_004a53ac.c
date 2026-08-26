/*
 * Decompiled function: FUN_004a53ac
 * Entry Point: 004a53ac
 * Size: 761 bytes
 */
#include "duel.h"


undefined4 FUN_004a53ac(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  if ((((((&DAT_006826fb)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0) &&
       (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_0068ecb0)) &&
     ((DAT_00690c48 != -1 && ((arg_3 == 0x32 || (arg_3 == 0x33)))))) {
    local_14 = 0;
    local_10 = 0;
    iVar2 = (int)(char)(&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120];
    local_8 = 0;
    bVar1 = false;
    while ((local_8 < (int)(&DAT_00666408)[iVar2] && (!bVar1))) {
      if ((((*(int *)(&DAT_006826c4 + local_8 * 0x120 + iVar2 * 0x5b20) == DAT_00690c40) &&
           (((&DAT_006826cc)[local_8 * 0x120 + iVar2 * 0x5b20] & 2) != 0)) &&
          ((&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
           (&DAT_006826d2)[local_8 * 0x120 + iVar2 * 0x5b20])) &&
         (*(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) ==
          *(int *)(&DAT_006826e8 + local_8 * 0x120 + iVar2 * 0x5b20))) {
        bVar1 = true;
        local_10 = -(int)*(short *)(&DAT_006826d8 + local_8 * 0x120 + iVar2 * 0x5b20);
        local_14 = -(int)*(short *)(&DAT_006826da + local_8 * 0x120 + iVar2 * 0x5b20);
      }
      local_8 = local_8 + 1;
    }
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c +
                     *(short *)(&DAT_006826d8 + arg_1 * 0x5b20 + arg_2 * 0x120) + local_10;
    }
    else {
      DAT_0066642c = DAT_0066642c +
                     *(short *)(&DAT_006826da + arg_1 * 0x5b20 + arg_2 * 0x120) + local_14;
    }
  }
  if ((((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}


