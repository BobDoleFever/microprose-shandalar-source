/*
 * Decompiled function: parse_cmdline
 * Entry Point: 004e7cc0
 * Size: 958 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 1998 Debug */

void __cdecl parse_cmdline(byte *arg_1,undefined4 *arg_2,byte *arg_3,int *arg_4,int *arg_5)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  uint local_14;
  byte *local_8;
  
  *arg_5 = 0;
  *arg_4 = 1;
  local_8 = arg_1;
  if (arg_2 != (undefined4 *)0x0) {
    *arg_2 = arg_3;
    arg_2 = arg_2 + 1;
  }
  if (*arg_1 == 0x22) {
    while ((pbVar1 = local_8 + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
      if ((((&DAT_0050a201)[*pbVar1] & 4) != 0) && (*arg_5 = *arg_5 + 1, arg_3 != (byte *)0x0)) {
        *arg_3 = *pbVar1;
        arg_3 = arg_3 + 1;
        pbVar1 = local_8 + 2;
      }
      local_8 = pbVar1;
      *arg_5 = *arg_5 + 1;
      if (arg_3 != (byte *)0x0) {
        *arg_3 = *local_8;
        arg_3 = arg_3 + 1;
      }
    }
    *arg_5 = *arg_5 + 1;
    if (arg_3 != (byte *)0x0) {
      *arg_3 = 0;
      arg_3 = arg_3 + 1;
    }
    if (*pbVar1 == 0x22) {
      pbVar1 = local_8 + 2;
    }
  }
  else {
    do {
      *arg_5 = *arg_5 + 1;
      if (arg_3 != (byte *)0x0) {
        *arg_3 = *local_8;
        arg_3 = arg_3 + 1;
      }
      bVar2 = *local_8;
      pbVar1 = local_8 + 1;
      if (((&DAT_0050a201)[bVar2] & 4) != 0) {
        *arg_5 = *arg_5 + 1;
        if (arg_3 != (byte *)0x0) {
          *arg_3 = local_8[1];
          arg_3 = arg_3 + 1;
        }
        pbVar1 = local_8 + 2;
      }
      local_8 = pbVar1;
    } while (((bVar2 != 0x20) && (bVar2 != 0)) && (bVar2 != 9));
    if (bVar2 == 0) {
      pbVar1 = local_8 + -1;
    }
    else {
      pbVar1 = local_8;
      if (arg_3 != (byte *)0x0) {
        arg_3[-1] = 0;
      }
    }
  }
  local_8 = pbVar1;
  bVar3 = false;
  while( true ) {
    if (*local_8 != 0) {
      for (; (*local_8 == 0x20 || (*local_8 == 9)); local_8 = local_8 + 1) {
      }
    }
    if (*local_8 == 0) break;
    if (arg_2 != (undefined4 *)0x0) {
      *arg_2 = arg_3;
      arg_2 = arg_2 + 1;
    }
    *arg_4 = *arg_4 + 1;
    while( true ) {
      bVar4 = true;
      local_14 = 0;
      for (; *local_8 == 0x5c; local_8 = local_8 + 1) {
        local_14 = local_14 + 1;
      }
      if (*local_8 == 0x22) {
        if ((local_14 & 1) == 0) {
          if (bVar3) {
            bVar4 = local_8[1] == 0x22;
            if (bVar4) {
              local_8 = local_8 + 1;
            }
          }
          else {
            bVar4 = false;
          }
          if (bVar3) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
        }
        local_14 = local_14 >> 1;
      }
      while (local_14 != 0) {
        if (arg_3 != (byte *)0x0) {
          *arg_3 = 0x5c;
          arg_3 = arg_3 + 1;
        }
        *arg_5 = *arg_5 + 1;
        local_14 = local_14 - 1;
      }
      if ((*local_8 == 0) || ((!bVar3 && ((*local_8 == 0x20 || (*local_8 == 9)))))) break;
      if (bVar4) {
        if (arg_3 == (byte *)0x0) {
          if (((&DAT_0050a201)[*local_8] & 4) != 0) {
            local_8 = local_8 + 1;
            *arg_5 = *arg_5 + 1;
          }
        }
        else {
          if (((&DAT_0050a201)[*local_8] & 4) != 0) {
            *arg_3 = *local_8;
            local_8 = local_8 + 1;
            arg_3 = arg_3 + 1;
            *arg_5 = *arg_5 + 1;
          }
          *arg_3 = *local_8;
          arg_3 = arg_3 + 1;
        }
        *arg_5 = *arg_5 + 1;
      }
      local_8 = local_8 + 1;
    }
    if (arg_3 != (byte *)0x0) {
      *arg_3 = 0;
      arg_3 = arg_3 + 1;
    }
    *arg_5 = *arg_5 + 1;
  }
  if (arg_2 != (undefined4 *)0x0) {
    *arg_2 = 0;
  }
  *arg_4 = *arg_4 + 1;
  return;
}


