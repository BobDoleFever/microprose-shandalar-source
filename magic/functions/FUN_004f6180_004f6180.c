/*
 * Decompiled function: FUN_004f6180
 * Entry Point: 004f6180
 * Size: 2434 bytes
 */
#include "magic.h"


int FUN_004f6180(char *str_1)

{
  char *pcVar1;
  int iVar2;
  int local_414;
  int local_410;
  int local_40c;
  char local_408 [1000];
  char *local_20;
  int local_1c;
  int local_18;
  int local_14;
  size_t local_10;
  int local_c;
  FILE *local_8;
  
  local_8 = fopen(str_1,&DAT_005302a4);
  if (local_8 == (FILE *)0x0) {
    iVar2 = 0;
  }
  else {
    fread(&DAT_006a49f4,4,1,local_8);
    fread(&local_10,4,1,local_8);
    DAT_00695e9c = (int)malloc(local_10);
    if ((void *)DAT_00695e9c == (void *)0x0) {
      fclose(local_8);
      iVar2 = 0;
    }
    else {
      fread(&DAT_006b3070,0x98,DAT_006a49f4,local_8);
      fread((void *)DAT_00695e9c,1,local_10,local_8);
      fclose(local_8);
      for (local_c = 0; local_c < DAT_006a49f4; local_c = local_c + 1) {
        *(int *)(&DAT_006b3074 + local_c * 0x98) =
             *(int *)(&DAT_006b3074 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b3078 + local_c * 0x98) =
             *(int *)(&DAT_006b3078 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e4 + local_c * 0x98) =
             *(int *)(&DAT_006b30e4 + local_c * 0x98) + DAT_00695e9c;
        *(int *)(&DAT_006b30e8 + local_c * 0x98) =
             *(int *)(&DAT_006b30e8 + local_c * 0x98) + DAT_00695e9c;
        iVar2 = _strcmpi(*(char **)(&DAT_006b30e4 + local_c * 0x98),&DAT_005302a8);
        if (iVar2 == 0) {
          *(undefined **)(&DAT_006b30e4 + local_c * 0x98) = &DAT_005302b0;
        }
        iVar2 = _strcmpi(*(char **)(&DAT_006b30e8 + local_c * 0x98),&DAT_005302b4);
        if ((iVar2 == 0) ||
           (iVar2 = _strcmpi(*(char **)(&DAT_006b30e8 + local_c * 0x98),s_Blank_005302bc),
           iVar2 == 0)) {
          *(undefined **)(&DAT_006b30e8 + local_c * 0x98) = &DAT_005302c4;
        }
        *(undefined **)(&DAT_006b30b0 + local_c * 0x98) =
             (&PTR_DAT_005290b0)[*(int *)(&DAT_006b30b0 + local_c * 0x98)];
        if (*(int *)(&DAT_006b30b4 + local_c * 0x98) == 0) {
          *(undefined4 *)(&DAT_006b30b4 + local_c * 0x98) = 1;
        }
        for (local_14 = 0; local_14 < *(int *)(&DAT_006b30b4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(int *)(&DAT_006b30bc + local_14 * 4 + local_c * 0x98) =
               *(int *)(&DAT_006b30bc + local_14 * 4 + local_c * 0x98) + DAT_00695e9c;
        }
        *(undefined4 *)(&DAT_006b30b8 + local_c * 0x98) = 0;
        for (local_14 = 0; local_14 < *(int *)(&DAT_006b30b4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(undefined4 *)(&DAT_006b30d0 + local_14 * 4 + local_c * 0x98) = 0;
        }
      }
      for (local_18 = 0; local_18 < DAT_006a49f4; local_18 = local_18 + 1) {
        if (((&DAT_006b307c)[local_18 * 0x98] & 0x40) != 0) {
          *(undefined4 *)(&DAT_006b307c + local_18 * 0x98) = 0x80;
        }
      }
      for (local_1c = 0; local_1c < DAT_006a49f4; local_1c = local_1c + 1) {
        if ((&DAT_006b3098)[local_1c * 0x98] == '\x11') {
          (&DAT_006b3098)[local_1c * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < DAT_006a49f4; local_40c = local_40c + 1) {
        local_410 = 0;
        for (local_20 = *(char **)(&DAT_006b30e4 + local_40c * 0x98); *local_20 != '\0';
            local_20 = local_20 + 1) {
          if (*local_20 == '|') {
            pcVar1 = local_20 + 1;
            if (*pcVar1 == 'T') {
              local_20 = pcVar1;
              local_408[local_410] = -0x12;
            }
            else if (*pcVar1 == 'B') {
              local_20 = pcVar1;
              local_408[local_410] = -2;
            }
            else if (*pcVar1 == 'U') {
              local_20 = pcVar1;
              local_408[local_410] = -3;
            }
            else if (*pcVar1 == 'W') {
              local_20 = pcVar1;
              local_408[local_410] = -5;
            }
            else if (*pcVar1 == 'G') {
              local_20 = pcVar1;
              local_408[local_410] = -1;
            }
            else if (*pcVar1 == 'R') {
              local_20 = pcVar1;
              local_408[local_410] = -4;
            }
            else if (*pcVar1 == 'X') {
              local_20 = pcVar1;
              local_408[local_410] = -0x10;
            }
            else if ((*pcVar1 == '1') && (local_20[2] == '0')) {
              local_20 = local_20 + 2;
              local_408[local_410] = -0x11;
            }
            else if ((*pcVar1 < '0') || ('9' < *pcVar1)) {
              local_20 = pcVar1;
              local_408[local_410] = '|';
              local_20 = local_20 + -1;
            }
            else {
              local_20 = pcVar1;
              local_408[local_410] = *pcVar1 + -0x3f;
            }
          }
          else if (((*local_20 == '\\') && (local_20[1] == '\\')) ||
                  ((*local_20 == '\\' && (local_20[1] == 'n')))) {
            local_20 = local_20 + 1;
            local_408[local_410] = '\n';
          }
          else {
            local_408[local_410] = *local_20;
          }
          local_410 = local_410 + 1;
        }
        local_408[local_410] = '\0';
        strcpy(*(char **)(&DAT_006b30e4 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; iVar2 = DAT_006a49f4, local_414 < DAT_006a49f4; local_414 = local_414 + 1)
      {
        *(undefined4 *)(&DAT_006b30cc + local_414 * 0x98) = 0;
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_black_005302c8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302d0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_green_005302d8,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),&DAT_005302e0,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_white_005302e4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b30cc + local_414 * 0x98) =
               *(uint *)(&DAT_006b30cc + local_414 * 0x98) | 0x20;
        }
        *(undefined4 *)(&DAT_006b3104 + local_414 * 0x98) = 0;
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_swamp_005302ec,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 2;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_island_005302f4,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 4;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_forest_005302fc,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 8;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_mountain_00530304,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 0x10;
        }
        iVar2 = FUN_004f4ce1(*(char **)(&DAT_006b30e4 + local_414 * 0x98),s_plains_00530310,0);
        if (iVar2 != -1) {
          *(uint *)(&DAT_006b3104 + local_414 * 0x98) =
               *(uint *)(&DAT_006b3104 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return iVar2;
}


