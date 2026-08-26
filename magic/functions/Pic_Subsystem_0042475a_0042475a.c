/*
 * Decompiled function: Pic_Subsystem_0042475a
 * Entry Point: 0042475a
 * Size: 340 bytes
 */
#include "magic.h"


int Pic_Subsystem_0042475a(char *str_1,char *str_2)

{
  int arg_1;
  int iVar1;
  size_t sVar2;
  int local_18;
  int local_10;
  int local_c;
  
  if (g_IsAiThinking == 1) {
    arg_1 = 0;
  }
  else {
    arg_1 = Pic_Subsystem_00424500(str_1,str_2);
    for (local_c = 0; iVar1 = abs(arg_1), local_c < iVar1; local_c = local_c + 1) {
      sVar2 = strlen(&g_OverworldGoldAmount + local_c * 0xfa);
      local_18 = 0;
      for (local_10 = 0; local_10 < (int)sVar2; local_10 = local_10 + 1) {
        if (((&g_OverworldGoldAmount)[local_c * 0xfa + local_10] == '\\') &&
           ((&DAT_0069f751)[local_c * 0xfa + local_10] == 'n')) {
          (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] = 10;
          local_10 = local_10 + 1;
        }
        else {
          (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] =
               (&g_OverworldGoldAmount)[local_c * 0xfa + local_10];
        }
        local_18 = local_18 + 1;
      }
      (&g_OverworldGoldAmount)[local_c * 0xfa + local_18] = 0;
    }
  }
  return arg_1;
}


