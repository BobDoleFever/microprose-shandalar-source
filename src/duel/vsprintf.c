/*
 * vsprintf.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: __vsnprintf
 * Entry Point: 004de780
 * Size: 229 bytes
 */


/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __vsnprintf(char *filepath,size_t arg_2,char *str_3,va_list arg_4)

{
  code *char_ptr_1;
  int val_2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b3c,0x5a,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_3 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b3c,0x5b,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = arg_2;
  val_2 = __output(&local_24,(uint8_t *)str_3,(int32_t *)arg_4);
  local_24._cnt = local_24._cnt - 1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return val_2;
}



/*
 * Decompiled function: _strncpy
 * Entry Point: 004de870
 * Size: 254 bytes
 */


/* Library Function - Single Match
    _strncpy
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strncpy(char *filepath,char *mode_str,size_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  char cVar3;
  uint32_t uval_4;
  uint32_t *puVar5;
  
  if (arg_3 == 0) {
    return str_1;
  }
  puVar5 = (uint32_t *)str_1;
  if (((uint32_t)str_2 & 3) != 0) {
    while( true ) {
      uval_4 = *(uint32_t *)str_2;
      str_2 = (char *)((int)str_2 + 1);
      *(char *)puVar5 = (char)uval_4;
      puVar5 = (uint32_t *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
      if (arg_3 == 0) {
        return str_1;
      }
      if ((char)uval_4 == '\0') break;
      if (((uint32_t)str_2 & 3) == 0) {
        uval_4 = arg_3 >> 2;
        goto joined_r0x004de8ae;
      }
    }
    do {
      if (((uint32_t)puVar5 & 3) == 0) {
        uval_4 = arg_3 >> 2;
        cVar3 = '\0';
        if (uval_4 == 0) goto LAB_004de8eb;
        goto LAB_004de959;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint32_t *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
    } while (arg_3 != 0);
    return str_1;
  }
  uval_4 = arg_3 >> 2;
  if (uval_4 != 0) {
    do {
      uval_1 = *(uint32_t *)str_2;
      uval_2 = *(uint32_t *)str_2;
      str_2 = (char *)((int)str_2 + 4);
      if (((uval_1 ^ 0xffffffff ^ uval_1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uval_2 == '\0') {
          *puVar5 = 0;
joined_r0x004de955:
          while( true ) {
            uval_4 = uval_4 - 1;
            puVar5 = puVar5 + 1;
            if (uval_4 == 0) break;
LAB_004de959:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          arg_3 = arg_3 & 3;
          if (arg_3 != 0) goto LAB_004de8eb;
          return str_1;
        }
        if ((char)(uval_2 >> 8) == '\0') {
          *puVar5 = uval_2 & 0xff;
          goto joined_r0x004de955;
        }
        if ((uval_2 & 0xff0000) == 0) {
          *puVar5 = uval_2 & 0xffff;
          goto joined_r0x004de955;
        }
        if ((uval_2 & 0xff000000) == 0) {
          *puVar5 = uval_2;
          goto joined_r0x004de955;
        }
      }
      *puVar5 = uval_2;
      puVar5 = puVar5 + 1;
      uval_4 = uval_4 - 1;
joined_r0x004de8ae:
    } while (uval_4 != 0);
    arg_3 = arg_3 & 3;
    if (arg_3 == 0) {
      return str_1;
    }
  }
  do {
    cVar3 = (char)*(uint32_t *)str_2;
    str_2 = (char *)((int)str_2 + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint32_t *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (arg_3 = arg_3 - 1, arg_3 != 0) {
LAB_004de8eb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint32_t *)((int)puVar5 + 1);
      }
      return str_1;
    }
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return str_1;
}



/*
 * Decompiled function: __fpmath
 * Entry Point: 004de970
 * Size: 38 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fpmath(int player_id)

{
  __cfltcvt_init();
  _DAT_005096cc = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004de9a0
 * Entry Point: 004de9a0
 * Size: 16 bytes
 */


void Mem_AllocOrFree_004de9a0(void)

{
  return;
}



/*
 * Decompiled function: __cfltcvt_init
 * Entry Point: 004de9b0
 * Size: 71 bytes
 */


/* Library Function - Single Match
    __cfltcvt_init
   
   Library: Visual Studio 1998 Debug */

void __cfltcvt_init(void)

{
  PTR___fptrap_0050a5b0 = __cfltcvt;
  PTR___fptrap_0050a5b4 = __cropzeros;
  PTR___fptrap_0050a5b8 = __fassign;
  PTR___fptrap_0050a5bc = __forcdecpt;
  PTR___fptrap_0050a5c0 = __positive;
  PTR___fptrap_0050a5c4 = __cfltcvt;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004dea00
 * Entry Point: 004dea00
 * Size: 38 bytes
 */


int32_t Mem_AllocOrFree_004dea00(int32_t arg_1)

{
  int32_t uval_1;
  
  uval_1 = DAT_005096c8;
  DAT_005096c8 = arg_1;
  return uval_1;
}



/*
 * Decompiled function: entry
 * Entry Point: 004dea30
 * Size: 494 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  uint8_t *pbVar1;
  DWORD DVar2;
  int val_3;
  HMODULE arg_1;
  int unaff_EDI;
  int32_t *unaff_FS_OFFSET;
  int32_t arg_2;
  uint8_t *local_68;
  _STARTUPINFOA local_60;
  uint8_t *color_idx;
  int32_t uStack_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  int32_t slot_idx;
  
  slot_idx = 0xffffffff;
  puStack_c = &DAT_004f0b48;
  puStack_10 = &LAB_004e85a4;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  color_idx = &stack0xffffff84;
  DVar2 = GetVersion();
  _DAT_00509438 = DVar2 >> 8 & 0xff;
  DAT_00509434 = DVar2 & 0xff;
  _DAT_00509430 = DAT_00509434 * 0x100 + _DAT_00509438;
  DAT_0050942c = DVar2 >> 0x10;
  val_3 = __heap_init();
  if (val_3 == 0) {
    __amsg_exit(0x1c);
  }
  slot_idx = 0;
  __ioinit();
  ___initmbctable();
  DAT_006c2ca8 = (uint8_t *)GetCommandLineA();
  DAT_005096dc = ___crtGetEnvironmentStringsA();
  if ((DAT_005096dc != (LPVOID)0x0) && (DAT_006c2ca8 != (uint8_t *)0x0)) {
    __setargv();
    Mem_AllocOrFree_004b9420();
    __cinit(unaff_EDI);
    local_68 = DAT_006c2ca8;
    pbVar1 = local_68;
    if (*DAT_006c2ca8 == 0x22) {
      while ((local_68 = pbVar1, pbVar1 = local_68 + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
        val_3 = __ismbblead((uint32_t)*pbVar1);
        if (val_3 != 0) {
          pbVar1 = local_68 + 2;
        }
      }
      if (*pbVar1 == 0x22) {
        pbVar1 = local_68 + 2;
      }
    }
    else {
      for (; pbVar1 = local_68, 0x20 < *local_68; local_68 = local_68 + 1) {
      }
    }
    while ((local_68 = pbVar1, *local_68 != 0 && (*local_68 < 0x21))) {
      pbVar1 = local_68 + 1;
    }
    local_60.dwFlags = 0;
    GetStartupInfoA(&local_60);
    arg_2 = 0;
    arg_1 = GetModuleHandleA((LPCSTR)0x0);
    val_3 = Palette_Subsystem_00495958(arg_1,arg_2,(char *)local_68);
                    /* WARNING: Subroutine does not return */
    _exit(val_3);
  }
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}



/*
 * Decompiled function: __amsg_exit
 * Entry Point: 004dec80
 * Size: 55 bytes
 */


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Debug */

void __cdecl __amsg_exit(int player_id)

{
  if (DAT_005096e8 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(arg_1);
  (*(code *)PTR___exit_005096e4)(0xff);
  return;
}



/*
 * Decompiled function: __flsbuf
 * Entry Point: 004decc0
 * Size: 660 bytes
 */


/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flsbuf(int arg1,FILE *arg2)

{
  code *char_ptr_1;
  FILE *fp;
  int val_2;
  uint32_t uval_3;
  uint8_t *color_idx;
  uint32_t card_idx;
  uint32_t slot_idx;
  
  if ((arg2 == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x4f0b94,0x69,0,"str != NULL"), val_2 == 1)
     ) {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  fp = arg2;
  uval_3 = arg2->_file;
  if (((arg2->_flag & 0x82) == 0) || ((arg2->_flag & 0x40) != 0)) {
    arg2->_flag = arg2->_flag | 0x20;
    uval_3 = 0xffffffff;
  }
  else {
    if ((arg2->_flag & 1) != 0) {
      arg2->_cnt = 0;
      if ((arg2->_flag & 0x10) == 0) {
        arg2->_flag = arg2->_flag | 0x20;
        return -1;
      }
      arg2->_ptr = arg2->_base;
      arg2->_flag = arg2->_flag & 0xfffffffe;
    }
    arg2->_flag = arg2->_flag | 2;
    arg2->_flag = arg2->_flag & 0xffffffef;
    arg2->_cnt = 0;
    card_idx = arg2->_cnt;
    if (((arg2->_flag & 0x10cU) == 0) &&
       (((arg2 != (FILE *)0x509770 && (arg2 != (FILE *)&DAT_00509790)) ||
        (val_2 = __isatty(uval_3), val_2 == 0)))) {
      __getbuf(fp);
    }
    if ((fp->_flag & 0x108U) == 0) {
      slot_idx = 1;
      card_idx = __write(uval_3,&arg1,1);
    }
    else {
      if (((int)fp->_ptr - (int)fp->_base < 0) &&
         (val_2 = __CrtDbgReport(2,0x4f0b94,0xa0,0,
                                 "(\"inconsistent IOB fields\", stream->_ptr - stream->_base >= 0)")
         , val_2 == 1)) {
        char_ptr_1 = (code *)swi(3);
        val_2 = (*char_ptr_1)();
        return val_2;
      }
      slot_idx = (int)fp->_ptr - (int)fp->_base;
      fp->_ptr = fp->_base + 1;
      fp->_cnt = fp->_bufsiz + -1;
      if ((int)slot_idx < 1) {
        if (uval_3 == 0xffffffff) {
          color_idx = &DAT_0050a590;
        }
        else {
          color_idx = (uint8_t *)
                     (*(int *)((int)&DAT_006c1b90 + ((int)(uval_3 & 0xffffffe0) >> 3)) +
                     (uval_3 & 0x1f) * 8);
        }
        if ((color_idx[4] & 0x20) != 0) {
          __lseek(uval_3,0,2);
        }
      }
      else {
        card_idx = __write(uval_3,fp->_base,slot_idx);
      }
      *fp->_base = (char)arg1;
    }
    if (card_idx == slot_idx) {
      uval_3 = arg1 & 0xff;
    }
    else {
      fp->_flag = fp->_flag | 0x20;
      uval_3 = 0xffffffff;
    }
  }
  return uval_3;
}



