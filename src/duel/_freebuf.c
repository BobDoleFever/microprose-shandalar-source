/*
 * _freebuf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 9
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __freebuf
 * Entry Point: 004e3660
 * Size: 138 bytes
 */


/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __freebuf(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0e98,0x30,0,"stream != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  if (((fp->_flag & 0x83) != 0) && ((fp->_flag & 8) != 0)) {
    __free_dbg(fp->_base,2);
    fp->_flag = fp->_flag & 0xfffffbf7;
    fp->_ptr = (char *)0x0;
    fp->_base = fp->_ptr;
    fp->_cnt = 0;
  }
  return;
}



/*
 * Decompiled function: __lseek
 * Entry Point: 004e36f0
 * Size: 285 bytes
 */


/* Library Function - Single Match
    __lseek
   
   Library: Visual Studio 1998 Debug */

long __cdecl __lseek(int player_id,long arg_2,int event_type)

{
  DWORD DVar1;
  HANDLE hFile;
  uint32_t slot_idx;
  
  if (((uint32_t)arg_1 < DAT_006c1c90) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(arg_1);
    if (hFile == (HANDLE)0xffffffff) {
      DAT_00509420 = 9;
      DVar1 = 0xffffffff;
    }
    else {
      DVar1 = SetFilePointer(hFile,arg_2,(PLONG)0x0,arg_3);
      if (DVar1 == 0xffffffff) {
        slot_idx = GetLastError();
      }
      else {
        slot_idx = 0;
      }
      if (slot_idx == 0) {
        *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) =
             *(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                      (arg_1 & 0x1fU) * 8) & 0xfd;
      }
      else {
        __dosmaperr(slot_idx);
        DVar1 = 0xffffffff;
      }
    }
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    DVar1 = 0xffffffff;
  }
  return DVar1;
}



/*
 * Decompiled function: __mbsnbcpy
 * Entry Point: 004e3810
 * Size: 277 bytes
 */


/* Library Function - Single Match
    __mbsnbcpy
   
   Library: Visual Studio 1998 Debug */

uchar * __cdecl __mbsnbcpy(uchar *str_1,uchar *str_2,size_t arg_3)

{
  size_t len_1;
  uchar *u_ptr_2;
  uchar *u_ptr_3;
  uchar uval_4;
  uchar *puVar5;
  
  puVar5 = str_1;
  u_ptr_3 = str_1;
  if (DAT_0050a304 == 0) {
    puVar5 = (uchar *)_strncpy((char *)str_1,(char *)str_2,arg_3);
  }
  else {
    do {
      while( true ) {
        str_1 = u_ptr_3;
        if (arg_3 == 0) goto LAB_004e38f7;
        len_1 = arg_3 - 1;
        if (((&DAT_0050a201)[*str_2] & 4) == 0) break;
        *str_1 = *str_2;
        u_ptr_2 = str_1 + 1;
        if (len_1 == 0) {
          *str_1 = '\0';
          str_1 = u_ptr_2;
          arg_3 = len_1;
          goto LAB_004e38f7;
        }
        arg_3 = arg_3 - 2;
        *u_ptr_2 = str_2[1];
        str_2 = str_2 + 2;
        u_ptr_3 = str_1 + 2;
        if (*u_ptr_2 == '\0') {
          *str_1 = '\0';
          str_1 = str_1 + 2;
          goto LAB_004e38f7;
        }
      }
      u_ptr_3 = str_1 + 1;
      *str_1 = *str_2;
      str_2 = str_2 + 1;
      uval_4 = *str_1;
      str_1 = u_ptr_3;
      arg_3 = len_1;
    } while (uval_4 != '\0');
LAB_004e38f7:
    while (arg_3 != 0) {
      *str_1 = '\0';
      str_1 = str_1 + 1;
      arg_3 = arg_3 - 1;
    }
  }
  return puVar5;
}



/*
 * Decompiled function: __setmbcp
 * Entry Point: 004e3930
 * Size: 815 bytes
 */


/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setmbcp(int player_id)

{
  UINT CodePage;
  int val_1;
  BOOL BVar2;
  BYTE *local_2c;
  uint32_t local_28;
  _cpinfo local_24;
  uint32_t card_idx;
  uint8_t *match_count;
  uint32_t slot_idx;
  
  CodePage = getSystemCP(arg_1);
  if (CodePage == DAT_0050a304) {
    val_1 = 0;
  }
  else if (CodePage == 0) {
    setSBCS();
    val_1 = 0;
  }
  else {
    for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
      if (*(UINT *)(&DAT_0050a328 + slot_idx * 0x30) == CodePage) {
        for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
          (&DAT_0050a200)[local_28] = 0;
        }
        for (card_idx = 0; card_idx < 4; card_idx = card_idx + 1) {
          for (match_count = &DAT_0050a338 + slot_idx * 0x30 + card_idx * 8;
              (*match_count != 0 && (match_count[1] != 0)); match_count = match_count + 2) {
            for (local_28 = (uint32_t)*match_count; local_28 <= match_count[1]; local_28 = local_28 + 1) {
              (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | (&DAT_0050a320)[card_idx];
            }
          }
        }
        DAT_0050a304 = CodePage;
        DAT_0050a308 = _CPtoLCID(CodePage);
        for (card_idx = 0; card_idx < 6; card_idx = card_idx + 1) {
          *(int16_t *)(&DAT_0050a310 + card_idx * 2) =
               *(int16_t *)(&DAT_0050a32c + card_idx * 2 + slot_idx * 0x30);
        }
        return 0;
      }
    }
    BVar2 = GetCPInfo(CodePage,&local_24);
    if (BVar2 == 1) {
      for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
        (&DAT_0050a200)[local_28] = 0;
      }
      if (local_24.MaxCharSize < 2) {
        DAT_0050a304 = 0;
        DAT_0050a308 = 0;
      }
      else {
        for (local_2c = local_24.LeadByte; (*local_2c != 0 && (local_2c[1] != 0));
            local_2c = local_2c + 2) {
          for (local_28 = (uint32_t)*local_2c; local_28 <= local_2c[1]; local_28 = local_28 + 1) {
            (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | 4;
          }
        }
        for (local_28 = 1; local_28 < 0xff; local_28 = local_28 + 1) {
          (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | 8;
        }
        DAT_0050a304 = CodePage;
        DAT_0050a308 = _CPtoLCID(CodePage);
      }
      for (card_idx = 0; card_idx < 6; card_idx = card_idx + 1) {
        *(int16_t *)(&DAT_0050a310 + card_idx * 2) = 0;
      }
      val_1 = 0;
    }
    else if (DAT_0050a31c == 0) {
      val_1 = -1;
    }
    else {
      setSBCS();
      val_1 = 0;
    }
  }
  return val_1;
}



/*
 * Decompiled function: getSystemCP
 * Entry Point: 004e3c60
 * Size: 121 bytes
 */


/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Debug */

UINT __cdecl getSystemCP(UINT arg_1)

{
  DAT_0050a31c = 0;
  if (arg_1 == 0xfffffffe) {
    DAT_0050a31c = 1;
    arg_1 = GetOEMCP();
  }
  else if (arg_1 == 0xfffffffd) {
    DAT_0050a31c = 1;
    arg_1 = GetACP();
  }
  else if (arg_1 == 0xfffffffc) {
    DAT_0050a31c = 1;
    arg_1 = DAT_0050a740;
  }
  return arg_1;
}



/*
 * Decompiled function: _CPtoLCID
 * Entry Point: 004e3cf0
 * Size: 107 bytes
 */


/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Debug */

int32_t _CPtoLCID(int32_t arg_1)

{
  int32_t uval_1;
  
  switch(arg_1) {
  case 0x3a4:
    uval_1 = 0x411;
    break;
  default:
    uval_1 = 0;
    break;
  case 0x3a8:
    uval_1 = 0x804;
    break;
  case 0x3b5:
    uval_1 = 0x412;
    break;
  case 0x3b6:
    uval_1 = 0x404;
  }
  return uval_1;
}



/*
 * Decompiled function: setSBCS
 * Entry Point: 004e3d90
 * Size: 120 bytes
 */


/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Debug */

void __cdecl setSBCS(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x101; slot_idx = slot_idx + 1) {
    (&DAT_0050a200)[slot_idx] = 0;
  }
  DAT_0050a304 = 0;
  DAT_0050a308 = 0;
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    *(int16_t *)(&DAT_0050a310 + slot_idx * 2) = 0;
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e3e10
 * Entry Point: 004e3e10
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_004e3e10(void)

{
  return DAT_0050a304;
}



/*
 * Decompiled function: ___initmbctable
 * Entry Point: 004e3e30
 * Size: 21 bytes
 */


/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 1998 Debug */

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}



