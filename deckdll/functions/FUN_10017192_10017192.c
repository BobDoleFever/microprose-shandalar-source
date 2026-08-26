/*
 * Decompiled function: FUN_10017192
 * Entry Point: 10017192
 * Size: 690 bytes
 */
#include "deckdll.h"


int32_t FUN_10017192(int32_t arg_1,int arg_2,int arg_3)

{
  int32_t uval_1;
  char local_58 [80];
  int32_t local_8;
  
  local_8 = 0;
  if (arg_3 == 0) {
    sprintf(local_58,s_Card_Number__d_does_not_have_a_v_10043170,arg_1);
    MessageBoxA(DAT_10176868,local_58,s_Card_Error_100431a0,0x10);
    uval_1 = 0;
  }
  else if ((DAT_101cf7d0 & 0x40) == 0) {
    uval_1 = 0;
  }
  else if (((DAT_101cf7d0 & 0x100) == 0) || (arg_2 != 4)) {
    if (((DAT_101cf7d0 & 0x200) == 0) || (arg_2 != 4)) {
      if ((((DAT_101cf7d0 & 0x400) == 0) || (arg_2 != 4)) ||
         (((((DAT_101cf7d0 & 8) == 0 || (*(char *)(arg_3 + 7) < '\x01')) &&
           (((((DAT_101cf7d0 & 4) == 0 || (*(char *)(arg_3 + 5) < '\x01')) &&
             (((DAT_101cf7d0 & 0x20) == 0 || (*(char *)(arg_3 + 2) < '\x01')))) &&
            (((DAT_101cf7d0 & 2) == 0 || (*(char *)(arg_3 + 8) < '\x01')))))) &&
          (((DAT_101cf7d0 & 0x10) == 0 || (*(char *)(arg_3 + 1) < '\x01')))))) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
    else {
      if ((DAT_101cf7d0 & 8) == 0) {
        if ('\0' < *(char *)(arg_3 + 7)) {
          return 0;
        }
      }
      else if (*(char *)(arg_3 + 7) == '\0') {
        return 0;
      }
      if ((DAT_101cf7d0 & 4) == 0) {
        if ('\0' < *(char *)(arg_3 + 5)) {
          return 0;
        }
      }
      else if (*(char *)(arg_3 + 5) == '\0') {
        return 0;
      }
      if ((DAT_101cf7d0 & 0x20) == 0) {
        if ('\0' < *(char *)(arg_3 + 2)) {
          return 0;
        }
      }
      else if (*(char *)(arg_3 + 2) == '\0') {
        return 0;
      }
      if ((DAT_101cf7d0 & 2) == 0) {
        if ('\0' < *(char *)(arg_3 + 8)) {
          return 0;
        }
      }
      else if (*(char *)(arg_3 + 8) == '\0') {
        return 0;
      }
      if ((DAT_101cf7d0 & 0x10) == 0) {
        if ('\0' < *(char *)(arg_3 + 1)) {
          return 0;
        }
      }
      else if (*(char *)(arg_3 + 1) == '\0') {
        return 0;
      }
      uval_1 = 1;
    }
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}


