/*
 * Decompiled function: _signal
 * Entry Point: 004080e0
 * Size: 432 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _signal
   
   Library: Visual Studio 1998 Debug */

void __cdecl _signal(int arg_1)

{
  BOOL BVar1;
  int stack_arg;
  int32_t *local_8;
  
  if ((stack_arg != 4) && (stack_arg != 3)) {
    if ((arg_1 == 2) || (((arg_1 == 0x15 || (arg_1 == 0x16)) || (arg_1 == 0xf)))) {
      if (((arg_1 == 2) || (arg_1 == 0x15)) && (DAT_00413920 == 0)) {
        BVar1 = SetConsoleCtrlHandler(ctrlevent_capture,1);
        if (BVar1 != 1) {
          _DAT_00412a70 = GetLastError();
          _DAT_00412a6c = 0x16;
          return;
        }
        DAT_00413920 = 1;
      }
      switch(arg_1) {
      case 2:
        DAT_00413910 = stack_arg;
        break;
      case 0xf:
        DAT_0041391c = stack_arg;
        break;
      case 0x15:
        DAT_00413914 = stack_arg;
        break;
      case 0x16:
        DAT_00413918 = stack_arg;
      }
      return;
    }
    if ((((arg_1 == 8) || (arg_1 == 4)) || (arg_1 == 0xb)) &&
       (local_8 = siglookup(arg_1), local_8 != (int32_t *)0x0)) {
      for (; local_8[1] == arg_1; local_8 = local_8 + 3) {
        local_8[2] = stack_arg;
      }
      return;
    }
  }
  _DAT_00412a6c = 0x16;
  return;
}


