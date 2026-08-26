/*
 * Decompiled function: Timer_GetTicks
 * Entry Point: 004cd6e3
 * Size: 50 bytes
 */
#include "magic.h"


undefined4 Timer_GetTicks(void)

{
  undefined4 local_8;
  
  DeviceIoControl(DAT_006410e4,2,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return local_8;
}


