/*
 * Decompiled function: FUN_100298f0
 * Entry Point: 100298f0
 * Size: 2434 bytes
 */
#include "deckdll.h"


int FUN_100298f0(char *str_1)

{
  char *char_ptr_1;
  int val_2;
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
  
  local_8 = fopen(str_1,&DAT_10046088);
  if (local_8 == (FILE *)0x0) {
    val_2 = 0;
  }
  else {
    fread(&DAT_10175ee0,4,1,local_8);
    fread(&local_10,4,1,local_8);
    DAT_101628d4 = (int)malloc(local_10);
    if ((void *)DAT_101628d4 == (void *)0x0) {
      fclose(local_8);
      val_2 = 0;
    }
    else {
      fread(&DAT_10176ab0,0x98,DAT_10175ee0,local_8);
      fread((void *)DAT_101628d4,1,local_10,local_8);
      fclose(local_8);
      for (local_c = 0; local_c < DAT_10175ee0; local_c = local_c + 1) {
        (&DAT_10176ab4)[local_c * 0x26] = (&DAT_10176ab4)[local_c * 0x26] + DAT_101628d4;
        *(int *)(&DAT_10176ab8 + local_c * 0x98) =
             *(int *)(&DAT_10176ab8 + local_c * 0x98) + DAT_101628d4;
        *(int *)(&DAT_10176b24 + local_c * 0x98) =
             *(int *)(&DAT_10176b24 + local_c * 0x98) + DAT_101628d4;
        *(int *)(&DAT_10176b28 + local_c * 0x98) =
             *(int *)(&DAT_10176b28 + local_c * 0x98) + DAT_101628d4;
        val_2 = _strcmpi(*(char **)(&DAT_10176b24 + local_c * 0x98),&DAT_1004608c);
        if (val_2 == 0) {
          *(uint8_t **)(&DAT_10176b24 + local_c * 0x98) = &DAT_10046094;
        }
        val_2 = _strcmpi(*(char **)(&DAT_10176b28 + local_c * 0x98),&DAT_10046098);
        if ((val_2 == 0) ||
           (val_2 = _strcmpi(*(char **)(&DAT_10176b28 + local_c * 0x98),s_Blank_100460a0),
           val_2 == 0)) {
          *(uint8_t **)(&DAT_10176b28 + local_c * 0x98) = &DAT_100460a8;
        }
        *(uint8_t **)(&DAT_10176af0 + local_c * 0x98) =
             (&PTR_DAT_10044058)[*(int *)(&DAT_10176af0 + local_c * 0x98)];
        if (*(int *)(&DAT_10176af4 + local_c * 0x98) == 0) {
          *(int32_t *)(&DAT_10176af4 + local_c * 0x98) = 1;
        }
        for (local_14 = 0; local_14 < *(int *)(&DAT_10176af4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(int *)(&DAT_10176afc + local_14 * 4 + local_c * 0x98) =
               *(int *)(&DAT_10176afc + local_14 * 4 + local_c * 0x98) + DAT_101628d4;
        }
        *(int32_t *)(&DAT_10176af8 + local_c * 0x98) = 0;
        for (local_14 = 0; local_14 < *(int *)(&DAT_10176af4 + local_c * 0x98);
            local_14 = local_14 + 1) {
          *(int32_t *)(&DAT_10176b10 + local_14 * 4 + local_c * 0x98) = 0;
        }
      }
      for (local_18 = 0; local_18 < DAT_10175ee0; local_18 = local_18 + 1) {
        if (((&DAT_10176abc)[local_18 * 0x98] & 0x40) != 0) {
          *(int32_t *)(&DAT_10176abc + local_18 * 0x98) = 0x80;
        }
      }
      for (local_1c = 0; local_1c < DAT_10175ee0; local_1c = local_1c + 1) {
        if ((&DAT_10176ad8)[local_1c * 0x98] == '\x11') {
          (&DAT_10176ad8)[local_1c * 0x98] = 10;
        }
      }
      for (local_40c = 0; local_40c < DAT_10175ee0; local_40c = local_40c + 1) {
        local_410 = 0;
        for (local_20 = *(char **)(&DAT_10176b24 + local_40c * 0x98); *local_20 != '\0';
            local_20 = local_20 + 1) {
          if (*local_20 == '|') {
            char_ptr_1 = local_20 + 1;
            if (*char_ptr_1 == 'T') {
              local_20 = char_ptr_1;
              local_408[local_410] = -0x12;
            }
            else if (*char_ptr_1 == 'B') {
              local_20 = char_ptr_1;
              local_408[local_410] = -2;
            }
            else if (*char_ptr_1 == 'U') {
              local_20 = char_ptr_1;
              local_408[local_410] = -3;
            }
            else if (*char_ptr_1 == 'W') {
              local_20 = char_ptr_1;
              local_408[local_410] = -5;
            }
            else if (*char_ptr_1 == 'G') {
              local_20 = char_ptr_1;
              local_408[local_410] = -1;
            }
            else if (*char_ptr_1 == 'R') {
              local_20 = char_ptr_1;
              local_408[local_410] = -4;
            }
            else if (*char_ptr_1 == 'X') {
              local_20 = char_ptr_1;
              local_408[local_410] = -0x10;
            }
            else if ((*char_ptr_1 == '1') && (local_20[2] == '0')) {
              local_20 = local_20 + 2;
              local_408[local_410] = -0x11;
            }
            else if ((*char_ptr_1 < '0') || ('9' < *char_ptr_1)) {
              local_20 = char_ptr_1;
              local_408[local_410] = '|';
              local_20 = local_20 + -1;
            }
            else {
              local_20 = char_ptr_1;
              local_408[local_410] = *char_ptr_1 + -0x3f;
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
        strcpy(*(char **)(&DAT_10176b24 + local_40c * 0x98),local_408);
      }
      for (local_414 = 0; val_2 = DAT_10175ee0, local_414 < DAT_10175ee0; local_414 = local_414 + 1)
      {
        *(int32_t *)(&DAT_10176b0c + local_414 * 0x98) = 0;
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_black_100460ac,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) | 2;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),&DAT_100460b4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) | 4;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_green_100460bc,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) | 8;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),&DAT_100460c4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) | 0x10;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_white_100460c8,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + local_414 * 0x98) | 0x20;
        }
        *(int32_t *)(&DAT_10176b44 + local_414 * 0x98) = 0;
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_swamp_100460d0,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) | 2;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_island_100460d8,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) | 4;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_forest_100460e0,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) | 8;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_mountain_100460e8,
                                   0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) | 0x10;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + local_414 * 0x98),s_plains_100460f4,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + local_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return val_2;
}


