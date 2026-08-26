/*
 * Decompiled function: FUN_1000b99f
 * Entry Point: 1000b99f
 * Size: 296 bytes
 */
#include "magvid.h"


bool __thiscall FUN_1000b99f(void *this,int arg_2)

{
  int val_1;
  uint32_t uval_2;
  int local_18;
  int local_8;
  
  if (arg_2 == 0) {
    local_8 = ICSendMessage(*(int32_t *)this,0x401d,0,0);
  }
  else {
    val_1 = *(int *)((int)this + 0x18);
    uval_2 = (uint32_t)*(uint16_t *)(arg_2 + 2);
    if (0xeb < *(uint16_t *)(arg_2 + 2)) {
      uval_2 = 0xec;
    }
    for (local_18 = 0; local_18 < (int)uval_2; local_18 = local_18 + 1) {
      *(uint8_t *)(val_1 + 0x52 + local_18 * 4) = *(uint8_t *)(arg_2 + 4 + local_18 * 4);
      *(uint8_t *)(val_1 + 0x51 + local_18 * 4) = *(uint8_t *)(arg_2 + 5 + local_18 * 4);
      *(uint8_t *)(val_1 + 0x50 + local_18 * 4) = *(uint8_t *)(arg_2 + 6 + local_18 * 4);
    }
    *(int32_t *)(*(int *)((int)this + 0x18) + 0x20) = 0x100;
    local_8 = ICSendMessage(*(int32_t *)this,0x401d,*(int32_t *)((int)this + 0x18),0);
    if (local_8 != 0) {
      ICSendMessage(*(int32_t *)this,0x401d,0,0);
    }
  }
  return local_8 == 0;
}


