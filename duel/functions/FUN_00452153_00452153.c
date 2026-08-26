/*
 * Decompiled function: FUN_00452153
 * Entry Point: 00452153
 * Size: 50 bytes
 */
#include "duel.h"


undefined4 FUN_00452153(void)

{
  undefined4 local_8;
  
  DeviceIoControl(DAT_00693428,2,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return local_8;
}


