/*
 * Decompiled function: _ftell
 * Entry Point: 004de240
 * Size: 674 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _ftell
   
   Library: Visual Studio 1998 Debug */

long __cdecl _ftell(FILE *fp)

{
  uint arg_1;
  code *pcVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  int local_20;
  int local_1c;
  char *local_14;
  char *local_8;
  
  if ((fp == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f0b28,99,0,"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    lVar3 = (*pcVar1)();
    return lVar3;
  }
  arg_1 = fp->_file;
  if (fp->_cnt < 0) {
    fp->_cnt = 0;
  }
  local_20 = __lseek(arg_1,0,1);
  if (local_20 < 0) {
    local_1c = -1;
  }
  else if ((fp->_flag & 0x108U) == 0) {
    local_1c = local_20 - fp->_cnt;
  }
  else {
    local_1c = (int)fp->_ptr - (int)fp->_base;
    if ((fp->_flag & 3) == 0) {
      if ((fp->_flag & 0x80) == 0) {
        DAT_00509420 = 0x16;
        return -1;
      }
    }
    else if ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                       (arg_1 & 0x1f) * 8) & 0x80) != 0) {
      for (local_8 = fp->_base; local_8 < fp->_ptr; local_8 = local_8 + 1) {
        if (*local_8 == '\n') {
          local_1c = local_1c + 1;
        }
      }
    }
    if (local_20 != 0) {
      if ((fp->_flag & 1) != 0) {
        if (fp->_cnt == 0) {
          local_1c = 0;
        }
        else {
          local_14 = fp->_ptr + (fp->_cnt - (int)fp->_base);
          if (((int)*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                             (arg_1 & 0x1f) * 8) & 0x80U) != 0) {
            lVar3 = __lseek(arg_1,0,2);
            if (lVar3 == local_20) {
              pcVar4 = fp->_base + (int)local_14;
              for (local_8 = fp->_base; local_8 < pcVar4; local_8 = local_8 + 1) {
                if (*local_8 == '\n') {
                  local_14 = local_14 + 1;
                }
              }
              if ((fp->_flag & 0x2000) != 0) {
                local_14 = local_14 + 1;
              }
            }
            else {
              __lseek(arg_1,local_20,0);
              if (((local_14 < (char *)0x201) && ((fp->_flag & 8) != 0)) &&
                 ((fp->_flag & 0x400) == 0)) {
                local_14 = (char *)0x200;
              }
              else {
                local_14 = (char *)fp->_bufsiz;
              }
              if ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0) >> 3)) + 4 +
                            (arg_1 & 0x1f) * 8) & 4) != 0) {
                local_14 = local_14 + 1;
              }
            }
          }
          local_20 = local_20 - (int)local_14;
        }
      }
      local_1c = local_20 + local_1c;
    }
  }
  return local_1c;
}


