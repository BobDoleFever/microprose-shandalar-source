/*
 * input.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 6
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __input
 * Entry Point: 004e3e50
 * Size: 4808 bytes
 */


/* Library Function - Single Match
    __input
   
   Library: Visual Studio 1998 Debug */

uint32_t __input(int player_id,uint8_t *arg_2,int32_t *arg_3)

{
  uint8_t *pbVar1;
  code *char_ptr_2;
  int val_3;
  uint32_t uval_4;
  uint8_t bVar5;
  bool bVar6;
  FILE *fp;
  uint32_t local_234;
  uint32_t local_224;
  uint32_t local_218;
  uint32_t local_214;
  uint32_t local_210;
  uint32_t local_20c;
  uint32_t local_208;
  uint32_t local_200;
  uint32_t local_1fc;
  uint8_t local_1f4;
  uint8_t local_1f3;
  uint8_t local_1f0;
  int local_1ec;
  wchar_t *local_1e8;
  uint8_t *local_1e4;
  int local_1e0;
  uint32_t local_1dc;
  int32_t *local_1d8;
  uint8_t local_1d4;
  uint8_t local_1d3 [351];
  char local_74;
  int local_70;
  char local_6c;
  char local_68;
  uint8_t local_64 [32];
  uint32_t local_44;
  wchar_t *local_40;
  char local_3c;
  uint32_t local_38;
  uint32_t local_34;
  uint32_t local_30;
  char local_2c;
  uint8_t local_28;
  uint32_t local_24;
  int loop_idx;
  char color_idx;
  char target_idx;
  uint8_t player_idx;
  uint32_t card_idx;
  uint8_t match_count;
  wchar_t slot_idx [2];
  
  if ((arg_2 == (uint8_t *)0x0) &&
     (val_3 = __CrtDbgReport(2,0x4f0ea4,0x109,0,"format != NULL"), val_3 == 1)) {
    char_ptr_2 = (code *)swi(3);
    uval_4 = (*char_ptr_2)();
    return uval_4;
  }
  if ((arg_1 == 0) && (val_3 = __CrtDbgReport(2,0x4f0ea4,0x10c,0,"stream != NULL"), val_3 == 1)) {
    char_ptr_2 = (code *)swi(3);
    uval_4 = (*char_ptr_2)();
    return uval_4;
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
      local_1fc = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)*arg_2 * 2) & 8;
    }
    else {
      local_1fc = __isctype((uint32_t)*arg_2,8);
    }
    if (local_1fc != 0) {
      local_24 = local_24 - 1;
      fp = (FILE *)arg_1;
      val_3 = __whiteout((int *)&local_24,(FILE *)arg_1);
      __un_inc(val_3,fp);
      do {
        arg_2 = arg_2 + 1;
        val_3 = _isspace((uint32_t)*arg_2);
      } while (val_3 != 0);
    }
    if (*arg_2 == 0x25) {
      local_44 = 0;
      match_count = 0;
      local_70 = 0;
      local_1ec = 0;
      loop_idx = 0;
      player_idx = 0;
      local_6c = '\0';
      local_74 = '\0';
      color_idx = '\0';
      local_68 = '\0';
      target_idx = '\0';
      local_3c = '\x01';
      local_1e0 = 0;
LAB_004e3fce:
      if (color_idx == '\0') {
        pbVar1 = arg_2 + 1;
        card_idx = (uint32_t)*pbVar1;
        if ((int)DAT_005096ac < 2) {
          local_200 = *(uint16_t *)(PTR_DAT_005094a0 + card_idx * 2) & 4;
        }
        else {
          local_200 = __isctype(card_idx,4);
        }
        if (local_200 == 0) {
          switch(card_idx) {
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
            color_idx = color_idx + '\x01';
            arg_2 = pbVar1;
            break;
          case 0x4c:
            local_3c = local_3c + '\x01';
            arg_2 = pbVar1;
            break;
          case 0x68:
            local_3c = local_3c + -1;
            target_idx = target_idx + -1;
            arg_2 = pbVar1;
            break;
          case 0x6c:
            local_3c = local_3c + '\x01';
          case 0x77:
            target_idx = target_idx + '\x01';
            arg_2 = pbVar1;
          }
        }
        else {
          local_1ec = local_1ec + 1;
          loop_idx = (card_idx - 0x30) + loop_idx * 10;
          arg_2 = pbVar1;
        }
        goto LAB_004e3fce;
      }
      if (local_74 == '\0') {
        local_1d8 = arg_3;
        local_40 = (wchar_t *)*arg_3;
        arg_3 = arg_3 + 1;
      }
      color_idx = '\0';
      if (target_idx == '\0') {
        if ((*arg_2 == 0x53) || (*arg_2 == 0x43)) {
          target_idx = '\x01';
        }
        else {
          target_idx = -1;
        }
      }
      card_idx = *arg_2 | 0x20;
      if (card_idx != 0x6e) {
        if ((card_idx == 99) || (card_idx == 0x7b)) {
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        else {
          local_1dc = __whiteout((int *)&local_24,(FILE *)arg_1);
        }
      }
      if ((local_1ec != 0) && (loop_idx == 0)) {
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        goto LAB_004e51af;
      }
      pbVar1 = arg_2;
      switch(card_idx) {
      case 99:
        if (local_1ec == 0) {
          local_1ec = 1;
          loop_idx = loop_idx + 1;
        }
        if ('\0' < target_idx) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = &DAT_0050a420;
        player_idx = player_idx - 1;
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
          loop_idx = loop_idx + -1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        else if (local_1dc == 0x2b) goto LAB_004e4c1f;
        if ((local_1ec == 0) || (0x15d < loop_idx)) {
          loop_idx = 0x15d;
        }
        while( true ) {
          if ((int)DAT_005096ac < 2) {
            local_218 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
          }
          else {
            local_218 = __isctype(local_1dc,4);
          }
          if ((local_218 == 0) ||
             (val_3 = loop_idx + -1, bVar6 = loop_idx == 0, loop_idx = val_3, bVar6)) break;
          local_70 = local_70 + 1;
          *local_1e4 = (uint8_t)local_1dc;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
        }
        if ((DAT_005096b0 == (uint8_t)local_1dc) &&
           (val_3 = loop_idx + -1, bVar6 = loop_idx != 0, loop_idx = val_3, bVar6)) {
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          *local_1e4 = DAT_005096b0;
          local_1e4 = local_1e4 + 1;
          while( true ) {
            if ((int)DAT_005096ac < 2) {
              local_224 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
            }
            else {
              local_224 = __isctype(local_1dc,4);
            }
            if ((local_224 == 0) ||
               (val_3 = loop_idx + -1, bVar6 = loop_idx == 0, loop_idx = val_3, bVar6)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (uint8_t)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        if ((local_70 != 0) &&
           (((local_1dc == 0x65 || (local_1dc == 0x45)) &&
            (val_3 = loop_idx + -1, bVar6 = loop_idx != 0, loop_idx = val_3, bVar6)))) {
          *local_1e4 = 0x65;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          if (local_1dc == 0x2d) {
            *local_1e4 = 0x2d;
            local_1e4 = local_1e4 + 1;
LAB_004e4e79:
            if (loop_idx != 0) {
              local_24 = local_24 + 1;
              loop_idx = loop_idx + -1;
              local_1dc = __inc((FILE *)arg_1);
            }
          }
          else if (local_1dc == 0x2b) goto LAB_004e4e79;
          while( true ) {
            if ((int)DAT_005096ac < 2) {
              local_234 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
            }
            else {
              local_234 = __isctype(local_1dc,4);
            }
            if ((local_234 == 0) ||
               (val_3 = loop_idx + -1, bVar6 = loop_idx == 0, loop_idx = val_3, bVar6)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (uint8_t)local_1dc;
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
        card_idx = 100;
      case 0x78:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_004e4670:
          loop_idx = loop_idx + -1;
          if ((loop_idx == 0) && (local_1ec != 0)) {
            color_idx = color_idx + '\x01';
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
          if (((uint8_t)local_1dc == 'x') || ((uint8_t)local_1dc == 'X')) {
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
            card_idx = 0x78;
          }
          else {
            local_70 = local_70 + 1;
            if (card_idx == 0x78) {
              local_24 = local_24 - 1;
              __un_inc(local_1dc,(FILE *)arg_1);
              local_1dc = 0x30;
            }
            else {
              card_idx = 0x6f;
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
          loop_idx = loop_idx + -1;
          if ((loop_idx == 0) && (local_1ec != 0)) {
            color_idx = color_idx + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc((FILE *)arg_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_004e476f;
LAB_004e47a2:
        if (local_1e0 == 0) {
          while (color_idx == '\0') {
            if ((card_idx == 0x78) || (card_idx == 0x70)) {
              if ((int)DAT_005096ac < 2) {
                local_210 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 0x80;
              }
              else {
                local_210 = __isctype(local_1dc,0x80);
              }
              if (local_210 == 0) {
                color_idx = color_idx + '\x01';
              }
              else {
                local_44 = local_44 << 4;
                local_1dc = __hextodec(local_1dc);
              }
            }
            else {
              if ((int)DAT_005096ac < 2) {
                local_214 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
              }
              else {
                local_214 = __isctype(local_1dc,4);
              }
              if (local_214 == 0) {
                color_idx = color_idx + '\x01';
              }
              else if (card_idx == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_44 = local_44 << 3;
                }
                else {
                  color_idx = color_idx + '\x01';
                }
              }
              else {
                local_44 = local_44 * 10;
              }
            }
            if (color_idx == '\0') {
              local_70 = local_70 + 1;
              local_44 = local_44 + (local_1dc - 0x30);
              if ((local_1ec == 0) || (loop_idx = loop_idx + -1, loop_idx != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc((FILE *)arg_1);
              }
              else {
                color_idx = '\x01';
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
          while (color_idx == '\0') {
            if (card_idx == 0x78) {
              if ((int)DAT_005096ac < 2) {
                local_208 = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 0x80;
              }
              else {
                local_208 = __isctype(local_1dc,0x80);
              }
              if (local_208 == 0) {
                color_idx = color_idx + '\x01';
              }
              else {
                local_30 = local_30 << 4 | local_34 >> 0x1c;
                local_34 = local_34 << 4;
                local_1dc = __hextodec(local_1dc);
              }
            }
            else {
              if ((int)DAT_005096ac < 2) {
                local_20c = *(uint16_t *)(PTR_DAT_005094a0 + local_1dc * 2) & 4;
              }
              else {
                local_20c = __isctype(local_1dc,4);
              }
              if (local_20c == 0) {
                color_idx = color_idx + '\x01';
              }
              else if (card_idx == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_30 = local_30 << 3 | local_34 >> 0x1d;
                  local_34 = local_34 << 3;
                }
                else {
                  color_idx = color_idx + '\x01';
                }
              }
              else {
                local_30 = ((local_30 << 2 | local_34 >> 0x1e) + local_30 +
                           (uint32_t)CARRY4(local_34 * 4,local_34)) * 2 | local_34 * 5 >> 0x1f;
                local_34 = local_34 * 10;
              }
            }
            if (color_idx == '\0') {
              local_70 = local_70 + 1;
              uval_4 = local_1dc - 0x30;
              bVar6 = CARRY4(local_34,uval_4);
              local_34 = local_34 + uval_4;
              local_30 = local_30 + ((int)uval_4 >> 0x1f) + (uint32_t)bVar6;
              if ((local_1ec == 0) || (loop_idx = loop_idx + -1, loop_idx != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc((FILE *)arg_1);
              }
              else {
                color_idx = '\x01';
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
        if (card_idx == 0x46) {
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
              *(uint32_t *)local_40 = local_44;
            }
          }
          else {
            *(uint32_t *)local_40 = local_34;
            *(uint32_t *)(local_40 + 2) = local_30;
          }
        }
        break;
      case 0x73:
        if ('\0' < target_idx) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = (uint8_t *)s_____0050a418;
        player_idx = player_idx - 1;
        goto LAB_004e42ea;
      case 0x7b:
        if ('\0' < target_idx) {
          local_68 = local_68 + '\x01';
        }
        pbVar1 = arg_2 + 1;
        local_1e4 = pbVar1;
        if (*pbVar1 == 0x5e) {
          local_1e4 = arg_2 + 2;
          player_idx = player_idx - 1;
        }
LAB_004e42ea:
        arg_2 = pbVar1;
        _memset(local_64,0,0x20);
        if ((card_idx == 0x7b) && (*local_1e4 == 0x5d)) {
          match_count = 0x5d;
          local_64[0xb] = 0x20;
          local_1e4 = local_1e4 + 1;
        }
        while (*local_1e4 != 0x5d) {
          local_1f0 = *local_1e4;
          pbVar1 = local_1e4 + 1;
          if (((local_1f0 == 0x2d) && (match_count != 0)) && (*pbVar1 != 0x5d)) {
            bVar5 = *pbVar1;
            local_1e4 = local_1e4 + 2;
            if (match_count < bVar5) {
              local_28 = bVar5;
            }
            else {
              local_28 = match_count;
              match_count = bVar5;
            }
            for (local_1f0 = match_count; local_1f0 <= local_28; local_1f0 = local_1f0 + 1) {
              local_64[(int)(uint32_t)local_1f0 >> 3] =
                   local_64[(int)(uint32_t)local_1f0 >> 3] | (uint8_t)(1 << (local_1f0 & 7));
            }
            match_count = 0;
          }
          else {
            match_count = local_1f0;
            local_64[(int)(uint32_t)local_1f0 >> 3] =
                 local_64[(int)(uint32_t)local_1f0 >> 3] | (uint8_t)(1 << (local_1f0 & 7));
            local_1e4 = pbVar1;
          }
        }
        if (*local_1e4 == 0) goto LAB_004e51af;
        if (card_idx == 0x7b) {
          arg_2 = local_1e4;
        }
        local_1e8 = local_40;
        local_24 = local_24 - 1;
        __un_inc(local_1dc,(FILE *)arg_1);
        while( true ) {
          if ((local_1ec != 0) &&
             (val_3 = loop_idx + -1, bVar6 = loop_idx == 0, loop_idx = val_3, bVar6))
          goto LAB_004e45e7;
          local_24 = local_24 + 1;
          local_1dc = __inc((FILE *)arg_1);
          if ((local_1dc == 0xffffffff) ||
             (bVar5 = (uint8_t)local_1dc,
             (1 << (bVar5 & 7) & (int)(char)(local_64[(int)local_1dc >> 3] ^ player_idx)) == 0))
          break;
          if (local_74 == '\0') {
            if (local_68 == '\0') {
              *(uint8_t *)local_40 = bVar5;
              local_40 = (wchar_t *)((int)local_40 + 1);
            }
            else {
              local_1f4 = bVar5;
              if ((*(uint16_t *)(PTR_DAT_005094a0 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
                local_24 = local_24 + 1;
                local_1f3 = __inc((FILE *)arg_1);
              }
              _mbtowc(slot_idx,(char *)&local_1f4,DAT_005096ac);
              *local_40 = slot_idx[0];
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
        if ((local_74 == '\0') && (local_38 = local_38 + 1, card_idx != 99)) {
          if (local_68 == '\0') {
            *(uint8_t *)local_40 = 0;
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
      if ((*(uint16_t *)(PTR_DAT_005094a0 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
        local_24 = local_24 + 1;
        uval_4 = __inc((FILE *)arg_1);
        if (arg_2[1] == uval_4) {
          local_24 = local_24 - 1;
          pbVar1 = arg_2 + 2;
          goto LAB_004e5177;
        }
        local_24 = local_24 - 1;
        __un_inc(uval_4,(FILE *)arg_1);
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



/*
 * Decompiled function: __hextodec
 * Entry Point: 004e5200
 * Size: 102 bytes
 */


/* Library Function - Single Match
    __hextodec
   
   Library: Visual Studio 1998 Debug */

uint32_t __hextodec(uint32_t arg_1)

{
  uint32_t slot_idx;
  
  if (DAT_005096ac < 2) {
    slot_idx = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 4;
  }
  else {
    slot_idx = __isctype(arg_1,4);
  }
  if (slot_idx == 0) {
    arg_1 = (arg_1 & 0xffffffdf) - 7;
  }
  return arg_1;
}



/*
 * Decompiled function: __inc
 * Entry Point: 004e5270
 * Size: 79 bytes
 */


/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 1998 Debug */

uint32_t __inc(FILE *fp)

{
  uint8_t *pbVar1;
  uint32_t uval_2;
  
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    uval_2 = __filbuf(fp);
  }
  else {
    pbVar1 = (uint8_t *)fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
    uval_2 = (uint32_t)*pbVar1;
  }
  return uval_2;
}



/*
 * Decompiled function: __un_inc
 * Entry Point: 004e52c0
 * Size: 37 bytes
 */


/* Library Function - Single Match
    __un_inc
   
   Library: Visual Studio 1998 Debug */

void __un_inc(int arg1,FILE *fp)

{
  if (arg1 != -1) {
    _ungetc(arg1,fp);
  }
  return;
}



/*
 * Decompiled function: __whiteout
 * Entry Point: 004e52f0
 * Size: 67 bytes
 */


/* Library Function - Single Match
    __whiteout
   
   Library: Visual Studio 1998 Debug */

int __whiteout(int *arg1,FILE *fp)

{
  int player_id;
  int val_1;
  
  do {
    *arg1 = *arg1 + 1;
    arg_1 = __inc(fp);
    val_1 = _isspace(arg_1);
  } while (val_1 != 0);
  return arg_1;
}



/*
 * Decompiled function: __dosmaperr
 * Entry Point: 004e5340
 * Size: 177 bytes
 */


/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Debug */

void __cdecl __dosmaperr(uint32_t arg_1)

{
  uint32_t slot_idx;
  
  DAT_00509424 = arg_1;
  slot_idx = 0;
  while( true ) {
    if (0x2c < slot_idx) {
      if ((arg_1 < 0x13) || (0x24 < arg_1)) {
        if ((arg_1 < 0xbc) || (0xca < arg_1)) {
          DAT_00509420 = 0x16;
        }
        else {
          DAT_00509420 = 8;
        }
      }
      else {
        DAT_00509420 = 0xd;
      }
      return;
    }
    if (*(uint32_t *)(&DAT_0050a428 + slot_idx * 8) == arg_1) break;
    slot_idx = slot_idx + 1;
  }
  DAT_00509420 = *(int32_t *)(&DAT_0050a42c + slot_idx * 8);
  return;
}



