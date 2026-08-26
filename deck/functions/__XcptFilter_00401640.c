/*
 * Decompiled function: __XcptFilter
 * Entry Point: 00401640
 * Size: 500 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 1998 Debug */

int __cdecl __XcptFilter(uint32_t card_id,_EXCEPTION_POINTERS *out_filter)

{
  code *char_ptr_1;
  int32_t uval_2;
  int32_t uval_3;
  int *piVar4;
  int val_5;
  int local_14;
  
  piVar4 = xcptlookup(card_id);
  uval_3 = DAT_00412b58;
  if ((piVar4 == (int *)0x0) || (piVar4[2] == 0)) {
    val_5 = UnhandledExceptionFilter(out_filter);
  }
  else if (piVar4[2] == 5) {
    piVar4[2] = 0;
    val_5 = 1;
  }
  else if (piVar4[2] == 1) {
    val_5 = -1;
    DAT_00412b58 = (_EXCEPTION_POINTERS *)uval_3;
  }
  else {
    char_ptr_1 = (code *)piVar4[2];
    DAT_00412b58 = out_filter;
    if (piVar4[1] == 8) {
      for (local_14 = DAT_00412b48; uval_2 = DAT_00412b54, local_14 < DAT_00412b4c + DAT_00412b48;
          local_14 = local_14 + 1) {
        *(int32_t *)(local_14 * 0xc + 0x412ad8) = 0;
      }
      if (*piVar4 == -0x3fffff72) {
        DAT_00412b54 = 0x83;
      }
      else if (*piVar4 == -0x3fffff70) {
        DAT_00412b54 = 0x81;
      }
      else if (*piVar4 == -0x3fffff6f) {
        DAT_00412b54 = 0x84;
      }
      else if (*piVar4 == -0x3fffff6d) {
        DAT_00412b54 = 0x85;
      }
      else if (*piVar4 == -0x3fffff73) {
        DAT_00412b54 = 0x82;
      }
      else if (*piVar4 == -0x3fffff71) {
        DAT_00412b54 = 0x86;
      }
      else if (*piVar4 == -0x3fffff6e) {
        DAT_00412b54 = 0x8a;
      }
      (*char_ptr_1)(8,DAT_00412b54);
      DAT_00412b54 = uval_2;
    }
    else {
      piVar4[2] = 0;
      (*char_ptr_1)(piVar4[1]);
    }
    val_5 = -1;
    DAT_00412b58 = (_EXCEPTION_POINTERS *)uval_3;
  }
  return val_5;
}


