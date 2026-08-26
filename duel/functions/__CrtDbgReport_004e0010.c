/*
 * Decompiled function: __CrtDbgReport
 * Entry Point: 004e0010
 * Size: 998 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtDbgReport
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtDbgReport(int arg_1,int arg_2,int arg_3,undefined4 arg_4,char *str_5)

{
  LONG LVar1;
  size_t nNumberOfBytesToWrite;
  int iVar2;
  undefined4 *puVar3;
  char local_3028 [20];
  DWORD local_3014;
  HMODULE local_3010;
  undefined1 local_300c;
  undefined4 local_300b;
  undefined1 local_200c;
  undefined4 local_200b;
  undefined4 local_100c;
  va_list local_1008;
  undefined1 local_1004;
  undefined4 local_1003;
  undefined4 uStackY_2c;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  
  Mem_AllocOrFree_004ddee0();
  local_300c = 0;
  puVar3 = &local_300b;
  for (iVar2 = 0x3ff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_200c = '\0';
  puVar3 = &local_200b;
  for (iVar2 = 0x3ff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_1004 = '\0';
  puVar3 = &local_1003;
  for (iVar2 = 0x3ff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  local_1008 = &stack0x00000018;
  if ((arg_1 < 0) || (2 < arg_1)) {
    local_100c = 0xffffffff;
  }
  else if ((arg_1 == 2) && (LVar1 = InterlockedIncrement((LONG *)&DAT_005096f8), 0 < LVar1)) {
    if ((DAT_0050972c == (FARPROC)0x0) &&
       ((local_3010 = LoadLibraryA("user32.dll"), local_3010 == (HMODULE)0x0 ||
        (DAT_0050972c = GetProcAddress(local_3010,"wsprintfA"), DAT_0050972c == (FARPROC)0x0)))) {
      local_100c = 0xffffffff;
    }
    else {
      (*DAT_0050972c)();
      OutputDebugStringA(&local_200c);
      InterlockedDecrement((LONG *)&DAT_005096f8);
      __CrtDbgBreak();
      local_100c = 0xffffffff;
    }
  }
  else {
    if ((str_5 != (char *)0x0) &&
       (iVar2 = __vsnprintf(&local_1004,0xfed,str_5,local_1008), iVar2 < 0)) {
      Mem_AllocOrFree_004d9630
                ((uint *)&local_1004,(uint *)"_CrtDbgReport: String too long or IO Error");
    }
    if (arg_1 == 2) {
      Mem_AllocOrFree_004d9630
                ((uint *)&local_300c,
                 (uint *)("Assertion failed: " + ((str_5 != (char *)0x0) - 1 & 0xfffff6dc)));
    }
    FUN_004d9640((uint *)&local_300c,(uint *)&local_1004);
    if (arg_1 == 2) {
      if ((bRam00509708 & 1) != 0) {
        FUN_004d9640((uint *)&local_300c,(uint *)&DAT_004f0c60);
      }
      FUN_004d9640((uint *)&local_300c,(uint *)&DAT_004f021c);
    }
    if (arg_2 == 0) {
      Mem_AllocOrFree_004d9630((uint *)&local_200c,(uint *)&local_300c);
    }
    else {
      uStackY_2c = 0x4e024d;
      iVar2 = __snprintf(&local_200c,0x1000,"%s(%d) : %s");
      if (iVar2 < 0) {
        Mem_AllocOrFree_004d9630
                  ((uint *)&local_200c,(uint *)"_CrtDbgReport: String too long or IO Error");
      }
    }
    if ((DAT_006c2ca4 == (code *)0x0) || (iVar2 = (*DAT_006c2ca4)(), iVar2 == 0)) {
      if ((((&DAT_00509700)[arg_1 * 4] & 1) != 0) && (*(int *)(&DAT_00509710 + arg_1 * 4) != -1)) {
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_3014;
        nNumberOfBytesToWrite = _strlen(&local_200c);
        WriteFile(*(HANDLE *)(&DAT_00509710 + arg_1 * 4),&local_200c,nNumberOfBytesToWrite,
                  lpNumberOfBytesWritten,lpOverlapped);
      }
      if (((&DAT_00509700)[arg_1 * 4] & 2) != 0) {
        OutputDebugStringA(&local_200c);
      }
      if (((&DAT_00509700)[arg_1 * 4] & 4) == 0) {
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_005096f8);
        }
        local_100c = 0;
      }
      else {
        if (arg_3 != 0) {
          __itoa(arg_3,local_3028,10);
        }
        local_100c = _CrtMessageWindow();
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_005096f8);
        }
      }
    }
    else if (arg_1 == 2) {
      InterlockedDecrement((LONG *)&DAT_005096f8);
    }
  }
  return local_100c;
}


