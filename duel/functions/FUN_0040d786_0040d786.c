/*
 * Decompiled function: FUN_0040d786
 * Entry Point: 0040d786
 * Size: 1858 bytes
 */
#include "duel.h"


undefined4 FUN_0040d786(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (param_3 == 0x73) {
    if ((DAT_00676504 == param_1) &&
       (*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (param_3 == 0x6d) {
      FUN_004348b2(s_prompts_txt_004f2894,s_URZAS_AVENGER_004f2884);
      iVar2 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_006679f0,0);
      *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = iVar2 + 1;
      if (*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) == 5) {
        DAT_00681ea4 = 1;
        *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
    }
    if (param_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        if (((&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] == -1) &&
           (*(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) == -1)) {
          local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
          if (local_8 != -1) {
            *(undefined4 *)(&DAT_006826fc + local_8 * 0x120 + param_1 * 0x5b20) = 0;
            (&DAT_006826d3)
            [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
             *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] =
                 (undefined1)param_1;
            *(int *)(&DAT_006826ec +
                    *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                    *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = local_8;
          }
        }
        else {
          local_8 = *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20);
        }
        if (local_8 != -1) {
          switch(*(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20)) {
          case 1:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) | 0x20;
            break;
          case 2:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) | 0x40;
            break;
          case 3:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) | 0x100;
            break;
          case 4:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + param_1 * 0x5b20) | 0x80;
          }
          *(short *)(&DAT_006826d8 + local_8 * 0x120 + param_1 * 0x5b20) =
               *(short *)(&DAT_006826d8 + local_8 * 0x120 + param_1 * 0x5b20) + 1;
          *(short *)(&DAT_006826da + local_8 * 0x120 + param_1 * 0x5b20) =
               *(short *)(&DAT_006826da + local_8 * 0x120 + param_1 * 0x5b20) + 1;
        }
        *(undefined4 *)
         (&DAT_006826fc +
         *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = 0x8000000;
        *(short *)(&DAT_006826d8 +
                  *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
             *(short *)(&DAT_006826d8 +
                       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) + -1;
        *(short *)(&DAT_006826da +
                  *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
             *(short *)(&DAT_006826da +
                       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) + -1;
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) + 1;
        *(undefined4 *)
         (&DAT_006826f0 +
         *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = 0;
      }
    }
    if ((param_3 == 0x22) || (param_3 == 199)) {
      *(short *)(&DAT_006826d8 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + param_2 * 0x120 + param_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
      *(short *)(&DAT_006826da + param_2 * 0x120 + param_1 * 0x5b20) =
           *(short *)(&DAT_006826da + param_2 * 0x120 + param_1 * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      *(undefined4 *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] =
           (&DAT_006826ec)[param_2 * 0x120 + param_1 * 0x5b20];
    }
    uVar1 = 0;
  }
  return uVar1;
}


