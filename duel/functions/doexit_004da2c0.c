/*
 * Decompiled function: doexit
 * Entry Point: 004da2c0
 * Size: 251 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Debug */

void __cdecl doexit(UINT arg_1,int arg_2,int arg_3)

{
  HANDLE hProcess;
  uint uVar1;
  UINT uExitCode;
  int *local_8;
  
  if (DAT_00509468 == 1) {
    uExitCode = arg_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00509464 = 1;
  DAT_00509460 = (undefined1)arg_3;
  if (arg_2 == 0) {
    if (DAT_006c2cb4 != (int *)0x0) {
      local_8 = DAT_006c2cb0;
      while (local_8 = local_8 + -1, DAT_006c2cb4 <= local_8) {
        if (*local_8 != 0) {
          (*(code *)*local_8)();
        }
      }
    }
    __initterm((int *)&DAT_004f2014,(int *)&DAT_004f201c);
  }
  __initterm((int *)&DAT_004f2020,(int *)&DAT_004f2024);
  if ((DAT_0050946c == 0) && (uVar1 = __CrtSetDbgFlag(-1), (uVar1 & 0x20) != 0)) {
    DAT_0050946c = 1;
    __CrtDumpMemoryLeaks();
  }
  if (arg_3 == 0) {
    DAT_00509468 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(arg_1);
  }
  return;
}


