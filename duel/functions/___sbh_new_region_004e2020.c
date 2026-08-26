/*
 * Decompiled function: ___sbh_new_region
 * Entry Point: 004e2020
 * Size: 508 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_new_region
   
   Library: Visual Studio 1998 Debug */

undefined ** ___sbh_new_region(void)

{
  LPVOID pvVar1;
  undefined **local_10;
  int local_c;
  undefined4 *local_8;
  
  if (DAT_0050a1f0 == 0) {
    local_10 = &PTR_LOOP_005099e0;
  }
  else {
    local_10 = HeapAlloc(DAT_006c1c94,0,0x814);
    if (local_10 == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  local_8 = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (local_8 != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(local_8,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (local_10 == &PTR_LOOP_005099e0) {
        if (PTR_LOOP_005099e0 == (undefined *)0x0) {
          PTR_LOOP_005099e0 = (undefined *)&PTR_LOOP_005099e0;
        }
        if (PTR_LOOP_005099e4 == (undefined *)0x0) {
          PTR_LOOP_005099e4 = (undefined *)&PTR_LOOP_005099e0;
        }
      }
      else {
        *local_10 = (undefined *)&PTR_LOOP_005099e0;
        local_10[1] = PTR_LOOP_005099e4;
        PTR_LOOP_005099e4 = (undefined *)local_10;
        *(undefined ***)local_10[1] = local_10;
      }
      local_10[0x204] = (undefined *)local_8;
      local_10[2] = (undefined *)0x0;
      local_10[3] = (undefined *)0x10;
      for (local_c = 0; local_c < 0x400; local_c = local_c + 1) {
        if (local_c < 0x10) {
          *(undefined1 *)(local_c + 0x10 + (int)local_10) = 0xf0;
        }
        else {
          *(undefined1 *)(local_c + 0x10 + (int)local_10) = 0xff;
        }
        *(undefined1 *)(local_c + 0x410 + (int)local_10) = 0xf1;
      }
      _memset(local_8,0,0x10000);
      for (; local_8 < local_10[0x204] + 0x10000; local_8 = local_8 + 0x400) {
        *local_8 = local_8 + 2;
        local_8[1] = 0xf0;
        *(undefined1 *)(local_8 + 0x3e) = 0xff;
      }
      return local_10;
    }
    VirtualFree(local_8,0,0x8000);
  }
  if (local_10 != &PTR_LOOP_005099e0) {
    HeapFree(DAT_006c1c94,0,local_10);
  }
  return (undefined **)0x0;
}


