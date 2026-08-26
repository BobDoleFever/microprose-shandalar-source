/*
 * Decompiled function: FUN_004543b6
 * Entry Point: 004543b6
 * Size: 273 bytes
 */
#include "duel.h"


undefined4 FUN_004543b6(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
    if (DAT_0066aaf4 != 1) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Mimic_004f8840);
      FUN_0044a5a4(arg_1,arg_2);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Mimic_different_creature__004f8848);
    }
    iVar1 = FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
    if (iVar1 != 0) {
      Prompts_Load_00454179(arg_1,arg_2,0x6c);
    }
  }
  return 0;
}


