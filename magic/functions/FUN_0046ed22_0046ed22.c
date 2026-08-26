/*
 * Decompiled function: FUN_0046ed22
 * Entry Point: 0046ed22
 * Size: 1104 bytes
 */
#include "magic.h"


undefined4 FUN_0046ed22(uint arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  bool bVar1;
  int iVar2;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  for (local_10 = 0; (int)local_10 < arg_2; local_10 = local_10 + 1) {
    local_14 = Pic_Subsystem_00451d90(1,arg_1);
    iVar2 = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[local_14 * 0x34],arg_1,0);
    if (((iVar2 == 0) || (4 < (int)local_14)) || (((&DAT_0051aed6)[local_14 * 0x34] & 0xc1) == 0)) {
      local_10 = local_10 + -1;
    }
    else {
      Pic_Subsystem_00451e40(local_14);
    }
  }
  for (local_10 = 0; (int)local_10 < arg_3; local_10 = local_10 + 1) {
    if (arg_6 == 0) {
      local_18 = 0;
    }
    else {
      local_18 = rand();
      local_18 = local_18 & 1;
    }
    if (local_18 == 0) {
      local_1c = arg_1;
    }
    else {
      local_1c = 1;
    }
    local_14 = Pic_Subsystem_00451d90((-(uint)(local_18 == 0) & 0xffffffc4) + 0x40,local_1c);
    if (((DAT_0067f380 == 0) && (((&DAT_0051aecc)[local_14 * 0x34] & 3) != 0)) ||
       (((&DAT_0051aed1)[local_14 * 0x34] & 9) != 0)) {
      local_10 = local_10 - 1;
    }
    else {
      if (((&g_MasterCardColorTable)[local_14 * 0x34] & 4) != 0) {
        local_18 = 0;
      }
      if (local_18 == 0) {
        local_20 = arg_1;
      }
      else {
        local_20 = 1;
      }
      iVar2 = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[local_14 * 0x34],local_20,0);
      if (((iVar2 == 0) ||
          (iVar2 = Pic_Subsystem_00452551(local_14), (int)(((local_10 & 1) == 0) + 1) < iVar2)) ||
         (((&DAT_0051aed6)[local_14 * 0x34] & 0xc1) == 0)) {
        local_10 = local_10 - 1;
      }
      else {
        Pic_Subsystem_00451e40(local_14);
      }
    }
  }
  local_c = 0;
  for (local_10 = 0; (int)local_10 < arg_4; local_10 = local_10 + 1) {
    local_14 = Pic_Subsystem_00451d90(2,arg_1);
    if (((DAT_0067f380 < 4) && (((&DAT_0051aecc)[local_14 * 0x34] & 3) != 0)) ||
       (((&DAT_0051aed1)[local_14 * 0x34] & 9) != 0)) {
      local_10 = local_10 - 1;
      local_c = local_c + -1;
    }
    else {
      if (local_c < 1000) {
        iVar2 = Duel_UpdateCardMotionStep(local_14);
        bVar1 = 0 < iVar2;
      }
      else {
        bVar1 = true;
      }
      iVar2 = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[local_14 * 0x34],arg_1,0);
      if (((iVar2 == 0) ||
          (iVar2 = Pic_Subsystem_00452551(local_14), (int)(((local_10 & 1) == 0) + 1) < iVar2)) ||
         ((!bVar1 || (((&DAT_0051aed6)[local_14 * 0x34] & 0xc1) == 0)))) {
        local_10 = local_10 - 1;
      }
      else {
        Pic_Subsystem_00451e40(local_14);
      }
    }
    local_c = local_c + 1;
  }
  if (arg_5 != 0) {
    do {
      do {
        local_14 = Pic_Subsystem_00451d90(0xe,1);
        iVar2 = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[local_14 * 0x34],arg_1,1);
      } while (iVar2 == 0);
      iVar2 = Pic_Subsystem_00452551(local_14);
    } while ((((iVar2 < 3) || (iVar2 = Duel_UpdateCardMotionStep(local_14), iVar2 < 1)) ||
             ((DAT_0067f380 == 0 && (((&DAT_0051aecc)[local_14 * 0x34] & 3) != 0)))) ||
            ((((&DAT_0051aed1)[local_14 * 0x34] & 9) != 0 ||
             (((&DAT_0051aed6)[local_14 * 0x34] & 0xc1) == 0))));
  }
  Pic_Subsystem_00451e40(local_14);
  return 0;
}


