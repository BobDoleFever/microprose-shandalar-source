/*
 * Decompiled function: FUN_0042458c
 * Entry Point: 0042458c
 * Size: 446 bytes
 */
#include "duel.h"


void FUN_0042458c(LPRECT arg_1,int *arg_2,int arg_3)

{
  int local_58;
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_1 != (LPRECT)0x0) {
    if (arg_2 == (int *)0x0) {
      SetRect(arg_1,0,0,0,0);
    }
    else if (arg_3 == 0) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      SetRect(&local_24,0,0,0,0);
      if (DAT_0050af8c != (HANDLE)0x0) {
        local_14 = *arg_2 + ((arg_2[2] - *arg_2) * 7) / 100;
        local_c = arg_2[2] - ((arg_2[2] - *arg_2) * 10) / 100;
        local_10 = arg_2[1] + ((arg_2[3] - arg_2[1]) * 8) / 100;
        local_8 = arg_2[1] + ((arg_2[3] - arg_2[1]) * 0x23) / 100;
        GetObjectA(DAT_0050af8c,0x18,local_4c);
        local_30 = local_48;
        local_34 = local_44 / 0x18;
        local_2c = local_8 - local_10;
        local_28 = (local_2c * local_48) / local_34;
        for (local_58 = local_28;
            (local_c < (arg_3 + -1) * local_58 + local_28 + local_14 && (1 < local_58));
            local_58 = local_58 + -1) {
        }
        SetRect(&local_24,local_14,local_10,(arg_3 + -1) * local_58 + local_28 + local_14,
                local_2c + local_10);
      }
      CopyRect(arg_1,&local_24);
    }
  }
  return;
}


