/*
 * dbgrpt.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _CrtMessageWindow
 * Entry Point: 004e0400
 * Size: 813 bytes
 */


/* Library Function - Single Match
    _CrtMessageWindow
   
   Library: Visual Studio 1998 Debug */

bool _CrtMessageWindow(void)

{
  int val_1;
  DWORD DVar2;
  size_t len_3;
  char *stack_arg;
  int stack_arg;
  uint32_t local_1110 [1009];
  char acStackY_14c [60];
  int local_110;
  uint32_t local_10c [47];
  int32_t uStackY_50;
  
  Mem_AllocOrFree_004ddee0();
  if ((stack_arg == 0) &&
     (val_1 = __CrtDbgReport(2,0x4f0dfc,0x1da,0,"szUserMessage != NULL"), val_1 == 1)) {
    __CrtDbgBreak();
  }
  DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_10c,0x104);
  if (DVar2 == 0) {
    Mem_AllocOrFree_004d9630(local_10c,(uint32_t *)"<program name unknown>");
  }
  len_3 = _strlen((char *)local_10c);
  if (0x40 < len_3) {
    len_3 = _strlen((char *)local_10c);
    _strncpy((char *)((int)local_10c + (len_3 - 0x40)),"...",3);
  }
  if ((stack_arg != (char *)0x0) && (len_3 = _strlen(stack_arg), 0x40 < len_3)) {
    len_3 = _strlen(stack_arg);
    _strncpy(stack_arg + (len_3 - 0x40),"...",3);
  }
  uStackY_50 = 0x4e06ab;
  val_1 = __snprintf((char *)local_1110,0x1000,
                     "Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s\n\n(Press Retry to debug the application)"
                    );
  if (val_1 < 0) {
    Mem_AllocOrFree_004d9630(local_1110,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
  }
  local_110 = ___crtMessageBoxA((LPCSTR)local_1110,"Microsoft Visual C++ Debug Library",0x12012);
  if (local_110 == 3) {
    _raise(0x16);
    __exit(3);
  }
  return local_110 == 4;
}



/*
 * Decompiled function: __allmul
 * Entry Point: 004e0730
 * Size: 52 bytes
 */


/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio 1998 Debug */

longlong __allmul(uint32_t x,int y,uint32_t width,int height)

{
  if (height == 0 && y == 0) {
    return (ulonglong)x * (ulonglong)width;
  }
  return CONCAT44((int)((ulonglong)x * (ulonglong)width >> 0x20) + y * width + x * height,
                  (int)((ulonglong)x * (ulonglong)width));
}



/*
 * Decompiled function: _abort
 * Entry Point: 004e0770
 * Size: 41 bytes
 */


/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 1998 Debug */

void __cdecl _abort(void)

{
  __NMSG_WRITE(10);
  _raise(0x16);
  __exit(3);
  return;
}



/*
 * Decompiled function: _signal
 * Entry Point: 004e07a0
 * Size: 432 bytes
 */


/* Library Function - Single Match
    _signal
   
   Library: Visual Studio 1998 Debug */

void __cdecl _signal(int player_id)

{
  BOOL BVar1;
  int stack_arg;
  int slot_idx;
  
  if ((stack_arg != 4) && (stack_arg != 3)) {
    if ((arg_1 == 2) || (((arg_1 == 0x15 || (arg_1 == 0x16)) || (arg_1 == 0xf)))) {
      if (((arg_1 == 2) || (arg_1 == 0x15)) && (DAT_00509740 == 0)) {
        BVar1 = SetConsoleCtrlHandler(ctrlevent_capture,1);
        if (BVar1 != 1) {
          DAT_00509424 = GetLastError();
          DAT_00509420 = 0x16;
          return;
        }
        DAT_00509740 = 1;
      }
      switch(arg_1) {
      case 2:
        DAT_00509730 = stack_arg;
        break;
      case 0xf:
        DAT_0050973c = stack_arg;
        break;
      case 0x15:
        DAT_00509734 = stack_arg;
        break;
      case 0x16:
        DAT_00509738 = stack_arg;
      }
      return;
    }
    if ((((arg_1 == 8) || (arg_1 == 4)) || (arg_1 == 0xb)) &&
       (slot_idx = siglookup(arg_1), slot_idx != 0)) {
      for (; *(int *)(slot_idx + 4) == arg_1; slot_idx = slot_idx + 0xc) {
        *(int *)(slot_idx + 8) = stack_arg;
      }
      return;
    }
  }
  DAT_00509420 = 0x16;
  return;
}



/*
 * Decompiled function: ctrlevent_capture
 * Entry Point: 004e0980
 * Size: 136 bytes
 */


/* Library Function - Single Match
    _ctrlevent_capture@4
   
   Library: Visual Studio 1998 Debug
   __stdcall ctrlevent_capture,4 */

int32_t ctrlevent_capture(int player_id)

{
  int32_t uval_1;
  code *card_idx;
  int32_t *match_count;
  int32_t slot_idx;
  
  if (arg_1 == 0) {
    match_count = &DAT_00509730;
    card_idx = DAT_00509730;
    slot_idx = 2;
  }
  else {
    match_count = &DAT_00509734;
    card_idx = DAT_00509734;
    slot_idx = 0x15;
  }
  if (card_idx == (code *)0x0) {
    uval_1 = 0;
  }
  else {
    if (card_idx != (code *)0x1) {
      *match_count = 0;
      (*card_idx)(slot_idx);
    }
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: _raise
 * Entry Point: 004e0a10
 * Size: 475 bytes
 */


/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Debug */

int __cdecl _raise(int player_id)

{
  int val_1;
  code *target_idx;
  int32_t *player_idx;
  int32_t card_idx;
  int match_count;
  int32_t slot_idx;
  
  switch(arg_1) {
  case 2:
    player_idx = &DAT_00509730;
    target_idx = DAT_00509730;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    val_1 = siglookup(arg_1);
    player_idx = (int32_t *)(val_1 + 8);
    target_idx = (code *)*player_idx;
    break;
  case 0xf:
    player_idx = &DAT_0050973c;
    target_idx = DAT_0050973c;
    break;
  case 0x15:
    player_idx = &DAT_00509734;
    target_idx = DAT_00509734;
    break;
  case 0x16:
    player_idx = &DAT_00509738;
    target_idx = DAT_00509738;
  }
  if (target_idx != (code *)0x1) {
    if (target_idx == (code *)0x0) {
      __exit(3);
    }
    if (((arg_1 == 8) || (arg_1 == 0xb)) || (arg_1 == 4)) {
      card_idx = DAT_0050a670;
      DAT_0050a670 = 0;
      if (arg_1 == 8) {
        slot_idx = DAT_0050a66c;
        DAT_0050a66c = 0x8c;
      }
    }
    if (arg_1 == 8) {
      for (match_count = DAT_0050a660; match_count < DAT_0050a664 + DAT_0050a660; match_count = match_count + 1) {
        *(int32_t *)(match_count * 0xc + 0x50a5f0) = 0;
      }
    }
    else {
      *player_idx = 0;
    }
    if (arg_1 == 8) {
      (*target_idx)(8,DAT_0050a66c);
    }
    else {
      (*target_idx)(arg_1);
      if ((arg_1 != 0xb) && (arg_1 != 4)) {
        return 0;
      }
    }
    if (arg_1 == 8) {
      DAT_0050a66c = slot_idx;
    }
    DAT_0050a670 = card_idx;
    return 0;
  }
  return 0;
}



/*
 * Decompiled function: siglookup
 * Entry Point: 004e0c30
 * Size: 99 bytes
 */


/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Debug */

int32_t * __cdecl siglookup(int player_id)

{
  int32_t *slot_idx;
  
  slot_idx = &DAT_0050a5e8;
  do {
    if (slot_idx[1] == arg_1) break;
    slot_idx = slot_idx + 3;
  } while (slot_idx < &DAT_0050a5e8 + DAT_0050a668 * 3);
  if (slot_idx[1] != arg_1) {
    slot_idx = (int32_t *)0x0;
  }
  return slot_idx;
}



/*
 * Decompiled function: ___crtMessageBoxA
 * Entry Point: 004e0ca0
 * Size: 223 bytes
 */


/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___crtMessageBoxA(LPCSTR arg_1,LPCSTR arg_2,UINT arg_3)

{
  HMODULE hModule;
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  if (DAT_00509744 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00509744 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00509744 != (FARPROC)0x0) {
        DAT_00509748 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0050974c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004e0d25;
      }
    }
    val_1 = 0;
  }
  else {
LAB_004e0d25:
    if (DAT_00509748 != (FARPROC)0x0) {
      slot_idx = (*DAT_00509748)();
    }
    if ((slot_idx != 0) && (DAT_0050974c != (FARPROC)0x0)) {
      slot_idx = (*DAT_0050974c)(slot_idx);
    }
    val_1 = (*DAT_00509744)(slot_idx,arg_1,arg_2,arg_3);
  }
  return val_1;
}



/*
 * Decompiled function: _strncat
 * Entry Point: 004e0d80
 * Size: 291 bytes
 */


/* Library Function - Single Match
    _strncat
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strncat(char *filepath,char *mode_str,size_t arg_3)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t *puVar5;
  uint32_t *puVar6;
  
  puVar5 = (uint32_t *)str_1;
  if (arg_3 == 0) {
    return str_1;
  }
  do {
    if (((uint32_t)puVar5 & 3) == 0) goto LAB_004e0daa;
    uval_4 = *puVar5;
    puVar5 = (uint32_t *)((int)puVar5 + 1);
  } while ((uint8_t)uval_4 != 0);
  goto LAB_004e0ddb;
  while( true ) {
    if ((uval_4 & 0xff0000) == 0) {
      puVar6 = (uint32_t *)((int)puVar6 + 2);
      goto LAB_004e0deb;
    }
    if ((uval_4 & 0xff000000) == 0) break;
LAB_004e0daa:
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
    } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
    uval_4 = *puVar6;
    if ((char)uval_4 == '\0') goto LAB_004e0deb;
    if ((char)(uval_4 >> 8) == '\0') {
      puVar6 = (uint32_t *)((int)puVar6 + 1);
      goto LAB_004e0deb;
    }
  }
LAB_004e0ddb:
  puVar6 = (uint32_t *)((int)puVar5 + -1);
LAB_004e0deb:
  if (((uint32_t)str_2 & 3) == 0) {
    uval_3 = arg_3 >> 2;
  }
  else {
    do {
      flag_1 = (uint8_t)*(uint32_t *)str_2;
      uval_4 = (uint32_t)flag_1;
      str_2 = (char *)((int)str_2 + 1);
      if (flag_1 == 0) goto LAB_004e0e3a;
      *(uint8_t *)puVar6 = flag_1;
      puVar6 = (uint32_t *)((int)puVar6 + 1);
      arg_3 = arg_3 - 1;
      if (arg_3 == 0) goto LAB_004e0e30;
    } while (((uint32_t)str_2 & 3) != 0);
    uval_3 = arg_3 >> 2;
  }
  do {
    if (uval_3 == 0) {
      for (uval_4 = arg_3 & 3; uval_4 != 0; uval_4 = uval_4 - 1) {
        uval_3 = *(uint32_t *)str_2;
        str_2 = (char *)((int)str_2 + 1);
        *(uint8_t *)puVar6 = (uint8_t)uval_3;
        puVar6 = (uint32_t *)((int)puVar6 + 1);
        if ((uint8_t)uval_3 == 0) {
          return str_1;
        }
      }
LAB_004e0e30:
      *(uint8_t *)puVar6 = 0;
      return str_1;
    }
    uval_2 = *(uint32_t *)str_2;
    uval_4 = *(uint32_t *)str_2;
    str_2 = (char *)((int)str_2 + 4);
    if (((uval_2 ^ 0xffffffff ^ uval_2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uval_4 == '\0') {
LAB_004e0e3a:
        *(uint8_t *)puVar6 = (uint8_t)uval_4;
        return str_1;
      }
      if ((char)(uval_4 >> 8) == '\0') {
        *(short *)puVar6 = (short)uval_4;
        return str_1;
      }
      if ((uval_4 & 0xff0000) == 0) {
        *(short *)puVar6 = (short)uval_4;
        *(uint8_t *)((int)puVar6 + 2) = 0;
        return str_1;
      }
      if ((uval_4 & 0xff000000) == 0) {
        *puVar6 = uval_4;
        return str_1;
      }
    }
    *puVar6 = uval_4;
    puVar6 = puVar6 + 1;
    uval_3 = uval_3 - 1;
  } while( true );
}



/*
 * Decompiled function: __itoa
 * Entry Point: 004e0eb0
 * Size: 88 bytes
 */


/* Library Function - Single Match
    __itoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __itoa(int player_id,char *mode_str,int event_type)

{
  if ((arg_3 == 10) && (arg_1 < 0)) {
    xtoa(arg_1,str_2,10,1);
  }
  else {
    xtoa(arg_1,str_2,arg_3,0);
  }
  return str_2;
}



/*
 * Decompiled function: xtoa
 * Entry Point: 004e0f10
 * Size: 181 bytes
 */


/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 1998 Debug */

void __cdecl xtoa(uint32_t x,char *mode_str,uint32_t width,int height)

{
  char cVar1;
  char *char_ptr_2;
  uint32_t uval_3;
  char *match_count;
  char *slot_idx;
  
  slot_idx = str_2;
  if (height != 0) {
    *str_2 = '-';
    slot_idx = str_2 + 1;
    x = -x;
  }
  match_count = slot_idx;
  do {
    char_ptr_2 = slot_idx;
    uval_3 = x % width;
    x = x / width;
    cVar1 = (char)uval_3;
    if (uval_3 < 10) {
      *slot_idx = cVar1 + '0';
    }
    else {
      *slot_idx = cVar1 + 'W';
    }
    slot_idx = slot_idx + 1;
  } while (x != 0);
  *slot_idx = '\0';
  slot_idx = char_ptr_2;
  do {
    cVar1 = *slot_idx;
    *slot_idx = *match_count;
    *match_count = cVar1;
    slot_idx = slot_idx + -1;
    match_count = match_count + 1;
  } while (match_count < slot_idx);
  return;
}



/*
 * Decompiled function: __ltoa
 * Entry Point: 004e0fd0
 * Size: 85 bytes
 */


/* Library Function - Single Match
    __ltoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ltoa(long arg_1,char *mode_str,int event_type)

{
  int32_t slot_idx;
  
  if ((arg_3 == 10) && (arg_1 < 0)) {
    slot_idx = 1;
  }
  else {
    slot_idx = 0;
  }
  xtoa(arg_1,str_2,arg_3,slot_idx);
  return str_2;
}



/*
 * Decompiled function: __ultoa
 * Entry Point: 004e1030
 * Size: 41 bytes
 */


/* Library Function - Single Match
    __ultoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ultoa(uint32_t arg_1,char *mode_str,int event_type)

{
  xtoa(arg_1,str_2,arg_3,0);
  return str_2;
}



/*
 * Decompiled function: __i64toa
 * Entry Point: 004e1060
 * Size: 102 bytes
 */


/* Library Function - Single Match
    __i64toa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __i64toa(longlong arg_1,char *mode_str,int event_type)

{
  int slot_idx;
  
  if (((arg_3 == 10) && (arg_1 < 0x100000000)) && (arg_1 < 0)) {
    slot_idx = 1;
  }
  else {
    slot_idx = 0;
  }
  x64toa((int32_t)arg_1,arg_1._4_4_,str_2,arg_3,slot_idx);
  return str_2;
}



/*
 * Decompiled function: x64toa
 * Entry Point: 004e10d0
 * Size: 216 bytes
 */


/* Library Function - Single Match
    _x64toa@20
   
   Library: Visual Studio 1998 Debug
   __stdcall x64toa,20 */

void x64toa(uint32_t arg_1,uint32_t arg_2,char *str_3,uint32_t arg_4,int arg_5)

{
  char cVar1;
  char *char_ptr_2;
  uint32_t uval_3;
  longlong lVar4;
  char *match_count;
  char *slot_idx;
  
  lVar4 = CONCAT44(arg_2,arg_1);
  slot_idx = str_3;
  if (arg_5 != 0) {
    *str_3 = '-';
    slot_idx = str_3 + 1;
  }
  match_count = slot_idx;
  do {
    char_ptr_2 = slot_idx;
    arg_2 = (uint32_t)((ulonglong)lVar4 >> 0x20);
    arg_1 = (uint32_t)lVar4;
    uval_3 = __aullrem(arg_1,arg_2,arg_4,0);
    lVar4 = __aulldiv(arg_1,arg_2,arg_4,0);
    if (uval_3 < 10) {
      *slot_idx = (char)uval_3 + '0';
    }
    else {
      *slot_idx = (char)uval_3 + 'W';
    }
    slot_idx = slot_idx + 1;
  } while (lVar4 != 0);
  *slot_idx = '\0';
  slot_idx = char_ptr_2;
  do {
    cVar1 = *slot_idx;
    *slot_idx = *match_count;
    *match_count = cVar1;
    slot_idx = slot_idx + -1;
    match_count = match_count + 1;
  } while (match_count < slot_idx);
  return;
}



/*
 * Decompiled function: __ui64toa
 * Entry Point: 004e11b0
 * Size: 42 bytes
 */


/* Library Function - Single Match
    __ui64toa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ui64toa(ulonglong arg_1,char *mode_str,int event_type)

{
  x64toa((int32_t)arg_1,arg_1._4_4_,str_2,arg_3,0);
  return str_2;
}



/*
 * Decompiled function: _fflush
 * Entry Point: 004e11e0
 * Size: 126 bytes
 */


/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fflush(FILE *fp)

{
  int val_1;
  
  if (fp == (FILE *)0x0) {
    val_1 = flsall(0);
  }
  else {
    val_1 = __flush(fp);
    if (val_1 == 0) {
      if ((fp->_flag & 0x4000) == 0) {
        val_1 = 0;
      }
      else {
        val_1 = __commit(fp->_file);
        if (val_1 == 0) {
          val_1 = 0;
        }
        else {
          val_1 = -1;
        }
      }
    }
    else {
      val_1 = -1;
    }
  }
  return val_1;
}



/*
 * Decompiled function: __flush
 * Entry Point: 004e1260
 * Size: 186 bytes
 */


/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flush(FILE *fp)

{
  uint32_t arg_3;
  uint32_t uval_1;
  int slot_idx;
  
  slot_idx = 0;
  if (((((uint8_t)fp->_flag & 3) == 2) && ((fp->_flag & 0x108U) != 0)) &&
     (arg_3 = (int)fp->_ptr - (int)fp->_base, 0 < (int)arg_3)) {
    uval_1 = __write(fp->_file,fp->_base,arg_3);
    if (uval_1 == arg_3) {
      if ((fp->_flag & 0x80) != 0) {
        fp->_flag = fp->_flag & 0xfffffffd;
      }
    }
    else {
      fp->_flag = fp->_flag | 0x20;
      slot_idx = -1;
    }
  }
  fp->_ptr = fp->_base;
  fp->_cnt = 0;
  return slot_idx;
}



/*
 * Decompiled function: __flushall
 * Entry Point: 004e1320
 * Size: 26 bytes
 */


/* Library Function - Single Match
    __flushall
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flushall(void)

{
  int val_1;
  
  val_1 = flsall(1);
  return val_1;
}



/*
 * Decompiled function: flsall
 * Entry Point: 004e1340
 * Size: 247 bytes
 */


/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Debug */

int __cdecl flsall(int player_id)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  match_count = 0;
  for (card_idx = 0; card_idx < DAT_006c2ca0; card_idx = card_idx + 1) {
    if ((*(int *)(DAT_006c1c98 + card_idx * 4) != 0) &&
       ((*(uint8_t *)(*(int *)(DAT_006c1c98 + card_idx * 4) + 0xc) & 0x83) != 0)) {
      if (arg_1 == 1) {
        val_1 = _fflush(*(FILE **)(DAT_006c1c98 + card_idx * 4));
        if (val_1 != -1) {
          slot_idx = slot_idx + 1;
        }
      }
      else if (((arg_1 == 0) && ((*(uint8_t *)(*(int *)(DAT_006c1c98 + card_idx * 4) + 0xc) & 2) != 0))
              && (val_1 = _fflush(*(FILE **)(DAT_006c1c98 + card_idx * 4)), val_1 == -1)) {
        match_count = -1;
      }
    }
  }
  if (arg_1 == 1) {
    match_count = slot_idx;
  }
  return match_count;
}



