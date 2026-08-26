/*
 * Decompiled function: __input
 * Entry Point: 004e3e50
 * Size: 4808 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __input
   
   Library: Visual Studio 1998 Debug */

uint __input(int arg_1,byte *arg_2,undefined4 *arg_3)

{
  byte *pbVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  bool bVar6;
  FILE *fp;
  uint local_234;
  uint local_224;
  uint local_218;
  uint local_214;
  uint local_210;
  uint local_20c;
  uint local_208;
  uint local_200;
  uint local_1fc;
  byte local_1f4;
  undefined1 local_1f3;
  byte local_1f0;
  int local_1ec;
  wchar_t *local_1e8;
  byte *local_1e4;
  int local_1e0;
  uint local_1dc;
  undefined4 *local_1d8;
  byte local_1d4;
  byte local_1d3 [351];
  char local_74;
  int local_70;
  char local_6c;
  char local_68;
  byte local_64 [32];
  uint local_44;
  wchar_t *local_40;
  char local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  char local_2c;
  byte local_28;
  uint local_24;
  int local_20;
  char local_1c;
  char local_18;
  byte local_14;
  uint local_10;
  byte local_c;
  wchar_t local_8 [2];
  
  if ((arg_2 == (byte *)0x0) &&
     (iVar3 = __CrtDbgReport(2,0x4f0ea4,0x109,0,"format != NULL"), iVar3 == 1)) {
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  if ((arg_1 == 0) && (iVar3 = __CrtDbgReport(2,0x4f0ea4,0x10c,0,"stream != NULL"), iVar3 == 1)) {
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  local_2c = '\0';
  local_38 = 0;
  local_24 = local_38;
  do {
    if (*arg_2 == 0) {
LAB_004e51af:
      if ((local_1dc == 0xffffffff) && ((local_38 == 0 && (local_2c == '\0')))) {
        local_38 = 0xffffffff;
      }
      return local_38;
    }
    if ((int)DAT_005096ac < 2) {
      local_1fc = *(ushort *)(PTR_DAT_005094a0 + (uint)*arg_2 * 2) & 8;
    }
    else {
      local_1fc = __isctype((uint)*arg_2,8);
    }
    if (local_1fc != 0) {
      local_24 = local_24 - 1;
      fp = (FILE *)arg_1;
      iVar3 = __whiteout((int *)&local_24,(FILE *)arg_1);
      __un_inc(iVar3,fp);
      do {
        arg_2 = arg_2 + 1;
        iVar3 = _isspace((uint)*arg_2);
      } while (iVar3 != 0);
    }
    if (*arg_2 == 0x25) {
      local_44 = 0;
      local_c = 0;
      local_70 = 0;
      local_1ec = 0;
      local_20 = 0;
      local_14 = 0;
      local_6c = '\0';
      local_74 = '\0';
      local_1c = '\0';
      local_68 = '\0';
      local_18 = '\0';
      local_3c = '\x01';
      local_1e0 = 0;
LAB_004e3fce:
      if (local_1c == '\0') {
        pbVar1 = arg_2 + 1;
        local_10 = (uint)*pbVar1;
        if ((int)DAT_005096ac < 2) {
          local_200 = *(ushort *)(PTR_DAT_005094a0 + local_10 * 2) & 4;
        }
        else {
          local_200 = __isctype(local_10,4);
        }
        if (local_200 == 0) {
          switch(local_10) {
          case 0x2a:
            local_74 = local_74 + '\x01';
            arg_2 = pbVar1;
            break;
          case 0x46:
          case 0x4e:
            arg_2 = pbVar1;
            break;
          case 0x49:
            if ((arg_2[2] == 0x36) && (arg_2[3] == 0x34)) {
              local_1e0 = local_1e0 + 1;
              local_34 = 0;
              local_30 = 0;
              arg_2 = arg_2 + 3;
              break;
            }
          default:
            local_1c = local_1c + '\x01';
            arg_2 = pbVar1;
            break;
          case 0x4c:
            local_3c = local_3c + '\x01';
            arg_2 = pbVar1;
            break;
          case 0x68:
            local_3c = local_3c + -1;
            local_18 = local_18 + -1;
            arg_2 = pbVar1;
            break;
          case 0x6c:
            local_3c = local_3c + '\x01';
          case 0x77:
            local_18 = local_18 + '\x01';
            arg_2 = pbVar1;
          }
        }
        else {
          local_1ec = local_1ec + 1;
          local_20 = (local_10 - 0x30) + local_20 * 10;
          arg_2 = pbVar1;
        }
        goto LAB_004e3fce;
      }
      if (local_74 == '\0') {
        local_1d8 = arg_3;
        local_40 = (wchar_t *)*arg_3;
        arg_3 = arg_3 + 1;
      }
      local_1c = '\0';
      if (local_18 == '\0') {
        if ((*arg_2 == 0x53) || (*arg_2 == 0x43)) {
          local_18 = '\x01';
        }
        else {
          local_18 = -1;
        }
      }
      local_10 = *arg_2 | 0x20;
      if (local_10 != 0x6e) {
        if ((local_10 == 99) || (local_10 == 0x7b)) {
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        else {
          local_1dc = __whiteout((int *)&local_24,(FILE *)arg_1);
        }
      }
      if ((local_1ec != 0) && (local_20 == 0)) {
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        goto LAB_004e51af;
      }
      pbVar1 = arg_2;
      switch(local_10) {
      case 99:
        if (local_1ec == 0) {
          local_1ec = 1;
          local_20 = local_20 + 1;
        }
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = &DAT_0050a420;
        local_14 = local_14 - 1;
        goto LAB_004e42ea;
      case 100:
      case 0x6f:
      case 0x75:
        goto switchD_004e5022_caseD_64;
      case 0x65:
      case 0x66:
      case 0x67:
        local_1e4 = &local_1d4;
        if (local_1dc == 0x2d) {
          local_1d4 = 0x2d;
          local_1e4 = local_1d3;
LAB_004e4c1f:
          local_20 = local_20 + -1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        else if (local_1dc == 0x2b) goto LAB_004e4c1f;
        if ((local_1ec == 0) || (0x15d < local_20)) {
          local_20 = 0x15d;
        }
        while( true ) {
          if ((int)DAT_005096ac < 2) {
            local_218 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
          }
          else {
            local_218 = __isctype(local_1dc,4);
          }
          if ((local_218 == 0) ||
             (iVar3 = local_20 + -1, bVar6 = local_20 == 0, local_20 = iVar3, bVar6)) break;
          local_70 = local_70 + 1;
          *local_1e4 = (byte)local_1dc;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        if ((DAT_005096b0 == (byte)local_1dc) &&
           (iVar3 = local_20 + -1, bVar6 = local_20 != 0, local_20 = iVar3, bVar6)) {
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          *local_1e4 = DAT_005096b0;
          local_1e4 = local_1e4 + 1;
          while( true ) {
            if ((int)DAT_005096ac < 2) {
              local_224 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
            }
            else {
              local_224 = __isctype(local_1dc,4);
            }
            if ((local_224 == 0) ||
               (iVar3 = local_20 + -1, bVar6 = local_20 == 0, local_20 = iVar3, bVar6)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        if ((local_70 != 0) &&
           (((local_1dc == 0x65 || (local_1dc == 0x45)) &&
            (iVar3 = local_20 + -1, bVar6 = local_20 != 0, local_20 = iVar3, bVar6)))) {
          *local_1e4 = 0x65;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          if (local_1dc == 0x2d) {
            *local_1e4 = 0x2d;
            local_1e4 = local_1e4 + 1;
LAB_004e4e79:
            if (local_20 != 0) {
              local_24 = local_24 + 1;
              local_20 = local_20 + -1;
              local_1dc = __inc((FILE *)arg_1);
            }
          }
          else if (local_1dc == 0x2b) goto LAB_004e4e79;
          while( true ) {
            if ((int)DAT_005096ac < 2) {
              local_234 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
            }
            else {
              local_234 = __isctype(local_1dc,4);
            }
            if ((local_234 == 0) ||
               (iVar3 = local_20 + -1, bVar6 = local_20 == 0, local_20 = iVar3, bVar6)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        if (local_70 == 0) goto LAB_004e51af;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
          *local_1e4 = 0;
          (*(code *)PTR___fptrap_0050a5b8)(local_3c + -1,local_40,&local_1d4);
        }
        break;
      default:
        if (*arg_2 != local_1dc) {
          local_24 = local_24 - 1;
          __un_inc(local_1dc,(FILE *)arg_1);
          goto LAB_004e51af;
        }
        local_2c = local_2c + -1;
        if (local_74 == '\0') {
          arg_3 = local_1d8;
        }
        break;
      case 0x69:
        local_10 = 100;
      case 0x78:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_004e4670:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_004e4670;
        if (local_1dc == 0x30) {
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          if (((byte)local_1dc == 'x') || ((byte)local_1dc == 'X')) {
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
            local_10 = 0x78;
          }
          else {
            local_70 = local_70 + 1;
            if (local_10 == 0x78) {
              local_24 = local_24 - 1;
              __un_inc(local_1dc,(FILE *)arg_1);
              local_1dc = 0x30;
            }
            else {
              local_10 = 0x6f;
            }
          }
        }
        goto LAB_004e47a2;
      case 0x6e:
        local_44 = local_24;
        if (local_74 != '\0') break;
        goto LAB_004e4b6e;
      case 0x70:
        local_3c = '\x01';
switchD_004e5022_caseD_64:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_004e476f:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_004e476f;
LAB_004e47a2:
        if (local_1e0 == 0) {
          while (local_1c == '\0') {
            if ((local_10 == 0x78) || (local_10 == 0x70)) {
              if ((int)DAT_005096ac < 2) {
                local_210 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 0x80;
              }
              else {
                local_210 = __isctype(local_1dc,0x80);
              }
              if (local_210 == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_44 = local_44 << 4;
                local_1dc = __hextodec(local_1dc);
              }
            }
            else {
              if ((int)DAT_005096ac < 2) {
                local_214 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
              }
              else {
                local_214 = __isctype(local_1dc,4);
              }
              if (local_214 == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_44 = local_44 << 3;
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                local_44 = local_44 * 10;
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              local_44 = local_44 + (local_1dc - 0x30);
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc((FILE *)arg_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 - 1;
              __un_inc(local_1dc,(FILE *)arg_1);
            }
          }
          if (local_6c != '\0') {
            local_44 = -local_44;
          }
        }
        else {
          while (local_1c == '\0') {
            if (local_10 == 0x78) {
              if ((int)DAT_005096ac < 2) {
                local_208 = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 0x80;
              }
              else {
                local_208 = __isctype(local_1dc,0x80);
              }
              if (local_208 == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_30 = local_30 << 4 | local_34 >> 0x1c;
                local_34 = local_34 << 4;
                local_1dc = __hextodec(local_1dc);
              }
            }
            else {
              if ((int)DAT_005096ac < 2) {
                local_20c = *(ushort *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
              }
              else {
                local_20c = __isctype(local_1dc,4);
              }
              if (local_20c == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_30 = local_30 << 3 | local_34 >> 0x1d;
                  local_34 = local_34 << 3;
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                local_30 = ((local_30 << 2 | local_34 >> 0x1e) + local_30 +
                           (uint)CARRY4(local_34 * 4,local_34)) * 2 | local_34 * 5 >> 0x1f;
                local_34 = local_34 * 10;
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              uVar4 = local_1dc - 0x30;
              bVar6 = CARRY4(local_34,uVar4);
              local_34 = local_34 + uVar4;
              local_30 = local_30 + ((int)uVar4 >> 0x1f) + (uint)bVar6;
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc((FILE *)arg_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 - 1;
              __un_inc(local_1dc,(FILE *)arg_1);
            }
          }
          if (local_6c != '\0') {
            bVar6 = local_34 != 0;
            local_34 = -local_34;
            local_30 = -(local_30 + bVar6);
          }
        }
        if (local_10 == 0x46) {
          local_70 = 0;
        }
        if (local_70 == 0) goto LAB_004e51af;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
LAB_004e4b6e:
          if (local_1e0 == 0) {
            if (local_3c == '\0') {
              *local_40 = (wchar_t)local_44;
            }
            else {
              *(uint *)local_40 = local_44;
            }
          }
          else {
            *(uint *)local_40 = local_34;
            *(uint *)(local_40 + 2) = local_30;
          }
        }
        break;
      case 0x73:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = (byte *)s_____0050a418;
        local_14 = local_14 - 1;
        goto LAB_004e42ea;
      case 0x7b:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        pbVar1 = arg_2 + 1;
        local_1e4 = pbVar1;
        if (*pbVar1 == 0x5e) {
          local_1e4 = arg_2 + 2;
          local_14 = local_14 - 1;
        }
LAB_004e42ea:
        arg_2 = pbVar1;
        _memset(local_64,0,0x20);
        if ((local_10 == 0x7b) && (*local_1e4 == 0x5d)) {
          local_c = 0x5d;
          local_64[0xb] = 0x20;
          local_1e4 = local_1e4 + 1;
        }
        while (*local_1e4 != 0x5d) {
          local_1f0 = *local_1e4;
          pbVar1 = local_1e4 + 1;
          if (((local_1f0 == 0x2d) && (local_c != 0)) && (*pbVar1 != 0x5d)) {
            bVar5 = *pbVar1;
            local_1e4 = local_1e4 + 2;
            if (local_c < bVar5) {
              local_28 = bVar5;
            }
            else {
              local_28 = local_c;
              local_c = bVar5;
            }
            for (local_1f0 = local_c; local_1f0 <= local_28; local_1f0 = local_1f0 + 1) {
              local_64[(int)(uint)local_1f0 >> 3] =
                   local_64[(int)(uint)local_1f0 >> 3] | (byte)(1 << (local_1f0 & 7));
            }
            local_c = 0;
          }
          else {
            local_c = local_1f0;
            local_64[(int)(uint)local_1f0 >> 3] =
                 local_64[(int)(uint)local_1f0 >> 3] | (byte)(1 << (local_1f0 & 7));
            local_1e4 = pbVar1;
          }
        }
        if (*local_1e4 == 0) goto LAB_004e51af;
        if (local_10 == 0x7b) {
          arg_2 = local_1e4;
        }
        local_1e8 = local_40;
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        while( true ) {
          if ((local_1ec != 0) &&
             (iVar3 = local_20 + -1, bVar6 = local_20 == 0, local_20 = iVar3, bVar6))
          goto LAB_004e45e7;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          if ((local_1dc == 0xffffffff) ||
             (bVar5 = (byte)local_1dc,
             (1 << (bVar5 & 7) & (int)(char)(local_64[(int)local_1dc >> 3] ^ local_14)) == 0))
          break;
          if (local_74 == '\0') {
            if (local_68 == '\0') {
              *(byte *)local_40 = bVar5;
              local_40 = (wchar_t *)((int)local_40 + 1);
            }
            else {
              local_1f4 = bVar5;
              if ((*(ushort *)(PTR_DAT_005094a0 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
                local_24 = local_24 + 1;
                local_1f3 = __inc((FILE *)arg_1);
              }
              _mbtowc(local_8,(char *)&local_1f4,DAT_005096ac);
              *local_40 = local_8[0];
              local_40 = local_40 + 1;
            }
          }
          else {
            local_1e8 = (wchar_t *)((int)local_1e8 + 1);
          }
        }
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
LAB_004e45e7:
        if (local_1e8 == local_40) goto LAB_004e51af;
        if ((local_74 == '\0') && (local_38 = local_38 + 1, local_10 != 99)) {
          if (local_68 == '\0') {
            *(byte *)local_40 = 0;
          }
          else {
            *local_40 = L'\0';
          }
        }
      }
      local_2c = local_2c + '\x01';
      pbVar1 = arg_2 + 1;
    }
    else {
      local_24 = local_24 + 1;
      local_1dc = __inc((FILE *)arg_1);
      if (*arg_2 != local_1dc) {
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        goto LAB_004e51af;
      }
      pbVar1 = arg_2 + 1;
      if ((*(ushort *)(PTR_DAT_005094a0 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
        local_24 = local_24 + 1;
        uVar4 = __inc((FILE *)arg_1);
        if (arg_2[1] == uVar4) {
          local_24 = local_24 - 1;
          pbVar1 = arg_2 + 2;
          goto LAB_004e5177;
        }
        local_24 = local_24 - 1;
        __un_inc(uVar4,(FILE *)arg_1);
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        goto LAB_004e51af;
      }
    }
LAB_004e5177:
    arg_2 = pbVar1;
    if ((local_1dc == 0xffffffff) && ((*arg_2 != 0x25 || (arg_2[1] != 0x6e)))) goto LAB_004e51af;
  } while( true );
}


