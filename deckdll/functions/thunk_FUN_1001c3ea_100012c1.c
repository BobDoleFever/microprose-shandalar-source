/*
 * Decompiled function: thunk_FUN_1001c3ea
 * Entry Point: 100012c1
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1001c3ea(int *arg1,char *str_2)

{
  int iStack_58;
  int iStack_54;
  int iStack_50;
  char acStack_4c [52];
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((arg1 == (int *)0x0) || (str_2 == (char *)0x0)) {
    iStack_50 = 0;
  }
  else {
    iStack_10 = arg1[5];
    iStack_8 = arg1[3];
    iStack_14 = arg1[4];
    iStack_58 = arg1[1];
    iStack_54 = arg1[2];
    iStack_18 = *arg1;
    iStack_50 = 0;
    if (iStack_18 != 0) {
      if (iStack_18 == -1) {
        acStack_4c[0] = -0x10;
        iStack_50 = 1;
      }
      else if (iStack_18 == 0x48) {
        acStack_4c[0] = -0x10;
        iStack_50 = 1;
      }
      else if ((iStack_18 < 1) || (9 < iStack_18)) {
        if (iStack_18 == 10) {
          acStack_4c[0] = -0x11;
          iStack_50 = 1;
        }
      }
      else {
        acStack_4c[0] = (char)iStack_18 + -0xf;
        iStack_50 = 1;
      }
    }
    iStack_c = 0;
    while (iStack_c == 0) {
      if (iStack_10 == 0) {
        if (iStack_8 == 0) {
          if (iStack_14 == 0) {
            if (iStack_58 == 0) {
              if (iStack_54 == 0) {
                acStack_4c[iStack_50] = '\0';
                iStack_c = 1;
              }
              else {
                acStack_4c[iStack_50] = -3;
                iStack_50 = iStack_50 + 1;
                iStack_54 = iStack_54 + -1;
              }
            }
            else {
              acStack_4c[iStack_50] = -2;
              iStack_50 = iStack_50 + 1;
              iStack_58 = iStack_58 + -1;
            }
          }
          else {
            acStack_4c[iStack_50] = -4;
            iStack_50 = iStack_50 + 1;
            iStack_14 = iStack_14 + -1;
          }
        }
        else {
          acStack_4c[iStack_50] = -1;
          iStack_50 = iStack_50 + 1;
          iStack_8 = iStack_8 + -1;
        }
      }
      else {
        acStack_4c[iStack_50] = -5;
        iStack_50 = iStack_50 + 1;
        iStack_10 = iStack_10 + -1;
      }
    }
    if ((((iStack_18 == 0) && (iStack_50 == 0)) && (iStack_10 == 0)) &&
       (((iStack_8 == 0 && (iStack_14 == 0)) && ((iStack_58 == 0 && (iStack_54 == 0)))))) {
      acStack_4c[0] = -0xf;
      acStack_4c[1] = 0;
    }
    if (str_2 != (char *)0x0) {
      strcpy(str_2,acStack_4c);
    }
  }
  return iStack_50;
}


