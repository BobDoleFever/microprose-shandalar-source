/*
 * Decompiled function: FUN_0042cbbb
 * Entry Point: 0042cbbb
 * Size: 507 bytes
 */
#include "duel.h"


void FUN_0042cbbb(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6)

{
  int local_8;
  
  if (DAT_0068ecf8 != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (DAT_0068ecf8 < 1) {
        while (((0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + arg_1 * 0x20) && (DAT_0068ecf8 == -1))
               && ((arg_6 == -1 || (arg_4 < arg_6 - DAT_00681ea0))))) {
          FUN_0042df08(0x68ece0,6,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
        }
      }
      else {
        while ((0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + arg_1 * 0x20) && (arg_4 < DAT_0068ecf8)))
        {
          FUN_0042df08(0x68ece0,6,1,(int *)0x0,0,arg_1,local_8,arg_2,arg_3);
        }
      }
    }
  }
  if (DAT_0068ece0 != 0) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if (local_8 != 6) {
        if (DAT_0068ece0 == -1) {
          while ((0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + arg_1 * 0x20) &&
                 ((DAT_00681ea0 < arg_6 || (arg_6 == -1))))) {
            FUN_0042df08(0x68ece0,0,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
          }
        }
        else {
          while ((0 < DAT_0068ece0 && (0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + arg_1 * 0x20)))) {
            FUN_0042df08(0x68ece0,0,1,(int *)0x0,0,arg_1,local_8,arg_2,arg_3);
          }
        }
      }
    }
  }
  return;
}


