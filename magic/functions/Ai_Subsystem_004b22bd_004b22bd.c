/*
 * Decompiled function: Ai_Subsystem_004b22bd
 * Entry Point: 004b22bd
 * Size: 698 bytes
 */
#include "magic.h"


INT_PTR Ai_Subsystem_004b22bd(int arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,uint arg_5)

{
  char cVar1;
  INT_PTR local_20;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  INT_PTR local_8;
  
  cVar1 = (arg_5 & 2) != 0;
  if ((arg_5 & 0x20) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 8) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 0x10) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 4) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 1) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if (cVar1 == '\0') {
    local_20 = -1;
  }
  else if (cVar1 == '\x01') {
    if ((arg_5 & 2) == 0) {
      if ((arg_5 & 0x20) == 0) {
        if ((arg_5 & 8) == 0) {
          if ((arg_5 & 0x10) == 0) {
            if ((arg_5 & 4) == 0) {
              local_20 = local_8;
              if ((arg_5 & 1) != 0) {
                local_8 = 0;
                local_20 = local_8;
              }
            }
            else {
              local_8 = 2;
              local_20 = local_8;
            }
          }
          else {
            local_8 = 4;
            local_20 = local_8;
          }
        }
        else {
          local_8 = 3;
          local_20 = local_8;
        }
      }
      else {
        local_8 = 5;
        local_20 = local_8;
      }
    }
    else {
      local_8 = 1;
      local_20 = local_8;
    }
  }
  else {
    if ((((((arg_4 == 1) && ((arg_5 & 2) == 0)) || ((arg_4 == 5 && ((arg_5 & 0x20) == 0)))) ||
         ((arg_4 == 3 && ((arg_5 & 8) == 0)))) || ((arg_4 == 4 && ((arg_5 & 0x10) == 0)))) ||
       ((((arg_4 == 2 && ((arg_5 & 4) == 0)) || ((arg_4 == 0 && ((arg_5 & 1) == 0)))) ||
        ((arg_4 < 0 || (5 < arg_4)))))) {
      if ((arg_5 & 0x20) == 0) {
        if ((arg_5 & 4) == 0) {
          if ((arg_5 & 2) == 0) {
            if ((arg_5 & 0x10) == 0) {
              if ((arg_5 & 8) == 0) {
                if ((arg_5 & 1) != 0) {
                  arg_4 = 0;
                }
              }
              else {
                arg_4 = 3;
              }
            }
            else {
              arg_4 = 4;
            }
          }
          else {
            arg_4 = 1;
          }
        }
        else {
          arg_4 = 2;
        }
      }
      else {
        arg_4 = 5;
      }
    }
    local_20 = arg_4;
    if (arg_1 == 0) {
      local_1c = arg_2;
      local_18 = arg_4;
      local_14 = (uint)(arg_4 != -1);
      local_10 = arg_3;
      local_c = arg_5;
      local_20 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xde,g_MainAppHwnd,Ai_Subsystem_004b257c,
                                 (LPARAM)&local_1c);
      if (local_20 == -1) {
        local_20 = -1;
      }
      else if (local_20 == -2) {
        local_20 = -1;
      }
    }
  }
  return local_20;
}


