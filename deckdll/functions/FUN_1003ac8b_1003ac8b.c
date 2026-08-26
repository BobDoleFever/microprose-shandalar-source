/*
 * Decompiled function: FUN_1003ac8b
 * Entry Point: 1003ac8b
 * Size: 792 bytes
 */
#include "deckdll.h"


int32_t FUN_1003ac8b(int arg_1,int32_t arg_2,int32_t arg_3,char *str_4,uint8_t *arg_5)

{
  char *_Str2;
  int val_1;
  int32_t arg_1_00;
  int32_t arg_2_00;
  int local_414;
  int local_410;
  uint8_t local_40c [1024];
  uint8_t *local_c;
  int local_8;
  
  local_8 = 8;
  _Str2 = strchr(str_4,0x2e);
  val_1 = _stricmp(&DAT_1004bafc,_Str2);
  if (val_1 == 0) {
    DAT_1013f3cc = (int)fopen(str_4,&DAT_1004bb04);
    if ((FILE *)DAT_1013f3cc == (FILE *)0x0) {
      return 0;
    }
    DAT_101407b0 = str_4;
    if (arg_5 == (uint8_t *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (uint8_t *)0x0) {
      thunk_FUN_1002389f((void *)0x0);
      if (arg_1 < 0) {
        DAT_1004a814 = 0;
      }
      if ((int)DAT_1004a810 % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)DAT_1004a810 % 3;
      }
      DAT_1013ec6c = DAT_1004a810 + local_410;
      thunk_FUN_1003aa60(DAT_1013ec6c,DAT_1004a814,local_8);
      local_c = *(uint8_t **)(PTR_DAT_1004bae8 + 0x18);
      for (DAT_1013ec74 = 0; DAT_1013ec74 < DAT_1004a814; DAT_1013ec74 = DAT_1013ec74 + 1) {
        thunk_FUN_10023a88(local_c);
        local_c = local_c + ((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3) * DAT_1013ec6c;
      }
      fclose((FILE *)DAT_1013f3cc);
    }
    else {
      thunk_FUN_1002389f(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(int16_t *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_1013ec78 = FUN_1003b02a(str_4,0x8000);
    if (DAT_1013ec78 == -1) {
      thunk_FUN_10016850(0,0x1004bb20,0xe4,s_Could_not_open_file__s_1004bb08);
      *(int32_t *)(PTR_DAT_1004bae8 + 8) = 0;
    }
    else {
      FUN_1003b089(DAT_1013ec78);
      thunk_FUN_10218000(arg_1_00,arg_2_00,(uint16_t *)arg_5);
      if ((DAT_1004a810 & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (DAT_1004a810 & 3);
      }
      DAT_1013ec6c = DAT_1004a810 + local_414;
      val_1 = thunk_FUN_1003aa60(DAT_1004a810,DAT_1004a814,local_8);
      if (val_1 == 0) {
        *(int32_t *)(PTR_DAT_1004bae8 + 8) = 0;
      }
      else {
        local_c = *(uint8_t **)(PTR_DAT_1004bae8 + 0x18);
        DAT_1013ec74 = 0;
        while (DAT_1013ec74 < DAT_1004a814) {
          thunk_FUN_10218484(local_c,DAT_1004a810);
          DAT_1013ec74 = DAT_1013ec74 + 1;
          local_c = (uint8_t *)((int)local_c +
                            *(int *)(PTR_DAT_1004bae8 + 0x2c) +
                            ((int)(local_8 * DAT_1004a810 +
                                  ((int)(local_8 * DAT_1004a810) >> 0x1f & 7U)) >> 3));
        }
      }
      FUN_1003b05e(DAT_1013ec78);
    }
  }
  return *(int32_t *)(PTR_DAT_1004bae8 + 8);
}


