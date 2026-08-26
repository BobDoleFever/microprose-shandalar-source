/*
 * Decompiled function: Deck_FilterAttributes_00406b4c
 * Entry Point: 00406b4c
 * Size: 1315 bytes
 */
#include "magic.h"


int Deck_FilterAttributes_00406b4c(char *filter_string,int color_mask,uint width,int height)

{
  int *piVar1;
  int iVar2;
  uint local_230;
  uint local_22c;
  int local_220;
  int local_21c;
  int local_218;
  char *local_214;
  int local_210;
  int local_20c;
  uint local_208;
  char local_204;
  char local_203 [499];
  int local_10;
  FILE *local_c;
  int local_8;
  
  strcpy(&DAT_00701830,filter_string);
  local_c = fopen(filter_string,&DAT_00516470);
  if (local_c == (FILE *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = 0;
    local_218 = 0;
    local_230 = 0;
    local_8 = fscanf(local_c,s_______00516474,&local_204);
    local_8 = fscanf(local_c,&DAT_0051647c,&local_204);
    local_208 = 0;
    local_20c = -1;
    local_22c = 0xffffffff;
    local_210 = 0;
    local_21c = -1;
    local_220 = -1;
    do {
      local_8 = fscanf(local_c,s_______00516484,&local_204);
      if (local_204 == '.') {
        if (local_203[0] == 'v') {
          local_214 = strchr(&local_204,0x20);
          if (local_214 != (char *)0x0) {
            *local_214 = '\0';
          }
          iVar2 = _strcmpi(&local_204,s__vNONE_00516494);
          if (iVar2 == 0) {
            local_208 = 1;
          }
          iVar2 = _strcmpi(&local_204,s__vBLACK_0051649c);
          if (iVar2 == 0) {
            local_208 = 2;
          }
          iVar2 = _strcmpi(&local_204,s__vBLUE_005164a4);
          if (iVar2 == 0) {
            local_208 = 4;
          }
          iVar2 = _strcmpi(&local_204,s__vRED_005164ac);
          if (iVar2 == 0) {
            local_208 = 0x10;
          }
          iVar2 = _strcmpi(&local_204,s__vGREEN_005164b4);
          if (iVar2 == 0) {
            local_208 = 8;
          }
          iVar2 = _strcmpi(&local_204,s__vWHITE_005164bc);
          if (iVar2 == 0) {
            local_208 = 0x20;
          }
          iVar2 = _strcmpi(&local_204,s__vFAST_005164c4);
          if (iVar2 == 0) {
            local_20c = 0;
          }
          iVar2 = _strcmpi(&local_204,s__vLARGE_005164cc);
          if (iVar2 == 0) {
            local_20c = 1;
          }
          iVar2 = _strcmpi(&local_204,s__vDIRECT_005164d4);
          if (iVar2 == 0) {
            local_20c = 2;
          }
          iVar2 = _strcmpi(&local_204,s__vARTIFACT_005164e0);
          if (iVar2 == 0) {
            local_20c = 6;
          }
        }
        else {
          sscanf(local_203,s__d__d_0051648c,&local_220,&local_21c);
          local_210 = local_210 + local_21c;
          if (((local_208 == 0) || ((width & local_208) != 0)) &&
             ((local_20c == -1 || (local_20c == height)))) {
            *(int *)(color_mask + local_230 * 8) = local_220;
            *(int *)(color_mask + 4 + local_230 * 8) = local_21c;
            iVar2 = Pic_Subsystem_0045268f(local_220);
            if (local_21c == 0) {
              local_21c = DAT_0067f380;
            }
            if (iVar2 == -1) {
              if ((local_22c != 0xffffffff) &&
                 (local_21c < *(int *)(color_mask + 4 + local_22c * 8))) {
                piVar1 = (int *)(color_mask + 4 + local_22c * 8);
                *piVar1 = *piVar1 - (int)((local_230 & 1) + local_21c) / 2;
              }
            }
            else if (iVar2 < 5) {
              local_22c = local_230;
            }
          }
        }
        local_230 = local_230 + 1;
      }
      else {
        local_218 = local_218 + 1;
        if (local_218 == 5) {
          local_10 = atoi(local_203);
        }
        else if ((local_218 == 6) && (iVar2 = strcmp(local_203,s_4th_Edition_005164ec), iVar2 != 0))
        {
          local_10 = -2;
        }
      }
      local_8 = fscanf(local_c,&DAT_005164f8,&local_204);
    } while ((((int)local_230 < 0x50) && (local_8 != -1)) && ((local_220 != 0 || (local_21c != 0))))
    ;
    fclose(local_c);
    if (local_210 < 0x28) {
      local_10 = -3;
    }
    if (0x37 < local_10) {
      local_10 = -1;
    }
  }
  return local_10;
}


