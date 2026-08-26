/*
 * Decompiled function: FUN_0043c4d0
 * Entry Point: 0043c4d0
 * Size: 2423 bytes
 */
#include "duel.h"


size_t FUN_0043c4d0(char *str_1)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  int local_414;
  int local_410;
  int local_40c;
  uint local_408 [250];
  char *local_20;
  int local_1c;
  int local_18;
  int local_14;
  size_t local_10;
  int local_c;
  FILE *local_8;
  
  local_8 = _fopen(str_1,&DAT_004f7888);
  if (local_8 == (FILE *)0x0) {
    sVar3 = 0;
  }
  else {
    _fread(&DAT_0061743c,4,1,local_8);
    _fread(&local_10,4,1,local_8);
    DAT_0060cc68 = _malloc(local_10);
    if (DAT_0060cc68 == (void *)0x0) {
      _fclose(local_8);
      sVar3 = 0;
    }
    else {
      _fread(&DAT_00618ac0,0x98,DAT_0061743c,local_8);
      _fread(DAT_0060cc68,1,local_10,local_8);
      _fclose(local_8);
      for (local_c = 0; local_c < (int)DAT_0061743c; local_c = local_c + 1) {
        *(int *)(&DAT_00618ac4 + local_c * 0x98) =
             *(int *)(&DAT_00618ac4 + local_c * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618ac8 + local_c * 0x98) =
             *(int *)(&DAT_00618ac8 + local_c * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618b34 + local_c * 0x98) =
             *(int *)(&DAT_00618b34 + local_c * 0x98) + (int)DAT_0060cc68;
        *(int *)(&DAT_00618b38 + local_c * 0x98) =
             *(int *)(&DAT_00618b38 + local_c * 0x98) + (int)DAT_0060cc68;
        iVar2 = __strcmpi(*(char **)(&DAT_00618b34 + local_c * 0x98),&DAT_004f788c);
        if (iVar2 == 0) {
          *(undefined **)(&DAT_00618b34 + local_c * 0x98) = &DAT_004f7894;
        }
        iVar2 = __strcmpi(*(char **)(&DAT_00618b38 + local_c * 0x98),&DAT_004f7898);
        if ((iVar2 == 0) ||
           (iVar2 = __strcmpi(*(char **)(&DAT_00618b38 + local_c * 0x98),s_Blank_004f78a0),
           iVar2 == 0)) {
          *(undefined **)(&DAT_00618b38 + local_c * 0x98) = &DAT_004f78a8;
        }
        *(undefined **)(&DAT_00618b00 + local_c * 0x98) =
             (&PTR_DAT_004f58e8)[*(int *)(&DAT_00618b00 + local_c * 0x98)];
        if (*(int *)(&DAT_00618b04 + local_c * 0x98) == 0) {
          *(undefined4 *)(&DAT_00618b04 + local_c * 0x98) = 1;
        }
        for (local_14 = 0; local_14 < *(int *)(&DAT_00618b04 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(int *)(&DAT_00618b0c + local_14 * 4 + local_c * 0x98) =
               *(int *)(&DAT_00618b0c + local_14 * 4 + local_c * 0x98) + (int)DAT_0060cc68;
        }
        *(undefined4 *)(&DAT_00618b08 + local_c * 0x98) = 0;
        for (local_14 = 0; local_14 < *(int *)(&DAT_00618b04 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_00618b20 + local_14 * 4 + local_c * 0x98) = 0;
        }
      }
      for (local_18 = 0; local_18 < (int)DAT_0061743c; local_18 = local_18 + 1) {
        if (((&DAT_00618acc)[local_18 * 0x98] & 0x40) != 0) {
          *(undefined4 *)(&DAT_00618acc + local_18 * 0x98) = 0x80;
        }
      }
      for (local_1c = 0; local_1c < (int)DAT_0061743c; local_1c = local_1c + 1) {
        if ((&DAT_00618ae8)[local_1c * 0x98] == '\x11') {
          (&DAT_00618ae8)[local_1c * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < (int)DAT_0061743c; local_40c = local_40c + 1) {
        local_410 = 0;
        for (local_20 = *(char **)(&DAT_00618b34 + local_40c * 0x98); *local_20 != '\0';
            local_20 = local_20 + 1) {
          if (*local_20 == '|') {
            pcVar1 = local_20 + 1;
            if (*pcVar1 == 'T') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xee;
            }
            else if (*pcVar1 == 'B') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xfe;
            }
            else if (*pcVar1 == 'U') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xfd;
            }
            else if (*pcVar1 == 'W') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xfb;
            }
            else if (*pcVar1 == 'G') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xff;
            }
            else if (*pcVar1 == 'R') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xfc;
            }
            else if (*pcVar1 == 'X') {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0xf0;
            }
            else if ((*pcVar1 == '1') && (local_20[2] == '0')) {
              local_20 = local_20 + 2;
              *(undefined1 *)((int)local_408 + local_410) = 0xef;
            }
            else if ((*pcVar1 < '0') || ('9' < *pcVar1)) {
              local_20 = pcVar1;
              *(undefined1 *)((int)local_408 + local_410) = 0x7c;
              local_20 = local_20 + -1;
            }
            else {
              local_20 = pcVar1;
              *(char *)((int)local_408 + local_410) = *pcVar1 + -0x3f;
            }
          }
          else if (((*local_20 == '\\') && (local_20[1] == '\\')) ||
                  ((*local_20 == '\\' && (local_20[1] == 'n')))) {
            local_20 = local_20 + 1;
            *(undefined1 *)((int)local_408 + local_410) = 10;
          }
          else {
            *(char *)((int)local_408 + local_410) = *local_20;
          }
          local_410 = local_410 + 1;
        }
        *(undefined1 *)((int)local_408 + local_410) = 0;
        Mem_AllocOrFree_004d9630(*(uint **)(&DAT_00618b34 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; sVar3 = DAT_0061743c, local_414 < (int)DAT_0061743c;
          local_414 = local_414 + 1) {
        *(undefined4 *)(&DAT_00618b1c + local_414 * 0x98) = 0;
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_black_004f78ac,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint *)(&DAT_00618b1c + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),&DAT_004f78b4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint *)(&DAT_00618b1c + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_green_004f78bc,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint *)(&DAT_00618b1c + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),&DAT_004f78c4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint *)(&DAT_00618b1c + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_white_004f78c8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b1c + local_414 * 0x98) =
               *(uint *)(&DAT_00618b1c + local_414 * 0x98) | 0x20;
        }
        *(undefined4 *)(&DAT_00618b54 + local_414 * 0x98) = 0;
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_swamp_004f78d0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint *)(&DAT_00618b54 + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_island_004f78d8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint *)(&DAT_00618b54 + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_forest_004f78e0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint *)(&DAT_00618b54 + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_mountain_004f78e8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint *)(&DAT_00618b54 + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_00471b26(*(char **)(&DAT_00618b34 + local_414 * 0x98),s_plains_004f78f4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_00618b54 + local_414 * 0x98) =
               *(uint *)(&DAT_00618b54 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return sVar3;
}


