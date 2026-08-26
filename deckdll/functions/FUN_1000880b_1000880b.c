/*
 * Decompiled function: FUN_1000880b
 * Entry Point: 1000880b
 * Size: 2482 bytes
 */
#include "deckdll.h"


void FUN_1000880b(void)

{
  uint32_t uval_1;
  int val_2;
  int val_3;
  int local_c;
  
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    (&DAT_101c12e0)[local_c * 0x70e] = 0;
    (&DAT_101c1794)[local_c * 0x70e] = 0;
    (&DAT_101c1c48)[local_c * 0x70e] = 0;
    (&DAT_101c20fc)[local_c * 0x70e] = 0;
    (&DAT_101c25b0)[local_c * 0x70e] = 0;
    (&DAT_101c2a64)[local_c * 0x70e] = 0;
  }
  for (local_c = 0; local_c < DAT_101cece4; local_c = local_c + 1) {
    uval_1 = *(uint32_t *)(local_c * 0xc + 0x101cded0);
    val_2 = *(int *)(local_c * 0xc + 0x101cded4);
    if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 5) {
      val_3 = strcmp((char *)(&DAT_10176ab4)[uval_1 * 0x26],s_Mountain_10040b80);
      if (val_3 == 0) {
        *(uint32_t *)(&DAT_101c62d8 + DAT_101c6788 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c6788 = DAT_101c6788 + 1;
      }
      else {
        val_3 = strcmp((char *)(&DAT_10176ab4)[uval_1 * 0x26],s_Plains_10040b8c);
        if (val_3 == 0) {
          *(uint32_t *)(&DAT_101c0e30 + DAT_101c12e0 * 4) = val_2 << 0x10 | uval_1;
          DAT_101c12e0 = DAT_101c12e0 + 1;
        }
        else {
          val_3 = strcmp((char *)(&DAT_10176ab4)[uval_1 * 0x26],s_Forest_10040b94);
          if (val_3 == 0) {
            *(uint32_t *)(&DAT_101c7f10 + DAT_101c83c0 * 4) = val_2 << 0x10 | uval_1;
            DAT_101c83c0 = DAT_101c83c0 + 1;
          }
          else {
            val_3 = strcmp((char *)(&DAT_10176ab4)[uval_1 * 0x26],s_Swamp_10040b9c);
            if (val_3 == 0) {
              *(uint32_t *)(&DAT_101c46a0 + DAT_101c4b50 * 4) = val_2 << 0x10 | uval_1;
              DAT_101c4b50 = DAT_101c4b50 + 1;
            }
            else {
              val_3 = strcmp((char *)(&DAT_10176ab4)[uval_1 * 0x26],s_Island_10040ba4);
              if (val_3 == 0) {
                *(uint32_t *)(&DAT_101c2a68 + DAT_101c2f18 * 4) = val_2 << 0x10 | uval_1;
                DAT_101c2f18 = DAT_101c2f18 + 1;
              }
              else {
                *(uint32_t *)(&DAT_101c9b48 + DAT_101c9ff8 * 4) = val_2 << 0x10 | uval_1;
                DAT_101c9ff8 = DAT_101c9ff8 + 1;
              }
            }
          }
        }
      }
    }
    else if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 7) {
      if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 7) {
        *(uint32_t *)(&DAT_101c678c + DAT_101c6c3c * 4) = val_2 << 0x10 | uval_1;
        DAT_101c6c3c = DAT_101c6c3c + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 1) {
        *(uint32_t *)(&DAT_101c4b54 + DAT_101c5004 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c5004 = DAT_101c5004 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 2) {
        *(uint32_t *)(&DAT_101c2f1c + DAT_101c33cc * 4) = val_2 << 0x10 | uval_1;
        DAT_101c33cc = DAT_101c33cc + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 5) {
        *(uint32_t *)(&DAT_101c83c4 + DAT_101c8874 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c8874 = DAT_101c8874 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 8) {
        *(uint32_t *)(&DAT_101c12e4 + DAT_101c1794 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c1794 = DAT_101c1794 + 1;
      }
      else {
        *(uint32_t *)(&DAT_101c9ffc + DAT_101ca4ac * 4) = val_2 << 0x10 | uval_1;
        DAT_101ca4ac = DAT_101ca4ac + 1;
      }
    }
    else if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 2) {
      if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 7) {
        *(uint32_t *)(&DAT_101c6c40 + DAT_101c70f0 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c70f0 = DAT_101c70f0 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 1) {
        *(uint32_t *)(&DAT_101c5008 + DAT_101c54b8 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c54b8 = DAT_101c54b8 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 2) {
        *(uint32_t *)(&DAT_101c33d0 + DAT_101c3880 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c3880 = DAT_101c3880 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 5) {
        *(uint32_t *)(&DAT_101c8878 + DAT_101c8d28 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c8d28 = DAT_101c8d28 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 8) {
        *(uint32_t *)(&DAT_101c1798 + DAT_101c1c48 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c1c48 = DAT_101c1c48 + 1;
      }
      else {
        *(uint32_t *)(&DAT_101ca4b0 + DAT_101ca960 * 4) = val_2 << 0x10 | uval_1;
        DAT_101ca960 = DAT_101ca960 + 1;
      }
    }
    else if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 6) {
      if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 7) {
        *(uint32_t *)(&DAT_101c70f4 + DAT_101c75a4 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c75a4 = DAT_101c75a4 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 1) {
        *(uint32_t *)(&DAT_101c54bc + DAT_101c596c * 4) = val_2 << 0x10 | uval_1;
        DAT_101c596c = DAT_101c596c + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 2) {
        *(uint32_t *)(&DAT_101c3884 + DAT_101c3d34 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c3d34 = DAT_101c3d34 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 5) {
        *(uint32_t *)(&DAT_101c8d2c + DAT_101c91dc * 4) = val_2 << 0x10 | uval_1;
        DAT_101c91dc = DAT_101c91dc + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 8) {
        *(uint32_t *)(&DAT_101c1c4c + DAT_101c20fc * 4) = val_2 << 0x10 | uval_1;
        DAT_101c20fc = DAT_101c20fc + 1;
      }
      else {
        *(uint32_t *)(&DAT_101ca964 + DAT_101cae14 * 4) = val_2 << 0x10 | uval_1;
        DAT_101cae14 = DAT_101cae14 + 1;
      }
    }
    else if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 4) {
      if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 7) {
        *(uint32_t *)(&DAT_101c75a8 + DAT_101c7a58 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c7a58 = DAT_101c7a58 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 1) {
        *(uint32_t *)(&DAT_101c5970 + DAT_101c5e20 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c5e20 = DAT_101c5e20 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 2) {
        *(uint32_t *)(&DAT_101c3d38 + DAT_101c41e8 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c41e8 = DAT_101c41e8 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 5) {
        *(uint32_t *)(&DAT_101c91e0 + DAT_101c9690 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c9690 = DAT_101c9690 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 8) {
        *(uint32_t *)(&DAT_101c2100 + DAT_101c25b0 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c25b0 = DAT_101c25b0 + 1;
      }
      else {
        *(uint32_t *)(&DAT_101cae18 + DAT_101cb2c8 * 4) = val_2 << 0x10 | uval_1;
        DAT_101cb2c8 = DAT_101cb2c8 + 1;
      }
    }
    else if (*(int *)(&DAT_10176ac4 + uval_1 * 0x98) == 3) {
      if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 7) {
        *(uint32_t *)(&DAT_101c7a5c + DAT_101c7f0c * 4) = val_2 << 0x10 | uval_1;
        DAT_101c7f0c = DAT_101c7f0c + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 1) {
        *(uint32_t *)(&DAT_101c5e24 + DAT_101c62d4 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c62d4 = DAT_101c62d4 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 2) {
        *(uint32_t *)(&DAT_101c41ec + DAT_101c469c * 4) = val_2 << 0x10 | uval_1;
        DAT_101c469c = DAT_101c469c + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 5) {
        *(uint32_t *)(&DAT_101c9694 + DAT_101c9b44 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c9b44 = DAT_101c9b44 + 1;
      }
      else if (*(int *)(&DAT_10176ac0 + uval_1 * 0x98) == 8) {
        *(uint32_t *)(&DAT_101c25b4 + DAT_101c2a64 * 4) = val_2 << 0x10 | uval_1;
        DAT_101c2a64 = DAT_101c2a64 + 1;
      }
      else {
        *(uint32_t *)(&DAT_101cb2cc + DAT_101cb77c * 4) = val_2 << 0x10 | uval_1;
        DAT_101cb77c = DAT_101cb77c + 1;
      }
    }
    else {
      *(uint32_t *)(&DAT_101cb2cc + DAT_101cb77c * 4) = val_2 << 0x10 | uval_1;
      DAT_101cb77c = DAT_101cb77c + 1;
    }
  }
  return;
}


