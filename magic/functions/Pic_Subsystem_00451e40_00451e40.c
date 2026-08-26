/*
 * Decompiled function: Pic_Subsystem_00451e40
 * Entry Point: 00451e40
 * Size: 461 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pic_Subsystem_00451e40(uint arg_1)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  
  iVar4 = Pic_Subsystem_00452551(arg_1);
  if (2 < iVar4) {
    FUN_0040b3c2(((int)(arg_1 + ((int)arg_1 >> 0x1f & 0xffU)) >> 8) + 8,arg_1 & 0xff);
  }
  iVar4 = FUN_00473cc5((&DAT_0051aebe)[arg_1 * 0x34]);
  bVar1 = (&g_MasterCardColorTable)[arg_1 * 0x34];
  cVar2 = s_Swamp_0051aea9[arg_1 * 0x34];
  bVar3 = false;
  for (local_14 = 0; local_14 < 500; local_14 = local_14 + 1) {
    if (*(int *)(&deck + local_14 * 4) == -1) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    for (local_14 = 0x1f2; -1 < local_14; local_14 = local_14 + -1) {
      if (*(int *)(&deck + local_14 * 4) != -1) {
        uVar5 = *(uint *)(&deck + local_14 * 4) & 0xfff;
        iVar6 = FUN_00473cc5((&DAT_0051aebe)[uVar5 * 0x34]);
        if ((int)(iVar4 * 0x20 + (uint)bVar1 * 0x100 + (int)cVar2) <=
            (int)(iVar6 * 0x20 + (uint)(byte)(&g_MasterCardColorTable)[uVar5 * 0x34] * 0x100 +
                 (int)s_Swamp_0051aea9[uVar5 * 0x34])) {
          *(uint *)(local_14 * 4 + 0x702154) = arg_1;
          return local_14 + 1;
        }
        *(undefined4 *)(local_14 * 4 + 0x702154) = *(undefined4 *)(&deck + local_14 * 4);
      }
    }
    _deck = arg_1;
    iVar4 = 0;
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


