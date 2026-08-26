/*
 * Decompiled function: __strnicmp
 * Entry Point: 0040b300
 * Size: 173 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __strnicmp(char *str_1,char *str_2,size_t arg_3)

{
  char cVar1;
  uint8_t flag_2;
  uint16_t uval_3;
  uint32_t arg_1;
  int val_4;
  uint32_t uval_5;
  bool bVar6;
  
  val_4 = 0;
  if (arg_3 != 0) {
    if (DAT_00413078 == 0) {
      do {
        flag_2 = *str_1;
        cVar1 = *str_2;
        uval_3 = CONCAT11(flag_2,cVar1);
        if (flag_2 == 0) break;
        uval_3 = CONCAT11(flag_2,cVar1);
        uval_5 = (uint32_t)uval_3;
        if (cVar1 == '\0') break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        if ((0x40 < flag_2) && (flag_2 < 0x5b)) {
          uval_5 = (uint32_t)CONCAT11(flag_2 + 0x20,cVar1);
        }
        uval_3 = (uint16_t)uval_5;
        flag_2 = (uint8_t)uval_5;
        if ((0x40 < flag_2) && (flag_2 < 0x5b)) {
          uval_3 = (uint16_t)CONCAT31((int3)(uval_5 >> 8),flag_2 + 0x20);
        }
        flag_2 = (uint8_t)(uval_3 >> 8);
        bVar6 = flag_2 < (uint8_t)uval_3;
        if (flag_2 != (uint8_t)uval_3) goto LAB_0040b35b;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      val_4 = 0;
      flag_2 = (uint8_t)(uval_3 >> 8);
      bVar6 = flag_2 < (uint8_t)uval_3;
      if (flag_2 != (uint8_t)uval_3) {
LAB_0040b35b:
        val_4 = -1;
        if (!bVar6) {
          val_4 = 1;
        }
      }
    }
    else {
      uval_5 = 0;
      arg_1 = 0;
      do {
        arg_1 = CONCAT31((int3)(arg_1 >> 8),*str_1);
        uval_5 = CONCAT31((int3)(uval_5 >> 8),*str_2);
        if ((arg_1 == 0) || (uval_5 == 0)) break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        uval_5 = _tolower(uval_5);
        arg_1 = _tolower(arg_1);
        bVar6 = arg_1 < uval_5;
        if (arg_1 != uval_5) goto LAB_0040b39d;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      val_4 = 0;
      bVar6 = arg_1 < uval_5;
      if (arg_1 != uval_5) {
LAB_0040b39d:
        val_4 = -1;
        if (!bVar6) {
          val_4 = 1;
        }
      }
    }
  }
  return val_4;
}


