/*
 * mbtowc.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _mbtowc
 * Entry Point: 004e8ee0
 * Size: 410 bytes
 */


/* Library Function - Single Match
    _mbtowc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _mbtowc(wchar_t *str_1,char *mode_str,size_t arg_3)

{
  code *char_ptr_1;
  int val_2;
  uint32_t uval_3;
  
  if (((DAT_005096ac != 1) && (DAT_005096ac != 2)) &&
     (val_2 = __CrtDbgReport(2,0x4f1234,0x4d,0,"MB_CUR_MAX == 1 || MB_CUR_MAX == 2"), val_2 == 1)) {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  if ((str_2 == (char *)0x0) || (arg_3 == 0)) {
    uval_3 = 0;
  }
  else if (*str_2 == '\0') {
    if (str_1 != (wchar_t *)0x0) {
      *str_1 = L'\0';
    }
    uval_3 = 0;
  }
  else if (DAT_0050a730 == 0) {
    if (str_1 != (wchar_t *)0x0) {
      *str_1 = (uint16_t)(uint8_t)*str_2;
    }
    uval_3 = 1;
  }
  else if ((*(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)(uint8_t)*str_2 * 2) & 0x8000) == 0) {
    val_2 = MultiByteToWideChar(DAT_0050a740,9,str_2,1,str_1,(uint32_t)(str_1 != (wchar_t *)0x0));
    if (val_2 == 0) {
      DAT_00509420 = 0x2a;
      uval_3 = 0xffffffff;
    }
    else {
      uval_3 = 1;
    }
  }
  else if (((((int)DAT_005096ac < 2) || ((int)arg_3 < (int)DAT_005096ac)) ||
           (val_2 = MultiByteToWideChar(DAT_0050a740,9,str_2,DAT_005096ac,str_1,
                                        (uint32_t)(str_1 != (wchar_t *)0x0)), uval_3 = DAT_005096ac,
           val_2 == 0)) && ((arg_3 < DAT_005096ac || (uval_3 = DAT_005096ac, str_2[1] == '\0')))) {
    DAT_00509420 = 0x2a;
    uval_3 = 0xffffffff;
  }
  return uval_3;
}



/*
 * Decompiled function: _isalpha
 * Entry Point: 004e9080
 * Size: 74 bytes
 */


/* Library Function - Single Match
    _isalpha
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isalpha(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x103;
  }
  else {
    uval_1 = __isctype(arg_1,0x103);
  }
  return uval_1;
}



/*
 * Decompiled function: _isupper
 * Entry Point: 004e90d0
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _isupper
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isupper(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 1;
  }
  else {
    uval_1 = __isctype(arg_1,1);
  }
  return uval_1;
}



/*
 * Decompiled function: _islower
 * Entry Point: 004e9120
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _islower
   
   Library: Visual Studio 1998 Debug */

int __cdecl _islower(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 2;
  }
  else {
    uval_1 = __isctype(arg_1,2);
  }
  return uval_1;
}



/*
 * Decompiled function: _isdigit
 * Entry Point: 004e9170
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isdigit(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 4;
  }
  else {
    uval_1 = __isctype(arg_1,4);
  }
  return uval_1;
}



/*
 * Decompiled function: _isxdigit
 * Entry Point: 004e91c0
 * Size: 74 bytes
 */


/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isxdigit(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x80;
  }
  else {
    uval_1 = __isctype(arg_1,0x80);
  }
  return uval_1;
}



/*
 * Decompiled function: _isspace
 * Entry Point: 004e9210
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _isspace
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isspace(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 8;
  }
  else {
    uval_1 = __isctype(arg_1,8);
  }
  return uval_1;
}



/*
 * Decompiled function: _ispunct
 * Entry Point: 004e9260
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _ispunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl _ispunct(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x10;
  }
  else {
    uval_1 = __isctype(arg_1,0x10);
  }
  return uval_1;
}



/*
 * Decompiled function: _isalnum
 * Entry Point: 004e92b0
 * Size: 74 bytes
 */


/* Library Function - Single Match
    _isalnum
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isalnum(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x107;
  }
  else {
    uval_1 = __isctype(arg_1,0x107);
  }
  return uval_1;
}



/*
 * Decompiled function: _isprint
 * Entry Point: 004e9300
 * Size: 74 bytes
 */


/* Library Function - Single Match
    _isprint
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isprint(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x157;
  }
  else {
    uval_1 = __isctype(arg_1,0x157);
  }
  return uval_1;
}



/*
 * Decompiled function: _isgraph
 * Entry Point: 004e9350
 * Size: 74 bytes
 */


/* Library Function - Single Match
    _isgraph
   
   Library: Visual Studio 1998 Debug */

int __cdecl _isgraph(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x117;
  }
  else {
    uval_1 = __isctype(arg_1,0x117);
  }
  return uval_1;
}



/*
 * Decompiled function: _iscntrl
 * Entry Point: 004e93a0
 * Size: 68 bytes
 */


/* Library Function - Single Match
    _iscntrl
   
   Library: Visual Studio 1998 Debug */

int __cdecl _iscntrl(int player_id)

{
  uint32_t uval_1;
  
  if (DAT_005096ac < 2) {
    uval_1 = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x20;
  }
  else {
    uval_1 = __isctype(arg_1,0x20);
  }
  return uval_1;
}



/*
 * Decompiled function: ___isascii
 * Entry Point: 004e93f0
 * Size: 41 bytes
 */


/* Library Function - Single Match
    ___isascii
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___isascii(int player_id)

{
  return (uint32_t)((uint32_t)arg_1 < 0x80);
}



/*
 * Decompiled function: Mem_AllocOrFree_004e9420
 * Entry Point: 004e9420
 * Size: 22 bytes
 */


uint32_t Mem_AllocOrFree_004e9420(uint32_t arg_1)

{
  return arg_1 & 0x7f;
}



/*
 * Decompiled function: ___iscsymf
 * Entry Point: 004e9440
 * Size: 113 bytes
 */


/* Library Function - Single Match
    ___iscsymf
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___iscsymf(int player_id)

{
  int val_1;
  uint32_t slot_idx;
  
  if (DAT_005096ac < 2) {
    slot_idx = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x103;
  }
  else {
    slot_idx = __isctype(arg_1,0x103);
  }
  if ((slot_idx == 0) && (arg_1 != 0x5f)) {
    val_1 = 0;
  }
  else {
    val_1 = 1;
  }
  return val_1;
}



/*
 * Decompiled function: ___iscsym
 * Entry Point: 004e94c0
 * Size: 113 bytes
 */


/* Library Function - Single Match
    ___iscsym
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___iscsym(int player_id)

{
  int val_1;
  uint32_t slot_idx;
  
  if (DAT_005096ac < 2) {
    slot_idx = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 0x107;
  }
  else {
    slot_idx = __isctype(arg_1,0x107);
  }
  if ((slot_idx == 0) && (arg_1 != 0x5f)) {
    val_1 = 0;
  }
  else {
    val_1 = 1;
  }
  return val_1;
}



