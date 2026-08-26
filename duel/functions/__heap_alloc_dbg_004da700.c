/*
 * Decompiled function: __heap_alloc_dbg
 * Entry Point: 004da700
 * Size: 818 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __heap_alloc_dbg
   
   Library: Visual Studio 1998 Debug */

undefined4 * __heap_alloc_dbg(uint x,uint y,int width,undefined4 arg_4)

{
  code *pcVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  bVar2 = false;
  if (((((byte)DAT_00509470 & 4) != 0) && (iVar4 = __CrtCheckMemory(), iVar4 == 0)) &&
     (iVar4 = __CrtDbgReport(2,0x4f0430,0x141,0,"_CrtCheckMemory()"), iVar4 == 1)) {
    pcVar1 = (code *)swi(3);
    puVar5 = (undefined4 *)(*pcVar1)();
    return puVar5;
  }
  iVar4 = DAT_00509474;
  if (DAT_00509474 == DAT_00509478) {
    pcVar1 = (code *)swi(3);
    puVar5 = (undefined4 *)(*pcVar1)();
    return puVar5;
  }
  iVar6 = (*(code *)PTR_Mem_AllocOrFree_004e1ae0_005099d8)(1,0,x,y,DAT_00509474,width,arg_4);
  if (iVar6 == 0) {
    if (width == 0) {
      iVar4 = __CrtDbgReport(0,0,0,0,"%s");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        puVar5 = (undefined4 *)(*pcVar1)();
        return puVar5;
      }
    }
    else {
      iVar4 = __CrtDbgReport(0,0,0,0,"Client hook allocation failure at file %hs line %d.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        puVar5 = (undefined4 *)(*pcVar1)();
        return puVar5;
      }
    }
    puVar5 = (undefined4 *)0x0;
  }
  else {
    if (((y & 0xffff) != 2) && (((byte)DAT_00509470 & 1) == 0)) {
      bVar2 = true;
    }
    if ((x < 0xffffffe1) && (x + 0x24 < 0xffffffe1)) {
      if (((((y & 0xffff) != 4) && (y != 1)) && ((y & 0xffff) != 2)) &&
         ((y != 3 && (iVar6 = __CrtDbgReport(1,0,0,0,"%s"), iVar6 == 1)))) {
        pcVar1 = (code *)swi(3);
        puVar5 = (undefined4 *)(*pcVar1)();
        return puVar5;
      }
      puVar5 = (undefined4 *)__heap_alloc_base(x + 0x24);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        DAT_00509474 = DAT_00509474 + 1;
        if (bVar2) {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0xfedcbabc;
          puVar5[4] = x;
          puVar5[5] = 3;
          puVar5[6] = 0;
        }
        else {
          DAT_005edac4 = DAT_005edac4 + x;
          DAT_005edacc = DAT_005edacc + x;
          if (DAT_005edad0 < DAT_005edacc) {
            DAT_005edad0 = DAT_005edacc;
          }
          puVar3 = puVar5;
          if (DAT_005edac8 != (undefined4 *)0x0) {
            DAT_005edac8[1] = puVar5;
            puVar3 = DAT_005edac0;
          }
          DAT_005edac0 = puVar3;
          *puVar5 = DAT_005edac8;
          puVar5[1] = 0;
          puVar5[2] = width;
          puVar5[3] = arg_4;
          puVar5[4] = x;
          puVar5[5] = y;
          puVar5[6] = iVar4;
          DAT_005edac8 = puVar5;
        }
        _memset(puVar5 + 7,(uint)DAT_0050947c,4);
        _memset((void *)((int)puVar5 + x + 0x20),(uint)DAT_0050947c,4);
        _memset(puVar5 + 8,(uint)DAT_00509484,x);
        puVar5 = puVar5 + 8;
      }
    }
    else {
      iVar4 = __CrtDbgReport(1,0,0,0,"Invalid allocation size: %u bytes.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        puVar5 = (undefined4 *)(*pcVar1)();
        return puVar5;
      }
      puVar5 = (undefined4 *)0x0;
    }
  }
  return puVar5;
}


