/*
 * Decompiled function: FUN_100201a4
 * Entry Point: 100201a4
 * Size: 677 bytes
 */
#include "deckdll.h"


void FUN_100201a4(HDC hdc,RECT *arg_2,int arg_3,int arg_4,int32_t arg_5,int arg_6,int arg_7)

{
  int val_1;
  uint32_t arg_5_00;
  uint8_t local_b0 [8];
  uint32_t local_a8;
  int local_a4;
  uint32_t local_a0;
  uint8_t *local_9c;
  char *local_98;
  int32_t local_94;
  int32_t local_90;
  int32_t local_8c;
  int32_t local_88;
  int32_t local_84;
  int32_t local_80;
  int32_t local_7c;
  uint8_t auStack_78 [10];
  uint8_t auStack_6e [10];
  int32_t local_64;
  int32_t local_60;
  int32_t local_5c;
  int32_t local_58;
  int32_t local_44;
  int32_t auStack_40 [4];
  int32_t local_30;
  uint8_t *local_2c;
  uint8_t *local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_c;
  uint32_t local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) {
    if ((DAT_1013f3c4 == arg_3) && (val_1 = thunk_FUN_10024372(arg_4,arg_5), val_1 == DAT_1013f364))
    {
      thunk_FUN_1001ad0b(hdc,arg_2);
      thunk_FUN_1001f83a(hdc,&arg_2->left,s_Activation_1004394c,0,1);
    }
    else {
      local_a8 = thunk_FUN_100241fb(local_b0,arg_4,arg_5);
      local_8 = local_a8 >> 0x10;
      local_a0 = local_a8 & 0xffff;
      if (DAT_1013f3c4 == arg_3) {
        strcpy(&DAT_1013e620,s_Activation_10043958);
      }
      else {
        DAT_1013e620 = 0;
      }
      local_98 = &DAT_1013e620;
      local_9c = &DAT_1013e620;
      local_94 = 0xffffffff;
      local_90 = 0xffffffff;
      local_8c = 0xffffffff;
      local_88 = 0xffffffff;
      local_84 = 0xffffffff;
      local_80 = 0xffffffff;
      local_7c = 0;
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_78[local_a4] = 0;
      }
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_6e[local_a4] = 0;
      }
      local_64 = 0xffffffff;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0xffffffff;
      for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
        auStack_40[local_a4] = 0;
      }
      local_30 = 0xffffffff;
      DAT_1013e3c0 = 0;
      local_2c = &DAT_1013e3c0;
      local_28 = &DAT_10043964;
      local_24 = 0;
      local_20 = 0;
      local_44 = 0;
      local_c = 0;
      thunk_FUN_1001df0d(hdc,arg_2,&local_a0,local_8,1);
      thunk_FUN_10020a41(hdc,&arg_2->left,arg_6,arg_7);
      val_1 = thunk_FUN_1002421f(arg_4,arg_5);
      arg_5_00 = (uint32_t)(val_1 == arg_4);
      val_1 = thunk_FUN_1002420d(arg_4,arg_5);
      thunk_FUN_1001f83a(hdc,&arg_2->left,local_98,val_1,arg_5_00);
    }
  }
  return;
}


