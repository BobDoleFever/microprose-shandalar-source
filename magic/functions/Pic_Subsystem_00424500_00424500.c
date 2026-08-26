/*
 * Decompiled function: Pic_Subsystem_00424500
 * Entry Point: 00424500
 * Size: 597 bytes
 */
#include "magic.h"


int Pic_Subsystem_00424500(char *str_1,char *str_2)

{
  FILE *_File;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_310;
  char local_30c [252];
  char local_210 [264];
  char local_108 [252];
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    strcpy(local_108,&DAT_00520d68);
    strcat(local_108,str_2);
    strcat(local_108,&DAT_00520d6c);
    strcpy(local_210,&DAT_006807a0);
    strcat(local_210,&DAT_00520d70);
    strcpy(local_210,str_1);
    _File = fopen(local_210,&DAT_00520d74);
    if (_File != (FILE *)0x0) {
      do {
        iVar1 = strcmp(local_108,local_30c);
        if (iVar1 == 0) {
          fscanf(_File,&DAT_00520d78,&local_8);
          fgets(local_30c,0x50,_File);
          local_c = 0;
          for (local_310 = 0; (local_310 < local_8 && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            pcVar2 = fgets(&g_OverworldGoldAmount + local_310 * 0xfa,0xfa,_File);
            if (pcVar2 == (char *)0x0) {
              fclose(_File);
              return -local_c;
            }
            sVar3 = strlen(&g_OverworldGoldAmount + local_310 * 0xfa);
            (&DAT_0069f74f)[local_310 * 0xfa + sVar3] = 0;
            local_c = local_c + 1;
          }
          fclose(_File);
          if (local_c < local_8) {
            return -local_c;
          }
          return local_c;
        }
        pcVar2 = fgets(local_30c,0x50,_File);
      } while (pcVar2 != (char *)0x0);
      fclose(_File);
    }
  }
  return 0;
}


