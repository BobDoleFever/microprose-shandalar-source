/*
 * Decompiled function: __read
 * Entry Point: 004dd990
 * Size: 1156 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __read
   
   Library: Visual Studio 1998 Debug */

int __cdecl __read(int arg_1,void *out_buffer,uint arg_3)

{
  BOOL BVar1;
  char local_20 [4];
  int local_1c;
  void *local_18;
  DWORD local_14;
  char *local_10;
  DWORD local_c;
  char *local_8;
  
  if (((uint)arg_1 < DAT_006c1c90) &&
     ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    local_1c = 0;
    local_18 = out_buffer;
    if ((arg_3 == 0) ||
       ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                  (arg_1 & 0x1fU) * 8) & 2) != 0)) {
      local_1c = 0;
    }
    else {
      if (((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) & 0x48) != 0) &&
         (*(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 +
                   (arg_1 & 0x1fU) * 8) != '\n')) {
        *(undefined1 *)out_buffer =
             *(undefined1 *)
              (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 +
              (arg_1 & 0x1fU) * 8);
        local_18 = (void *)((int)out_buffer + 1);
        local_1c = 1;
        arg_3 = arg_3 - 1;
        *(undefined1 *)
         (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5 + (arg_1 & 0x1fU) * 8
         ) = 10;
      }
      BVar1 = ReadFile(*(HANDLE *)
                        (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                        (arg_1 & 0x1fU) * 8),local_18,arg_3,&local_14,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        local_c = GetLastError();
        if (local_c == 5) {
          DAT_00509420 = 9;
          local_1c = -1;
          DAT_00509424 = 5;
        }
        else if (local_c == 0x6d) {
          local_1c = 0;
        }
        else {
          __dosmaperr(local_c);
          local_1c = -1;
        }
      }
      else {
        local_1c = local_1c + local_14;
        if ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                      (arg_1 & 0x1fU) * 8) & 0x80) != 0) {
          if ((local_14 == 0) || (*(char *)out_buffer != '\n')) {
            *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) =
                 *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) & 0xfb;
          }
          else {
            *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                     (arg_1 & 0x1fU) * 8) =
                 *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                          (arg_1 & 0x1fU) * 8) | 4;
          }
          local_10 = out_buffer;
          local_8 = out_buffer;
          while (local_8 < (char *)(local_1c + (int)out_buffer)) {
            if (*local_8 == '\x1a') {
              if ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                            (arg_1 & 0x1fU) * 8) & 0x40) == 0) {
                *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                         (arg_1 & 0x1fU) * 8) =
                     *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4
                              + (arg_1 & 0x1fU) * 8) | 2;
              }
              break;
            }
            if (*local_8 == '\r') {
              if (local_8 < (char *)((int)out_buffer + local_1c + -1)) {
                if (local_8[1] == '\n') {
                  local_8 = local_8 + 2;
                  *local_10 = '\n';
                }
                else {
                  *local_10 = *local_8;
                  local_8 = local_8 + 1;
                }
                local_10 = local_10 + 1;
              }
              else {
                local_8 = local_8 + 1;
                local_c = 0;
                BVar1 = ReadFile(*(HANDLE *)
                                  (*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3))
                                  + (arg_1 & 0x1fU) * 8),local_20,1,&local_14,(LPOVERLAPPED)0x0);
                if (BVar1 == 0) {
                  local_c = GetLastError();
                }
                if ((local_c == 0) && (local_14 != 0)) {
                  if ((*(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) +
                                 4 + (arg_1 & 0x1fU) * 8) & 0x48) == 0) {
                    if ((out_buffer == local_10) && (local_20[0] == '\n')) {
                      *local_10 = '\n';
                      local_10 = local_10 + 1;
                    }
                    else {
                      __lseek(arg_1,-1,1);
                      if (local_20[0] != '\n') {
                        *local_10 = '\r';
                        local_10 = local_10 + 1;
                      }
                    }
                  }
                  else {
                    if (local_20[0] == '\n') {
                      *local_10 = '\n';
                    }
                    else {
                      *local_10 = '\r';
                      *(char *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 5
                               + (arg_1 & 0x1fU) * 8) = local_20[0];
                    }
                    local_10 = local_10 + 1;
                  }
                }
                else {
                  *local_10 = '\r';
                  local_10 = local_10 + 1;
                }
              }
            }
            else {
              *local_10 = *local_8;
              local_8 = local_8 + 1;
              local_10 = local_10 + 1;
            }
          }
          local_1c = (int)local_10 - (int)out_buffer;
        }
      }
    }
  }
  else {
    DAT_00509420 = 9;
    DAT_00509424 = 0;
    local_1c = -1;
  }
  return local_1c;
}


