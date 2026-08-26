/*
 * Decompiled function: FID_conflict:__fwrite_lk
 * Entry Point: 004ddf10
 * Size: 536 bytes
 */
#include "duel.h"


/* Library Function - Multiple Matches With Different Base Names
    __fwrite_lk
    _fwrite
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl FID_conflict___fwrite_lk(void *ptr_1,size_t arg_2,size_t arg_3,FILE *fp)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uint local_20;
  uint local_1c;
  uint local_10;
  char *local_c;
  
  local_c = ptr_1;
  uVar1 = arg_3 * arg_2;
  if (uVar1 == 0) {
    sVar2 = 0;
  }
  else {
    local_10 = uVar1;
    if ((fp->_flag & 0x10cU) == 0) {
      local_20 = 0x1000;
    }
    else {
      local_20 = fp->_bufsiz;
    }
    do {
      while( true ) {
        while( true ) {
          if (local_10 == 0) {
            return arg_3;
          }
          if (((fp->_flag & 0x108U) == 0) || (fp->_cnt == 0)) break;
          uVar4 = fp->_cnt;
          if (local_10 <= (uint)fp->_cnt) {
            uVar4 = local_10;
          }
          FID_conflict__memcpy(fp->_ptr,local_c,uVar4);
          local_10 = local_10 - uVar4;
          fp->_cnt = fp->_cnt - uVar4;
          fp->_ptr = fp->_ptr + uVar4;
          local_c = local_c + uVar4;
        }
        if (local_20 <= local_10) break;
        iVar3 = __flsbuf((int)*local_c,fp);
        if (iVar3 == -1) {
          return (uVar1 - local_10) / arg_2;
        }
        local_c = local_c + 1;
        local_10 = local_10 - 1;
        if (fp->_bufsiz < 1) {
          local_20 = 1;
        }
        else {
          local_20 = fp->_bufsiz;
        }
      }
      if (((fp->_flag & 0x108U) != 0) && (iVar3 = __flush(fp), iVar3 != 0)) {
        return (uVar1 - local_10) / arg_2;
      }
      if (local_20 == 0) {
        local_1c = local_10;
      }
      else {
        local_1c = local_10 - local_10 % local_20;
      }
      uVar4 = __write(fp->_file,local_c,local_1c);
      if (uVar4 == 0xffffffff) {
        fp->_flag = fp->_flag | 0x20;
        return (uVar1 - local_10) / arg_2;
      }
      local_10 = local_10 - uVar4;
      local_c = local_c + uVar4;
    } while (local_1c <= uVar4);
    fp->_flag = fp->_flag | 0x20;
    sVar2 = (uVar1 - local_10) / arg_2;
  }
  return sVar2;
}


