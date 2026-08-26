/*
 * aw_str.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___crtGetStringTypeW
 * Entry Point: 004e6240
 * Size: 607 bytes
 */


/* Library Function - Single Match
    ___crtGetStringTypeW
   
   Library: Visual Studio 1998 Debug */

void ___crtGetStringTypeW(DWORD arg_1,LPCWSTR arg_2,int event_type,LPWORD arg_4,UINT arg_5,LCID arg_6)

{
  BOOL BVar1;
  int arg_2_00;
  LPCSTR lpMultiByteStr;
  int val_2;
  LPWORD card_idx;
  WORD slot_idx [2];
  
  if (DAT_0050a59c == 0) {
    BVar1 = GetStringTypeW(1,L"",1,slot_idx);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,slot_idx);
      if (BVar1 == 0) {
        return;
      }
      DAT_0050a59c = 2;
    }
    else {
      DAT_0050a59c = 1;
    }
  }
  if (DAT_0050a59c == 1) {
    GetStringTypeW(arg_1,arg_2,arg_3,arg_4);
  }
  else if (DAT_0050a59c == 2) {
    card_idx = (LPWORD)0x0;
    if (arg_5 == 0) {
      arg_5 = DAT_0050a740;
    }
    arg_2_00 = WideCharToMultiByte(arg_5,0x220,arg_2,arg_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((arg_2_00 != 0) &&
       (lpMultiByteStr = (LPCSTR)__calloc_dbg(1,arg_2_00,2,"aw_str.c",0x76),
       lpMultiByteStr != (LPCSTR)0x0)) {
      val_2 = WideCharToMultiByte(arg_5,0x220,arg_2,arg_3,lpMultiByteStr,arg_2_00,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if ((val_2 != 0) &&
         (card_idx = (LPWORD)__malloc_dbg(arg_2_00 * 2 + 2,2,"aw_str.c",0x80),
         card_idx != (LPWORD)0x0)) {
        if (arg_6 == 0) {
          arg_6 = DAT_0050a730;
        }
        card_idx[arg_3] = 0xffff;
        card_idx[arg_3 + -1] = card_idx[arg_3];
        GetStringTypeA(arg_6,arg_1,lpMultiByteStr,arg_2_00,card_idx);
        if ((card_idx[arg_3 + -1] != 0xffff) && (card_idx[arg_3] == 0xffff)) {
          FID_conflict__memcpy(arg_4,card_idx,arg_3 * 2);
        }
      }
      __free_dbg(lpMultiByteStr,2);
      __free_dbg(card_idx,2);
    }
  }
  return;
}



/*
 * Decompiled function: ___crtGetStringTypeA
 * Entry Point: 004e64a0
 * Size: 406 bytes
 */


/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 1998 Debug */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t arg_1,DWORD arg_2,LPCSTR arg_3,int arg_4,LPWORD arg_5,int arg_6,BOOL arg_7)

{
  BOOL reg_eax;
  int val_1;
  LPCWSTR player_idx;
  BOOL match_count;
  WORD slot_idx [2];
  
  match_count = reg_eax;
  if (DAT_0050a5a0 == 0) {
    match_count = GetStringTypeA(0,1,"",1,slot_idx);
    if (match_count == 0) {
      match_count = GetStringTypeW(1,L"",1,slot_idx);
      if (match_count == 0) {
        return 0;
      }
      DAT_0050a5a0 = 1;
    }
    else {
      DAT_0050a5a0 = 2;
    }
  }
  if (DAT_0050a5a0 == 2) {
    if (arg_6 == 0) {
      arg_6 = DAT_0050a730;
    }
    match_count = GetStringTypeA(arg_6,(DWORD)arg_1,(LPCSTR)arg_2,(int)arg_3,(LPWORD)arg_4);
  }
  else if (DAT_0050a5a0 == 1) {
    match_count = 0;
    player_idx = (LPCWSTR)0x0;
    if (arg_5 == (LPWORD)0x0) {
      arg_5 = DAT_0050a740;
    }
    val_1 = MultiByteToWideChar((UINT)arg_5,9,(LPCSTR)arg_2,(int)arg_3,(LPWSTR)0x0,0);
    if (((val_1 != 0) &&
        (player_idx = (LPCWSTR)__calloc_dbg(2,val_1,2,"aw_str.c",0x104), player_idx != (LPCWSTR)0x0)) &&
       (val_1 = MultiByteToWideChar((UINT)arg_5,1,(LPCSTR)arg_2,(int)arg_3,player_idx,val_1),
       val_1 != 0)) {
      match_count = GetStringTypeW((DWORD)arg_1,player_idx,val_1,(LPWORD)arg_4);
    }
    __free_dbg(player_idx,2);
  }
  return match_count;
}



