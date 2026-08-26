/*
 * Decompiled function: ___strgtold12
 * Entry Point: 004ec4f0
 * Size: 2795 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___strgtold12
   
   Library: Visual Studio 1998 Debug */

uint __cdecl
___strgtold12(_LDBL12 *ptr_1,char **str_2,char *str_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  byte *pbVar1;
  bool bVar2;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  int local_78;
  uint local_74;
  int local_70;
  char *local_6c;
  byte *local_68;
  undefined2 local_64;
  undefined4 local_62;
  undefined4 local_5e;
  ushort local_5a;
  int local_58;
  ushort local_54;
  int local_50;
  undefined2 local_4c;
  uint local_48;
  int local_44;
  byte local_40;
  char local_3c [23];
  char local_25;
  undefined4 local_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  byte *local_8;
  
  local_6c = local_3c;
  local_20 = local_20 & 0xffff0000;
  local_78 = 1;
  local_74 = 0;
  local_58 = 0;
  local_10 = 0;
  local_1c = 0;
  local_44 = 0;
  bVar2 = false;
  local_18 = 0;
  local_70 = 0;
  local_48 = 0;
  local_50 = 0;
  local_68 = (byte *)str_3;
  for (local_8 = (byte *)str_3;
      (((*local_8 == 0x20 || (*local_8 == 9)) || (*local_8 == 10)) || (*local_8 == 0xd));
      local_8 = local_8 + 1) {
  }
  do {
    if (local_50 == 10) {
      *str_2 = (char *)local_8;
      if ((local_58 != 0) && (local_44 == 0)) {
        if (0x18 < local_74) {
          if ('\x04' < local_25) {
            local_25 = local_25 + '\x01';
          }
          local_74 = 0x18;
          local_6c = local_6c + -1;
          local_70 = local_70 + 1;
        }
        if (local_74 == 0) {
          local_4c = 0;
          local_54 = 0;
          local_14 = 0;
          local_c = 0;
        }
        else {
          while (local_6c = local_6c + -1, *local_6c == '\0') {
            local_74 = local_74 - 1;
            local_70 = local_70 + 1;
          }
          ___mtold12(local_3c,local_74,(uint *)&local_64);
          if (local_78 < 0) {
            local_18 = -local_18;
          }
          local_18 = local_18 + local_70;
          if (local_1c == 0) {
            local_18 = local_18 + arg_5;
          }
          if (local_10 == 0) {
            local_18 = local_18 - arg_6;
          }
          if ((int)local_18 < 0x1451) {
            if ((int)local_18 < -0x1450) {
              bVar2 = true;
            }
            else {
              ___multtenpow12((int *)&local_64,local_18,arg_4);
              local_4c = local_64;
              local_c = local_62;
              local_14 = local_5e;
              local_54 = local_5a;
            }
          }
          else {
            local_44 = 1;
          }
        }
      }
      if (local_58 == 0) {
        local_4c = 0;
        local_54 = 0;
        local_14 = 0;
        local_c = 0;
        local_48 = local_48 | 4;
      }
      else if (local_44 == 0) {
        if (bVar2) {
          local_4c = 0;
          local_54 = 0;
          local_14 = 0;
          local_c = 0;
          local_48 = local_48 | 1;
        }
      }
      else {
        local_54 = 0x7fff;
        local_14 = 0x80000000;
        local_c = 0;
        local_4c = 0;
        local_48 = local_48 | 2;
      }
      *(undefined2 *)ptr_1->ld12 = local_4c;
      *(undefined4 *)(ptr_1->ld12 + 2) = local_c;
      *(undefined4 *)(ptr_1->ld12 + 6) = local_14;
      *(ushort *)(ptr_1->ld12 + 10) = (ushort)local_20 | local_54;
      return local_48;
    }
    local_40 = *local_8;
    pbVar1 = local_8 + 1;
    switch(local_50) {
    case 0:
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (DAT_005096b0 == local_40) {
          local_50 = 5;
        }
        else if (local_40 == 0x2b) {
          local_50 = 2;
          local_20 = (uint)local_20._2_2_ << 0x10;
        }
        else if (local_40 == 0x2d) {
          local_50 = 2;
          local_20 = CONCAT22(local_20._2_2_,0x8000);
        }
        else if (local_40 == 0x30) {
          local_50 = 1;
        }
        else {
          local_50 = 10;
          pbVar1 = local_8;
        }
      }
      else {
        local_50 = 3;
        pbVar1 = local_8;
      }
      break;
    case 1:
      local_58 = 1;
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (DAT_005096b0 == local_40) {
          local_50 = 4;
        }
        else {
          switch(local_40) {
          case 0x2b:
          case 0x2d:
            local_50 = 0xb;
            pbVar1 = local_8;
            break;
          default:
            local_50 = 10;
            pbVar1 = local_8;
            break;
          case 0x30:
            local_50 = 1;
            break;
          case 0x44:
          case 0x45:
          case 100:
          case 0x65:
            local_50 = 6;
          }
        }
      }
      else {
        local_50 = 3;
        pbVar1 = local_8;
      }
      break;
    case 2:
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (DAT_005096b0 == local_40) {
          local_50 = 5;
        }
        else if (local_40 == 0x30) {
          local_50 = 1;
        }
        else {
          local_50 = 10;
          local_8 = local_68;
          pbVar1 = local_8;
        }
      }
      else {
        local_50 = 3;
        pbVar1 = local_8;
      }
      break;
    case 3:
      local_58 = 1;
      local_8 = pbVar1;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_84 = *(ushort *)(PTR_DAT_005094a0 + (uint)local_40 * 2) & 4;
        }
        else {
          local_84 = __isctype((uint)local_40,4);
        }
        if (local_84 == 0) break;
        if (local_74 < 0x19) {
          local_74 = local_74 + 1;
          *local_6c = local_40 - 0x30;
          local_6c = local_6c + 1;
        }
        else {
          local_70 = local_70 + 1;
        }
        local_40 = *local_8;
        local_8 = local_8 + 1;
      }
      pbVar1 = local_8;
      if (DAT_005096b0 == local_40) {
        local_50 = 4;
      }
      else {
        switch(local_40) {
        case 0x2b:
        case 0x2d:
          local_50 = 0xb;
          pbVar1 = local_8 + -1;
          break;
        default:
          local_50 = 10;
          pbVar1 = local_8 + -1;
          break;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          local_50 = 6;
        }
      }
      break;
    case 4:
      local_58 = 1;
      local_10 = 1;
      local_8 = pbVar1;
      if (local_74 == 0) {
        while (local_40 == 0x30) {
          local_70 = local_70 + -1;
          local_40 = *local_8;
          local_8 = local_8 + 1;
        }
      }
      while( true ) {
        if (DAT_005096ac < 2) {
          local_88 = *(ushort *)(PTR_DAT_005094a0 + (uint)local_40 * 2) & 4;
        }
        else {
          local_88 = __isctype((uint)local_40,4);
        }
        if (local_88 == 0) break;
        if (local_74 < 0x19) {
          local_74 = local_74 + 1;
          *local_6c = local_40 - 0x30;
          local_6c = local_6c + 1;
          local_70 = local_70 + -1;
        }
        local_40 = *local_8;
        local_8 = local_8 + 1;
      }
      switch(local_40) {
      case 0x2b:
      case 0x2d:
        local_50 = 0xb;
        pbVar1 = local_8 + -1;
        break;
      default:
        local_50 = 10;
        pbVar1 = local_8 + -1;
        break;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        local_50 = 6;
        pbVar1 = local_8;
      }
      break;
    case 5:
      local_10 = 1;
      if (DAT_005096ac < 2) {
        local_8c = *(ushort *)(PTR_DAT_005094a0 + (uint)local_40 * 2) & 4;
        local_8 = pbVar1;
      }
      else {
        local_8 = pbVar1;
        local_8c = __isctype((uint)local_40,4);
      }
      if (local_8c == 0) {
        local_50 = 10;
        local_8 = local_68;
        pbVar1 = local_8;
      }
      else {
        local_50 = 4;
        pbVar1 = local_8 + -1;
      }
      break;
    case 6:
      local_68 = local_8 + -1;
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (local_40 == 0x2b) {
          local_50 = 7;
        }
        else if (local_40 == 0x2d) {
          local_50 = 7;
          local_78 = -1;
        }
        else if (local_40 == 0x30) {
          local_50 = 8;
        }
        else {
          local_50 = 10;
          pbVar1 = local_68;
        }
      }
      else {
        local_50 = 9;
        pbVar1 = local_8;
      }
      break;
    case 7:
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (local_40 == 0x30) {
          local_50 = 8;
        }
        else {
          local_50 = 10;
          local_8 = local_68;
          pbVar1 = local_8;
        }
      }
      else {
        local_50 = 9;
        pbVar1 = local_8;
      }
      break;
    case 8:
      local_1c = 1;
      local_8 = pbVar1;
      while (local_40 == 0x30) {
        local_40 = *local_8;
        local_8 = local_8 + 1;
      }
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        local_50 = 10;
      }
      else {
        local_50 = 9;
      }
      local_8 = local_8 + -1;
      pbVar1 = local_8;
      break;
    case 9:
      local_1c = 1;
      local_80 = 0;
      local_8 = pbVar1;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_90 = *(ushort *)(PTR_DAT_005094a0 + (uint)local_40 * 2) & 4;
        }
        else {
          local_90 = __isctype((uint)local_40,4);
        }
        if (local_90 == 0) goto LAB_004ecd9b;
        local_80 = (char)local_40 + -0x30 + local_80 * 10;
        if (0x1450 < local_80) break;
        local_40 = *local_8;
        local_8 = local_8 + 1;
      }
      local_80 = 0x1451;
LAB_004ecd9b:
      local_18 = local_80;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_94 = *(ushort *)(PTR_DAT_005094a0 + (uint)local_40 * 2) & 4;
        }
        else {
          local_94 = __isctype((uint)local_40,4);
        }
        if (local_94 == 0) break;
        local_40 = *local_8;
        local_8 = local_8 + 1;
      }
      local_50 = 10;
      pbVar1 = local_8 + -1;
      break;
    case 0xb:
      if (arg_7 == 0) {
        local_50 = 10;
        pbVar1 = local_8;
      }
      else {
        local_68 = local_8;
        if (local_40 == 0x2b) {
          local_50 = 7;
        }
        else if (local_40 == 0x2d) {
          local_50 = 7;
          local_78 = -1;
        }
        else {
          local_50 = 10;
          pbVar1 = local_8;
        }
      }
    }
    local_8 = pbVar1;
  } while( true );
}


