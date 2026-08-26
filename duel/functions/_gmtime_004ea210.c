/*
 * Decompiled function: _gmtime
 * Entry Point: 004ea210
 * Size: 487 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _gmtime
   
   Library: Visual Studio 1998 Debug */

tm * __cdecl _gmtime(time_t *ptr_1)

{
  int iVar1;
  bool bVar2;
  tm *ptVar3;
  int iVar4;
  int local_18;
  undefined *local_14;
  int local_10;
  
  iVar4 = (int)*ptr_1;
  bVar2 = false;
  if (iVar4 < 0) {
    ptVar3 = (tm *)0x0;
  }
  else {
    iVar1 = iVar4 % 0x7861f80;
    iVar4 = (iVar4 / 0x7861f80) * 4;
    local_18 = iVar4 + 0x46;
    local_10 = iVar1;
    if (0x1e1337f < iVar1) {
      local_18 = iVar4 + 0x47;
      local_10 = iVar1 + -0x1e13380;
      if (0x1e1337f < local_10) {
        local_18 = iVar4 + 0x48;
        local_10 = iVar1 + -0x3c26700;
        if (local_10 < 0x1e28500) {
          bVar2 = true;
        }
        else {
          local_18 = iVar4 + 0x49;
          local_10 = iVar1 + -0x5a4ec00;
        }
      }
    }
    DAT_0050a824 = local_18;
    DAT_0050a82c = local_10 / 0x15180;
    if (bVar2) {
      local_14 = &DAT_0050a838;
    }
    else {
      local_14 = &DAT_0050a870;
    }
    for (local_18 = 1; *(int *)(local_14 + local_18 * 4) < DAT_0050a82c; local_18 = local_18 + 1) {
    }
    DAT_0050a820 = local_18 + -1;
    DAT_0050a81c = DAT_0050a82c - *(int *)(local_14 + DAT_0050a820 * 4);
    DAT_0050a828 = ((int)*ptr_1 / 0x15180 + 4) % 7;
    DAT_0050a818 = (local_10 % 0x15180) / 0xe10;
    iVar4 = (local_10 % 0x15180) % 0xe10;
    DAT_0050a814 = iVar4 / 0x3c;
    DAT_0050a810 = iVar4 % 0x3c;
    DAT_0050a830 = 0;
    ptVar3 = (tm *)&DAT_0050a810;
  }
  return ptVar3;
}


