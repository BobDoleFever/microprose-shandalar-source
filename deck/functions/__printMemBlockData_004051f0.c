/*
 * Decompiled function: __printMemBlockData
 * Entry Point: 004051f0
 * Size: 252 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __printMemBlockData
   
   Library: Visual Studio 1998 Debug */

void __cdecl __printMemBlockData(int arg_1)

{
  uint8_t flag_1;
  code *char_ptr_2;
  int val_3;
  uint32_t local_58;
  int local_50;
  uint8_t local_4c [20];
  char local_38 [52];
  
  local_50 = 0;
  while( true ) {
    val_3 = *(int *)(arg_1 + 0x10);
    if (0xf < val_3) {
      val_3 = 0x10;
    }
    if (val_3 <= local_50) break;
    flag_1 = *(uint8_t *)(arg_1 + 0x20 + local_50);
    if (DAT_00413904 < 2) {
      local_58 = *(uint16_t *)(PTR_DAT_00412e58 + (uint32_t)flag_1 * 2) & 0x157;
    }
    else {
      local_58 = __isctype((uint32_t)flag_1,0x157);
    }
    if (local_58 == 0) {
      local_4c[local_50] = 0x20;
    }
    else {
      local_4c[local_50] = flag_1;
    }
    _sprintf(local_38 + local_50 * 3,"%.2X ",(uint32_t)flag_1);
    local_50 = local_50 + 1;
  }
  local_4c[local_50] = 0;
  val_3 = __CrtDbgReport(0,0,0,0," Data: <%s> %s\n");
  if (val_3 == 1) {
    char_ptr_2 = (code *)swi(3);
    (*char_ptr_2)();
    return;
  }
  return;
}


