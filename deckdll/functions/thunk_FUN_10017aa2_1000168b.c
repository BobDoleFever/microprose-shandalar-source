/*
 * Decompiled function: thunk_FUN_10017aa2
 * Entry Point: 1000168b
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017aa2(int32_t arg_1,int arg_2,int arg_3)

{
  int32_t uval_1;
  bool flag_2;
  bool flag_3;
  char acStack_60 [80];
  int32_t uStack_10;
  int32_t uStack_c;
  int iStack_8;
  
  uStack_10 = 0;
  uStack_c = 0;
  if (arg_3 == 0) {
    sprintf(acStack_60,s_Card_Number__d_does_not_have_a_v_10043228,arg_1);
    MessageBoxA(DAT_10176868,acStack_60,s_Card_Error_10043260,0x10);
    uval_1 = 0;
  }
  else if ((DAT_101cf800 & 1) == 0) {
    uval_1 = 1;
  }
  else {
    flag_2 = (DAT_101cf800 & 2) != 0;
    flag_3 = (DAT_101cf800 & 4) != 0;
    if ((flag_2) || (flag_3)) {
      for (iStack_8 = 0; iStack_8 < arg_2; iStack_8 = iStack_8 + 1) {
        if ((DAT_101cf800 & 8) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x04') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x18') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x10) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x03') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x17') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x20) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x14') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == ')') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x40) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x11') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '&') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x80) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x01') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x16') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x100) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\f') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\r') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x0e') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1f') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\"') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '#') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == ' ') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '!') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1e') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x200) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x02') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x05') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\a') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\b') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\t') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\n') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x13') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x19') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1b') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1c') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1d') && (flag_3)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '(') && (flag_3)) {
            return 1;
          }
        }
        if ((((DAT_101cf800 & 0x400) != 0) && (*(char *)(iStack_8 + arg_3) == '\v')) && (flag_2)) {
          return 1;
        }
        if ((DAT_101cf800 & 0x800) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x10') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '%') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x1000) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x15') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '*') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x2000) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x12') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\'') && (flag_3)) {
            return 1;
          }
        }
        if ((DAT_101cf800 & 0x4000) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x06') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '\x1a') && (flag_3)) {
            return 1;
          }
        }
        if (((int)(short)DAT_101cf800 & 0x8000U) != 0) {
          if ((*(char *)(iStack_8 + arg_3) == '\x0f') && (flag_2)) {
            return 1;
          }
          if ((*(char *)(iStack_8 + arg_3) == '$') && (flag_3)) {
            return 1;
          }
        }
      }
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}


