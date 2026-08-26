/*
 * Decompiled function: __tzset
 * Entry Point: 004e9930
 * Size: 861 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __tzset
   
   Library: Visual Studio 1998 Debug */

void __cdecl __tzset(void)

{
  char cVar1;
  uint *arg2;
  DWORD DVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  undefined4 arg_2;
  char *arg_3;
  undefined4 arg_4;
  uint *local_c;
  
  DAT_005edc20 = 0;
  DAT_0050a800 = 0xffffffff;
  DAT_0050a7f0 = 0xffffffff;
  arg2 = (uint *)_getenv("TZ");
  if (arg2 == (uint *)0x0) {
    DVar2 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_005edc28);
    if (DVar2 != 0) {
      DAT_005edc20 = 1;
      DAT_0050a750 = DAT_005edc28 * 0x3c;
      if (DAT_005edc6e != 0) {
        DAT_0050a750 = DAT_0050a750 + DAT_005edc7c * 0x3c;
      }
      if ((DAT_005edcc2 == 0) || (DAT_005edcd0 == 0)) {
        DAT_0050a754 = 0;
        DAT_0050a758 = 0;
      }
      else {
        DAT_0050a754 = 1;
        DAT_0050a758 = (DAT_005edcd0 - DAT_005edc7c) * 0x3c;
      }
      _wcstombs(PTR_DAT_0050a7e0,(wchar_t *)&DAT_005edc2c,0x40);
      _wcstombs(PTR_DAT_0050a7e4,(wchar_t *)&DAT_005edc80,0x40);
      PTR_DAT_0050a7e4[0x3f] = 0;
      PTR_DAT_0050a7e0[0x3f] = PTR_DAT_0050a7e4[0x3f];
    }
  }
  else if (((char)*arg2 != '\0') &&
          ((DAT_0050a7e8 == (uint *)0x0 ||
           (iVar3 = _strcmp((char *)arg2,(char *)DAT_0050a7e8), iVar3 != 0)))) {
    __free_dbg(DAT_0050a7e8,2);
    arg_4 = 0xec;
    arg_3 = "tzset.c";
    arg_2 = 2;
    sVar4 = _strlen((char *)arg2);
    DAT_0050a7e8 = (uint *)__malloc_dbg(sVar4 + 1,arg_2,arg_3,arg_4);
    if (DAT_0050a7e8 != (uint *)0x0) {
      Mem_AllocOrFree_004d9630(DAT_0050a7e8,arg2);
      _strncpy(PTR_DAT_0050a7e0,(char *)arg2,3);
      PTR_DAT_0050a7e0[3] = 0;
      local_c = (uint *)((int)arg2 + 3);
      cVar1 = *(char *)local_c;
      if (cVar1 == '-') {
        local_c = arg2 + 1;
      }
      lVar5 = _atol((char *)local_c);
      DAT_0050a750 = lVar5 * 0xe10;
      for (; ((char)*local_c == '+' || (('/' < (char)*local_c && ((char)*local_c < ':'))));
          local_c = (uint *)((int)local_c + 1)) {
      }
      if ((char)*local_c == ':') {
        local_c = (uint *)((int)local_c + 1);
        lVar5 = _atol((char *)local_c);
        DAT_0050a750 = DAT_0050a750 + lVar5 * 0x3c;
        for (; ('/' < (char)*local_c && ((char)*local_c < ':'));
            local_c = (uint *)((int)local_c + 1)) {
        }
        if ((char)*local_c == ':') {
          local_c = (uint *)((int)local_c + 1);
          lVar5 = _atol((char *)local_c);
          DAT_0050a750 = DAT_0050a750 + lVar5;
          for (; ('/' < (char)*local_c && ((char)*local_c < ':'));
              local_c = (uint *)((int)local_c + 1)) {
          }
        }
      }
      if (cVar1 == '-') {
        DAT_0050a750 = -DAT_0050a750;
      }
      DAT_0050a754 = (int)(char)*local_c;
      if (DAT_0050a754 == 0) {
        *PTR_DAT_0050a7e4 = 0;
      }
      else {
        _strncpy(PTR_DAT_0050a7e4,(char *)local_c,3);
        PTR_DAT_0050a7e4[3] = 0;
      }
    }
  }
  return;
}


