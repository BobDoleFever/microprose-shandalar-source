/*
 * aw_cmp.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___crtCompareStringW
 * Entry Point: 004edd00
 * Size: 746 bytes
 */


/* Library Function - Single Match
    ___crtCompareStringW
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtCompareStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPCWSTR arg_5,int arg_6)

{
  int reg_eax;
  int cbMultiByte;
  PCNZCH lpMultiByteStr;
  int val_1;
  int val_2;
  UINT stack_arg;
  LPSTR slot_idx;
  
  if (DAT_0050a8e0 == 0) {
    reg_eax = CompareStringW(0,0,L"",1,L"",1);
    if (reg_eax == 0) {
      reg_eax = CompareStringA(0,0,"",1,"",1);
      if (reg_eax == 0) {
        return 0;
      }
      DAT_0050a8e0 = 2;
    }
    else {
      DAT_0050a8e0 = 1;
    }
  }
  if (0 < arg_4) {
    reg_eax = wcsncnt(arg_3,arg_4);
    arg_4 = reg_eax;
  }
  if (0 < arg_6) {
    reg_eax = wcsncnt(arg_5,arg_6);
    arg_6 = reg_eax;
  }
  if ((arg_4 == 0) || (arg_6 == 0)) {
    if (arg_4 == arg_6) {
      reg_eax = 2;
    }
    else if (arg_4 - arg_6 < 0) {
      reg_eax = 1;
    }
    else {
      reg_eax = 3;
    }
  }
  else if (DAT_0050a8e0 == 1) {
    reg_eax = CompareStringW((LCID)arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
  }
  else if (DAT_0050a8e0 == 2) {
    slot_idx = (LPSTR)0x0;
    if (stack_arg == 0) {
      stack_arg = DAT_0050a740;
    }
    cbMultiByte = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
    if (cbMultiByte == 0) {
      reg_eax = 0;
    }
    else {
      lpMultiByteStr = (PCNZCH)__malloc_dbg(cbMultiByte,2,"aw_cmp.c",0xc4);
      if (lpMultiByteStr == (PCNZCH)0x0) {
        reg_eax = 0;
      }
      else {
        val_1 = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,lpMultiByteStr,cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if ((((val_1 == 0) ||
             (val_1 = WideCharToMultiByte(stack_arg,0x220,arg_5,arg_6,(LPSTR)0x0,0,
                                          (LPCSTR)0x0,(LPBOOL)0x0), val_1 == 0)) ||
            (slot_idx = (LPSTR)__malloc_dbg(val_1,2,"aw_cmp.c",0xd5), slot_idx == (LPSTR)0x0)) ||
           (val_2 = WideCharToMultiByte(stack_arg,0x220,arg_5,arg_6,slot_idx,val_1,
                                        (LPCSTR)0x0,(LPBOOL)0x0), val_2 == 0)) {
          __free_dbg(lpMultiByteStr,2);
          __free_dbg(slot_idx,2);
          reg_eax = 0;
        }
        else {
          reg_eax = CompareStringA((LCID)arg_1,arg_2,lpMultiByteStr,cbMultiByte,slot_idx,val_1);
          __free_dbg(lpMultiByteStr,2);
          __free_dbg(slot_idx,2);
        }
      }
    }
  }
  return reg_eax;
}



/*
 * Decompiled function: wcsncnt
 * Entry Point: 004edff0
 * Size: 108 bytes
 */


/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Debug */

int __cdecl wcsncnt(short *arg1,int arg2)

{
  int match_count;
  short *slot_idx;
  
  match_count = arg2;
  for (slot_idx = arg1; (match_count != 0 && (*slot_idx != 0)); slot_idx = slot_idx + 1) {
    match_count = match_count + -1;
  }
  if (*slot_idx == 0) {
    arg2 = (int)slot_idx - (int)arg1 >> 1;
  }
  return arg2;
}



/*
 * Decompiled function: ___crtCompareStringA
 * Entry Point: 004ee060
 * Size: 1107 bytes
 */


/* Library Function - Single Match
    ___crtCompareStringA
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtCompareStringA
          (_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPCSTR arg_6,int arg_7,
          int arg_8)

{
  code *char_ptr_1;
  LPCSTR reg_eax;
  BOOL BVar2;
  int val_3;
  BYTE *local_30;
  _cpinfo local_2c;
  LPCSTR target_idx;
  LPWSTR player_idx;
  LPWSTR card_idx;
  int match_count;
  int slot_idx;
  
  if (DAT_0050a8e4 == 0) {
    reg_eax = (LPCSTR)CompareStringA(0,0,"",1,"",1);
    if (reg_eax == (LPCSTR)0x0) {
      reg_eax = (LPCSTR)CompareStringW(0,0,L"",1,L"",1);
      if (reg_eax == (LPCSTR)0x0) {
        return 0;
      }
      DAT_0050a8e4 = 1;
    }
    else {
      DAT_0050a8e4 = 2;
    }
  }
  target_idx = reg_eax;
  if (0 < (int)arg_4) {
    target_idx = (LPCSTR)_strncnt((char *)arg_3,(size_t)arg_4);
    arg_4 = target_idx;
  }
  if (0 < (int)arg_6) {
    target_idx = (LPCSTR)_strncnt((char *)arg_5,(size_t)arg_6);
    arg_6 = target_idx;
  }
  if (DAT_0050a8e4 == 2) {
    target_idx = (LPCSTR)CompareStringA((LCID)arg_1,(DWORD)arg_2,(PCNZCH)arg_3,(int)arg_4,
                                      (PCNZCH)arg_5,(int)arg_6);
  }
  else if (DAT_0050a8e4 == 1) {
    target_idx = (LPCSTR)0x0;
    slot_idx = 0;
    match_count = 0;
    card_idx = (LPWSTR)0x0;
    player_idx = (LPWSTR)0x0;
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
         (val_3 = __CrtDbgReport(2,0x4f1310,0x162,0,
                                 "cchCount1==0 && cchCount2==1 || cchCount1==1 && cchCount2==0"),
         val_3 == 1)) {
        char_ptr_1 = (code *)swi(3);
        val_3 = (*char_ptr_1)();
        return val_3;
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
          if ((*local_30 <= *(uint8_t *)arg_3) && (*(uint8_t *)arg_3 <= local_30[1])) break;
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
          if ((*local_30 <= *(uint8_t *)arg_5) && (*(uint8_t *)arg_5 <= local_30[1])) break;
          local_30 = local_30 + 2;
        }
        return 2;
      }
    }
    slot_idx = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_3,(int)arg_4,(LPWSTR)0x0,0);
    if (slot_idx == 0) {
      target_idx = (LPCSTR)0x0;
    }
    else {
      card_idx = (LPWSTR)__malloc_dbg(slot_idx * 2,2,"aw_cmp.c",0x18a);
      if (card_idx == (LPWSTR)0x0) {
        target_idx = (LPCSTR)0x0;
      }
      else {
        val_3 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_3,(int)arg_4,card_idx,slot_idx);
        if ((((val_3 != 0) &&
             (match_count = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_5,(int)arg_6,(LPWSTR)0x0,0),
             match_count != 0)) &&
            (player_idx = (LPWSTR)__malloc_dbg(match_count * 2,2,"aw_cmp.c",0x199),
            player_idx != (LPWSTR)0x0)) &&
           (val_3 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_5,(int)arg_6,player_idx,match_count),
           val_3 != 0)) {
          target_idx = (LPCSTR)CompareStringW((LCID)arg_1,(DWORD)arg_2,card_idx,slot_idx,player_idx,
                                            match_count);
        }
        __free_dbg(card_idx,2);
        __free_dbg(player_idx,2);
      }
    }
  }
  return (int)target_idx;
}



/*
 * Decompiled function: _strncnt
 * Entry Point: 004ee4c0
 * Size: 100 bytes
 */


/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _strncnt(char *filepath,size_t arg_2)

{
  size_t match_count;
  char *slot_idx;
  
  match_count = arg_2;
  for (slot_idx = str_1; (match_count != 0 && (*slot_idx != '\0')); slot_idx = slot_idx + 1) {
    match_count = match_count - 1;
  }
  if (*slot_idx == '\0') {
    arg_2 = (int)slot_idx - (int)str_1;
  }
  return arg_2;
}



