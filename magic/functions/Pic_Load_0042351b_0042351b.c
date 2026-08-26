/*
 * Decompiled function: Pic_Load_0042351b
 * Entry Point: 0042351b
 * Size: 792 bytes
 */
#include "magic.h"


undefined4
Pic_Load_0042351b(int arg_1,undefined4 arg_2,undefined4 arg_3,char *str_4,undefined1 *arg_5)

{
  char *_Str2;
  int iVar1;
  undefined4 arg_1_00;
  undefined4 arg_2_00;
  int local_414;
  int local_410;
  undefined1 local_40c [1024];
  byte *local_c;
  int local_8;
  
  local_8 = 8;
  _Str2 = strchr(str_4,0x2e);
  iVar1 = _stricmp(&DAT_00520cc8,_Str2);
  if (iVar1 == 0) {
    DAT_00703930 = (int)fopen(str_4,&DAT_00520cd0);
    if ((FILE *)DAT_00703930 == (FILE *)0x0) {
      return 0;
    }
    DAT_00703938 = str_4;
    if (arg_5 == (undefined1 *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (undefined1 *)0x0) {
      FUN_00512500((void *)0x0);
      if (arg_1 < 0) {
        DAT_00536864 = 0;
      }
      if ((int)DAT_00536860 % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)DAT_00536860 % 3;
      }
      DAT_00538ad4 = DAT_00536860 + local_410;
      FUN_004232f0(DAT_00538ad4,DAT_00536864,local_8);
      local_c = *(byte **)(PTR_DAT_00520cb8 + 0x18);
      for (DAT_00538adc = 0; DAT_00538adc < DAT_00536864; DAT_00538adc = DAT_00538adc + 1) {
        FUN_005126b0(local_c);
        local_c = local_c + ((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3) * DAT_00538ad4;
      }
      fclose((FILE *)DAT_00703930);
    }
    else {
      FUN_00512500(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(undefined2 *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_00538ae0 = Pic_Subsystem_004238ba(str_4,0x8000);
    if (DAT_00538ae0 == -1) {
      AssertOrLog(0,0x520cec,0xe4,s_Could_not_open_file__s_00520cd4);
      *(undefined4 *)(PTR_DAT_00520cb8 + 8) = 0;
    }
    else {
      Pic_Util_00423919(DAT_00538ae0);
      FUN_0070d000(arg_1_00,arg_2_00,(ushort *)arg_5);
      if ((DAT_00536860 & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (DAT_00536860 & 3);
      }
      DAT_00538ad4 = DAT_00536860 + local_414;
      iVar1 = FUN_004232f0(DAT_00536860,DAT_00536864,local_8);
      if (iVar1 == 0) {
        *(undefined4 *)(PTR_DAT_00520cb8 + 8) = 0;
      }
      else {
        local_c = *(byte **)(PTR_DAT_00520cb8 + 0x18);
        DAT_00538adc = 0;
        while (DAT_00538adc < DAT_00536864) {
          Mem_AllocOrFree_0070d484(local_c,DAT_00536860);
          DAT_00538adc = DAT_00538adc + 1;
          local_c = (byte *)((int)local_c +
                            *(int *)(PTR_DAT_00520cb8 + 0x2c) +
                            ((int)(local_8 * DAT_00536860 +
                                  ((int)(local_8 * DAT_00536860) >> 0x1f & 7U)) >> 3));
        }
      }
      Pic_Subsystem_004238ee(DAT_00538ae0);
    }
  }
  return *(undefined4 *)(PTR_DAT_00520cb8 + 8);
}


