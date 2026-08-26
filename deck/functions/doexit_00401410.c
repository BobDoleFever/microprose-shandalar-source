/*
 * Decompiled function: doexit
 * Entry Point: 00401410
 * Size: 251 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Debug */

void __cdecl doexit(UINT arg_1,int arg_2,int arg_3)

{
  HANDLE hProcess;
  uint32_t uval_1;
  UINT uExitCode;
  int *local_8;
  
  if (DAT_00412ab4 == 1) {
    uExitCode = arg_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00412ab0 = 1;
  DAT_00412aac = (uint8_t)arg_3;
  if (arg_2 == 0) {
    if (DAT_00415810 != (int *)0x0) {
      local_8 = DAT_00415800;
      while (local_8 = local_8 + -1, DAT_00415810 <= local_8) {
        if (*local_8 != 0) {
          (*(code *)*local_8)();
        }
      }
    }
    __initterm((int *)&DAT_00412514,(int *)&DAT_0041271c);
  }
  __initterm((int *)&DAT_00412820,(int *)&DAT_00412924);
  if ((DAT_00412ab8 == 0) && (uval_1 = __CrtSetDbgFlag(-1), (uval_1 & 0x20) != 0)) {
    DAT_00412ab8 = 1;
    __CrtDumpMemoryLeaks();
  }
  if (arg_3 == 0) {
    DAT_00412ab4 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(arg_1);
  }
  return;
}


