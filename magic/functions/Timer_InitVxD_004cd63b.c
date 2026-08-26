/*
 * Decompiled function: Timer_InitVxD
 * Entry Point: 004cd63b
 * Size: 168 bytes
 */
#include "magic.h"


undefined4 Timer_InitVxD(void)

{
  int local_8;
  
  if (DAT_006410e4 == (HANDLE)0x0) {
    DAT_006410e4 = CreateFileA(s_____MPStime_VXD_0052e63c,0,0,(LPSECURITY_ATTRIBUTES)0x0,0,0x4000000
                               ,(HANDLE)0x0);
    AssertOrLog((uint)(DAT_006410e4 != (HANDLE)0xffffffff),0x52e674,0x2c4,
                s_Could_Not_Load_Dave_s_Extra_Cool_0052e64c);
    DeviceIoControl(DAT_006410e4,1,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    AssertOrLog((uint)(local_8 == 0x100),0x52e6c4,0x2cb,s_Could_Not_Initialize_Dave_s_Extr_0052e694)
    ;
  }
  return 1;
}


