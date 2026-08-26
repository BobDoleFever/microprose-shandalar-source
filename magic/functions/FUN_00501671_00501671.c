/*
 * Decompiled function: FUN_00501671
 * Entry Point: 00501671
 * Size: 136 bytes
 */
#include "magic.h"


void FUN_00501671(void)

{
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  HANDLE hSourceHandle;
  LPHANDLE lpTargetHandle;
  DWORD dwDesiredAccess;
  BOOL bInheritHandle;
  DWORD dwOptions;
  
  if (DAT_0061d880 == 0) {
    DAT_0061d880 = 1;
    DAT_00627850 = GetCurrentThread();
    dwOptions = 0;
    bInheritHandle = 0;
    dwDesiredAccess = 0x1f03ff;
    lpTargetHandle = &DAT_00627850;
    hTargetProcessHandle = GetCurrentProcess();
    hSourceHandle = DAT_00627850;
    hSourceProcessHandle = GetCurrentProcess();
    DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                    dwDesiredAccess,bInheritHandle,dwOptions);
  }
  DAT_00530da0 = DAT_00530da0 + 1;
  if (DAT_0062681c == 0) {
    DAT_0062681c = 1;
    Pic_Subsystem_00423ed6();
    DAT_0062681c = 0;
  }
  return;
}


