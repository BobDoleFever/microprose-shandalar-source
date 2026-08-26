/*
 * Decompiled function: _CrtMessageWindow
 * Entry Point: 004e0400
 * Size: 813 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _CrtMessageWindow
   
   Library: Visual Studio 1998 Debug */

bool _CrtMessageWindow(void)

{
  int iVar1;
  DWORD DVar2;
  size_t sVar3;
  char *in_stack_00000010;
  int in_stack_00000014;
  uint local_1110 [1009];
  char acStackY_14c [60];
  int local_110;
  uint local_10c [47];
  undefined4 uStackY_50;
  
  Mem_AllocOrFree_004ddee0();
  if ((in_stack_00000014 == 0) &&
     (iVar1 = __CrtDbgReport(2,0x4f0dfc,0x1da,0,"szUserMessage != NULL"), iVar1 == 1)) {
    __CrtDbgBreak();
  }
  DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_10c,0x104);
  if (DVar2 == 0) {
    Mem_AllocOrFree_004d9630(local_10c,(uint *)"<program name unknown>");
  }
  sVar3 = _strlen((char *)local_10c);
  if (0x40 < sVar3) {
    sVar3 = _strlen((char *)local_10c);
    _strncpy((char *)((int)local_10c + (sVar3 - 0x40)),"...",3);
  }
  if ((in_stack_00000010 != (char *)0x0) && (sVar3 = _strlen(in_stack_00000010), 0x40 < sVar3)) {
    sVar3 = _strlen(in_stack_00000010);
    _strncpy(in_stack_00000010 + (sVar3 - 0x40),"...",3);
  }
  uStackY_50 = 0x4e06ab;
  iVar1 = __snprintf((char *)local_1110,0x1000,
                     "Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s\n\n(Press Retry to debug the application)"
                    );
  if (iVar1 < 0) {
    Mem_AllocOrFree_004d9630(local_1110,(uint *)"_CrtDbgReport: String too long or IO Error");
  }
  local_110 = ___crtMessageBoxA((LPCSTR)local_1110,"Microsoft Visual C++ Debug Library",0x12012);
  if (local_110 == 3) {
    _raise(0x16);
    __exit(3);
  }
  return local_110 == 4;
}


