/*
 * Decompiled function: FUN_00462039
 * Entry Point: 00462039
 * Size: 175 bytes
 */
#include "duel.h"


undefined4 FUN_00462039(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    iVar1 = FUN_00468a84(arg_1);
    if (iVar1 == 0) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}


