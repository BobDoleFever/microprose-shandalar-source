/*
 * Decompiled function: entry
 * Entry Point: 004dea30
 * Size: 494 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte *pbVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE arg_1;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 arg_2;
  byte *local_68;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004f0b48;
  puStack_10 = &LAB_004e85a4;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff84;
  DVar2 = GetVersion();
  _DAT_00509438 = DVar2 >> 8 & 0xff;
  DAT_00509434 = DVar2 & 0xff;
  _DAT_00509430 = DAT_00509434 * 0x100 + _DAT_00509438;
  DAT_0050942c = DVar2 >> 0x10;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_006c2ca8 = (byte *)GetCommandLineA();
  DAT_005096dc = ___crtGetEnvironmentStringsA();
  if ((DAT_005096dc != (LPVOID)0x0) && (DAT_006c2ca8 != (byte *)0x0)) {
    __setargv();
    Mem_AllocOrFree_004b9420();
    __cinit(unaff_EDI);
    local_68 = DAT_006c2ca8;
    pbVar1 = local_68;
    if (*DAT_006c2ca8 == 0x22) {
      while ((local_68 = pbVar1, pbVar1 = local_68 + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
        iVar3 = __ismbblead((uint)*pbVar1);
        if (iVar3 != 0) {
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
    iVar3 = Palette_Subsystem_00495958(arg_1,arg_2,(char *)local_68);
                    /* WARNING: Subroutine does not return */
    _exit(iVar3);
  }
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}


