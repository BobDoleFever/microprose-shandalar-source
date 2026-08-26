/*
 * Decompiled function: __assert
 * Entry Point: 004d9dd0
 * Size: 951 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __assert
   
   Library: Visual Studio 1998 Debug */

void __assert(uint *arg_1,uint *arg_2,int arg_3)

{
  code *pcVar1;
  DWORD DVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  uint local_328 [65];
  uint *local_224;
  uint local_220 [135];
  
  if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
    if ((_DAT_0050979c & 0x10c) == 0) {
      _setvbuf((FILE *)&DAT_00509790,(char *)0x0,4,0);
    }
    _fprintf((FILE *)&DAT_00509790,s_Assertion_failed___s__file__s__l_005093e0,arg_1,arg_2,arg_3);
    _fflush((FILE *)&DAT_00509790);
  }
  else {
    Mem_AllocOrFree_004d9630(local_220,(uint *)"Assertion failed!");
    FUN_004d9640(local_220,(uint *)PTR_DAT_00509410);
    FUN_004d9640(local_220,(uint *)"Program: ");
    DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_328,0x104);
    if (DVar2 == 0) {
      Mem_AllocOrFree_004d9630(local_328,(uint *)"<program name unknown>");
    }
    local_224 = local_328;
    sVar3 = _strlen((char *)local_328);
    if (0x3c < sVar3 + 0xb) {
      sVar3 = _strlen((char *)local_328);
      local_224 = (uint *)((int)local_224 + (sVar3 - 0x31));
      _strncpy((char *)local_224,PTR_DAT_00509408,3);
    }
    FUN_004d9640(local_220,local_224);
    FUN_004d9640(local_220,(uint *)PTR_DAT_0050940c);
    FUN_004d9640(local_220,(uint *)"File: ");
    local_224 = arg_2;
    sVar3 = _strlen((char *)arg_2);
    if (0x3c < sVar3 + 8) {
      sVar3 = _strlen((char *)arg_2);
      local_224 = (uint *)((int)local_224 + (sVar3 - 0x34));
      _strncpy((char *)local_224,PTR_DAT_00509408,3);
    }
    FUN_004d9640(local_220,local_224);
    FUN_004d9640(local_220,(uint *)PTR_DAT_0050940c);
    FUN_004d9640(local_220,(uint *)"Line: ");
    iVar5 = 10;
    sVar3 = _strlen((char *)local_220);
    __itoa(arg_3,(char *)((int)local_220 + sVar3),iVar5);
    FUN_004d9640(local_220,(uint *)PTR_DAT_00509410);
    FUN_004d9640(local_220,(uint *)"Expression: ");
    sVar3 = _strlen((char *)arg_1);
    sVar4 = _strlen((char *)local_220);
    if (sVar3 + sVar4 + 0xb0 < 0x21d) {
      FUN_004d9640(local_220,arg_1);
    }
    else {
      sVar3 = _strlen((char *)local_220);
      _strncat((char *)local_220,(char *)arg_1,0x21c - (sVar3 + 0xb1));
      FUN_004d9640(local_220,(uint *)PTR_DAT_00509408);
    }
    FUN_004d9640(local_220,(uint *)PTR_DAT_00509410);
    FUN_004d9640(local_220,
                 (uint *)
                 "For information on how your program can cause an assertion\nfailure, see the Visual C++ documentation on asserts"
                );
    FUN_004d9640(local_220,(uint *)PTR_DAT_00509410);
    FUN_004d9640(local_220,(uint *)"(Press Retry to debug the application - JIT must be enabled)");
    iVar5 = ___crtMessageBoxA((LPCSTR)local_220,"Microsoft Visual C++ Runtime Library",0x12012);
    if (iVar5 == 3) {
      _raise(0x16);
      __exit(3);
    }
    if (iVar5 == 4) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (iVar5 == 5) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}


