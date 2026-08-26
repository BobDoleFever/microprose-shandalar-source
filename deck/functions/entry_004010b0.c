/*
 * Decompiled function: entry
 * Entry Point: 004010b0
 * Size: 494 bytes
 */
#include "deck.h"


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
  uint8_t *local_1c;
  int32_t uStack_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00410058;
  puStack_10 = &LAB_00402f68;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff84;
  DVar2 = GetVersion();
  _DAT_00412a84 = DVar2 >> 8 & 0xff;
  DAT_00412a80 = DVar2 & 0xff;
  _DAT_00412a7c = DAT_00412a80 * 0x100 + _DAT_00412a84;
  DAT_00412a78 = DVar2 >> 0x10;
  val_3 = __heap_init();
  if (val_3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00415818 = (uint8_t *)GetCommandLineA();
  DAT_00412a58 = ___crtGetEnvironmentStringsA();
  if ((DAT_00412a58 != (LPVOID)0x0) && (DAT_00415818 != (uint8_t *)0x0)) {
    __setargv();
    __setenvp();
    __cinit(unaff_EDI);
    local_68 = DAT_00415818;
    pbVar1 = local_68;
    if (*DAT_00415818 == 0x22) {
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
    val_3 = thunk_FUN_00401010(arg_1,arg_2,(char *)local_68);
                    /* WARNING: Subroutine does not return */
    _exit(val_3);
  }
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}


