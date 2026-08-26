/*
 * Decompiled function: __CrtMemDumpAllObjectsSince
 * Entry Point: 004dc1c0
 * Size: 704 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtMemDumpAllObjectsSince
   
   Library: Visual Studio 1998 Debug */

void __CrtMemDumpAllObjectsSince(undefined4 *arg_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = (undefined4 *)0x0;
  iVar2 = __CrtDbgReport(0,0,0,0,"%s");
  if (iVar2 == 1) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (arg_1 != (undefined4 *)0x0) {
    local_c = (undefined4 *)*arg_1;
  }
  local_8 = DAT_005edac8;
  do {
    if ((local_8 == (undefined4 *)0x0) || (local_8 == local_c)) {
      iVar2 = __CrtDbgReport(0,0,0,0,"%s");
      if (iVar2 != 1) {
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((((local_8[5] & 0xffff) != 3) && ((local_8[5] & 0xffff) != 0)) &&
       (((local_8[5] & 0xffff) != 2 || (((byte)DAT_00509470 & 0x10) != 0)))) {
      if (local_8[2] != 0) {
        iVar2 = __CrtIsValidPointer((void *)local_8[2],1,0);
        if (iVar2 == 0) {
          iVar2 = __CrtDbgReport(0,0,0,0,"#File Error#(%d) : ");
          if (iVar2 == 1) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
        }
        else {
          iVar2 = __CrtDbgReport(0,0,0,0,"%hs(%d) : ");
          if (iVar2 == 1) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
        }
      }
      iVar2 = __CrtDbgReport(0,0,0,0,"{%ld} ");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if ((local_8[5] & 0xffff) == 4) {
        iVar2 = __CrtDbgReport(0,0,0,0,"client block at 0x%08X, subtype %x, %u bytes long.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (DAT_006c2cac == (code *)0x0) {
          __printMemBlockData((int)local_8);
        }
        else {
          (*DAT_006c2cac)(local_8 + 8,local_8[4]);
        }
      }
      else if (local_8[5] == 1) {
        iVar2 = __CrtDbgReport(0,0,0,0,"normal block at 0x%08X, %u bytes long.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        __printMemBlockData((int)local_8);
      }
      else if ((local_8[5] & 0xffff) == 2) {
        iVar2 = __CrtDbgReport(0,0,0,0,"crt block at 0x%08X, subtype %x, %u bytes long.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        __printMemBlockData((int)local_8);
      }
    }
    local_8 = (undefined4 *)*local_8;
  } while( true );
}


