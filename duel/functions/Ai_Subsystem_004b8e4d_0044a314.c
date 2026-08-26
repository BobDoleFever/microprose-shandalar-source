/*
 * Decompiled function: Ai_Subsystem_004b8e4d
 * Entry Point: 0044a314
 * Size: 656 bytes
 */
#include "duel.h"


undefined1 * Ai_Subsystem_004b8e4d(int arg1,int arg2)

{
  uint arg_1;
  int iVar1;
  uint local_4c [13];
  int local_18;
  int local_14;
  uint local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = (undefined1 *)0x0;
  local_8 = FUN_00450725(arg1,arg2);
  if (local_8 != -1) {
    if (local_8 == DAT_0068f0fc) {
      arg_1 = Mem_AllocOrFree_004506c7(arg1,arg2);
      local_8 = CardIDFromType(arg_1);
    }
    local_10 = (uint)*(ushort *)(&DAT_00682704 + arg2 * 0x120 + arg1 * 0x5b20);
    local_14 = (int)(char)(&DAT_006826d3)[arg2 * 0x120 + arg1 * 0x5b20];
    local_18 = *(int *)(&DAT_006826ec + arg2 * 0x120 + arg1 * 0x5b20);
    if (local_8 == DAT_00666720) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_00516a08,(uint *)s_Damage_004f7fe0);
    }
    else if (local_8 == DAT_00666450) {
      _sprintf(&DAT_00516a08,s_Hunting___s_004f7fe8,
               (&PTR_DAT_004f5500)[*(int *)(&DAT_006826e4 + arg2 * 0x120 + arg1 * 0x5b20)]);
    }
    else if (local_8 == DAT_00666444) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_00516a08,*(uint **)(&DAT_005f7914 + local_10 * 0x14));
    }
    else if (local_8 == DAT_0066aae8) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_00516a08,*(uint **)(&DAT_005f791c + local_10 * 0x14));
    }
    else {
      DAT_00516a08 = '\0';
    }
    if ((local_8 == DAT_00666444) && (0 < *(int *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20))) {
      Mem_AllocOrFree_004d9630(local_4c,(uint *)&DAT_00516a08);
      FUN_00426b51(&DAT_00516a08,(char *)local_4c,
                   *(int *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20));
    }
    iVar1 = FUN_00450725(local_14,local_18);
    if ((iVar1 == 0x361) || (iVar1 == 0x360)) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_00516a08,*(uint **)(&DAT_005f7914 + iVar1 * 0x14));
    }
    if (DAT_00516a08 == '\0') {
      local_c = *(undefined1 **)(&DAT_00618ac4 + local_8 * 0x98);
    }
    else {
      local_c = &DAT_00516a08;
    }
  }
  return local_c;
}


