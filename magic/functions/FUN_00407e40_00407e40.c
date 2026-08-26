/*
 * Decompiled function: FUN_00407e40
 * Entry Point: 00407e40
 * Size: 585 bytes
 */
#include "magic.h"


void FUN_00407e40(undefined4 arg1,uint arg2)

{
  ushort uVar1;
  SHORT SVar2;
  SHORT SVar3;
  uint uVar4;
  int *piVar5;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  if (DAT_005382d8 == 0) {
    do {
      SVar2 = GetAsyncKeyState(0x12);
    } while (SVar2 != 0);
    do {
      SVar2 = GetAsyncKeyState(0x11);
    } while (SVar2 != 0);
    DAT_005382d8 = 1;
  }
  if (DAT_00516bdc == 0x31) {
    MessageBeep(0xffffffff);
  }
  else {
    uVar4 = (arg2 & 0xff0000) >> 0x10;
    SVar2 = GetAsyncKeyState(0x12);
    if (SVar2 == 0) {
      SVar2 = GetAsyncKeyState(0x11);
      if (SVar2 == 0) {
        piVar5 = (int *)__p___mb_cur_max();
        if (*piVar5 < 2) {
          uVar1 = *(ushort *)(&DAT_0051664a + uVar4 * 0x10);
          piVar5 = (int *)__p__pctype();
          local_14 = *(ushort *)(*piVar5 + (uVar1 & 0xff) * 2) & 0x103;
        }
        else {
          local_14 = _isctype(*(ushort *)(&DAT_0051664a + uVar4 * 0x10) & 0xff,0x103);
        }
        if (local_14 == 0) {
          if ((uVar4 < 0x47) || (0x53 < uVar4)) {
            SVar2 = GetAsyncKeyState(0x10);
            if (SVar2 != 0) {
              local_c = 1;
            }
          }
          else {
            SVar2 = GetAsyncKeyState(0x90);
            SVar3 = GetAsyncKeyState(0x10);
            local_c = (uint)((SVar2 != 0) != (SVar3 != 0));
          }
        }
        else {
          SVar2 = GetAsyncKeyState(0x10);
          SVar3 = GetAsyncKeyState(0x14);
          local_c = (uint)((SVar2 != 0) != (SVar3 != 0));
        }
      }
      else {
        local_c = 2;
      }
    }
    else {
      local_c = 3;
    }
    if (*(char *)(uVar4 * 0x10 + 0x516648 + local_c * 4) != '\0') {
      uVar1 = *(ushort *)(&DAT_0051664a + local_c * 4 + uVar4 * 0x10);
      local_10 = 0x32U - DAT_00516bdc;
      if ((int)(arg2 & 0xffff) <= (int)(0x32U - DAT_00516bdc)) {
        local_10 = arg2 & 0xffff;
      }
      while (local_10 != 0) {
        (&DAT_00538210)[DAT_00516bdc] = (uint)uVar1;
        DAT_00516bdc = DAT_00516bdc + 1;
        local_10 = local_10 - 1;
      }
    }
  }
  return;
}


