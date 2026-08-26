/*
 * Decompiled function: __CrtDbgReport
 * Entry Point: 00406c90
 * Size: 998 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtDbgReport
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __CrtDbgReport(int arg_1,int arg_2,int arg_3,int32_t arg_4,char *str_5)

{
  bool flag_1;
  LONG LVar2;
  size_t nNumberOfBytesToWrite;
  undefined3 extraout_var;
  int val_3;
  int32_t *puVar4;
  char local_3028 [20];
  DWORD local_3014;
  HMODULE local_3010;
  uint8_t local_300c;
  int32_t local_300b;
  uint8_t local_200c;
  int32_t local_200b;
  int32_t local_100c;
  va_list local_1008;
  uint8_t local_1004;
  int32_t local_1003;
  int32_t uStackY_2c;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  
  FUN_004080b0();
  local_300c = 0;
  puVar4 = &local_300b;
  for (val_3 = 0x3ff; val_3 != 0; val_3 = val_3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(int16_t *)puVar4 = 0;
  *(uint8_t *)((int)puVar4 + 2) = 0;
  local_200c = '\0';
  puVar4 = &local_200b;
  for (val_3 = 0x3ff; val_3 != 0; val_3 = val_3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(int16_t *)puVar4 = 0;
  *(uint8_t *)((int)puVar4 + 2) = 0;
  local_1004 = '\0';
  puVar4 = &local_1003;
  for (val_3 = 0x3ff; val_3 != 0; val_3 = val_3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(int16_t *)puVar4 = 0;
  *(uint8_t *)((int)puVar4 + 2) = 0;
  local_1008 = &stack0x00000018;
  if ((arg_1 < 0) || (2 < arg_1)) {
    local_100c = 0xffffffff;
  }
  else if ((arg_1 == 2) && (LVar2 = InterlockedIncrement((LONG *)&DAT_004138c0), 0 < LVar2)) {
    if ((DAT_004138f4 == (FARPROC)0x0) &&
       ((local_3010 = LoadLibraryA("user32.dll"), local_3010 == (HMODULE)0x0 ||
        (DAT_004138f4 = GetProcAddress(local_3010,"wsprintfA"), DAT_004138f4 == (FARPROC)0x0)))) {
      local_100c = 0xffffffff;
    }
    else {
      (*DAT_004138f4)();
      OutputDebugStringA(&local_200c);
      InterlockedDecrement((LONG *)&DAT_004138c0);
      __CrtDbgBreak();
      local_100c = 0xffffffff;
    }
  }
  else {
    if ((str_5 != (char *)0x0) &&
       (val_3 = __vsnprintf(&local_1004,0xfed,str_5,local_1008), val_3 < 0)) {
      FUN_00405450((uint32_t *)&local_1004,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
    }
    if (arg_1 == 2) {
      FUN_00405450((uint32_t *)&local_300c,
                   (uint32_t *)("Assertion failed: " + ((str_5 != (char *)0x0) - 1 & 0xffffffec)));
    }
    FUN_00405460((uint32_t *)&local_300c,(uint32_t *)&local_1004);
    if (arg_1 == 2) {
      if ((bRam004138d0 & 1) != 0) {
        FUN_00405460((uint32_t *)&local_300c,(uint32_t *)&DAT_00410b20);
      }
      FUN_00405460((uint32_t *)&local_300c,(uint32_t *)&DAT_00410b1c);
    }
    if (arg_2 == 0) {
      FUN_00405450((uint32_t *)&local_200c,(uint32_t *)&local_300c);
    }
    else {
      uStackY_2c = 0x406ecd;
      val_3 = __snprintf(&local_200c,0x1000,"%s(%d) : %s");
      if (val_3 < 0) {
        FUN_00405450((uint32_t *)&local_200c,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
      }
    }
    if ((DAT_00415694 == (code *)0x0) || (val_3 = (*DAT_00415694)(), val_3 == 0)) {
      if ((((&DAT_004138c8)[arg_1 * 4] & 1) != 0) && (*(int *)(&DAT_004138d8 + arg_1 * 4) != -1)) {
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_3014;
        nNumberOfBytesToWrite = _strlen(&local_200c);
        WriteFile(*(HANDLE *)(&DAT_004138d8 + arg_1 * 4),&local_200c,nNumberOfBytesToWrite,
                  lpNumberOfBytesWritten,lpOverlapped);
      }
      if (((&DAT_004138c8)[arg_1 * 4] & 2) != 0) {
        OutputDebugStringA(&local_200c);
      }
      if (((&DAT_004138c8)[arg_1 * 4] & 4) == 0) {
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_004138c0);
        }
        local_100c = 0;
      }
      else {
        if (arg_3 != 0) {
          __itoa(arg_3,local_3028,10);
        }
        flag_1 = _CrtMessageWindow();
        local_100c = CONCAT31(extraout_var,flag_1);
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_004138c0);
        }
      }
    }
    else if (arg_1 == 2) {
      InterlockedDecrement((LONG *)&DAT_004138c0);
    }
  }
  return local_100c;
}


