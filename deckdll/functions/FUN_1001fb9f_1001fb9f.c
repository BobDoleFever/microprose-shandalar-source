/*
 * Decompiled function: FUN_1001fb9f
 * Entry Point: 1001fb9f
 * Size: 1541 bytes
 */
#include "deckdll.h"


void FUN_1001fb9f(HDC hdc,RECT *arg_2,int arg_3,int arg_4,int arg_5)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t local_f4;
  char local_e8 [52];
  int local_b4;
  uint32_t local_b0;
  int32_t local_ac;
  int32_t local_a8;
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
    local_b0 = thunk_FUN_100241fb(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (DAT_1013f35c == arg_3) {
      uval_1 = thunk_FUN_100241cc(arg_4,arg_5);
      sprintf(&DAT_1013e000,s_Damage___d_100438f0,uval_1);
      uval_1 = thunk_FUN_100241a8(arg_4,arg_5);
      local_b4 = thunk_FUN_10024196(uval_1);
      if (local_b4 == 1) {
        strcat(&DAT_1013e000,s__Black__100438fc);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_1013e000,s__Blue__10043908);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_1013e000,s__Red__10043910);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_1013e000,s__Green__10043918);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_1013e000,s__White__10043924);
      }
    }
    else if (DAT_1013f358 == arg_3) {
      val_2 = thunk_FUN_100241cc(arg_4,arg_5);
      sprintf(&DAT_1013e000,s_Hunting___s_10043930,(&PTR_DAT_10043c70)[val_2]);
    }
    else if (DAT_1013f334 == arg_3) {
      strcpy(&DAT_1013e000,*(char **)(&DAT_101589a4 + local_a0 * 0x14));
    }
    else if (DAT_1013f360 == arg_3) {
      strcpy(&DAT_1013e000,*(char **)(&DAT_101589ac + local_a0 * 0x14));
    }
    else if (DAT_1013f3c4 == arg_3) {
      strcpy(&DAT_1013e000,s_Activation_1004393c);
    }
    else {
      DAT_1013e000 = 0;
    }
    if ((DAT_1013f334 == arg_3) && (val_2 = thunk_FUN_100241de(arg_4,arg_5), 0 < val_2)) {
      strcpy(local_e8,&DAT_1013e000);
      val_2 = thunk_FUN_100241de(arg_4,arg_5);
      thunk_FUN_1002140e(&DAT_1013e000,local_e8,val_2);
    }
    val_2 = thunk_FUN_100241ba(local_ac,local_a8);
    if ((val_2 == 0x361) || (val_2 == 0x360)) {
      strcpy(&DAT_1013e000,*(char **)(&DAT_101589a4 + val_2 * 0x14));
    }
    local_98 = &DAT_1013e000;
    local_9c = &DAT_1013e000;
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
    if (DAT_1013f35c == arg_3) {
      strcpy(&DAT_1013e050,*(char **)(&DAT_101589a0 + local_a0 * 0x14));
    }
    else if (DAT_1013f358 == arg_3) {
      strcpy(&DAT_1013e050,*(char **)(&DAT_101589a8 + local_a0 * 0x14));
    }
    else if (DAT_1013f334 == arg_3) {
      strcpy(&DAT_1013e050,*(char **)(&DAT_101589a8 + local_a0 * 0x14));
    }
    else if (DAT_1013f360 == arg_3) {
      strcpy(&DAT_1013e050,*(char **)(&DAT_101589b0 + local_a0 * 0x14));
    }
    else {
      DAT_1013e050 = 0;
    }
    local_2c = &DAT_1013e050;
    local_28 = &DAT_10043948;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    thunk_FUN_1001df0d(hdc,arg_2,&local_a0,local_8,1);
    thunk_FUN_10020a41(hdc,&arg_2->left,arg_4,arg_5);
    val_2 = thunk_FUN_1002421f(arg_4,arg_5);
    uval_3 = (uint32_t)(val_2 == arg_4);
    val_2 = thunk_FUN_1002420d(arg_4,arg_5);
    thunk_FUN_1001f83a(hdc,&arg_2->left,local_98,val_2,uval_3);
    if (DAT_1013f35c == arg_3) {
      uval_3 = thunk_FUN_1002434e(arg_4,arg_5);
      local_f4 = 0;
      if ((uval_3 & 0x100000) != 0) {
        local_f4 = 0x100;
      }
      if ((uval_3 & 0x80000) != 0) {
        local_f4 = local_f4 | 0x80;
      }
      if ((DAT_1013f37c != 0) && (local_f4 != 0)) {
        thunk_FUN_1001f340(hdc,&arg_2->left,local_f4);
      }
    }
  }
  return;
}


