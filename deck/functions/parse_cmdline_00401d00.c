/*
 * Decompiled function: parse_cmdline
 * Entry Point: 00401d00
 * Size: 958 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 1998 Debug */

void __cdecl parse_cmdline(uint8_t *ptr_1,int32_t *ptr_2,uint8_t *ptr_3,int *ptr_4,int *ptr_5)

{
  uint8_t *pbVar1;
  uint8_t flag_2;
  bool flag_3;
  bool bVar4;
  uint32_t local_14;
  uint8_t *local_8;
  
  *ptr_5 = 0;
  *ptr_4 = 1;
  local_8 = ptr_1;
  if (ptr_2 != (int32_t *)0x0) {
    *ptr_2 = ptr_3;
    ptr_2 = ptr_2 + 1;
  }
  if (*ptr_1 == 0x22) {
    while ((pbVar1 = local_8 + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
      if ((((&DAT_00412b69)[*pbVar1] & 4) != 0) && (*ptr_5 = *ptr_5 + 1, ptr_3 != (uint8_t *)0x0)) {
        *ptr_3 = *pbVar1;
        ptr_3 = ptr_3 + 1;
        pbVar1 = local_8 + 2;
      }
      local_8 = pbVar1;
      *ptr_5 = *ptr_5 + 1;
      if (ptr_3 != (uint8_t *)0x0) {
        *ptr_3 = *local_8;
        ptr_3 = ptr_3 + 1;
      }
    }
    *ptr_5 = *ptr_5 + 1;
    if (ptr_3 != (uint8_t *)0x0) {
      *ptr_3 = 0;
      ptr_3 = ptr_3 + 1;
    }
    if (*pbVar1 == 0x22) {
      pbVar1 = local_8 + 2;
    }
  }
  else {
    do {
      *ptr_5 = *ptr_5 + 1;
      if (ptr_3 != (uint8_t *)0x0) {
        *ptr_3 = *local_8;
        ptr_3 = ptr_3 + 1;
      }
      flag_2 = *local_8;
      pbVar1 = local_8 + 1;
      if (((&DAT_00412b69)[flag_2] & 4) != 0) {
        *ptr_5 = *ptr_5 + 1;
        if (ptr_3 != (uint8_t *)0x0) {
          *ptr_3 = local_8[1];
          ptr_3 = ptr_3 + 1;
        }
        pbVar1 = local_8 + 2;
      }
      local_8 = pbVar1;
    } while (((flag_2 != 0x20) && (flag_2 != 0)) && (flag_2 != 9));
    if (flag_2 == 0) {
      pbVar1 = local_8 + -1;
    }
    else {
      pbVar1 = local_8;
      if (ptr_3 != (uint8_t *)0x0) {
        ptr_3[-1] = 0;
      }
    }
  }
  local_8 = pbVar1;
  flag_3 = false;
  while( true ) {
    if (*local_8 != 0) {
      for (; (*local_8 == 0x20 || (*local_8 == 9)); local_8 = local_8 + 1) {
      }
    }
    if (*local_8 == 0) break;
    if (ptr_2 != (int32_t *)0x0) {
      *ptr_2 = ptr_3;
      ptr_2 = ptr_2 + 1;
    }
    *ptr_4 = *ptr_4 + 1;
    while( true ) {
      bVar4 = true;
      local_14 = 0;
      for (; *local_8 == 0x5c; local_8 = local_8 + 1) {
        local_14 = local_14 + 1;
      }
      if (*local_8 == 0x22) {
        if ((local_14 & 1) == 0) {
          if (flag_3) {
            bVar4 = local_8[1] == 0x22;
            if (bVar4) {
              local_8 = local_8 + 1;
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
        local_14 = local_14 >> 1;
      }
      while (local_14 != 0) {
        if (ptr_3 != (uint8_t *)0x0) {
          *ptr_3 = 0x5c;
          ptr_3 = ptr_3 + 1;
        }
        *ptr_5 = *ptr_5 + 1;
        local_14 = local_14 - 1;
      }
      if ((*local_8 == 0) || ((!flag_3 && ((*local_8 == 0x20 || (*local_8 == 9)))))) break;
      if (bVar4) {
        if (ptr_3 == (uint8_t *)0x0) {
          if (((&DAT_00412b69)[*local_8] & 4) != 0) {
            local_8 = local_8 + 1;
            *ptr_5 = *ptr_5 + 1;
          }
        }
        else {
          if (((&DAT_00412b69)[*local_8] & 4) != 0) {
            *ptr_3 = *local_8;
            local_8 = local_8 + 1;
            ptr_3 = ptr_3 + 1;
            *ptr_5 = *ptr_5 + 1;
          }
          *ptr_3 = *local_8;
          ptr_3 = ptr_3 + 1;
        }
        *ptr_5 = *ptr_5 + 1;
      }
      local_8 = local_8 + 1;
    }
    if (ptr_3 != (uint8_t *)0x0) {
      *ptr_3 = 0;
      ptr_3 = ptr_3 + 1;
    }
    *ptr_5 = *ptr_5 + 1;
  }
  if (ptr_2 != (int32_t *)0x0) {
    *ptr_2 = 0;
  }
  *ptr_4 = *ptr_4 + 1;
  return;
}


