/*
 * Decompiled function: FUN_0046e960
 * Entry Point: 0046e960
 * Size: 941 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x0046ea84) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e960(void)

{
  uint uVar1;
  DWORD _Seed;
  uint arg_1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  if (g_IsAiThinking == 0) {
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      *(undefined4 *)(&deck + local_10 * 4) = 0xffffffff;
    }
    if (DAT_0067f388 == 0) {
      for (local_10 = 0; local_10 < 7; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_006a48f0 + local_10 * 4) = 0;
        *(undefined4 *)(&DAT_006a4908 + local_10 * 4) = 0xffffffff;
      }
      _DAT_0067f374 = _DAT_0067f374 | 1 << ((char)DAT_0052effc * '\x02' & 0x1fU);
      *(undefined4 *)(&DAT_005224e8 + DAT_0052effc * 0x20) = 0;
      uVar1 = 1 << ((byte)DAT_0052effc & 0x1f);
      _Seed = GetTickCount();
      srand(_Seed);
      switch(DAT_0067f380) {
      case 0:
        FUN_0046ed22(uVar1,0xd,0xc,10,1,1);
        break;
      case 1:
        FUN_0046ed22(uVar1,0xb,4,0xc,1,1);
        iVar6 = 1;
        iVar5 = 0;
        iVar4 = 4;
        iVar3 = 3;
        iVar2 = 4;
        uVar1 = FUN_0046e922(uVar1);
        FUN_0046ed22(uVar1,iVar2,iVar3,iVar4,iVar5,iVar6);
        break;
      case 2:
        FUN_0046ed22(uVar1,9,3,9,1,1);
        arg_1 = FUN_0046e922(uVar1);
        FUN_0046ed22(arg_1,5,3,4,0,1);
        iVar6 = 1;
        iVar5 = 0;
        iVar4 = 3;
        iVar3 = 3;
        iVar2 = 4;
        uVar1 = FUN_0046e922(uVar1 | arg_1);
        FUN_0046ed22(uVar1,iVar2,iVar3,iVar4,iVar5,iVar6);
        break;
      case 3:
        FUN_0046ed22(uVar1,6,3,5,1,1);
        FUN_0046ed22(1,0xb,5,0xe,0,1);
      }
      DAT_0067bde0 = 0;
      for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
        (&DAT_0067bdc0)[local_10] = 0;
      }
      *(int *)(&DAT_0067bdbc + DAT_0052effc * 4) = *(int *)(&DAT_0067bdbc + DAT_0052effc * 4) + 1;
      for (local_10 = 0; local_10 < 3 - DAT_0067f380; local_10 = local_10 + 1) {
        iVar2 = FUN_0040a1d2(5);
        (&DAT_0067bdc0)[iVar2] = (&DAT_0067bdc0)[iVar2] + 1;
      }
      for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0067bdf0 + local_10 * 100) = 0xffffffff;
      }
      for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_0067f2d0 + local_10 * 0x14) = 0xffffffff;
      }
      for (local_10 = 0; local_10 < 1000; local_10 = local_10 + 1) {
        DAT_0067b9b0 = 0;
      }
      for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
        *(undefined4 *)(&g_PlayerLifeTotals + local_10 * 4) = 8;
      }
      for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
        *(uint *)(&deck + local_10 * 4) = *(uint *)(&deck + local_10 * 4) | 0x10000;
      }
      DAT_0052effc = -1;
    }
  }
  return;
}


