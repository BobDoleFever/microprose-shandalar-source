/*
 * Decompiled function: Prompts_Load_0040c267
 * Entry Point: 0040c267
 * Size: 756 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0040c267(int spell_id,int target_id,int flags)

{
  int iVar1;
  int iVar2;
  
  if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    FUN_004348b2(s_prompts_txt_004f2770,s_PRIMAL_CLAY_004f2764);
    iVar1 = FUN_0045102d(spell_id,spell_id,target_id,-1,-1,&DAT_006679f0,1);
    iVar2 = FUN_004af68f(*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120));
    if (iVar2 != -1) {
      if (iVar1 == 0) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 1;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 6;
        (&DAT_004ff595)[iVar2 * 0x34] = 0;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0;
      }
      else if (iVar1 == 1) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 2;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 2;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0x20;
      }
      else if (iVar1 == 2) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 3;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 3;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0;
      }
      *(int *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120) = iVar2;
      *(undefined4 *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) =
           *(undefined4 *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120);
      *(uint *)(&DAT_006826fc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&DAT_006826fc + spell_id * 0x5b20 + target_id * 0x120) | 0x1000000;
    }
  }
  if (((flags == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
     ((target_id == DAT_00690c48 &&
      ((spell_id == DAT_0068ecb0 && (iVar1 = FUN_0048a33f(spell_id,target_id), iVar1 != 0)))))) {
    DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120);
  }
  if (((flags == 0x77) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    Mem_AllocOrFree_004af72b(*(int *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120));
  }
  return 0;
}


