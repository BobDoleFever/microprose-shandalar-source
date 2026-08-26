/*
 * Decompiled function: __CrtCheckMemory
 * Entry Point: 004db8c0
 * Size: 873 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtCheckMemory
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtCheckMemory(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_8 = 1;
  if (((byte)DAT_00509470 & 1) == 0) {
    local_8 = 1;
  }
  else {
    iVar3 = __heapchk();
    if ((iVar3 == -1) || (iVar3 == -2)) {
      for (local_c = DAT_005edac8; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
        bVar2 = true;
        iVar3 = _CheckBytes((char *)(local_c + 7),DAT_0050947c,4);
        if (iVar3 == 0) {
          iVar3 = __CrtDbgReport(0,0,0,0,"DAMAGE: before %hs block (#%d) at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        iVar3 = _CheckBytes((char *)((int)local_c + local_c[4] + 0x20),DAT_0050947c,4);
        if (iVar3 == 0) {
          iVar3 = __CrtDbgReport(0,0,0,0,"DAMAGE: after %hs block (#%d) at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        if ((local_c[5] == 0) &&
           (iVar3 = _CheckBytes((char *)(local_c + 8),DAT_00509480,local_c[4]), iVar3 == 0)) {
          iVar3 = __CrtDbgReport(0,0,0,0,"DAMAGE: on top of Free block at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        if (!bVar2) {
          if ((local_c[2] != 0) &&
             (iVar3 = __CrtDbgReport(0,0,0,0,"%hs allocated at file %hs(%d).\n"), iVar3 == 1)) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          iVar3 = __CrtDbgReport(0,0,0,0,"%hs located at 0x%08X is %u bytes long.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          local_8 = 0;
        }
      }
    }
    else {
      switch(iVar3) {
      case -6:
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -5:
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -4:
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -3:
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      default:
        iVar3 = __CrtDbgReport(0,0,0,0,"%s");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
      }
      local_8 = 0;
    }
  }
  return local_8;
}


