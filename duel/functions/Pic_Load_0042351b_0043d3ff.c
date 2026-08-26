/*
 * Decompiled function: Pic_Load_0042351b
 * Entry Point: 0043d3ff
 * Size: 788 bytes
 */
#include "duel.h"


undefined4
Pic_Load_0042351b(int arg_1,undefined4 arg_2,undefined4 arg_3,char *str_4,undefined1 *arg_5)

{
  char *str_2;
  int iVar1;
  undefined4 arg_1_00;
  undefined4 arg_2_00;
  int local_414;
  int local_410;
  undefined1 local_40c [1024];
  byte *local_c;
  int local_8;
  
  local_8 = 8;
  str_2 = _strchr(str_4,0x2e);
  iVar1 = __strcmpi(&DAT_004f7928,str_2);
  if (iVar1 == 0) {
    DAT_00694430 = _fopen(str_4,&DAT_004f7930);
    if (DAT_00694430 == (FILE *)0x0) {
      return 0;
    }
    DAT_00694438 = str_4;
    if (arg_5 == (undefined1 *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (undefined1 *)0x0) {
      FUN_0044c47a((void *)0x0);
      if (arg_1 < 0) {
        DAT_004ff158 = 0;
      }
      if ((int)DAT_004ff154 % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)DAT_004ff154 % 3;
      }
      DAT_00516914 = DAT_004ff154 + local_410;
      FUN_0043d1d0(DAT_00516914,DAT_004ff158,local_8);
      local_c = *(byte **)(PTR_DAT_004f7914 + 0x18);
      for (DAT_0051691c = 0; DAT_0051691c < DAT_004ff158; DAT_0051691c = DAT_0051691c + 1) {
        FUN_0044c660(local_c);
        local_c = local_c + ((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3) * DAT_00516914;
      }
      _fclose(DAT_00694430);
    }
    else {
      FUN_0044c47a(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(undefined2 *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_00516920 = FUN_0043d799(str_4,0x8000);
    if (DAT_00516920 == -1) {
      Assert_Handler_00499950(0,0x4f794c,0xe4,s_Could_not_open_file__s_004f7934);
      *(undefined4 *)(PTR_DAT_004f7914 + 8) = 0;
    }
    else {
      Mem_AllocOrFree_0043d7f6(DAT_00516920);
      FUN_006c5000(arg_1_00,arg_2_00,(ushort *)arg_5);
      if ((DAT_004ff154 & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (DAT_004ff154 & 3);
      }
      DAT_00516914 = DAT_004ff154 + local_414;
      iVar1 = FUN_0043d1d0(DAT_004ff154,DAT_004ff158,local_8);
      if (iVar1 == 0) {
        *(undefined4 *)(PTR_DAT_004f7914 + 8) = 0;
      }
      else {
        local_c = *(byte **)(PTR_DAT_004f7914 + 0x18);
        DAT_0051691c = 0;
        while (DAT_0051691c < DAT_004ff158) {
          Mem_AllocOrFree_006c5484(local_c,DAT_004ff154);
          DAT_0051691c = DAT_0051691c + 1;
          local_c = (byte *)((int)local_c +
                            *(int *)(PTR_DAT_004f7914 + 0x2c) +
                            ((int)(local_8 * DAT_004ff154 +
                                  ((int)(local_8 * DAT_004ff154) >> 0x1f & 7U)) >> 3));
        }
      }
      FUN_0043d7cc(DAT_00516920);
    }
  }
  return *(undefined4 *)(PTR_DAT_004f7914 + 8);
}


