/*
 * Decompiled function: __sopen
 * Entry Point: 004dd2e0
 * Size: 1355 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __sopen
   
   Library: Visual Studio 1998 Debug */

int __cdecl __sopen(char *filename,int arg_2,int arg_3,...)

{
  uint uVar1;
  DWORD DVar2;
  long lVar3;
  int iVar4;
  bool bVar5;
  uint in_stack_00000010;
  byte local_3c;
  uint local_38;
  char local_34 [4];
  undefined4 local_30;
  uint local_2c;
  _SECURITY_ATTRIBUTES local_28;
  DWORD local_1c;
  uint local_18;
  uint local_14;
  DWORD local_10;
  DWORD local_c;
  HANDLE local_8;
  
  local_28.nLength = 0xc;
  local_28.lpSecurityDescriptor = (LPVOID)0x0;
  bVar5 = (arg_2 & 0x80U) == 0;
  if (bVar5) {
    local_3c = 0;
  }
  else {
    local_3c = 0x10;
  }
  local_28.bInheritHandle = (BOOL)bVar5;
  if ((arg_2 & 0x8000U) == 0) {
    if ((arg_2 & 0x4000U) == 0) {
      if (DAT_0050a598 != 0x8000) {
        local_3c = local_3c | 0x80;
      }
    }
    else {
      local_3c = local_3c | 0x80;
    }
  }
  uVar1 = arg_2 & 3;
  if (uVar1 == 0) {
    local_38 = 0x80000000;
  }
  else if (uVar1 == 1) {
    local_38 = 0x40000000;
  }
  else {
    if (uVar1 != 2) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
    local_38 = 0xc0000000;
  }
  switch(arg_3) {
  case 0x10:
    local_c = 0;
    break;
  default:
    DAT_00509420 = 0x16;
    DAT_00509424 = 0;
    return -1;
  case 0x20:
    local_c = 1;
    break;
  case 0x30:
    local_c = 2;
    break;
  case 0x40:
    local_c = 3;
  }
  uVar1 = arg_2 & 0x700;
  if (uVar1 < 0x101) {
    if (uVar1 == 0x100) {
      local_1c = 4;
      goto LAB_004dd58c;
    }
    if (uVar1 != 0) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
LAB_004dd4a2:
    local_1c = 3;
    goto LAB_004dd58c;
  }
  if (uVar1 < 0x301) {
    if (uVar1 == 0x300) {
      local_1c = 2;
      goto LAB_004dd58c;
    }
    if (uVar1 != 0x200) {
      DAT_00509420 = 0x16;
      DAT_00509424 = 0;
      return -1;
    }
LAB_004dd4c6:
    local_1c = 5;
  }
  else {
    if (uVar1 < 0x501) {
      if (uVar1 != 0x500) {
        if (uVar1 != 0x400) {
          DAT_00509420 = 0x16;
          DAT_00509424 = 0;
          return -1;
        }
        goto LAB_004dd4a2;
      }
    }
    else {
      if (uVar1 == 0x600) goto LAB_004dd4c6;
      if (uVar1 != 0x700) {
        DAT_00509420 = 0x16;
        DAT_00509424 = 0;
        return -1;
      }
    }
    local_1c = 1;
  }
LAB_004dd58c:
  local_2c = 0x80;
  if ((arg_2 & 0x100U) != 0) {
    local_14 = in_stack_00000010;
    local_30 = 0;
    if ((~DAT_00509428 & in_stack_00000010 & 0x80) == 0) {
      local_2c = 1;
    }
  }
  if ((arg_2 & 0x40U) != 0) {
    local_2c = local_2c | 0x4000000;
    local_38 = local_38 | 0x10000;
  }
  if ((arg_2 & 0x1000U) != 0) {
    local_2c = local_2c | 0x100;
  }
  if ((arg_2 & 0x20U) == 0) {
    if ((arg_2 & 0x10U) != 0) {
      local_2c = local_2c | 0x10000000;
    }
  }
  else {
    local_2c = local_2c | 0x8000000;
  }
  local_18 = __alloc_osfhnd();
  if (local_18 == 0xffffffff) {
    DAT_00509420 = 0x18;
    DAT_00509424 = 0;
    local_18 = 0xffffffff;
  }
  else {
    local_8 = CreateFileA(filename,local_38,local_c,&local_28,local_1c,local_2c,(HANDLE)0x0);
    if (local_8 == (HANDLE)0xffffffff) {
      DVar2 = GetLastError();
      __dosmaperr(DVar2);
      local_18 = 0xffffffff;
    }
    else {
      local_10 = GetFileType(local_8);
      if (local_10 == 0) {
        CloseHandle(local_8);
        DVar2 = GetLastError();
        __dosmaperr(DVar2);
        local_18 = 0xffffffff;
      }
      else {
        if (local_10 == 2) {
          local_3c = local_3c | 0x40;
        }
        else if (local_10 == 3) {
          local_3c = local_3c | 8;
        }
        __set_osfhnd(local_18,(intptr_t)local_8);
        *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(local_18 & 0xffffffe0) >> 3)) + 4 +
                 (local_18 & 0x1f) * 8) = local_3c | 1;
        if ((((local_3c & 0x48) == 0) && ((local_3c & 0x80) != 0)) && ((arg_2 & 2U) != 0)) {
          lVar3 = __lseek(local_18,-1,2);
          if (lVar3 == -1) {
            if (DAT_00509424 != 0x83) {
              __close(local_18);
              return -1;
            }
          }
          else {
            local_34[0] = '\0';
            iVar4 = __read(local_18,local_34,1);
            if (((iVar4 == 0) && (local_34[0] == '\x1a')) &&
               (iVar4 = __chsize(local_18,lVar3), iVar4 == -1)) {
              __close(local_18);
              return -1;
            }
            lVar3 = __lseek(local_18,0,0);
            if (lVar3 == -1) {
              __close(local_18);
              return -1;
            }
          }
        }
        if (((local_3c & 0x48) == 0) && ((arg_2 & 8U) != 0)) {
          *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(local_18 & 0xffffffe0) >> 3)) + 4 +
                   (local_18 & 0x1f) * 8) =
               *(byte *)(*(int *)((int)&DAT_006c1b90 + ((int)(local_18 & 0xffffffe0) >> 3)) + 4 +
                        (local_18 & 0x1f) * 8) | 0x20;
        }
      }
    }
  }
  return local_18;
}


