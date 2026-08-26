/*
 * Decompiled function: Minit_Subsystem_0045a9ff
 * Entry Point: 0040d786
 * Size: 1858 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_0045a9ff(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (flags == 0x73) {
    if ((DAT_00676504 == spell_id) &&
       (*(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (flags == 0x6d) {
      FUN_004348b2(s_prompts_txt_004f2894,s_URZAS_AVENGER_004f2884);
      iVar2 = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_006679f0,0);
      *(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = iVar2 + 1;
      if (*(int *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) == 5) {
        DAT_00681ea4 = 1;
        *(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
    }
    if (flags == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        if (((&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] == -1) &&
           (*(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) == -1)) {
          local_8 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
          if (local_8 != -1) {
            *(undefined4 *)(&DAT_006826fc + local_8 * 0x120 + spell_id * 0x5b20) = 0;
            (&DAT_006826d3)
            [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] =
                 (undefined1)spell_id;
            *(int *)(&DAT_006826ec +
                    *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                    *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
                 local_8;
          }
        }
        else {
          local_8 = *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20);
        }
        if (local_8 != -1) {
          switch(*(undefined4 *)(&DAT_006826f0 + target_id * 0x120 + spell_id * 0x5b20)) {
          case 1:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) | 0x20;
            break;
          case 2:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) | 0x40;
            break;
          case 3:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) | 0x100;
            break;
          case 4:
            *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + local_8 * 0x120 + spell_id * 0x5b20) | 0x80;
          }
          *(short *)(&DAT_006826d8 + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006826d8 + local_8 * 0x120 + spell_id * 0x5b20) + 1;
          *(short *)(&DAT_006826da + local_8 * 0x120 + spell_id * 0x5b20) =
               *(short *)(&DAT_006826da + local_8 * 0x120 + spell_id * 0x5b20) + 1;
        }
        *(undefined4 *)
         (&DAT_006826fc +
         *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0x8000000;
        *(short *)(&DAT_006826d8 +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             *(short *)(&DAT_006826d8 +
                       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) + -1
        ;
        *(short *)(&DAT_006826da +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             *(short *)(&DAT_006826da +
                       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) + -1
        ;
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) + 1;
        *(undefined4 *)
         (&DAT_006826f0 +
         *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
      }
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(short *)(&DAT_006826d8 + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006826d8 + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      *(short *)(&DAT_006826da + target_id * 0x120 + spell_id * 0x5b20) =
           *(short *)(&DAT_006826da + target_id * 0x120 + spell_id * 0x5b20) +
           (short)*(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      *(undefined4 *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      *(undefined4 *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      (&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] =
           (&DAT_006826ec)[target_id * 0x120 + spell_id * 0x5b20];
    }
    uVar1 = 0;
  }
  return uVar1;
}


