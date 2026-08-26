/*
 * Decompiled function: thunk_FUN_100298f0
 * Entry Point: 100010be
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_100298f0(char *str_1)

{
  char *char_ptr_1;
  int val_2;
  int iStack_414;
  int iStack_410;
  int iStack_40c;
  char acStack_408 [1000];
  char *pcStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  size_t sStack_10;
  int iStack_c;
  FILE *pFStack_8;
  
  pFStack_8 = fopen(str_1,&DAT_10046088);
  if (pFStack_8 == (FILE *)0x0) {
    val_2 = 0;
  }
  else {
    fread(&DAT_10175ee0,4,1,pFStack_8);
    fread(&sStack_10,4,1,pFStack_8);
    DAT_101628d4 = (int)malloc(sStack_10);
    if ((void *)DAT_101628d4 == (void *)0x0) {
      fclose(pFStack_8);
      val_2 = 0;
    }
    else {
      fread(&DAT_10176ab0,0x98,DAT_10175ee0,pFStack_8);
      fread((void *)DAT_101628d4,1,sStack_10,pFStack_8);
      fclose(pFStack_8);
      for (iStack_c = 0; iStack_c < DAT_10175ee0; iStack_c = iStack_c + 1) {
        (&DAT_10176ab4)[iStack_c * 0x26] = (&DAT_10176ab4)[iStack_c * 0x26] + DAT_101628d4;
        *(int *)(&DAT_10176ab8 + iStack_c * 0x98) =
             *(int *)(&DAT_10176ab8 + iStack_c * 0x98) + DAT_101628d4;
        *(int *)(&DAT_10176b24 + iStack_c * 0x98) =
             *(int *)(&DAT_10176b24 + iStack_c * 0x98) + DAT_101628d4;
        *(int *)(&DAT_10176b28 + iStack_c * 0x98) =
             *(int *)(&DAT_10176b28 + iStack_c * 0x98) + DAT_101628d4;
        val_2 = _strcmpi(*(char **)(&DAT_10176b24 + iStack_c * 0x98),&DAT_1004608c);
        if (val_2 == 0) {
          *(uint8_t **)(&DAT_10176b24 + iStack_c * 0x98) = &DAT_10046094;
        }
        val_2 = _strcmpi(*(char **)(&DAT_10176b28 + iStack_c * 0x98),&DAT_10046098);
        if ((val_2 == 0) ||
           (val_2 = _strcmpi(*(char **)(&DAT_10176b28 + iStack_c * 0x98),s_Blank_100460a0),
           val_2 == 0)) {
          *(uint8_t **)(&DAT_10176b28 + iStack_c * 0x98) = &DAT_100460a8;
        }
        *(uint8_t **)(&DAT_10176af0 + iStack_c * 0x98) =
             (&PTR_DAT_10044058)[*(int *)(&DAT_10176af0 + iStack_c * 0x98)];
        if (*(int *)(&DAT_10176af4 + iStack_c * 0x98) == 0) {
          *(int32_t *)(&DAT_10176af4 + iStack_c * 0x98) = 1;
        }
        for (iStack_14 = 0; iStack_14 < *(int *)(&DAT_10176af4 + iStack_c * 0x98);
            iStack_14 = iStack_14 + 1) {
          *(int *)(&DAT_10176afc + iStack_14 * 4 + iStack_c * 0x98) =
               *(int *)(&DAT_10176afc + iStack_14 * 4 + iStack_c * 0x98) + DAT_101628d4;
        }
        *(int32_t *)(&DAT_10176af8 + iStack_c * 0x98) = 0;
        for (iStack_14 = 0; iStack_14 < *(int *)(&DAT_10176af4 + iStack_c * 0x98);
            iStack_14 = iStack_14 + 1) {
          *(int32_t *)(&DAT_10176b10 + iStack_14 * 4 + iStack_c * 0x98) = 0;
        }
      }
      for (iStack_18 = 0; iStack_18 < DAT_10175ee0; iStack_18 = iStack_18 + 1) {
        if (((&DAT_10176abc)[iStack_18 * 0x98] & 0x40) != 0) {
          *(int32_t *)(&DAT_10176abc + iStack_18 * 0x98) = 0x80;
        }
      }
      for (iStack_1c = 0; iStack_1c < DAT_10175ee0; iStack_1c = iStack_1c + 1) {
        if ((&DAT_10176ad8)[iStack_1c * 0x98] == '\x11') {
          (&DAT_10176ad8)[iStack_1c * 0x98] = 10;
        }
      }
      for (iStack_40c = 0; iStack_40c < DAT_10175ee0; iStack_40c = iStack_40c + 1) {
        iStack_410 = 0;
        for (pcStack_20 = *(char **)(&DAT_10176b24 + iStack_40c * 0x98); *pcStack_20 != '\0';
            pcStack_20 = pcStack_20 + 1) {
          if (*pcStack_20 == '|') {
            char_ptr_1 = pcStack_20 + 1;
            if (*char_ptr_1 == 'T') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -0x12;
            }
            else if (*char_ptr_1 == 'B') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -2;
            }
            else if (*char_ptr_1 == 'U') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -3;
            }
            else if (*char_ptr_1 == 'W') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -5;
            }
            else if (*char_ptr_1 == 'G') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -1;
            }
            else if (*char_ptr_1 == 'R') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -4;
            }
            else if (*char_ptr_1 == 'X') {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = -0x10;
            }
            else if ((*char_ptr_1 == '1') && (pcStack_20[2] == '0')) {
              pcStack_20 = pcStack_20 + 2;
              acStack_408[iStack_410] = -0x11;
            }
            else if ((*char_ptr_1 < '0') || ('9' < *char_ptr_1)) {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = '|';
              pcStack_20 = pcStack_20 + -1;
            }
            else {
              pcStack_20 = char_ptr_1;
              acStack_408[iStack_410] = *char_ptr_1 + -0x3f;
            }
          }
          else if (((*pcStack_20 == '\\') && (pcStack_20[1] == '\\')) ||
                  ((*pcStack_20 == '\\' && (pcStack_20[1] == 'n')))) {
            pcStack_20 = pcStack_20 + 1;
            acStack_408[iStack_410] = '\n';
          }
          else {
            acStack_408[iStack_410] = *pcStack_20;
          }
          iStack_410 = iStack_410 + 1;
        }
        acStack_408[iStack_410] = '\0';
        strcpy(*(char **)(&DAT_10176b24 + iStack_40c * 0x98),acStack_408);
      }
      for (iStack_414 = 0; val_2 = DAT_10175ee0, iStack_414 < DAT_10175ee0;
          iStack_414 = iStack_414 + 1) {
        *(int32_t *)(&DAT_10176b0c + iStack_414 * 0x98) = 0;
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_black_100460ac,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) | 2;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),&DAT_100460b4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) | 4;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_green_100460bc,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) | 8;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),&DAT_100460c4,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) | 0x10;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_white_100460c8,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b0c + iStack_414 * 0x98) | 0x20;
        }
        *(int32_t *)(&DAT_10176b44 + iStack_414 * 0x98) = 0;
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_swamp_100460d0,0)
        ;
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) | 2;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_island_100460d8,0
                                  );
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) | 4;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_forest_100460e0,0
                                  );
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) | 8;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_mountain_100460e8
                                   ,0);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) | 0x10;
        }
        val_2 = thunk_FUN_100327b1(*(char **)(&DAT_10176b24 + iStack_414 * 0x98),s_plains_100460f4,0
                                  );
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) =
               *(uint32_t *)(&DAT_10176b44 + iStack_414 * 0x98) | 0x20;
        }
      }
    }
  }
  return val_2;
}


