/*
 * sscanf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _sscanf
 * Entry Point: 004dd040
 * Size: 193 bytes
 */


/* Library Function - Single Match
    _sscanf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _sscanf(char *filepath,char *mode_str,...)

{
  code *char_ptr_1;
  int val_2;
  char *local_24;
  size_t loop_idx;
  char *color_idx;
  int32_t target_idx;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b14,0x42,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b14,0x43,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  target_idx = 0x49;
  color_idx = str_1;
  local_24 = str_1;
  loop_idx = _strlen(str_1);
  val_2 = __input((int)&local_24,(uint8_t *)str_2,(int32_t *)&stack0x0000000c);
  return val_2;
}



/*
 * Decompiled function: _strspn
 * Entry Point: 004dd110
 * Size: 62 bytes
 */


/* Library Function - Single Match
    _strspn
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strspn(char *filepath,char *mode_str)

{
  uint8_t flag_1;
  size_t len_2;
  uint8_t abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    flag_1 = *str_2;
    if (flag_1 == 0) break;
    str_2 = str_2 + 1;
    abStack_28[(int)(uint32_t)flag_1 >> 3] = abStack_28[(int)(uint32_t)flag_1 >> 3] | '\x01' << (flag_1 & 7);
  }
  len_2 = 0xffffffff;
  do {
    len_2 = len_2 + 1;
    flag_1 = *str_1;
    if (flag_1 == 0) {
      return len_2;
    }
    str_1 = str_1 + 1;
  } while ((abStack_28[(int)(uint32_t)flag_1 >> 3] >> (flag_1 & 7) & 1) != 0);
  return len_2;
}



/*
 * Decompiled function: _strcspn
 * Entry Point: 004dd150
 * Size: 62 bytes
 */


/* Library Function - Single Match
    _strcspn
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strcspn(char *filepath,char *mode_str)

{
  uint8_t flag_1;
  size_t len_2;
  uint8_t abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    flag_1 = *str_2;
    if (flag_1 == 0) break;
    str_2 = str_2 + 1;
    abStack_28[(int)(uint32_t)flag_1 >> 3] = abStack_28[(int)(uint32_t)flag_1 >> 3] | '\x01' << (flag_1 & 7);
  }
  len_2 = 0xffffffff;
  do {
    len_2 = len_2 + 1;
    flag_1 = *str_1;
    if (flag_1 == 0) {
      return len_2;
    }
    str_1 = str_1 + 1;
  } while ((abStack_28[(int)(uint32_t)flag_1 >> 3] >> (flag_1 & 7) & 1) == 0);
  return len_2;
}



/*
 * Decompiled function: FID_conflict:__mkdir
 * Entry Point: 004dd190
 * Size: 94 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __mkdir
    __wmkdir
   
   Library: Visual Studio 1998 Debug */

int __cdecl FID_conflict___mkdir(char *filepath)

{
  BOOL BVar1;
  int val_2;
  int32_t slot_idx;
  
  BVar1 = CreateDirectoryA(str_1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 == 0) {
    slot_idx = GetLastError();
  }
  else {
    slot_idx = 0;
  }
  if (slot_idx == 0) {
    val_2 = 0;
  }
  else {
    __dosmaperr(slot_idx);
    val_2 = -1;
  }
  return val_2;
}



