/*
 * Decompiled function: ___crtCompareStringW
 * Entry Point: 004edd00
 * Size: 746 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtCompareStringW
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtCompareStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPCWSTR arg_5,int arg_6)

{
  int in_EAX;
  int cbMultiByte;
  PCNZCH lpMultiByteStr;
  int iVar1;
  int iVar2;
  UINT in_stack_0000001c;
  LPSTR local_8;
  
  if (DAT_0050a8e0 == 0) {
    in_EAX = CompareStringW(0,0,L"",1,L"",1);
    if (in_EAX == 0) {
      in_EAX = CompareStringA(0,0,"",1,"",1);
      if (in_EAX == 0) {
        return 0;
      }
      DAT_0050a8e0 = 2;
    }
    else {
      DAT_0050a8e0 = 1;
    }
  }
  if (0 < arg_4) {
    in_EAX = wcsncnt(arg_3,arg_4);
    arg_4 = in_EAX;
  }
  if (0 < arg_6) {
    in_EAX = wcsncnt(arg_5,arg_6);
    arg_6 = in_EAX;
  }
  if ((arg_4 == 0) || (arg_6 == 0)) {
    if (arg_4 == arg_6) {
      in_EAX = 2;
    }
    else if (arg_4 - arg_6 < 0) {
      in_EAX = 1;
    }
    else {
      in_EAX = 3;
    }
  }
  else if (DAT_0050a8e0 == 1) {
    in_EAX = CompareStringW((LCID)arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
  }
  else if (DAT_0050a8e0 == 2) {
    local_8 = (LPSTR)0x0;
    if (in_stack_0000001c == 0) {
      in_stack_0000001c = DAT_0050a740;
    }
    cbMultiByte = WideCharToMultiByte(in_stack_0000001c,0x220,arg_3,arg_4,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
    if (cbMultiByte == 0) {
      in_EAX = 0;
    }
    else {
      lpMultiByteStr = (PCNZCH)__malloc_dbg(cbMultiByte,2,"aw_cmp.c",0xc4);
      if (lpMultiByteStr == (PCNZCH)0x0) {
        in_EAX = 0;
      }
      else {
        iVar1 = WideCharToMultiByte(in_stack_0000001c,0x220,arg_3,arg_4,lpMultiByteStr,cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if ((((iVar1 == 0) ||
             (iVar1 = WideCharToMultiByte(in_stack_0000001c,0x220,arg_5,arg_6,(LPSTR)0x0,0,
                                          (LPCSTR)0x0,(LPBOOL)0x0), iVar1 == 0)) ||
            (local_8 = (LPSTR)__malloc_dbg(iVar1,2,"aw_cmp.c",0xd5), local_8 == (LPSTR)0x0)) ||
           (iVar2 = WideCharToMultiByte(in_stack_0000001c,0x220,arg_5,arg_6,local_8,iVar1,
                                        (LPCSTR)0x0,(LPBOOL)0x0), iVar2 == 0)) {
          __free_dbg(lpMultiByteStr,2);
          __free_dbg(local_8,2);
          in_EAX = 0;
        }
        else {
          in_EAX = CompareStringA((LCID)arg_1,arg_2,lpMultiByteStr,cbMultiByte,local_8,iVar1);
          __free_dbg(lpMultiByteStr,2);
          __free_dbg(local_8,2);
        }
      }
    }
  }
  return in_EAX;
}


