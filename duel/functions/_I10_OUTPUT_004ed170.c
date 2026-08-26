/*
 * Decompiled function: $I10_OUTPUT
 * Entry Point: 004ed170
 * Size: 1335 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _$I10_OUTPUT
   
   Library: Visual Studio 1998 Debug */

undefined4 __cdecl _I10_OUTPUT(int arg_1,uint arg_2,ushort arg_3,int arg_4,byte arg_5,short *arg_6)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint local_78;
  short local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  int local_4c;
  int local_48;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined2 local_3c;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined1 local_32;
  char cStack_31;
  int local_30;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  ushort local_10;
  int local_c;
  short *local_8;
  
  _local_40 = CONCAT22(uStack_3e,0x4d);
  local_24 = 0x134312f4;
  local_58 = 0xcc;
  local_57 = 0xcc;
  local_56 = 0xcc;
  local_55 = 0xcc;
  local_54 = 0xcc;
  local_53 = 0xcc;
  local_52 = 0xcc;
  local_51 = 0xcc;
  local_50 = 0xcc;
  local_4f = 0xcc;
  local_4e = 0xfb;
  local_4d = 0x3f;
  local_5c = 1;
  local_28 = arg_2;
  local_4c = arg_1;
  if ((arg_3 & 0x8000) == 0) {
    *(undefined1 *)(arg_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(arg_6 + 1) = 0x2d;
  }
  if ((((arg_3 & 0x7fff) == 0) && (arg_2 == 0)) && (arg_1 == 0)) {
    *arg_6 = 0;
    *(undefined1 *)(arg_6 + 1) = 0x20;
    *(undefined1 *)((int)arg_6 + 3) = 1;
    *(undefined1 *)(arg_6 + 2) = 0x30;
    *(undefined1 *)((int)arg_6 + 5) = 0;
    local_5c = 1;
  }
  else if ((arg_3 & 0x7fff) == 0x7fff) {
    *arg_6 = 1;
    if (((arg_2 == 0x80000000) && (arg_1 == 0)) || ((arg_2 & 0x40000000) != 0)) {
      if ((((arg_3 & 0x8000) == 0) || (arg_2 != 0xc0000000)) || (arg_1 != 0)) {
        if ((arg_2 == 0x80000000) && (arg_1 == 0)) {
          Mem_AllocOrFree_004d9630((uint *)(arg_6 + 2),(uint *)"1#INF");
          *(undefined1 *)((int)arg_6 + 3) = 5;
        }
        else {
          Mem_AllocOrFree_004d9630((uint *)(arg_6 + 2),(uint *)"1#QNAN");
          *(undefined1 *)((int)arg_6 + 3) = 6;
        }
      }
      else {
        Mem_AllocOrFree_004d9630((uint *)(arg_6 + 2),(uint *)"1#IND");
        *(undefined1 *)((int)arg_6 + 3) = 5;
      }
    }
    else {
      Mem_AllocOrFree_004d9630((uint *)(arg_6 + 2),(uint *)"1#SNAN");
      *(undefined1 *)((int)arg_6 + 3) = 6;
    }
    local_5c = 0;
  }
  else {
    local_10 = arg_3 & 0xff;
    uVar4 = (ushort)(byte)(arg_2 >> 0x18);
    _local_44 = CONCAT22(uStack_42,uVar4);
    local_c = (arg_3 & 0x7fff) * 0x4d10 + (uint)uVar4 * 0x9a + (uint)(arg_3 >> 8 & 0x7f) * 0x4d +
              -0x134312f4;
    local_60 = (short)((uint)local_c >> 0x10);
    local_32 = (undefined1)(arg_3 & 0x7fff);
    cStack_31 = (char)((arg_3 & 0x7fff) >> 8);
    local_3c = 0;
    uStack_36 = arg_2;
    uStack_3a = arg_1;
    ___multtenpow12((int *)&local_3c,-(int)local_60,1);
    if (0x3ffe < CONCAT11(cStack_31,local_32)) {
      local_60 = local_60 + 1;
      ___ld12mul((int *)&local_3c,(int *)&local_58);
    }
    *arg_6 = local_60;
    if (((arg_5 & 1) == 0) || (arg_4 = arg_4 + local_60, 0 < arg_4)) {
      if (0x15 < arg_4) {
        arg_4 = 0x15;
      }
      local_30 = CONCAT11(cStack_31,local_32) - 0x3ffe;
      local_32 = 0;
      cStack_31 = '\0';
      for (local_48 = 0; local_48 < 8; local_48 = local_48 + 1) {
        ___shl_12((int *)&local_3c);
      }
      if (local_30 < 0) {
        for (local_78 = -local_30 & 0xff; 0 < (int)local_78; local_78 = local_78 - 1) {
          ___shr_12((uint *)&local_3c);
        }
      }
      local_8 = arg_6 + 2;
      local_14 = arg_4 + 1;
      iVar2 = uStack_3a;
      uVar3 = uStack_36;
      while( true ) {
        uStack_36._2_2_ = (undefined2)(uVar3 >> 0x10);
        uStack_36._0_2_ = (undefined2)uVar3;
        uStack_3a._2_2_ = (undefined2)((uint)iVar2 >> 0x10);
        uStack_3a._0_2_ = (undefined2)iVar2;
        if (local_14 < 1) break;
        local_20 = CONCAT22((undefined2)uStack_3a,local_3c);
        local_1c = CONCAT22((undefined2)uStack_36,uStack_3a._2_2_);
        local_18 = CONCAT13(cStack_31,CONCAT12(local_32,uStack_36._2_2_));
        uStack_3a = iVar2;
        uStack_36 = uVar3;
        ___shl_12((int *)&local_3c);
        ___shl_12((int *)&local_3c);
        ___add_12((uint *)&local_3c,&local_20);
        ___shl_12((int *)&local_3c);
        *(char *)local_8 = cStack_31 + '0';
        local_8 = (short *)((int)local_8 + 1);
        cStack_31 = '\0';
        local_14 = local_14 + -1;
        iVar2 = uStack_3a;
        uVar3 = uStack_36;
      }
      pcVar1 = (char *)((int)local_8 + -1);
      local_8 = local_8 + -1;
      if (*pcVar1 < '5') {
        for (; (arg_6 + 2 <= local_8 && ((char)*local_8 == '0'));
            local_8 = (short *)((int)local_8 + -1)) {
        }
        if (local_8 < arg_6 + 2) {
          *arg_6 = 0;
          *(undefined1 *)(arg_6 + 1) = 0x20;
          *(undefined1 *)((int)arg_6 + 3) = 1;
          *(undefined1 *)(arg_6 + 2) = 0x30;
          *(undefined1 *)((int)arg_6 + 5) = 0;
          return 1;
        }
      }
      else {
        for (; (arg_6 + 2 <= local_8 && ((char)*local_8 == '9'));
            local_8 = (short *)((int)local_8 + -1)) {
          *(char *)local_8 = '0';
        }
        if (local_8 < arg_6 + 2) {
          local_8 = (short *)((int)local_8 + 1);
          *arg_6 = *arg_6 + 1;
        }
        *(char *)local_8 = (char)*local_8 + '\x01';
      }
      *(char *)((int)arg_6 + 3) = ((char)local_8 - ((char)arg_6 + '\x04')) + '\x01';
      *(undefined1 *)(*(char *)((int)arg_6 + 3) + 4 + (int)arg_6) = 0;
    }
    else {
      *arg_6 = 0;
      *(undefined1 *)(arg_6 + 1) = 0x20;
      *(undefined1 *)((int)arg_6 + 3) = 1;
      *(undefined1 *)(arg_6 + 2) = 0x30;
      *(undefined1 *)((int)arg_6 + 5) = 0;
      local_5c = 1;
    }
  }
  return local_5c;
}


