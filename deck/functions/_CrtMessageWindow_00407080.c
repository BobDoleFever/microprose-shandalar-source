/*
 * Decompiled function: _CrtMessageWindow
 * Entry Point: 00407080
 * Size: 813 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _CrtMessageWindow
   
   Library: Visual Studio 1998 Debug */

bool _CrtMessageWindow(void)

{
  int val_1;
  DWORD DVar2;
  size_t len_3;
  char *stack_arg;
  int stack_arg;
  uint32_t local_1110 [1009];
  char acStackY_14c [60];
  int local_110;
  uint32_t local_10c [47];
  int32_t uStackY_50;
  
  FUN_004080b0();
  if ((stack_arg == 0) &&
     (val_1 = __CrtDbgReport(2,0x410cd4,0x1da,0,"szUserMessage != NULL"), val_1 == 1)) {
    __CrtDbgBreak();
  }
  DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_10c,0x104);
  if (DVar2 == 0) {
    FUN_00405450(local_10c,(uint32_t *)"<program name unknown>");
  }
  len_3 = _strlen((char *)local_10c);
  if (0x40 < len_3) {
    len_3 = _strlen((char *)local_10c);
    _strncpy((char *)((int)local_10c + (len_3 - 0x40)),"...",3);
  }
  if ((stack_arg != (char *)0x0) && (len_3 = _strlen(stack_arg), 0x40 < len_3)) {
    len_3 = _strlen(stack_arg);
    _strncpy(stack_arg + (len_3 - 0x40),"...",3);
  }
  uStackY_50 = 0x40732b;
  val_1 = __snprintf((char *)local_1110,0x1000,
                     "Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s\n\n(Press Retry to debug the application)"
                    );
  if (val_1 < 0) {
    FUN_00405450(local_1110,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
  }
  local_110 = ___crtMessageBoxA((LPCSTR)local_1110,"Microsoft Visual C++ Debug Library",0x12012);
  if (local_110 == 3) {
    _raise(0x16);
    __exit(3);
  }
  return local_110 == 4;
}


