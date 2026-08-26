/*
 * Decompiled function: FUN_0048b950
 * Entry Point: 0048b950
 * Size: 579 bytes
 */
#include "magic.h"


int FUN_0048b950(uint *arg_1,undefined4 arg_2,undefined4 arg_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint local_4;
  
  iVar3 = 0;
  local_4 = 0xd;
  do {
    (&DAT_00539e08)[iVar3] = 0xffffffff >> ((byte)iVar3 & 0x1f);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  DAT_0053aa94 = arg_1;
  DAT_0053aa90 = arg_1 + 1;
  DAT_0053aa98 = 100000;
  DAT_00527b44 = 0x13;
  uVar1 = DAT_00539e54 & *arg_1;
  DAT_00539e8c = *arg_1 >> 0xd;
  DAT_0053aa9c = uVar1;
  if (0 < (int)uVar1) {
    puVar5 = &DAT_0053aaa8;
    local_4 = uVar1 * 0x1a + 0xd;
    do {
      if (DAT_00527b44 < 0xd) {
        iVar3 = 0xd - DAT_00527b44;
        if ((int)DAT_0053aa90 + (4 - (int)arg_1) < 100000) {
          uVar2 = *DAT_0053aa90;
          DAT_0053aa90 = DAT_0053aa90 + 1;
          uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
          DAT_00539e8c = uVar2 >> ((byte)iVar3 & 0x1f);
          DAT_00527b44 = 0x20 - iVar3;
          *puVar5 = uVar4;
        }
        else {
          *puVar5 = 0xffffffff;
        }
      }
      else {
        uVar2 = DAT_00539e54 & DAT_00539e8c;
        DAT_00539e8c = DAT_00539e8c >> 0xd;
        DAT_00527b44 = DAT_00527b44 - 0xd;
        *puVar5 = uVar2;
      }
      if (DAT_00527b44 < 0xd) {
        iVar3 = 0xd - DAT_00527b44;
        if ((int)DAT_0053aa90 + (4 - (int)arg_1) < 100000) {
          uVar2 = *DAT_0053aa90;
          DAT_0053aa90 = DAT_0053aa90 + 1;
          uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
          DAT_00539e8c = uVar2 >> ((byte)iVar3 & 0x1f);
          DAT_00527b44 = 0x20 - iVar3;
          puVar5[1] = uVar4;
        }
        else {
          puVar5[1] = 0xffffffff;
        }
      }
      else {
        uVar2 = DAT_00539e54 & DAT_00539e8c;
        DAT_00539e8c = DAT_00539e8c >> 0xd;
        DAT_00527b44 = DAT_00527b44 - 0xd;
        puVar5[1] = uVar2;
      }
      puVar5 = puVar5 + 2;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  DAT_0053aaa0 = arg_3;
  DAT_0053aaa4 = arg_2;
  FUN_0048bba0(DAT_0053aa9c);
  return ((int)(local_4 + ((int)local_4 >> 0x1f & 7U)) >> 3) + (uint)((local_4 & 7) != 0);
}


