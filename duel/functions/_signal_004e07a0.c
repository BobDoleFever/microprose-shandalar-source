/*
 * Decompiled function: _signal
 * Entry Point: 004e07a0
 * Size: 432 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _signal
   
   Library: Visual Studio 1998 Debug */

void __cdecl _signal(int arg_1)

{
  BOOL BVar1;
  int in_stack_00000008;
  int local_8;
  
  if ((in_stack_00000008 != 4) && (in_stack_00000008 != 3)) {
    if ((arg_1 == 2) || (((arg_1 == 0x15 || (arg_1 == 0x16)) || (arg_1 == 0xf)))) {
      if (((arg_1 == 2) || (arg_1 == 0x15)) && (DAT_00509740 == 0)) {
        BVar1 = SetConsoleCtrlHandler(ctrlevent_capture,1);
        if (BVar1 != 1) {
          DAT_00509424 = GetLastError();
          DAT_00509420 = 0x16;
          return;
        }
        DAT_00509740 = 1;
      }
      switch(arg_1) {
      case 2:
        DAT_00509730 = in_stack_00000008;
        break;
      case 0xf:
        DAT_0050973c = in_stack_00000008;
        break;
      case 0x15:
        DAT_00509734 = in_stack_00000008;
        break;
      case 0x16:
        DAT_00509738 = in_stack_00000008;
      }
      return;
    }
    if ((((arg_1 == 8) || (arg_1 == 4)) || (arg_1 == 0xb)) &&
       (local_8 = siglookup(arg_1), local_8 != 0)) {
      for (; *(int *)(local_8 + 4) == arg_1; local_8 = local_8 + 0xc) {
        *(int *)(local_8 + 8) = in_stack_00000008;
      }
      return;
    }
  }
  DAT_00509420 = 0x16;
  return;
}


