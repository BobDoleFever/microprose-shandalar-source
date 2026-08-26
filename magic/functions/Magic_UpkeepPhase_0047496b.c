/*
 * Decompiled function: Magic_UpkeepPhase
 * Entry Point: 0047496b
 * Size: 788 bytes
 */
#include "magic.h"


/* WARNING: Type propagation algorithm not settling */

undefined4 Magic_UpkeepPhase(int arg_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_134 [264];
  int local_2c;
  int local_28 [8];
  uint local_8;
  
  local_28[1] = 300;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = arg_1;
  local_8 = 0;
  if (g_IsAiThinking == 1) {
    uVar1 = 0;
  }
  else {
    local_28[0] = arg_1;
    if (arg_1 < 0x14) {
      Pic_Subsystem_00423bf4(arg_1,0);
    }
    else if (arg_1 < 0x1d) {
      iVar2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (iVar2 == 0) {
        local_2c = Pic_Subsystem_00424165(local_28,0x14,0x16);
        if (local_2c == 0) {
          Pic_Subsystem_00423b93(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d1c);
        strcat(local_134,(&PTR_s_artifact_wav_00525788)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
      }
      Pic_Subsystem_00423bf4(local_28[0],0);
    }
    else if (arg_1 < 0x22) {
      iVar2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (iVar2 == 0) {
        local_2c = Pic_Subsystem_00424165(local_28,0x1d,0x1d);
        if (local_2c == 0) {
          Pic_Subsystem_00423b93(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d20);
        strcat(local_134,(&PTR_s_buried_wav_0052578c)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
      }
      Pic_Subsystem_00423bf4(local_28[0],0);
    }
    else {
      if (0x2f < arg_1) {
        return 0;
      }
      local_28[1] = 400;
      iVar2 = Pic_Subsystem_00424123(arg_1,local_28);
      if (iVar2 == 0) {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        strcpy(local_134,&DAT_00696910);
        strcat(local_134,&DAT_00525d24);
        strcat(local_134,(&PTR_s_draw_wav_00525790)[arg_1]);
        Pic_Subsystem_00423b57(local_134,local_28[0],local_28 + 1);
        Pic_Subsystem_00423bf4(local_28[0],local_28 + 1);
      }
      else {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        Pic_Subsystem_00423bf4(local_28[0],local_28 + 1);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


