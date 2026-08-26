/*
 * aw_env.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 6
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___crtGetEnvironmentStringsW
 * Entry Point: 004e8080
 * Size: 689 bytes
 */


/* Library Function - Single Match
    ___crtGetEnvironmentStringsW
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsW(void)

{
  LPWCH pWVar1;
  LPWCH reg_eax;
  size_t len_2;
  int val_3;
  LPWCH target_idx;
  LPWCH player_idx;
  int card_idx;
  LPWCH match_count;
  
  target_idx = (LPWCH)0x0;
  card_idx = 0;
  if (DAT_0050a674 == 0) {
    reg_eax = GetEnvironmentStringsW();
    if (reg_eax == (LPWCH)0x0) {
      reg_eax = (LPWCH)GetEnvironmentStrings();
      if (reg_eax == (LPWCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0050a674 = 2;
      target_idx = reg_eax;
    }
    else {
      DAT_0050a674 = 1;
      target_idx = reg_eax;
    }
  }
  if (DAT_0050a674 == 1) {
    if ((target_idx == (LPWCH)0x0) && (target_idx = GetEnvironmentStringsW(), target_idx == (LPWCH)0x0)) {
      reg_eax = (LPWCH)0x0;
    }
    else {
      player_idx = target_idx;
      pWVar1 = player_idx;
      while (player_idx = pWVar1, *player_idx != L'\0') {
        pWVar1 = player_idx + 1;
        if (player_idx[1] == L'\0') {
          pWVar1 = player_idx + 2;
        }
      }
      len_2 = (int)player_idx + (2 - (int)target_idx);
      reg_eax = (LPWCH)__malloc_dbg(len_2,2,"aw_env.c",0x57);
      if (reg_eax == (LPWCH)0x0) {
        FreeEnvironmentStringsW(target_idx);
        reg_eax = (LPWCH)0x0;
      }
      else {
        FID_conflict__memcpy(reg_eax,target_idx,len_2);
        FreeEnvironmentStringsW(target_idx);
      }
    }
  }
  else if (DAT_0050a674 == 2) {
    if ((target_idx == (LPWCH)0x0) &&
       (target_idx = (LPWCH)GetEnvironmentStrings(), target_idx == (LPWCH)0x0)) {
      reg_eax = (LPWCH)0x0;
    }
    else {
      for (match_count = target_idx; (char)*match_count != '\0'; match_count = (LPWCH)((int)match_count + len_2 + 1))
      {
        val_3 = MultiByteToWideChar(DAT_0050a740,1,(LPCSTR)match_count,-1,(LPWSTR)0x0,0);
        if (val_3 == 0) {
          return (LPVOID)0x0;
        }
        card_idx = card_idx + val_3;
        len_2 = _strlen((char *)match_count);
      }
      reg_eax = (LPWCH)__malloc_dbg((card_idx + 1) * 2,2,"aw_env.c",0x87);
      if (reg_eax == (LPWCH)0x0) {
        FreeEnvironmentStringsA((LPCH)target_idx);
        reg_eax = (LPWCH)0x0;
      }
      else {
        match_count = target_idx;
        player_idx = reg_eax;
        while ((char)*match_count != '\0') {
          val_3 = MultiByteToWideChar(DAT_0050a740,1,(LPCSTR)match_count,-1,player_idx,
                                      (card_idx + 1) - ((int)player_idx - (int)reg_eax >> 1));
          if (val_3 == 0) {
            __free_dbg(reg_eax,2);
            FreeEnvironmentStringsA((LPCH)target_idx);
            return (LPVOID)0x0;
          }
          len_2 = _strlen((char *)match_count);
          match_count = (LPWCH)((int)match_count + len_2 + 1);
          len_2 = _wcslen(player_idx);
          player_idx = player_idx + len_2 + 1;
        }
        *player_idx = L'\0';
        FreeEnvironmentStringsA((LPCH)target_idx);
      }
    }
  }
  return reg_eax;
}



/*
 * Decompiled function: ___crtGetEnvironmentStringsA
 * Entry Point: 004e8340
 * Size: 602 bytes
 */


/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char *char_ptr_1;
  LPWCH pWVar2;
  int val_3;
  int cbMultiByte;
  LPSTR ptr_1;
  LPCH color_idx;
  LPWCH target_idx;
  char *card_idx;
  LPWCH match_count;
  
  target_idx = (LPWCH)0x0;
  color_idx = (LPCH)0x0;
  if (DAT_0050a678 == 0) {
    target_idx = GetEnvironmentStringsW();
    if (target_idx == (LPWCH)0x0) {
      color_idx = GetEnvironmentStrings();
      if (color_idx == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0050a678 = 2;
    }
    else {
      DAT_0050a678 = 1;
    }
  }
  if (DAT_0050a678 == 1) {
    if ((target_idx == (LPWCH)0x0) && (target_idx = GetEnvironmentStringsW(), target_idx == (LPWCH)0x0)) {
      ptr_1 = (LPSTR)0x0;
    }
    else {
      match_count = target_idx;
      pWVar2 = match_count;
      while (match_count = pWVar2, *match_count != L'\0') {
        pWVar2 = match_count + 1;
        if (match_count[1] == L'\0') {
          pWVar2 = match_count + 2;
        }
      }
      val_3 = ((int)match_count - (int)target_idx >> 1) + 1;
      cbMultiByte = WideCharToMultiByte(0,0,target_idx,val_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((cbMultiByte == 0) ||
         (color_idx = (LPCH)__malloc_dbg(cbMultiByte,2,"aw_env.c",0xfb), color_idx == (LPSTR)0x0)) {
        FreeEnvironmentStringsW(target_idx);
        ptr_1 = (LPSTR)0x0;
      }
      else {
        val_3 = WideCharToMultiByte(0,0,target_idx,val_3,color_idx,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0)
        ;
        if (val_3 == 0) {
          __free_dbg(color_idx,2);
          color_idx = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(target_idx);
        ptr_1 = color_idx;
      }
    }
  }
  else if (DAT_0050a678 == 2) {
    if ((color_idx == (LPCH)0x0) && (color_idx = GetEnvironmentStrings(), color_idx == (LPCH)0x0)) {
      ptr_1 = (LPSTR)0x0;
    }
    else {
      card_idx = color_idx;
      char_ptr_1 = card_idx;
      while (card_idx = char_ptr_1, *card_idx != '\0') {
        char_ptr_1 = card_idx + 1;
        if (card_idx[1] == '\0') {
          char_ptr_1 = card_idx + 2;
        }
      }
      ptr_1 = (LPSTR)__malloc_dbg(card_idx + (1 - (int)color_idx),2,"aw_env.c",0x126);
      if (ptr_1 == (LPSTR)0x0) {
        FreeEnvironmentStringsA(color_idx);
        ptr_1 = (LPSTR)0x0;
      }
      else {
        FID_conflict__memcpy(ptr_1,color_idx,(size_t)(card_idx + (1 - (int)color_idx)));
        FreeEnvironmentStringsA(color_idx);
      }
    }
  }
  else {
    ptr_1 = (LPSTR)0x0;
  }
  return ptr_1;
}



/*
 * Decompiled function: FUN_004e8661
 * Entry Point: 004e8661
 * Size: 27 bytes
 */


void FUN_004e8661(int player_id)

{
  __local_unwind2(*(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c));
  return;
}



/*
 * Decompiled function: __FF_MSGBANNER
 * Entry Point: 004e8680
 * Size: 95 bytes
 */


/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Debug */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0050a710 != (code *)0x0) {
      (*DAT_0050a710)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}



/*
 * Decompiled function: __NMSG_WRITE
 * Entry Point: 004e86e0
 * Size: 537 bytes
 */


/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 1998 Debug */

void __cdecl __NMSG_WRITE(int player_id)

{
  code *char_ptr_1;
  int val_2;
  size_t len_3;
  DWORD DVar4;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  HANDLE local_1b8;
  uint32_t local_1b4 [40];
  uint32_t local_114 [65];
  uint32_t *card_idx;
  uint32_t match_count;
  DWORD slot_idx;
  
  for (match_count = 0; (match_count < 0x12 && (*(int *)(&DAT_0050a680 + match_count * 8) != arg_1));
      match_count = match_count + 1) {
  }
  if (*(int *)(&DAT_0050a680 + match_count * 8) == arg_1) {
    if ((arg_1 != 0xfc) &&
       (val_2 = __CrtDbgReport(1,0,0,0,(&PTR_s_R6002___floating_point_not_loade_0050a684)
                                       [match_count * 2]), val_2 == 1)) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
      if ((DAT_006c1b90 == 0) || (*(int *)(DAT_006c1b90 + 0x10) == -1)) {
        local_1b8 = GetStdHandle(0xfffffff4);
      }
      else {
        local_1b8 = *(HANDLE *)(DAT_006c1b90 + 0x10);
      }
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &slot_idx;
      len_3 = _strlen((&PTR_s_R6002___floating_point_not_loade_0050a684)[match_count * 2]);
      WriteFile(local_1b8,(&PTR_s_R6002___floating_point_not_loade_0050a684)[match_count * 2],len_3,
                lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (arg_1 != 0xfc) {
      DVar4 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_114,0x104);
      if (DVar4 == 0) {
        Mem_AllocOrFree_004d9630(local_114,(uint32_t *)"<program name unknown>");
      }
      card_idx = local_114;
      len_3 = _strlen((char *)card_idx);
      if (0x3c < len_3 + 1) {
        len_3 = _strlen((char *)local_114);
        card_idx = (uint32_t *)((int)card_idx + (len_3 - 0x3b));
        _strncpy((char *)card_idx,"...",3);
      }
      Mem_AllocOrFree_004d9630(local_1b4,(uint32_t *)"Runtime Error!\n\nProgram: ");
      FUN_004d9640(local_1b4,card_idx);
      FUN_004d9640(local_1b4,(uint32_t *)&DAT_004f0218);
      FUN_004d9640(local_1b4,(uint32_t *)(&PTR_s_R6002___floating_point_not_loade_0050a684)[match_count * 2]
                  );
      ___crtMessageBoxA((LPCSTR)local_1b4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



/*
 * Decompiled function: __GET_RTERRMSG
 * Entry Point: 004e8900
 * Size: 109 bytes
 */


/* Library Function - Single Match
    __GET_RTERRMSG
   
   Library: Visual Studio 1998 Debug */

wchar_t * __cdecl __GET_RTERRMSG(int player_id)

{
  wchar_t *pwVar1;
  uint32_t slot_idx;
  
  for (slot_idx = 0; (slot_idx < 0x12 && (*(int *)(&DAT_0050a680 + slot_idx * 8) != arg_1));
      slot_idx = slot_idx + 1) {
  }
  if (*(int *)(&DAT_0050a680 + slot_idx * 8) == arg_1) {
    pwVar1 = (wchar_t *)(&PTR_s_R6002___floating_point_not_loade_0050a684)[slot_idx * 2];
  }
  else {
    pwVar1 = (wchar_t *)0x0;
  }
  return pwVar1;
}



