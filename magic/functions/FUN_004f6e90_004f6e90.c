/*
 * Decompiled function: FUN_004f6e90
 * Entry Point: 004f6e90
 * Size: 701 bytes
 */
#include "magic.h"


undefined4 FUN_004f6e90(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int height;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      local_18 = 0;
      do {
        local_18 = local_18 + 1;
        if (999 < local_18) {
          local_8 = -1;
          break;
        }
        local_14 = FUN_0040a1d2(2);
        local_8 = FUN_0040a1d2(500);
        local_10 = *(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000);
      } while ((local_10 == -1) || (((&g_MasterCardColorTable)[local_10 * 0x34] & 2) == 0));
      if (local_8 == -1) {
        local_1c = 0;
        while ((local_1c < 2 && (local_8 == -1))) {
          local_18 = 0;
          while (((local_18 < 500 &&
                  (*(int *)(&DAT_006ff710 + local_18 * 4 + local_1c * 2000) != -1)) &&
                 (local_8 == -1))) {
            local_10 = *(int *)(&DAT_006ff710 + local_18 * 4 + local_1c * 2000);
            if (((&g_MasterCardColorTable)[local_10 * 0x34] & 2) != 0) {
              local_8 = local_18;
              local_14 = local_1c;
            }
            local_18 = local_18 + 1;
          }
          local_1c = local_1c + 1;
        }
      }
      if ((local_8 != -1) && (*(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000) != -1)) {
        if (g_IsAiThinking != 1) {
          Magic_UpkeepPhase(0x23);
        }
        iVar3 = Pic_Subsystem_00451291
                          (arg_1,*(int *)(&DAT_006ff710 + local_8 * 4 + local_14 * 2000));
        if (local_14 == 0) {
          *(undefined4 *)(&g_CardSlot_Flags + iVar3 * 0x120 + arg_1 * 0x5b20) = 0;
        }
        else {
          *(undefined4 *)(&g_CardSlot_Flags + iVar3 * 0x120 + arg_1 * 0x5b20) = 0x1000;
        }
        if (iVar3 != -1) {
          Pic_Subsystem_00449223(local_14,local_8);
          Pic_Subsystem_0042ac1f(arg_1,iVar3);
          cVar1 = (&DAT_0051aebf)[local_10 * 0x34];
          iVar3 = arg_1;
          height = arg_2;
          iVar4 = FUN_0040a305((int)(char)(&DAT_0051aec0)[local_10 * 0x34],0,99);
          Mem_AllocOrFree_0041df33(arg_1,cVar1 + iVar4,iVar3,height);
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


