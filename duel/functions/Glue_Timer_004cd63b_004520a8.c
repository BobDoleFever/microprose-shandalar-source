/*
 * Decompiled function: Glue_Timer_004cd63b
 * Entry Point: 004520a8
 * Size: 171 bytes
 */
#include "duel.h"


undefined4 Glue_Timer_004cd63b(void)

{
  int local_8;
  
  if (DAT_00693428 == (HANDLE)0x0) {
    DAT_00693428 = CreateFileA(s_____MPStime_VXD_004f8660,0,0,(LPSECURITY_ATTRIBUTES)0x0,0,0x4000000
                               ,(HANDLE)0x0);
    Assert_Handler_00499950
              ((uint)(DAT_00693428 != (HANDLE)0xffffffff),0x4f8698,0x2c4,
               s_Could_Not_Load_Dave_s_Extra_Cool_004f8670);
    DeviceIoControl(DAT_00693428,1,(LPVOID)0x0,0,&local_8,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    Assert_Handler_00499950
              ((uint)(local_8 == 0x100),0x4f86e8,0x2cb,s_Could_Not_Initialize_Dave_s_Extr_004f86b8);
  }
  return 1;
}


