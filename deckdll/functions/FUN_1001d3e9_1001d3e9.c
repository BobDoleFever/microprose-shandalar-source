/*
 * Decompiled function: FUN_1001d3e9
 * Entry Point: 1001d3e9
 * Size: 2852 bytes
 */
#include "deckdll.h"


void FUN_1001d3e9(HDC hdc,int *arg_2,int arg_3,int32_t arg_4,int32_t arg_5)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  char local_354 [400];
  int local_1c4;
  int32_t local_1c0;
  char local_1bc [100];
  char local_158;
  char local_157;
  uint8_t local_156;
  int32_t local_f4;
  uint32_t local_f0;
  int local_ec;
  char local_e8 [52];
  int local_b4;
  uint32_t local_b0;
  int32_t local_ac;
  int32_t local_a8;
  int local_a4;
  uint32_t local_a0;
  uint8_t *local_9c;
  uint8_t *local_98;
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
  char *local_2c;
  uint8_t *local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_c;
  uint32_t local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_b0 = thunk_FUN_100241fb(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (arg_3 == DAT_1013f35c) {
      uval_1 = thunk_FUN_100241cc(arg_4,arg_5);
      sprintf(&DAT_1013e598,s_Damage___d_10043744,uval_1);
      uval_1 = thunk_FUN_100241a8(arg_4,arg_5);
      local_b4 = thunk_FUN_10024196(uval_1);
      if (local_b4 == 1) {
        strcat(&DAT_1013e598,s__Black__10043750);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_1013e598,s__Blue__1004375c);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_1013e598,s__Red__10043764);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_1013e598,s__Green__1004376c);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_1013e598,s__White__10043778);
      }
    }
    else if (DAT_1013f358 == arg_3) {
      val_2 = thunk_FUN_100241cc(arg_4,arg_5);
      sprintf(&DAT_1013e598,s_Hunting___s_10043784,(&PTR_DAT_10043c70)[val_2]);
    }
    else if (DAT_1013f334 == arg_3) {
      strcpy(&DAT_1013e598,*(char **)(&DAT_101589a4 + local_a0 * 0x14));
    }
    else if (DAT_1013f360 == arg_3) {
      strcpy(&DAT_1013e598,*(char **)(&DAT_101589ac + local_a0 * 0x14));
    }
    else {
      DAT_1013e598 = 0;
    }
    if ((DAT_1013f334 == arg_3) && (val_2 = thunk_FUN_100241de(arg_4,arg_5), 0 < val_2)) {
      strcpy(local_e8,&DAT_1013e598);
      val_2 = thunk_FUN_100241de(arg_4,arg_5);
      thunk_FUN_1002140e(&DAT_1013e598,local_e8,val_2);
    }
    local_ec = thunk_FUN_100241ba(local_ac,local_a8);
    if ((local_ec == 0x361) || (local_ec == 0x360)) {
      strcpy(&DAT_1013e598,*(char **)(&DAT_101589a4 + local_ec * 0x14));
    }
    local_98 = &DAT_1013e598;
    local_9c = &DAT_1013e598;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0;
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
    if (arg_3 == DAT_1013f35c) {
      strcpy(&DAT_1013e210,*(char **)(&DAT_101589a0 + local_a0 * 0x14));
    }
    else if (DAT_1013f358 == arg_3) {
      strcpy(&DAT_1013e210,*(char **)(&DAT_101589a8 + local_a0 * 0x14));
    }
    else if (DAT_1013f334 == arg_3) {
      strcpy(&DAT_1013e210,*(char **)(&DAT_101589a8 + local_a0 * 0x14));
    }
    else if (DAT_1013f360 == arg_3) {
      strcpy(&DAT_1013e210,*(char **)(&DAT_101589b0 + local_a0 * 0x14));
    }
    else {
      DAT_1013e210 = '\0';
    }
    thunk_FUN_10024180(arg_4,arg_5,&DAT_1013e210);
    thunk_FUN_1002418b(arg_4,arg_5,&DAT_1013e210);
    local_1bc[1] = 0;
    local_1bc[0] = -0x12;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_10043790,0,local_1bc);
    local_1bc[0] = -2;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_10043794,0,local_1bc);
    local_1bc[0] = -3;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_10043798,0,local_1bc);
    local_1bc[0] = -5;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_1004379c,0,local_1bc);
    local_1bc[0] = -4;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_100437a0,0,local_1bc);
    local_1bc[0] = -1;
    thunk_FUN_10032562(&DAT_1013e210,&DAT_100437a4,0,local_1bc);
    local_158 = '|';
    local_156 = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      local_1bc[0] = (char)local_a4 + -0xf;
      local_157 = (char)local_a4 + '0';
      thunk_FUN_10032562(&DAT_1013e210,&local_158,0,local_1bc);
    }
    thunk_FUN_100241f0(arg_4,arg_5,&local_1c0,&local_f4);
    sprintf(local_1bc,s___d___d_100437a8,local_1c0,local_f4);
    thunk_FUN_10032562(&DAT_1013e210,s___X___X_100437b0,0,local_1bc);
    sprintf(local_1bc,s__0___d_100437b8,local_f4);
    thunk_FUN_10032562(&DAT_1013e210,s__0___X_100437c0,0,local_1bc);
    sprintf(local_1bc,s___d__0_100437c8,local_1c0);
    thunk_FUN_10032562(&DAT_1013e210,s___X__0_100437d0,0,local_1bc);
    if (local_a0 == 0x132) {
      local_f0 = thunk_FUN_100241cc(arg_4,arg_5);
      if (local_f0 == 1) {
        strcpy(local_1bc,s_swampwalk_100437d8);
      }
      else if (local_f0 == 0x10) {
        strcpy(local_1bc,s_plainswalk_100437e4);
      }
      else if (local_f0 == 4) {
        strcpy(local_1bc,s_forestwalk_100437f0);
      }
      else if (local_f0 == 8) {
        strcpy(local_1bc,s_mountainwalk_100437fc);
      }
      else if (local_f0 == 2) {
        strcpy(local_1bc,s_islandwalk_1004380c);
      }
      else {
        strcpy(local_1bc,&DAT_10043818);
      }
      thunk_FUN_10032562(&DAT_1013e210,&DAT_1004381c,0,local_1bc);
    }
    if (local_a0 == 0x21b) {
      local_f0 = thunk_FUN_100241cc(arg_4,arg_5);
      local_1c4 = 0;
      strcpy(local_1bc,&DAT_10043820);
      if ((local_f0 & 0x20) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_10043824);
        }
        strcat(local_1bc,s_flying_1004382c);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x100) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_10043834);
        }
        strcat(local_1bc,s_first_strike_1004383c);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x40) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_1004384c);
        }
        strcat(local_1bc,s_banding_10043854);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x80) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_1004385c);
        }
        strcat(local_1bc,s_trample_10043864);
        local_1c4 = 1;
      }
      thunk_FUN_10032562(&DAT_1013e210,&DAT_1004386c,0,local_1bc);
      thunk_FUN_100241f0(arg_4,arg_5,&local_1c0,&local_f4);
      sprintf(local_1bc,s___d___d_10043870,local_1c0,local_f4);
      thunk_FUN_10032562(&DAT_1013e210,s___X___X_10043878,0,local_1bc);
    }
    if ((DAT_1013f334 == arg_3) && (val_2 = thunk_FUN_100241de(arg_4,arg_5), 0 < val_2)) {
      strcpy(local_354,&DAT_1013e210);
      val_2 = thunk_FUN_100241de(arg_4,arg_5);
      thunk_FUN_1002140e(&DAT_1013e210,local_354,val_2);
    }
    if (arg_3 == DAT_1013f35c) {
      uval_3 = thunk_FUN_1002434e(arg_4,arg_5);
      if ((DAT_1013e210 != '\0') && (DAT_1013e210 != '\n')) {
        strcat(&DAT_1013e210,&DAT_10043880);
      }
      if ((uval_3 & 0x100000) != 0) {
        strcat(&DAT_1013e210,s_First_strike_10043884);
      }
      if ((uval_3 & 0x80000) != 0) {
        strcat(&DAT_1013e210,s_Trample_10043894);
      }
    }
    local_2c = &DAT_1013e210;
    local_28 = &DAT_1004389c;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    thunk_FUN_1001ae07(hdc,arg_2,&local_a0,local_8,2,DAT_1013f380);
  }
  return;
}


