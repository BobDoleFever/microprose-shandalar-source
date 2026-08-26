/*
 * wcstombs.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _wcstombs
 * Entry Point: 004eb5f0
 * Size: 829 bytes
 */


/* Library Function - Single Match
    _wcstombs
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _wcstombs(char *filepath,wchar_t *str_2,size_t arg_3)

{
  code *char_ptr_1;
  int val_2;
  size_t len_3;
  DWORD DVar4;
  BOOL target_idx;
  int player_idx;
  CHAR card_idx [4];
  int match_count;
  uint32_t slot_idx;
  
  slot_idx = 0;
  target_idx = 0;
  if ((str_1 == (char *)0x0) || (arg_3 != 0)) {
    if ((str_2 == (wchar_t *)0x0) &&
       (val_2 = __CrtDbgReport(2,0x4f12bc,0x7a,0,"pwcs != NULL"), val_2 == 1)) {
      char_ptr_1 = (code *)swi(3);
      len_3 = (*char_ptr_1)();
      return len_3;
    }
    if (str_1 == (char *)0x0) {
      if (DAT_0050a730 == 0) {
        slot_idx = _wcslen(str_2);
      }
      else {
        val_2 = WideCharToMultiByte(DAT_0050a740,0x220,str_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,&target_idx);
        if ((val_2 == 0) || (target_idx != 0)) {
          DAT_00509420 = 0x2a;
          slot_idx = 0xffffffff;
        }
        else {
          slot_idx = val_2 - 1;
        }
      }
    }
    else if (DAT_0050a730 == 0) {
      for (; slot_idx < arg_3; slot_idx = slot_idx + 1) {
        if (0xff < (uint16_t)*str_2) {
          DAT_00509420 = 0x2a;
          return 0xffffffff;
        }
        str_1[slot_idx] = (char)*str_2;
        if (*str_2 == L'\0') {
          return slot_idx;
        }
        str_2 = str_2 + 1;
      }
    }
    else if (DAT_005096ac == 1) {
      if (arg_3 != 0) {
        arg_3 = wcsncnt(str_2,arg_3);
      }
      slot_idx = WideCharToMultiByte(DAT_0050a740,0x220,str_2,arg_3,str_1,arg_3,(LPCSTR)0x0,&target_idx
                                   );
      if ((slot_idx == 0) || (target_idx != 0)) {
        DAT_00509420 = 0x2a;
        slot_idx = 0xffffffff;
      }
      else if (str_1[slot_idx - 1] == '\0') {
        slot_idx = slot_idx - 1;
      }
    }
    else {
      slot_idx = WideCharToMultiByte(DAT_0050a740,0x220,str_2,-1,str_1,arg_3,(LPCSTR)0x0,&target_idx);
      if ((slot_idx == 0) || (target_idx != 0)) {
        if ((target_idx == 0) && (DVar4 = GetLastError(), DVar4 == 0x7a)) {
          while (slot_idx < arg_3) {
            player_idx = WideCharToMultiByte(DAT_0050a740,0,str_2,1,card_idx,DAT_005096ac,(LPCSTR)0x0,
                                           &target_idx);
            if ((player_idx == 0) || (target_idx != 0)) {
              DAT_00509420 = 0x2a;
              return 0xffffffff;
            }
            if (arg_3 < player_idx + slot_idx) {
              return slot_idx;
            }
            for (match_count = 0; match_count < player_idx; match_count = match_count + 1) {
              str_1[slot_idx] = card_idx[match_count];
              if (str_1[slot_idx] == '\0') {
                return slot_idx;
              }
              slot_idx = slot_idx + 1;
            }
            str_2 = str_2 + 1;
          }
        }
        else {
          DAT_00509420 = 0x2a;
          slot_idx = 0xffffffff;
        }
      }
      else {
        slot_idx = slot_idx - 1;
      }
    }
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: wcsncnt
 * Entry Point: 004eb950
 * Size: 110 bytes
 */


/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Debug */

int __cdecl wcsncnt(short *arg1,int arg2)

{
  int match_count;
  short *slot_idx;
  
  match_count = arg2 + 1;
  for (slot_idx = arg1; (match_count = match_count + -1, match_count != 0 && (*slot_idx != 0));
      slot_idx = slot_idx + 1) {
  }
  if ((match_count != 0) && (*slot_idx == 0)) {
    arg2 = ((int)slot_idx - (int)arg1 >> 1) + 1;
  }
  return arg2;
}



/*
 * Decompiled function: _getenv
 * Entry Point: 004eb9c0
 * Size: 227 bytes
 */


/* Library Function - Single Match
    _getenv
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _getenv(char *filepath)

{
  int val_1;
  size_t arg_3;
  size_t len_2;
  int *match_count;
  
  match_count = DAT_00509448;
  if ((DAT_00509448 == (int *)0x0) && (DAT_00509450 != 0)) {
    val_1 = ___wtomb_environ();
    if (val_1 != 0) {
      return (char *)0x0;
    }
    match_count = DAT_00509448;
  }
  DAT_00509448 = match_count;
  if ((match_count != (int *)0x0) && (str_1 != (char *)0x0)) {
    arg_3 = _strlen(str_1);
    for (; *match_count != 0; match_count = match_count + 1) {
      len_2 = _strlen((char *)*match_count);
      if (((arg_3 < len_2) && (*(char *)(arg_3 + *match_count) == '=')) &&
         (val_1 = __mbsnbicoll((uchar *)*match_count,(uchar *)str_1,arg_3), val_1 == 0)) {
        return (char *)(arg_3 + 1 + *match_count);
      }
    }
  }
  return (char *)0x0;
}



