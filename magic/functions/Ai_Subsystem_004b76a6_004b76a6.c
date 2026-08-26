/*
 * Decompiled function: Ai_Subsystem_004b76a6
 * Entry Point: 004b76a6
 * Size: 423 bytes
 */
#include "magic.h"


int Ai_Subsystem_004b76a6(void *arg_1,int y,int width,int height)

{
  int iVar1;
  int local_8ac;
  char local_8a4 [200];
  int local_7dc [500];
  int local_c;
  int local_8;
  
  if ((((arg_1 == (void *)0x0) || (y == 0)) || (width == 0)) || (height == 0)) {
    local_8ac = 0;
  }
  else {
    memcpy(local_7dc,arg_1,y << 2);
    local_c = 0;
    local_8ac = 0;
    while ((local_c == 0 && (local_8ac < height))) {
      do {
        if (local_8ac == 0) {
          strcpy(local_8a4,&g_OverworldGoldAmount);
        }
        else if (local_8ac == 1) {
          strcpy(local_8a4,&DAT_0069f84a);
        }
        else {
          strcpy(local_8a4,&DAT_0069f944);
        }
        iVar1 = Ai_ScoreCardPlay_004afa69(local_7dc,0,y,local_8a4,0,&DAT_0052d400);
        if (iVar1 == -1) {
          local_c = 1;
        }
        else if (local_7dc[iVar1] < 5) {
          local_8 = 1;
          *(int *)(width + local_8ac * 4) = iVar1;
          local_8ac = local_8ac + 1;
          local_7dc[iVar1] = DAT_006a3f74;
        }
        else {
          local_8 = 0;
        }
      } while ((local_c == 0) && (local_8 == 0));
    }
  }
  return local_8ac;
}


