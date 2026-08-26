/*
 * Decompiled function: __XcptFilter
 * Entry Point: 004e7740
 * Size: 500 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 1998 Debug */

int __cdecl __XcptFilter(ulong card_id,_EXCEPTION_POINTERS *out_filter)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int local_14;
  
  piVar4 = (int *)xcptlookup(card_id);
  uVar3 = DAT_0050a670;
  if ((piVar4 == (int *)0x0) || (piVar4[2] == 0)) {
    iVar5 = UnhandledExceptionFilter(out_filter);
  }
  else if (piVar4[2] == 5) {
    piVar4[2] = 0;
    iVar5 = 1;
  }
  else if (piVar4[2] == 1) {
    iVar5 = -1;
    DAT_0050a670 = (_EXCEPTION_POINTERS *)uVar3;
  }
  else {
    pcVar1 = (code *)piVar4[2];
    DAT_0050a670 = out_filter;
    if (piVar4[1] == 8) {
      for (local_14 = DAT_0050a660; uVar2 = DAT_0050a66c, local_14 < DAT_0050a664 + DAT_0050a660;
          local_14 = local_14 + 1) {
        *(undefined4 *)(local_14 * 0xc + 0x50a5f0) = 0;
      }
      if (*piVar4 == -0x3fffff72) {
        DAT_0050a66c = 0x83;
      }
      else if (*piVar4 == -0x3fffff70) {
        DAT_0050a66c = 0x81;
      }
      else if (*piVar4 == -0x3fffff6f) {
        DAT_0050a66c = 0x84;
      }
      else if (*piVar4 == -0x3fffff6d) {
        DAT_0050a66c = 0x85;
      }
      else if (*piVar4 == -0x3fffff73) {
        DAT_0050a66c = 0x82;
      }
      else if (*piVar4 == -0x3fffff71) {
        DAT_0050a66c = 0x86;
      }
      else if (*piVar4 == -0x3fffff6e) {
        DAT_0050a66c = 0x8a;
      }
      (*pcVar1)(8,DAT_0050a66c);
      DAT_0050a66c = uVar2;
    }
    else {
      piVar4[2] = 0;
      (*pcVar1)(piVar4[1]);
    }
    iVar5 = -1;
    DAT_0050a670 = (_EXCEPTION_POINTERS *)uVar3;
  }
  return iVar5;
}


