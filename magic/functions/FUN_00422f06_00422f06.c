/*
 * Decompiled function: FUN_00422f06
 * Entry Point: 00422f06
 * Size: 380 bytes
 */
#include "magic.h"


void FUN_00422f06(void)

{
  uint uVar1;
  int local_1c;
  
  memset(&DAT_00538850,0,0x1c0);
  DAT_00538a6c = 0;
  DAT_00538a68 = 0;
  DAT_00538a60 = 0;
  DAT_00538a70 = 0;
  DAT_00538ab8 = 0;
  DAT_00538a64 = 0;
  DAT_00538a24 = 0;
  local_1c = 0;
  while( true ) {
    if (9999 < local_1c) {
      return;
    }
    uVar1 = *(uint *)(&DAT_0067a9a4 + local_1c * 0x10);
    if (*(int *)(&DAT_0067a9a0 + local_1c * 0x10) == 0) break;
    switch(*(undefined4 *)(&DAT_0067a9a0 + local_1c * 0x10)) {
    case 2:
      if ((uVar1 & 0x80) == 0) {
        DAT_00538a64 = DAT_00538a64 + 1;
        *(int *)(&DAT_00538854 + (uVar1 & 0x7f) * 8) =
             *(int *)(&DAT_00538854 + (uVar1 & 0x7f) * 8) + 1;
      }
      else {
        DAT_00538a24 = DAT_00538a24 + 1;
        *(int *)(&DAT_00538850 + (uVar1 & 0x7f) * 8) =
             *(int *)(&DAT_00538850 + (uVar1 & 0x7f) * 8) + 1;
      }
      break;
    case 4:
      *(int *)(&DAT_00538838 + (uVar1 & 0x7f) * 4) =
           *(int *)(&DAT_00538838 + (uVar1 & 0x7f) * 4) + 1;
      break;
    case 7:
      DAT_00538a60 = DAT_00538a60 + 1;
      break;
    case 0xd:
      DAT_00538a70 = DAT_00538a70 + 1;
      break;
    case 0xf:
      break;
    case 0x10:
      DAT_00538a68 = DAT_00538a68 + 1;
      break;
    case 0x11:
      DAT_00538a6c = DAT_00538a6c + 1;
      break;
    case 0x13:
      DAT_00538ab8 = DAT_00538ab8 + 1;
    }
    local_1c = local_1c + 1;
  }
  return;
}


