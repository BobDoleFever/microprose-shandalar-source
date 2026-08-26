/*
 * Decompiled function: FUN_00489c9c
 * Entry Point: 00489c9c
 * Size: 1310 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00489c9c(char *str_1,int arg2)

{
  size_t sVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _DAT_00539d60 = 0;
  if (DAT_00676d38 == 1) {
    DAT_00527b30 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_14 = 0; (int)local_14 < 0x20; local_14 = local_14 + 1) {
      (&DAT_00676d10)[local_14] = 0xff;
    }
    local_c = 0;
    DAT_00539de8 = 0;
    local_8 = 0;
    DAT_00676d48 = 0;
    for (local_14 = 0; sVar1 = strlen(str_1), local_14 < sVar1; local_14 = local_14 + 1) {
      if (str_1[local_14] == '\n') {
        if (DAT_00676d48 < local_8) {
          DAT_00676d48 = local_8;
        }
        local_8 = 0;
        DAT_00539de8 = DAT_00539de8 + 1;
        *(uint *)(&DAT_00539d60 + DAT_00539de8 * 4) = local_14 + 1;
      }
      else {
        if ((local_8 == 0) && ((str_1[local_14] == ' ' || (str_1[local_14] == '_')))) {
          if (local_c < 0x20) {
            (&DAT_00676d10)[local_c] = str_1[local_14 + 1];
          }
          if (DAT_00676d50 == -1) {
            DAT_00676d50 = DAT_00539de8;
          }
          local_c = local_c + 1;
        }
        iVar2 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),str_1[local_14]);
        local_8 = local_8 + iVar2;
      }
    }
    DAT_00539de8 = FUN_0040a305(DAT_00539de8,0,(DAT_0052245c - DAT_00539df0) / DAT_00527b30);
    if (DAT_00539dec == -1) {
      DAT_00539dec = 0xa0 - (DAT_00676d48 + 8) / 2;
    }
    DAT_00676d44 = DAT_00539dec + DAT_00676d48 + 8;
    iVar2 = DAT_00527b30 * DAT_00539de8 + DAT_00539df0;
    local_10 = iVar2 + 6;
    if (DAT_00527b24 != 0) {
      local_10 = iVar2 + 8;
    }
    sVar1 = strlen(str_1);
    if (str_1[sVar1 - 1] != '\n') {
      local_c = local_c + -1;
    }
    DAT_00676d40 = local_c;
    FUN_0048a1ba(DAT_00539dec,DAT_00539df0,DAT_00676d44 - DAT_00539dec,local_10 - DAT_00539df0);
    if (DAT_00676d4c != 0) {
      FUN_0040c1ad(&DAT_00527b40,DAT_00676d44 + -0x11,local_10 + -8,0xfe);
      FUN_0048a2a5(DAT_00676d44 + -0x14,local_10 + -10,0x14,10,0xfe);
    }
  }
  if ((*str_1 == ' ') || (*str_1 == '_')) {
    local_c = 0;
  }
  else {
    local_c = -1;
  }
  DAT_00539de0 = DAT_00527b34;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x18) = DAT_00527b34;
  for (local_14 = 0; (int)local_14 < DAT_00539de8; local_14 = local_14 + 1) {
    if (((DAT_00676d38 != 0) || (DAT_00539e04 == local_c)) || (arg2 == local_c)) {
      str_1[*(int *)(&DAT_00539d64 + local_14 * 4) + -1] = '\0';
      if ((local_c < 0) || ((_DAT_00676d30 & 1 << ((byte)local_c & 0x1f)) == 0)) {
        if (local_c < 0) {
          local_1c = DAT_00539de0;
        }
        else if (arg2 == local_c) {
          local_1c = DAT_00527b38;
        }
        else {
          local_1c = DAT_00527b34;
        }
        FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                     DAT_00527b30 * local_14 + DAT_00539df0 + 5,local_1c);
      }
      else {
        str_1[*(int *)(&DAT_00539d60 + local_14 * 4)] = '^';
        if ((DAT_00539de4 == 0) || (arg2 != local_c)) {
          if (local_c < 0) {
            local_18 = DAT_00539de0;
          }
          else if (arg2 == local_c) {
            local_18 = DAT_00527b38;
          }
          else {
            local_18 = DAT_00527b34;
          }
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                       DAT_00527b30 * local_14 + DAT_00539df0 + 5,local_18);
        }
        else {
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                       DAT_00527b30 * local_14 + DAT_00539df0 + 5,0xff);
        }
        str_1[*(int *)(&DAT_00539d60 + local_14 * 4)] = ' ';
      }
      str_1[*(int *)(&DAT_00539d64 + local_14 * 4) + -1] = '\n';
    }
    if ((str_1[*(int *)(&DAT_00539d64 + local_14 * 4)] == ' ') ||
       (str_1[*(int *)(&DAT_00539d64 + local_14 * 4)] == '_')) {
      local_c = local_c + 1;
    }
  }
  return arg2;
}


