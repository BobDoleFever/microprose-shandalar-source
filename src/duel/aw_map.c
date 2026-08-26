/*
 * aw_map.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___crtLCMapStringW
 * Entry Point: 004ebab0
 * Size: 760 bytes
 */


/* Library Function - Single Match
    ___crtLCMapStringW
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPWSTR arg_5,int arg_6)

{
  int reg_eax;
  int val_1;
  LPCSTR lpMultiByteStr;
  int val_2;
  UINT stack_arg;
  size_t player_idx;
  char *card_idx;
  
  if (DAT_0050a8d8 == 0) {
    reg_eax = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (reg_eax == 0) {
      reg_eax = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (reg_eax == 0) {
        return 0;
      }
      DAT_0050a8d8 = 2;
    }
    else {
      DAT_0050a8d8 = 1;
    }
  }
  if (0 < arg_4) {
    reg_eax = wcsncnt(arg_3,arg_4);
    arg_4 = reg_eax;
  }
  if (DAT_0050a8d8 == 1) {
    val_1 = LCMapStringW((LCID)arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
    return val_1;
  }
  if (DAT_0050a8d8 != 2) {
    return reg_eax;
  }
  card_idx = (char *)0x0;
  if (stack_arg == 0) {
    stack_arg = DAT_0050a740;
  }
  val_1 = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,(LPSTR)0x0,0,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if (val_1 == 0) {
    return 0;
  }
  lpMultiByteStr = (LPCSTR)__malloc_dbg(val_1,2,"aw_map.c",0xcc);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    return 0;
  }
  val_2 = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,lpMultiByteStr,val_1,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if ((((val_2 == 0) ||
       (player_idx = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,val_1,(LPSTR)0x0,0), player_idx == 0)
       ) || (card_idx = (char *)__malloc_dbg(player_idx,2,"aw_map.c",0xdb), card_idx == (char *)0x0))
     || (val_1 = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,val_1,card_idx,player_idx), val_1 == 0)
     ) {
LAB_004ebd80:
    __free_dbg(lpMultiByteStr,2);
    __free_dbg(card_idx,2);
    player_idx = 0;
  }
  else {
    if ((arg_2 & 0x400) == 0) {
      if (arg_6 == 0) {
        player_idx = MultiByteToWideChar(stack_arg,1,card_idx,player_idx,(LPWSTR)0x0,0);
      }
      else {
        player_idx = MultiByteToWideChar(stack_arg,1,card_idx,player_idx,arg_5,arg_6);
      }
      if (player_idx == 0) goto LAB_004ebd80;
    }
    else if (arg_6 != 0) {
      if ((int)player_idx <= arg_6) {
        arg_6 = player_idx;
      }
      _strncpy((char *)arg_5,card_idx,arg_6);
    }
    __free_dbg(lpMultiByteStr,2);
    __free_dbg(card_idx,2);
  }
  return player_idx;
}



/*
 * Decompiled function: wcsncnt
 * Entry Point: 004ebdb0
 * Size: 108 bytes
 */


/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Debug */

int __cdecl wcsncnt(short *arg1,int arg2)

{
  int match_count;
  short *slot_idx;
  
  match_count = arg2;
  for (slot_idx = arg1; (match_count != 0 && (*slot_idx != 0)); slot_idx = slot_idx + 1) {
    match_count = match_count + -1;
  }
  if (*slot_idx == 0) {
    arg2 = (int)slot_idx - (int)arg1 >> 1;
  }
  return arg2;
}



/*
 * Decompiled function: ___crtLCMapStringA
 * Entry Point: 004ebe20
 * Size: 791 bytes
 */


/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringA(_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPSTR arg_6,
                  int arg_7,int arg_8,BOOL arg_9)

{
  LPCSTR reg_eax;
  int val_1;
  LPCWSTR lpWideCharStr;
  int val_2;
  int player_idx;
  LPCWSTR match_count;
  
  if (DAT_0050a8dc == 0) {
    reg_eax = (LPCSTR)LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (reg_eax == (LPCSTR)0x0) {
      reg_eax = (LPCSTR)LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (reg_eax == (LPCSTR)0x0) {
        return 0;
      }
      DAT_0050a8dc = 1;
    }
    else {
      DAT_0050a8dc = 2;
    }
  }
  if (0 < (int)arg_4) {
    reg_eax = (LPCSTR)_strncnt((char *)arg_3,(size_t)arg_4);
    arg_4 = reg_eax;
  }
  if (DAT_0050a8dc == 2) {
    val_1 = LCMapStringA((LCID)arg_1,(DWORD)arg_2,(LPCSTR)arg_3,(int)arg_4,(LPSTR)arg_5,(int)arg_6);
    return val_1;
  }
  if (DAT_0050a8dc != 1) {
    return (int)reg_eax;
  }
  match_count = (LPCWSTR)0x0;
  if (arg_7 == 0) {
    arg_7 = DAT_0050a740;
  }
  val_1 = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_3,(int)arg_4,(LPWSTR)0x0,0);
  if (val_1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)__malloc_dbg(val_1 * 2,2,"aw_map.c",0x16d);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  val_2 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_3,(int)arg_4,lpWideCharStr,val_1);
  if ((val_2 != 0) &&
     (player_idx = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,(LPWSTR)0x0,0),
     player_idx != 0)) {
    if (((uint32_t)arg_2 & 0x400) == 0) {
      match_count = (LPCWSTR)__malloc_dbg(player_idx * 2,2,"aw_map.c",0x191);
      if ((match_count == (LPCWSTR)0x0) ||
         (val_1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,match_count,player_idx),
         val_1 == 0)) goto LAB_004ec10f;
      if (arg_6 == (LPSTR)0x0) {
        player_idx = WideCharToMultiByte(arg_7,0x220,match_count,player_idx,(LPSTR)0x0,0,(LPCSTR)0x0,
                                       (LPBOOL)0x0);
        val_1 = player_idx;
      }
      else {
        player_idx = WideCharToMultiByte(arg_7,0x220,match_count,player_idx,(LPSTR)arg_5,(int)arg_6,
                                       (LPCSTR)0x0,(LPBOOL)0x0);
        val_1 = player_idx;
      }
    }
    else {
      if (arg_6 == (LPSTR)0x0) goto LAB_004ec0eb;
      if ((int)arg_6 < player_idx) goto LAB_004ec10f;
      val_1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,(LPWSTR)arg_5,(int)arg_6);
    }
    if (val_1 != 0) {
LAB_004ec0eb:
      __free_dbg(lpWideCharStr,2);
      __free_dbg(match_count,2);
      return player_idx;
    }
  }
LAB_004ec10f:
  __free_dbg(lpWideCharStr,2);
  __free_dbg(match_count,2);
  return 0;
}



/*
 * Decompiled function: _strncnt
 * Entry Point: 004ec140
 * Size: 100 bytes
 */


/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _strncnt(char *filepath,size_t arg_2)

{
  size_t match_count;
  char *slot_idx;
  
  match_count = arg_2;
  for (slot_idx = str_1; (match_count != 0 && (*slot_idx != '\0')); slot_idx = slot_idx + 1) {
    match_count = match_count - 1;
  }
  if (*slot_idx == '\0') {
    arg_2 = (int)slot_idx - (int)str_1;
  }
  return arg_2;
}



/*
 * Decompiled function: ___addl
 * Entry Point: 004ec1b0
 * Size: 73 bytes
 */


/* Library Function - Single Match
    ___addl
   
   Library: Visual Studio 1998 Debug */

int32_t ___addl(uint32_t arg_1,uint32_t arg_2,uint32_t *arg_3)

{
  uint32_t uval_1;
  int32_t match_count;
  
  match_count = 0;
  uval_1 = arg_2 + arg_1;
  if ((uval_1 < arg_1) || (uval_1 < arg_2)) {
    match_count = 1;
  }
  *arg_3 = uval_1;
  return match_count;
}



/*
 * Decompiled function: ___add_12
 * Entry Point: 004ec200
 * Size: 171 bytes
 */


/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 1998 Debug */

void ___add_12(uint32_t *arg1,uint32_t *arg2)

{
  int val_1;
  
  val_1 = ___addl(*arg1,*arg2,arg1);
  if (val_1 != 0) {
    val_1 = ___addl(arg1[1],1,arg1 + 1);
    if (val_1 != 0) {
      arg1[2] = arg1[2] + 1;
    }
  }
  val_1 = ___addl(arg1[1],arg2[1],arg1 + 1);
  if (val_1 != 0) {
    arg1[2] = arg1[2] + 1;
  }
  ___addl(arg1[2],arg2[2],arg1 + 2);
  return;
}



/*
 * Decompiled function: ___shl_12
 * Entry Point: 004ec2b0
 * Size: 118 bytes
 */


/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 1998 Debug */

void ___shl_12(int *arg_1)

{
  uint32_t match_count;
  uint32_t slot_idx;
  
  slot_idx = (uint32_t)((int)(*arg_1 & -0x80000000) != 0);
  match_count = (uint32_t)((*(uint8_t *)((int)arg_1 + 7) & 0x80) != 0);
  *arg_1 = *arg_1 << 1;
  arg_1[1] = arg_1[1] * 2 | slot_idx;
  arg_1[2] = arg_1[2] * 2 | match_count;
  return;
}



/*
 * Decompiled function: ___shr_12
 * Entry Point: 004ec330
 * Size: 119 bytes
 */


/* Library Function - Single Match
    ___shr_12
   
   Library: Visual Studio 1998 Debug */

void ___shr_12(uint32_t *arg_1)

{
  uint32_t match_count;
  uint32_t slot_idx;
  
  if ((arg_1[2] & 1) == 0) {
    match_count = 0;
  }
  else {
    match_count = 0x80000000;
  }
  if ((arg_1[1] & 1) == 0) {
    slot_idx = 0;
  }
  else {
    slot_idx = 0x80000000;
  }
  arg_1[2] = arg_1[2] >> 1;
  arg_1[1] = arg_1[1] >> 1 | match_count;
  *arg_1 = *arg_1 >> 1 | slot_idx;
  return;
}



/*
 * Decompiled function: ___mtold12
 * Entry Point: 004ec3b0
 * Size: 312 bytes
 */


/* Library Function - Single Match
    ___mtold12
   
   Library: Visual Studio 1998 Debug */

void ___mtold12(char *filepath,int card_slot,uint32_t *arg_3)

{
  short player_idx;
  uint32_t card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  player_idx = 0x404e;
  *arg_3 = 0;
  arg_3[1] = 0;
  arg_3[2] = 0;
  for (; arg_2 != 0; arg_2 = arg_2 + -1) {
    card_idx = *arg_3;
    match_count = arg_3[1];
    slot_idx = arg_3[2];
    ___shl_12((int *)arg_3);
    ___shl_12((int *)arg_3);
    ___add_12(arg_3,&card_idx);
    ___shl_12((int *)arg_3);
    card_idx = (uint32_t)*str_1;
    match_count = 0;
    slot_idx = 0;
    ___add_12(arg_3,&card_idx);
    str_1 = str_1 + 1;
  }
  while (arg_3[2] == 0) {
    arg_3[2] = arg_3[1] >> 0x10;
    arg_3[1] = arg_3[1] << 0x10 | *arg_3 >> 0x10;
    *arg_3 = *arg_3 << 0x10;
    player_idx = player_idx + -0x10;
  }
  while ((*(uint8_t *)((int)arg_3 + 9) & 0x80) == 0) {
    ___shl_12((int *)arg_3);
    player_idx = player_idx + -1;
  }
  *(short *)((int)arg_3 + 10) = player_idx;
  return;
}



/*
 * Decompiled function: ___strgtold12
 * Entry Point: 004ec4f0
 * Size: 2795 bytes
 */


/* Library Function - Single Match
    ___strgtold12
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl
___strgtold12(_LDBL12 *ptr_1,char **str_2,char *str_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  uint8_t *pbVar1;
  bool flag_2;
  uint32_t local_94;
  uint32_t local_90;
  uint32_t local_8c;
  uint32_t local_88;
  uint32_t local_84;
  int local_80;
  int local_78;
  uint32_t local_74;
  int local_70;
  char *local_6c;
  uint8_t *local_68;
  int16_t local_64;
  int32_t local_62;
  int32_t local_5e;
  uint16_t local_5a;
  int local_58;
  uint16_t local_54;
  int local_50;
  int16_t local_4c;
  uint32_t local_48;
  int local_44;
  uint8_t local_40;
  char local_3c [23];
  char local_25;
  int32_t loop_idx;
  int color_idx;
  uint32_t target_idx;
  int32_t player_idx;
  int card_idx;
  int32_t match_count;
  uint8_t *slot_idx;
  
  local_6c = local_3c;
  loop_idx = loop_idx & 0xffff0000;
  local_78 = 1;
  local_74 = 0;
  local_58 = 0;
  card_idx = 0;
  color_idx = 0;
  local_44 = 0;
  flag_2 = false;
  target_idx = 0;
  local_70 = 0;
  local_48 = 0;
  local_50 = 0;
  local_68 = (uint8_t *)str_3;
  for (slot_idx = (uint8_t *)str_3;
      (((*slot_idx == 0x20 || (*slot_idx == 9)) || (*slot_idx == 10)) || (*slot_idx == 0xd));
      slot_idx = slot_idx + 1) {
  }
  do {
    if (local_50 == 10) {
      *str_2 = (char *)slot_idx;
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
          player_idx = 0;
          match_count = 0;
        }
        else {
          while (local_6c = local_6c + -1, *local_6c == '\0') {
            local_74 = local_74 - 1;
            local_70 = local_70 + 1;
          }
          ___mtold12(local_3c,local_74,(uint32_t *)&local_64);
          if (local_78 < 0) {
            target_idx = -target_idx;
          }
          target_idx = target_idx + local_70;
          if (color_idx == 0) {
            target_idx = target_idx + arg_5;
          }
          if (card_idx == 0) {
            target_idx = target_idx - arg_6;
          }
          if ((int)target_idx < 0x1451) {
            if ((int)target_idx < -0x1450) {
              flag_2 = true;
            }
            else {
              ___multtenpow12((int *)&local_64,target_idx,arg_4);
              local_4c = local_64;
              match_count = local_62;
              player_idx = local_5e;
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
        player_idx = 0;
        match_count = 0;
        local_48 = local_48 | 4;
      }
      else if (local_44 == 0) {
        if (flag_2) {
          local_4c = 0;
          local_54 = 0;
          player_idx = 0;
          match_count = 0;
          local_48 = local_48 | 1;
        }
      }
      else {
        local_54 = 0x7fff;
        player_idx = 0x80000000;
        match_count = 0;
        local_4c = 0;
        local_48 = local_48 | 2;
      }
      *(int16_t *)ptr_1->ld12 = local_4c;
      *(int32_t *)(ptr_1->ld12 + 2) = match_count;
      *(int32_t *)(ptr_1->ld12 + 6) = player_idx;
      *(uint16_t *)(ptr_1->ld12 + 10) = (uint16_t)loop_idx | local_54;
      return local_48;
    }
    local_40 = *slot_idx;
    pbVar1 = slot_idx + 1;
    switch(local_50) {
    case 0:
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (DAT_005096b0 == local_40) {
          local_50 = 5;
        }
        else if (local_40 == 0x2b) {
          local_50 = 2;
          loop_idx = (uint32_t)loop_idx._2_2_ << 0x10;
        }
        else if (local_40 == 0x2d) {
          local_50 = 2;
          loop_idx = CONCAT22(loop_idx._2_2_,0x8000);
        }
        else if (local_40 == 0x30) {
          local_50 = 1;
        }
        else {
          local_50 = 10;
          pbVar1 = slot_idx;
        }
      }
      else {
        local_50 = 3;
        pbVar1 = slot_idx;
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
            pbVar1 = slot_idx;
            break;
          default:
            local_50 = 10;
            pbVar1 = slot_idx;
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
        pbVar1 = slot_idx;
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
          slot_idx = local_68;
          pbVar1 = slot_idx;
        }
      }
      else {
        local_50 = 3;
        pbVar1 = slot_idx;
      }
      break;
    case 3:
      local_58 = 1;
      slot_idx = pbVar1;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_84 = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)local_40 * 2) & 4;
        }
        else {
          local_84 = __isctype((uint32_t)local_40,4);
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
        local_40 = *slot_idx;
        slot_idx = slot_idx + 1;
      }
      pbVar1 = slot_idx;
      if (DAT_005096b0 == local_40) {
        local_50 = 4;
      }
      else {
        switch(local_40) {
        case 0x2b:
        case 0x2d:
          local_50 = 0xb;
          pbVar1 = slot_idx + -1;
          break;
        default:
          local_50 = 10;
          pbVar1 = slot_idx + -1;
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
      card_idx = 1;
      slot_idx = pbVar1;
      if (local_74 == 0) {
        while (local_40 == 0x30) {
          local_70 = local_70 + -1;
          local_40 = *slot_idx;
          slot_idx = slot_idx + 1;
        }
      }
      while( true ) {
        if (DAT_005096ac < 2) {
          local_88 = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)local_40 * 2) & 4;
        }
        else {
          local_88 = __isctype((uint32_t)local_40,4);
        }
        if (local_88 == 0) break;
        if (local_74 < 0x19) {
          local_74 = local_74 + 1;
          *local_6c = local_40 - 0x30;
          local_6c = local_6c + 1;
          local_70 = local_70 + -1;
        }
        local_40 = *slot_idx;
        slot_idx = slot_idx + 1;
      }
      switch(local_40) {
      case 0x2b:
      case 0x2d:
        local_50 = 0xb;
        pbVar1 = slot_idx + -1;
        break;
      default:
        local_50 = 10;
        pbVar1 = slot_idx + -1;
        break;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        local_50 = 6;
        pbVar1 = slot_idx;
      }
      break;
    case 5:
      card_idx = 1;
      if (DAT_005096ac < 2) {
        local_8c = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)local_40 * 2) & 4;
        slot_idx = pbVar1;
      }
      else {
        slot_idx = pbVar1;
        local_8c = __isctype((uint32_t)local_40,4);
      }
      if (local_8c == 0) {
        local_50 = 10;
        slot_idx = local_68;
        pbVar1 = slot_idx;
      }
      else {
        local_50 = 4;
        pbVar1 = slot_idx + -1;
      }
      break;
    case 6:
      local_68 = slot_idx + -1;
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
        pbVar1 = slot_idx;
      }
      break;
    case 7:
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        if (local_40 == 0x30) {
          local_50 = 8;
        }
        else {
          local_50 = 10;
          slot_idx = local_68;
          pbVar1 = slot_idx;
        }
      }
      else {
        local_50 = 9;
        pbVar1 = slot_idx;
      }
      break;
    case 8:
      color_idx = 1;
      slot_idx = pbVar1;
      while (local_40 == 0x30) {
        local_40 = *slot_idx;
        slot_idx = slot_idx + 1;
      }
      if (((char)local_40 < '1') || ('9' < (char)local_40)) {
        local_50 = 10;
      }
      else {
        local_50 = 9;
      }
      slot_idx = slot_idx + -1;
      pbVar1 = slot_idx;
      break;
    case 9:
      color_idx = 1;
      local_80 = 0;
      slot_idx = pbVar1;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_90 = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)local_40 * 2) & 4;
        }
        else {
          local_90 = __isctype((uint32_t)local_40,4);
        }
        if (local_90 == 0) goto LAB_004ecd9b;
        local_80 = (char)local_40 + -0x30 + local_80 * 10;
        if (0x1450 < local_80) break;
        local_40 = *slot_idx;
        slot_idx = slot_idx + 1;
      }
      local_80 = 0x1451;
LAB_004ecd9b:
      target_idx = local_80;
      while( true ) {
        if (DAT_005096ac < 2) {
          local_94 = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)local_40 * 2) & 4;
        }
        else {
          local_94 = __isctype((uint32_t)local_40,4);
        }
        if (local_94 == 0) break;
        local_40 = *slot_idx;
        slot_idx = slot_idx + 1;
      }
      local_50 = 10;
      pbVar1 = slot_idx + -1;
      break;
    case 0xb:
      if (arg_7 == 0) {
        local_50 = 10;
        pbVar1 = slot_idx;
      }
      else {
        local_68 = slot_idx;
        if (local_40 == 0x2b) {
          local_50 = 7;
        }
        else if (local_40 == 0x2d) {
          local_50 = 7;
          local_78 = -1;
        }
        else {
          local_50 = 10;
          pbVar1 = slot_idx;
        }
      }
    }
    slot_idx = pbVar1;
  } while( true );
}



/*
 * Decompiled function: ___STRINGTOLD
 * Entry Point: 004ed110
 * Size: 88 bytes
 */


/* Library Function - Single Match
    ___STRINGTOLD
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl ___STRINGTOLD(_LDOUBLE *x,char **y,char *width,int height)

{
  INTRNCVT_STATUS IVar1;
  uint32_t target_idx;
  _LDBL12 card_idx;
  
  target_idx = ___strgtold12(&card_idx,y,width,height,0,0,0);
  IVar1 = __ld12told(&card_idx,x);
  if (IVar1 == INTRNCVT_OVERFLOW) {
    target_idx = target_idx | 2;
  }
  return target_idx;
}



/*
 * Decompiled function: $I10_OUTPUT
 * Entry Point: 004ed170
 * Size: 1335 bytes
 */


/* Library Function - Single Match
    _$I10_OUTPUT
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl _I10_OUTPUT(int player_id,uint32_t arg_2,uint16_t arg_3,int arg_4,uint8_t arg_5,short *arg_6)

{
  char *char_ptr_1;
  int val_2;
  uint32_t uval_3;
  uint16_t uval_4;
  uint32_t local_78;
  short local_60;
  int32_t local_5c;
  uint8_t local_58;
  uint8_t local_57;
  uint8_t local_56;
  uint8_t local_55;
  uint8_t local_54;
  uint8_t local_53;
  uint8_t local_52;
  uint8_t local_51;
  uint8_t local_50;
  uint8_t local_4f;
  uint8_t local_4e;
  uint8_t local_4d;
  int local_4c;
  int local_48;
  uint16_t local_44;
  int16_t uStack_42;
  int16_t local_40;
  int16_t uStack_3e;
  int16_t local_3c;
  int32_t uStack_3a;
  int32_t uStack_36;
  uint8_t local_32;
  char cStack_31;
  int local_30;
  uint32_t local_28;
  int32_t local_24;
  uint32_t loop_idx;
  int32_t color_idx;
  int32_t target_idx;
  int player_idx;
  uint16_t card_idx;
  int match_count;
  short *slot_idx;
  
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
    *(uint8_t *)(arg_6 + 1) = 0x20;
  }
  else {
    *(uint8_t *)(arg_6 + 1) = 0x2d;
  }
  if ((((arg_3 & 0x7fff) == 0) && (arg_2 == 0)) && (arg_1 == 0)) {
    *arg_6 = 0;
    *(uint8_t *)(arg_6 + 1) = 0x20;
    *(uint8_t *)((int)arg_6 + 3) = 1;
    *(uint8_t *)(arg_6 + 2) = 0x30;
    *(uint8_t *)((int)arg_6 + 5) = 0;
    local_5c = 1;
  }
  else if ((arg_3 & 0x7fff) == 0x7fff) {
    *arg_6 = 1;
    if (((arg_2 == 0x80000000) && (arg_1 == 0)) || ((arg_2 & 0x40000000) != 0)) {
      if ((((arg_3 & 0x8000) == 0) || (arg_2 != 0xc0000000)) || (arg_1 != 0)) {
        if ((arg_2 == 0x80000000) && (arg_1 == 0)) {
          Mem_AllocOrFree_004d9630((uint32_t *)(arg_6 + 2),(uint32_t *)"1#INF");
          *(uint8_t *)((int)arg_6 + 3) = 5;
        }
        else {
          Mem_AllocOrFree_004d9630((uint32_t *)(arg_6 + 2),(uint32_t *)"1#QNAN");
          *(uint8_t *)((int)arg_6 + 3) = 6;
        }
      }
      else {
        Mem_AllocOrFree_004d9630((uint32_t *)(arg_6 + 2),(uint32_t *)"1#IND");
        *(uint8_t *)((int)arg_6 + 3) = 5;
      }
    }
    else {
      Mem_AllocOrFree_004d9630((uint32_t *)(arg_6 + 2),(uint32_t *)"1#SNAN");
      *(uint8_t *)((int)arg_6 + 3) = 6;
    }
    local_5c = 0;
  }
  else {
    card_idx = arg_3 & 0xff;
    uval_4 = (uint16_t)(uint8_t)(arg_2 >> 0x18);
    _local_44 = CONCAT22(uStack_42,uval_4);
    match_count = (arg_3 & 0x7fff) * 0x4d10 + (uint32_t)uval_4 * 0x9a + (uint32_t)(arg_3 >> 8 & 0x7f) * 0x4d +
              -0x134312f4;
    local_60 = (short)((uint32_t)match_count >> 0x10);
    local_32 = (uint8_t)(arg_3 & 0x7fff);
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
          ___shr_12((uint32_t *)&local_3c);
        }
      }
      slot_idx = arg_6 + 2;
      player_idx = arg_4 + 1;
      val_2 = uStack_3a;
      uval_3 = uStack_36;
      while( true ) {
        uStack_36._2_2_ = (int16_t)(uval_3 >> 0x10);
        uStack_36._0_2_ = (int16_t)uval_3;
        uStack_3a._2_2_ = (int16_t)((uint32_t)val_2 >> 0x10);
        uStack_3a._0_2_ = (int16_t)val_2;
        if (player_idx < 1) break;
        loop_idx = CONCAT22((int16_t)uStack_3a,local_3c);
        color_idx = CONCAT22((int16_t)uStack_36,uStack_3a._2_2_);
        target_idx = CONCAT13(cStack_31,CONCAT12(local_32,uStack_36._2_2_));
        uStack_3a = val_2;
        uStack_36 = uval_3;
        ___shl_12((int *)&local_3c);
        ___shl_12((int *)&local_3c);
        ___add_12((uint32_t *)&local_3c,&loop_idx);
        ___shl_12((int *)&local_3c);
        *(char *)slot_idx = cStack_31 + '0';
        slot_idx = (short *)((int)slot_idx + 1);
        cStack_31 = '\0';
        player_idx = player_idx + -1;
        val_2 = uStack_3a;
        uval_3 = uStack_36;
      }
      char_ptr_1 = (char *)((int)slot_idx + -1);
      slot_idx = slot_idx + -1;
      if (*char_ptr_1 < '5') {
        for (; (arg_6 + 2 <= slot_idx && ((char)*slot_idx == '0'));
            slot_idx = (short *)((int)slot_idx + -1)) {
        }
        if (slot_idx < arg_6 + 2) {
          *arg_6 = 0;
          *(uint8_t *)(arg_6 + 1) = 0x20;
          *(uint8_t *)((int)arg_6 + 3) = 1;
          *(uint8_t *)(arg_6 + 2) = 0x30;
          *(uint8_t *)((int)arg_6 + 5) = 0;
          return 1;
        }
      }
      else {
        for (; (arg_6 + 2 <= slot_idx && ((char)*slot_idx == '9'));
            slot_idx = (short *)((int)slot_idx + -1)) {
          *(char *)slot_idx = '0';
        }
        if (slot_idx < arg_6 + 2) {
          slot_idx = (short *)((int)slot_idx + 1);
          *arg_6 = *arg_6 + 1;
        }
        *(char *)slot_idx = (char)*slot_idx + '\x01';
      }
      *(char *)((int)arg_6 + 3) = ((char)slot_idx - ((char)arg_6 + '\x04')) + '\x01';
      *(uint8_t *)(*(char *)((int)arg_6 + 3) + 4 + (int)arg_6) = 0;
    }
    else {
      *arg_6 = 0;
      *(uint8_t *)(arg_6 + 1) = 0x20;
      *(uint8_t *)((int)arg_6 + 3) = 1;
      *(uint8_t *)(arg_6 + 2) = 0x30;
      *(uint8_t *)((int)arg_6 + 5) = 0;
      local_5c = 1;
    }
  }
  return local_5c;
}



/*
 * Decompiled function: __mbsnbicoll
 * Entry Point: 004ed6b0
 * Size: 103 bytes
 */


/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 1998 Debug */

int __cdecl __mbsnbicoll(uchar *str_1,uchar *str_2,size_t arg_3)

{
  int val_1;
  int unaff_EDI;
  
  if (arg_3 == 0) {
    val_1 = 0;
  }
  else {
    val_1 = ___crtCompareStringA
                      (DAT_0050a308,(LPCWSTR)0x1,(DWORD)str_1,(LPCSTR)arg_3,(int)str_2,(LPCSTR)arg_3
                       ,DAT_0050a304,unaff_EDI);
    if (val_1 == 0) {
      val_1 = 0x7fffffff;
    }
    else {
      val_1 = val_1 + -2;
    }
  }
  return val_1;
}



