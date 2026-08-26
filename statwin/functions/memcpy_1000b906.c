/*
 * Decompiled function: memcpy
 * Entry Point: 1000b906
 * Size: 6 bytes
 */
#include "statwin.h"


void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000b906. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memcpy(ptr_1,ptr_2,arg_3);
  return buf_ptr_1;
}


