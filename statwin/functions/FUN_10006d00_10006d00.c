/*
 * Decompiled function: FUN_10006d00
 * Entry Point: 10006d00
 * Size: 134 bytes
 */
#include "statwin.h"


void __fastcall FUN_10006d00(int *ptr_1)

{
  int *i_ptr_1;
  tagRECT local_24;
  RECT local_14;
  
  i_ptr_1 = (int *)(*ptr_1 + 0x14 + (uint32_t)*(uint8_t *)(*ptr_1 + 0x2d) * 4);
  *i_ptr_1 = *i_ptr_1 + 1;
  thunk_FUN_100065ce(ptr_1);
  SetRect(&local_24,0,0,0x7c,0xc3);
  OffsetRect(&local_24,*(int *)(&DAT_1000f1c8 + (uint32_t)*(uint8_t *)(*ptr_1 + 0x2d) * 8),
             *(int *)(&DAT_1000f1cc + (uint32_t)*(uint8_t *)(*ptr_1 + 0x2d) * 8));
  UnionRect(&local_24,&local_14,&local_24);
  return;
}


