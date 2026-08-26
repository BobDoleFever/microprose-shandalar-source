/*
 * Decompiled function: Pic_Subsystem_004475a4
 * Entry Point: 0046d497
 * Size: 1142 bytes
 */
#include "duel.h"


void Pic_Subsystem_004475a4(void)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  if ((DAT_00681eb0 & 2) == 0) {
    return;
  }
  DAT_00681eb0 = DAT_00681eb0 & 0xfffffffd;
  DAT_00681eb0 = DAT_00681eb0 | 4;
  FUN_00451482(0,0xff);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < (int)(&DAT_00666408)[local_14]; local_18 = local_18 + 1) {
      if (((*(int *)(&DAT_006826c4 + local_18 * 0x120 + local_14 * 0x5b20) == DAT_0068f104) &&
          (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
         (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
        FUN_0048c50b(local_14,local_18,0x21);
      }
    }
  }
  bVar1 = false;
  do {
    if ((DAT_0066aaf4 != 1) && (DAT_0067650c == 0)) {
      FUN_0048b5c9(9,0xf);
      local_10 = -99999;
      bVar1 = true;
    }
    while( true ) {
      if ((DAT_00666400 == 9) && (bVar1)) {
        FUN_004305d3();
        DAT_0068ecbc = 0;
        DAT_0068ecb8 = 0;
        DAT_0066aae4 = 0;
        DAT_0068f2d4 = 0;
      }
      iVar2 = FUN_0048e32b(-2,0xffffffff,s_Damage_prevention_004f96e8,0x8e);
      if (iVar2 != 0) break;
      Magic_ScanCards(0x25);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&DAT_00666408)[local_14]; local_18 = local_18 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_18 * 0x120 + local_14 * 0x5b20) == DAT_0068f104) &&
              (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
             (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0)) {
            FUN_0048c50b(local_14,local_18,0x6e);
          }
        }
      }
      FUN_0048e8a8(DAT_00666458,0xd7,s_Damage_Dealing_004f96fc,0);
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        for (local_18 = 0; local_18 < (int)(&DAT_00666408)[local_14]; local_18 = local_18 + 1) {
          if ((*(int *)(&DAT_006826c4 + local_18 * 0x120 + local_14 * 0x5b20) == DAT_0068f104) &&
             (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 2) != 0)) {
            if (((&DAT_006826cc)[local_18 * 0x120 + local_14 * 0x5b20] & 0x10) == 0) {
              DAT_00681eb0 = DAT_00681eb0 | 2;
            }
            else {
              FUN_0046e571(local_14,local_18,1);
            }
          }
        }
      }
      FUN_0046d90d();
      DAT_00681eb0 = DAT_00681eb0 & 0xfffffffb;
      if (((DAT_0066aaf4 != 1) || (!bVar1)) || (DAT_00666400 != 9)) {
        if (DAT_0066aaf4 == 1) {
          return;
        }
        if (!bVar1) {
          return;
        }
        DAT_0067650c = 0;
        return;
      }
      Pic_Subsystem_004488a0();
      iVar2 = FUN_00430911(DAT_00676504);
      iVar2 = DAT_0068f2d4 + iVar2;
      if (local_10 < iVar2) {
        FUN_0043081e();
        local_c = DAT_006663f8;
        local_10 = iVar2;
      }
      if (DAT_0066aae0 == 999) {
        DAT_0066aae0 = -1;
      }
      DAT_0066aadc = 0;
      iVar2 = Mem_AllocOrFree_0049f553();
      if ((DAT_0068ef94 * DAT_005071bc) / 5 < iVar2) {
        DAT_0066aaf4 = 0;
        DAT_0066aae0 = -1;
        DAT_006663f8 = local_c;
      }
      DAT_00681eb0 = DAT_00681eb0 | 4;
    }
  } while( true );
}


