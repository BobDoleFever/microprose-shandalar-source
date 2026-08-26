/*
 * Decompiled function: _fread
 * Entry Point: 004da400
 * Size: 456 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _fread(void *ptr_1,size_t arg_2,size_t arg_3,FILE *fp)

{
  uint uVar1;
  uint arg_3_00;
  int iVar2;
  uint local_20;
  uint local_1c;
  uint local_10;
  undefined1 *local_c;
  undefined1 local_8;
  
  local_c = ptr_1;
  uVar1 = arg_3 * arg_2;
  if (uVar1 == 0) {
    arg_3 = 0;
  }
  else {
    local_10 = uVar1;
    if ((fp->_flag & 0x10cU) == 0) {
      local_20 = 0x1000;
    }
    else {
      local_20 = fp->_bufsiz;
    }
    while (local_10 != 0) {
      if (((fp->_flag & 0x10cU) == 0) || (fp->_cnt == 0)) {
        if (local_10 < local_20) {
          iVar2 = __filbuf(fp);
          if (iVar2 == -1) {
            return (uVar1 - local_10) / arg_2;
          }
          local_8 = (undefined1)iVar2;
          *local_c = local_8;
          local_c = local_c + 1;
          local_10 = local_10 - 1;
          local_20 = fp->_bufsiz;
        }
        else {
          if (local_20 == 0) {
            local_1c = local_10;
          }
          else {
            local_1c = local_10 - local_10 % local_20;
          }
          iVar2 = __read(fp->_file,local_c,local_1c);
          if (iVar2 == 0) {
            fp->_flag = fp->_flag | 0x10;
            return (uVar1 - local_10) / arg_2;
          }
          if (iVar2 == -1) {
            fp->_flag = fp->_flag | 0x20;
            return (uVar1 - local_10) / arg_2;
          }
          local_10 = local_10 - iVar2;
          local_c = local_c + iVar2;
        }
      }
      else {
        arg_3_00 = fp->_cnt;
        if (local_10 <= (uint)fp->_cnt) {
          arg_3_00 = local_10;
        }
        FID_conflict__memcpy(local_c,fp->_ptr,arg_3_00);
        local_10 = local_10 - arg_3_00;
        fp->_cnt = fp->_cnt - arg_3_00;
        fp->_ptr = fp->_ptr + arg_3_00;
        local_c = local_c + arg_3_00;
      }
    }
  }
  return arg_3;
}


