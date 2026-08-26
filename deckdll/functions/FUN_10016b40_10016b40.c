/*
 * Decompiled function: FUN_10016b40
 * Entry Point: 10016b40
 * Size: 1512 bytes
 */
#include "deckdll.h"


int FUN_10016b40(int arg_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int val_7;
  int val_8;
  int iVar9;
  char local_58 [52];
  uint32_t local_24;
  int local_20;
  int local_1c;
  char *local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  uint32_t local_8;
  
  val_7 = strcmp((char *)(&DAT_10176ab4)[arg_1 * 0x26],s_Blank_10043164);
  if (val_7 == 0) {
    local_c = 0;
  }
  else if ((((DAT_1017646c & 1) == 0) && ((DAT_1017646c & 0x20) == 0)) ||
          (val_7 = thunk_FUN_10017128(arg_1), val_7 != 0)) {
    val_7 = *(int *)(&DAT_10176ac0 + arg_1 * 0x98);
    uval_1 = *(uint32_t *)(&DAT_10176abc + arg_1 * 0x98);
    local_10 = *(int *)(&DAT_10176ac4 + arg_1 * 0x98);
    val_8 = *(int *)(&DAT_10176ac8 + arg_1 * 0x98);
    local_20 = *(int *)(&DAT_10176ad0 + arg_1 * 0x98);
    local_18 = &DAT_10176ad8 + arg_1 * 0x98;
    uval_2 = *(uint32_t *)(&DAT_10176b2c + arg_1 * 0x98);
    uval_3 = *(uint32_t *)(&DAT_10176b30 + arg_1 * 0x98);
    local_1c = *(int *)(&DAT_10176af0 + arg_1 * 0x98);
    iVar9 = *(int *)(&DAT_10176ad4 + arg_1 * 0x98);
    if (val_7 == 0) {
      bVar4 = true;
    }
    else if (((((val_7 == 8) && ((DAT_101cf7d0 & 2) != 0)) ||
              ((val_7 == 5 && ((DAT_101cf7d0 & 4) != 0)))) ||
             ((val_7 == 7 && ((DAT_101cf7d0 & 8) != 0)))) ||
            (((val_7 == 1 && ((DAT_101cf7d0 & 0x10) != 0)) ||
             ((((val_7 == 2 && ((DAT_101cf7d0 & 0x20) != 0)) || (val_7 == 6)) || (val_7 == 3)))))) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if ((((((uval_1 & 0x800) == 0) || ((DAT_101cf7d2 & 0x800) == 0)) &&
         (((uval_1 & 4) == 0 || ((DAT_101cf7d2 & 0x40) == 0)))) &&
        ((((uval_1 & 2) == 0 || ((DAT_101cf7d2 & 8) == 0)) &&
         (((uval_1 & 0x20) == 0 || ((DAT_101cf7d2 & 0x10) == 0)))))) &&
       ((((((uval_1 & 0x80) == 0 || ((DAT_101cf7d2 & 2) == 0)) &&
          (((uval_1 & 0x200) == 0 || ((DAT_101cf7d2 & 0x200) == 0)))) &&
         ((((uval_1 & 0x10) == 0 || ((DAT_101cf7d2 & 0x20) == 0)) &&
          (((uval_1 & 0x400) == 0 || ((DAT_101cf7d2 & 0x400) == 0)))))) &&
        (((((uval_1 & 0x1000) == 0 || ((DAT_101cf7d2 & 0x100) == 0)) &&
          (((uval_1 & 8) == 0 || ((DAT_101cf7d2 & 4) == 0)))) &&
         (((uval_1 & 0x100) == 0 || ((DAT_101cf7d2 & 0x80) == 0)))))))) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    val_7 = thunk_FUN_10017444(local_10,local_20);
    if ((((((val_7 == 0) && (val_7 = thunk_FUN_100174ee(local_10,val_8), val_7 == 0)) &&
          (val_7 = thunk_FUN_10017566(local_10,val_8), val_7 == 0)) &&
         ((val_7 = thunk_FUN_10017624(local_10,val_8), val_7 == 0 &&
          ((local_10 != 3 || ((DAT_101cf7d4._2_1_ & 8) == 0)))))) &&
        ((local_10 != 4 || ((DAT_101cf7d4._2_1_ & 0x10) == 0)))) &&
       ((local_10 != 6 || ((DAT_101cf7d4._2_1_ & 0x20) == 0)))) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    val_7 = thunk_FUN_1001772e(arg_1,local_18);
    val_8 = thunk_FUN_1001787e(uval_2 & 0xfff);
    local_8 = (uint32_t)(val_8 != 0);
    val_8 = thunk_FUN_10017926(uval_3 & 0xfff);
    local_14 = (uint32_t)(val_8 != 0);
    val_8 = thunk_FUN_100179ce(arg_1,iVar9);
    local_24 = (uint32_t)(val_8 != 0);
    val_8 = thunk_FUN_10017aa2(arg_1,4,arg_1 * 0x98 + 0x10176b38);
    iVar9 = thunk_FUN_100182b4(arg_1,local_1c);
    if (((((bVar4) && (bVar5)) && (bVar6)) &&
        (((val_7 != 0 && (local_8 != 0)) && ((local_14 != 0 && ((local_24 != 0 && (val_8 != 0)))))))
        ) && (iVar9 != 0)) {
      local_c = 1;
    }
    else {
      local_c = 0;
    }
    if ((DAT_101cfb98 != 0) && (local_c != 0)) {
      sprintf(local_58,&DAT_1004316c,arg_1);
      fprintf(DAT_10175ed8,local_58);
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}


