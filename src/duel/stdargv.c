/*
 * stdargv.c - Reconstructed MicroProse Source Module
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
 * Decompiled function: __setargv
 * Entry Point: 004e7bf0
 * Size: 204 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setargv(void)

{
  uint8_t *player_idx;
  int card_idx;
  int32_t *match_count;
  int slot_idx;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_005edb18,0x104);
  DAT_00509458 = &DAT_005edb18;
  if (*DAT_006c2ca8 == 0) {
    player_idx = &DAT_005edb18;
  }
  else {
    player_idx = DAT_006c2ca8;
  }
  parse_cmdline(player_idx,(int32_t *)0x0,(uint8_t *)0x0,&card_idx,&slot_idx);
  match_count = (int32_t *)__malloc_dbg(card_idx * 4 + slot_idx,2,"stdargv.c",0x75);
  if (match_count == (int32_t *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(player_idx,match_count,(uint8_t *)(match_count + card_idx),&card_idx,&slot_idx);
  _DAT_0050943c = card_idx + -1;
  _DAT_00509440 = match_count;
  return (int)match_count;
}



/*
 * Decompiled function: parse_cmdline
 * Entry Point: 004e7cc0
 * Size: 958 bytes
 */


/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 1998 Debug */

void __cdecl parse_cmdline(uint8_t *arg_1,int32_t *arg_2,uint8_t *arg_3,int *arg_4,int *arg_5)

{
  uint8_t *pbVar1;
  uint8_t flag_2;
  bool flag_3;
  bool bVar4;
  uint32_t player_idx;
  uint8_t *slot_idx;
  
  *arg_5 = 0;
  *arg_4 = 1;
  slot_idx = arg_1;
  if (arg_2 != (int32_t *)0x0) {
    *arg_2 = arg_3;
    arg_2 = arg_2 + 1;
  }
  if (*arg_1 == 0x22) {
    while ((pbVar1 = slot_idx + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
      if ((((&DAT_0050a201)[*pbVar1] & 4) != 0) && (*arg_5 = *arg_5 + 1, arg_3 != (uint8_t *)0x0)) {
        *arg_3 = *pbVar1;
        arg_3 = arg_3 + 1;
        pbVar1 = slot_idx + 2;
      }
      slot_idx = pbVar1;
      *arg_5 = *arg_5 + 1;
      if (arg_3 != (uint8_t *)0x0) {
        *arg_3 = *slot_idx;
        arg_3 = arg_3 + 1;
      }
    }
    *arg_5 = *arg_5 + 1;
    if (arg_3 != (uint8_t *)0x0) {
      *arg_3 = 0;
      arg_3 = arg_3 + 1;
    }
    if (*pbVar1 == 0x22) {
      pbVar1 = slot_idx + 2;
    }
  }
  else {
    do {
      *arg_5 = *arg_5 + 1;
      if (arg_3 != (uint8_t *)0x0) {
        *arg_3 = *slot_idx;
        arg_3 = arg_3 + 1;
      }
      flag_2 = *slot_idx;
      pbVar1 = slot_idx + 1;
      if (((&DAT_0050a201)[flag_2] & 4) != 0) {
        *arg_5 = *arg_5 + 1;
        if (arg_3 != (uint8_t *)0x0) {
          *arg_3 = slot_idx[1];
          arg_3 = arg_3 + 1;
        }
        pbVar1 = slot_idx + 2;
      }
      slot_idx = pbVar1;
    } while (((flag_2 != 0x20) && (flag_2 != 0)) && (flag_2 != 9));
    if (flag_2 == 0) {
      pbVar1 = slot_idx + -1;
    }
    else {
      pbVar1 = slot_idx;
      if (arg_3 != (uint8_t *)0x0) {
        arg_3[-1] = 0;
      }
    }
  }
  slot_idx = pbVar1;
  flag_3 = false;
  while( true ) {
    if (*slot_idx != 0) {
      for (; (*slot_idx == 0x20 || (*slot_idx == 9)); slot_idx = slot_idx + 1) {
      }
    }
    if (*slot_idx == 0) break;
    if (arg_2 != (int32_t *)0x0) {
      *arg_2 = arg_3;
      arg_2 = arg_2 + 1;
    }
    *arg_4 = *arg_4 + 1;
    while( true ) {
      bVar4 = true;
      player_idx = 0;
      for (; *slot_idx == 0x5c; slot_idx = slot_idx + 1) {
        player_idx = player_idx + 1;
      }
      if (*slot_idx == 0x22) {
        if ((player_idx & 1) == 0) {
          if (flag_3) {
            bVar4 = slot_idx[1] == 0x22;
            if (bVar4) {
              slot_idx = slot_idx + 1;
            }
          }
          else {
            bVar4 = false;
          }
          if (flag_3) {
            flag_3 = false;
          }
          else {
            flag_3 = true;
          }
        }
        player_idx = player_idx >> 1;
      }
      while (player_idx != 0) {
        if (arg_3 != (uint8_t *)0x0) {
          *arg_3 = 0x5c;
          arg_3 = arg_3 + 1;
        }
        *arg_5 = *arg_5 + 1;
        player_idx = player_idx - 1;
      }
      if ((*slot_idx == 0) || ((!flag_3 && ((*slot_idx == 0x20 || (*slot_idx == 9)))))) break;
      if (bVar4) {
        if (arg_3 == (uint8_t *)0x0) {
          if (((&DAT_0050a201)[*slot_idx] & 4) != 0) {
            slot_idx = slot_idx + 1;
            *arg_5 = *arg_5 + 1;
          }
        }
        else {
          if (((&DAT_0050a201)[*slot_idx] & 4) != 0) {
            *arg_3 = *slot_idx;
            slot_idx = slot_idx + 1;
            arg_3 = arg_3 + 1;
            *arg_5 = *arg_5 + 1;
          }
          *arg_3 = *slot_idx;
          arg_3 = arg_3 + 1;
        }
        *arg_5 = *arg_5 + 1;
      }
      slot_idx = slot_idx + 1;
    }
    if (arg_3 != (uint8_t *)0x0) {
      *arg_3 = 0;
      arg_3 = arg_3 + 1;
    }
    *arg_5 = *arg_5 + 1;
  }
  if (arg_2 != (int32_t *)0x0) {
    *arg_2 = 0;
  }
  *arg_4 = *arg_4 + 1;
  return;
}



