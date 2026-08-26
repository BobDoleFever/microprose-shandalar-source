/*
 * Decompiled function: FUN_00448b6f
 * Entry Point: 00448b6f
 * Size: 423 bytes
 */
#include "duel.h"


int FUN_00448b6f(void *arg_1,int y,int width,int height)

{
  int iVar1;
  int local_8ac;
  uint local_8a4 [50];
  int local_7dc [500];
  int local_c;
  int local_8;
  
  if ((((arg_1 == (void *)0x0) || (y == 0)) || (width == 0)) || (height == 0)) {
    local_8ac = 0;
  }
  else {
    FID_conflict__memcpy(local_7dc,arg_1,y << 2);
    local_c = 0;
    local_8ac = 0;
    while ((local_c == 0 && (local_8ac < height))) {
      do {
        if (local_8ac == 0) {
          Mem_AllocOrFree_004d9630(local_8a4,(uint *)&DAT_006679f0);
        }
        else if (local_8ac == 1) {
          Mem_AllocOrFree_004d9630(local_8a4,(uint *)&DAT_00667aea);
        }
        else {
          Mem_AllocOrFree_004d9630(local_8a4,(uint *)&DAT_00667be4);
        }
        iVar1 = Ai_ScoreCardPlay_004afa69(local_7dc,0,y,local_8a4,0,&DAT_004f7f20);
        if (iVar1 == -1) {
          local_c = 1;
        }
        else if (local_7dc[iVar1] < 5) {
          local_8 = 1;
          *(int *)(width + local_8ac * 4) = iVar1;
          local_8ac = local_8ac + 1;
          local_7dc[iVar1] = DAT_006764b4;
        }
        else {
          local_8 = 0;
        }
      } while ((local_c == 0) && (local_8 == 0));
    }
  }
  return local_8ac;
}


