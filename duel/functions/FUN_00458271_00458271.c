/*
 * Decompiled function: FUN_00458271
 * Entry Point: 00458271
 * Size: 367 bytes
 */
#include "duel.h"


undefined4 FUN_00458271(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  int local_8;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar1 = FUN_004af74c(arg_1,arg_2,4);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar1 - 1U & 0x1f);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) && ((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0))))
  {
    iVar3 = FUN_004af7bb(arg_1,arg_2,5);
    bVar4 = *(int *)(&DAT_0068ef50 + iVar3 * 4 + (1 - arg_1) * 0x20) != 0;
    if (!bVar4) {
      for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
        iVar3 = FUN_0048a33f(1 - arg_1,local_8);
        if ((iVar3 != 0) &&
           (cVar1 = (&DAT_006826dc)[local_8 * 0x120 + (1 - arg_1) * 0x5b20],
           bVar2 = FUN_004af7bb(arg_1,arg_2,5), (1 << (bVar2 & 0x1f) & (int)cVar1) != 0)) {
          bVar4 = true;
          break;
        }
      }
    }
    if (bVar4) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return 0;
}


