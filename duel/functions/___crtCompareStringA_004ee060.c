/*
 * Decompiled function: ___crtCompareStringA
 * Entry Point: 004ee060
 * Size: 1107 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtCompareStringA
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtCompareStringA
          (_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPCSTR arg_6,int arg_7,
          int arg_8)

{
  code *pcVar1;
  LPCSTR in_EAX;
  BOOL BVar2;
  int iVar3;
  BYTE *local_30;
  _cpinfo local_2c;
  LPCSTR local_18;
  LPWSTR local_14;
  LPWSTR local_10;
  int local_c;
  int local_8;
  
  if (DAT_0050a8e4 == 0) {
    in_EAX = (LPCSTR)CompareStringA(0,0,"",1,"",1);
    if (in_EAX == (LPCSTR)0x0) {
      in_EAX = (LPCSTR)CompareStringW(0,0,L"",1,L"",1);
      if (in_EAX == (LPCSTR)0x0) {
        return 0;
      }
      DAT_0050a8e4 = 1;
    }
    else {
      DAT_0050a8e4 = 2;
    }
  }
  local_18 = in_EAX;
  if (0 < (int)arg_4) {
    local_18 = (LPCSTR)_strncnt((char *)arg_3,(size_t)arg_4);
    arg_4 = local_18;
  }
  if (0 < (int)arg_6) {
    local_18 = (LPCSTR)_strncnt((char *)arg_5,(size_t)arg_6);
    arg_6 = local_18;
  }
  if (DAT_0050a8e4 == 2) {
    local_18 = (LPCSTR)CompareStringA((LCID)arg_1,(DWORD)arg_2,(PCNZCH)arg_3,(int)arg_4,
                                      (PCNZCH)arg_5,(int)arg_6);
  }
  else if (DAT_0050a8e4 == 1) {
    local_18 = (LPCSTR)0x0;
    local_8 = 0;
    local_c = 0;
    local_10 = (LPWSTR)0x0;
    local_14 = (LPWSTR)0x0;
    if (arg_7 == 0) {
      arg_7 = DAT_0050a740;
    }
    if ((arg_4 == (LPCSTR)0x0) || (arg_6 == (LPCSTR)0x0)) {
      if (arg_6 == arg_4) {
        return 2;
      }
      if (1 < (int)arg_6) {
        return 1;
      }
      if (1 < (int)arg_4) {
        return 3;
      }
      BVar2 = GetCPInfo(arg_7,&local_2c);
      if (BVar2 == 0) {
        return 0;
      }
      if ((((arg_4 != (LPCSTR)0x0) || (arg_6 != (LPCSTR)0x1)) &&
          ((arg_4 != (LPCSTR)0x1 || (arg_6 != (LPCSTR)0x0)))) &&
         (iVar3 = __CrtDbgReport(2,0x4f1310,0x162,0,
                                 "cchCount1==0 && cchCount2==1 || cchCount1==1 && cchCount2==0"),
         iVar3 == 1)) {
        pcVar1 = (code *)swi(3);
        iVar3 = (*pcVar1)();
        return iVar3;
      }
      if (0 < (int)arg_4) {
        if (local_2c.MaxCharSize < 2) {
          return 3;
        }
        local_30 = local_2c.LeadByte;
        while( true ) {
          if ((*local_30 == 0) || (local_30[1] == 0)) {
            return 3;
          }
          if ((*local_30 <= *(byte *)arg_3) && (*(byte *)arg_3 <= local_30[1])) break;
          local_30 = local_30 + 2;
        }
        return 2;
      }
      if (0 < (int)arg_6) {
        if (local_2c.MaxCharSize < 2) {
          return 1;
        }
        local_30 = local_2c.LeadByte;
        while( true ) {
          if ((*local_30 == 0) || (local_30[1] == 0)) {
            return 1;
          }
          if ((*local_30 <= *(byte *)arg_5) && (*(byte *)arg_5 <= local_30[1])) break;
          local_30 = local_30 + 2;
        }
        return 2;
      }
    }
    local_8 = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_3,(int)arg_4,(LPWSTR)0x0,0);
    if (local_8 == 0) {
      local_18 = (LPCSTR)0x0;
    }
    else {
      local_10 = (LPWSTR)__malloc_dbg(local_8 * 2,2,"aw_cmp.c",0x18a);
      if (local_10 == (LPWSTR)0x0) {
        local_18 = (LPCSTR)0x0;
      }
      else {
        iVar3 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_3,(int)arg_4,local_10,local_8);
        if ((((iVar3 != 0) &&
             (local_c = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_5,(int)arg_6,(LPWSTR)0x0,0),
             local_c != 0)) &&
            (local_14 = (LPWSTR)__malloc_dbg(local_c * 2,2,"aw_cmp.c",0x199),
            local_14 != (LPWSTR)0x0)) &&
           (iVar3 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_5,(int)arg_6,local_14,local_c),
           iVar3 != 0)) {
          local_18 = (LPCSTR)CompareStringW((LCID)arg_1,(DWORD)arg_2,local_10,local_8,local_14,
                                            local_c);
        }
        __free_dbg(local_10,2);
        __free_dbg(local_14,2);
      }
    }
  }
  return (int)local_18;
}


