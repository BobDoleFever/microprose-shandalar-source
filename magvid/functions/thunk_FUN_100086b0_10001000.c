/*
 * Decompiled function: thunk_FUN_100086b0
 * Entry Point: 10001000
 * Size: 5 bytes
 */
#include "magvid.h"


void __thiscall
thunk_FUN_100086b0(void *this,int32_t arg_2,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x84) = DVar1;
  *(int32_t *)((int)this + 0x88) = arg_2;
  *(int32_t *)((int)this + 0x8c) = arg_3;
  *(int32_t *)((int)this + 0x90) = arg_4;
  *(int32_t *)((int)this + 0x94) = arg_5;
  return;
}


