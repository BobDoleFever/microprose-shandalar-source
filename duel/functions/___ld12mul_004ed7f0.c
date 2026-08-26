/*
 * Decompiled function: ___ld12mul
 * Entry Point: 004ed7f0
 * Size: 1063 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___ld12mul
   
   Library: Visual Studio 1998 Debug */

void ___ld12mul(int *arg1,int *arg2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int local_3c;
  ushort local_38;
  int local_30;
  int local_2c;
  int local_24;
  undefined4 local_1c;
  short local_18 [3];
  undefined1 uStack_12;
  byte bStack_11;
  undefined2 local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_1c._0_1_ = 0;
  local_1c._1_1_ = 0;
  local_1c._2_2_ = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  uStack_12 = 0;
  bStack_11 = 0;
  uVar3 = *(ushort *)((int)arg1 + 10);
  uVar4 = *(ushort *)((int)arg2 + 10);
  uVar5 = uVar4 ^ uVar3;
  local_38 = (uVar4 & 0x7fff) + (uVar3 & 0x7fff);
  if ((((uVar3 & 0x7fff) < 0x7fff) && ((uVar4 & 0x7fff) < 0x7fff)) && (local_38 < 0xbffe)) {
    if (local_38 < 0x3fc0) {
      arg1[2] = 0;
      arg1[1] = 0;
      *arg1 = 0;
    }
    else if ((((uVar3 & 0x7fff) == 0) && (local_38 = local_38 + 1, (arg1[2] & 0x7fffffffU) == 0)) &&
            ((arg1[1] == 0 && (*arg1 == 0)))) {
      *(undefined2 *)((int)arg1 + 10) = 0;
    }
    else if ((((uVar4 & 0x7fff) == 0) && (local_38 = local_38 + 1, (arg2[2] & 0x7fffffffU) == 0)) &&
            ((arg2[1] == 0 && (*arg2 == 0)))) {
      arg1[2] = 0;
      arg1[1] = 0;
      *arg1 = 0;
    }
    else {
      local_30 = 0;
      for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
        local_2c = local_24 * 2;
        local_c = 8;
        for (local_3c = 5 - local_24; 0 < local_3c; local_3c = local_3c + -1) {
          iVar6 = ___addl(*(uint *)((int)&local_1c + local_30),
                          (uint)*(ushort *)((int)arg2 + local_c) *
                          (uint)*(ushort *)(local_2c + (int)arg1),
                          (uint *)((int)&local_1c + local_30));
          if (iVar6 != 0) {
            *(short *)((int)local_18 + local_30) = *(short *)((int)local_18 + local_30) + 1;
          }
          local_2c = local_2c + 2;
          local_c = local_c + -2;
        }
        local_30 = local_30 + 2;
      }
      local_38 = local_38 + 0xc002;
      while ((0 < (short)local_38 && ((bStack_11 & 0x80) == 0))) {
        ___shl_12(&local_1c);
        local_38 = local_38 - 1;
      }
      if ((short)local_38 < 1) {
        for (local_38 = local_38 - 1; (short)local_38 < 0; local_38 = local_38 + 1) {
          if (((byte)local_1c & 1) != 0) {
            local_8 = local_8 + 1;
          }
          ___shr_12(&local_1c);
        }
        if (local_8 != 0) {
          local_1c._0_1_ = (byte)local_1c | 1;
        }
      }
      iVar2 = CONCAT22(local_18[0],local_1c._2_2_);
      iVar6 = CONCAT22(local_18[2],local_18[1]);
      sVar1 = CONCAT11(bStack_11,uStack_12);
      if (0x8000 < CONCAT11(local_1c._1_1_,(byte)local_1c)) {
        if (CONCAT22(local_18[0],local_1c._2_2_) == -1) {
          iVar2 = 0;
          if (CONCAT22(local_18[2],local_18[1]) == -1) {
            iVar6 = 0;
            if (CONCAT11(bStack_11,uStack_12) == -1) {
              sVar1 = -0x8000;
              local_38 = local_38 + 1;
            }
            else {
              sVar1 = CONCAT11(bStack_11,uStack_12) + 1;
            }
          }
          else {
            iVar6 = CONCAT22(local_18[2],local_18[1]) + 1;
          }
        }
        else {
          iVar2 = CONCAT22(local_18[0],local_1c._2_2_) + 1;
          iVar6 = CONCAT22(local_18[2],local_18[1]);
        }
      }
      local_18[0] = (short)((uint)iVar2 >> 0x10);
      local_1c._2_2_ = (undefined2)iVar2;
      bStack_11 = (byte)((ushort)sVar1 >> 8);
      uStack_12 = (undefined1)sVar1;
      local_18[2] = (short)((uint)iVar6 >> 0x10);
      local_18[1] = (short)iVar6;
      if (local_38 < 0x7fff) {
        *(undefined2 *)arg1 = local_1c._2_2_;
        *(uint *)((int)arg1 + 2) = CONCAT22(local_18[1],local_18[0]);
        *(uint *)((int)arg1 + 6) = CONCAT13(bStack_11,CONCAT12(uStack_12,local_18[2]));
        *(ushort *)((int)arg1 + 10) = uVar5 & 0x8000 | local_38;
      }
      else {
        if ((uVar5 & 0x8000) == 0) {
          arg1[2] = 0x7fff8000;
        }
        else {
          arg1[2] = -0x8000;
        }
        arg1[1] = 0;
        *arg1 = 0;
      }
    }
  }
  else {
    if ((uVar5 & 0x8000) == 0) {
      arg1[2] = 0x7fff8000;
    }
    else {
      arg1[2] = -0x8000;
    }
    arg1[1] = 0;
    *arg1 = 0;
  }
  return;
}


