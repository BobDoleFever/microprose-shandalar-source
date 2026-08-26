/*
 * Decompiled function: FUN_10218000
 * Entry Point: 10218000
 * Size: 396 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10218000(int32_t arg_1,int32_t arg_2,uint16_t *arg_3)

{
  uint16_t uval_1;
  uint32_t uval_2;
  int32_t extraout_ECX;
  int32_t extraout_EDX;
  int32_t unaff_EBX;
  uint16_t *u_ptr_3;
  uint16_t *puVar4;
  
  while( true ) {
    u_ptr_3 = DAT_1013eefc;
    if (PTR_DAT_1004baec <= DAT_1013eefc) {
      (*DAT_1013f170)(arg_2,arg_1,unaff_EBX);
      u_ptr_3 = DAT_1013eefc;
    }
    DAT_1013eefc = u_ptr_3 + 1;
    uval_1 = *u_ptr_3;
    if ((char)uval_1 == 'X') break;
    u_ptr_3 = &DAT_10046810;
    if ((uval_1 == 0x304d) || (uval_1 == 0x314d)) {
      if ((int)arg_3 < 1) {
        u_ptr_3 = (uint16_t *)&DAT_10046812;
      }
      else if (arg_3 != (uint16_t *)0x1) {
        u_ptr_3 = arg_3;
      }
    }
    *u_ptr_3 = uval_1;
    puVar4 = u_ptr_3;
    if (PTR_DAT_1004baec <= DAT_1013eefc) {
      (*DAT_1013f170)(arg_2,arg_1);
    }
    uval_1 = *DAT_1013eefc;
    DAT_1013eefc = DAT_1013eefc + 1;
    u_ptr_3[1] = uval_1;
    u_ptr_3 = u_ptr_3 + 2;
    for (uval_2 = (uint32_t)(uval_1 >> 1); uval_2 != 0; uval_2 = uval_2 - 1) {
      if (PTR_DAT_1004baec <= DAT_1013eefc) {
        (*DAT_1013f170)();
      }
      uval_1 = *DAT_1013eefc;
      DAT_1013eefc = DAT_1013eefc + 1;
      *u_ptr_3 = uval_1;
      u_ptr_3 = u_ptr_3 + 1;
    }
    arg_1 = 0;
    if (puVar4 == &DAT_10046810) {
      thunk_FUN_1003b0ec(&DAT_10046810);
      arg_1 = extraout_ECX;
      arg_2 = extraout_EDX;
    }
  }
  DAT_1004a835 = (uint8_t)(uval_1 >> 8) & 1;
  if (PTR_DAT_1004baec <= DAT_1013eefc) {
    (*DAT_1013f170)(arg_2,arg_1,unaff_EBX);
  }
  u_ptr_3 = DAT_1013eefc + 1;
  _DAT_1004a818 = (uint32_t)*DAT_1013eefc;
  if (PTR_DAT_1004baec <= u_ptr_3) {
    DAT_1013eefc = u_ptr_3;
    (*DAT_1013f170)(arg_2,arg_1,unaff_EBX);
    u_ptr_3 = DAT_1013eefc;
  }
  DAT_1013eefc = u_ptr_3 + 1;
  DAT_1004a810 = (uint32_t)*u_ptr_3;
  if (PTR_DAT_1004baec <= DAT_1013eefc) {
    (*DAT_1013f170)(arg_2,arg_1,unaff_EBX);
  }
  DAT_1004a814 = (uint32_t)*DAT_1013eefc;
  DAT_1013eefc = DAT_1013eefc + 1;
  FUN_10218245(arg_1,arg_2);
  return;
}


