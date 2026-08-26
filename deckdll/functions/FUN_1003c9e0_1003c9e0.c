/*
 * Decompiled function: FUN_1003c9e0
 * Entry Point: 1003c9e0
 * Size: 1315 bytes
 */
#include "deckdll.h"


void FUN_1003c9e0(void)

{
  int val_1;
  int val_2;
  int val_3;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  
  for (local_1c = 0; local_1c < 9; local_1c = local_1c + 1) {
    for (local_18 = 0; local_18 < 7; local_18 = local_18 + 1) {
      *(int32_t *)(&DAT_1013ed08 + local_18 * 4 + local_1c * 0x1c) = 0;
    }
  }
  local_18 = 0;
  do {
    if (DAT_101cece4 <= local_18) {
      for (local_1c = 0; local_1c < 8; local_1c = local_1c + 1) {
        for (local_18 = 0; local_18 < 6; local_18 = local_18 + 1) {
          *(int *)(&DAT_1013ed20 + local_1c * 0x1c) =
               *(int *)(&DAT_1013ed20 + local_1c * 0x1c) +
               *(int *)(&DAT_1013ed08 + local_18 * 4 + local_1c * 0x1c);
        }
      }
      for (local_18 = 0; local_18 < 6; local_18 = local_18 + 1) {
        for (local_1c = 0; local_1c < 8; local_1c = local_1c + 1) {
          if (local_1c != 0) {
            *(int *)(&DAT_1013ede8 + local_18 * 4) =
                 *(int *)(&DAT_1013ede8 + local_18 * 4) +
                 *(int *)(&DAT_1013ed08 + local_18 * 4 + local_1c * 0x1c);
          }
        }
      }
      for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
        if (local_18 != 0) {
          DAT_1013ee00 = DAT_1013ee00 + *(int *)(&DAT_1013ed20 + local_18 * 0x1c);
        }
      }
      return;
    }
    val_1 = *(int *)(local_18 * 0xc + 0x101cded0);
    val_2 = *(int *)(local_18 * 0xc + 0x101cded4);
    if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 7) {
      local_c = 1;
LAB_1003cb86:
      if (*(int *)(&DAT_10176ac0 + val_1 * 0x98) == 1) {
        local_14 = 0;
      }
      else if (*(int *)(&DAT_10176ac0 + val_1 * 0x98) == 2) {
        local_14 = 1;
      }
      else if (*(int *)(&DAT_10176ac0 + val_1 * 0x98) == 5) {
        local_14 = 2;
      }
      else if (*(int *)(&DAT_10176ac0 + val_1 * 0x98) == 7) {
        local_14 = 3;
      }
      else if (*(int *)(&DAT_10176ac0 + val_1 * 0x98) == 8) {
        local_14 = 4;
      }
      else {
        local_14 = -1;
      }
      if (local_c == 6) {
        val_3 = strcmp((char *)(&DAT_10176ab4)[val_1 * 0x26],s_Mountain_1004bcfc);
        if (val_3 == 0) {
          local_14 = 3;
        }
        else {
          val_3 = strcmp((char *)(&DAT_10176ab4)[val_1 * 0x26],s_Forest_1004bd08);
          if (val_3 == 0) {
            local_14 = 2;
          }
          else {
            val_3 = strcmp((char *)(&DAT_10176ab4)[val_1 * 0x26],s_Island_1004bd10);
            if (val_3 == 0) {
              local_14 = 1;
            }
            else {
              val_3 = strcmp((char *)(&DAT_10176ab4)[val_1 * 0x26],s_Plains_1004bd18);
              if (val_3 == 0) {
                local_14 = 4;
              }
              else {
                val_3 = strcmp((char *)(&DAT_10176ab4)[val_1 * 0x26],s_Swamp_1004bd20);
                if (val_3 == 0) {
                  local_14 = 0;
                }
                else {
                  local_14 = 5;
                }
              }
            }
          }
        }
      }
      if ((local_c == 7) && (local_14 = 5, *(int *)(&DAT_10176ac8 + val_1 * 0x98) == 0x2d)) {
        local_c = 1;
      }
      if (local_14 == -1) {
        MessageBoxA((HWND)0x0,s_Color_is__1_1004bd34,s_Stats_Error_1004bd28,0);
      }
      else {
        if (*(int *)(&DAT_10176ad0 + val_1 * 0x98) == 10) {
          *(int *)(&DAT_1013ed08 + local_14 * 4) = *(int *)(&DAT_1013ed08 + local_14 * 4) + val_2;
        }
        *(int *)(&DAT_1013ed08 + local_14 * 4 + local_c * 0x1c) =
             *(int *)(&DAT_1013ed08 + local_14 * 4 + local_c * 0x1c) + val_2;
      }
    }
    else {
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 2) {
        local_c = 2;
        goto LAB_1003cb86;
      }
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 6) {
        local_c = 3;
        goto LAB_1003cb86;
      }
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 3) {
        local_c = 4;
        goto LAB_1003cb86;
      }
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 4) {
        local_c = 5;
        goto LAB_1003cb86;
      }
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 1) {
        local_c = 7;
        goto LAB_1003cb86;
      }
      if (*(int *)(&DAT_10176ac4 + val_1 * 0x98) == 5) {
        local_c = 6;
        goto LAB_1003cb86;
      }
    }
    local_18 = local_18 + 1;
  } while( true );
}


