/*
 * Decompiled function: ___sbh_new_region
 * Entry Point: 004057d0
 * Size: 508 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_new_region
   
   Library: Visual Studio 1998 Debug */

uint8_t ** ___sbh_new_region(void)

{
  LPVOID buf_ptr_1;
  uint8_t **local_10;
  int local_c;
  int32_t *local_8;
  
  if (DAT_004138a0 == 0) {
    local_10 = &PTR_LOOP_00413090;
  }
  else {
    local_10 = HeapAlloc(DAT_004156ac,0,0x814);
    if (local_10 == (uint8_t **)0x0) {
      return (uint8_t **)0x0;
    }
  }
  local_8 = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (local_8 != (int32_t *)0x0) {
    buf_ptr_1 = VirtualAlloc(local_8,0x10000,0x1000,4);
    if (buf_ptr_1 != (LPVOID)0x0) {
      if (local_10 == &PTR_LOOP_00413090) {
        if (PTR_LOOP_00413090 == (uint8_t *)0x0) {
          PTR_LOOP_00413090 = (uint8_t *)&PTR_LOOP_00413090;
        }
        if (PTR_LOOP_00413094 == (uint8_t *)0x0) {
          PTR_LOOP_00413094 = (uint8_t *)&PTR_LOOP_00413090;
        }
      }
      else {
        *local_10 = (uint8_t *)&PTR_LOOP_00413090;
        local_10[1] = PTR_LOOP_00413094;
        PTR_LOOP_00413094 = (uint8_t *)local_10;
        *(uint8_t ***)local_10[1] = local_10;
      }
      local_10[0x204] = (uint8_t *)local_8;
      local_10[2] = (uint8_t *)0x0;
      local_10[3] = (uint8_t *)0x10;
      for (local_c = 0; local_c < 0x400; local_c = local_c + 1) {
        if (local_c < 0x10) {
          *(uint8_t *)(local_c + 0x10 + (int)local_10) = 0xf0;
        }
        else {
          *(uint8_t *)(local_c + 0x10 + (int)local_10) = 0xff;
        }
        *(uint8_t *)(local_c + 0x410 + (int)local_10) = 0xf1;
      }
      _memset(local_8,0,0x10000);
      for (; local_8 < local_10[0x204] + 0x10000; local_8 = local_8 + 0x400) {
        *local_8 = local_8 + 2;
        local_8[1] = 0xf0;
        *(uint8_t *)(local_8 + 0x3e) = 0xff;
      }
      return local_10;
    }
    VirtualFree(local_8,0,0x8000);
  }
  if (local_10 != &PTR_LOOP_00413090) {
    HeapFree(DAT_004156ac,0,local_10);
  }
  return (uint8_t **)0x0;
}


